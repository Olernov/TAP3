/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP3.12.asn1"
 */

#ifndef	_BatchControlInfo_H_
#define	_BatchControlInfo_H_


#include <asn_application.h>

/* Including external dependencies */
#include "Sender.h"
#include "Recipient.h"
#include "FileSequenceNumber.h"
#include "SpecificationVersionNumber.h"
#include "ReleaseVersionNumber.h"
#include "FileTypeIndicator.h"
#include "RapFileSequenceNumber.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct DateTimeLong;
struct OperatorSpecInfoList;

/* BatchControlInfo */
typedef struct BatchControlInfo {
	Sender_t	*sender	/* OPTIONAL */;
	Recipient_t	*recipient	/* OPTIONAL */;
	FileSequenceNumber_t	*fileSequenceNumber	/* OPTIONAL */;
	struct DateTimeLong	*fileCreationTimeStamp	/* OPTIONAL */;
	struct DateTimeLong	*transferCutOffTimeStamp	/* OPTIONAL */;
	struct DateTimeLong	*fileAvailableTimeStamp	/* OPTIONAL */;
	SpecificationVersionNumber_t	*specificationVersionNumber	/* OPTIONAL */;
	ReleaseVersionNumber_t	*releaseVersionNumber	/* OPTIONAL */;
	FileTypeIndicator_t	*fileTypeIndicator	/* OPTIONAL */;
	RapFileSequenceNumber_t	*rapFileSequenceNumber	/* OPTIONAL */;
	struct OperatorSpecInfoList	*operatorSpecInformation	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} BatchControlInfo_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_BatchControlInfo;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "FileCreationTimeStamp.h"
#include "TransferCutOffTimeStamp.h"
#include "FileAvailableTimeStamp.h"
#include "OperatorSpecInfoList.h"

#endif	/* _BatchControlInfo_H_ */
#include <asn_internal.h>
