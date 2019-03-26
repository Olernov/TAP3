/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP-0312"
 */

#include "AccountingInfo.h"

static asn_TYPE_member_t asn_MBR_AccountingInfo_1[] = {
	{ ATF_POINTER, 6, offsetof(struct AccountingInfo, taxation),
		(ASN_TAG_CLASS_APPLICATION | (211 << 2)),
		0,
		&asn_DEF_TaxationList,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"taxation"
		},
	{ ATF_POINTER, 5, offsetof(struct AccountingInfo, discounting),
		(ASN_TAG_CLASS_APPLICATION | (95 << 2)),
		0,
		&asn_DEF_DiscountingList,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"discounting"
		},
	{ ATF_POINTER, 4, offsetof(struct AccountingInfo, localCurrency),
		(ASN_TAG_CLASS_APPLICATION | (135 << 2)),
		0,
		&asn_DEF_LocalCurrency,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"localCurrency"
		},
	{ ATF_POINTER, 3, offsetof(struct AccountingInfo, tapCurrency),
		(ASN_TAG_CLASS_APPLICATION | (210 << 2)),
		0,
		&asn_DEF_TapCurrency,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"tapCurrency"
		},
	{ ATF_POINTER, 2, offsetof(struct AccountingInfo, currencyConversionInfo),
		(ASN_TAG_CLASS_APPLICATION | (80 << 2)),
		0,
		&asn_DEF_CurrencyConversionList,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"currencyConversionInfo"
		},
	{ ATF_POINTER, 1, offsetof(struct AccountingInfo, tapDecimalPlaces),
		(ASN_TAG_CLASS_APPLICATION | (244 << 2)),
		0,
		&asn_DEF_TapDecimalPlaces,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"tapDecimalPlaces"
		},
};
static ber_tlv_tag_t asn_DEF_AccountingInfo_tags_1[] = {
	(ASN_TAG_CLASS_APPLICATION | (5 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_AccountingInfo_tag2el_1[] = {
    { (ASN_TAG_CLASS_APPLICATION | (80 << 2)), 4, 0, 0 }, /* currencyConversionInfo */
    { (ASN_TAG_CLASS_APPLICATION | (95 << 2)), 1, 0, 0 }, /* discounting */
    { (ASN_TAG_CLASS_APPLICATION | (135 << 2)), 2, 0, 0 }, /* localCurrency */
    { (ASN_TAG_CLASS_APPLICATION | (210 << 2)), 3, 0, 0 }, /* tapCurrency */
    { (ASN_TAG_CLASS_APPLICATION | (211 << 2)), 0, 0, 0 }, /* taxation */
    { (ASN_TAG_CLASS_APPLICATION | (244 << 2)), 5, 0, 0 } /* tapDecimalPlaces */
};
static asn_SEQUENCE_specifics_t asn_SPC_AccountingInfo_specs_1 = {
	sizeof(struct AccountingInfo),
	offsetof(struct AccountingInfo, _asn_ctx),
	asn_MAP_AccountingInfo_tag2el_1,
	6,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	5,	/* Start extensions */
	7	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_AccountingInfo = {
	"AccountingInfo",
	"AccountingInfo",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_AccountingInfo_tags_1,
	sizeof(asn_DEF_AccountingInfo_tags_1)
		/sizeof(asn_DEF_AccountingInfo_tags_1[0]) - 1, /* 1 */
	asn_DEF_AccountingInfo_tags_1,	/* Same as above */
	sizeof(asn_DEF_AccountingInfo_tags_1)
		/sizeof(asn_DEF_AccountingInfo_tags_1[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_AccountingInfo_1,
	6,	/* Elements count */
	&asn_SPC_AccountingInfo_specs_1	/* Additional specs */
};

