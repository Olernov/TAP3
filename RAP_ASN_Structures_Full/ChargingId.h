/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP-0312"
 */

#ifndef	_ChargingId_H_
#define	_ChargingId_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OCTET_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ChargingId */
typedef OCTET_STRING_t	 ChargingId_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ChargingId;
asn_struct_free_f ChargingId_free;
asn_struct_print_f ChargingId_print;
asn_constr_check_f ChargingId_constraint;
ber_type_decoder_f ChargingId_decode_ber;
der_type_encoder_f ChargingId_encode_der;
xer_type_decoder_f ChargingId_decode_xer;
xer_type_encoder_f ChargingId_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _ChargingId_H_ */
#include <asn_internal.h>
