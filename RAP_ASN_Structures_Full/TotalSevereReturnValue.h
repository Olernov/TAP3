/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "RAP-0105"
 * 	found in "RAP_ASN_specification.txt"
 */

#ifndef	_TotalSevereReturnValue_H_
#define	_TotalSevereReturnValue_H_


#include <asn_application.h>

/* Including external dependencies */
#include "AbsoluteAmount.h"

#ifdef __cplusplus
extern "C" {
#endif

/* TotalSevereReturnValue */
typedef AbsoluteAmount_t	 TotalSevereReturnValue_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_TotalSevereReturnValue;
asn_struct_free_f TotalSevereReturnValue_free;
asn_struct_print_f TotalSevereReturnValue_print;
asn_constr_check_f TotalSevereReturnValue_constraint;
ber_type_decoder_f TotalSevereReturnValue_decode_ber;
der_type_encoder_f TotalSevereReturnValue_encode_der;
xer_type_decoder_f TotalSevereReturnValue_decode_xer;
xer_type_encoder_f TotalSevereReturnValue_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _TotalSevereReturnValue_H_ */
#include <asn_internal.h>
