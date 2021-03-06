/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "RAP-0105"
 * 	found in "RAP_ASN_specification.txt"
 */

#ifndef	_NotificationError_H_
#define	_NotificationError_H_


#include <asn_application.h>

/* Including external dependencies */
#include "Notification.h"
#include "ErrorDetailList.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* NotificationError */
typedef struct NotificationError {
	Notification_t	 notification;
	ErrorDetailList_t	 errorDetail;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NotificationError_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NotificationError;

#ifdef __cplusplus
}
#endif

#endif	/* _NotificationError_H_ */
#include <asn_internal.h>
