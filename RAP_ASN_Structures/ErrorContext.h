/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "RAP-0105"
 * 	found in "RAP_ASN_specification.txt"
 */

#ifndef	_ErrorContext_H_
#define	_ErrorContext_H_


#include <asn_application.h>

/* Including external dependencies */
#include "PathItemId.h"
#include "ItemOccurrence.h"
#include "ItemLevel.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ErrorContext */
typedef struct ErrorContext {
	PathItemId_t	 pathItemId;
	ItemOccurrence_t	*itemOccurrence	/* OPTIONAL */;
	ItemLevel_t	 itemLevel;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ErrorContext_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ErrorContext;

#ifdef __cplusplus
}
#endif

#endif	/* _ErrorContext_H_ */
#include <asn_internal.h>
