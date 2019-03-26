/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "RAP-0105"
 * 	found in "RAP_ASN_specification.txt"
 */

#ifndef	_ReturnBatch_H_
#define	_ReturnBatch_H_


#include <asn_application.h>

/* Including external dependencies */
#include "RapBatchControlInfo.h"
#include "ReturnDetailList.h"
#include "RapAuditControlInfo.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ReturnBatch */
typedef struct ReturnBatch {
	RapBatchControlInfo_t	 rapBatchControlInfoRap;
	ReturnDetailList_t	 returnDetails;
	RapAuditControlInfo_t	 rapAuditControlInfo;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ReturnBatch_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ReturnBatch;

#ifdef __cplusplus
}
#endif

#endif	/* _ReturnBatch_H_ */
#include <asn_internal.h>
