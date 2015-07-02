/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP3.12.asn1"
 */

#include "ContentTransaction.h"

static asn_TYPE_member_t asn_MBR_ContentTransaction_1[] = {
	{ ATF_POINTER, 5, offsetof(struct ContentTransaction, contentTransactionBasicInfo),
		(ASN_TAG_CLASS_APPLICATION | (304 << 2)),
		0,
		&asn_DEF_ContentTransactionBasicInfo,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"contentTransactionBasicInfo"
		},
	{ ATF_POINTER, 4, offsetof(struct ContentTransaction, chargedPartyInformation),
		(ASN_TAG_CLASS_APPLICATION | (324 << 2)),
		0,
		&asn_DEF_ChargedPartyInformation,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"chargedPartyInformation"
		},
	{ ATF_POINTER, 3, offsetof(struct ContentTransaction, servingPartiesInformation),
		(ASN_TAG_CLASS_APPLICATION | (335 << 2)),
		0,
		&asn_DEF_ServingPartiesInformation,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"servingPartiesInformation"
		},
	{ ATF_POINTER, 2, offsetof(struct ContentTransaction, contentServiceUsed),
		(ASN_TAG_CLASS_APPLICATION | (285 << 2)),
		0,
		&asn_DEF_ContentServiceUsedList,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"contentServiceUsed"
		},
	{ ATF_POINTER, 1, offsetof(struct ContentTransaction, operatorSpecInformation),
		(ASN_TAG_CLASS_APPLICATION | (162 << 2)),
		0,
		&asn_DEF_OperatorSpecInfoList,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"operatorSpecInformation"
		},
};
static ber_tlv_tag_t asn_DEF_ContentTransaction_tags_1[] = {
	(ASN_TAG_CLASS_APPLICATION | (17 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_ContentTransaction_tag2el_1[] = {
    { (ASN_TAG_CLASS_APPLICATION | (162 << 2)), 4, 0, 0 }, /* operatorSpecInformation */
    { (ASN_TAG_CLASS_APPLICATION | (285 << 2)), 3, 0, 0 }, /* contentServiceUsed */
    { (ASN_TAG_CLASS_APPLICATION | (304 << 2)), 0, 0, 0 }, /* contentTransactionBasicInfo */
    { (ASN_TAG_CLASS_APPLICATION | (324 << 2)), 1, 0, 0 }, /* chargedPartyInformation */
    { (ASN_TAG_CLASS_APPLICATION | (335 << 2)), 2, 0, 0 } /* servingPartiesInformation */
};
static asn_SEQUENCE_specifics_t asn_SPC_ContentTransaction_specs_1 = {
	sizeof(struct ContentTransaction),
	offsetof(struct ContentTransaction, _asn_ctx),
	asn_MAP_ContentTransaction_tag2el_1,
	5,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	4,	/* Start extensions */
	6	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_ContentTransaction = {
	"ContentTransaction",
	"ContentTransaction",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_ContentTransaction_tags_1,
	sizeof(asn_DEF_ContentTransaction_tags_1)
		/sizeof(asn_DEF_ContentTransaction_tags_1[0]) - 1, /* 1 */
	asn_DEF_ContentTransaction_tags_1,	/* Same as above */
	sizeof(asn_DEF_ContentTransaction_tags_1)
		/sizeof(asn_DEF_ContentTransaction_tags_1[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_ContentTransaction_1,
	5,	/* Elements count */
	&asn_SPC_ContentTransaction_specs_1	/* Additional specs */
};

