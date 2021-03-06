/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "RAP-0105"
 * 	found in "RAP_ASN_specification.txt"
 */

#ifndef	_MessageDescriptionInformationDefinition_H_
#define	_MessageDescriptionInformationDefinition_H_


#include <asn_application.h>

/* Including external dependencies */
#include "MessageDescriptionCode.h"
#include "MessageDescription.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* MessageDescriptionInformationDefinition */
typedef struct MessageDescriptionInformationDefinition {
	MessageDescriptionCode_t	*messageDescriptionCode	/* OPTIONAL */;
	MessageDescription_t	*messageDescription	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} MessageDescriptionInformationDefinition_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MessageDescriptionInformationDefinition;

#ifdef __cplusplus
}
#endif

#endif	/* _MessageDescriptionInformationDefinition_H_ */
#include <asn_internal.h>
