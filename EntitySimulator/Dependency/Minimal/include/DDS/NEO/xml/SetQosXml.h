#include <core.h>
#include <cpsdcps.h>
#include <dcps_func.h>
#include <time.h>

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>

#pragma warning(disable:4996)

#define MAX_STR_LEN 4000
#define MAX_QOS_LEN 32
 
#define STR_USER_DATA
#define STR_TOPIC_DATA
#define STR_GROUP_DATA
#define STR_DURABILITY
#define STR_DURABILITY_SERVICE
#define STR_PRESENTATION
#define STR_DEADLINE
#define STR_LATENCY_BUDGET
#define STR_OWNERSHIP
#define STR_OWNERSHIP_STRENGTH
#define STR_LIVELINESS
#define STR_TIME_BASED_FILTER
#define STR_PARTITION
#define STR_RELIABILITY
#define STR_TRANSPORT_PRIORITY
#define STR_LIFESPAN
#define STR_DESTINATION_ORDER
#define STR_HISTORY
#define STR_RESOURCE_LIMITS
#define STR_ENTITY_FACTORY
#define STR_WRITER_DATA_LIFECYCLE
#define STR_READER_DATA_LIFECYCLE

#define STR_VALUE "value"
#define STR_KIND "kind"
#define STR_SEC "sec"
#define STR_NANOSEC "nanosec"

// ReliabilityQosPolicyKind
#define STR_BEST_EFFORT_RELIABILITY_QOS "BEST_EFFORT_RELIABILITY_QOS"
#define STR_RELIABLE_RELIABILITY_QOS "RELIABLE_RELIABILITY_QOS"

// DurabilityQosPolicyKind
#define STR_VOLATILE_DURABILITY_QOS "VOLATILE_DURABILITY_QOS"
#define STR_TRANSIENT_LOCAL_DURABILITY_QOS "TRANSIENT_LOCAL_DURABILITY_QOS"
#define STR_TRANSIENT_DURABILITY_QOS "TRANSIENT_DURABILITY_QOS"
#define STR_PERSISTENT_DURABILITY_QOS "PERSISTENT_DURABILITY_QOS"

// HistoryQosPolicyKind
#define STR_KEEP_LAST_HISTORY_QOS "KEEP_LAST_HISTORY_QOS"
#define STR_KEEP_ALL_HISTORY_QOS "KEEP_ALL_HISTORY_QOS"

// OwnershipQosPolicyKind
#define STR_SHARED_OWNERSHIP_QOS "SHARED_OWNERSHIP_QOS"
#define STR_EXCLUSIVE_OWNERSHIP_QOS "EXCLUSIVE_OWNERSHIP_QOS"

// LivelinessQosPolicyKind
#define STR_AUTOMATIC_LIVELINESS_QOS "AUTOMATIC_LIVELINESS_QOS"
#define STR_MANUAL_BY_PARTICIPANT_LIVELINESS_QOS "MANUAL_BY_PARTICIPANT_LIVELINESS_QOS"
#define STR_MANUAL_BY_TOPIC_LIVELINESS_QOS "MANUAL_BY_TOPIC_LIVELINESS_QOS"

// DestinationOrderQosPolicyKind
#define STR_BY_RECEPTION_TIMESTAMP_DESTINATIONORDER_QOS "BY_RECEPTION_TIMESTAMP_DESTINATIONORDER_QOS"
#define STR_BY_SOURCE_TIMESTAMP_DESTINATIONORDER_QOS "BY_SOURCE_TIMESTAMP_DESTINATIONORDER_QOS"

// HistoryQosPolicyKind
#define STR_KEEP_LAST_HISTORY_QOS "KEEP_LAST_HISTORY_QOS"
#define STR_KEEP_ALL_HISTORY_QOS "KEEP_ALL_HISTORY_QOS"

#define STR_TRUE "true"
#define STR_FALSE "false"

#define STR_DEFAULTXMLFILE "USER_QOS_PROFILES.xml"

enum QOS_TYPE
{
	DATAWRITER = 1,
	DATAREADER,
	PARTICIPANT
};

typedef int32_t ReturnXmlCode_t;

// ----------------------------------------------------------------------
// Return codes
// ----------------------------------------------------------------------
enum RETURNXMLCODE_T
{
	RETXMLCODE_OK = 0,
	RETXMLCODE_NOFILE,
	RETXMLCODE_FAILEDPARSING,
	RETXMLCODE_UNSUPPORTED,
	RETXMLCODE_NOFINDED,
};

#ifdef __cplusplus
extern "C" {
#endif
	char* trim(char *s);
	void xmlTrace(const char* filename, int line, const char* lpszFormat, ...);
	//ReturnXmlCode_t Set_qos_xml(char* qos_library, char* qos_profile, void* qos, int qos_type);
	ReturnXmlCode_t Set_qos_xml(char* qos_library, char* qos_profile, void* qos, int qos_type, char* xmlfile);
	ReturnXmlCode_t select_library(xmlDocPtr doc, xmlNodePtr cur, char* qos_library, char* qos_profile, void* qos, int qos_type);
	ReturnXmlCode_t select_profile(xmlDocPtr doc, xmlNodePtr cur, char* qos_profile, void* qos, int qos_type);
	ReturnXmlCode_t select_type(xmlDocPtr doc, xmlNodePtr cur, void* qos, int qos_type);
	ReturnXmlCode_t set_datawriter(xmlDocPtr doc, xmlNodePtr cur, void* qos, int qos_type);
	ReturnXmlCode_t set_datareader(xmlDocPtr doc, xmlNodePtr cur, void* qos, int qos_type);
	ReturnXmlCode_t set_participant(xmlDocPtr doc, xmlNodePtr cur, void* qos, int qos_type);

	// qos ¼³Á¤
	ReturnXmlCode_t	set_qos_user_data(xmlDocPtr doc, xmlNodePtr cur, void* qos, int qos_type);
	ReturnXmlCode_t	set_qos_topic_data(xmlDocPtr doc, xmlNodePtr cur, void* qos, int qos_type);
	ReturnXmlCode_t	set_qos_group_data(xmlDocPtr doc, xmlNodePtr cur, void* qos, int qos_type);
	ReturnXmlCode_t	set_qos_durability(xmlDocPtr doc, xmlNodePtr cur, void* qos, int qos_type);
	ReturnXmlCode_t	set_qos_durability_service(xmlDocPtr doc, xmlNodePtr cur, void* qos, int qos_type);
	ReturnXmlCode_t	set_qos_presentation(xmlDocPtr doc, xmlNodePtr cur, void* qos, int qos_type);
	ReturnXmlCode_t	set_qos_deadline(xmlDocPtr doc, xmlNodePtr cur, void* qos, int qos_type);
	ReturnXmlCode_t	set_qos_latency_budget(xmlDocPtr doc, xmlNodePtr cur, void* qos, int qos_type);
	ReturnXmlCode_t	set_qos_ownership(xmlDocPtr doc, xmlNodePtr cur, void* qos, int qos_type);
	ReturnXmlCode_t	set_qos_ownership_strength(xmlDocPtr doc, xmlNodePtr cur, void* qos, int qos_type);
	ReturnXmlCode_t	set_qos_liveliness(xmlDocPtr doc, xmlNodePtr cur, void* qos, int qos_type);
	ReturnXmlCode_t	set_qos_time_based_filter(xmlDocPtr doc, xmlNodePtr cur, void* qos, int qos_type);
	ReturnXmlCode_t	set_qos_partition(xmlDocPtr doc, xmlNodePtr cur, void* qos, int qos_type);
	ReturnXmlCode_t	set_qos_reliability(xmlDocPtr doc, xmlNodePtr cur, void* qos, int qos_type);
	ReturnXmlCode_t	set_qos_transport_priority(xmlDocPtr doc, xmlNodePtr cur, void* qos, int qos_type);
	ReturnXmlCode_t	set_qos_lifespan(xmlDocPtr doc, xmlNodePtr cur, void* qos, int qos_type);
	ReturnXmlCode_t	set_qos_destination_order(xmlDocPtr doc, xmlNodePtr cur, void* qos, int qos_type);
	ReturnXmlCode_t	set_qos_history(xmlDocPtr doc, xmlNodePtr cur, void* qos, int qos_type);
	ReturnXmlCode_t	set_qos_resource_limits(xmlDocPtr doc, xmlNodePtr cur, void* qos, int qos_type);
	ReturnXmlCode_t	set_qos_entity_factory(xmlDocPtr doc, xmlNodePtr cur, void* qos, int qos_type);
	ReturnXmlCode_t	set_qos_writer_data_lifecycle(xmlDocPtr doc, xmlNodePtr cur, void* qos, int qos_type);
	ReturnXmlCode_t	set_qos_reader_data_lifecycle(xmlDocPtr doc, xmlNodePtr cur, void* qos, int qos_type);

	ReturnXmlCode_t	set_duration_t(xmlDocPtr doc, xmlNodePtr cur, Duration_t* duration);
#ifdef __cplusplus
}
#endif