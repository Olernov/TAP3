/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "RAP-0105"
 * 	found in "RAP_ASN_specification.txt"
 */

#include "ReturnDetail.h"

static asn_TYPE_member_t asn_MBR_ReturnDetail_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct ReturnDetail, choice.stopReturn),
		(ASN_TAG_CLASS_APPLICATION | (554 << 2)),
		0,
		&asn_DEF_StopReturn,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"stopReturn"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct ReturnDetail, choice.missingReturn),
		(ASN_TAG_CLASS_APPLICATION | (538 << 2)),
		0,
		&asn_DEF_MissingReturn,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"missingReturn"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct ReturnDetail, choice.fatalReturn),
		(ASN_TAG_CLASS_APPLICATION | (539 << 2)),
		0,
		&asn_DEF_FatalReturn,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"fatalReturn"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct ReturnDetail, choice.severeReturn),
		(ASN_TAG_CLASS_APPLICATION | (540 << 2)),
		0,
		&asn_DEF_SevereReturn,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"severeReturn"
		},
};
static asn_TYPE_tag2member_t asn_MAP_ReturnDetail_tag2el_1[] = {
    { (ASN_TAG_CLASS_APPLICATION | (538 << 2)), 1, 0, 0 }, /* missingReturn */
    { (ASN_TAG_CLASS_APPLICATION | (539 << 2)), 2, 0, 0 }, /* fatalReturn */
    { (ASN_TAG_CLASS_APPLICATION | (540 << 2)), 3, 0, 0 }, /* severeReturn */
    { (ASN_TAG_CLASS_APPLICATION | (554 << 2)), 0, 0, 0 } /* stopReturn */
};
static asn_CHOICE_specifics_t asn_SPC_ReturnDetail_specs_1 = {
	sizeof(struct ReturnDetail),
	offsetof(struct ReturnDetail, _asn_ctx),
	offsetof(struct ReturnDetail, present),
	sizeof(((struct ReturnDetail *)0)->present),
	asn_MAP_ReturnDetail_tag2el_1,
	4,	/* Count of tags in the map */
	0,
	4	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_ReturnDetail = {
	"ReturnDetail",
	"ReturnDetail",
	CHOICE_free,
	CHOICE_print,
	CHOICE_constraint,
	CHOICE_decode_ber,
	CHOICE_encode_der,
	CHOICE_decode_xer,
	CHOICE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	CHOICE_outmost_tag,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	0,	/* No PER visible constraints */
	asn_MBR_ReturnDetail_1,
	4,	/* Elements count */
	&asn_SPC_ReturnDetail_specs_1	/* Additional specs */
};

