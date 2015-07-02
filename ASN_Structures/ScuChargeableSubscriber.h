/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP3.12.asn1"
 */

#ifndef	_ScuChargeableSubscriber_H_
#define	_ScuChargeableSubscriber_H_


#include <asn_application.h>

/* Including external dependencies */
#include "GsmChargeableSubscriber.h"
#include "MinChargeableSubscriber.h"
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ScuChargeableSubscriber_PR {
	ScuChargeableSubscriber_PR_NOTHING,	/* No components present */
	ScuChargeableSubscriber_PR_gsmChargeableSubscriber,
	ScuChargeableSubscriber_PR_minChargeableSubscriber,
	/* Extensions may appear below */
	
} ScuChargeableSubscriber_PR;

/* ScuChargeableSubscriber */
typedef struct ScuChargeableSubscriber {
	ScuChargeableSubscriber_PR present;
	union ScuChargeableSubscriber_u {
		GsmChargeableSubscriber_t	 gsmChargeableSubscriber;
		MinChargeableSubscriber_t	 minChargeableSubscriber;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ScuChargeableSubscriber_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ScuChargeableSubscriber;

#ifdef __cplusplus
}
#endif

#endif	/* _ScuChargeableSubscriber_H_ */
#include <asn_internal.h>
