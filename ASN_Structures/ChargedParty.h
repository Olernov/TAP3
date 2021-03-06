/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP3.12.asn1"
 */

#ifndef	_ChargedParty_H_
#define	_ChargedParty_H_


#include <asn_application.h>

/* Including external dependencies */
#include "Imsi.h"
#include "Msisdn.h"
#include "PublicUserId.h"
#include "HomeBid.h"
#include "HomeLocationDescription.h"
#include "Imei.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ChargedParty */
typedef struct ChargedParty {
	Imsi_t	*imsi	/* OPTIONAL */;
	Msisdn_t	*msisdn	/* OPTIONAL */;
	PublicUserId_t	*publicUserId	/* OPTIONAL */;
	HomeBid_t	*homeBid	/* OPTIONAL */;
	HomeLocationDescription_t	*homeLocationDescription	/* OPTIONAL */;
	Imei_t	*imei	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ChargedParty_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ChargedParty;

#ifdef __cplusplus
}
#endif

#endif	/* _ChargedParty_H_ */
#include <asn_internal.h>
