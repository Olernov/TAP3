/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP-0312"
 */

#ifndef	_CallOriginator_H_
#define	_CallOriginator_H_


#include <asn_application.h>

/* Including external dependencies */
#include "CallingNumber.h"
#include "ClirIndicator.h"
#include "SMSOriginator.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* CallOriginator */
typedef struct CallOriginator {
	CallingNumber_t	*callingNumber	/* OPTIONAL */;
	ClirIndicator_t	*clirIndicator	/* OPTIONAL */;
	SMSOriginator_t	*sMSOriginator	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} CallOriginator_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CallOriginator;

#ifdef __cplusplus
}
#endif

#endif	/* _CallOriginator_H_ */
#include <asn_internal.h>