/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP3.12.asn1"
 */

#ifndef	_TrackingCustomerLocation_H_
#define	_TrackingCustomerLocation_H_


#include <asn_application.h>

/* Including external dependencies */
#include "LocationIdType.h"
#include "LocationIdentifier.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* TrackingCustomerLocation */
typedef struct TrackingCustomerLocation {
	LocationIdType_t	*locationIdType	/* OPTIONAL */;
	LocationIdentifier_t	*locationIdentifier	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} TrackingCustomerLocation_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_TrackingCustomerLocation;

#ifdef __cplusplus
}
#endif

#endif	/* _TrackingCustomerLocation_H_ */
#include <asn_internal.h>
