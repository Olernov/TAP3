/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP-0312"
 */

#include "GprsLocationInformation.h"

static asn_TYPE_member_t asn_MBR_GprsLocationInformation_1[] = {
	{ ATF_POINTER, 3, offsetof(struct GprsLocationInformation, gprsNetworkLocation),
		(ASN_TAG_CLASS_APPLICATION | (118 << 2)),
		0,
		&asn_DEF_GprsNetworkLocation,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"gprsNetworkLocation"
		},
	{ ATF_POINTER, 2, offsetof(struct GprsLocationInformation, homeLocationInformation),
		(ASN_TAG_CLASS_APPLICATION | (123 << 2)),
		0,
		&asn_DEF_HomeLocationInformation,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"homeLocationInformation"
		},
	{ ATF_POINTER, 1, offsetof(struct GprsLocationInformation, geographicalLocation),
		(ASN_TAG_CLASS_APPLICATION | (113 << 2)),
		0,
		&asn_DEF_GeographicalLocation,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"geographicalLocation"
		},
};
static ber_tlv_tag_t asn_DEF_GprsLocationInformation_tags_1[] = {
	(ASN_TAG_CLASS_APPLICATION | (117 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_GprsLocationInformation_tag2el_1[] = {
    { (ASN_TAG_CLASS_APPLICATION | (113 << 2)), 2, 0, 0 }, /* geographicalLocation */
    { (ASN_TAG_CLASS_APPLICATION | (118 << 2)), 0, 0, 0 }, /* gprsNetworkLocation */
    { (ASN_TAG_CLASS_APPLICATION | (123 << 2)), 1, 0, 0 } /* homeLocationInformation */
};
static asn_SEQUENCE_specifics_t asn_SPC_GprsLocationInformation_specs_1 = {
	sizeof(struct GprsLocationInformation),
	offsetof(struct GprsLocationInformation, _asn_ctx),
	asn_MAP_GprsLocationInformation_tag2el_1,
	3,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	2,	/* Start extensions */
	4	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_GprsLocationInformation = {
	"GprsLocationInformation",
	"GprsLocationInformation",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_GprsLocationInformation_tags_1,
	sizeof(asn_DEF_GprsLocationInformation_tags_1)
		/sizeof(asn_DEF_GprsLocationInformation_tags_1[0]) - 1, /* 1 */
	asn_DEF_GprsLocationInformation_tags_1,	/* Same as above */
	sizeof(asn_DEF_GprsLocationInformation_tags_1)
		/sizeof(asn_DEF_GprsLocationInformation_tags_1[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_GprsLocationInformation_1,
	3,	/* Elements count */
	&asn_SPC_GprsLocationInformation_specs_1	/* Additional specs */
};
