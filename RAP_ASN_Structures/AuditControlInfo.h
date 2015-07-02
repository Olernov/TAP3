/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP-0312"
 */

#ifndef	_AuditControlInfo_H_
#define	_AuditControlInfo_H_


#include <asn_application.h>

/* Including external dependencies */
#include "TotalCharge.h"
#include "TotalChargeRefund.h"
#include "TotalTaxRefund.h"
#include "TotalTaxValue.h"
#include "TotalDiscountValue.h"
#include "TotalDiscountRefund.h"
#include "CallEventDetailsCount.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct DateTimeLong;
struct TotalAdvisedChargeValueList;
struct OperatorSpecInfoList;

/* AuditControlInfo */
typedef struct AuditControlInfo {
	struct DateTimeLong	*earliestCallTimeStamp	/* OPTIONAL */;
	struct DateTimeLong	*latestCallTimeStamp	/* OPTIONAL */;
	TotalCharge_t	*totalCharge	/* OPTIONAL */;
	TotalChargeRefund_t	*totalChargeRefund	/* OPTIONAL */;
	TotalTaxRefund_t	*totalTaxRefund	/* OPTIONAL */;
	TotalTaxValue_t	*totalTaxValue	/* OPTIONAL */;
	TotalDiscountValue_t	*totalDiscountValue	/* OPTIONAL */;
	TotalDiscountRefund_t	*totalDiscountRefund	/* OPTIONAL */;
	struct TotalAdvisedChargeValueList	*totalAdvisedChargeValueList	/* OPTIONAL */;
	CallEventDetailsCount_t	*callEventDetailsCount	/* OPTIONAL */;
	struct OperatorSpecInfoList	*operatorSpecInformation	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} AuditControlInfo_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_AuditControlInfo;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "EarliestCallTimeStamp.h"
#include "LatestCallTimeStamp.h"
#include "TotalAdvisedChargeValueList.h"
#include "OperatorSpecInfoList.h"

#endif	/* _AuditControlInfo_H_ */
#include <asn_internal.h>
