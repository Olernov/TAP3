/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP-0312"
 */

#ifndef	_TotalAdvisedChargeValue_H_
#define	_TotalAdvisedChargeValue_H_


#include <asn_application.h>

/* Including external dependencies */
#include "AdvisedChargeCurrency.h"
#include "TotalAdvisedCharge.h"
#include "TotalAdvisedChargeRefund.h"
#include "TotalCommission.h"
#include "TotalCommissionRefund.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* TotalAdvisedChargeValue */
typedef struct TotalAdvisedChargeValue {
	AdvisedChargeCurrency_t	*advisedChargeCurrency	/* OPTIONAL */;
	TotalAdvisedCharge_t	*totalAdvisedCharge	/* OPTIONAL */;
	TotalAdvisedChargeRefund_t	*totalAdvisedChargeRefund	/* OPTIONAL */;
	TotalCommission_t	*totalCommission	/* OPTIONAL */;
	TotalCommissionRefund_t	*totalCommissionRefund	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} TotalAdvisedChargeValue_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_TotalAdvisedChargeValue;

#ifdef __cplusplus
}
#endif

#endif	/* _TotalAdvisedChargeValue_H_ */
#include <asn_internal.h>