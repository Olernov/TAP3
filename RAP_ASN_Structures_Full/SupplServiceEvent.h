/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP-0312"
 */

#ifndef	_SupplServiceEvent_H_
#define	_SupplServiceEvent_H_


#include <asn_application.h>

/* Including external dependencies */
#include "RapFileSequenceNumber.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ChargeableSubscriber;
struct LocationInformation;
struct ImeiOrEsn;
struct SupplServiceUsed;
struct OperatorSpecInfoList;

/* SupplServiceEvent */
typedef struct SupplServiceEvent {
	struct ChargeableSubscriber	*chargeableSubscriber	/* OPTIONAL */;
	RapFileSequenceNumber_t	*rapFileSequenceNumber	/* OPTIONAL */;
	struct LocationInformation	*locationInformation	/* OPTIONAL */;
	struct ImeiOrEsn	*equipmentIdentifier	/* OPTIONAL */;
	struct SupplServiceUsed	*supplServiceUsed	/* OPTIONAL */;
	struct OperatorSpecInfoList	*operatorSpecInformation	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SupplServiceEvent_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SupplServiceEvent;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ChargeableSubscriber.h"
#include "LocationInformation.h"
#include "ImeiOrEsn.h"
#include "SupplServiceUsed.h"
#include "OperatorSpecInfoList.h"

#endif	/* _SupplServiceEvent_H_ */
#include <asn_internal.h>
