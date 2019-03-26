/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "RAP-0105"
 * 	found in "RAP_ASN_specification.txt"
 */

#include "ErrorDetail.h"

static asn_TYPE_member_t asn_MBR_ErrorDetail_1[] = {
	{ ATF_POINTER, 2, offsetof(struct ErrorDetail, errorContext),
		(ASN_TAG_CLASS_APPLICATION | (549 << 2)),
		0,
		&asn_DEF_ErrorContextList,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"errorContext"
		},
	{ ATF_POINTER, 1, offsetof(struct ErrorDetail, itemOffset),
		(ASN_TAG_CLASS_APPLICATION | (524 << 2)),
		0,
		&asn_DEF_ItemOffset,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"itemOffset"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct ErrorDetail, errorCode),
		(ASN_TAG_CLASS_APPLICATION | (519 << 2)),
		0,
		&asn_DEF_ErrorCode,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"errorCode"
		},
};
static ber_tlv_tag_t asn_DEF_ErrorDetail_tags_1[] = {
	(ASN_TAG_CLASS_APPLICATION | (521 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_ErrorDetail_tag2el_1[] = {
    { (ASN_TAG_CLASS_APPLICATION | (519 << 2)), 2, 0, 0 }, /* errorCode */
    { (ASN_TAG_CLASS_APPLICATION | (524 << 2)), 1, 0, 0 }, /* itemOffset */
    { (ASN_TAG_CLASS_APPLICATION | (549 << 2)), 0, 0, 0 } /* errorContext */
};
static asn_SEQUENCE_specifics_t asn_SPC_ErrorDetail_specs_1 = {
	sizeof(struct ErrorDetail),
	offsetof(struct ErrorDetail, _asn_ctx),
	asn_MAP_ErrorDetail_tag2el_1,
	3,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	2,	/* Start extensions */
	4	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_ErrorDetail = {
	"ErrorDetail",
	"ErrorDetail",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_ErrorDetail_tags_1,
	sizeof(asn_DEF_ErrorDetail_tags_1)
		/sizeof(asn_DEF_ErrorDetail_tags_1[0]) - 1, /* 1 */
	asn_DEF_ErrorDetail_tags_1,	/* Same as above */
	sizeof(asn_DEF_ErrorDetail_tags_1)
		/sizeof(asn_DEF_ErrorDetail_tags_1[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_ErrorDetail_1,
	3,	/* Elements count */
	&asn_SPC_ErrorDetail_specs_1	/* Additional specs */
};
