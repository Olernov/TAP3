/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP3.12.asn1"
 */

#include "CurrencyConversion.h"

static asn_TYPE_member_t asn_MBR_CurrencyConversion_1[] = {
	{ ATF_POINTER, 3, offsetof(struct CurrencyConversion, exchangeRateCode),
		(ASN_TAG_CLASS_APPLICATION | (105 << 2)),
		0,
		&asn_DEF_ExchangeRateCode,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"exchangeRateCode"
		},
	{ ATF_POINTER, 2, offsetof(struct CurrencyConversion, numberOfDecimalPlaces),
		(ASN_TAG_CLASS_APPLICATION | (159 << 2)),
		0,
		&asn_DEF_NumberOfDecimalPlaces,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"numberOfDecimalPlaces"
		},
	{ ATF_POINTER, 1, offsetof(struct CurrencyConversion, exchangeRate),
		(ASN_TAG_CLASS_APPLICATION | (104 << 2)),
		0,
		&asn_DEF_ExchangeRate,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"exchangeRate"
		},
};
static ber_tlv_tag_t asn_DEF_CurrencyConversion_tags_1[] = {
	(ASN_TAG_CLASS_APPLICATION | (106 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_CurrencyConversion_tag2el_1[] = {
    { (ASN_TAG_CLASS_APPLICATION | (104 << 2)), 2, 0, 0 }, /* exchangeRate */
    { (ASN_TAG_CLASS_APPLICATION | (105 << 2)), 0, 0, 0 }, /* exchangeRateCode */
    { (ASN_TAG_CLASS_APPLICATION | (159 << 2)), 1, 0, 0 } /* numberOfDecimalPlaces */
};
static asn_SEQUENCE_specifics_t asn_SPC_CurrencyConversion_specs_1 = {
	sizeof(struct CurrencyConversion),
	offsetof(struct CurrencyConversion, _asn_ctx),
	asn_MAP_CurrencyConversion_tag2el_1,
	3,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	2,	/* Start extensions */
	4	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_CurrencyConversion = {
	"CurrencyConversion",
	"CurrencyConversion",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_CurrencyConversion_tags_1,
	sizeof(asn_DEF_CurrencyConversion_tags_1)
		/sizeof(asn_DEF_CurrencyConversion_tags_1[0]) - 1, /* 1 */
	asn_DEF_CurrencyConversion_tags_1,	/* Same as above */
	sizeof(asn_DEF_CurrencyConversion_tags_1)
		/sizeof(asn_DEF_CurrencyConversion_tags_1[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_CurrencyConversion_1,
	3,	/* Elements count */
	&asn_SPC_CurrencyConversion_specs_1	/* Additional specs */
};
