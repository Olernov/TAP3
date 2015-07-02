/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP3.12.asn1"
 */

#ifndef	_Charge_H_
#define	_Charge_H_


#include <asn_application.h>

/* Including external dependencies */
#include "AbsoluteAmount.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Charge */
typedef AbsoluteAmount_t	 Charge_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Charge;
asn_struct_free_f Charge_free;
asn_struct_print_f Charge_print;
asn_constr_check_f Charge_constraint;
ber_type_decoder_f Charge_decode_ber;
der_type_encoder_f Charge_encode_der;
xer_type_decoder_f Charge_decode_xer;
xer_type_encoder_f Charge_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _Charge_H_ */
#include <asn_internal.h>
