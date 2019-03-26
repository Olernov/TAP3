/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP-0312"
 */

#ifndef	_CallingNumber_H_
#define	_CallingNumber_H_


#include <asn_application.h>

/* Including external dependencies */
#include "AddressStringDigits.h"

#ifdef __cplusplus
extern "C" {
#endif

/* CallingNumber */
typedef AddressStringDigits_t	 CallingNumber_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CallingNumber;
asn_struct_free_f CallingNumber_free;
asn_struct_print_f CallingNumber_print;
asn_constr_check_f CallingNumber_constraint;
ber_type_decoder_f CallingNumber_decode_ber;
der_type_encoder_f CallingNumber_encode_der;
xer_type_decoder_f CallingNumber_decode_xer;
xer_type_encoder_f CallingNumber_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _CallingNumber_H_ */
#include <asn_internal.h>
