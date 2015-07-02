/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP3.12.asn1"
 */

#ifndef	_ServiceCentreUsage_H_
#define	_ServiceCentreUsage_H_


#include <asn_application.h>

/* Including external dependencies */
#include "RapFileSequenceNumber.h"
#include "ServingNetwork.h"
#include "RecEntityCode.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ScuBasicInformation;
struct ChargeInformation;
struct ScuChargeType;
struct ScuTimeStamps;
struct OperatorSpecInfoList;

/* ServiceCentreUsage */
typedef struct ServiceCentreUsage {
	struct ScuBasicInformation	*basicInformation	/* OPTIONAL */;
	RapFileSequenceNumber_t	*rapFileSequenceNumber	/* OPTIONAL */;
	ServingNetwork_t	*servingNetwork	/* OPTIONAL */;
	RecEntityCode_t	*recEntityCode	/* OPTIONAL */;
	struct ChargeInformation	*chargeInformation	/* OPTIONAL */;
	struct ScuChargeType	*scuChargeType	/* OPTIONAL */;
	struct ScuTimeStamps	*scuTimeStamps	/* OPTIONAL */;
	struct OperatorSpecInfoList	*operatorSpecInformation	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ServiceCentreUsage_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ServiceCentreUsage;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ScuBasicInformation.h"
#include "ChargeInformation.h"
#include "ScuChargeType.h"
#include "ScuTimeStamps.h"
#include "OperatorSpecInfoList.h"

#endif	/* _ServiceCentreUsage_H_ */
#include <asn_internal.h>
