/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP-0312"
 */

#ifndef	_RequestedNumber_H_
#define	_RequestedNumber_H_


#include <asn_application.h>

/* Including external dependencies */
#include "AddressStringDigits.h"

#ifdef __cplusplus
extern "C" {
#endif

/* RequestedNumber */
typedef AddressStringDigits_t	 RequestedNumber_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RequestedNumber;
asn_struct_free_f RequestedNumber_free;
asn_struct_print_f RequestedNumber_print;
asn_constr_check_f RequestedNumber_constraint;
ber_type_decoder_f RequestedNumber_decode_ber;
der_type_encoder_f RequestedNumber_encode_der;
xer_type_decoder_f RequestedNumber_decode_xer;
xer_type_encoder_f RequestedNumber_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _RequestedNumber_H_ */
#include <asn_internal.h>