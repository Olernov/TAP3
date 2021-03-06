/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "RAP-0105"
 * 	found in "RAP_ASN_specification.txt"
 */

#include "NetworkInfoError.h"

static asn_TYPE_member_t asn_MBR_NetworkInfoError_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct NetworkInfoError, networkInfo),
		(ASN_TAG_CLASS_APPLICATION | (6 << 2)),
		0,
		&asn_DEF_NetworkInfo,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"networkInfo"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct NetworkInfoError, errorDetail),
		(ASN_TAG_CLASS_APPLICATION | (520 << 2)),
		0,
		&asn_DEF_ErrorDetailList,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"errorDetail"
		},
};
static ber_tlv_tag_t asn_DEF_NetworkInfoError_tags_1[] = {
	(ASN_TAG_CLASS_APPLICATION | (523 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_NetworkInfoError_tag2el_1[] = {
    { (ASN_TAG_CLASS_APPLICATION | (6 << 2)), 0, 0, 0 }, /* networkInfo */
    { (ASN_TAG_CLASS_APPLICATION | (520 << 2)), 1, 0, 0 } /* errorDetail */
};
static asn_SEQUENCE_specifics_t asn_SPC_NetworkInfoError_specs_1 = {
	sizeof(struct NetworkInfoError),
	offsetof(struct NetworkInfoError, _asn_ctx),
	asn_MAP_NetworkInfoError_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	1,	/* Start extensions */
	3	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_NetworkInfoError = {
	"NetworkInfoError",
	"NetworkInfoError",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_NetworkInfoError_tags_1,
	sizeof(asn_DEF_NetworkInfoError_tags_1)
		/sizeof(asn_DEF_NetworkInfoError_tags_1[0]) - 1, /* 1 */
	asn_DEF_NetworkInfoError_tags_1,	/* Same as above */
	sizeof(asn_DEF_NetworkInfoError_tags_1)
		/sizeof(asn_DEF_NetworkInfoError_tags_1[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_NetworkInfoError_1,
	2,	/* Elements count */
	&asn_SPC_NetworkInfoError_specs_1	/* Additional specs */
};

