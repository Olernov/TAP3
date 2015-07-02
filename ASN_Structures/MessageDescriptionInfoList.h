/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP3.12.asn1"
 */

#ifndef	_MessageDescriptionInfoList_H_
#define	_MessageDescriptionInfoList_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct MessageDescriptionInformation;

/* MessageDescriptionInfoList */
typedef struct MessageDescriptionInfoList {
	A_SEQUENCE_OF(struct MessageDescriptionInformation) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} MessageDescriptionInfoList_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MessageDescriptionInfoList;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "MessageDescriptionInformation.h"

#endif	/* _MessageDescriptionInfoList_H_ */
#include <asn_internal.h>