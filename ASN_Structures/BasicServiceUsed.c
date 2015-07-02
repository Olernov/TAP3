/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP3.12.asn1"
 */

#include "BasicServiceUsed.h"

static asn_TYPE_member_t asn_MBR_BasicServiceUsed_1[] = {
	{ ATF_POINTER, 4, offsetof(struct BasicServiceUsed, basicService),
		(ASN_TAG_CLASS_APPLICATION | (36 << 2)),
		0,
		&asn_DEF_BasicService,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"basicService"
		},
	{ ATF_POINTER, 3, offsetof(struct BasicServiceUsed, chargingTimeStamp),
		(ASN_TAG_CLASS_APPLICATION | (74 << 2)),
		0,
		&asn_DEF_ChargingTimeStamp,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"chargingTimeStamp"
		},
	{ ATF_POINTER, 2, offsetof(struct BasicServiceUsed, chargeInformationList),
		(ASN_TAG_CLASS_APPLICATION | (70 << 2)),
		0,
		&asn_DEF_ChargeInformationList,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"chargeInformationList"
		},
	{ ATF_POINTER, 1, offsetof(struct BasicServiceUsed, hSCSDIndicator),
		(ASN_TAG_CLASS_APPLICATION | (424 << 2)),
		0,
		&asn_DEF_HSCSDIndicator,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"hSCSDIndicator"
		},
};
static ber_tlv_tag_t asn_DEF_BasicServiceUsed_tags_1[] = {
	(ASN_TAG_CLASS_APPLICATION | (39 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_BasicServiceUsed_tag2el_1[] = {
    { (ASN_TAG_CLASS_APPLICATION | (36 << 2)), 0, 0, 0 }, /* basicService */
    { (ASN_TAG_CLASS_APPLICATION | (70 << 2)), 2, 0, 0 }, /* chargeInformationList */
    { (ASN_TAG_CLASS_APPLICATION | (74 << 2)), 1, 0, 0 }, /* chargingTimeStamp */
    { (ASN_TAG_CLASS_APPLICATION | (424 << 2)), 3, 0, 0 } /* hSCSDIndicator */
};
static asn_SEQUENCE_specifics_t asn_SPC_BasicServiceUsed_specs_1 = {
	sizeof(struct BasicServiceUsed),
	offsetof(struct BasicServiceUsed, _asn_ctx),
	asn_MAP_BasicServiceUsed_tag2el_1,
	4,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	3,	/* Start extensions */
	5	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_BasicServiceUsed = {
	"BasicServiceUsed",
	"BasicServiceUsed",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_BasicServiceUsed_tags_1,
	sizeof(asn_DEF_BasicServiceUsed_tags_1)
		/sizeof(asn_DEF_BasicServiceUsed_tags_1[0]) - 1, /* 1 */
	asn_DEF_BasicServiceUsed_tags_1,	/* Same as above */
	sizeof(asn_DEF_BasicServiceUsed_tags_1)
		/sizeof(asn_DEF_BasicServiceUsed_tags_1[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_BasicServiceUsed_1,
	4,	/* Elements count */
	&asn_SPC_BasicServiceUsed_specs_1	/* Additional specs */
};

