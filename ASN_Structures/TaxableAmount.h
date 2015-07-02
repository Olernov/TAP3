/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP3.12.asn1"
 */

#ifndef	_TaxableAmount_H_
#define	_TaxableAmount_H_


#include <asn_application.h>

/* Including external dependencies */
#include "AbsoluteAmount.h"

#ifdef __cplusplus
extern "C" {
#endif

/* TaxableAmount */
typedef AbsoluteAmount_t	 TaxableAmount_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_TaxableAmount;
asn_struct_free_f TaxableAmount_free;
asn_struct_print_f TaxableAmount_print;
asn_constr_check_f TaxableAmount_constraint;
ber_type_decoder_f TaxableAmount_decode_ber;
der_type_encoder_f TaxableAmount_encode_der;
xer_type_decoder_f TaxableAmount_decode_xer;
xer_type_encoder_f TaxableAmount_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _TaxableAmount_H_ */
#include <asn_internal.h>
