/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP-0312"
 */

#include "MoBasicCallInformation.h"

static asn_TYPE_member_t asn_MBR_MoBasicCallInformation_1[] = {
	{ ATF_POINTER, 8, offsetof(struct MoBasicCallInformation, chargeableSubscriber),
		(ASN_TAG_CLASS_APPLICATION | (427 << 2)),
		0,
		&asn_DEF_ChargeableSubscriber,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"chargeableSubscriber"
		},
	{ ATF_POINTER, 7, offsetof(struct MoBasicCallInformation, rapFileSequenceNumber),
		(ASN_TAG_CLASS_APPLICATION | (181 << 2)),
		0,
		&asn_DEF_RapFileSequenceNumber,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"rapFileSequenceNumber"
		},
	{ ATF_POINTER, 6, offsetof(struct MoBasicCallInformation, destination),
		(ASN_TAG_CLASS_APPLICATION | (89 << 2)),
		0,
		&asn_DEF_Destination,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"destination"
		},
	{ ATF_POINTER, 5, offsetof(struct MoBasicCallInformation, destinationNetwork),
		(ASN_TAG_CLASS_APPLICATION | (90 << 2)),
		0,
		&asn_DEF_DestinationNetwork,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"destinationNetwork"
		},
	{ ATF_POINTER, 4, offsetof(struct MoBasicCallInformation, callEventStartTimeStamp),
		(ASN_TAG_CLASS_APPLICATION | (44 << 2)),
		0,
		&asn_DEF_CallEventStartTimeStamp,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"callEventStartTimeStamp"
		},
	{ ATF_POINTER, 3, offsetof(struct MoBasicCallInformation, totalCallEventDuration),
		(ASN_TAG_CLASS_APPLICATION | (223 << 2)),
		0,
		&asn_DEF_TotalCallEventDuration,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"totalCallEventDuration"
		},
	{ ATF_POINTER, 2, offsetof(struct MoBasicCallInformation, simToolkitIndicator),
		(ASN_TAG_CLASS_APPLICATION | (200 << 2)),
		0,
		&asn_DEF_SimToolkitIndicator,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"simToolkitIndicator"
		},
	{ ATF_POINTER, 1, offsetof(struct MoBasicCallInformation, causeForTerm),
		(ASN_TAG_CLASS_APPLICATION | (58 << 2)),
		0,
		&asn_DEF_CauseForTerm,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"causeForTerm"
		},
};
static ber_tlv_tag_t asn_DEF_MoBasicCallInformation_tags_1[] = {
	(ASN_TAG_CLASS_APPLICATION | (147 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_MoBasicCallInformation_tag2el_1[] = {
    { (ASN_TAG_CLASS_APPLICATION | (44 << 2)), 4, 0, 0 }, /* callEventStartTimeStamp */
    { (ASN_TAG_CLASS_APPLICATION | (58 << 2)), 7, 0, 0 }, /* causeForTerm */
    { (ASN_TAG_CLASS_APPLICATION | (89 << 2)), 2, 0, 0 }, /* destination */
    { (ASN_TAG_CLASS_APPLICATION | (90 << 2)), 3, 0, 0 }, /* destinationNetwork */
    { (ASN_TAG_CLASS_APPLICATION | (181 << 2)), 1, 0, 0 }, /* rapFileSequenceNumber */
    { (ASN_TAG_CLASS_APPLICATION | (200 << 2)), 6, 0, 0 }, /* simToolkitIndicator */
    { (ASN_TAG_CLASS_APPLICATION | (223 << 2)), 5, 0, 0 }, /* totalCallEventDuration */
    { (ASN_TAG_CLASS_APPLICATION | (427 << 2)), 0, 0, 0 } /* chargeableSubscriber */
};
static asn_SEQUENCE_specifics_t asn_SPC_MoBasicCallInformation_specs_1 = {
	sizeof(struct MoBasicCallInformation),
	offsetof(struct MoBasicCallInformation, _asn_ctx),
	asn_MAP_MoBasicCallInformation_tag2el_1,
	8,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	7,	/* Start extensions */
	9	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_MoBasicCallInformation = {
	"MoBasicCallInformation",
	"MoBasicCallInformation",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_MoBasicCallInformation_tags_1,
	sizeof(asn_DEF_MoBasicCallInformation_tags_1)
		/sizeof(asn_DEF_MoBasicCallInformation_tags_1[0]) - 1, /* 1 */
	asn_DEF_MoBasicCallInformation_tags_1,	/* Same as above */
	sizeof(asn_DEF_MoBasicCallInformation_tags_1)
		/sizeof(asn_DEF_MoBasicCallInformation_tags_1[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_MoBasicCallInformation_1,
	8,	/* Elements count */
	&asn_SPC_MoBasicCallInformation_specs_1	/* Additional specs */
};

