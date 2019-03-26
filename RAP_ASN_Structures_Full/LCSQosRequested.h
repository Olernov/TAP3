/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP-0312"
 */

#ifndef	_LCSQosRequested_H_
#define	_LCSQosRequested_H_


#include <asn_application.h>

/* Including external dependencies */
#include "HorizontalAccuracyRequested.h"
#include "VerticalAccuracyRequested.h"
#include "ResponseTimeCategory.h"
#include "TrackingPeriod.h"
#include "TrackingFrequency.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct DateTime;

/* LCSQosRequested */
typedef struct LCSQosRequested {
	struct DateTime	*lCSRequestTimestamp	/* OPTIONAL */;
	HorizontalAccuracyRequested_t	*horizontalAccuracyRequested	/* OPTIONAL */;
	VerticalAccuracyRequested_t	*verticalAccuracyRequested	/* OPTIONAL */;
	ResponseTimeCategory_t	*responseTimeCategory	/* OPTIONAL */;
	TrackingPeriod_t	*trackingPeriod	/* OPTIONAL */;
	TrackingFrequency_t	*trackingFrequency	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} LCSQosRequested_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_LCSQosRequested;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "LCSRequestTimestamp.h"

#endif	/* _LCSQosRequested_H_ */
#include <asn_internal.h>
