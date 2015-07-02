/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP-0312"
 */

#include "GprsDestination.h"

static asn_TYPE_member_t asn_MBR_GprsDestination_1[] = {
	{ ATF_POINTER, 2, offsetof(struct GprsDestination, accessPointNameNI),
		(ASN_TAG_CLASS_APPLICATION | (261 << 2)),
		0,
		&asn_DEF_AccessPointNameNI,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"accessPointNameNI"
		},
	{ ATF_POINTER, 1, offsetof(struct GprsDestination, accessPointNameOI),
		(ASN_TAG_CLASS_APPLICATION | (262 << 2)),
		0,
		&asn_DEF_AccessPointNameOI,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"accessPointNameOI"
		},
};
static ber_tlv_tag_t asn_DEF_GprsDestination_tags_1[] = {
	(ASN_TAG_CLASS_APPLICATION | (116 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_GprsDestination_tag2el_1[] = {
    { (ASN_TAG_CLASS_APPLICATION | (261 << 2)), 0, 0, 0 }, /* accessPointNameNI */
    { (ASN_TAG_CLASS_APPLICATION | (262 << 2)), 1, 0, 0 } /* accessPointNameOI */
};
static asn_SEQUENCE_specifics_t asn_SPC_GprsDestination_specs_1 = {
	sizeof(struct GprsDestination),
	offsetof(struct GprsDestination, _asn_ctx),
	asn_MAP_GprsDestination_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	1,	/* Start extensions */
	3	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_GprsDestination = {
	"GprsDestination",
	"GprsDestination",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_GprsDestination_tags_1,
	sizeof(asn_DEF_GprsDestination_tags_1)
		/sizeof(asn_DEF_GprsDestination_tags_1[0]) - 1, /* 1 */
	asn_DEF_GprsDestination_tags_1,	/* Same as above */
	sizeof(asn_DEF_GprsDestination_tags_1)
		/sizeof(asn_DEF_GprsDestination_tags_1[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_GprsDestination_1,
	2,	/* Elements count */
	&asn_SPC_GprsDestination_specs_1	/* Additional specs */
};

