/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "RAP-0105"
 * 	found in "RAP_ASN_specification.txt"
 */

#ifndef	_FatalReturn_H_
#define	_FatalReturn_H_


#include <asn_application.h>

/* Including external dependencies */
#include "FileSequenceNumber.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct TransferBatchError;
struct NotificationError;
struct BatchControlError;
struct AccountingInfoError;
struct NetworkInfoError;
struct MessageDescriptionError;
struct AuditControlInfoError;
struct OperatorSpecList;

/* FatalReturn */
typedef struct FatalReturn {
	FileSequenceNumber_t	 fileSequenceNumber;
	struct TransferBatchError	*transferBatchError	/* OPTIONAL */;
	struct NotificationError	*notificationError	/* OPTIONAL */;
	struct BatchControlError	*batchControlError	/* OPTIONAL */;
	struct AccountingInfoError	*accountingInfoError	/* OPTIONAL */;
	struct NetworkInfoError	*networkInfoError	/* OPTIONAL */;
	struct MessageDescriptionError	*messageDescriptionError	/* OPTIONAL */;
	struct AuditControlInfoError	*auditControlInfoError	/* OPTIONAL */;
	struct OperatorSpecList	*operatorSpecList	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} FatalReturn_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_FatalReturn;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "TransferBatchError.h"
#include "NotificationError.h"
#include "BatchControlError.h"
#include "AccountingInfoError.h"
#include "NetworkInfoError.h"
#include "MessageDescriptionError.h"
#include "AuditControlInfoError.h"
#include "OperatorSpecList.h"

#endif	/* _FatalReturn_H_ */
#include <asn_internal.h>
