// TAP3.12c.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DataInterChange.h"
#include "BatchControlInfo.h"

#include "TAP_Constants.h"
#include "ConfigContainer.h"

#define OTL_ORA9I // Compile OTL 4.0/OCI9i
// #define OTL_ORA8
// #define OTL_ORA8I

#if defined(_MSC_VER) // VC++

// Enabling support for 64-bit signed integers
// Since 64-bit integers are not part of the ANSI C++
// standard, this definition is compiler specific.
#define OTL_BIGINT __int64

// Defining a bigint constant that is larger than
// the max 32-bit integer value.
const OTL_BIGINT BIGINT_VAL1=12345678901234000;

// Defining a string-to-bigint conversion 
// that is used by OTL internally.
// Since 64-bit ineteger conversion functions are
// not part of the ANSI C++ standard, the code
// below is compiler specific
#define OTL_STR_TO_BIGINT(str,n)                \
{                                               \
  n=_atoi64(str);                               \
}

// Defining a bigint-to-string conversion 
// that is used by OTL internally.
// Since 64-bit ineteger conversion functions are
// not part of the ANSI C++ standard, the code
// below is compiler specific
#define OTL_BIGINT_TO_STR(n,str)                \
{                                               \
  _i64toa(n,str,10);                            \
}

#elif defined(__GNUC__) // GNU C++

#include <stdlib.h>

// Enabling support for 64-bit signed integers
// Since 64-bit integers are not part of the ANSI C++
// standard, this definition is compiler specific.
#define OTL_BIGINT long long

const OTL_BIGINT BIGINT_VAL1=12345678901234000LL;

// Defining a string-to-bigint conversion 
// that is used by OTL internally.
// Since 64-bit ineteger conversion functions are
// not part of the ANSI C++ standard, the code
// below is compiler specific.
#define OTL_STR_TO_BIGINT(str,n)                \
{                                               \
  n=strtoll(str,0,10);                          \
}

// Defining a bigint-to-string conversion 
// that is used by OTL internally.
// Since 64-bit ineteger conversion functions are
// not part of the ANSI C++ standard, the code
// below is compiler specific
#define OTL_BIGINT_TO_STR(n,str)                \
{                                               \
  sprintf(str,"%lld",n);                        \
}


#endif


#define OTL_STL
#include "otlv4.h"

extern "C" int ncftp_main(int argc, char **argv, char* result);


//const char *pShortName;
// string filename;
long TapFileID;				// ID TAP-файла в таблице TAP3_FILE
double dblTAPPower = 1;			// делитель денежных единиц
//long totalCharge=0;			// суммарное начисление (считается без деления на dblTAPPower)
int totalCallDetailCount=0;
int debugMode = 0;
DataInterChange* dataInterchange = NULL;

otl_connect otlConnect;
otl_connect otlLogConnect;
ofstream ofsLog;

//-----------------------------
void logToFile(string message)
{
	time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
	
	(ofsLog.is_open() ? ofsLog : cout) << now->tm_mday << '.' << (now->tm_mon + 1) << '.' << (now->tm_year + 1900) << ' ' << now->tm_hour << ':' << now->tm_min << ':' << now->tm_sec << ' ' << message << endl;
}
//-----------------------------
void log(string filename, short msgType, string msgText)
{
	otl_stream otlLog;
	
	if (otlLogConnect.connected) {
		if(msgText.length() > 2048)
			msgText = msgText.substr(0, 2048);
		try {
			otlLog.open(1, "insert into BILLING.TAP3WRITER_LOG (datetime, filename, msg_type, msg_text) values (sysdate, :fn /*char[255]*/, :msg_type/*short*/, :msg_text /*char[2048]*/)", otlLogConnect);
			otlLog << filename << msgType << msgText;
		}
		catch (otl_exception &otlEx) {
			string msg = "Unable to write log message to DB: ";
			msg += msgText;
			logToFile(msg);
			logToFile((char*)otlEx.msg);
			if (strlen(otlEx.stm_text) > 0)
				logToFile((char*)otlEx.stm_text); // log SQL that caused the error
			if (strlen(otlEx.var_info) > 0)
				logToFile((char*)otlEx.var_info); // log the variable that caused the error
		}
	}
	else {
		logToFile(to_string(static_cast<unsigned long long> (msgType)) + '\t' + msgText);
	}
}
//------------------------------
int assign_integer_option(string _name, string _value, long& param, long minValid, long maxValid)
{
	size_t stoi_idx;
	try {
		param = stoi(_value, &stoi_idx);
	}
	catch(...) {
		cerr << "Wrong value for " << _name << " given in ini-file.";
		return -1;
	}
	if(stoi_idx < _value.length()) {
		cerr << "Wrong value for " << _name << " given in ini-file.";
		return -1;
	}
	if(param<minValid || param>maxValid) {
		cerr << "Wrong value for " << _name << " given in ini-file. Valid range is from " << minValid << " to " << maxValid;
		return -1;
	}
	
	return 0;
}
//----------------------------
static int write_out(const void *buffer, size_t size, void *app_key) {
	FILE *out_fp = (FILE*) app_key;
	size_t wrote = fwrite(buffer, 1, size, out_fp);
	return (wrote == size) ? 0 : -1;
}
//-----------------------------
string BCDString(BCDString_t* src, bool bSwitchDigits=false)
{
	string dest;
	
	if(src) {
		for(int i=0; i<src->size; i++) {
			if( bSwitchDigits ) {
				dest.push_back(src->buf[i] & 0x0F);
				dest.push_back((src->buf[i] & 0xF0) >> 4);
			}
			else {
				dest.push_back((src->buf[i] & 0xF0) >> 4);
				dest.push_back(src->buf[i] & 0x0F);
			}
		}

		for(unsigned int i=0; i<dest.size(); i++)
			if(dest[i]<0xA)
			{	
				dest[i]+='0';
			}
			else
			{
				switch( dest[i] )
				{
				case 0xA: dest[i]='*';
						break;
				case 0xB: dest[i]='*';
						break;
				case 0xC: dest[i]='#';
						break;
				case 0xD: dest[i]='a';
						break;
				case 0xE: dest[i]='b';
						break;
				case 0xF: //dest[i]='c';
					dest.erase(i--, 1);
				}
			}
	}
	return dest;
}	
//------------------------------
string BCDStringFromStr(string src, bool bSwitchDigits=false)
{
	string dest;
		
	if(src.length()>0) {
		if(src.size() % 2 == 1) {
			// odd number of symbols. Fill with F
			src.push_back('0'+ 0x0F);
		}

		for(unsigned int i=0, j=0; i<src.size(); i+=2, j++) {
			// decode to binary and check for special symbols
			switch( src[i] ) {
				case '*': src[i]=0x0A;
					break;
				case '#': src[i]=0x0C;
					break;
				case 'a': src[i]=0x0D;
					break;
				case 'b': src[i]=0x0E;
					break;
				default:
					src[i] -= '0';
			}

			switch( src[i+1] ) {
				case '*': src[i+1]=0x0A;
					break;
				case '#': src[i+1]=0x0C;
					break;
				case 'a': src[i+1]=0x0D;
					break;
				case 'b': src[i+1]=0x0E;
					break;
				default:
					src[i+1] -= '0';
			}

			if( bSwitchDigits ) 
				dest.push_back( (src[i+1]) << 4 | src[i] );
			else 
				dest.push_back( (src[i]) << 4 | src[i+1] );
		}
	}

	return dest;
}
//------------------------------
OCTET_STRING_t* BCDString_new_FromStr(asn_TYPE_descriptor_t* asnType, string src, bool bSwitchDigits=false)
{
	string bcdString = BCDStringFromStr(src, bSwitchDigits);
	return OCTET_STRING_new_fromBuf(asnType, bcdString.c_str(), bcdString.size());
}	
//-----------------------------
void BCDStringFromStr(BCDString_t* pDest, string src, bool bSwitchDigits=false)
{
	string bcdString = BCDStringFromStr(src, bSwitchDigits);
	OCTET_STRING_fromBuf(pDest, bcdString.c_str(), bcdString.size());
}

//-----------------------------
bool OctetStrCompare ( OCTET_STRING* pOctetStr, string str)
{
	if ((unsigned int)pOctetStr->size != str.length()) return false;

	if ( strncmp ( (const char*) pOctetStr->buf, str.c_str(), pOctetStr->size ) != 0 )
		return false;

	return true;
}
//------------------------------
bool equals(double a, double b)
{
	if (abs(a - b) < 10e-6)
		return true;
	else
		return false;
}

//-----------------------------
int OctetString_new_fromInt64(OCTET_STRING *&pOctetStr, asn_TYPE_descriptor_t* asnTypeDescriptor, long long value)
{
	unsigned char buf[8];
	int i;
	// fill buffer with value, most significant bytes first, less significant - last
	for( i=7; i>=0; i--) {
		buf[ i ] = value & 0xFF;
		value >>= 8;
		if (value == 0) break;
	}

	if( i==0 && value>0 )
		throw "8-byte integer overflow";

	if( buf[i] >= 0x80 ) {
		// it will be treated as negative value, so add one more byte
		if( i == 0 )
			throw "8-byte integer overflow";
		buf[ --i ] = 0;
	}
	
	pOctetStr = OCTET_STRING_new_fromBuf( asnTypeDescriptor, (const char*) (buf+i), 8-i);

	return 8-i;
}
//-----------------------------
int OctetString_fromInt64(OCTET_STRING& octetStr, long long value)
{
	unsigned char buf[8];
	int i;
	// fill buffer with value, most significant bytes first, less significant - last
	for( i=7; i>=0; i--) {
		buf[ i ] = value & 0xFF;
		value >>= 8;
		if (value == 0) break;
	}
	if( i==0 && value>0 )
		throw "8-byte integer overflow";

	if( buf[i] >= 0x80 ) {
		// it will be treated as negative value, so add one more byte
		if( i == 0 )
			throw "8-byte integer overflow";
		buf[ --i ] = 0;
	}

	OCTET_STRING_fromBuf( &octetStr, (const char*) (buf+i), 8-i);

	return 8-i;
}
//----------------------------
string GetUTCOffset(int nCode)
{
	for(int i=0; i<dataInterchange->choice.transferBatch.networkInfo->utcTimeOffsetInfo->list.count; i++)
	{	
		if( *dataInterchange->choice.transferBatch.networkInfo->utcTimeOffsetInfo->list.array[i]->utcTimeOffsetCode == nCode)
			return (string) (const char*)dataInterchange->choice.transferBatch.networkInfo->utcTimeOffsetInfo->list.array[i]->utcTimeOffset->buf;
	}
	// неверный код UTC offset
	return "???";
}
//-------------------------------
long GetUTCOffsetCode(string utcOffset)
{
	if ( dataInterchange->choice.transferBatch.networkInfo->utcTimeOffsetInfo == NULL )
		dataInterchange->choice.transferBatch.networkInfo->utcTimeOffsetInfo = (UtcTimeOffsetInfoList*) calloc (1, sizeof(UtcTimeOffsetInfoList));

	int i=0;
	for( ; i < dataInterchange->choice.transferBatch.networkInfo->utcTimeOffsetInfo->list.count; i++) {
		if ( OctetStrCompare( dataInterchange->choice.transferBatch.networkInfo->utcTimeOffsetInfo->list.array[i]->utcTimeOffset, utcOffset ))
			return *dataInterchange->choice.transferBatch.networkInfo->utcTimeOffsetInfo->list.array[i]->utcTimeOffsetCode;
	}

	// not found - create new UTC time offset info record
	UtcTimeOffsetInfo* pUtcOffsetInfo = (UtcTimeOffsetInfo*) calloc ( 1, sizeof(UtcTimeOffsetInfo));
	pUtcOffsetInfo->utcTimeOffset = OCTET_STRING_new_fromBuf (&asn_DEF_UtcTimeOffset, utcOffset.c_str(), utcOffset.size());
	pUtcOffsetInfo->utcTimeOffsetCode = (UtcTimeOffsetCode_t*) calloc ( 1, sizeof(UtcTimeOffsetCode_t));
	*pUtcOffsetInfo->utcTimeOffsetCode = ++i;

	ASN_SEQUENCE_ADD(dataInterchange->choice.transferBatch.networkInfo->utcTimeOffsetInfo, pUtcOffsetInfo);

	return *pUtcOffsetInfo->utcTimeOffsetCode;
}

//--------------------------------
long GetExchangeRateCode ( double exchangeRate )
{
	if ( dataInterchange->choice.transferBatch.accountingInfo->currencyConversionInfo == NULL )
		dataInterchange->choice.transferBatch.accountingInfo->currencyConversionInfo = (CurrencyConversionList*) calloc (1, sizeof(CurrencyConversionList));

	for(int i=0; i < dataInterchange->choice.transferBatch.accountingInfo->currencyConversionInfo->list.count; i++) {
		if ( *dataInterchange->choice.transferBatch.accountingInfo->currencyConversionInfo->list.array[i]->exchangeRate == 
				(long) floor(exchangeRate * pow( (double) 10, *dataInterchange->choice.transferBatch.accountingInfo->currencyConversionInfo->list.array[i]->numberOfDecimalPlaces) + 0.5))
			return *dataInterchange->choice.transferBatch.accountingInfo->currencyConversionInfo->list.array[i]->exchangeRateCode;
	}

	// not found - create new currency conversion info record
	int numOfDecimalPlaces = 6;	// According to TD.57 v32.3
	CurrencyConversion* pCurrencyConversion = (CurrencyConversion*) calloc ( 1, sizeof(CurrencyConversion));
	pCurrencyConversion->exchangeRate = (ExchangeRate_t*) calloc ( 1, sizeof(ExchangeRate_t));
	*pCurrencyConversion->exchangeRate = (long) floor(exchangeRate * pow( (double) 10, numOfDecimalPlaces) + 0.5);
	pCurrencyConversion->numberOfDecimalPlaces = (NumberOfDecimalPlaces_t*) calloc ( 1, sizeof(NumberOfDecimalPlaces_t));
	*pCurrencyConversion->numberOfDecimalPlaces = numOfDecimalPlaces;

	pCurrencyConversion->exchangeRateCode = (ExchangeRateCode_t*) calloc ( 1, sizeof(ExchangeRateCode_t));
	*pCurrencyConversion->exchangeRateCode = dataInterchange->choice.transferBatch.accountingInfo->currencyConversionInfo->list.count + 1; // next index in array of exchange rates

	ASN_SEQUENCE_ADD(dataInterchange->choice.transferBatch.accountingInfo->currencyConversionInfo, pCurrencyConversion);

	return *pCurrencyConversion->exchangeRateCode;
}
//-------------------------------
long GetTaxCode( double taxRate )
{
	if ( dataInterchange->choice.transferBatch.accountingInfo->taxation == NULL )
		dataInterchange->choice.transferBatch.accountingInfo->taxation = (TaxationList*) calloc (1, sizeof(TaxationList));

	int i=0;
	string taxStr = to_string(static_cast<unsigned long long> (taxRate * 100000 * 100)); // The rate is given to 5 decimal places, see TD.57 v32, and expresses in percents

	for( ; i < dataInterchange->choice.transferBatch.accountingInfo->taxation->list.count; i++) {
		if ( OctetStrCompare( dataInterchange->choice.transferBatch.accountingInfo->taxation->list.array[i]->taxRate, taxStr))
			return *dataInterchange->choice.transferBatch.accountingInfo->taxation->list.array[i]->taxCode;
	}

	// not found - create new currency conversion info record
	Taxation* pTaxation = (Taxation*) calloc ( 1, sizeof(Taxation));
	pTaxation->taxType = OCTET_STRING_new_fromBuf (&asn_DEF_TaxType, "01", 2);	// always use tax type 01 (National)
	pTaxation->taxRate = OCTET_STRING_new_fromBuf (&asn_DEF_TaxRate, taxStr.c_str(), taxStr.size());	
	pTaxation->taxCode = (TaxCode_t*) calloc ( 1, sizeof(TaxCode_t));
	*pTaxation->taxCode = ++i;

	ASN_SEQUENCE_ADD(dataInterchange->choice.transferBatch.accountingInfo->taxation, pTaxation);

	return *pTaxation->taxCode;
}
//--------------------------------
long GetDiscountCode( double discountRate, double fixedDiscountValue )
{
	if ( dataInterchange->choice.transferBatch.accountingInfo->discounting == NULL )
		dataInterchange->choice.transferBatch.accountingInfo->discounting = (DiscountingList*) calloc (1, sizeof(DiscountingList));

	int i=0;
	for( ; i < dataInterchange->choice.transferBatch.accountingInfo->discounting->list.count; i++) {
		if ( dataInterchange->choice.transferBatch.accountingInfo->discounting->list.array[i]->discountApplied->present == DiscountApplied_PR_discountRate )
			if ( dataInterchange->choice.transferBatch.accountingInfo->discounting->list.array[i]->discountApplied->choice.discountRate ==  floor(discountRate * 100 +0.5)) // The rate is held to 2 decimal places, see TD 57 v32.3
				return *dataInterchange->choice.transferBatch.accountingInfo->discounting->list.array[i]->discountCode;

		if ( dataInterchange->choice.transferBatch.accountingInfo->discounting->list.array[i]->discountApplied->present == DiscountApplied_PR_fixedDiscountValue )
			if ( dataInterchange->choice.transferBatch.accountingInfo->discounting->list.array[i]->discountApplied->choice.discountRate ==  
					floor( fixedDiscountValue * dblTAPPower + 0.5) ) // here default TAP decimal places are used
				return *dataInterchange->choice.transferBatch.accountingInfo->discounting->list.array[i]->discountCode;
	}

	// not found - create new discount record
	Discounting* pDiscounting = (Discounting*) calloc ( 1, sizeof(Discounting));
	pDiscounting->discountApplied = (DiscountApplied_t*) calloc ( 1, sizeof(DiscountApplied_t));
	
	if( discountRate >= 0  && fixedDiscountValue < 0 ) {
		pDiscounting->discountApplied->present = DiscountApplied_PR_discountRate;
		pDiscounting->discountApplied->choice.discountRate = (long) (discountRate * 100);
	}
	
	if( discountRate < 0  && fixedDiscountValue >= 0 ) {
		pDiscounting->discountApplied->present = DiscountApplied_PR_fixedDiscountValue;
		// was before 8-byte integers pDiscounting->discountApplied->choice.fixedDiscountValue = fixedDiscountValue * dblTAPPower;
		OctetString_fromInt64( pDiscounting->discountApplied->choice.fixedDiscountValue, (long long) floor(fixedDiscountValue * dblTAPPower +0.5));
	}

	pDiscounting->discountCode = (DiscountCode_t*) calloc ( 1, sizeof(DiscountCode_t));
	*pDiscounting->discountCode = ++i;

	ASN_SEQUENCE_ADD(dataInterchange->choice.transferBatch.accountingInfo->discounting, pDiscounting);

	return *pDiscounting->discountCode;
}
//-----------------------------
void AddToRecordingEntityCodeList(RecEntityCodeList* pRecEntityCodeList, string recEntity, long recEntityTypeCode)
{
	RecEntityCode_t* pRecEntityCode = (RecEntityCode_t*)calloc(1, sizeof(RecEntityCode_t));
	bool bFound = false;
	for (int i = 0; i < dataInterchange->choice.transferBatch.networkInfo->recEntityInfo->list.count; i++) {
		if (OctetStrCompare(dataInterchange->choice.transferBatch.networkInfo->recEntityInfo->list.array[i]->recEntityId, recEntity) &&
			*dataInterchange->choice.transferBatch.networkInfo->recEntityInfo->list.array[i]->recEntityType == recEntityTypeCode) {

			*pRecEntityCode = *dataInterchange->choice.transferBatch.networkInfo->recEntityInfo->list.array[i]->recEntityCode;
			ASN_SEQUENCE_ADD(pRecEntityCodeList, pRecEntityCode);
			bFound = true;
			break;
		}
	}

	if (!bFound) {
		// not found in list - creating
		RecEntityInformation * pRecEntityInfo = (RecEntityInformation *)calloc(1, sizeof(RecEntityInformation));
		pRecEntityInfo->recEntityId = OCTET_STRING_new_fromBuf(&asn_DEF_RecEntityId, recEntity.c_str(), recEntity.size());
		pRecEntityInfo->recEntityType = (RecEntityType_t*)calloc(1, sizeof(RecEntityType_t));
		*pRecEntityInfo->recEntityType = recEntityTypeCode;
		pRecEntityInfo->recEntityCode = (RecEntityCode_t *)calloc(1, sizeof(RecEntityCode_t));
		*pRecEntityInfo->recEntityCode = dataInterchange->choice.transferBatch.networkInfo->recEntityInfo->list.count + 1;	// use next index in list starting from 1

		*pRecEntityCode = *pRecEntityInfo->recEntityCode;
		ASN_SEQUENCE_ADD(pRecEntityCodeList, pRecEntityCode);
		ASN_SEQUENCE_ADD(dataInterchange->choice.transferBatch.networkInfo->recEntityInfo, pRecEntityInfo);
	}
}
//-----------------------------

int FillLocationInfo(LocationInformation* pLocationInfo, string recEntity, long recEntityTypeCode, long locationArea, long cellID, string servingNetwork)
{
	pLocationInfo->networkLocation = (NetworkLocation*) calloc (1, sizeof(NetworkLocation));
	pLocationInfo->networkLocation->recEntityCode = (RecEntityCode_t*) calloc ( 1, sizeof(RecEntityCode_t));

	if ( dataInterchange->choice.transferBatch.networkInfo->recEntityInfo == NULL )
		dataInterchange->choice.transferBatch.networkInfo->recEntityInfo = (RecEntityInfoList*) calloc (1, sizeof(RecEntityInfoList));

	bool bFound = false;
	for(int i=0 ; i < dataInterchange->choice.transferBatch.networkInfo->recEntityInfo->list.count; i++) {
		if ( OctetStrCompare( dataInterchange->choice.transferBatch.networkInfo->recEntityInfo->list.array[i]->recEntityId, recEntity ) && 
				*dataInterchange->choice.transferBatch.networkInfo->recEntityInfo->list.array[i]->recEntityType == recEntityTypeCode) {
		
			*pLocationInfo->networkLocation->recEntityCode =  *dataInterchange->choice.transferBatch.networkInfo->recEntityInfo->list.array[i]->recEntityCode;
			bFound = true;
			break;
		}
	}

	if( !bFound ) {
		// not found in list - creating
		RecEntityInformation * pRecEntityInfo = (RecEntityInformation *) calloc ( 1, sizeof(RecEntityInformation ));
		pRecEntityInfo->recEntityId = OCTET_STRING_new_fromBuf (&asn_DEF_RecEntityId, recEntity.c_str(), recEntity.size());
		pRecEntityInfo->recEntityType = (RecEntityType_t*) calloc ( 1, sizeof(RecEntityType_t));
		*pRecEntityInfo->recEntityType = recEntityTypeCode;
		pRecEntityInfo->recEntityCode = (RecEntityCode_t *)  calloc ( 1, sizeof(RecEntityCode_t));
		*pRecEntityInfo->recEntityCode = dataInterchange->choice.transferBatch.networkInfo->recEntityInfo->list.count + 1; // use next index in list starting from 1

		ASN_SEQUENCE_ADD(dataInterchange->choice.transferBatch.networkInfo->recEntityInfo, pRecEntityInfo);
	
		*pLocationInfo->networkLocation->recEntityCode = *pRecEntityInfo->recEntityCode;
	}

	if( locationArea != -1 ) {
		pLocationInfo->networkLocation->locationArea = (LocationArea_t*) calloc (1, sizeof(LocationArea_t));
		*pLocationInfo->networkLocation->locationArea = locationArea;
	}

	if( cellID != -1 ) {
		pLocationInfo->networkLocation->cellId = (CellId_t*) calloc (1, sizeof(CellId_t));
		*pLocationInfo->networkLocation->cellId = cellID;
	}

	if ( servingNetwork.length()>0 ) {
		pLocationInfo->geographicalLocation = (GeographicalLocation_t*) calloc (1, sizeof(GeographicalLocation_t));
		pLocationInfo->geographicalLocation->servingNetwork = OCTET_STRING_new_fromBuf(&asn_DEF_ServingNetwork, servingNetwork.c_str(), servingNetwork.size());
	}

	return 0;

}
//-----------------------------
// GPRS version of FillLocationInfo
//-----------------------------
int FillLocationInfo(GprsLocationInformation* pLocationInfo, string recEntity1, long recEntity1TypeCode, string recEntity2, long recEntity2TypeCode, 
					long locationArea, long cellID, string servingNetwork)
{
	pLocationInfo->gprsNetworkLocation = (GprsNetworkLocation*) calloc (1, sizeof(GprsNetworkLocation));
	
	if ( !recEntity1.empty() || !recEntity2.empty() ) {
		pLocationInfo->gprsNetworkLocation->recEntity = (RecEntityCodeList*)calloc(1, sizeof(RecEntityCodeList));

		if ( dataInterchange->choice.transferBatch.networkInfo->recEntityInfo == NULL )
			dataInterchange->choice.transferBatch.networkInfo->recEntityInfo = (RecEntityInfoList*)calloc(1, sizeof(RecEntityInfoList));

		if ( !recEntity1.empty() ) 
			AddToRecordingEntityCodeList(pLocationInfo->gprsNetworkLocation->recEntity, recEntity1, recEntity1TypeCode);

		if ( !recEntity2.empty() )
			AddToRecordingEntityCodeList(pLocationInfo->gprsNetworkLocation->recEntity, recEntity2, recEntity2TypeCode);
	}

	if( locationArea != -1) {
		pLocationInfo->gprsNetworkLocation->locationArea = (LocationArea_t*) calloc (1, sizeof(LocationArea_t));
		*pLocationInfo->gprsNetworkLocation->locationArea = locationArea;
	}

	if( cellID != -1) {
		pLocationInfo->gprsNetworkLocation->cellId = (CellId_t*) calloc (1, sizeof(CellId_t));
		*pLocationInfo->gprsNetworkLocation->cellId = cellID;
	}

	if ( servingNetwork.length()>0 ) {
		pLocationInfo->geographicalLocation = (GeographicalLocation_t*) calloc (1, sizeof(GeographicalLocation_t));
		pLocationInfo->geographicalLocation->servingNetwork = OCTET_STRING_new_fromBuf(&asn_DEF_ServingNetwork, servingNetwork.c_str(), servingNetwork.size());
	}

	return 0;

}

//-----------------------------
int FillChargeInfo(long eventID, ChargeInformationList* pChargeInformationList)
{
	otl_nocommit_stream otlChrStream, otlChrDetStream;
	double fixedDiscountValue = 0;
	long chargeID, ctLevel1, ctLevel2, ctLevel3;
	string chrItem;
	double exchangeRate, taxRate, taxValue, discountRate, discountValue;

	otlChrStream.open( 1 , "select CHARGE_ID /*long*/, CHR_ITEM /*char*/, nvl(EXCHANGE_RATE, -1) /*double*/,nvl(CT_LEVEL1,-1) /*long*/, nvl(CT_LEVEL2, -1) /*long*/, nvl(CT_LEVEL3, -1) /*long*/,"
		"nvl(TAX_RATE,-1) /*double*/, nvl(TAX_VAL,-1) /*double*/, nvl(DISCOUNT_RATE,-1) /*double*/, nvl(FIXED_DISCOUNT_VALUE,-1) /*double*/ , nvl(DISCOUNT_VALUE,-1) /*double*/ "
		"from BILLING.TAP3_CHARGEINFO "
		"where EVENT_ID = :hEventId /*long*/", otlConnect );
	otlChrStream << eventID ;

	while( !otlChrStream.eof()) {
		otlChrStream
			>> chargeID
			>> chrItem
			>> exchangeRate
			>> ctLevel1
			>> ctLevel2
			>> ctLevel3
			>> taxRate
			>> taxValue
			>> discountRate
			>> fixedDiscountValue
			>> discountValue;

		ChargeInformation* pChrInfo = (ChargeInformation*) calloc (1, sizeof(ChargeInformation));

		pChrInfo->chargedItem = OCTET_STRING_new_fromBuf(&asn_DEF_ChargedItem, chrItem.c_str(), chrItem.size());
		if ( !equals(exchangeRate, -1)) {
			pChrInfo->exchangeRateCode = (ExchangeRateCode_t*) calloc (1, sizeof(ExchangeRateCode_t));
			*pChrInfo->exchangeRateCode = GetExchangeRateCode ( exchangeRate );
		}
		if( ctLevel1 !=-1 || ctLevel2 != -1 || ctLevel3 != -1) {
			pChrInfo->callTypeGroup = (CallTypeGroup*) calloc (1, sizeof(CallTypeGroup));
			if ( ctLevel1 !=-1 ) {
				pChrInfo->callTypeGroup->callTypeLevel1 = (CallTypeLevel1_t*) calloc (1, sizeof(CallTypeLevel1_t));
				*pChrInfo->callTypeGroup->callTypeLevel1 = ctLevel1;
			}
			if ( ctLevel2 !=-1 ) {
				pChrInfo->callTypeGroup->callTypeLevel2 = (CallTypeLevel2_t*) calloc (1, sizeof(CallTypeLevel2_t));
				*pChrInfo->callTypeGroup->callTypeLevel2 = ctLevel2;
			}
			if ( ctLevel3 !=-1 ) {
				pChrInfo->callTypeGroup->callTypeLevel3 = (CallTypeLevel3_t*) calloc (1, sizeof(CallTypeLevel3_t));
				*pChrInfo->callTypeGroup->callTypeLevel3 = ctLevel3;
			}
		}
			
		// Fill Charge Detail Data
		pChrInfo->chargeDetailList = (ChargeDetailList*) calloc ( 1, sizeof(ChargeDetailList));
		string chrType, detailTime, detailUTC;
		double charge;
		OTL_BIGINT chargeableUnits, chargedUnits;

		otlChrDetStream.open( 1 , "select CHR_TYPE /*char*/, CHARGE /*double*/, nvl(CHARGEABLE_UNITS,-1) :#3<bigint>, nvl(CHARGED_UNITS,-1) :#4<bigint>,"
			"to_char(DETAIL_TIME /*char*/,'yyyymmddhh24miss'), DETAIL_UTCOFF /*char*/ "
			"from BILLING.TAP3_CHARGEDETAIL where CHARGE_ID=:hChrID /*long*/", otlConnect);

		otlChrDetStream	<< chargeID;
		while( !otlChrDetStream.eof()) {
			otlChrDetStream
				>> chrType
				>> charge
				>> chargeableUnits
				>> chargedUnits
				>> detailTime
				>> detailUTC;

			ChargeDetail* pChrDetail = (ChargeDetail*) calloc (1, sizeof(ChargeDetail));
			pChrDetail->chargeType = OCTET_STRING_new_fromBuf(&asn_DEF_ChargeType, chrType.c_str(), chrType.size());
			// was before 8-byte integers pChrDetail->charge = (Charge_t*) calloc (1, sizeof(Charge_t));
			OctetString_new_fromInt64( pChrDetail->charge, &asn_DEF_Charge, (long long) floor(charge * dblTAPPower +0.5) );
			if( chargeableUnits != -1 ) {
				//pChrDetail->chargeableUnits = (ChargeableUnits_t*) calloc (1, sizeof(ChargeableUnits_t));
				OctetString_new_fromInt64(pChrDetail->chargeableUnits, &asn_DEF_ChargeableUnits, chargeableUnits);
			}
			if( chargedUnits != -1 ) {
				//pChrDetail->chargedUnits = (ChargedUnits_t*) calloc (1, sizeof(ChargedUnits_t));
				OctetString_new_fromInt64(pChrDetail->chargedUnits, &asn_DEF_ChargedUnits, chargedUnits);
			}
			if ( detailTime.length() > 0 ) {
				pChrDetail->chargeDetailTimeStamp = (DateTime*) calloc (1, sizeof(DateTime));
				pChrDetail->chargeDetailTimeStamp->localTimeStamp = OCTET_STRING_new_fromBuf(&asn_DEF_DateTime, detailTime.c_str(), detailTime.size());
				pChrDetail->chargeDetailTimeStamp->utcTimeOffsetCode = (UtcTimeOffsetCode_t*) calloc (1, sizeof(UtcTimeOffsetCode_t));
				*pChrDetail->chargeDetailTimeStamp->utcTimeOffsetCode = GetUTCOffsetCode(detailUTC);
			}

			ASN_SEQUENCE_ADD(pChrInfo->chargeDetailList, pChrDetail);
		}
		otlChrDetStream.close();

		if (!equals(taxRate, -1) && !equals(taxValue, -1)) {
			pChrInfo->taxInformation = (TaxInformationList*) calloc (1, sizeof(TaxInformationList));

			TaxInformation* pTaxInfo = (TaxInformation*) calloc (1, sizeof(TaxInformation));
			pTaxInfo->taxCode = (TaxCode_t*) calloc ( 1, sizeof(TaxCode_t) );
			*pTaxInfo->taxCode = GetTaxCode( taxRate ); 
			// was before 8-byte integers pTaxInfo->taxValue = (TaxValue_t*) calloc ( 1, sizeof(TaxValue_t) );
			OctetString_new_fromInt64(pTaxInfo->taxValue, &asn_DEF_TaxValue, (long long) floor(taxValue * dblTAPPower + 0.5));

			ASN_SEQUENCE_ADD(pChrInfo->taxInformation, pTaxInfo);
		}

		if (!equals(discountRate, -1) || !equals(discountValue, -1) || !equals(fixedDiscountValue, -1)) {	// comparing floating point numbers
			pChrInfo->discountInformation = (DiscountInformation*) calloc (1, sizeof(DiscountInformation));

			pChrInfo->discountInformation->discountCode = (DiscountCode_t*) calloc ( 1, sizeof(DiscountCode_t) );
			long discountCode = GetDiscountCode( discountRate,  fixedDiscountValue); 
			if( discountCode != -1 )
				*pChrInfo->discountInformation->discountCode = discountCode;

			if (!equals(discountValue, -1)) {
				// was before 8-byte integerspChrInfo->discountInformation->discount = (DiscountValue_t*) calloc ( 1, sizeof(Discount_t) );
				OctetString_new_fromInt64(pChrInfo->discountInformation->discount, &asn_DEF_Discount, (long long) floor(discountValue * dblTAPPower + 0.5));
			}
		}

		ASN_SEQUENCE_ADD(pChargeInformationList, pChrInfo);
	}
	otlChrStream.close();

	return 0;
}



//--------------------------------------------------
int FillBasicServiceUsed(long eventID, BasicServiceUsedList* pBSUList)
{
	otl_nocommit_stream otlStream, otlChrStream, otlChrDetStream;
	long serviceID, serviceType, hsCSD;
	string serviceCode, chrTime, chrTimeUTC;

	otlStream.open( 1 , "select SERVICE_ID /*long*/, SERVICE_TYPE /*long*/,SERVICE_CODE /*char[10]*/, "
		"to_char(CHR_TIME,'yyyymmddhh24miss') /*char[20]*/, CHR_UTCOFF /*char[10]*/, nvl(HSCSD,-1) /*long*/"
		"from BILLING.TAP3_BASICSERVICE where EVENT_ID = :hEventId /*long*/", otlConnect);

	otlStream << eventID;

	while( !otlStream.eof()) {
		otlStream 
			>> serviceID
			>> serviceType
			>> serviceCode
			>> chrTime
			>> chrTimeUTC
			>> hsCSD;

		BasicServiceUsed* pBSU = (BasicServiceUsed*) calloc(1, sizeof(BasicServiceUsed));
		pBSU->basicService = (BasicService*) calloc(1, sizeof(BasicService));
		pBSU->basicService->serviceCode = (BasicServiceCode*) calloc(1, sizeof(BasicServiceCode));
		pBSU->basicService->serviceCode->present = serviceType ? BasicServiceCode_PR_bearerServiceCode : BasicServiceCode_PR_teleServiceCode;
		if ( serviceType == 0 )
			OCTET_STRING_fromBuf( &pBSU->basicService->serviceCode->choice.teleServiceCode , serviceCode.c_str(), serviceCode.size());
		else
			OCTET_STRING_fromBuf( &pBSU->basicService->serviceCode->choice.bearerServiceCode , serviceCode.c_str(), serviceCode.size());

		if ( chrTime.length() > 0 ) {
			pBSU->chargingTimeStamp = (DateTime*) calloc (1, sizeof(DateTime));
			pBSU->chargingTimeStamp->localTimeStamp = OCTET_STRING_new_fromBuf(&asn_DEF_DateTime, chrTime.c_str(), chrTime.size());
			pBSU->chargingTimeStamp->utcTimeOffsetCode = (UtcTimeOffsetCode_t*) calloc (1, sizeof(UtcTimeOffsetCode_t));
			*pBSU->chargingTimeStamp->utcTimeOffsetCode = GetUTCOffsetCode(chrTimeUTC);
		}

		if( hsCSD > 0 ) 
			pBSU->hSCSDIndicator = OCTET_STRING_new_fromBuf(&asn_DEF_HSCSDIndicator, to_string(static_cast<unsigned long long> (hsCSD)).c_str(), to_string(static_cast<unsigned long long> (hsCSD)).size());

		// Fill Charge Information
		pBSU->chargeInformationList = (ChargeInformationList*) calloc (1, sizeof(ChargeInformationList));

		FillChargeInfo( serviceID, pBSU->chargeInformationList );

		ASN_SEQUENCE_ADD(pBSUList, pBSU);
	}

	otlStream.close();
	return 0;
}
//-----------------------------
void Finalize(string filename, bool bSuccess = false)
{
	//if( dataInterchange )
	//	ASN_STRUCT_FREE(asn_DEF_DataInterChange, dataInterchange);
	if( otlConnect.connected ) {
		if( bSuccess )
			otlConnect.commit();
		else
			otlConnect.rollback();
		otlConnect.logoff();
	}

	if( otlLogConnect.connected ) {
		log( filename, bSuccess? LOG_INFO : LOG_ERROR, bSuccess ? "-------- TAP3 writer finished successfully ------------" : "-------- TAP3 writer finished with errors ------------");
		otlLogConnect.commit();
		otlLogConnect.logoff();
	}

	if(ofsLog.is_open()) ofsLog.close();
}
//-----------------------------
int assign_integer_option(string _name, string _value, long& param, long minValid, long maxValid, string& errorDescr)
{
	size_t stoi_idx;
	try {
		param = stoi(_value, &stoi_idx);
	}
	catch(...) {
		errorDescr = "Wrong value for " + _name + " given in ini-file.";
		return -1;
	}
	if(stoi_idx < _value.length()) {
		errorDescr = "Wrong value for " + _name + " given in ini-file.";
		return -1;
	}
	if(param<minValid || param>maxValid) {
		errorDescr = "Wrong value for " + _name + " given in ini-file. Valid range is from " 
			+ to_string(static_cast<unsigned long long> (minValid)) + " to " + to_string(static_cast<unsigned long long> (maxValid));
		return -1;
	}
	
	return 0;
}
//------------------------------

bool UploadFileToFtp(string filename, string fullFileName, FtpSetting ftpSetting, string roamingHubName)
{
	try {
		if (ftpSetting.ftpPort.length() == 0)
			ftpSetting.ftpPort = "21";	// use default ftp port
		int ncftp_argc = 11;
		const char* pszArguments[] = { "ncftpput", "-u", ftpSetting.ftpUsername.c_str(), "-p", ftpSetting.ftpPassword.c_str(), "-P", ftpSetting.ftpPort.c_str(), 
			ftpSetting.ftpServer.c_str(), ftpSetting.ftpDirectory.c_str(), fullFileName.c_str(), NULL };
		char szFtpResult[4096];
		int ftpResult = ncftp_main(ncftp_argc, (char**)pszArguments, szFtpResult);
		if (ftpResult != 0) {
			log(filename, LOG_ERROR, "Error while uploading file " + filename + " on FTP server " + ftpSetting.ftpServer + ":");
			log(filename, LOG_ERROR, szFtpResult);
			return false;
		}
		log(filename, LOG_INFO, "Successful upload to FTP server " + ftpSetting.ftpServer + " for " + roamingHubName);
		return true;
	}
	catch (...) {
		log(filename, LOG_ERROR, "Exception while uploading " + filename + " to FTP server " + ftpSetting.ftpServer + ". Uploading failed.");
		return false;
	}
}
//------------------------------
long FillDataIntercharge(DataInterChange* dataInterchange, otl_nocommit_stream& otlFileStream, string& filename, string& roamingHubName, string& fileAvailableTimeStamp)
{
	string sender, recipient, fileSequenceNumber, fileCreationTimeStamp, fileCreationTimeStampUTC, transferCutOffTimeStamp, transferCutOffTimeStampUTC,
		fileAvailableTimeStampUTC, localCurrency, loadTime, earliestTime, earliestTimeUTC, latestTime, latestTimeUTC, fileTypeIndicator, rapFileSeqNum;		
	long fileID, eventCount, notification, tapVersion, tapRelease, tapDecimalPlaces;
	double totalCharge, totalTax, totalDiscount;

	otlFileStream
		>> fileID
		>> filename
		>> sender
		>> recipient
		>> fileSequenceNumber
		>> fileCreationTimeStamp
		>> fileCreationTimeStampUTC
		>> transferCutOffTimeStamp
		>> transferCutOffTimeStampUTC
		>> fileAvailableTimeStamp		
		>> fileAvailableTimeStampUTC
		>> localCurrency
		>> loadTime
		>> earliestTime
		>> earliestTimeUTC
		>> latestTime
		>> latestTimeUTC
		>> eventCount
		>> totalCharge
		>> totalTax
		>> totalDiscount
		>> fileTypeIndicator
		>> rapFileSeqNum
		>> notification
		>> tapVersion
		>> tapRelease
		>> tapDecimalPlaces
		>> roamingHubName
		;
	
	if (notification == 0) {
		// processing file having call records (transfer batch)
		log(filename, LOG_INFO, "Creating Transer Batch TAP file");

		dataInterchange->present = DataInterChange_PR_transferBatch;
		dataInterchange->choice.transferBatch.accountingInfo = (AccountingInfo*)calloc(1, sizeof(AccountingInfo));
		dataInterchange->choice.transferBatch.batchControlInfo = (BatchControlInfo*)calloc(1, sizeof(BatchControlInfo));
		dataInterchange->choice.transferBatch.networkInfo = (NetworkInfo*)calloc(1, sizeof(NetworkInfo));
		dataInterchange->choice.transferBatch.auditControlInfo = (AuditControlInfo*)calloc(1, sizeof(AuditControlInfo));

		dataInterchange->choice.transferBatch.batchControlInfo->sender = OCTET_STRING_new_fromBuf(&asn_DEF_Sender, sender.c_str(), sender.size());
		dataInterchange->choice.transferBatch.batchControlInfo->recipient = OCTET_STRING_new_fromBuf(&asn_DEF_Recipient, recipient.c_str(), recipient.size());
		dataInterchange->choice.transferBatch.batchControlInfo->fileSequenceNumber = OCTET_STRING_new_fromBuf(&asn_DEF_FileSequenceNumber, fileSequenceNumber.c_str(), fileSequenceNumber.size());

		if (fileCreationTimeStamp.length() > 0) {
			dataInterchange->choice.transferBatch.batchControlInfo->fileCreationTimeStamp = (DateTimeLong*)calloc(1, sizeof(DateTimeLong));
			dataInterchange->choice.transferBatch.batchControlInfo->fileCreationTimeStamp->localTimeStamp = OCTET_STRING_new_fromBuf(&asn_DEF_LocalTimeStamp, fileCreationTimeStamp.c_str(), fileCreationTimeStamp.size());
			dataInterchange->choice.transferBatch.batchControlInfo->fileCreationTimeStamp->utcTimeOffset = OCTET_STRING_new_fromBuf(&asn_DEF_UtcTimeOffset, fileCreationTimeStampUTC.c_str(), fileCreationTimeStampUTC.size());
		}

		dataInterchange->choice.transferBatch.batchControlInfo->transferCutOffTimeStamp = (DateTimeLong*)calloc(1, sizeof(DateTimeLong));
		dataInterchange->choice.transferBatch.batchControlInfo->transferCutOffTimeStamp->localTimeStamp = OCTET_STRING_new_fromBuf(&asn_DEF_LocalTimeStamp, transferCutOffTimeStamp.c_str(), transferCutOffTimeStamp.size());
		dataInterchange->choice.transferBatch.batchControlInfo->transferCutOffTimeStamp->utcTimeOffset = OCTET_STRING_new_fromBuf(&asn_DEF_UtcTimeOffset, transferCutOffTimeStampUTC.c_str(), transferCutOffTimeStampUTC.size());

		dataInterchange->choice.transferBatch.batchControlInfo->fileAvailableTimeStamp = (DateTimeLong*)calloc(1, sizeof(DateTimeLong));
		dataInterchange->choice.transferBatch.batchControlInfo->fileAvailableTimeStamp->localTimeStamp = OCTET_STRING_new_fromBuf(&asn_DEF_LocalTimeStamp, fileAvailableTimeStamp.c_str(), fileAvailableTimeStamp.size());
		dataInterchange->choice.transferBatch.batchControlInfo->fileAvailableTimeStamp->utcTimeOffset = OCTET_STRING_new_fromBuf(&asn_DEF_UtcTimeOffset, fileAvailableTimeStampUTC.c_str(), fileAvailableTimeStampUTC.size());

		dataInterchange->choice.transferBatch.batchControlInfo->specificationVersionNumber = (SpecificationVersionNumber_t*)calloc(1, sizeof(SpecificationVersionNumber_t));
		*dataInterchange->choice.transferBatch.batchControlInfo->specificationVersionNumber = tapVersion;
		dataInterchange->choice.transferBatch.batchControlInfo->releaseVersionNumber = (ReleaseVersionNumber_t*)calloc(1, sizeof(ReleaseVersionNumber_t));
		*dataInterchange->choice.transferBatch.batchControlInfo->releaseVersionNumber = tapRelease;

		if (fileTypeIndicator.length() > 0)
			dataInterchange->choice.transferBatch.batchControlInfo->fileTypeIndicator = OCTET_STRING_new_fromBuf(&asn_DEF_FileTypeIndicator, fileTypeIndicator.c_str(), fileTypeIndicator.size());

		if (rapFileSeqNum.length() > 0)
			dataInterchange->choice.transferBatch.batchControlInfo->rapFileSequenceNumber = OCTET_STRING_new_fromBuf(&asn_DEF_RapFileSequenceNumber, rapFileSeqNum.c_str(), rapFileSeqNum.size());

		dataInterchange->choice.transferBatch.accountingInfo->localCurrency = OCTET_STRING_new_fromBuf(&asn_DEF_LocalCurrency, localCurrency.c_str(), localCurrency.size());

		dataInterchange->choice.transferBatch.accountingInfo->tapDecimalPlaces = (TapDecimalPlaces_t*)calloc(1, sizeof(TapDecimalPlaces_t));
		*dataInterchange->choice.transferBatch.accountingInfo->tapDecimalPlaces = tapDecimalPlaces; // This is the number of decimal places we use while encoding floats
		dblTAPPower = pow((double)10, tapDecimalPlaces);

		// Processing calls
		long eventID, RSN, origOrTerm, clir, duration, causeForTerm, locationArea, cellID, recEntityTypeCode, recEntity2TypeCode;
		OTL_BIGINT volumeIncoming, volumeOutgoing, chargingID;
		string IMSI, MSISDN, partyNumber, dialledDigits, thirdParty, smsPartyNumber, callTime, callUTC, recEntity, recEntityType, recEntity2, recEntity2Type, 
			servingNetwork, IMEI, PDPAddress, APN_NI, APN_OI, PDPStartTime, PDPStartUTC, partialType;

		dataInterchange->choice.transferBatch.callEventDetails = (CallEventDetailList*)calloc(1, sizeof(CallEventDetailList));

		otl_nocommit_stream otlStream;
		otlStream.open(100, // stream buffer size in logical rows
			"select EVENT_ID /*long*/, RSN /*long*/, ORIG_OR_TERM /*long*/, IMSI /*char*/, MSISDN /*char*/, PARTY_NUMBER /*char*/, DIALLED_DIGITS /*char*/, THIRD_PARTY /*char*/, "
			"SMS_PARTYNUMBER /*char*/, nvl(CLIR, -1) /*long*/, to_char(CALL_TIME, 'yyyymmddhh24miss') /*char*/, "
			"CALL_UTCOFF /*char*/, DURATION /*long*/, nvl(CAUSE_FOR_TERM, -1) /*long*/, REC_ENTITY /*char*/, REC_ENTITY_TYPE /*char*/, "
			"decode(REC_ENTITY_TYPE, 'MSC', 1, 'SMSC', 2, 'GGSN/P-GW', 3, 'SGSN', 4, 'GMLC', 5, 'Wi-Fi', 6, 'P-GW', 7, 'S-GW', 8, 'P-CSCF', 9, 'TRF', 10, 'ATCF', 11, -1) REC_ENTITY_TYPE_CODE /*long*/, "
			"nvl(LOCATION_AREA, -1) /*long*/, nvl(CELL_ID, -1) /*long*/, SERVING_NETWORK /*char*/,"
			"IMEI /*char*/, RAP_FILE_SEQNUM /*char*/"
			"from BILLING.TAP3_CALL where FILE_ID=:hFileID /*long*/ order by RSN",
			otlConnect
			);

		otlStream << fileID;

		while (!otlStream.eof()) {
			otlStream
				>> eventID
				>> RSN
				>> origOrTerm
				>> IMSI
				>> MSISDN
				>> partyNumber
				>> dialledDigits
				>> thirdParty
				>> smsPartyNumber
				>> clir
				>> callTime
				>> callUTC
				>> duration
				>> causeForTerm
				>> recEntity
				>> recEntityType
				>> recEntityTypeCode
				>> locationArea
				>> cellID
				>> servingNetwork
				>> IMEI
				>> rapFileSeqNum;

			CallEventDetail* callED = (CallEventDetail*)calloc(1, sizeof(CallEventDetail));
			if (origOrTerm > 0) {
				// Mobile Originated Call
				callED->present = CallEventDetail_PR_mobileOriginatedCall;
				callED->choice.mobileOriginatedCall.basicCallInformation = (MoBasicCallInformation*)calloc(1, sizeof(MoBasicCallInformation));
				callED->choice.mobileOriginatedCall.basicCallInformation->chargeableSubscriber = (ChargeableSubscriber*)calloc(1, sizeof(ChargeableSubscriber));
				callED->choice.mobileOriginatedCall.basicCallInformation->chargeableSubscriber->present = ChargeableSubscriber_PR_simChargeableSubscriber;
				if (IMSI.length() > 0)
					callED->choice.mobileOriginatedCall.basicCallInformation->chargeableSubscriber->choice.simChargeableSubscriber.imsi =
					BCDString_new_FromStr(&asn_DEF_Imsi, IMSI);
				if (MSISDN.length() > 0)
					callED->choice.mobileOriginatedCall.basicCallInformation->chargeableSubscriber->choice.simChargeableSubscriber.msisdn =
					BCDString_new_FromStr(&asn_DEF_Msisdn, MSISDN);
				if (rapFileSeqNum.length() > 0)
					callED->choice.mobileOriginatedCall.basicCallInformation->rapFileSequenceNumber =
					OCTET_STRING_new_fromBuf(&asn_DEF_RapFileSequenceNumber, rapFileSeqNum.c_str(), rapFileSeqNum.size());
				callED->choice.mobileOriginatedCall.basicCallInformation->destination = (Destination*)calloc(1, sizeof(Destination));
				if (partyNumber.length() > 0)
					callED->choice.mobileOriginatedCall.basicCallInformation->destination->calledNumber = BCDString_new_FromStr(&asn_DEF_CalledNumber, partyNumber);
				if (dialledDigits.length() > 0)
					callED->choice.mobileOriginatedCall.basicCallInformation->destination->dialledDigits =
					OCTET_STRING_new_fromBuf(&asn_DEF_DialledDigits, dialledDigits.c_str(), dialledDigits.size());
				if (smsPartyNumber.length() > 0)
					callED->choice.mobileOriginatedCall.basicCallInformation->destination->sMSDestinationNumber = OCTET_STRING_new_fromBuf(&asn_DEF_SMSOriginator, smsPartyNumber.c_str(), smsPartyNumber.size());
				callED->choice.mobileOriginatedCall.basicCallInformation->callEventStartTimeStamp = (DateTime*)calloc(1, sizeof(asn_DEF_DateTime));
				callED->choice.mobileOriginatedCall.basicCallInformation->callEventStartTimeStamp->localTimeStamp = OCTET_STRING_new_fromBuf(&asn_DEF_DateTime, callTime.c_str(), callTime.size());

				callED->choice.mobileOriginatedCall.basicCallInformation->callEventStartTimeStamp->utcTimeOffsetCode = (UtcTimeOffsetCode_t*)calloc(1, sizeof(UtcTimeOffsetCode_t));
				*callED->choice.mobileOriginatedCall.basicCallInformation->callEventStartTimeStamp->utcTimeOffsetCode = GetUTCOffsetCode(callUTC);

				callED->choice.mobileOriginatedCall.basicCallInformation->totalCallEventDuration = (TotalCallEventDuration_t*)calloc(1, sizeof(TotalCallEventDuration_t));
				*callED->choice.mobileOriginatedCall.basicCallInformation->totalCallEventDuration = duration;
				if (causeForTerm != -1) {
					callED->choice.mobileOriginatedCall.basicCallInformation->causeForTerm = (CauseForTerm_t*)calloc(1, sizeof(CauseForTerm_t));
					*callED->choice.mobileOriginatedCall.basicCallInformation->causeForTerm = causeForTerm;
				}

				callED->choice.mobileOriginatedCall.locationInformation = (LocationInformation*)calloc(1, sizeof(LocationInformation));
				FillLocationInfo(callED->choice.mobileOriginatedCall.locationInformation, recEntity, recEntityTypeCode, locationArea, cellID, servingNetwork);

				if (IMEI.length() > 0) {
					callED->choice.mobileOriginatedCall.equipmentIdentifier = (ImeiOrEsn*)calloc(1, sizeof(ImeiOrEsn));
					callED->choice.mobileOriginatedCall.equipmentIdentifier->present = ImeiOrEsn_PR_imei;
					BCDStringFromStr(&callED->choice.mobileOriginatedCall.equipmentIdentifier->choice.imei, IMEI);
				}

				callED->choice.mobileOriginatedCall.basicServiceUsedList = (BasicServiceUsedList*)calloc(1, sizeof(BasicServiceUsedList));
				FillBasicServiceUsed(eventID, callED->choice.mobileOriginatedCall.basicServiceUsedList);

				if (thirdParty.length() > 0 || clir != -1) {
					callED->choice.mobileOriginatedCall.thirdPartyInformation = (ThirdPartyInformation*)calloc(1, sizeof(ThirdPartyInformation));
					if (thirdParty.length() > 0)
						callED->choice.mobileOriginatedCall.thirdPartyInformation->thirdPartyNumber = BCDString_new_FromStr(&asn_DEF_ThirdPartyNumber, thirdParty);

					if (clir != -1) {
						callED->choice.mobileOriginatedCall.thirdPartyInformation->clirIndicator = (ClirIndicator_t*)calloc(1, sizeof(ClirIndicator_t));
						*callED->choice.mobileOriginatedCall.thirdPartyInformation->clirIndicator = clir;
					}
				}

				ASN_SEQUENCE_ADD(dataInterchange->choice.transferBatch.callEventDetails, callED);
			}
			else {
				// Mobile Terminated Call
				callED->present = CallEventDetail_PR_mobileTerminatedCall;

				callED->choice.mobileTerminatedCall.basicCallInformation = (MtBasicCallInformation*)calloc(1, sizeof(MtBasicCallInformation));
				callED->choice.mobileTerminatedCall.basicCallInformation->chargeableSubscriber = (ChargeableSubscriber*)calloc(1, sizeof(ChargeableSubscriber));
				callED->choice.mobileTerminatedCall.basicCallInformation->chargeableSubscriber->present = ChargeableSubscriber_PR_simChargeableSubscriber;
				if (IMSI.length() > 0)
					callED->choice.mobileTerminatedCall.basicCallInformation->chargeableSubscriber->choice.simChargeableSubscriber.imsi =
					BCDString_new_FromStr(&asn_DEF_Imsi, IMSI);
				if (MSISDN.length() > 0)
					callED->choice.mobileTerminatedCall.basicCallInformation->chargeableSubscriber->choice.simChargeableSubscriber.msisdn =
					BCDString_new_FromStr(&asn_DEF_Msisdn, MSISDN);
				if (rapFileSeqNum.length() > 0)
					callED->choice.mobileTerminatedCall.basicCallInformation->rapFileSequenceNumber =
					OCTET_STRING_new_fromBuf(&asn_DEF_RapFileSequenceNumber, rapFileSeqNum.c_str(), rapFileSeqNum.size());
				callED->choice.mobileTerminatedCall.basicCallInformation->callOriginator = (CallOriginator*)calloc(1, sizeof(CallOriginator));
				if (partyNumber.length() > 0)
					callED->choice.mobileTerminatedCall.basicCallInformation->callOriginator->callingNumber = BCDString_new_FromStr(&asn_DEF_CallingNumber, partyNumber);
				if (clir != -1) {
					callED->choice.mobileTerminatedCall.basicCallInformation->callOriginator->clirIndicator = (ClirIndicator_t*)calloc(1, sizeof(ClirIndicator_t));
					*callED->choice.mobileTerminatedCall.basicCallInformation->callOriginator->clirIndicator = clir;
				}
				if (smsPartyNumber.length() > 0)
					callED->choice.mobileTerminatedCall.basicCallInformation->callOriginator->sMSOriginator = OCTET_STRING_new_fromBuf(&asn_DEF_SMSOriginator, smsPartyNumber.c_str(), smsPartyNumber.size());

				callED->choice.mobileTerminatedCall.basicCallInformation->callEventStartTimeStamp = (DateTime*)calloc(1, sizeof(asn_DEF_DateTime));
				callED->choice.mobileTerminatedCall.basicCallInformation->callEventStartTimeStamp->localTimeStamp = OCTET_STRING_new_fromBuf(&asn_DEF_DateTime, callTime.c_str(), callTime.size());

				callED->choice.mobileTerminatedCall.basicCallInformation->callEventStartTimeStamp->utcTimeOffsetCode = (UtcTimeOffsetCode_t*)calloc(1, sizeof(UtcTimeOffsetCode_t));
				*callED->choice.mobileTerminatedCall.basicCallInformation->callEventStartTimeStamp->utcTimeOffsetCode = GetUTCOffsetCode(callUTC);

				callED->choice.mobileTerminatedCall.basicCallInformation->totalCallEventDuration = (TotalCallEventDuration_t*)calloc(1, sizeof(TotalCallEventDuration_t));
				*callED->choice.mobileTerminatedCall.basicCallInformation->totalCallEventDuration = duration;
				if (causeForTerm != -1) {
					callED->choice.mobileTerminatedCall.basicCallInformation->causeForTerm = (CauseForTerm_t*)calloc(1, sizeof(CauseForTerm_t));
					*callED->choice.mobileTerminatedCall.basicCallInformation->causeForTerm = causeForTerm;
				}

				callED->choice.mobileTerminatedCall.locationInformation = (LocationInformation*)calloc(1, sizeof(LocationInformation));
				FillLocationInfo(callED->choice.mobileTerminatedCall.locationInformation, recEntity, recEntityTypeCode, locationArea, cellID, servingNetwork);

				if (IMEI.length() > 0) {
					callED->choice.mobileTerminatedCall.equipmentIdentifier = (ImeiOrEsn*)calloc(1, sizeof(ImeiOrEsn));
					callED->choice.mobileTerminatedCall.equipmentIdentifier->present = ImeiOrEsn_PR_imei;
					BCDStringFromStr(&callED->choice.mobileTerminatedCall.equipmentIdentifier->choice.imei, IMEI);
				}

				callED->choice.mobileTerminatedCall.basicServiceUsedList = (BasicServiceUsedList*)calloc(1, sizeof(BasicServiceUsedList));
				FillBasicServiceUsed(eventID, callED->choice.mobileTerminatedCall.basicServiceUsedList);

				ASN_SEQUENCE_ADD(dataInterchange->choice.transferBatch.callEventDetails, callED);
			}

		}

		otlStream.close();

		otlStream.open(100, // stream buffer size in logical rows
			"select EVENT_ID /*long*/, RSN /*long*/, IMSI /*char*/, MSISDN /*char*/, PDP_ADDRESS /*char*/, APN_NI /*char*/, APN_OI/*char*/, "
			"to_char(CALL_TIME, 'yyyymmddhh24miss') /*char*/, CALL_UTCOFF /*char*/, DURATION /*long*/, nvl(CAUSE_FOR_TERM, -1) /*long*/, "
			"PARTIAL_TYPE /*char*/, to_char(PDP_START_TIME, 'yyyymmddhh24miss') /*char*/, PDP_START_UTCOFF /*char*/, nvl(CHARGING_ID, -1) :#15<bigint>,"
			"REC_ENTITY /*char*/, REC_ENTITY_TYPE /*char*/, "
			"decode(REC_ENTITY_TYPE, 'MSC', 1, 'SMSC', 2, 'GGSN/P-GW', 3, 'SGSN', 4, 'GMLC', 5, 'Wi-Fi', 6, 'P-GW', 7, 'S-GW', 8, 'P-CSCF', 9, 'TRF', 10, 'ATCF', 11, -1) REC_ENTITY_TYPE_CODE /*long*/, "
			"REC_ENTITY2 /*char*/, REC_ENTITY2_TYPE /*char*/, "
			"decode(REC_ENTITY2_TYPE, 'MSC', 1, 'SMSC', 2, 'GGSN/P-GW', 3, 'SGSN', 4, 'GMLC', 5, 'Wi-Fi', 6, 'P-GW', 7, 'S-GW', 8, 'P-CSCF', 9, 'TRF', 10, 'ATCF', 11, -1) REC_ENTITY2_TYPE_CODE /*long*/, "
			"nvl(LOCATION_AREA, -1) /*long*/, nvl(CELL_ID, -1) /*long*/, SERVING_NETWORK /*char*/,"
			"IMEI /*char*/, RAP_FILE_SEQNUM /*char*/, nvl(VOLUME_INCOMING, -1) :#27<bigint>, nvl(VOLUME_OUTGOING, -1) :#28<bigint>"
			"from BILLING.TAP3_GPRSCALL where FILE_ID=:hFileID /*long*/ order by RSN",
			otlConnect
			);

		otlStream << fileID;

		while (!otlStream.eof()) {
			otlStream
				>> eventID
				>> RSN
				>> IMSI
				>> MSISDN
				>> PDPAddress
				>> APN_NI
				>> APN_OI
				>> callTime
				>> callUTC
				>> duration
				>> causeForTerm
				>> partialType
				>> PDPStartTime
				>> PDPStartUTC
				>> chargingID
				>> recEntity
				>> recEntityType
				>> recEntityTypeCode
				>> recEntity2
				>> recEntity2Type
				>> recEntity2TypeCode
				>> locationArea
				>> cellID
				>> servingNetwork
				>> IMEI
				>> rapFileSeqNum
				>> volumeIncoming
				>> volumeOutgoing
				;

			CallEventDetail* callED = (CallEventDetail*)calloc(1, sizeof(CallEventDetail));
			callED->present = CallEventDetail_PR_gprsCall;
			callED->choice.gprsCall.gprsBasicCallInformation = (GprsBasicCallInformation*)calloc(1, sizeof(GprsBasicCallInformation));
			callED->choice.gprsCall.gprsBasicCallInformation->gprsChargeableSubscriber = (GprsChargeableSubscriber*)calloc(1, sizeof(GprsChargeableSubscriber));
			callED->choice.gprsCall.gprsBasicCallInformation->gprsChargeableSubscriber->chargeableSubscriber = (ChargeableSubscriber*)calloc(1, sizeof(ChargeableSubscriber));
			callED->choice.gprsCall.gprsBasicCallInformation->gprsChargeableSubscriber->chargeableSubscriber->present = ChargeableSubscriber_PR_simChargeableSubscriber;

			if (IMSI.length() > 0)
				callED->choice.gprsCall.gprsBasicCallInformation->gprsChargeableSubscriber->chargeableSubscriber->choice.simChargeableSubscriber.imsi =
				BCDString_new_FromStr(&asn_DEF_Imsi, IMSI);
			if (MSISDN.length() > 0)
				callED->choice.gprsCall.gprsBasicCallInformation->gprsChargeableSubscriber->chargeableSubscriber->choice.simChargeableSubscriber.msisdn =
				BCDString_new_FromStr(&asn_DEF_Msisdn, MSISDN);

			if (PDPAddress.length() > 0)
				callED->choice.gprsCall.gprsBasicCallInformation->gprsChargeableSubscriber->pdpAddress = OCTET_STRING_new_fromBuf(&asn_DEF_PdpAddress, PDPAddress.c_str(), PDPAddress.size());

			if (APN_NI.length()>0 || APN_OI.length()>0) {
				callED->choice.gprsCall.gprsBasicCallInformation->gprsDestination = (GprsDestination*)calloc(1, sizeof(GprsDestination));
				if (APN_NI.length()>0)
					callED->choice.gprsCall.gprsBasicCallInformation->gprsDestination->accessPointNameNI = OCTET_STRING_new_fromBuf(&asn_DEF_AccessPointNameNI, APN_NI.c_str(), APN_NI.size());
				if (APN_OI.length()>0)
					callED->choice.gprsCall.gprsBasicCallInformation->gprsDestination->accessPointNameOI = OCTET_STRING_new_fromBuf(&asn_DEF_AccessPointNameOI, APN_OI.c_str(), APN_OI.size());
			}

			if (rapFileSeqNum.length() > 0)
				callED->choice.gprsCall.gprsBasicCallInformation->rapFileSequenceNumber =
				OCTET_STRING_new_fromBuf(&asn_DEF_RapFileSequenceNumber, rapFileSeqNum.c_str(), rapFileSeqNum.size());

			callED->choice.gprsCall.gprsBasicCallInformation->callEventStartTimeStamp = (DateTime*)calloc(1, sizeof(asn_DEF_DateTime));
			callED->choice.gprsCall.gprsBasicCallInformation->callEventStartTimeStamp->localTimeStamp = OCTET_STRING_new_fromBuf(&asn_DEF_DateTime, callTime.c_str(), callTime.size());
			callED->choice.gprsCall.gprsBasicCallInformation->callEventStartTimeStamp->utcTimeOffsetCode = (UtcTimeOffsetCode_t*)calloc(1, sizeof(UtcTimeOffsetCode_t));
			*callED->choice.gprsCall.gprsBasicCallInformation->callEventStartTimeStamp->utcTimeOffsetCode = GetUTCOffsetCode(callUTC);

			callED->choice.gprsCall.gprsBasicCallInformation->totalCallEventDuration = (TotalCallEventDuration_t*)calloc(1, sizeof(TotalCallEventDuration_t));
			*callED->choice.gprsCall.gprsBasicCallInformation->totalCallEventDuration = duration;
			if (causeForTerm != -1) {
				callED->choice.gprsCall.gprsBasicCallInformation->causeForTerm = (CauseForTerm_t*)calloc(1, sizeof(CauseForTerm_t));
				*callED->choice.gprsCall.gprsBasicCallInformation->causeForTerm = causeForTerm;
			}

			if (partialType.length() > 0)
				callED->choice.gprsCall.gprsBasicCallInformation->partialTypeIndicator = OCTET_STRING_new_fromBuf(&asn_DEF_PartialTypeIndicator, partialType.c_str(), partialType.size());

			if (PDPStartTime.length() > 0) {
				callED->choice.gprsCall.gprsBasicCallInformation->pDPContextStartTimestamp = (DateTime*)calloc(1, sizeof(asn_DEF_DateTime));
				callED->choice.gprsCall.gprsBasicCallInformation->pDPContextStartTimestamp->localTimeStamp = OCTET_STRING_new_fromBuf(&asn_DEF_DateTime, PDPStartTime.c_str(), PDPStartTime.size());
				callED->choice.gprsCall.gprsBasicCallInformation->pDPContextStartTimestamp->utcTimeOffsetCode = (UtcTimeOffsetCode_t*)calloc(1, sizeof(UtcTimeOffsetCode_t));
				*callED->choice.gprsCall.gprsBasicCallInformation->pDPContextStartTimestamp->utcTimeOffsetCode = GetUTCOffsetCode(PDPStartUTC);
			}

			if (chargingID != -1) {
				//callED->choice.gprsCall.gprsBasicCallInformation->chargingId = (ChargingId_t*) calloc(1, sizeof(ChargingId_t));
				OctetString_new_fromInt64(callED->choice.gprsCall.gprsBasicCallInformation->chargingId, &asn_DEF_ChargingId, chargingID);
			}

			callED->choice.gprsCall.gprsLocationInformation = (GprsLocationInformation*)calloc(1, sizeof(GprsLocationInformation));
			FillLocationInfo(callED->choice.gprsCall.gprsLocationInformation, recEntity, recEntityTypeCode, recEntity2, recEntity2TypeCode, locationArea, cellID, servingNetwork);

			if (IMEI.length() > 0) {
				callED->choice.gprsCall.equipmentIdentifier = (ImeiOrEsn*)calloc(1, sizeof(ImeiOrEsn));
				callED->choice.gprsCall.equipmentIdentifier->present = ImeiOrEsn_PR_imei;
				BCDStringFromStr(&callED->choice.gprsCall.equipmentIdentifier->choice.imei, IMEI);
			}

			callED->choice.gprsCall.gprsServiceUsed = (GprsServiceUsed*)calloc(1, sizeof(GprsServiceUsed));
			if (volumeIncoming >= 0) {
				// was before 8-byte integers callED->choice.gprsCall.gprsServiceUsed->dataVolumeIncoming = (DataVolumeIncoming_t*) calloc(1, sizeof(DataVolumeIncoming_t));
				OctetString_new_fromInt64(callED->choice.gprsCall.gprsServiceUsed->dataVolumeIncoming, &asn_DEF_DataVolumeIncoming, volumeIncoming);
			}

			if (volumeOutgoing >= 0) {
				// was before 8-byte integers callED->choice.gprsCall.gprsServiceUsed->dataVolumeOutgoing = (DataVolumeOutgoing_t*) calloc(1, sizeof(DataVolumeOutgoing_t));
				OctetString_new_fromInt64(callED->choice.gprsCall.gprsServiceUsed->dataVolumeOutgoing, &asn_DEF_DataVolumeOutgoing, volumeOutgoing);
			}

			callED->choice.gprsCall.gprsServiceUsed->chargeInformationList = (ChargeInformationList*)calloc(1, sizeof(ChargeInformationList));
			FillChargeInfo(eventID, callED->choice.gprsCall.gprsServiceUsed->chargeInformationList);

			ASN_SEQUENCE_ADD(dataInterchange->choice.transferBatch.callEventDetails, callED);
		}

		otlStream.close();

		// Construct Audit Control Info
		dataInterchange->choice.transferBatch.auditControlInfo = (AuditControlInfo*)calloc(1, sizeof(AuditControlInfo));
		dataInterchange->choice.transferBatch.auditControlInfo->earliestCallTimeStamp = (DateTimeLong*)calloc(1, sizeof(asn_DEF_DateTimeLong));
		dataInterchange->choice.transferBatch.auditControlInfo->earliestCallTimeStamp->localTimeStamp = OCTET_STRING_new_fromBuf(&asn_DEF_LocalTimeStamp, earliestTime.c_str(), earliestTime.size());
		dataInterchange->choice.transferBatch.auditControlInfo->earliestCallTimeStamp->utcTimeOffset = OCTET_STRING_new_fromBuf(&asn_DEF_UtcTimeOffset, earliestTimeUTC.c_str(), earliestTimeUTC.size());
		dataInterchange->choice.transferBatch.auditControlInfo->latestCallTimeStamp = (DateTimeLong*)calloc(1, sizeof(asn_DEF_DateTimeLong));
		dataInterchange->choice.transferBatch.auditControlInfo->latestCallTimeStamp->localTimeStamp = OCTET_STRING_new_fromBuf(&asn_DEF_LocalTimeStamp, latestTime.c_str(), latestTime.size());
		dataInterchange->choice.transferBatch.auditControlInfo->latestCallTimeStamp->utcTimeOffset = OCTET_STRING_new_fromBuf(&asn_DEF_UtcTimeOffset, latestTimeUTC.c_str(), latestTimeUTC.size());
		// was before 8-byte integers dataInterchange->choice.transferBatch.auditControlInfo->totalCharge = (TotalCharge_t*) calloc(1, sizeof(TotalCharge_t));
		OctetString_new_fromInt64(dataInterchange->choice.transferBatch.auditControlInfo->totalCharge, &asn_DEF_TotalCharge, (long long)floor(totalCharge * dblTAPPower + 0.5));
		// was before 8-byte integers  dataInterchange->choice.transferBatch.auditControlInfo->totalTaxValue = (TotalTaxValue_t*) calloc(1, sizeof(TotalTaxValue_t));
		OctetString_new_fromInt64(dataInterchange->choice.transferBatch.auditControlInfo->totalTaxValue, &asn_DEF_TotalTaxValue, (long long)floor(totalTax * dblTAPPower + 0.5));
		// was before 8-byte integers  dataInterchange->choice.transferBatch.auditControlInfo->totalDiscountValue = (TotalDiscountValue_t*) calloc(1, sizeof(TotalDiscountValue_t));
		OctetString_new_fromInt64(dataInterchange->choice.transferBatch.auditControlInfo->totalDiscountValue, &asn_DEF_TotalDiscountValue, (long long)floor(totalDiscount * dblTAPPower + 0.5));
		dataInterchange->choice.transferBatch.auditControlInfo->callEventDetailsCount = (CallEventDetailsCount_t*)calloc(1, sizeof(CallEventDetailsCount_t));
		*dataInterchange->choice.transferBatch.auditControlInfo->callEventDetailsCount = eventCount;

	}
	else {
		// creation NOTIFICATION (file having no call records)
		log(filename, LOG_INFO, "Creating Notification TAP file");
		dataInterchange->present = DataInterChange_PR_notification;

		dataInterchange->choice.notification.sender = OCTET_STRING_new_fromBuf(&asn_DEF_Sender, sender.c_str(), sender.size());
		dataInterchange->choice.notification.recipient = OCTET_STRING_new_fromBuf(&asn_DEF_Recipient, recipient.c_str(), recipient.size());
		dataInterchange->choice.notification.fileSequenceNumber = OCTET_STRING_new_fromBuf(&asn_DEF_FileSequenceNumber, fileSequenceNumber.c_str(), fileSequenceNumber.size());

		if (fileCreationTimeStamp.length() > 0) {
			dataInterchange->choice.notification.fileCreationTimeStamp = (DateTimeLong*)calloc(1, sizeof(DateTimeLong));
			dataInterchange->choice.notification.fileCreationTimeStamp->localTimeStamp = OCTET_STRING_new_fromBuf(&asn_DEF_LocalTimeStamp, fileCreationTimeStamp.c_str(), fileCreationTimeStamp.size());
			dataInterchange->choice.notification.fileCreationTimeStamp->utcTimeOffset = OCTET_STRING_new_fromBuf(&asn_DEF_UtcTimeOffset, fileCreationTimeStampUTC.c_str(), fileCreationTimeStampUTC.size());
		}

		dataInterchange->choice.notification.fileAvailableTimeStamp = (DateTimeLong*)calloc(1, sizeof(DateTimeLong));
		dataInterchange->choice.notification.fileAvailableTimeStamp->localTimeStamp = OCTET_STRING_new_fromBuf(&asn_DEF_LocalTimeStamp, fileAvailableTimeStamp.c_str(), fileAvailableTimeStamp.size());
		dataInterchange->choice.notification.fileAvailableTimeStamp->utcTimeOffset = OCTET_STRING_new_fromBuf(&asn_DEF_UtcTimeOffset, fileAvailableTimeStampUTC.c_str(), fileAvailableTimeStampUTC.size());

		dataInterchange->choice.notification.transferCutOffTimeStamp = (DateTimeLong*)calloc(1, sizeof(DateTimeLong));
		dataInterchange->choice.notification.transferCutOffTimeStamp->localTimeStamp = OCTET_STRING_new_fromBuf(&asn_DEF_LocalTimeStamp, transferCutOffTimeStamp.c_str(), transferCutOffTimeStamp.size());
		dataInterchange->choice.notification.transferCutOffTimeStamp->utcTimeOffset = OCTET_STRING_new_fromBuf(&asn_DEF_UtcTimeOffset, transferCutOffTimeStampUTC.c_str(), transferCutOffTimeStampUTC.size());

		dataInterchange->choice.notification.specificationVersionNumber = (SpecificationVersionNumber_t*)calloc(1, sizeof(SpecificationVersionNumber_t));
		*dataInterchange->choice.notification.specificationVersionNumber = tapVersion;
		dataInterchange->choice.notification.releaseVersionNumber = (ReleaseVersionNumber_t*)calloc(1, sizeof(ReleaseVersionNumber_t));
		*dataInterchange->choice.notification.releaseVersionNumber = tapRelease;
		if (fileTypeIndicator.length() > 0)
			dataInterchange->choice.notification.fileTypeIndicator = OCTET_STRING_new_fromBuf(&asn_DEF_FileTypeIndicator, fileTypeIndicator.c_str(), fileTypeIndicator.size());
	}

	return fileID;
}

//------------------------------
int main(int argc, const char* argv[])
{
	// установим pShortName на имя файла, отбросив путь
	/*pShortName =  strrchr(argv[1],'\\');
	if(!pShortName)
		pShortName=argv[1];
	else
		pShortName++;
*/
	try {

		if(argc>1) {
			if(!strcmp(argv[1], "-d") || !strcmp(argv[1], "-D")) {
				debugMode = 1;
			}
		}
	
		
		ofsLog.open("TAP3Writer.log", ofstream::app);

		// чтение файла конфигурации
		ifstream ifsSettings ("TAPWriter.cfg", ifstream::in);
		if (!ifsSettings.is_open())	{
			log("", LOG_ERROR, "Unable to open config file TAPWriter.cfg");
			exit(TL_FILEERROR);
		}

		Config config(ifsSettings);

		ifsSettings.close();

		if (config.GetConnectString().empty()) {
			log("", LOG_ERROR, "Connect string to DB is not found in TAP3Writer.cfg file. Exiting.");
			ofsLog.close();
			exit(TL_FILEERROR);
		}

		// DB connect
		otl_connect::otl_initialize();
		try {
			otlConnect.rlogon(config.GetConnectString().c_str());
			otlLogConnect.rlogon(config.GetConnectString().c_str());
		}
		catch (otl_exception &otlEx) {
			log("", LOG_ERROR, "Unable to connect to DB:");
			log("", LOG_ERROR, (char*) otlEx.msg);
			if( strlen(otlEx.stm_text) > 0 )
				log("", LOG_ERROR, (char*) otlEx.stm_text); // log SQL that caused the error
			if( strlen(otlEx.var_info) > 0 )
				log("", LOG_ERROR, (char*) otlEx.var_info); // log the variable that caused the error
			log("", LOG_ERROR, "---- TAP3 writer finished with errors, see DB log----");
			if(ofsLog.is_open()) ofsLog.close();
			exit(TL_CONNECTERROR);
		}
	
		log("", LOG_INFO, "-------- TAP3 writer started --------");

		otl_nocommit_stream otlFileStream;
		
		otlFileStream.open( 1 /*stream buffer size in logical rows*/, 
					"select FILE_ID /* long */, FILENAME /*char[255],in*/, SENDER /*char[20],in*/, RECIPIENT /*char[20],in*/, SEQUENCE_NUMBER /*char[10],in*/, \
					to_char(CREATION_STAMP, 'yyyymmddhh24miss') /*char[20],in*/ , CREATION_UTCOFF /*char[10],in*/,\
					to_char(CUTOFF_STAMP, 'yyyymmddhh24miss') /*char[20],in*/, CUTOFF_UTCOFF /*char[10],in*/, \
					to_char(sysdate, 'yyyymmddhh24miss') /*char[20],in*/ /*this is for AVAILABLE_STAMP*/, AVAILABLE_UTCOFF /*char[10],in*/, LOCAL_CURRENCY /* char[10] */,\
					to_char(LOAD_TIME, 'yyyymmddhh24miss') /*char[20],in*/, to_char(EARLIEST_TIME, 'yyyymmddhh24miss') /*char[20],in*/, EARLIEST_UTCOFF /*char[10],in*/,\
					to_char(LATEST_TIME, 'yyyymmddhh24miss') /*char[20],in*/, LATEST_UTCOFF /*char[10],in*/,\
					EVENT_COUNT /* long */, TOTAL_CHARGE /* double */, TOTAL_TAX /* double */, TOTAL_DISCOUNT /* double */, FILE_TYPE_INDICATOR /* char[1] */, RAP_FILE_SEQNUM /* char[10]*/, \
					nvl(NOTIFICATION, 0) /*long*/, nvl(TAP_VERSION, 3) /*long*/, nvl(TAP_RELEASE, 12) /*long*/, nvl(TAP_DECIMAL_PLACES, 6) /*long*/, h.NAME /*char[100]*/ \
					from BILLING.TAP3_FILE f, BILLING.TMOBILENETWORK n, BILLING.TROAMINGHUB h \
					where STATUS = :status /*long*/ and n.OBJECT_NO=f.MOBILENETWORK_ID and h.OBJECT_NO=n.ROAMINGHUB_ID", otlConnect);

		otlFileStream << (long) OUTFILE_READY_FOR_SENDING; // status
		while( ! otlFileStream.eof()) {

			dataInterchange = (DataInterChange*)calloc(1, sizeof(DataInterChange));
			
			long fileID;
			string filename, roamingHubName, fileAvailableTimeStamp;
			fileID = FillDataIntercharge(dataInterchange, otlFileStream, filename, roamingHubName, fileAvailableTimeStamp);
			
			// UPDATE STATUS of FILE in DB
			otl_nocommit_stream otlStream;
			otlStream.open( 1, // stream buffer size in logical rows
				"UPDATE BILLING.TAP3_FILE set status=:hStatus /*long*/, available_stamp=to_date(:hAvailStamp /*char[20]*/, 'yyyymmddhh24miss') \
					where file_id=:hFileId /*long*/", otlConnect ); 
			otlStream 
				<< (long) OUTFILE_CREATED_AND_SENT	/* file written status */
				<< fileAvailableTimeStamp
				<< fileID;

			otlStream.flush();
			otlStream.close();

			// ENCODING FILE
			string fullFileName;
#ifdef WIN32
			fullFileName = (config.GetOutputDirectory().empty() ? "." : config.GetOutputDirectory()) + "\\" + filename;
#else
			fullFileName = (config.GetOutputDirectory().empty() ? "." : config.GetOutputDirectory()) + "/" + filename;
#endif

			FILE *fTapFile=fopen( fullFileName.c_str(), "wb");
			if(!fTapFile) {
				log(filename, LOG_ERROR, string("Unable to open file ") + fullFileName + " for writing.");
				Finalize(filename);
				exit(TL_FILEERROR);
			}
			asn_enc_rval_t encodeRes = der_encode(&asn_DEF_DataInterChange, dataInterchange, write_out, fTapFile);
	
			fclose(fTapFile);
			ASN_STRUCT_FREE(asn_DEF_DataInterChange, dataInterchange);
			dataInterchange = NULL;
	
			if(encodeRes.encoded == -1) {
				log(filename, LOG_ERROR, string("Error while encoding ASN file. Error code ") + string(encodeRes.failed_type ? encodeRes.failed_type->name : "unknown"));
				Finalize(filename);
				exit(TL_DECODEERROR);
			}
			
			log(filename, LOG_INFO, "TAP File successfully created.");
	
			// Upload file to FTP-server
			FtpSetting ftpSetting = config.GetFTPSetting(roamingHubName);
			if (!ftpSetting.ftpServer.empty()) {
				if (!UploadFileToFtp(filename, fullFileName, ftpSetting, roamingHubName)) {
					Finalize(filename);
					exit(TL_FILEERROR);
				}
			}
			else
				log(filename, LOG_INFO, "FTP server is not set in cfg-file for roaming hub " + roamingHubName + ". No uploading done.");

			otlConnect.commit();
			otlLogConnect.commit();

			}	// end of file loop
			
			otlFileStream.close();

			// Writing RAP acknowledgement files
	
	}
	catch (otl_exception &otlEx) {
		otlConnect.rollback();
		otlConnect.logoff();
		log("", LOG_ERROR, "DB error while processing CDR records:");
		log("", LOG_ERROR, (char*)otlEx.msg);
		if( strlen(otlEx.stm_text) > 0 )
			log("", LOG_ERROR, (char*)otlEx.stm_text); // log SQL that caused the error
		if( strlen(otlEx.var_info) > 0 )
			log("", LOG_ERROR, (char*)otlEx.var_info); // log the variable that caused the error
		Finalize("");
		exit(TL_ORACLEERROR);
	}
	catch(char* pMess)
	{
		log("", LOG_ERROR, string("Exception caught: ") + string(pMess));
		Finalize("");
		return TL_UNKNOWN;
	}
	catch(...)
	{
		log("", LOG_ERROR, "Unknown exception caught.");
		Finalize("");
		return TL_UNKNOWN;
	}

	Finalize("", true);

	return TL_OK;
}
