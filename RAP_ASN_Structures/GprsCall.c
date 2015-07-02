/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP-0312"
 */

#include "GprsCall.h"

static asn_TYPE_member_t asn_MBR_GprsCall_1[] = {
	{ ATF_POINTER, 6, offsetof(struct GprsCall, gprsBasicCallInformation),
		(ASN_TAG_CLASS_APPLICATION | (114 << 2)),
		0,
		&asn_DEF_GprsBasicCallInformation,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"gprsBasicCallInformation"
		},
	{ ATF_POINTER, 5, offsetof(struct GprsCall, gprsLocationInformation),
		(ASN_TAG_CLASS_APPLICATION | (117 << 2)),
		0,
		&asn_DEF_GprsLocationInformation,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"gprsLocationInformation"
		},
	{ ATF_POINTER, 4, offsetof(struct GprsCall, equipmentIdentifier),
		(ASN_TAG_CLASS_APPLICATION | (429 << 2)),
		0,
		&asn_DEF_ImeiOrEsn,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"equipmentIdentifier"
		},
	{ ATF_POINTER, 3, offsetof(struct GprsCall, gprsServiceUsed),
		(ASN_TAG_CLASS_APPLICATION | (121 << 2)),
		0,
		&asn_DEF_GprsServiceUsed,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"gprsServiceUsed"
		},
	{ ATF_POINTER, 2, offsetof(struct GprsCall, camelServiceUsed),
		(ASN_TAG_CLASS_APPLICATION | (57 << 2)),
		0,
		&asn_DEF_CamelServiceUsed,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"camelServiceUsed"
		},
	{ ATF_POINTER, 1, offsetof(struct GprsCall, operatorSpecInformation),
		(ASN_TAG_CLASS_APPLICATION | (162 << 2)),
		0,
		&asn_DEF_OperatorSpecInfoList,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"operatorSpecInformation"
		},
};
static ber_tlv_tag_t asn_DEF_GprsCall_tags_1[] = {
	(ASN_TAG_CLASS_APPLICATION | (14 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_GprsCall_tag2el_1[] = {
    { (ASN_TAG_CLASS_APPLICATION | (57 << 2)), 4, 0, 0 }, /* camelServiceUsed */
    { (ASN_TAG_CLASS_APPLICATION | (114 << 2)), 0, 0, 0 }, /* gprsBasicCallInformation */
    { (ASN_TAG_CLASS_APPLICATION | (117 << 2)), 1, 0, 0 }, /* gprsLocationInformation */
    { (ASN_TAG_CLASS_APPLICATION | (121 << 2)), 3, 0, 0 }, /* gprsServiceUsed */
    { (ASN_TAG_CLASS_APPLICATION | (162 << 2)), 5, 0, 0 }, /* operatorSpecInformation */
    { (ASN_TAG_CLASS_APPLICATION | (429 << 2)), 2, 0, 0 } /* equipmentIdentifier */
};
static asn_SEQUENCE_specifics_t asn_SPC_GprsCall_specs_1 = {
	sizeof(struct GprsCall),
	offsetof(struct GprsCall, _asn_ctx),
	asn_MAP_GprsCall_tag2el_1,
	6,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	5,	/* Start extensions */
	7	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_GprsCall = {
	"GprsCall",
	"GprsCall",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_GprsCall_tags_1,
	sizeof(asn_DEF_GprsCall_tags_1)
		/sizeof(asn_DEF_GprsCall_tags_1[0]) - 1, /* 1 */
	asn_DEF_GprsCall_tags_1,	/* Same as above */
	sizeof(asn_DEF_GprsCall_tags_1)
		/sizeof(asn_DEF_GprsCall_tags_1[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_GprsCall_1,
	6,	/* Elements count */
	&asn_SPC_GprsCall_specs_1	/* Additional specs */
};

