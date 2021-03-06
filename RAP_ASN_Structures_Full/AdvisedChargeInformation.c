/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP-0312"
 */

#include "AdvisedChargeInformation.h"

static asn_TYPE_member_t asn_MBR_AdvisedChargeInformation_1[] = {
	{ ATF_POINTER, 5, offsetof(struct AdvisedChargeInformation, paidIndicator),
		(ASN_TAG_CLASS_APPLICATION | (346 << 2)),
		0,
		&asn_DEF_PaidIndicator,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"paidIndicator"
		},
	{ ATF_POINTER, 4, offsetof(struct AdvisedChargeInformation, paymentMethod),
		(ASN_TAG_CLASS_APPLICATION | (347 << 2)),
		0,
		&asn_DEF_PaymentMethod,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"paymentMethod"
		},
	{ ATF_POINTER, 3, offsetof(struct AdvisedChargeInformation, advisedChargeCurrency),
		(ASN_TAG_CLASS_APPLICATION | (348 << 2)),
		0,
		&asn_DEF_AdvisedChargeCurrency,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"advisedChargeCurrency"
		},
	{ ATF_POINTER, 2, offsetof(struct AdvisedChargeInformation, advisedCharge),
		(ASN_TAG_CLASS_APPLICATION | (349 << 2)),
		0,
		&asn_DEF_AdvisedCharge,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"advisedCharge"
		},
	{ ATF_POINTER, 1, offsetof(struct AdvisedChargeInformation, commission),
		(ASN_TAG_CLASS_APPLICATION | (350 << 2)),
		0,
		&asn_DEF_Commission,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"commission"
		},
};
static ber_tlv_tag_t asn_DEF_AdvisedChargeInformation_tags_1[] = {
	(ASN_TAG_CLASS_APPLICATION | (351 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_AdvisedChargeInformation_tag2el_1[] = {
    { (ASN_TAG_CLASS_APPLICATION | (346 << 2)), 0, 0, 0 }, /* paidIndicator */
    { (ASN_TAG_CLASS_APPLICATION | (347 << 2)), 1, 0, 0 }, /* paymentMethod */
    { (ASN_TAG_CLASS_APPLICATION | (348 << 2)), 2, 0, 0 }, /* advisedChargeCurrency */
    { (ASN_TAG_CLASS_APPLICATION | (349 << 2)), 3, 0, 0 }, /* advisedCharge */
    { (ASN_TAG_CLASS_APPLICATION | (350 << 2)), 4, 0, 0 } /* commission */
};
static asn_SEQUENCE_specifics_t asn_SPC_AdvisedChargeInformation_specs_1 = {
	sizeof(struct AdvisedChargeInformation),
	offsetof(struct AdvisedChargeInformation, _asn_ctx),
	asn_MAP_AdvisedChargeInformation_tag2el_1,
	5,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	4,	/* Start extensions */
	6	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_AdvisedChargeInformation = {
	"AdvisedChargeInformation",
	"AdvisedChargeInformation",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_AdvisedChargeInformation_tags_1,
	sizeof(asn_DEF_AdvisedChargeInformation_tags_1)
		/sizeof(asn_DEF_AdvisedChargeInformation_tags_1[0]) - 1, /* 1 */
	asn_DEF_AdvisedChargeInformation_tags_1,	/* Same as above */
	sizeof(asn_DEF_AdvisedChargeInformation_tags_1)
		/sizeof(asn_DEF_AdvisedChargeInformation_tags_1[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_AdvisedChargeInformation_1,
	5,	/* Elements count */
	&asn_SPC_AdvisedChargeInformation_specs_1	/* Additional specs */
};

