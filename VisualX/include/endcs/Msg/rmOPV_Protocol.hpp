#include <core.h>
#include <cpsdcps.h>
#include <dcps_func.h>
#if defined(_MSC_VER)
#define STRUCT_ALIGNED_(x) struct __declspec(align(x))
#elif defined(__GNUC__)
#define STRUCT_ALIGNED_(x) struct __attribute__ ((aligned(x)))
#else
#define STRUCT_ALIGNED_(x) struct
#endif

typedef STRUCT_ALIGNED_(1) ST_POSITION {
	double dLon;
	double dLat;
	double dAlt;
} ST_POSITION;

class ST_POSITIONTypeSupport
{
public:
	FooTypeSupport	*fooTS;
public:
	void register_topic_type(DomainParticipant *p_Participant)
	{
		if(p_Participant == NULL) return;
		{
			fooTS = get_new_foo_type_support();
			insert_topic_parameters(fooTS);
			fooTS->i_size = sizeof(struct ST_POSITION);
			fooTS->register_type(fooTS, p_Participant, "ST_POSITION");
		}
	}
	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{dds_parameter_t *p_para = get_new_parameter("dLon", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("dLat", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("dAlt", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
	}
};

typedef STRUCT_ALIGNED_(1) ST_ENTITY_STATE {
	ST_POSITION stPosition;
	double dSpeed;
	double dCourse;
	double dHeading;
	double dRoll;
	double dPitch;
	double dHealthPoint;
	int16_t bDestroyed;
	int16_t Reserved_1;
	int16_t Reserved_2;
} ST_ENTITY_STATE;

class ST_ENTITY_STATETypeSupport
{
public:
	FooTypeSupport	*fooTS;
public:
	void register_topic_type(DomainParticipant *p_Participant)
	{
		if(p_Participant == NULL) return;
		{
			fooTS = get_new_foo_type_support();
			insert_topic_parameters(fooTS);
			fooTS->i_size = sizeof(struct ST_ENTITY_STATE);
			fooTS->register_type(fooTS, p_Participant, "ST_ENTITY_STATE");
		}
	}
	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{dds_parameter_t *p_para = get_new_parameter("stPosition", DDS_Struct, sizeof(ST_POSITION));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("dSpeed", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("dCourse", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("dHeading", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("dRoll", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("dPitch", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("dHealthPoint", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("bDestroyed", DDS_Int16, sizeof(int16_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("Reserved_1", DDS_Int16, sizeof(int16_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("Reserved_2", DDS_Int16, sizeof(int16_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
	}
};

typedef STRUCT_ALIGNED_(1) ST_ENTITY_INFO {
	int32_t ulType;
	char chESM_Name[5];
	int32_t ulPlatformClass;
	int32_t ulPlatformKind;
	int32_t ulPlatformMission;
	int32_t ulIdentity;
	int16_t nMode1;
	int16_t nMode2;
	int16_t nMode3A;
	int16_t nMode4;
	int16_t nWeaponClass;
	char chWeaponRadarInfo[5];
	double dWeaponRange;
	double dWeaponSpeed;
	int16_t nWeaponOperationType;
	int16_t nSensorClass;
	int16_t nSensorThreatLevel;
	char chSensorInfo[5];
	double dSensorFreqency;
	double dSensorScanRate;
	double dSensorScanType;
	double dSensorAmplitude;
} ST_ENTITY_INFO;

class ST_ENTITY_INFOTypeSupport
{
public:
	FooTypeSupport	*fooTS;
public:
	void register_topic_type(DomainParticipant *p_Participant)
	{
		if(p_Participant == NULL) return;
		{
			fooTS = get_new_foo_type_support();
			insert_topic_parameters(fooTS);
			fooTS->i_size = sizeof(struct ST_ENTITY_INFO);
			fooTS->register_type(fooTS, p_Participant, "ST_ENTITY_INFO");
		}
	}
	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{dds_parameter_t *p_para = get_new_parameter("ulType", DDS_Int32, sizeof(int32_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("chESM_Name", DDS_Array_Char8, sizeof(char)*((5)));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("ulPlatformClass", DDS_Int32, sizeof(int32_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("ulPlatformKind", DDS_Int32, sizeof(int32_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("ulPlatformMission", DDS_Int32, sizeof(int32_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("ulIdentity", DDS_Int32, sizeof(int32_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("nMode1", DDS_Int16, sizeof(int16_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("nMode2", DDS_Int16, sizeof(int16_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("nMode3A", DDS_Int16, sizeof(int16_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("nMode4", DDS_Int16, sizeof(int16_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("nWeaponClass", DDS_Int16, sizeof(int16_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("chWeaponRadarInfo", DDS_Array_Char8, sizeof(char)*((5)));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("dWeaponRange", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("dWeaponSpeed", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("nWeaponOperationType", DDS_Int16, sizeof(int16_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("nSensorClass", DDS_Int16, sizeof(int16_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("nSensorThreatLevel", DDS_Int16, sizeof(int16_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("chSensorInfo", DDS_Array_Char8, sizeof(char)*((5)));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("dSensorFreqency", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("dSensorScanRate", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("dSensorScanType", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("dSensorAmplitude", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
	}
};

typedef STRUCT_ALIGNED_(1) ST_ENTITY_ATTRIBUTE {
	double dTurnRate;
	double dRiseRate;
	double dMaxAltitude;
	double dMaxSpeed;
	double dMaxAcceleration;
	double dMaxHealthPoint;
	double dLength;
	double dWidth;
	double dHeight;
	double dWeight;
	int16_t Reserved;
} ST_ENTITY_ATTRIBUTE;

class ST_ENTITY_ATTRIBUTETypeSupport
{
public:
	FooTypeSupport	*fooTS;
public:
	void register_topic_type(DomainParticipant *p_Participant)
	{
		if(p_Participant == NULL) return;
		{
			fooTS = get_new_foo_type_support();
			insert_topic_parameters(fooTS);
			fooTS->i_size = sizeof(struct ST_ENTITY_ATTRIBUTE);
			fooTS->register_type(fooTS, p_Participant, "ST_ENTITY_ATTRIBUTE");
		}
	}
	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{dds_parameter_t *p_para = get_new_parameter("dTurnRate", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("dRiseRate", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("dMaxAltitude", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("dMaxSpeed", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("dMaxAcceleration", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("dMaxHealthPoint", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("dLength", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("dWidth", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("dHeight", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("dWeight", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("Reserved", DDS_Int16, sizeof(int16_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
	}
};

typedef STRUCT_ALIGNED_(1) ST_MISSILE_DATA {
	double nMissileType;
	double nMissileCategory;
	double dWeight;
	double dDamage;
	double dSpeed;
	double dTurnRate;
	double dSeekerAngle;
	double dSeekerRange;
} ST_MISSILE_DATA;

class ST_MISSILE_DATATypeSupport
{
public:
	FooTypeSupport	*fooTS;
public:
	void register_topic_type(DomainParticipant *p_Participant)
	{
		if(p_Participant == NULL) return;
		{
			fooTS = get_new_foo_type_support();
			insert_topic_parameters(fooTS);
			fooTS->i_size = sizeof(struct ST_MISSILE_DATA);
			fooTS->register_type(fooTS, p_Participant, "ST_MISSILE_DATA");
		}
	}
	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{dds_parameter_t *p_para = get_new_parameter("nMissileType", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("nMissileCategory", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("dWeight", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("dDamage", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("dSpeed", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("dTurnRate", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("dSeekerAngle", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("dSeekerRange", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
	}
};

typedef STRUCT_ALIGNED_(1) ST_AMMUNITION_DATA {
	int16_t nAmmunitionType;
	int16_t nAmmunitionCategory;
	double dWeight;
	double dMuzzleVelocity;
	int16_t nSimulatorManagementCommand;
} ST_AMMUNITION_DATA;

class ST_AMMUNITION_DATATypeSupport
{
public:
	FooTypeSupport	*fooTS;
public:
	void register_topic_type(DomainParticipant *p_Participant)
	{
		if(p_Participant == NULL) return;
		{
			fooTS = get_new_foo_type_support();
			insert_topic_parameters(fooTS);
			fooTS->i_size = sizeof(struct ST_AMMUNITION_DATA);
			fooTS->register_type(fooTS, p_Participant, "ST_AMMUNITION_DATA");
		}
	}
	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{dds_parameter_t *p_para = get_new_parameter("nAmmunitionType", DDS_Int16, sizeof(int16_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("nAmmunitionCategory", DDS_Int16, sizeof(int16_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("dWeight", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("dMuzzleVelocity", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("nSimulatorManagementCommand", DDS_Int16, sizeof(int16_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
	}
};

typedef STRUCT_ALIGNED_(1) SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK {
	int16_t nSimulatorID;
	int16_t nSimulatorManagementCommand;
} SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK;

class SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKTypeSupport
{
public:
	FooTypeSupport	*fooTS;
public:
	void register_topic_type(DomainParticipant *p_Participant)
	{
		if(p_Participant == NULL) return;
		{
			fooTS = get_new_foo_type_support();
			insert_topic_parameters(fooTS);
			fooTS->i_size = sizeof(struct SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK);
			fooTS->register_type(fooTS, p_Participant, "SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK");
		}
	}
	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{dds_parameter_t *p_para = get_new_parameter("nSimulatorID", DDS_Int16, sizeof(int16_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("nSimulatorManagementCommand", DDS_Int16, sizeof(int16_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
	}
};

typedef STRUCT_ALIGNED_(1) SIM_SC_SIMULATOR_STATUS_REPORT {
	int16_t nSimulatorID;
	int16_t nSimulatorStatus;
} SIM_SC_SIMULATOR_STATUS_REPORT;

class SIM_SC_SIMULATOR_STATUS_REPORTTypeSupport
{
public:
	FooTypeSupport	*fooTS;
public:
	void register_topic_type(DomainParticipant *p_Participant)
	{
		if(p_Participant == NULL) return;
		{
			fooTS = get_new_foo_type_support();
			insert_topic_parameters(fooTS);
			fooTS->i_size = sizeof(struct SIM_SC_SIMULATOR_STATUS_REPORT);
			fooTS->register_type(fooTS, p_Participant, "SIM_SC_SIMULATOR_STATUS_REPORT");
		}
	}
	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{dds_parameter_t *p_para = get_new_parameter("nSimulatorID", DDS_Int16, sizeof(int16_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("nSimulatorStatus", DDS_Int16, sizeof(int16_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
	}
};

typedef STRUCT_ALIGNED_(1) SC_SER_LINK_CONNECTION_COMMAND {
	int16_t nLinkConnectionCommand;
} SC_SER_LINK_CONNECTION_COMMAND;

class SC_SER_LINK_CONNECTION_COMMANDTypeSupport
{
public:
	FooTypeSupport	*fooTS;
public:
	void register_topic_type(DomainParticipant *p_Participant)
	{
		if(p_Participant == NULL) return;
		{
			fooTS = get_new_foo_type_support();
			insert_topic_parameters(fooTS);
			fooTS->i_size = sizeof(struct SC_SER_LINK_CONNECTION_COMMAND);
			fooTS->register_type(fooTS, p_Participant, "SC_SER_LINK_CONNECTION_COMMAND");
		}
	}
	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{dds_parameter_t *p_para = get_new_parameter("nLinkConnectionCommand", DDS_Int16, sizeof(int16_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
	}
};

typedef STRUCT_ALIGNED_(1) SER_SC_LINK_CONNECTION_COMMAND_ACK {
	int16_t nLinkConnectionCommand;
} SER_SC_LINK_CONNECTION_COMMAND_ACK;

class SER_SC_LINK_CONNECTION_COMMAND_ACKTypeSupport
{
public:
	FooTypeSupport	*fooTS;
public:
	void register_topic_type(DomainParticipant *p_Participant)
	{
		if(p_Participant == NULL) return;
		{
			fooTS = get_new_foo_type_support();
			insert_topic_parameters(fooTS);
			fooTS->i_size = sizeof(struct SER_SC_LINK_CONNECTION_COMMAND_ACK);
			fooTS->register_type(fooTS, p_Participant, "SER_SC_LINK_CONNECTION_COMMAND_ACK");
		}
	}
	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{dds_parameter_t *p_para = get_new_parameter("nLinkConnectionCommand", DDS_Int16, sizeof(int16_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
	}
};

typedef STRUCT_ALIGNED_(1) SC_SIM_SIMULATION_MANAGEMENT_COMMAND {
	int16_t nSimulationManagementCommand;
} SC_SIM_SIMULATION_MANAGEMENT_COMMAND;

class SC_SIM_SIMULATION_MANAGEMENT_COMMANDTypeSupport
{
public:
	FooTypeSupport	*fooTS;
public:
	void register_topic_type(DomainParticipant *p_Participant)
	{
		if(p_Participant == NULL) return;
		{
			fooTS = get_new_foo_type_support();
			insert_topic_parameters(fooTS);
			fooTS->i_size = sizeof(struct SC_SIM_SIMULATION_MANAGEMENT_COMMAND);
			fooTS->register_type(fooTS, p_Participant, "SC_SIM_SIMULATION_MANAGEMENT_COMMAND");
		}
	}
	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{dds_parameter_t *p_para = get_new_parameter("nSimulationManagementCommand", DDS_Int16, sizeof(int16_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
	}
};

typedef STRUCT_ALIGNED_(1) SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK {
	int16_t nSimulatorID;
	int16_t nSimulationManagementCommand;
} SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK;

class SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKTypeSupport
{
public:
	FooTypeSupport	*fooTS;
public:
	void register_topic_type(DomainParticipant *p_Participant)
	{
		if(p_Participant == NULL) return;
		{
			fooTS = get_new_foo_type_support();
			insert_topic_parameters(fooTS);
			fooTS->i_size = sizeof(struct SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK);
			fooTS->register_type(fooTS, p_Participant, "SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK");
		}
	}
	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{dds_parameter_t *p_para = get_new_parameter("nSimulatorID", DDS_Int16, sizeof(int16_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("nSimulationManagementCommand", DDS_Int16, sizeof(int16_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
	}
};

typedef STRUCT_ALIGNED_(1) SC_SIM_PARAMETER_DISTRIBUTION_COMMAND {
	int16_t eParameterDistributionCommand;
} SC_SIM_PARAMETER_DISTRIBUTION_COMMAND;

class SC_SIM_PARAMETER_DISTRIBUTION_COMMANDTypeSupport
{
public:
	FooTypeSupport	*fooTS;
public:
	void register_topic_type(DomainParticipant *p_Participant)
	{
		if(p_Participant == NULL) return;
		{
			fooTS = get_new_foo_type_support();
			insert_topic_parameters(fooTS);
			fooTS->i_size = sizeof(struct SC_SIM_PARAMETER_DISTRIBUTION_COMMAND);
			fooTS->register_type(fooTS, p_Participant, "SC_SIM_PARAMETER_DISTRIBUTION_COMMAND");
		}
	}
	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{dds_parameter_t *p_para = get_new_parameter("eParameterDistributionCommand", DDS_Int16, sizeof(int16_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
	}
};

typedef STRUCT_ALIGNED_(1) SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK {
	int16_t eParameterDistributionCommand;
} SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK;

class SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKTypeSupport
{
public:
	FooTypeSupport	*fooTS;
public:
	void register_topic_type(DomainParticipant *p_Participant)
	{
		if(p_Participant == NULL) return;
		{
			fooTS = get_new_foo_type_support();
			insert_topic_parameters(fooTS);
			fooTS->i_size = sizeof(struct SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK);
			fooTS->register_type(fooTS, p_Participant, "SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK");
		}
	}
	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{dds_parameter_t *p_para = get_new_parameter("eParameterDistributionCommand", DDS_Int16, sizeof(int16_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
	}
};

typedef STRUCT_ALIGNED_(1) SC_SIM_SIMULATOR_PARAMETER {
	char chParameterXML[2048];
} SC_SIM_SIMULATOR_PARAMETER;

class SC_SIM_SIMULATOR_PARAMETERTypeSupport
{
public:
	FooTypeSupport	*fooTS;
public:
	void register_topic_type(DomainParticipant *p_Participant)
	{
		if(p_Participant == NULL) return;
		{
			fooTS = get_new_foo_type_support();
			insert_topic_parameters(fooTS);
			fooTS->i_size = sizeof(struct SC_SIM_SIMULATOR_PARAMETER);
			fooTS->register_type(fooTS, p_Participant, "SC_SIM_SIMULATOR_PARAMETER");
		}
	}
	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{dds_parameter_t *p_para = get_new_parameter("chParameterXML", DDS_Array_Char8, sizeof(char)*((2048)));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
	}
};

typedef STRUCT_ALIGNED_(1) SIM_SC_SIMULATOR_PARAMETER_ACK {
	int16_t nSimulatorID;
	int16_t nSimulatorParameterAckState;
} SIM_SC_SIMULATOR_PARAMETER_ACK;

class SIM_SC_SIMULATOR_PARAMETER_ACKTypeSupport
{
public:
	FooTypeSupport	*fooTS;
public:
	void register_topic_type(DomainParticipant *p_Participant)
	{
		if(p_Participant == NULL) return;
		{
			fooTS = get_new_foo_type_support();
			insert_topic_parameters(fooTS);
			fooTS->i_size = sizeof(struct SIM_SC_SIMULATOR_PARAMETER_ACK);
			fooTS->register_type(fooTS, p_Participant, "SIM_SC_SIMULATOR_PARAMETER_ACK");
		}
	}
	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{dds_parameter_t *p_para = get_new_parameter("nSimulatorID", DDS_Int16, sizeof(int16_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("nSimulatorParameterAckState", DDS_Int16, sizeof(int16_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
	}
};

typedef STRUCT_ALIGNED_(1) SC_SIM_ENVIRONMENT {
	int16_t nWeather;
	double dTemparature;
	double dAirPressure;
	double dHumidity;
	double dVisibility;
	double dWindDirection;
	double dWindSpeed;
	double dWaterDirection;
	double dWaterSpeed;
} SC_SIM_ENVIRONMENT;

class SC_SIM_ENVIRONMENTTypeSupport
{
public:
	FooTypeSupport	*fooTS;
public:
	void register_topic_type(DomainParticipant *p_Participant)
	{
		if(p_Participant == NULL) return;
		{
			fooTS = get_new_foo_type_support();
			insert_topic_parameters(fooTS);
			fooTS->i_size = sizeof(struct SC_SIM_ENVIRONMENT);
			fooTS->register_type(fooTS, p_Participant, "SC_SIM_ENVIRONMENT");
		}
	}
	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{dds_parameter_t *p_para = get_new_parameter("nWeather", DDS_Int16, sizeof(int16_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("dTemparature", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("dAirPressure", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("dHumidity", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("dVisibility", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("dWindDirection", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("dWindSpeed", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("dWaterDirection", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("dWaterSpeed", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
	}
};

typedef STRUCT_ALIGNED_(1) SC_SIM_ENTITY {
	uint16_t unEntityID;
	ST_ENTITY_INFO stEntityInfo;
	ST_ENTITY_ATTRIBUTE stEntityAttribute;
	ST_ENTITY_STATE stEntityState;
} SC_SIM_ENTITY;

class SC_SIM_ENTITYTypeSupport
{
public:
	FooTypeSupport	*fooTS;
public:
	void register_topic_type(DomainParticipant *p_Participant)
	{
		if(p_Participant == NULL) return;
		{
			fooTS = get_new_foo_type_support();
			insert_topic_parameters(fooTS);
			fooTS->i_size = sizeof(struct SC_SIM_ENTITY);
			fooTS->register_type(fooTS, p_Participant, "SC_SIM_ENTITY");
		}
	}
	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{dds_parameter_t *p_para = get_new_parameter("unEntityID", DDS_UInt16, sizeof(uint16_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("stEntityInfo", DDS_Struct, sizeof(ST_ENTITY_INFO));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("stEntityAttribute", DDS_Struct, sizeof(ST_ENTITY_ATTRIBUTE));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("stEntityState", DDS_Struct, sizeof(ST_ENTITY_STATE));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
	}
};

typedef STRUCT_ALIGNED_(1) SC_SIM_ENTITY_STATE {
	uint16_t unEntityID;
	ST_ENTITY_STATE stEntityState;
} SC_SIM_ENTITY_STATE;

class SC_SIM_ENTITY_STATETypeSupport
{
public:
	FooTypeSupport	*fooTS;
public:
	void register_topic_type(DomainParticipant *p_Participant)
	{
		if(p_Participant == NULL) return;
		{
			fooTS = get_new_foo_type_support();
			insert_topic_parameters(fooTS);
			fooTS->i_size = sizeof(struct SC_SIM_ENTITY_STATE);
			fooTS->register_type(fooTS, p_Participant, "SC_SIM_ENTITY_STATE");
		}
	}
	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{dds_parameter_t *p_para = get_new_parameter("unEntityID", DDS_UInt16, sizeof(uint16_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("stEntityState", DDS_Struct, sizeof(ST_ENTITY_STATE));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
	}
};

typedef STRUCT_ALIGNED_(1) SC_SIM_OWNSHIP {
	uint16_t unEntityID;
	ST_ENTITY_INFO stEntityInfo;
	ST_ENTITY_ATTRIBUTE stEntityAttribute;
	ST_ENTITY_STATE stEntityState;
} SC_SIM_OWNSHIP;

class SC_SIM_OWNSHIPTypeSupport
{
public:
	FooTypeSupport	*fooTS;
public:
	void register_topic_type(DomainParticipant *p_Participant)
	{
		if(p_Participant == NULL) return;
		{
			fooTS = get_new_foo_type_support();
			insert_topic_parameters(fooTS);
			fooTS->i_size = sizeof(struct SC_SIM_OWNSHIP);
			fooTS->register_type(fooTS, p_Participant, "SC_SIM_OWNSHIP");
		}
	}
	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{dds_parameter_t *p_para = get_new_parameter("unEntityID", DDS_UInt16, sizeof(uint16_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("stEntityInfo", DDS_Struct, sizeof(ST_ENTITY_INFO));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("stEntityAttribute", DDS_Struct, sizeof(ST_ENTITY_ATTRIBUTE));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("stEntityState", DDS_Struct, sizeof(ST_ENTITY_STATE));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
	}
};

typedef STRUCT_ALIGNED_(1) SC_SIM_OWNSHIP_STATE {
	uint16_t unEntityID;
	ST_ENTITY_STATE stEntityState;
} SC_SIM_OWNSHIP_STATE;

class SC_SIM_OWNSHIP_STATETypeSupport
{
public:
	FooTypeSupport	*fooTS;
public:
	void register_topic_type(DomainParticipant *p_Participant)
	{
		if(p_Participant == NULL) return;
		{
			fooTS = get_new_foo_type_support();
			insert_topic_parameters(fooTS);
			fooTS->i_size = sizeof(struct SC_SIM_OWNSHIP_STATE);
			fooTS->register_type(fooTS, p_Participant, "SC_SIM_OWNSHIP_STATE");
		}
	}
	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{dds_parameter_t *p_para = get_new_parameter("unEntityID", DDS_UInt16, sizeof(uint16_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("stEntityState", DDS_Struct, sizeof(ST_ENTITY_STATE));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
	}
};

typedef STRUCT_ALIGNED_(1) SIM_SC_MISSILE_CREATION {
	int32_t lTimeToFire;
	ST_MISSILE_DATA stMissileData;
	ST_POSITION stWaypointCoordinate[8];
} SIM_SC_MISSILE_CREATION;

class SIM_SC_MISSILE_CREATIONTypeSupport
{
public:
	FooTypeSupport	*fooTS;
public:
	void register_topic_type(DomainParticipant *p_Participant)
	{
		if(p_Participant == NULL) return;
		{
			fooTS = get_new_foo_type_support();
			insert_topic_parameters(fooTS);
			fooTS->i_size = sizeof(struct SIM_SC_MISSILE_CREATION);
			fooTS->register_type(fooTS, p_Participant, "SIM_SC_MISSILE_CREATION");
		}
	}
	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{dds_parameter_t *p_para = get_new_parameter("lTimeToFire", DDS_Int32, sizeof(int32_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("stMissileData", DDS_Struct, sizeof(ST_MISSILE_DATA));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("stWaypointCoordinate", DDS_Struct, sizeof(ST_POSITION)*((8)));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
	}
};

typedef STRUCT_ALIGNED_(1) SIM_SC_SHELL_CREATION {
	int32_t lTimeToFire;
	ST_AMMUNITION_DATA stAmmunitionData;
	double dBearing;
	double dElevation;
} SIM_SC_SHELL_CREATION;

class SIM_SC_SHELL_CREATIONTypeSupport
{
public:
	FooTypeSupport	*fooTS;
public:
	void register_topic_type(DomainParticipant *p_Participant)
	{
		if(p_Participant == NULL) return;
		{
			fooTS = get_new_foo_type_support();
			insert_topic_parameters(fooTS);
			fooTS->i_size = sizeof(struct SIM_SC_SHELL_CREATION);
			fooTS->register_type(fooTS, p_Participant, "SIM_SC_SHELL_CREATION");
		}
	}
	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{dds_parameter_t *p_para = get_new_parameter("lTimeToFire", DDS_Int32, sizeof(int32_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("stAmmunitionData", DDS_Struct, sizeof(ST_AMMUNITION_DATA));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("dBearing", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("dElevation", DDS_Float64, sizeof(double));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
	}
};

