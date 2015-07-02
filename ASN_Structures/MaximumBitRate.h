/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP3.12.asn1"
 */

#ifndef	_MaximumBitRate_H_
#define	_MaximumBitRate_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OCTET_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* MaximumBitRate */
typedef OCTET_STRING_t	 MaximumBitRate_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MaximumBitRate;
asn_struct_free_f MaximumBitRate_free;
asn_struct_print_f MaximumBitRate_print;
asn_constr_check_f MaximumBitRate_constraint;
ber_type_decoder_f MaximumBitRate_decode_ber;
der_type_encoder_f MaximumBitRate_encode_der;
xer_type_decoder_f MaximumBitRate_decode_xer;
xer_type_encoder_f MaximumBitRate_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _MaximumBitRate_H_ */
#include <asn_internal.h>