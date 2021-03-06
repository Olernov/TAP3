/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP-0312"
 */

#ifndef	_DiscountInformation_H_
#define	_DiscountInformation_H_


#include <asn_application.h>

/* Including external dependencies */
#include "DiscountCode.h"
#include "Discount.h"
#include "DiscountableAmount.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* DiscountInformation */
typedef struct DiscountInformation {
	DiscountCode_t	*discountCode	/* OPTIONAL */;
	Discount_t	*discount	/* OPTIONAL */;
	DiscountableAmount_t	*discountableAmount	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} DiscountInformation_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_DiscountInformation;

#ifdef __cplusplus
}
#endif

#endif	/* _DiscountInformation_H_ */
#include <asn_internal.h>
