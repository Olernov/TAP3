/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP-0312"
 */

#ifndef	_TotalTransactionDuration_H_
#define	_TotalTransactionDuration_H_


#include <asn_application.h>

/* Including external dependencies */
#include "TotalCallEventDuration.h"

#ifdef __cplusplus
extern "C" {
#endif

/* TotalTransactionDuration */
typedef TotalCallEventDuration_t	 TotalTransactionDuration_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_TotalTransactionDuration;
asn_struct_free_f TotalTransactionDuration_free;
asn_struct_print_f TotalTransactionDuration_print;
asn_constr_check_f TotalTransactionDuration_constraint;
ber_type_decoder_f TotalTransactionDuration_decode_ber;
der_type_encoder_f TotalTransactionDuration_encode_der;
xer_type_decoder_f TotalTransactionDuration_decode_xer;
xer_type_encoder_f TotalTransactionDuration_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _TotalTransactionDuration_H_ */
#include <asn_internal.h>