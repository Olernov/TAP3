/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP3.12.asn1"
 */

#include "TaxInformation.h"

static asn_TYPE_member_t asn_MBR_TaxInformation_1[] = {
	{ ATF_POINTER, 3, offsetof(struct TaxInformation, taxCode),
		(ASN_TAG_CLASS_APPLICATION | (212 << 2)),
		0,
		&asn_DEF_TaxCode,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"taxCode"
		},
	{ ATF_POINTER, 2, offsetof(struct TaxInformation, taxValue),
		(ASN_TAG_CLASS_APPLICATION | (397 << 2)),
		0,
		&asn_DEF_TaxValue,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"taxValue"
		},
	{ ATF_POINTER, 1, offsetof(struct TaxInformation, taxableAmount),
		(ASN_TAG_CLASS_APPLICATION | (398 << 2)),
		0,
		&asn_DEF_TaxableAmount,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"taxableAmount"
		},
};
static ber_tlv_tag_t asn_DEF_TaxInformation_tags_1[] = {
	(ASN_TAG_CLASS_APPLICATION | (213 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_TaxInformation_tag2el_1[] = {
    { (ASN_TAG_CLASS_APPLICATION | (212 << 2)), 0, 0, 0 }, /* taxCode */
    { (ASN_TAG_CLASS_APPLICATION | (397 << 2)), 1, 0, 0 }, /* taxValue */
    { (ASN_TAG_CLASS_APPLICATION | (398 << 2)), 2, 0, 0 } /* taxableAmount */
};
static asn_SEQUENCE_specifics_t asn_SPC_TaxInformation_specs_1 = {
	sizeof(struct TaxInformation),
	offsetof(struct TaxInformation, _asn_ctx),
	asn_MAP_TaxInformation_tag2el_1,
	3,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	2,	/* Start extensions */
	4	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_TaxInformation = {
	"TaxInformation",
	"TaxInformation",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_TaxInformation_tags_1,
	sizeof(asn_DEF_TaxInformation_tags_1)
		/sizeof(asn_DEF_TaxInformation_tags_1[0]) - 1, /* 1 */
	asn_DEF_TaxInformation_tags_1,	/* Same as above */
	sizeof(asn_DEF_TaxInformation_tags_1)
		/sizeof(asn_DEF_TaxInformation_tags_1[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_TaxInformation_1,
	3,	/* Elements count */
	&asn_SPC_TaxInformation_specs_1	/* Additional specs */
};

