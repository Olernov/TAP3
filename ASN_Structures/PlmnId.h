/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP3.12.asn1"
 */

#ifndef	_PlmnId_H_
#define	_PlmnId_H_


#include <asn_application.h>

/* Including external dependencies */
#include "AsciiString.h"

#ifdef __cplusplus
extern "C" {
#endif

/* PlmnId */
typedef AsciiString_t	 PlmnId_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_PlmnId;
asn_struct_free_f PlmnId_free;
asn_struct_print_f PlmnId_print;
asn_constr_check_f PlmnId_constraint;
ber_type_decoder_f PlmnId_decode_ber;
der_type_encoder_f PlmnId_encode_der;
xer_type_decoder_f PlmnId_decode_xer;
xer_type_encoder_f PlmnId_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _PlmnId_H_ */
#include <asn_internal.h>
