/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP-0312"
 */

#ifndef	_BCDString_H_
#define	_BCDString_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OCTET_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* BCDString */
typedef OCTET_STRING_t	 BCDString_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_BCDString;
asn_struct_free_f BCDString_free;
asn_struct_print_f BCDString_print;
asn_constr_check_f BCDString_constraint;
ber_type_decoder_f BCDString_decode_ber;
der_type_encoder_f BCDString_encode_der;
xer_type_decoder_f BCDString_decode_xer;
xer_type_encoder_f BCDString_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _BCDString_H_ */
#include <asn_internal.h>