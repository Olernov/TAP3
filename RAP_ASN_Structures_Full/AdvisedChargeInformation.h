/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP-0312"
 */

#ifndef	_AdvisedChargeInformation_H_
#define	_AdvisedChargeInformation_H_


#include <asn_application.h>

/* Including external dependencies */
#include "PaidIndicator.h"
#include "PaymentMethod.h"
#include "AdvisedChargeCurrency.h"
#include "AdvisedCharge.h"
#include "Commission.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* AdvisedChargeInformation */
typedef struct AdvisedChargeInformation {
	PaidIndicator_t	*paidIndicator	/* OPTIONAL */;
	PaymentMethod_t	*paymentMethod	/* OPTIONAL */;
	AdvisedChargeCurrency_t	*advisedChargeCurrency	/* OPTIONAL */;
	AdvisedCharge_t	*advisedCharge	/* OPTIONAL */;
	Commission_t	*commission	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} AdvisedChargeInformation_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_AdvisedChargeInformation;

#ifdef __cplusplus
}
#endif

#endif	/* _AdvisedChargeInformation_H_ */
#include <asn_internal.h>
