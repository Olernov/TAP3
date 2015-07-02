/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP3.12.asn1"
 */

#include "AuditControlInfo.h"

static asn_TYPE_member_t asn_MBR_AuditControlInfo_1[] = {
	{ ATF_POINTER, 11, offsetof(struct AuditControlInfo, earliestCallTimeStamp),
		(ASN_TAG_CLASS_APPLICATION | (101 << 2)),
		0,
		&asn_DEF_EarliestCallTimeStamp,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"earliestCallTimeStamp"
		},
	{ ATF_POINTER, 10, offsetof(struct AuditControlInfo, latestCallTimeStamp),
		(ASN_TAG_CLASS_APPLICATION | (133 << 2)),
		0,
		&asn_DEF_LatestCallTimeStamp,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"latestCallTimeStamp"
		},
	{ ATF_POINTER, 9, offsetof(struct AuditControlInfo, totalCharge),
		(ASN_TAG_CLASS_APPLICATION | (415 << 2)),
		0,
		&asn_DEF_TotalCharge,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"totalCharge"
		},
	{ ATF_POINTER, 8, offsetof(struct AuditControlInfo, totalChargeRefund),
		(ASN_TAG_CLASS_APPLICATION | (355 << 2)),
		0,
		&asn_DEF_TotalChargeRefund,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"totalChargeRefund"
		},
	{ ATF_POINTER, 7, offsetof(struct AuditControlInfo, totalTaxRefund),
		(ASN_TAG_CLASS_APPLICATION | (353 << 2)),
		0,
		&asn_DEF_TotalTaxRefund,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"totalTaxRefund"
		},
	{ ATF_POINTER, 6, offsetof(struct AuditControlInfo, totalTaxValue),
		(ASN_TAG_CLASS_APPLICATION | (226 << 2)),
		0,
		&asn_DEF_TotalTaxValue,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"totalTaxValue"
		},
	{ ATF_POINTER, 5, offsetof(struct AuditControlInfo, totalDiscountValue),
		(ASN_TAG_CLASS_APPLICATION | (225 << 2)),
		0,
		&asn_DEF_TotalDiscountValue,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"totalDiscountValue"
		},
	{ ATF_POINTER, 4, offsetof(struct AuditControlInfo, totalDiscountRefund),
		(ASN_TAG_CLASS_APPLICATION | (354 << 2)),
		0,
		&asn_DEF_TotalDiscountRefund,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"totalDiscountRefund"
		},
	{ ATF_POINTER, 3, offsetof(struct AuditControlInfo, totalAdvisedChargeValueList),
		(ASN_TAG_CLASS_APPLICATION | (361 << 2)),
		0,
		&asn_DEF_TotalAdvisedChargeValueList,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"totalAdvisedChargeValueList"
		},
	{ ATF_POINTER, 2, offsetof(struct AuditControlInfo, callEventDetailsCount),
		(ASN_TAG_CLASS_APPLICATION | (43 << 2)),
		0,
		&asn_DEF_CallEventDetailsCount,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"callEventDetailsCount"
		},
	{ ATF_POINTER, 1, offsetof(struct AuditControlInfo, operatorSpecInformation),
		(ASN_TAG_CLASS_APPLICATION | (162 << 2)),
		0,
		&asn_DEF_OperatorSpecInfoList,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"operatorSpecInformation"
		},
};
static ber_tlv_tag_t asn_DEF_AuditControlInfo_tags_1[] = {
	(ASN_TAG_CLASS_APPLICATION | (15 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_AuditControlInfo_tag2el_1[] = {
    { (ASN_TAG_CLASS_APPLICATION | (43 << 2)), 9, 0, 0 }, /* callEventDetailsCount */
    { (ASN_TAG_CLASS_APPLICATION | (101 << 2)), 0, 0, 0 }, /* earliestCallTimeStamp */
    { (ASN_TAG_CLASS_APPLICATION | (133 << 2)), 1, 0, 0 }, /* latestCallTimeStamp */
    { (ASN_TAG_CLASS_APPLICATION | (162 << 2)), 10, 0, 0 }, /* operatorSpecInformation */
    { (ASN_TAG_CLASS_APPLICATION | (225 << 2)), 6, 0, 0 }, /* totalDiscountValue */
    { (ASN_TAG_CLASS_APPLICATION | (226 << 2)), 5, 0, 0 }, /* totalTaxValue */
    { (ASN_TAG_CLASS_APPLICATION | (353 << 2)), 4, 0, 0 }, /* totalTaxRefund */
    { (ASN_TAG_CLASS_APPLICATION | (354 << 2)), 7, 0, 0 }, /* totalDiscountRefund */
    { (ASN_TAG_CLASS_APPLICATION | (355 << 2)), 3, 0, 0 }, /* totalChargeRefund */
    { (ASN_TAG_CLASS_APPLICATION | (361 << 2)), 8, 0, 0 }, /* totalAdvisedChargeValueList */
    { (ASN_TAG_CLASS_APPLICATION | (415 << 2)), 2, 0, 0 } /* totalCharge */
};
static asn_SEQUENCE_specifics_t asn_SPC_AuditControlInfo_specs_1 = {
	sizeof(struct AuditControlInfo),
	offsetof(struct AuditControlInfo, _asn_ctx),
	asn_MAP_AuditControlInfo_tag2el_1,
	11,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	10,	/* Start extensions */
	12	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_AuditControlInfo = {
	"AuditControlInfo",
	"AuditControlInfo",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_AuditControlInfo_tags_1,
	sizeof(asn_DEF_AuditControlInfo_tags_1)
		/sizeof(asn_DEF_AuditControlInfo_tags_1[0]) - 1, /* 1 */
	asn_DEF_AuditControlInfo_tags_1,	/* Same as above */
	sizeof(asn_DEF_AuditControlInfo_tags_1)
		/sizeof(asn_DEF_AuditControlInfo_tags_1[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_AuditControlInfo_1,
	11,	/* Elements count */
	&asn_SPC_AuditControlInfo_specs_1	/* Additional specs */
};

