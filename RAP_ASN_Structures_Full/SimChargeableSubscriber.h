/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP-0312"
 */

#ifndef	_SimChargeableSubscriber_H_
#define	_SimChargeableSubscriber_H_


#include <asn_application.h>

/* Including external dependencies */
#include "Imsi.h"
#include "Msisdn.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* SimChargeableSubscriber */
typedef struct SimChargeableSubscriber {
	Imsi_t	*imsi	/* OPTIONAL */;
	Msisdn_t	*msisdn	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SimChargeableSubscriber_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SimChargeableSubscriber;

#ifdef __cplusplus
}
#endif

#endif	/* _SimChargeableSubscriber_H_ */
#include <asn_internal.h>
