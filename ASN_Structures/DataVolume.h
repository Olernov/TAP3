/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP3.12.asn1"
 */

#ifndef	_DataVolume_H_
#define	_DataVolume_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OCTET_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* DataVolume */
typedef OCTET_STRING_t	 DataVolume_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_DataVolume;
asn_struct_free_f DataVolume_free;
asn_struct_print_f DataVolume_print;
asn_constr_check_f DataVolume_constraint;
ber_type_decoder_f DataVolume_decode_ber;
der_type_encoder_f DataVolume_encode_der;
xer_type_decoder_f DataVolume_decode_xer;
xer_type_encoder_f DataVolume_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _DataVolume_H_ */
#include <asn_internal.h>
