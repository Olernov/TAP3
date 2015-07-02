/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP-0312"
 */

#ifndef	_ChargeableSubscriber_H_
#define	_ChargeableSubscriber_H_


#include <asn_application.h>

/* Including external dependencies */
#include "SimChargeableSubscriber.h"
#include "MinChargeableSubscriber.h"
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ChargeableSubscriber_PR {
	ChargeableSubscriber_PR_NOTHING,	/* No components present */
	ChargeableSubscriber_PR_simChargeableSubscriber,
	ChargeableSubscriber_PR_minChargeableSubscriber,
	/* Extensions may appear below */
	
} ChargeableSubscriber_PR;

/* ChargeableSubscriber */
typedef struct ChargeableSubscriber {
	ChargeableSubscriber_PR present;
	union ChargeableSubscriber_u {
		SimChargeableSubscriber_t	 simChargeableSubscriber;
		MinChargeableSubscriber_t	 minChargeableSubscriber;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ChargeableSubscriber_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ChargeableSubscriber;

#ifdef __cplusplus
}
#endif

#endif	/* _ChargeableSubscriber_H_ */
#include <asn_internal.h>
