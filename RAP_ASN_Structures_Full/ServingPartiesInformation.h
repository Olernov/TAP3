/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP-0312"
 */

#ifndef	_ServingPartiesInformation_H_
#define	_ServingPartiesInformation_H_


#include <asn_application.h>

/* Including external dependencies */
#include "ContentProviderName.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ContentProviderIdList;
struct InternetServiceProviderIdList;
struct NetworkList;

/* ServingPartiesInformation */
typedef struct ServingPartiesInformation {
	ContentProviderName_t	*contentProviderName	/* OPTIONAL */;
	struct ContentProviderIdList	*contentProviderIdList	/* OPTIONAL */;
	struct InternetServiceProviderIdList	*internetServiceProviderIdList	/* OPTIONAL */;
	struct NetworkList	*networkList	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ServingPartiesInformation_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ServingPartiesInformation;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ContentProviderIdList.h"
#include "InternetServiceProviderIdList.h"
#include "NetworkList.h"

#endif	/* _ServingPartiesInformation_H_ */
#include <asn_internal.h>
