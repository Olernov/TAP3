/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP-0312"
 */

#ifndef	_OperatorSpecInfoList_H_
#define	_OperatorSpecInfoList_H_


#include <asn_application.h>

/* Including external dependencies */
#include "OperatorSpecInformation.h"
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* OperatorSpecInfoList */
typedef struct OperatorSpecInfoList {
	A_SEQUENCE_OF(OperatorSpecInformation_t) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} OperatorSpecInfoList_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_OperatorSpecInfoList;

#ifdef __cplusplus
}
#endif

#endif	/* _OperatorSpecInfoList_H_ */
#include <asn_internal.h>
