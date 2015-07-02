/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "RAP-0105"
 * 	found in "RAP_ASN_specification.txt"
 */

#ifndef	_AckFileCreationTimeStamp_H_
#define	_AckFileCreationTimeStamp_H_


#include <asn_application.h>

/* Including external dependencies */
#include "DateTimeLong.h"

#ifdef __cplusplus
extern "C" {
#endif

/* AckFileCreationTimeStamp */
typedef DateTimeLong_t	 AckFileCreationTimeStamp_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_AckFileCreationTimeStamp;
asn_struct_free_f AckFileCreationTimeStamp_free;
asn_struct_print_f AckFileCreationTimeStamp_print;
asn_constr_check_f AckFileCreationTimeStamp_constraint;
ber_type_decoder_f AckFileCreationTimeStamp_decode_ber;
der_type_encoder_f AckFileCreationTimeStamp_encode_der;
xer_type_decoder_f AckFileCreationTimeStamp_decode_xer;
xer_type_encoder_f AckFileCreationTimeStamp_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _AckFileCreationTimeStamp_H_ */
#include <asn_internal.h>
