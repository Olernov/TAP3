/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP-0312"
 */

#include "ContentTransactionBasicInfo.h"

static asn_TYPE_member_t asn_MBR_ContentTransactionBasicInfo_1[] = {
	{ ATF_POINTER, 6, offsetof(struct ContentTransactionBasicInfo, rapFileSequenceNumber),
		(ASN_TAG_CLASS_APPLICATION | (181 << 2)),
		0,
		&asn_DEF_RapFileSequenceNumber,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"rapFileSequenceNumber"
		},
	{ ATF_POINTER, 5, offsetof(struct ContentTransactionBasicInfo, orderPlacedTimeStamp),
		(ASN_TAG_CLASS_APPLICATION | (300 << 2)),
		0,
		&asn_DEF_OrderPlacedTimeStamp,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"orderPlacedTimeStamp"
		},
	{ ATF_POINTER, 4, offsetof(struct ContentTransactionBasicInfo, requestedDeliveryTimeStamp),
		(ASN_TAG_CLASS_APPLICATION | (301 << 2)),
		0,
		&asn_DEF_RequestedDeliveryTimeStamp,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"requestedDeliveryTimeStamp"
		},
	{ ATF_POINTER, 3, offsetof(struct ContentTransactionBasicInfo, actualDeliveryTimeStamp),
		(ASN_TAG_CLASS_APPLICATION | (302 << 2)),
		0,
		&asn_DEF_ActualDeliveryTimeStamp,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"actualDeliveryTimeStamp"
		},
	{ ATF_POINTER, 2, offsetof(struct ContentTransactionBasicInfo, totalTransactionDuration),
		(ASN_TAG_CLASS_APPLICATION | (416 << 2)),
		0,
		&asn_DEF_TotalTransactionDuration,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"totalTransactionDuration"
		},
	{ ATF_POINTER, 1, offsetof(struct ContentTransactionBasicInfo, transactionStatus),
		(ASN_TAG_CLASS_APPLICATION | (303 << 2)),
		0,
		&asn_DEF_TransactionStatus,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"transactionStatus"
		},
};
static ber_tlv_tag_t asn_DEF_ContentTransactionBasicInfo_tags_1[] = {
	(ASN_TAG_CLASS_APPLICATION | (304 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_ContentTransactionBasicInfo_tag2el_1[] = {
    { (ASN_TAG_CLASS_APPLICATION | (181 << 2)), 0, 0, 0 }, /* rapFileSequenceNumber */
    { (ASN_TAG_CLASS_APPLICATION | (300 << 2)), 1, 0, 0 }, /* orderPlacedTimeStamp */
    { (ASN_TAG_CLASS_APPLICATION | (301 << 2)), 2, 0, 0 }, /* requestedDeliveryTimeStamp */
    { (ASN_TAG_CLASS_APPLICATION | (302 << 2)), 3, 0, 0 }, /* actualDeliveryTimeStamp */
    { (ASN_TAG_CLASS_APPLICATION | (303 << 2)), 5, 0, 0 }, /* transactionStatus */
    { (ASN_TAG_CLASS_APPLICATION | (416 << 2)), 4, 0, 0 } /* totalTransactionDuration */
};
static asn_SEQUENCE_specifics_t asn_SPC_ContentTransactionBasicInfo_specs_1 = {
	sizeof(struct ContentTransactionBasicInfo),
	offsetof(struct ContentTransactionBasicInfo, _asn_ctx),
	asn_MAP_ContentTransactionBasicInfo_tag2el_1,
	6,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	4,	/* Start extensions */
	7	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_ContentTransactionBasicInfo = {
	"ContentTransactionBasicInfo",
	"ContentTransactionBasicInfo",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_ContentTransactionBasicInfo_tags_1,
	sizeof(asn_DEF_ContentTransactionBasicInfo_tags_1)
		/sizeof(asn_DEF_ContentTransactionBasicInfo_tags_1[0]) - 1, /* 1 */
	asn_DEF_ContentTransactionBasicInfo_tags_1,	/* Same as above */
	sizeof(asn_DEF_ContentTransactionBasicInfo_tags_1)
		/sizeof(asn_DEF_ContentTransactionBasicInfo_tags_1[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_ContentTransactionBasicInfo_1,
	6,	/* Elements count */
	&asn_SPC_ContentTransactionBasicInfo_specs_1	/* Additional specs */
};

