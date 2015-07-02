/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP3.12.asn1"
 */

#ifndef	_Taxation_H_
#define	_Taxation_H_


#include <asn_application.h>

/* Including external dependencies */
#include "TaxCode.h"
#include "TaxType.h"
#include "TaxRate.h"
#include "ChargeType.h"
#include "TaxIndicator.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Taxation */
typedef struct Taxation {
	TaxCode_t	*taxCode	/* OPTIONAL */;
	TaxType_t	*taxType	/* OPTIONAL */;
	TaxRate_t	*taxRate	/* OPTIONAL */;
	ChargeType_t	*chargeType	/* OPTIONAL */;
	TaxIndicator_t	*taxIndicator	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Taxation_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Taxation;

#ifdef __cplusplus
}
#endif

#endif	/* _Taxation_H_ */
#include <asn_internal.h>
