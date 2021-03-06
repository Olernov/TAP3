/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP-0312"
 */

#ifndef	_GprsLocationInformation_H_
#define	_GprsLocationInformation_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct GprsNetworkLocation;
struct HomeLocationInformation;
struct GeographicalLocation;

/* GprsLocationInformation */
typedef struct GprsLocationInformation {
	struct GprsNetworkLocation	*gprsNetworkLocation	/* OPTIONAL */;
	struct HomeLocationInformation	*homeLocationInformation	/* OPTIONAL */;
	struct GeographicalLocation	*geographicalLocation	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} GprsLocationInformation_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_GprsLocationInformation;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "GprsNetworkLocation.h"
#include "HomeLocationInformation.h"
#include "GeographicalLocation.h"

#endif	/* _GprsLocationInformation_H_ */
#include <asn_internal.h>
