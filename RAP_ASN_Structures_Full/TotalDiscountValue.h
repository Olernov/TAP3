/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP-0312"
 */

#ifndef	_TotalDiscountValue_H_
#define	_TotalDiscountValue_H_


#include <asn_application.h>

/* Including external dependencies */
#include "AbsoluteAmount.h"

#ifdef __cplusplus
extern "C" {
#endif

/* TotalDiscountValue */
typedef AbsoluteAmount_t	 TotalDiscountValue_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_TotalDiscountValue;
asn_struct_free_f TotalDiscountValue_free;
asn_struct_print_f TotalDiscountValue_print;
asn_constr_check_f TotalDiscountValue_constraint;
ber_type_decoder_f TotalDiscountValue_decode_ber;
der_type_encoder_f TotalDiscountValue_encode_der;
xer_type_decoder_f TotalDiscountValue_decode_xer;
xer_type_encoder_f TotalDiscountValue_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _TotalDiscountValue_H_ */
#include <asn_internal.h>
