/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP3.12.asn1"
 */

#ifndef	_AddressStringDigits_H_
#define	_AddressStringDigits_H_


#include <asn_application.h>

/* Including external dependencies */
#include "BCDString.h"

#ifdef __cplusplus
extern "C" {
#endif

/* AddressStringDigits */
typedef BCDString_t	 AddressStringDigits_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_AddressStringDigits;
asn_struct_free_f AddressStringDigits_free;
asn_struct_print_f AddressStringDigits_print;
asn_constr_check_f AddressStringDigits_constraint;
ber_type_decoder_f AddressStringDigits_decode_ber;
der_type_encoder_f AddressStringDigits_encode_der;
xer_type_decoder_f AddressStringDigits_decode_xer;
xer_type_encoder_f AddressStringDigits_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _AddressStringDigits_H_ */
#include <asn_internal.h>
