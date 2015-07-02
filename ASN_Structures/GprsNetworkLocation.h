/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP3.12.asn1"
 */

#ifndef	_GprsNetworkLocation_H_
#define	_GprsNetworkLocation_H_


#include <asn_application.h>

/* Including external dependencies */
#include "LocationArea.h"
#include "CellId.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct RecEntityCodeList;

/* GprsNetworkLocation */
typedef struct GprsNetworkLocation {
	struct RecEntityCodeList	*recEntity	/* OPTIONAL */;
	LocationArea_t	*locationArea	/* OPTIONAL */;
	CellId_t	*cellId	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} GprsNetworkLocation_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_GprsNetworkLocation;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "RecEntityCodeList.h"

#endif	/* _GprsNetworkLocation_H_ */
#include <asn_internal.h>
