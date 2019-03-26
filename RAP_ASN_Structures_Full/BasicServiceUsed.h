/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP-0312"
 */

#ifndef	_BasicServiceUsed_H_
#define	_BasicServiceUsed_H_


#include <asn_application.h>

/* Including external dependencies */
#include "HSCSDIndicator.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct BasicService;
struct DateTime;
struct ChargeInformationList;

/* BasicServiceUsed */
typedef struct BasicServiceUsed {
	struct BasicService	*basicService	/* OPTIONAL */;
	struct DateTime	*chargingTimeStamp	/* OPTIONAL */;
	struct ChargeInformationList	*chargeInformationList	/* OPTIONAL */;
	HSCSDIndicator_t	*hSCSDIndicator	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} BasicServiceUsed_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_BasicServiceUsed;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "BasicService.h"
#include "ChargingTimeStamp.h"
#include "ChargeInformationList.h"

#endif	/* _BasicServiceUsed_H_ */
#include <asn_internal.h>
