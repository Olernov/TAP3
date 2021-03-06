/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP3.12.asn1"
 */

#ifndef	_LatestCallTimeStamp_H_
#define	_LatestCallTimeStamp_H_


#include <asn_application.h>

/* Including external dependencies */
#include "DateTimeLong.h"

#ifdef __cplusplus
extern "C" {
#endif

/* LatestCallTimeStamp */
typedef DateTimeLong_t	 LatestCallTimeStamp_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_LatestCallTimeStamp;
asn_struct_free_f LatestCallTimeStamp_free;
asn_struct_print_f LatestCallTimeStamp_print;
asn_constr_check_f LatestCallTimeStamp_constraint;
ber_type_decoder_f LatestCallTimeStamp_decode_ber;
der_type_encoder_f LatestCallTimeStamp_encode_der;
xer_type_decoder_f LatestCallTimeStamp_decode_xer;
xer_type_encoder_f LatestCallTimeStamp_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _LatestCallTimeStamp_H_ */
#include <asn_internal.h>
