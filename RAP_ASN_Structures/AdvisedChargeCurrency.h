/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP-0312"
 */

#ifndef	_AdvisedChargeCurrency_H_
#define	_AdvisedChargeCurrency_H_


#include <asn_application.h>

/* Including external dependencies */
#include "Currency.h"

#ifdef __cplusplus
extern "C" {
#endif

/* AdvisedChargeCurrency */
typedef Currency_t	 AdvisedChargeCurrency_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_AdvisedChargeCurrency;
asn_struct_free_f AdvisedChargeCurrency_free;
asn_struct_print_f AdvisedChargeCurrency_print;
asn_constr_check_f AdvisedChargeCurrency_constraint;
ber_type_decoder_f AdvisedChargeCurrency_decode_ber;
der_type_encoder_f AdvisedChargeCurrency_encode_der;
xer_type_decoder_f AdvisedChargeCurrency_decode_xer;
xer_type_encoder_f AdvisedChargeCurrency_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _AdvisedChargeCurrency_H_ */
#include <asn_internal.h>
