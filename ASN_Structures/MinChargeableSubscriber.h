/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP3.12.asn1"
 */

#ifndef	_MinChargeableSubscriber_H_
#define	_MinChargeableSubscriber_H_


#include <asn_application.h>

/* Including external dependencies */
#include "Min.h"
#include "Mdn.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* MinChargeableSubscriber */
typedef struct MinChargeableSubscriber {
	Min_t	*min	/* OPTIONAL */;
	Mdn_t	*mdn	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} MinChargeableSubscriber_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MinChargeableSubscriber;

#ifdef __cplusplus
}
#endif

#endif	/* _MinChargeableSubscriber_H_ */
#include <asn_internal.h>
