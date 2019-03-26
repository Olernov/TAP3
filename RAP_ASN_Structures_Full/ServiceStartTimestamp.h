/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP-0312"
 */

#ifndef	_ServiceStartTimestamp_H_
#define	_ServiceStartTimestamp_H_


#include <asn_application.h>

/* Including external dependencies */
#include "DateTime.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ServiceStartTimestamp */
typedef DateTime_t	 ServiceStartTimestamp_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ServiceStartTimestamp;
asn_struct_free_f ServiceStartTimestamp_free;
asn_struct_print_f ServiceStartTimestamp_print;
asn_constr_check_f ServiceStartTimestamp_constraint;
ber_type_decoder_f ServiceStartTimestamp_decode_ber;
der_type_encoder_f ServiceStartTimestamp_encode_der;
xer_type_decoder_f ServiceStartTimestamp_decode_xer;
xer_type_encoder_f ServiceStartTimestamp_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _ServiceStartTimestamp_H_ */
#include <asn_internal.h>
