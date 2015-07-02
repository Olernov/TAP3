/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "RAP-0105"
 * 	found in "RAP_ASN_specification.txt"
 */

#ifndef	_Acknowledgement_H_
#define	_Acknowledgement_H_


#include <asn_application.h>

/* Including external dependencies */
#include "Sender.h"
#include "Recipient.h"
#include "RapFileSequenceNumber.h"
#include "AckFileCreationTimeStamp.h"
#include "AckFileAvailableTimeStamp.h"
#include "FileTypeIndicator.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct OperatorSpecList;

/* Acknowledgement */
typedef struct Acknowledgement {
	Sender_t	 sender;
	Recipient_t	 recipient;
	RapFileSequenceNumber_t	 rapFileSequenceNumber;
	AckFileCreationTimeStamp_t	 ackFileCreationTimeStamp;
	AckFileAvailableTimeStamp_t	 ackFileAvailableTimeStamp;
	FileTypeIndicator_t	*fileTypeIndicator	/* OPTIONAL */;
	struct OperatorSpecList	*operatorSpecList	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Acknowledgement_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Acknowledgement;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "OperatorSpecList.h"

#endif	/* _Acknowledgement_H_ */
#include <asn_internal.h>
