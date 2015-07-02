/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP-0312"
 */

#include "ScuBasicInformation.h"

static asn_TYPE_member_t asn_MBR_ScuBasicInformation_1[] = {
	{ ATF_POINTER, 6, offsetof(struct ScuBasicInformation, chargeableSubscriber),
		(ASN_TAG_CLASS_APPLICATION | (430 << 2)),
		0,
		&asn_DEF_ScuChargeableSubscriber,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"chargeableSubscriber"
		},
	{ ATF_POINTER, 5, offsetof(struct ScuBasicInformation, chargedPartyStatus),
		(ASN_TAG_CLASS_APPLICATION | (67 << 2)),
		0,
		&asn_DEF_ChargedPartyStatus,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"chargedPartyStatus"
		},
	{ ATF_POINTER, 4, offsetof(struct ScuBasicInformation, nonChargedNumber),
		(ASN_TAG_CLASS_APPLICATION | (402 << 2)),
		0,
		&asn_DEF_NonChargedNumber,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"nonChargedNumber"
		},
	{ ATF_POINTER, 3, offsetof(struct ScuBasicInformation, clirIndicator),
		(ASN_TAG_CLASS_APPLICATION | (75 << 2)),
		0,
		&asn_DEF_ClirIndicator,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"clirIndicator"
		},
	{ ATF_POINTER, 2, offsetof(struct ScuBasicInformation, originatingNetwork),
		(ASN_TAG_CLASS_APPLICATION | (164 << 2)),
		0,
		&asn_DEF_OriginatingNetwork,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"originatingNetwork"
		},
	{ ATF_POINTER, 1, offsetof(struct ScuBasicInformation, destinationNetwork),
		(ASN_TAG_CLASS_APPLICATION | (90 << 2)),
		0,
		&asn_DEF_DestinationNetwork,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"destinationNetwork"
		},
};
static ber_tlv_tag_t asn_DEF_ScuBasicInformation_tags_1[] = {
	(ASN_TAG_CLASS_APPLICATION | (191 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_ScuBasicInformation_tag2el_1[] = {
    { (ASN_TAG_CLASS_APPLICATION | (67 << 2)), 1, 0, 0 }, /* chargedPartyStatus */
    { (ASN_TAG_CLASS_APPLICATION | (75 << 2)), 3, 0, 0 }, /* clirIndicator */
    { (ASN_TAG_CLASS_APPLICATION | (90 << 2)), 5, 0, 0 }, /* destinationNetwork */
    { (ASN_TAG_CLASS_APPLICATION | (164 << 2)), 4, 0, 0 }, /* originatingNetwork */
    { (ASN_TAG_CLASS_APPLICATION | (402 << 2)), 2, 0, 0 }, /* nonChargedNumber */
    { (ASN_TAG_CLASS_APPLICATION | (430 << 2)), 0, 0, 0 } /* chargeableSubscriber */
};
static asn_SEQUENCE_specifics_t asn_SPC_ScuBasicInformation_specs_1 = {
	sizeof(struct ScuBasicInformation),
	offsetof(struct ScuBasicInformation, _asn_ctx),
	asn_MAP_ScuBasicInformation_tag2el_1,
	6,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	5,	/* Start extensions */
	7	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_ScuBasicInformation = {
	"ScuBasicInformation",
	"ScuBasicInformation",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_ScuBasicInformation_tags_1,
	sizeof(asn_DEF_ScuBasicInformation_tags_1)
		/sizeof(asn_DEF_ScuBasicInformation_tags_1[0]) - 1, /* 1 */
	asn_DEF_ScuBasicInformation_tags_1,	/* Same as above */
	sizeof(asn_DEF_ScuBasicInformation_tags_1)
		/sizeof(asn_DEF_ScuBasicInformation_tags_1[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_ScuBasicInformation_1,
	6,	/* Elements count */
	&asn_SPC_ScuBasicInformation_specs_1	/* Additional specs */
};

