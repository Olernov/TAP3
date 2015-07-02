/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP3.12.asn1"
 */

#include "DiscountApplied.h"

static asn_TYPE_member_t asn_MBR_DiscountApplied_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct DiscountApplied, choice.fixedDiscountValue),
		(ASN_TAG_CLASS_APPLICATION | (411 << 2)),
		0,
		&asn_DEF_FixedDiscountValue,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"fixedDiscountValue"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct DiscountApplied, choice.discountRate),
		(ASN_TAG_CLASS_APPLICATION | (92 << 2)),
		0,
		&asn_DEF_DiscountRate,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"discountRate"
		},
};
static ber_tlv_tag_t asn_DEF_DiscountApplied_tags_1[] = {
	(ASN_TAG_CLASS_APPLICATION | (428 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_DiscountApplied_tag2el_1[] = {
    { (ASN_TAG_CLASS_APPLICATION | (92 << 2)), 1, 0, 0 }, /* discountRate */
    { (ASN_TAG_CLASS_APPLICATION | (411 << 2)), 0, 0, 0 } /* fixedDiscountValue */
};
static asn_CHOICE_specifics_t asn_SPC_DiscountApplied_specs_1 = {
	sizeof(struct DiscountApplied),
	offsetof(struct DiscountApplied, _asn_ctx),
	offsetof(struct DiscountApplied, present),
	sizeof(((struct DiscountApplied *)0)->present),
	asn_MAP_DiscountApplied_tag2el_1,
	2,	/* Count of tags in the map */
	0,
	2	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_DiscountApplied = {
	"DiscountApplied",
	"DiscountApplied",
	CHOICE_free,
	CHOICE_print,
	CHOICE_constraint,
	CHOICE_decode_ber,
	CHOICE_encode_der,
	CHOICE_decode_xer,
	CHOICE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	CHOICE_outmost_tag,
	asn_DEF_DiscountApplied_tags_1,
	sizeof(asn_DEF_DiscountApplied_tags_1)
		/sizeof(asn_DEF_DiscountApplied_tags_1[0]), /* 1 */
	asn_DEF_DiscountApplied_tags_1,	/* Same as above */
	sizeof(asn_DEF_DiscountApplied_tags_1)
		/sizeof(asn_DEF_DiscountApplied_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_DiscountApplied_1,
	2,	/* Elements count */
	&asn_SPC_DiscountApplied_specs_1	/* Additional specs */
};

