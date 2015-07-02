/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP-0312"
 */

#ifndef	_ImeiOrEsn_H_
#define	_ImeiOrEsn_H_


#include <asn_application.h>

/* Including external dependencies */
#include "Imei.h"
#include "Esn.h"
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ImeiOrEsn_PR {
	ImeiOrEsn_PR_NOTHING,	/* No components present */
	ImeiOrEsn_PR_imei,
	ImeiOrEsn_PR_esn,
	/* Extensions may appear below */
	
} ImeiOrEsn_PR;

/* ImeiOrEsn */
typedef struct ImeiOrEsn {
	ImeiOrEsn_PR present;
	union ImeiOrEsn_u {
		Imei_t	 imei;
		Esn_t	 esn;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ImeiOrEsn_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ImeiOrEsn;

#ifdef __cplusplus
}
#endif

#endif	/* _ImeiOrEsn_H_ */
#include <asn_internal.h>
