/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP-0312"
 */

#ifndef	_TotalTaxValue_H_
#define	_TotalTaxValue_H_


#include <asn_application.h>

/* Including external dependencies */
#include "AbsoluteAmount.h"

#ifdef __cplusplus
extern "C" {
#endif

/* TotalTaxValue */
typedef AbsoluteAmount_t	 TotalTaxValue_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_TotalTaxValue;
asn_struct_free_f TotalTaxValue_free;
asn_struct_print_f TotalTaxValue_print;
asn_constr_check_f TotalTaxValue_constraint;
ber_type_decoder_f TotalTaxValue_decode_ber;
der_type_encoder_f TotalTaxValue_encode_der;
xer_type_decoder_f TotalTaxValue_decode_xer;
xer_type_encoder_f TotalTaxValue_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _TotalTaxValue_H_ */
#include <asn_internal.h>
