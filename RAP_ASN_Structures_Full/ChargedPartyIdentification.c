/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP-0312"
 */

#include "ChargedPartyIdentification.h"

static asn_TYPE_member_t asn_MBR_ChargedPartyIdentification_1[] = {
	{ ATF_POINTER, 2, offsetof(struct ChargedPartyIdentification, chargedPartyIdType),
		(ASN_TAG_CLASS_APPLICATION | (305 << 2)),
		0,
		&asn_DEF_ChargedPartyIdType,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"chargedPartyIdType"
		},
	{ ATF_POINTER, 1, offsetof(struct ChargedPartyIdentification, chargedPartyIdentifier),
		(ASN_TAG_CLASS_APPLICATION | (287 << 2)),
		0,
		&asn_DEF_ChargedPartyIdentifier,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"chargedPartyIdentifier"
		},
};
static ber_tlv_tag_t asn_DEF_ChargedPartyIdentification_tags_1[] = {
	(ASN_TAG_CLASS_APPLICATION | (309 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_ChargedPartyIdentification_tag2el_1[] = {
    { (ASN_TAG_CLASS_APPLICATION | (287 << 2)), 1, 0, 0 }, /* chargedPartyIdentifier */
    { (ASN_TAG_CLASS_APPLICATION | (305 << 2)), 0, 0, 0 } /* chargedPartyIdType */
};
static asn_SEQUENCE_specifics_t asn_SPC_ChargedPartyIdentification_specs_1 = {
	sizeof(struct ChargedPartyIdentification),
	offsetof(struct ChargedPartyIdentification, _asn_ctx),
	asn_MAP_ChargedPartyIdentification_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	1,	/* Start extensions */
	3	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_ChargedPartyIdentification = {
	"ChargedPartyIdentification",
	"ChargedPartyIdentification",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_ChargedPartyIdentification_tags_1,
	sizeof(asn_DEF_ChargedPartyIdentification_tags_1)
		/sizeof(asn_DEF_ChargedPartyIdentification_tags_1[0]) - 1, /* 1 */
	asn_DEF_ChargedPartyIdentification_tags_1,	/* Same as above */
	sizeof(asn_DEF_ChargedPartyIdentification_tags_1)
		/sizeof(asn_DEF_ChargedPartyIdentification_tags_1[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_ChargedPartyIdentification_1,
	2,	/* Elements count */
	&asn_SPC_ChargedPartyIdentification_specs_1	/* Additional specs */
};

