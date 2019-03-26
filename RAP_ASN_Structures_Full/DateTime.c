/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP-0312"
 */

#include "DateTime.h"

static asn_TYPE_member_t asn_MBR_DateTime_1[] = {
	{ ATF_POINTER, 2, offsetof(struct DateTime, localTimeStamp),
		(ASN_TAG_CLASS_APPLICATION | (16 << 2)),
		0,
		&asn_DEF_LocalTimeStamp,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"localTimeStamp"
		},
	{ ATF_POINTER, 1, offsetof(struct DateTime, utcTimeOffsetCode),
		(ASN_TAG_CLASS_APPLICATION | (232 << 2)),
		0,
		&asn_DEF_UtcTimeOffsetCode,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"utcTimeOffsetCode"
		},
};
static ber_tlv_tag_t asn_DEF_DateTime_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_DateTime_tag2el_1[] = {
    { (ASN_TAG_CLASS_APPLICATION | (16 << 2)), 0, 0, 0 }, /* localTimeStamp */
    { (ASN_TAG_CLASS_APPLICATION | (232 << 2)), 1, 0, 0 } /* utcTimeOffsetCode */
};
static asn_SEQUENCE_specifics_t asn_SPC_DateTime_specs_1 = {
	sizeof(struct DateTime),
	offsetof(struct DateTime, _asn_ctx),
	asn_MAP_DateTime_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	1,	/* Start extensions */
	3	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_DateTime = {
	"DateTime",
	"DateTime",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_DateTime_tags_1,
	sizeof(asn_DEF_DateTime_tags_1)
		/sizeof(asn_DEF_DateTime_tags_1[0]), /* 1 */
	asn_DEF_DateTime_tags_1,	/* Same as above */
	sizeof(asn_DEF_DateTime_tags_1)
		/sizeof(asn_DEF_DateTime_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_DateTime_1,
	2,	/* Elements count */
	&asn_SPC_DateTime_specs_1	/* Additional specs */
};

