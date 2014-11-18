#include <core.h>
#include <cpsdcps.h>
#include <dcps_func.h>

typedef struct DMSG_TDSR_FIELDSETRESULT{
	char byFieldCategory;
	char byFieldConfig;
	char bySerialNumber;
	double dStartBearing;
	double dEndBearing;
	double dStartDistance;
	double dEndDistance;
	double dStartAltitude;
	double dEndAltitude;
	char byStandardPoint;
}DMSG_TDSR_FIELDSETRESULT;

class DMSG_TDSR_FIELDSETRESULTTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_TDSR_FIELDSETRESULT);
			fooTS->register_type(fooTS,p_Participant,"DMSG_TDSR_FIELDSETRESULT");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("byFieldCategory", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byFieldConfig", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("bySerialNumber", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dStartBearing", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dEndBearing", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dStartDistance", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dEndDistance", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dStartAltitude", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dEndAltitude", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byStandardPoint", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_TDSR_JAMMING{
	double dTime;
	char ReceiveRFChannel;
	double dBearing;
	double dAltitude;
}DMSG_TDSR_JAMMING;

class DMSG_TDSR_JAMMINGTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_TDSR_JAMMING);
			fooTS->register_type(fooTS,p_Participant,"DMSG_TDSR_JAMMING");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("dTime", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("ReceiveRFChannel", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dBearing", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dAltitude", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_TDSR_STATE{
	char StateInfo;
	char ValidState;
	char BattleShort;
	char PlatformControl;
	char BDriveControl;
	int32_t BDriveAngle;
	char TransmitterControl;
	char DuctingMode;
	char RadarSlience;
	char RFChannel1State;
	char RFChannel2State;
	char RFChannel3State;
	char RFChannel4State;
	char RFChannel5State;
	char RFChannel6State;
	char RFChannel7State;
	char RFChannel8State;
	char RFMode;
	char VideoMode;
	char VideoFilter;
	char VideoSTCType;
	char VideoThreshold;
}DMSG_TDSR_STATE;

class DMSG_TDSR_STATETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_TDSR_STATE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_TDSR_STATE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("StateInfo", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("ValidState", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("BattleShort", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("PlatformControl", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("BDriveControl", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("BDriveAngle", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("TransmitterControl", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("DuctingMode", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("RadarSlience", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("RFChannel1State", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("RFChannel2State", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("RFChannel3State", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("RFChannel4State", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("RFChannel5State", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("RFChannel6State", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("RFChannel7State", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("RFChannel8State", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("RFMode", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("VideoMode", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("VideoFilter", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("VideoSTCType", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("VideoThreshold", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_TDSR_TARGET{
	int32_t nTarget_Number;
	double dSystem_Time;
	char Target_Category;
	double dPosX;
	double dPosY;
	double dPosZ;
	double dVelocityX;
	double dVelocityY;
	double dVelocityZ;
	double dRange_Accuracy;
	double dBearing_Accuracy;
	double dElevation_Accuracy;
	char Track_Phase;
}DMSG_TDSR_TARGET;

class DMSG_TDSR_TARGETTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_TDSR_TARGET);
			fooTS->register_type(fooTS,p_Participant,"DMSG_TDSR_TARGET");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("nTarget_Number", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dSystem_Time", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("Target_Category", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
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
		{
			dds_parameter_t *p_para = get_new_parameter("dVelocityX", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dVelocityY", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dVelocityZ", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dRange_Accuracy", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dBearing_Accuracy", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dElevation_Accuracy", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("Track_Phase", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_TDSR_BSCOPE{
	int32_t nTWS_ID;
	char cGreen[40000];
}DMSG_TDSR_BSCOPE;

class DMSG_TDSR_BSCOPETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_TDSR_BSCOPE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_TDSR_BSCOPE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("nTWS_ID", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cGreen", DDS_CHARACTER_TYPE,sizeof(char)*40000);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_TDSR_COLUMNOFWATER{
	int32_t nTWS_ID;
	int32_t nID;
	double dDegree;
	double dRange;
}DMSG_TDSR_COLUMNOFWATER;

class DMSG_TDSR_COLUMNOFWATERTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_TDSR_COLUMNOFWATER);
			fooTS->register_type(fooTS,p_Participant,"DMSG_TDSR_COLUMNOFWATER");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("nTWS_ID", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nID", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dDegree", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dRange", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_TDSR_TWSTRACKING{
	int32_t nTWS_TrackingInfo;
	int32_t nTarget_Number;
	double dSystem_Time;
	char cTarget_Category;
	double dPosX;
	double dPosY;
	double dPosZ;
	double dVelocityX;
	double dVelocityY;
	double dVelocityZ;
	double dRange_Accuracy;
	double dBearing_Accuracy;
	double dElevation_Accuracy;
	char cTrack_Phase;
}DMSG_TDSR_TWSTRACKING;

class DMSG_TDSR_TWSTRACKINGTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_TDSR_TWSTRACKING);
			fooTS->register_type(fooTS,p_Participant,"DMSG_TDSR_TWSTRACKING");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("nTWS_TrackingInfo", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nTarget_Number", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dSystem_Time", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTarget_Category", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
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
		{
			dds_parameter_t *p_para = get_new_parameter("dVelocityX", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dVelocityY", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dVelocityZ", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dRange_Accuracy", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dBearing_Accuracy", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dElevation_Accuracy", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTrack_Phase", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_TDSRANTENNACTRL{
	char PlatformControl;
	char BDriveControl;
	int32_t nRequiredBearing;
}DMSG_HMI_TDSRANTENNACTRL;

class DMSG_HMI_TDSRANTENNACTRLTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_TDSRANTENNACTRL);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_TDSRANTENNACTRL");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("PlatformControl", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("BDriveControl", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nRequiredBearing", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_TDSRBATTLESHORTCMD{
	char BattleShot;
}DMSG_HMI_TDSRBATTLESHORTCMD;

class DMSG_HMI_TDSRBATTLESHORTCMDTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_TDSRBATTLESHORTCMD);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_TDSRBATTLESHORTCMD");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("BattleShot", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_TDSRTRANSMITTERCTRL{
	char TransmitterControl;
}DMSG_HMI_TDSRTRANSMITTERCTRL;

class DMSG_HMI_TDSRTRANSMITTERCTRLTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_TDSRTRANSMITTERCTRL);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_TDSRTRANSMITTERCTRL");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("TransmitterControl", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_OSM_TDSRFIELDSET{
	char SiteCategory;
	uint32_t nID;
	char OnOff;
	char SerialNumber;
	double dStartBearing;
	double dEndBearing;
	double dStartDistance;
	double dEndDistance;
	double dStartAltitude;
	double dEndAltitude;
	char StandardPoint;
}DMSG_OSM_TDSRFIELDSET;

class DMSG_OSM_TDSRFIELDSETTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_OSM_TDSRFIELDSET);
			fooTS->register_type(fooTS,p_Participant,"DMSG_OSM_TDSRFIELDSET");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("SiteCategory", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nID", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("OnOff", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("SerialNumber", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dStartBearing", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dEndBearing", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dStartDistance", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dEndDistance", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dStartAltitude", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dEndAltitude", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("StandardPoint", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_TDSRSURFACETRACKCTRL{
	char command;
	int32_t nTrackNum;
	double dPosX;
	double dPosY;
	double dTimeValidity;
}DMSG_HMI_TDSRSURFACETRACKCTRL;

class DMSG_HMI_TDSRSURFACETRACKCTRLTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_TDSRSURFACETRACKCTRL);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_TDSRSURFACETRACKCTRL");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("command", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nTrackNum", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dPosX", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dPosY", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dTimeValidity", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_TDSRRDRSILENCECTRL{
	char cCommand;
}DMSG_HMI_TDSRRDRSILENCECTRL;

class DMSG_HMI_TDSRRDRSILENCECTRLTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_TDSRRDRSILENCECTRL);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_TDSRRDRSILENCECTRL");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cCommand", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_TDSRSENDCHANNELSET{
	char FreqVariableSys;
	char ReceiveChannel;
	uint16_t usSetRFChannel;
}DMSG_HMI_TDSRSENDCHANNELSET;

class DMSG_HMI_TDSRSENDCHANNELSETTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_TDSRSENDCHANNELSET);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_TDSRSENDCHANNELSET");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("FreqVariableSys", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("ReceiveChannel", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("usSetRFChannel", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_TDSRSENDRFMODE{
	char RFMode;
}DMSG_HMI_TDSRSENDRFMODE;

class DMSG_HMI_TDSRSENDRFMODETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_TDSRSENDRFMODE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_TDSRSENDRFMODE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("RFMode", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_TDSRBLANKSECTORCTRL{
	char cBlanckSector;
}DMSG_HMI_TDSRBLANKSECTORCTRL;

class DMSG_HMI_TDSRBLANKSECTORCTRLTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_TDSRBLANKSECTORCTRL);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_TDSRBLANKSECTORCTRL");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cBlanckSector", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_TDSRVIDEOSET{
	char VideoMode;
	char StcCurve;
	char VideoClutterFilter;
	char VideoLimitMode;
	int32_t nVideoLimitValue;
	char DuctingConfigMode;
}DMSG_HMI_TDSRVIDEOSET;

class DMSG_HMI_TDSRVIDEOSETTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_TDSRVIDEOSET);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_TDSRVIDEOSET");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("VideoMode", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("StcCurve", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("VideoClutterFilter", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("VideoLimitMode", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nVideoLimitValue", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("DuctingConfigMode", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_TDSRVIDEOREQ{
	char VideoRequestStatus;
}DMSG_HMI_TDSRVIDEOREQ;

class DMSG_HMI_TDSRVIDEOREQTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_TDSRVIDEOREQ);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_TDSRVIDEOREQ");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("VideoRequestStatus", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_TDSRRDRMODESET{
	char ManagementMode;
	char PRF;
}DMSG_HMI_TDSRRDRMODESET;

class DMSG_HMI_TDSRRDRMODESETTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_TDSRRDRMODESET);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_TDSRRDRMODESET");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("ManagementMode", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("PRF", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_TDSRAIRTRACKINGSET{
	char Mode;
}DMSG_HMI_TDSRAIRTRACKINGSET;

class DMSG_HMI_TDSRAIRTRACKINGSETTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_TDSRAIRTRACKINGSET);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_TDSRAIRTRACKINGSET");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("Mode", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_TDSRSHIPTRACKINGSET{
	char Mode;
}DMSG_HMI_TDSRSHIPTRACKINGSET;

class DMSG_HMI_TDSRSHIPTRACKINGSETTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_TDSRSHIPTRACKINGSET);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_TDSRSHIPTRACKINGSET");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("Mode", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_TDSRJAMMINGDETECTSET{
	char DetectMode;
}DMSG_HMI_TDSRJAMMINGDETECTSET;

class DMSG_HMI_TDSRJAMMINGDETECTSETTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_TDSRJAMMINGDETECTSET);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_TDSRJAMMINGDETECTSET");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("DetectMode", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_TDSRLOWSPEEDDETECTSET{
	char LowDetectConfig;
}DMSG_HMI_TDSRLOWSPEEDDETECTSET;

class DMSG_HMI_TDSRLOWSPEEDDETECTSETTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_TDSRLOWSPEEDDETECTSET);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_TDSRLOWSPEEDDETECTSET");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("LowDetectConfig", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_TDSRLOWALTDETECTSET{
	char LowAltitudeConfig;
}DMSG_HMI_TDSRLOWALTDETECTSET;

class DMSG_HMI_TDSRLOWALTDETECTSETTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_TDSRLOWALTDETECTSET);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_TDSRLOWALTDETECTSET");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("LowAltitudeConfig", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_TDSRSIDELOBEBLOCK{
	char SubLobeBlock;
}DMSG_HMI_TDSRSIDELOBEBLOCK;

class DMSG_HMI_TDSRSIDELOBEBLOCKTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_TDSRSIDELOBEBLOCK);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_TDSRSIDELOBEBLOCK");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("SubLobeBlock", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_TDSREQUIPQUITSET{
	char EquitQuitConfig;
}DMSG_HMI_TDSREQUIPQUITSET;

class DMSG_HMI_TDSREQUIPQUITSETTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_TDSREQUIPQUITSET);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_TDSREQUIPQUITSET");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("EquitQuitConfig", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_EC_TDSRTWSTARGETDESIG{
	char byTrackingStatus;
	char TrackingChannel;
	int32_t nTargetNumber;
	double dPosX;
	double dPosY;
	double dPosZ;
}DMSG_EC_TDSRTWSTARGETDESIG;

class DMSG_EC_TDSRTWSTARGETDESIGTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_EC_TDSRTWSTARGETDESIG);
			fooTS->register_type(fooTS,p_Participant,"DMSG_EC_TDSRTWSTARGETDESIG");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("byTrackingStatus", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("TrackingChannel", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nTargetNumber", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
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

