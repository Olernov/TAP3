/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP3.12.asn1"
 */

#ifndef	_BearerServiceCode_H_
#define	_BearerServiceCode_H_


#include <asn_application.h>

/* Including external dependencies */
#include "HexString.h"

#ifdef __cplusplus
extern "C" {
#endif

/* BearerServiceCode */
typedef HexString_t	 BearerServiceCode_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_BearerServiceCode;
asn_struct_free_f BearerServiceCode_free;
asn_struct_print_f BearerServiceCode_print;
asn_constr_check_f BearerServiceCode_constraint;
ber_type_decoder_f BearerServiceCode_decode_ber;
der_type_encoder_f BearerServiceCode_encode_der;
xer_type_decoder_f BearerServiceCode_decode_xer;
xer_type_encoder_f BearerServiceCode_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _BearerServiceCode_H_ */
#include <asn_internal.h>
