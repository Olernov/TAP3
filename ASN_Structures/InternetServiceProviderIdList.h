/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP3.12.asn1"
 */

#ifndef	_InternetServiceProviderIdList_H_
#define	_InternetServiceProviderIdList_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct InternetServiceProvider;

/* InternetServiceProviderIdList */
typedef struct InternetServiceProviderIdList {
	A_SEQUENCE_OF(struct InternetServiceProvider) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} InternetServiceProviderIdList_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_InternetServiceProviderIdList;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "InternetServiceProvider.h"

#endif	/* _InternetServiceProviderIdList_H_ */
#include <asn_internal.h>
