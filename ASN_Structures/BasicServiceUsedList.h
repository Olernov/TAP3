/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP3.12.asn1"
 */

#ifndef	_BasicServiceUsedList_H_
#define	_BasicServiceUsedList_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct BasicServiceUsed;

/* BasicServiceUsedList */
typedef struct BasicServiceUsedList {
	A_SEQUENCE_OF(struct BasicServiceUsed) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} BasicServiceUsedList_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_BasicServiceUsedList;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "BasicServiceUsed.h"

#endif	/* _BasicServiceUsedList_H_ */
#include <asn_internal.h>
