/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP3.12.asn1"
 */

#include "LocationServiceUsage.h"

static asn_TYPE_member_t asn_MBR_LocationServiceUsage_1[] = {
	{ ATF_POINTER, 4, offsetof(struct LocationServiceUsage, lCSQosRequested),
		(ASN_TAG_CLASS_APPLICATION | (383 << 2)),
		0,
		&asn_DEF_LCSQosRequested,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"lCSQosRequested"
		},
	{ ATF_POINTER, 3, offsetof(struct LocationServiceUsage, lCSQosDelivered),
		(ASN_TAG_CLASS_APPLICATION | (390 << 2)),
		0,
		&asn_DEF_LCSQosDelivered,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"lCSQosDelivered"
		},
	{ ATF_POINTER, 2, offsetof(struct LocationServiceUsage, chargingTimeStamp),
		(ASN_TAG_CLASS_APPLICATION | (74 << 2)),
		0,
		&asn_DEF_ChargingTimeStamp,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"chargingTimeStamp"
		},
	{ ATF_POINTER, 1, offsetof(struct LocationServiceUsage, chargeInformationList),
		(ASN_TAG_CLASS_APPLICATION | (70 << 2)),
		0,
		&asn_DEF_ChargeInformationList,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"chargeInformationList"
		},
};
static ber_tlv_tag_t asn_DEF_LocationServiceUsage_tags_1[] = {
	(ASN_TAG_CLASS_APPLICATION | (382 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_LocationServiceUsage_tag2el_1[] = {
    { (ASN_TAG_CLASS_APPLICATION | (70 << 2)), 3, 0, 0 }, /* chargeInformationList */
    { (ASN_TAG_CLASS_APPLICATION | (74 << 2)), 2, 0, 0 }, /* chargingTimeStamp */
    { (ASN_TAG_CLASS_APPLICATION | (383 << 2)), 0, 0, 0 }, /* lCSQosRequested */
    { (ASN_TAG_CLASS_APPLICATION | (390 << 2)), 1, 0, 0 } /* lCSQosDelivered */
};
static asn_SEQUENCE_specifics_t asn_SPC_LocationServiceUsage_specs_1 = {
	sizeof(struct LocationServiceUsage),
	offsetof(struct LocationServiceUsage, _asn_ctx),
	asn_MAP_LocationServiceUsage_tag2el_1,
	4,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	3,	/* Start extensions */
	5	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_LocationServiceUsage = {
	"LocationServiceUsage",
	"LocationServiceUsage",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_LocationServiceUsage_tags_1,
	sizeof(asn_DEF_LocationServiceUsage_tags_1)
		/sizeof(asn_DEF_LocationServiceUsage_tags_1[0]) - 1, /* 1 */
	asn_DEF_LocationServiceUsage_tags_1,	/* Same as above */
	sizeof(asn_DEF_LocationServiceUsage_tags_1)
		/sizeof(asn_DEF_LocationServiceUsage_tags_1[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_LocationServiceUsage_1,
	4,	/* Elements count */
	&asn_SPC_LocationServiceUsage_specs_1	/* Additional specs */
};
