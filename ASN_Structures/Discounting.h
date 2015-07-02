/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP3.12.asn1"
 */

#ifndef	_Discounting_H_
#define	_Discounting_H_


#include <asn_application.h>

/* Including external dependencies */
#include "DiscountCode.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct DiscountApplied;

/* Discounting */
typedef struct Discounting {
	DiscountCode_t	*discountCode	/* OPTIONAL */;
	struct DiscountApplied	*discountApplied	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Discounting_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Discounting;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "DiscountApplied.h"

#endif	/* _Discounting_H_ */
#include <asn_internal.h>
