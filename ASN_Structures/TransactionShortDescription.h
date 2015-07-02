/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP3.12.asn1"
 */

#ifndef	_TransactionShortDescription_H_
#define	_TransactionShortDescription_H_


#include <asn_application.h>

/* Including external dependencies */
#include "AsciiString.h"

#ifdef __cplusplus
extern "C" {
#endif

/* TransactionShortDescription */
typedef AsciiString_t	 TransactionShortDescription_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_TransactionShortDescription;
asn_struct_free_f TransactionShortDescription_free;
asn_struct_print_f TransactionShortDescription_print;
asn_constr_check_f TransactionShortDescription_constraint;
ber_type_decoder_f TransactionShortDescription_decode_ber;
der_type_encoder_f TransactionShortDescription_encode_der;
xer_type_decoder_f TransactionShortDescription_decode_xer;
xer_type_encoder_f TransactionShortDescription_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _TransactionShortDescription_H_ */
#include <asn_internal.h>
