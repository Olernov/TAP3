/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP-0312"
 */

#ifndef	_HomeBid_H_
#define	_HomeBid_H_


#include <asn_application.h>

/* Including external dependencies */
#include "Bid.h"

#ifdef __cplusplus
extern "C" {
#endif

/* HomeBid */
typedef Bid_t	 HomeBid_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_HomeBid;
asn_struct_free_f HomeBid_free;
asn_struct_print_f HomeBid_print;
asn_constr_check_f HomeBid_constraint;
ber_type_decoder_f HomeBid_decode_ber;
der_type_encoder_f HomeBid_encode_der;
xer_type_decoder_f HomeBid_decode_xer;
xer_type_encoder_f HomeBid_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _HomeBid_H_ */
#include <asn_internal.h>
