/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP-0312"
 */

#ifndef	_RequestedPublicUserId_H_
#define	_RequestedPublicUserId_H_


#include <asn_application.h>

/* Including external dependencies */
#include "AsciiString.h"

#ifdef __cplusplus
extern "C" {
#endif

/* RequestedPublicUserId */
typedef AsciiString_t	 RequestedPublicUserId_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RequestedPublicUserId;
asn_struct_free_f RequestedPublicUserId_free;
asn_struct_print_f RequestedPublicUserId_print;
asn_constr_check_f RequestedPublicUserId_constraint;
ber_type_decoder_f RequestedPublicUserId_decode_ber;
der_type_encoder_f RequestedPublicUserId_encode_der;
xer_type_decoder_f RequestedPublicUserId_decode_xer;
xer_type_encoder_f RequestedPublicUserId_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _RequestedPublicUserId_H_ */
#include <asn_internal.h>
