/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP3.12.asn1"
 */

#ifndef	_Min_H_
#define	_Min_H_


#include <asn_application.h>

/* Including external dependencies */
#include "NumberString.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Min */
typedef NumberString_t	 Min_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Min;
asn_struct_free_f Min_free;
asn_struct_print_f Min_print;
asn_constr_check_f Min_constraint;
ber_type_decoder_f Min_decode_ber;
der_type_encoder_f Min_encode_der;
xer_type_decoder_f Min_decode_xer;
xer_type_encoder_f Min_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _Min_H_ */
#include <asn_internal.h>
