/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP3.12.asn1"
 */

#ifndef	_BasicServiceCodeList_H_
#define	_BasicServiceCodeList_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct BasicServiceCode;

/* BasicServiceCodeList */
typedef struct BasicServiceCodeList {
	A_SEQUENCE_OF(struct BasicServiceCode) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} BasicServiceCodeList_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_BasicServiceCodeList;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "BasicServiceCode.h"

#endif	/* _BasicServiceCodeList_H_ */
#include <asn_internal.h>
