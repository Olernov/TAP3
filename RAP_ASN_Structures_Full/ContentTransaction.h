/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP-0312"
 */

#ifndef	_ContentTransaction_H_
#define	_ContentTransaction_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ContentTransactionBasicInfo;
struct ChargedPartyInformation;
struct ServingPartiesInformation;
struct ContentServiceUsedList;
struct OperatorSpecInfoList;

/* ContentTransaction */
typedef struct ContentTransaction {
	struct ContentTransactionBasicInfo	*contentTransactionBasicInfo	/* OPTIONAL */;
	struct ChargedPartyInformation	*chargedPartyInformation	/* OPTIONAL */;
	struct ServingPartiesInformation	*servingPartiesInformation	/* OPTIONAL */;
	struct ContentServiceUsedList	*contentServiceUsed	/* OPTIONAL */;
	struct OperatorSpecInfoList	*operatorSpecInformation	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ContentTransaction_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ContentTransaction;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ContentTransactionBasicInfo.h"
#include "ChargedPartyInformation.h"
#include "ServingPartiesInformation.h"
#include "ContentServiceUsedList.h"
#include "OperatorSpecInfoList.h"

#endif	/* _ContentTransaction_H_ */
#include <asn_internal.h>
