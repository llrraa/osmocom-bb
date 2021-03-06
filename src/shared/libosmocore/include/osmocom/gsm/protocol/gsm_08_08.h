/* From GSM08.08 */

#ifndef GSM_0808_H
#define GSM_0808_H

#include <stdlib.h>

/*
 * this is from GSM 03.03 CGI but is copied in GSM 08.08
 * in § 3.2.2.27 for Cell Identifier List
 */
enum CELL_IDENT {
	CELL_IDENT_WHOLE_GLOBAL		= 0,
	CELL_IDENT_LAC_AND_CI		= 1,
	CELL_IDENT_CI			= 2,
	CELL_IDENT_NO_CELL		= 3,
	CELL_IDENT_LAI_AND_LAC		= 4,
	CELL_IDENT_LAC			= 5,
	CELL_IDENT_BSS			= 6,
	CELL_IDENT_UTRAN_PLMN_LAC_RNC	= 8,
	CELL_IDENT_UTRAN_RNC		= 9,
	CELL_IDENT_UTRAN_LAC_RNC	= 10,
};


/* GSM 08.06 § 6.3 */
enum BSSAP_MSG_TYPE {
	BSSAP_MSG_BSS_MANAGEMENT    = 0x0,
	BSSAP_MSG_DTAP		    = 0x1,
};

struct bssmap_header {
	uint8_t type;
	uint8_t length;
} __attribute__((packed));

struct dtap_header {
	uint8_t type;
	uint8_t link_id;
	uint8_t length;
} __attribute__((packed));


enum BSS_MAP_MSG_TYPE {
	BSS_MAP_MSG_RESERVED_0		= 0,

	/* ASSIGNMENT MESSAGES */
	BSS_MAP_MSG_ASSIGMENT_RQST	= 1,
	BSS_MAP_MSG_ASSIGMENT_COMPLETE	= 2,
	BSS_MAP_MSG_ASSIGMENT_FAILURE	= 3,

	/*  HANDOVER MESSAGES */
	BSS_MAP_MSG_HANDOVER_RQST		= 16,
	BSS_MAP_MSG_HANDOVER_REQUIRED		= 17,
	BSS_MAP_MSG_HANDOVER_RQST_ACKNOWLEDGE= 18,
	BSS_MAP_MSG_HANDOVER_CMD		= 19,
	BSS_MAP_MSG_HANDOVER_COMPLETE		= 20,
	BSS_MAP_MSG_HANDOVER_SUCCEEDED		= 21,
	BSS_MAP_MSG_HANDOVER_FAILURE		= 22,
	BSS_MAP_MSG_HANDOVER_PERFORMED		= 23,
	BSS_MAP_MSG_HANDOVER_CANDIDATE_ENQUIRE	= 24,
	BSS_MAP_MSG_HANDOVER_CANDIDATE_RESPONSE	= 25,
	BSS_MAP_MSG_HANDOVER_REQUIRED_REJECT	= 26,
	BSS_MAP_MSG_HANDOVER_DETECT		= 27,

	/* RELEASE MESSAGES */
	BSS_MAP_MSG_CLEAR_CMD		= 32,
	BSS_MAP_MSG_CLEAR_COMPLETE		= 33,
	BSS_MAP_MSG_CLEAR_RQST		= 34,
	BSS_MAP_MSG_RESERVED_1			= 35,
	BSS_MAP_MSG_RESERVED_2			= 36,
	BSS_MAP_MSG_SAPI_N_REJECT		= 37,
	BSS_MAP_MSG_CONFUSION			= 38,

	/* OTHER CONNECTION RELATED MESSAGES */
	BSS_MAP_MSG_SUSPEND			= 40,
	BSS_MAP_MSG_RESUME			= 41,
	BSS_MAP_MSG_CONNECTION_ORIENTED_INFORMATION = 42,
	BSS_MAP_MSG_PERFORM_LOCATION_RQST	= 43,
	BSS_MAP_MSG_LSA_INFORMATION		= 44,
	BSS_MAP_MSG_PERFORM_LOCATION_RESPONSE	= 45,
	BSS_MAP_MSG_PERFORM_LOCATION_ABORT	= 46,
	BSS_MAP_MSG_COMMON_ID			= 47,

	/* GENERAL MESSAGES */
	BSS_MAP_MSG_RESET			= 48,
	BSS_MAP_MSG_RESET_ACKNOWLEDGE		= 49,
	BSS_MAP_MSG_OVERLOAD			= 50,
	BSS_MAP_MSG_RESERVED_3			= 51,
	BSS_MAP_MSG_RESET_CIRCUIT		= 52,
	BSS_MAP_MSG_RESET_CIRCUIT_ACKNOWLEDGE	= 53,
	BSS_MAP_MSG_MSC_INVOKE_TRACE		= 54,
	BSS_MAP_MSG_BSS_INVOKE_TRACE		= 55,
	BSS_MAP_MSG_CONNECTIONLESS_INFORMATION	= 58,

	/* TERRESTRIAL RESOURCE MESSAGES */
	BSS_MAP_MSG_BLOCK			= 64,
	BSS_MAP_MSG_BLOCKING_ACKNOWLEDGE	= 65,
	BSS_MAP_MSG_UNBLOCK			= 66,
	BSS_MAP_MSG_UNBLOCKING_ACKNOWLEDGE	= 67,
	BSS_MAP_MSG_CIRCUIT_GROUP_BLOCK		= 68,
	BSS_MAP_MSG_CIRCUIT_GROUP_BLOCKING_ACKNOWLEDGE	= 69,
	BSS_MAP_MSG_CIRCUIT_GROUP_UNBLOCK	= 70,
	BSS_MAP_MSG_CIRCUIT_GROUP_UNBLOCKING_ACKNOWLEDGE = 71,
	BSS_MAP_MSG_UNEQUIPPED_CIRCUIT		= 72,
	BSS_MAP_MSG_CHANGE_CIRCUIT		= 78,
	BSS_MAP_MSG_CHANGE_CIRCUIT_ACKNOWLEDGE	= 79,

	/* RADIO RESOURCE MESSAGES */
	BSS_MAP_MSG_RESOURCE_RQST		= 80,
	BSS_MAP_MSG_RESOURCE_INDICATION		= 81,
	BSS_MAP_MSG_PAGING			= 82,
	BSS_MAP_MSG_CIPHER_MODE_CMD		= 83,
	BSS_MAP_MSG_CLASSMARK_UPDATE		= 84,
	BSS_MAP_MSG_CIPHER_MODE_COMPLETE	= 85,
	BSS_MAP_MSG_QUEUING_INDICATION		= 86,
	BSS_MAP_MSG_COMPLETE_LAYER_3		= 87,
	BSS_MAP_MSG_CLASSMARK_RQST		= 88,
	BSS_MAP_MSG_CIPHER_MODE_REJECT		= 89,
	BSS_MAP_MSG_LOAD_INDICATION		= 90,

	/* VGCS/VBS */
	BSS_MAP_MSG_VGCS_VBS_SETUP		= 4,
	BSS_MAP_MSG_VGCS_VBS_SETUP_ACK		= 5,
	BSS_MAP_MSG_VGCS_VBS_SETUP_REFUSE	= 6,
	BSS_MAP_MSG_VGCS_VBS_ASSIGNMENT_RQST	= 7,
	BSS_MAP_MSG_VGCS_VBS_ASSIGNMENT_RESULT	= 28,
	BSS_MAP_MSG_VGCS_VBS_ASSIGNMENT_FAILURE	= 29,
	BSS_MAP_MSG_VGCS_VBS_QUEUING_INDICATION	= 30,
	BSS_MAP_MSG_UPLINK_RQST		= 31,
	BSS_MAP_MSG_UPLINK_RQST_ACKNOWLEDGE	= 39,
	BSS_MAP_MSG_UPLINK_RQST_CONFIRMATION	= 73,
	BSS_MAP_MSG_UPLINK_RELEASE_INDICATION	= 74,
	BSS_MAP_MSG_UPLINK_REJECT_CMD	= 75,
	BSS_MAP_MSG_UPLINK_RELEASE_CMD	= 76,
	BSS_MAP_MSG_UPLINK_SEIZED_CMD	= 77,
};

enum GSM0808_IE_CODING {
	GSM0808_IE_CIRCUIT_IDENTITY_CODE	= 1,
	GSM0808_IE_RESERVED_0			= 2,
	GSM0808_IE_RESOURCE_AVAILABLE		= 3,
	GSM0808_IE_CAUSE			= 4,
	GSM0808_IE_CELL_IDENTIFIER		= 5,
	GSM0808_IE_PRIORITY			= 6,
	GSM0808_IE_LAYER_3_HEADER_INFORMATION	= 7,
	GSM0808_IE_IMSI				= 8,
	GSM0808_IE_TMSI				= 9,
	GSM0808_IE_ENCRYPTION_INFORMATION	= 10,
	GSM0808_IE_CHANNEL_TYPE			= 11,
	GSM0808_IE_PERIODICITY			= 12,
	GSM0808_IE_EXTENDED_RESOURCE_INDICATOR	= 13,
	GSM0808_IE_NUMBER_OF_MSS		= 14,
	GSM0808_IE_RESERVED_1			= 15,
	GSM0808_IE_RESERVED_2			= 16,
	GSM0808_IE_RESERVED_3			= 17,
	GSM0808_IE_CLASSMARK_INFORMATION_T2	= 18,
	GSM0808_IE_CLASSMARK_INFORMATION_T3	= 19,
	GSM0808_IE_INTERFERENCE_BAND_TO_USE	= 20,
	GSM0808_IE_RR_CAUSE			= 21,
	GSM0808_IE_RESERVED_4			= 22,
	GSM0808_IE_LAYER_3_INFORMATION		= 23,
	GSM0808_IE_DLCI				= 24,
	GSM0808_IE_DOWNLINK_DTX_FLAG		= 25,
	GSM0808_IE_CELL_IDENTIFIER_LIST		= 26,
	GSM0808_IE_RESPONSE_RQST		= 27,
	GSM0808_IE_RESOURCE_INDICATION_METHOD	= 28,
	GSM0808_IE_CLASSMARK_INFORMATION_TYPE_1	= 29,
	GSM0808_IE_CIRCUIT_IDENTITY_CODE_LIST	= 30,
	GSM0808_IE_DIAGNOSTIC			= 31,
	GSM0808_IE_LAYER_3_MESSAGE_CONTENTS	= 32,
	GSM0808_IE_CHOSEN_CHANNEL		= 33,
	GSM0808_IE_TOTAL_RESOURCE_ACCESSIBLE	= 34,
	GSM0808_IE_CIPHER_RESPONSE_MODE		= 35,
	GSM0808_IE_CHANNEL_NEEDED		= 36,
	GSM0808_IE_TRACE_TYPE			= 37,
	GSM0808_IE_TRIGGERID			= 38,
	GSM0808_IE_TRACE_REFERENCE		= 39,
	GSM0808_IE_TRANSACTIONID		= 40,
	GSM0808_IE_MOBILE_IDENTITY		= 41,
	GSM0808_IE_OMCID			= 42,
	GSM0808_IE_FORWARD_INDICATOR		= 43,
	GSM0808_IE_CHOSEN_ENCR_ALG		= 44,
	GSM0808_IE_CIRCUIT_POOL			= 45,
	GSM0808_IE_CIRCUIT_POOL_LIST		= 46,
	GSM0808_IE_TIME_INDICATION		= 47,
	GSM0808_IE_RESOURCE_SITUATION		= 48,
	GSM0808_IE_CURRENT_CHANNEL_TYPE_1	= 49,
	GSM0808_IE_QUEUEING_INDICATOR		= 50,
	GSM0808_IE_SPEECH_VERSION		= 64,
	GSM0808_IE_ASSIGNMENT_REQUIREMENT	= 51,
	GSM0808_IE_TALKER_FLAG			= 53,
	GSM0808_IE_CONNECTION_RELEASE_RQSTED	= 54,
	GSM0808_IE_GROUP_CALL_REFERENCE		= 55,
	GSM0808_IE_EMLPP_PRIORITY		= 56,
	GSM0808_IE_CONFIG_EVO_INDI		= 57,
	GSM0808_IE_OLD_BSS_TO_NEW_BSS_INFORMATION	= 58,
	GSM0808_IE_LSA_IDENTIFIER		= 59,
	GSM0808_IE_LSA_IDENTIFIER_LIST		= 60,
	GSM0808_IE_LSA_INFORMATION		= 61,
	GSM0808_IE_LCS_QOS			= 62,
	GSM0808_IE_LSA_ACCESS_CTRL_SUPPR	= 63,
	GSM0808_IE_LCS_PRIORITY			= 67,
	GSM0808_IE_LOCATION_TYPE		= 68,
	GSM0808_IE_LOCATION_ESTIMATE		= 69,
	GSM0808_IE_POSITIONING_DATA		= 70,
	GSM0808_IE_LCS_CAUSE			= 71,
	GSM0808_IE_LCS_CLIENT_TYPE		= 72,
	GSM0808_IE_APDU				= 73,
	GSM0808_IE_NETWORK_ELEMENT_IDENTITY	= 74,
	GSM0808_IE_GPS_ASSISTANCE_DATA		= 75,
	GSM0808_IE_DECIPHERING_KEYS		= 76,
	GSM0808_IE_RETURN_ERROR_RQST		= 77,
	GSM0808_IE_RETURN_ERROR_CAUSE		= 78,
	GSM0808_IE_SEGMENTATION			= 79,
	GSM0808_IE_SERVICE_HANDOVER		= 80,
	GSM0808_IE_SOURCE_RNC_TO_TARGET_RNC_TRANSPARENT_UMTS	= 81,
	GSM0808_IE_SOURCE_RNC_TO_TARGET_RNC_TRANSPARENT_CDMA2000= 82,
	GSM0808_IE_RESERVED_5			= 65,
	GSM0808_IE_RESERVED_6			= 66,
};

enum gsm0808_cause {
	GSM0808_CAUSE_RADIO_INTERFACE_MESSAGE_FAILURE			= 0,
	GSM0808_CAUSE_RADIO_INTERFACE_FAILURE				= 1,
	GSM0808_CAUSE_UPLINK_QUALITY					= 2,
	GSM0808_CAUSE_UPLINK_STRENGTH					= 3,
	GSM0808_CAUSE_DOWNLINK_QUALITY					= 4,
	GSM0808_CAUSE_DOWNLINK_STRENGTH					= 5,
	GSM0808_CAUSE_DISTANCE						= 6,
	GSM0808_CAUSE_O_AND_M_INTERVENTION				= 7,
	GSM0808_CAUSE_RESPONSE_TO_MSC_INVOCATION			= 8,
	GSM0808_CAUSE_CALL_CONTROL					= 9,
	GSM0808_CAUSE_RADIO_INTERFACE_FAILURE_REVERSION			= 10,
	GSM0808_CAUSE_HANDOVER_SUCCESSFUL				= 11,
	GSM0808_CAUSE_BETTER_CELL					= 12,
	GSM0808_CAUSE_DIRECTED_RETRY					= 13,
	GSM0808_CAUSE_JOINED_GROUP_CALL_CHANNEL				= 14,
	GSM0808_CAUSE_TRAFFIC						= 15,
	GSM0808_CAUSE_EQUIPMENT_FAILURE					= 32,
	GSM0808_CAUSE_NO_RADIO_RESOURCE_AVAILABLE			= 33,
	GSM0808_CAUSE_RQSTED_TERRESTRIAL_RESOURCE_UNAVAILABLE	= 34,
	GSM0808_CAUSE_CCCH_OVERLOAD					= 35,
	GSM0808_CAUSE_PROCESSOR_OVERLOAD				= 36,
	GSM0808_CAUSE_BSS_NOT_EQUIPPED					= 37,
	GSM0808_CAUSE_MS_NOT_EQUIPPED					= 38,
	GSM0808_CAUSE_INVALID_CELL					= 39,
	GSM0808_CAUSE_TRAFFIC_LOAD					= 40,
	GSM0808_CAUSE_PREEMPTION					= 41,
	GSM0808_CAUSE_RQSTED_TRANSCODING_RATE_ADAPTION_UNAVAILABLE	= 48,
	GSM0808_CAUSE_CIRCUIT_POOL_MISMATCH				= 49,
	GSM0808_CAUSE_SWITCH_CIRCUIT_POOL				= 50,
	GSM0808_CAUSE_RQSTED_SPEECH_VERSION_UNAVAILABLE		= 51,
	GSM0808_CAUSE_LSA_NOT_ALLOWED					= 52,
	GSM0808_CAUSE_CIPHERING_ALGORITHM_NOT_SUPPORTED			= 64,
	GSM0808_CAUSE_TERRESTRIAL_CIRCUIT_ALREADY_ALLOCATED		= 80,
	GSM0808_CAUSE_INVALID_MESSAGE_CONTENTS				= 81,
	GSM0808_CAUSE_INFORMATION_ELEMENT_OR_FIELD_MISSING		= 82,
	GSM0808_CAUSE_INCORRECT_VALUE					= 83,
	GSM0808_CAUSE_UNKNOWN_MESSAGE_TYPE				= 84,
	GSM0808_CAUSE_UNKNOWN_INFORMATION_ELEMENT			= 85,
	GSM0808_CAUSE_PROTOCOL_ERROR_BETWEEN_BSS_AND_MSC		= 96,
};

/* GSM 08.08 3.2.2.11 Channel Type */
enum gsm0808_chan_indicator {
	GSM0808_CHAN_SPEECH = 1,
	GSM0808_CHAN_DATA   = 2,
	GSM0808_CHAN_SIGN   = 3,
};

enum gsm0808_chan_rate_type_data {
	GSM0808_DATA_FULL_BM	= 0x8,
	GSM0808_DATA_HALF_LM	= 0x9,
	GSM0808_DATA_FULL_RPREF	= 0xa,
	GSM0808_DATA_HALF_PREF	= 0xb,
	GSM0808_DATA_FULL_PREF_NO_CHANGE	= 0x1a,
	GSM0808_DATA_HALF_PREF_NO_CHANGE	= 0x1b,
	GSM0808_DATA_MULTI_MASK	= 0x20,
	GSM0808_DATA_MULTI_MASK_NO_CHANGE	= 0x30,
};

enum gsm0808_chan_rate_type_speech {
	GSM0808_SPEECH_FULL_BM	= 0x8,
	GSM0808_SPEECH_HALF_LM	= 0x9,
	GSM0808_SPEECH_FULL_PREF= 0xa,
	GSM0808_SPEECH_HALF_PREF= 0xb,
	GSM0808_SPEECH_FULL_PREF_NO_CHANGE	= 0x1a,
	GSM0808_SPEECH_HALF_PREF_NO_CHANGE	= 0x1b,
	GSM0808_SPEECH_PERM	= 0xf,
	GSM0808_SPEECH_PERM_NO_CHANGE = 0x1f,
};

enum gsm0808_permitted_speech {
	GSM0808_PERM_FR1	= 0x01,
	GSM0808_PERM_FR2	= 0x11,
	GSM0808_PERM_FR3	= 0x21,
	GSM0808_PERM_HR1	= GSM0808_PERM_FR1 | 0x4,
	GSM0808_PERM_HR2	= GSM0808_PERM_FR2 | 0x4,
	GSM0808_PERM_HR3	= GSM0808_PERM_FR3 | 0x4,
};

#endif
