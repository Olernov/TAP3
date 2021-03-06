/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "RAP-0105"
 * 	found in "RAP_ASN_specification.txt"
 */

#ifndef	_MissingReturn_H_
#define	_MissingReturn_H_


#include <asn_application.h>

/* Including external dependencies */
#include "StartMissingSeqNumber.h"
#include "EndMissingSeqNumber.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct OperatorSpecList;

/* MissingReturn */
typedef struct MissingReturn {
	StartMissingSeqNumber_t	 startMissingSeqNumber;
	EndMissingSeqNumber_t	*endMissingSeqNumber	/* OPTIONAL */;
	struct OperatorSpecList	*operatorSpecList	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} MissingReturn_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MissingReturn;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "OperatorSpecList.h"

#endif	/* _MissingReturn_H_ */
#include <asn_internal.h>
