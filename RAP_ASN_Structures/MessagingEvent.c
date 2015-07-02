/*
 * Generated by asn1c-0.9.26 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0312"
 * 	found in "TAP-0312"
 */

#include "MessagingEvent.h"

static asn_TYPE_member_t asn_MBR_MessagingEvent_1[] = {
	{ ATF_POINTER, 17, offsetof(struct MessagingEvent, messagingEventService),
		(ASN_TAG_CLASS_APPLICATION | (439 << 2)),
		0,
		&asn_DEF_MessagingEventService,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"messagingEventService"
		},
	{ ATF_POINTER, 16, offsetof(struct MessagingEvent, chargedParty),
		(ASN_TAG_CLASS_APPLICATION | (436 << 2)),
		0,
		&asn_DEF_ChargedParty,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"chargedParty"
		},
	{ ATF_POINTER, 15, offsetof(struct MessagingEvent, rapFileSequenceNumber),
		(ASN_TAG_CLASS_APPLICATION | (181 << 2)),
		0,
		&asn_DEF_RapFileSequenceNumber,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"rapFileSequenceNumber"
		},
	{ ATF_POINTER, 14, offsetof(struct MessagingEvent, simToolkitIndicator),
		(ASN_TAG_CLASS_APPLICATION | (200 << 2)),
		0,
		&asn_DEF_SimToolkitIndicator,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"simToolkitIndicator"
		},
	{ ATF_POINTER, 13, offsetof(struct MessagingEvent, geographicalLocation),
		(ASN_TAG_CLASS_APPLICATION | (113 << 2)),
		0,
		&asn_DEF_GeographicalLocation,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"geographicalLocation"
		},
	{ ATF_POINTER, 12, offsetof(struct MessagingEvent, eventReference),
		(ASN_TAG_CLASS_APPLICATION | (435 << 2)),
		0,
		&asn_DEF_EventReference,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"eventReference"
		},
	{ ATF_POINTER, 11, offsetof(struct MessagingEvent, recEntityCodeList),
		(ASN_TAG_CLASS_APPLICATION | (185 << 2)),
		0,
		&asn_DEF_RecEntityCodeList,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"recEntityCodeList"
		},
	{ ATF_POINTER, 10, offsetof(struct MessagingEvent, networkElementList),
		(ASN_TAG_CLASS_APPLICATION | (442 << 2)),
		0,
		&asn_DEF_NetworkElementList,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"networkElementList"
		},
	{ ATF_POINTER, 9, offsetof(struct MessagingEvent, locationArea),
		(ASN_TAG_CLASS_APPLICATION | (136 << 2)),
		0,
		&asn_DEF_LocationArea,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"locationArea"
		},
	{ ATF_POINTER, 8, offsetof(struct MessagingEvent, cellId),
		(ASN_TAG_CLASS_APPLICATION | (59 << 2)),
		0,
		&asn_DEF_CellId,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"cellId"
		},
	{ ATF_POINTER, 7, offsetof(struct MessagingEvent, serviceStartTimestamp),
		(ASN_TAG_CLASS_APPLICATION | (447 << 2)),
		0,
		&asn_DEF_ServiceStartTimestamp,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"serviceStartTimestamp"
		},
	{ ATF_POINTER, 6, offsetof(struct MessagingEvent, nonChargedParty),
		(ASN_TAG_CLASS_APPLICATION | (443 << 2)),
		0,
		&asn_DEF_NonChargedParty,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"nonChargedParty"
		},
	{ ATF_POINTER, 5, offsetof(struct MessagingEvent, exchangeRateCode),
		(ASN_TAG_CLASS_APPLICATION | (105 << 2)),
		0,
		&asn_DEF_ExchangeRateCode,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"exchangeRateCode"
		},
	{ ATF_POINTER, 4, offsetof(struct MessagingEvent, callTypeGroup),
		(ASN_TAG_CLASS_APPLICATION | (258 << 2)),
		0,
		&asn_DEF_CallTypeGroup,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"callTypeGroup"
		},
	{ ATF_POINTER, 3, offsetof(struct MessagingEvent, charge),
		(ASN_TAG_CLASS_APPLICATION | (62 << 2)),
		0,
		&asn_DEF_Charge,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"charge"
		},
	{ ATF_POINTER, 2, offsetof(struct MessagingEvent, taxInformationList),
		(ASN_TAG_CLASS_APPLICATION | (214 << 2)),
		0,
		&asn_DEF_TaxInformationList,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"taxInformationList"
		},
	{ ATF_POINTER, 1, offsetof(struct MessagingEvent, operatorSpecInformation),
		(ASN_TAG_CLASS_APPLICATION | (162 << 2)),
		0,
		&asn_DEF_OperatorSpecInfoList,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"operatorSpecInformation"
		},
};
static ber_tlv_tag_t asn_DEF_MessagingEvent_tags_1[] = {
	(ASN_TAG_CLASS_APPLICATION | (433 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_MessagingEvent_tag2el_1[] = {
    { (ASN_TAG_CLASS_APPLICATION | (59 << 2)), 9, 0, 0 }, /* cellId */
    { (ASN_TAG_CLASS_APPLICATION | (62 << 2)), 14, 0, 0 }, /* charge */
    { (ASN_TAG_CLASS_APPLICATION | (105 << 2)), 12, 0, 0 }, /* exchangeRateCode */
    { (ASN_TAG_CLASS_APPLICATION | (113 << 2)), 4, 0, 0 }, /* geographicalLocation */
    { (ASN_TAG_CLASS_APPLICATION | (136 << 2)), 8, 0, 0 }, /* locationArea */
    { (ASN_TAG_CLASS_APPLICATION | (162 << 2)), 16, 0, 0 }, /* operatorSpecInformation */
    { (ASN_TAG_CLASS_APPLICATION | (181 << 2)), 2, 0, 0 }, /* rapFileSequenceNumber */
    { (ASN_TAG_CLASS_APPLICATION | (185 << 2)), 6, 0, 0 }, /* recEntityCodeList */
    { (ASN_TAG_CLASS_APPLICATION | (200 << 2)), 3, 0, 0 }, /* simToolkitIndicator */
    { (ASN_TAG_CLASS_APPLICATION | (214 << 2)), 15, 0, 0 }, /* taxInformationList */
    { (ASN_TAG_CLASS_APPLICATION | (258 << 2)), 13, 0, 0 }, /* callTypeGroup */
    { (ASN_TAG_CLASS_APPLICATION | (435 << 2)), 5, 0, 0 }, /* eventReference */
    { (ASN_TAG_CLASS_APPLICATION | (436 << 2)), 1, 0, 0 }, /* chargedParty */
    { (ASN_TAG_CLASS_APPLICATION | (439 << 2)), 0, 0, 0 }, /* messagingEventService */
    { (ASN_TAG_CLASS_APPLICATION | (442 << 2)), 7, 0, 0 }, /* networkElementList */
    { (ASN_TAG_CLASS_APPLICATION | (443 << 2)), 11, 0, 0 }, /* nonChargedParty */
    { (ASN_TAG_CLASS_APPLICATION | (447 << 2)), 10, 0, 0 } /* serviceStartTimestamp */
};
static asn_SEQUENCE_specifics_t asn_SPC_MessagingEvent_specs_1 = {
	sizeof(struct MessagingEvent),
	offsetof(struct MessagingEvent, _asn_ctx),
	asn_MAP_MessagingEvent_tag2el_1,
	17,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	16,	/* Start extensions */
	18	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_MessagingEvent = {
	"MessagingEvent",
	"MessagingEvent",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_MessagingEvent_tags_1,
	sizeof(asn_DEF_MessagingEvent_tags_1)
		/sizeof(asn_DEF_MessagingEvent_tags_1[0]) - 1, /* 1 */
	asn_DEF_MessagingEvent_tags_1,	/* Same as above */
	sizeof(asn_DEF_MessagingEvent_tags_1)
		/sizeof(asn_DEF_MessagingEvent_tags_1[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_MessagingEvent_1,
	17,	/* Elements count */
	&asn_SPC_MessagingEvent_specs_1	/* Additional specs */
};

