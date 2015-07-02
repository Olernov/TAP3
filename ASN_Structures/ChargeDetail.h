/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP3.12.asn1"
 */

#ifndef	_ChargeDetail_H_
#define	_ChargeDetail_H_


#include <asn_application.h>

/* Including external dependencies */
#include "ChargeType.h"
#include "Charge.h"
#include "ChargeableUnits.h"
#include "ChargedUnits.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct DateTime;

/* ChargeDetail */
typedef struct ChargeDetail {
	ChargeType_t	*chargeType	/* OPTIONAL */;
	Charge_t	*charge	/* OPTIONAL */;
	ChargeableUnits_t	*chargeableUnits	/* OPTIONAL */;
	ChargedUnits_t	*chargedUnits	/* OPTIONAL */;
	struct DateTime	*chargeDetailTimeStamp	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ChargeDetail_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ChargeDetail;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ChargeDetailTimeStamp.h"

#endif	/* _ChargeDetail_H_ */
#include <asn_internal.h>
