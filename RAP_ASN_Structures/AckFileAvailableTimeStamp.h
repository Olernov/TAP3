/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "RAP-0105"
 * 	found in "RAP_ASN_specification.txt"
 */

#ifndef	_AckFileAvailableTimeStamp_H_
#define	_AckFileAvailableTimeStamp_H_


#include <asn_application.h>

/* Including external dependencies */
#include "DateTimeLong.h"

#ifdef __cplusplus
extern "C" {
#endif

/* AckFileAvailableTimeStamp */
typedef DateTimeLong_t	 AckFileAvailableTimeStamp_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_AckFileAvailableTimeStamp;
asn_struct_free_f AckFileAvailableTimeStamp_free;
asn_struct_print_f AckFileAvailableTimeStamp_print;
asn_constr_check_f AckFileAvailableTimeStamp_constraint;
ber_type_decoder_f AckFileAvailableTimeStamp_decode_ber;
der_type_encoder_f AckFileAvailableTimeStamp_encode_der;
xer_type_decoder_f AckFileAvailableTimeStamp_decode_xer;
xer_type_encoder_f AckFileAvailableTimeStamp_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _AckFileAvailableTimeStamp_H_ */
#include <asn_internal.h>