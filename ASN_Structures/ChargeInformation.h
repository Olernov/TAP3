/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP3.12.asn1"
 */

#ifndef	_ChargeInformation_H_
#define	_ChargeInformation_H_


#include <asn_application.h>

/* Including external dependencies */
#include "ChargedItem.h"
#include "ExchangeRateCode.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct CallTypeGroup;
struct ChargeDetailList;
struct TaxInformationList;
struct DiscountInformation;

/* ChargeInformation */
typedef struct ChargeInformation {
	ChargedItem_t	*chargedItem	/* OPTIONAL */;
	ExchangeRateCode_t	*exchangeRateCode	/* OPTIONAL */;
	struct CallTypeGroup	*callTypeGroup	/* OPTIONAL */;
	struct ChargeDetailList	*chargeDetailList	/* OPTIONAL */;
	struct TaxInformationList	*taxInformation	/* OPTIONAL */;
	struct DiscountInformation	*discountInformation	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ChargeInformation_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ChargeInformation;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "CallTypeGroup.h"
#include "ChargeDetailList.h"
#include "TaxInformationList.h"
#include "DiscountInformation.h"

#endif	/* _ChargeInformation_H_ */
#include <asn_internal.h>
