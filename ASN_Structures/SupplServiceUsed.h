/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP3.12.asn1"
 */

#ifndef	_SupplServiceUsed_H_
#define	_SupplServiceUsed_H_


#include <asn_application.h>

/* Including external dependencies */
#include "SupplServiceCode.h"
#include "SupplServiceActionCode.h"
#include "SsParameters.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct DateTime;
struct ChargeInformation;
struct BasicServiceCodeList;

/* SupplServiceUsed */
typedef struct SupplServiceUsed {
	SupplServiceCode_t	*supplServiceCode	/* OPTIONAL */;
	SupplServiceActionCode_t	*supplServiceActionCode	/* OPTIONAL */;
	SsParameters_t	*ssParameters	/* OPTIONAL */;
	struct DateTime	*chargingTimeStamp	/* OPTIONAL */;
	struct ChargeInformation	*chargeInformation	/* OPTIONAL */;
	struct BasicServiceCodeList	*basicServiceCodeList	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SupplServiceUsed_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SupplServiceUsed;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ChargingTimeStamp.h"
#include "ChargeInformation.h"
#include "BasicServiceCodeList.h"

#endif	/* _SupplServiceUsed_H_ */
#include <asn_internal.h>
