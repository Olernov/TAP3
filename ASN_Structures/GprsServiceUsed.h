/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP3.12.asn1"
 */

#ifndef	_GprsServiceUsed_H_
#define	_GprsServiceUsed_H_


#include <asn_application.h>

/* Including external dependencies */
#include "IMSSignallingContext.h"
#include "DataVolumeIncoming.h"
#include "DataVolumeOutgoing.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ChargeInformationList;

/* GprsServiceUsed */
typedef struct GprsServiceUsed {
	IMSSignallingContext_t	*iMSSignallingContext	/* OPTIONAL */;
	DataVolumeIncoming_t	*dataVolumeIncoming	/* OPTIONAL */;
	DataVolumeOutgoing_t	*dataVolumeOutgoing	/* OPTIONAL */;
	struct ChargeInformationList	*chargeInformationList	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} GprsServiceUsed_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_GprsServiceUsed;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ChargeInformationList.h"

#endif	/* _GprsServiceUsed_H_ */
#include <asn_internal.h>
