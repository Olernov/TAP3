/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP-0312"
 */

#ifndef	_TaxInformation_H_
#define	_TaxInformation_H_


#include <asn_application.h>

/* Including external dependencies */
#include "TaxCode.h"
#include "TaxValue.h"
#include "TaxableAmount.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* TaxInformation */
typedef struct TaxInformation {
	TaxCode_t	*taxCode	/* OPTIONAL */;
	TaxValue_t	*taxValue	/* OPTIONAL */;
	TaxableAmount_t	*taxableAmount	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} TaxInformation_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_TaxInformation;

#ifdef __cplusplus
}
#endif

#endif	/* _TaxInformation_H_ */
#include <asn_internal.h>
