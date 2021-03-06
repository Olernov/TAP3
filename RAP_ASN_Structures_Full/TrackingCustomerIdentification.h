/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP-0312"
 */

#ifndef	_TrackingCustomerIdentification_H_
#define	_TrackingCustomerIdentification_H_


#include <asn_application.h>

/* Including external dependencies */
#include "CustomerIdType.h"
#include "CustomerIdentifier.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* TrackingCustomerIdentification */
typedef struct TrackingCustomerIdentification {
	CustomerIdType_t	*customerIdType	/* OPTIONAL */;
	CustomerIdentifier_t	*customerIdentifier	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} TrackingCustomerIdentification_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_TrackingCustomerIdentification;

#ifdef __cplusplus
}
#endif

#endif	/* _TrackingCustomerIdentification_H_ */
#include <asn_internal.h>
