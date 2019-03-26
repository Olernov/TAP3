/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP-0312"
 */

#include "ChargeInformation.h"

static asn_TYPE_member_t asn_MBR_ChargeInformation_1[] = {
	{ ATF_POINTER, 6, offsetof(struct ChargeInformation, chargedItem),
		(ASN_TAG_CLASS_APPLICATION | (66 << 2)),
		0,
		&asn_DEF_ChargedItem,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"chargedItem"
		},
	{ ATF_POINTER, 5, offsetof(struct ChargeInformation, exchangeRateCode),
		(ASN_TAG_CLASS_APPLICATION | (105 << 2)),
		0,
		&asn_DEF_ExchangeRateCode,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"exchangeRateCode"
		},
	{ ATF_POINTER, 4, offsetof(struct ChargeInformation, callTypeGroup),
		(ASN_TAG_CLASS_APPLICATION | (258 << 2)),
		0,
		&asn_DEF_CallTypeGroup,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"callTypeGroup"
		},
	{ ATF_POINTER, 3, offsetof(struct ChargeInformation, chargeDetailList),
		(ASN_TAG_CLASS_APPLICATION | (64 << 2)),
		0,
		&asn_DEF_ChargeDetailList,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"chargeDetailList"
		},
	{ ATF_POINTER, 2, offsetof(struct ChargeInformation, taxInformation),
		(ASN_TAG_CLASS_APPLICATION | (214 << 2)),
		0,
		&asn_DEF_TaxInformationList,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"taxInformation"
		},
	{ ATF_POINTER, 1, offsetof(struct ChargeInformation, discountInformation),
		(ASN_TAG_CLASS_APPLICATION | (96 << 2)),
		0,
		&asn_DEF_DiscountInformation,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"discountInformation"
		},
};
static ber_tlv_tag_t asn_DEF_ChargeInformation_tags_1[] = {
	(ASN_TAG_CLASS_APPLICATION | (69 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_ChargeInformation_tag2el_1[] = {
    { (ASN_TAG_CLASS_APPLICATION | (64 << 2)), 3, 0, 0 }, /* chargeDetailList */
    { (ASN_TAG_CLASS_APPLICATION | (66 << 2)), 0, 0, 0 }, /* chargedItem */
    { (ASN_TAG_CLASS_APPLICATION | (96 << 2)), 5, 0, 0 }, /* discountInformation */
    { (ASN_TAG_CLASS_APPLICATION | (105 << 2)), 1, 0, 0 }, /* exchangeRateCode */
    { (ASN_TAG_CLASS_APPLICATION | (214 << 2)), 4, 0, 0 }, /* taxInformation */
    { (ASN_TAG_CLASS_APPLICATION | (258 << 2)), 2, 0, 0 } /* callTypeGroup */
};
static asn_SEQUENCE_specifics_t asn_SPC_ChargeInformation_specs_1 = {
	sizeof(struct ChargeInformation),
	offsetof(struct ChargeInformation, _asn_ctx),
	asn_MAP_ChargeInformation_tag2el_1,
	6,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	5,	/* Start extensions */
	7	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_ChargeInformation = {
	"ChargeInformation",
	"ChargeInformation",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_ChargeInformation_tags_1,
	sizeof(asn_DEF_ChargeInformation_tags_1)
		/sizeof(asn_DEF_ChargeInformation_tags_1[0]) - 1, /* 1 */
	asn_DEF_ChargeInformation_tags_1,	/* Same as above */
	sizeof(asn_DEF_ChargeInformation_tags_1)
		/sizeof(asn_DEF_ChargeInformation_tags_1[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_ChargeInformation_1,
	6,	/* Elements count */
	&asn_SPC_ChargeInformation_specs_1	/* Additional specs */
};

