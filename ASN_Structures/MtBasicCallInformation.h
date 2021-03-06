/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP3.12.asn1"
 */

#ifndef	_MtBasicCallInformation_H_
#define	_MtBasicCallInformation_H_


#include <asn_application.h>

/* Including external dependencies */
#include "RapFileSequenceNumber.h"
#include "OriginatingNetwork.h"
#include "TotalCallEventDuration.h"
#include "SimToolkitIndicator.h"
#include "CauseForTerm.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ChargeableSubscriber;
struct CallOriginator;
struct DateTime;

/* MtBasicCallInformation */
typedef struct MtBasicCallInformation {
	struct ChargeableSubscriber	*chargeableSubscriber	/* OPTIONAL */;
	RapFileSequenceNumber_t	*rapFileSequenceNumber	/* OPTIONAL */;
	struct CallOriginator	*callOriginator	/* OPTIONAL */;
	OriginatingNetwork_t	*originatingNetwork	/* OPTIONAL */;
	struct DateTime	*callEventStartTimeStamp	/* OPTIONAL */;
	TotalCallEventDuration_t	*totalCallEventDuration	/* OPTIONAL */;
	SimToolkitIndicator_t	*simToolkitIndicator	/* OPTIONAL */;
	CauseForTerm_t	*causeForTerm	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} MtBasicCallInformation_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MtBasicCallInformation;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ChargeableSubscriber.h"
#include "CallOriginator.h"
#include "CallEventStartTimeStamp.h"

#endif	/* _MtBasicCallInformation_H_ */
#include <asn_internal.h>
