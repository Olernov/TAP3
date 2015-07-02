/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP3.12.asn1"
 */

#ifndef	_ContentProviderIdentifier_H_
#define	_ContentProviderIdentifier_H_


#include <asn_application.h>

/* Including external dependencies */
#include "AsciiString.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ContentProviderIdentifier */
typedef AsciiString_t	 ContentProviderIdentifier_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ContentProviderIdentifier;
asn_struct_free_f ContentProviderIdentifier_free;
asn_struct_print_f ContentProviderIdentifier_print;
asn_constr_check_f ContentProviderIdentifier_constraint;
ber_type_decoder_f ContentProviderIdentifier_decode_ber;
der_type_encoder_f ContentProviderIdentifier_encode_der;
xer_type_decoder_f ContentProviderIdentifier_decode_xer;
xer_type_encoder_f ContentProviderIdentifier_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _ContentProviderIdentifier_H_ */
#include <asn_internal.h>