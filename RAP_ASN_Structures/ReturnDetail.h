/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "RAP-0105"
 * 	found in "RAP_ASN_specification.txt"
 */

#ifndef	_ReturnDetail_H_
#define	_ReturnDetail_H_


#include <asn_application.h>

/* Including external dependencies */
#include "StopReturn.h"
#include "MissingReturn.h"
#include "FatalReturn.h"
#include "SevereReturn.h"
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ReturnDetail_PR {
	ReturnDetail_PR_NOTHING,	/* No components present */
	ReturnDetail_PR_stopReturn,
	ReturnDetail_PR_missingReturn,
	ReturnDetail_PR_fatalReturn,
	ReturnDetail_PR_severeReturn,
	/* Extensions may appear below */
	
} ReturnDetail_PR;

/* ReturnDetail */
typedef struct ReturnDetail {
	ReturnDetail_PR present;
	union ReturnDetail_u {
		StopReturn_t	 stopReturn;
		MissingReturn_t	 missingReturn;
		FatalReturn_t	 fatalReturn;
		SevereReturn_t	 severeReturn;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ReturnDetail_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ReturnDetail;

#ifdef __cplusplus
}
#endif

#endif	/* _ReturnDetail_H_ */
#include <asn_internal.h>
