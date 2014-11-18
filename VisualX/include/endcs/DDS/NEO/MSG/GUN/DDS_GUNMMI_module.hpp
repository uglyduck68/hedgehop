#include <core.h>
#include <cpsdcps.h>
#include <dcps_func.h>

typedef struct DMSG_GFC_FIREDATA{
	double dAoS;
	double dEle;
	double dAzi;
	double dToF;
}DMSG_GFC_FIREDATA;

class DMSG_GFC_FIREDATATypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_GFC_FIREDATA);
			fooTS->register_type(fooTS,p_Participant,"DMSG_GFC_FIREDATA");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("dAoS", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dEle", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dAzi", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dToF", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_EC_FIRINGCMD{
	char command;
}DMSG_EC_FIRINGCMD;

class DMSG_EC_FIRINGCMDTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_EC_FIRINGCMD);
			fooTS->register_type(fooTS,p_Participant,"DMSG_EC_FIRINGCMD");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("command", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_GFC_HITEXPECT{
	double dPosX;
	double dPosY;
	double dPosZ;
}DMSG_GFC_HITEXPECT;

class DMSG_GFC_HITEXPECTTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_GFC_HITEXPECT);
			fooTS->register_type(fooTS,p_Participant,"DMSG_GFC_HITEXPECT");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("dPosX", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dPosY", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dPosZ", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_GUN_STATE{
	char bMotorState;
	char bControlMode;
	char bGunState;
	char bServerState;
	char bAngleModeState;
	char bAlignedState;
	char bFireAuthorizedState;
	char bAssignedState;
	char bFiringState;
	char byAimingMode;
	char bFuzeSetter;
	uint32_t nInventoryInfo;
	double dAngle;
	double dElevation;
	double fTimeOfFlight;
	double dTellbackMuzzleVelocity;
	double dTellbackPropellantsTemp;
	double dTellbackRatateAngle;
	double dTellbackElevation;
}DMSG_GUN_STATE;

class DMSG_GUN_STATETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_GUN_STATE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_GUN_STATE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("bMotorState", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("bControlMode", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("bGunState", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("bServerState", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("bAngleModeState", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("bAlignedState", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("bFireAuthorizedState", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("bAssignedState", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("bFiringState", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byAimingMode", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("bFuzeSetter", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nInventoryInfo", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dAngle", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dElevation", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fTimeOfFlight", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dTellbackMuzzleVelocity", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dTellbackPropellantsTemp", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dTellbackRatateAngle", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dTellbackElevation", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

