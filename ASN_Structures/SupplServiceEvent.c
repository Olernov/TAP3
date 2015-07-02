/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP3.12.asn1"
 */

#include "SupplServiceEvent.h"

static asn_TYPE_member_t asn_MBR_SupplServiceEvent_1[] = {
	{ ATF_POINTER, 6, offsetof(struct SupplServiceEvent, chargeableSubscriber),
		(ASN_TAG_CLASS_APPLICATION | (427 << 2)),
		0,
		&asn_DEF_ChargeableSubscriber,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"chargeableSubscriber"
		},
	{ ATF_POINTER, 5, offsetof(struct SupplServiceEvent, rapFileSequenceNumber),
		(ASN_TAG_CLASS_APPLICATION | (181 << 2)),
		0,
		&asn_DEF_RapFileSequenceNumber,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"rapFileSequenceNumber"
		},
	{ ATF_POINTER, 4, offsetof(struct SupplServiceEvent, locationInformation),
		(ASN_TAG_CLASS_APPLICATION | (138 << 2)),
		0,
		&asn_DEF_LocationInformation,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"locationInformation"
		},
	{ ATF_POINTER, 3, offsetof(struct SupplServiceEvent, equipmentIdentifier),
		(ASN_TAG_CLASS_APPLICATION | (429 << 2)),
		0,
		&asn_DEF_ImeiOrEsn,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"equipmentIdentifier"
		},
	{ ATF_POINTER, 2, offsetof(struct SupplServiceEvent, supplServiceUsed),
		(ASN_TAG_CLASS_APPLICATION | (206 << 2)),
		0,
		&asn_DEF_SupplServiceUsed,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"supplServiceUsed"
		},
	{ ATF_POINTER, 1, offsetof(struct SupplServiceEvent, operatorSpecInformation),
		(ASN_TAG_CLASS_APPLICATION | (162 << 2)),
		0,
		&asn_DEF_OperatorSpecInfoList,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"operatorSpecInformation"
		},
};
static ber_tlv_tag_t asn_DEF_SupplServiceEvent_tags_1[] = {
	(ASN_TAG_CLASS_APPLICATION | (11 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_SupplServiceEvent_tag2el_1[] = {
    { (ASN_TAG_CLASS_APPLICATION | (138 << 2)), 2, 0, 0 }, /* locationInformation */
    { (ASN_TAG_CLASS_APPLICATION | (162 << 2)), 5, 0, 0 }, /* operatorSpecInformation */
    { (ASN_TAG_CLASS_APPLICATION | (181 << 2)), 1, 0, 0 }, /* rapFileSequenceNumber */
    { (ASN_TAG_CLASS_APPLICATION | (206 << 2)), 4, 0, 0 }, /* supplServiceUsed */
    { (ASN_TAG_CLASS_APPLICATION | (427 << 2)), 0, 0, 0 }, /* chargeableSubscriber */
    { (ASN_TAG_CLASS_APPLICATION | (429 << 2)), 3, 0, 0 } /* equipmentIdentifier */
};
static asn_SEQUENCE_specifics_t asn_SPC_SupplServiceEvent_specs_1 = {
	sizeof(struct SupplServiceEvent),
	offsetof(struct SupplServiceEvent, _asn_ctx),
	asn_MAP_SupplServiceEvent_tag2el_1,
	6,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	5,	/* Start extensions */
	7	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_SupplServiceEvent = {
	"SupplServiceEvent",
	"SupplServiceEvent",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_SupplServiceEvent_tags_1,
	sizeof(asn_DEF_SupplServiceEvent_tags_1)
		/sizeof(asn_DEF_SupplServiceEvent_tags_1[0]) - 1, /* 1 */
	asn_DEF_SupplServiceEvent_tags_1,	/* Same as above */
	sizeof(asn_DEF_SupplServiceEvent_tags_1)
		/sizeof(asn_DEF_SupplServiceEvent_tags_1[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_SupplServiceEvent_1,
	6,	/* Elements count */
	&asn_SPC_SupplServiceEvent_specs_1	/* Additional specs */
};

