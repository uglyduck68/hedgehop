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

typedef STRUCT_ALIGNED_(1) SIM_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK {
	int16_t nSimulatorID;
	int16_t nSimulatorManagementCommand;
} SIM_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK;

class SIM_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKTypeSupport
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
			fooTS->i_size = sizeof(struct SIM_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK);
			fooTS->register_type(fooTS, p_Participant, "SIM_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK");
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

typedef STRUCT_ALIGNED_(1) SC_SIM_LINK_CONNECTION_COMMAND {
	int16_t nLinkConnectionCommand;
} SC_SIM_LINK_CONNECTION_COMMAND;

class SC_SIM_LINK_CONNECTION_COMMANDTypeSupport
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
			fooTS->i_size = sizeof(struct SC_SIM_LINK_CONNECTION_COMMAND);
			fooTS->register_type(fooTS, p_Participant, "SC_SIM_LINK_CONNECTION_COMMAND");
		}
	}
	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{dds_parameter_t *p_para = get_new_parameter("nLinkConnectionCommand", DDS_Int16, sizeof(int16_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
	}
};

typedef STRUCT_ALIGNED_(1) SIM_SC_LINK_CONNECTION_COMMAND_ACK {
	int16_t nLinkConnectionCommand;
} SIM_SC_LINK_CONNECTION_COMMAND_ACK;

class SIM_SC_LINK_CONNECTION_COMMAND_ACKTypeSupport
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
			fooTS->i_size = sizeof(struct SIM_SC_LINK_CONNECTION_COMMAND_ACK);
			fooTS->register_type(fooTS, p_Participant, "SIM_SC_LINK_CONNECTION_COMMAND_ACK");
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
	int16_t nParameterDistributionCommand;
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
		{dds_parameter_t *p_para = get_new_parameter("nParameterDistributionCommand", DDS_Int16, sizeof(int16_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
	}
};

typedef STRUCT_ALIGNED_(1) SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK {
	int16_t nParameterDistributionCommand;
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
		{dds_parameter_t *p_para = get_new_parameter("nParameterDistributionCommand", DDS_Int16, sizeof(int16_t));
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
	float fTemparature;
	float fAirPressure;
	float fHumidity;
	float fVisibility;
	float fWindDirection;
	float fWindSpeed;
	float fWaterDirection;
	float fWaterSpeed;
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
		{dds_parameter_t *p_para = get_new_parameter("fTemparature", DDS_Float32, sizeof(float));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("fAirPressure", DDS_Float32, sizeof(float));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("fHumidity", DDS_Float32, sizeof(float));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("fVisibility", DDS_Float32, sizeof(float));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("fWindDirection", DDS_Float32, sizeof(float));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("fWindSpeed", DDS_Float32, sizeof(float));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("fWaterDirection", DDS_Float32, sizeof(float));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("fWaterSpeed", DDS_Float32, sizeof(float));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
	}
};

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
	float dWeaponRange;
	float dWeaponSpeed;
	int16_t nWeaponOperationType;
	int16_t nSensorClass;
	int16_t nSensorThreatLevel;
	char chSensorInfo[5];
	float fSensorFreqency;
	float fSensorScanRate;
	float fSensorScanType;
	float fSensorAmplitude;
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
		{dds_parameter_t *p_para = get_new_parameter("dWeaponRange", DDS_Float32, sizeof(float));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("dWeaponSpeed", DDS_Float32, sizeof(float));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("nWeaponOperationType", DDS_Int16, sizeof(int16_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("nSensorClass", DDS_Int16, sizeof(int16_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("nSensorThreatLevel", DDS_Int16, sizeof(int16_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("chSensorInfo", DDS_Array_Char8, sizeof(char)*((5)));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("fSensorFreqency", DDS_Float32, sizeof(float));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("fSensorScanRate", DDS_Float32, sizeof(float));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("fSensorScanType", DDS_Float32, sizeof(float));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("fSensorAmplitude", DDS_Float32, sizeof(float));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
	}
};

typedef STRUCT_ALIGNED_(1) ST_ENTITY_ATTRIBUTE {
	float fTurnRate;
	float fRiseRate;
	float fMaxAltitude;
	float fMaxSpeed;
	float fMaxAcceleration;
	float fMaxHealthPoint;
	float fLength;
	float fWidth;
	float fHeight;
	float fWeight;
	float Reserved_1;
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
		{dds_parameter_t *p_para = get_new_parameter("fTurnRate", DDS_Float32, sizeof(float));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("fRiseRate", DDS_Float32, sizeof(float));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("fMaxAltitude", DDS_Float32, sizeof(float));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("fMaxSpeed", DDS_Float32, sizeof(float));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("fMaxAcceleration", DDS_Float32, sizeof(float));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("fMaxHealthPoint", DDS_Float32, sizeof(float));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("fLength", DDS_Float32, sizeof(float));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("fWidth", DDS_Float32, sizeof(float));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("fHeight", DDS_Float32, sizeof(float));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("fWeight", DDS_Float32, sizeof(float));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("Reserved_1", DDS_Float32, sizeof(float));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
	}
};

typedef STRUCT_ALIGNED_(1) ST_ENTITY_STATE {
	ST_POSITION stPosition;
	float fSpeed;
	float fCourse;
	float fHeading;
	float fRoll;
	float fPitch;
	float fHealthPoint;
	int16_t nDestroyed;
	float Reserved_1;
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
		{dds_parameter_t *p_para = get_new_parameter("fSpeed", DDS_Float32, sizeof(float));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("fCourse", DDS_Float32, sizeof(float));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("fHeading", DDS_Float32, sizeof(float));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("fRoll", DDS_Float32, sizeof(float));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("fPitch", DDS_Float32, sizeof(float));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("fHealthPoint", DDS_Float32, sizeof(float));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("nDestroyed", DDS_Int16, sizeof(int16_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("Reserved_1", DDS_Float32, sizeof(float));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
	}
};

typedef STRUCT_ALIGNED_(1) SC_SIM_ENTITY {
	int32_t nEntityID;
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
		{dds_parameter_t *p_para = get_new_parameter("nEntityID", DDS_Int32, sizeof(int32_t));
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
	int32_t nEntityID;
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
		{dds_parameter_t *p_para = get_new_parameter("nEntityID", DDS_Int32, sizeof(int32_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("stEntityState", DDS_Struct, sizeof(ST_ENTITY_STATE));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
	}
};

typedef STRUCT_ALIGNED_(1) SC_SIM_OWNSHIP {
	int32_t nEntityID;
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
		{dds_parameter_t *p_para = get_new_parameter("nEntityID", DDS_Int32, sizeof(int32_t));
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
	int32_t nEntityID;
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
		{dds_parameter_t *p_para = get_new_parameter("nEntityID", DDS_Int32, sizeof(int32_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("stEntityState", DDS_Struct, sizeof(ST_ENTITY_STATE));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
	}
};

