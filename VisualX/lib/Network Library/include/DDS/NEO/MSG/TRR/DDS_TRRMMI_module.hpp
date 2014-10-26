#include <core.h>
#include <cpsdcps.h>
#include <dcps_func.h>

typedef struct DMSG_TRR_TARGET{
	uint32_t nTargetNum;
	char byTargetCategory;
	double dPosX;
	double dPosY;
	double dPosZ;
	double dVelocityX;
	double dVelocityY;
	double dVelocityZ;
	char byIsValidTarget;
}DMSG_TRR_TARGET;

class DMSG_TRR_TARGETTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_TRR_TARGET);
			fooTS->register_type(fooTS,p_Participant,"DMSG_TRR_TARGET");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("nTargetNum", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byTargetCategory", DDS_CHARACTER_TYPE,sizeof(char));
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
			dds_parameter_t *p_para = get_new_parameter("byIsValidTarget", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_TRR_DIRECTOR{
	double dDirectorTraverse;
	double dDirectorBearing;
	double dDirectorElevation;
}DMSG_TRR_DIRECTOR;

class DMSG_TRR_DIRECTORTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_TRR_DIRECTOR);
			fooTS->register_type(fooTS,p_Participant,"DMSG_TRR_DIRECTOR");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("dDirectorTraverse", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dDirectorBearing", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dDirectorElevation", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_TRR_TRACKING{
	int32_t nTargetNum;
	char byTrackingStatus;
	char bySourceTrack;
	char byKillAssessment;
	char byRadiationAuthority;
}DMSG_TRR_TRACKING;

class DMSG_TRR_TRACKINGTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_TRR_TRACKING);
			fooTS->register_type(fooTS,p_Participant,"DMSG_TRR_TRACKING");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("nTargetNum", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byTrackingStatus", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("bySourceTrack", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byKillAssessment", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byRadiationAuthority", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_TRR_SHOOTDOWNRESULT{
	uint32_t nTargetNum;
	char byshootdownResult;
}DMSG_TRR_SHOOTDOWNRESULT;

class DMSG_TRR_SHOOTDOWNRESULTTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_TRR_SHOOTDOWNRESULT);
			fooTS->register_type(fooTS,p_Participant,"DMSG_TRR_SHOOTDOWNRESULT");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("nTargetNum", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byshootdownResult", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_TRR_SETRESULT{
	char bySettingCategory;
	char bySettingResult;
}DMSG_TRR_SETRESULT;

class DMSG_TRR_SETRESULTTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_TRR_SETRESULT);
			fooTS->register_type(fooTS,p_Participant,"DMSG_TRR_SETRESULT");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("bySettingCategory", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("bySettingResult", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_TRR_ASCOPE{
	int32_t nSamplingNum;
	int32_t nSignalPower[100];
	int32_t nScaleX;
	int32_t nScaleY;
}DMSG_TRR_ASCOPE;

class DMSG_TRR_ASCOPETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_TRR_ASCOPE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_TRR_ASCOPE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("nSamplingNum", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nSignalPower", DDS_INTEGER_TYPE,sizeof(int32_t)*100);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nScaleX", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nScaleY", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_TRR_STATE{
	char byInterlockState;
	char byAvailableState;
}DMSG_TRR_STATE;

class DMSG_TRR_STATETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_TRR_STATE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_TRR_STATE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("byInterlockState", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byAvailableState", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_TRRRDRCHECKREQ{
	char cRadarTest;
}DMSG_HMI_TRRRDRCHECKREQ;

class DMSG_HMI_TRRRDRCHECKREQTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_TRRRDRCHECKREQ);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_TRRRDRCHECKREQ");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cRadarTest", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_EC_TRRTRACKINGCMD{
	char byTrackingStatus;
	uint32_t nTargetNum;
	double dBearing;
	double dElevation;
	double dDistance;
}DMSG_EC_TRRTRACKINGCMD;

class DMSG_EC_TRRTRACKINGCMDTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_EC_TRRTRACKINGCMD);
			fooTS->register_type(fooTS,p_Participant,"DMSG_EC_TRRTRACKINGCMD");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("byTrackingStatus", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nTargetNum", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dBearing", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dElevation", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dDistance", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_TRRSHOOTDOWNRESULTREQ{
	uint32_t nTargetNum;
	char byRequestStatus;
}DMSG_HMI_TRRSHOOTDOWNRESULTREQ;

class DMSG_HMI_TRRSHOOTDOWNRESULTREQTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_TRRSHOOTDOWNRESULTREQ);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_TRRSHOOTDOWNRESULTREQ");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("nTargetNum", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byRequestStatus", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_TRRRDRSET{
	char byTWTConfig;
	char byTransmitMode;
	char byDecreaseMode;
}DMSG_HMI_TRRRDRSET;

class DMSG_HMI_TRRRDRSETTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_TRRRDRSET);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_TRRRDRSET");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("byTWTConfig", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byTransmitMode", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byDecreaseMode", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_TRRVIDEOSET{
	char byAScopeSTC;
	char byAScopeVideo;
	char byNoiseThreshold;
	char byDisplayThreshold;
}DMSG_HMI_TRRVIDEOSET;

class DMSG_HMI_TRRVIDEOSETTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_TRRVIDEOSET);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_TRRVIDEOSET");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("byAScopeSTC", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byAScopeVideo", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byNoiseThreshold", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byDisplayThreshold", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_TRRMANAGESET{
	int32_t nInitAltitude;
	int32_t nShipTrackAltitude;
	char bySeaState;
	int32_t nMaxAltitude;
}DMSG_HMI_TRRMANAGESET;

class DMSG_HMI_TRRMANAGESETTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_TRRMANAGESET);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_TRRMANAGESET");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("nInitAltitude", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nShipTrackAltitude", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("bySeaState", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nMaxAltitude", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_TRRCAUTIONSET{
	char bMissileCaution;
	char bJammerTracking;
}DMSG_HMI_TRRCAUTIONSET;

class DMSG_HMI_TRRCAUTIONSETTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_TRRCAUTIONSET);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_TRRCAUTIONSET");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("bMissileCaution", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("bJammerTracking", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_TRREQUIPMENTSET{
	char byTWTPower;
	char byEmergencyManageMode;
	char byRadiationControl;
	char byRadarSilence;
	char byDirector;
	char byJoystick;
}DMSG_HMI_TRREQUIPMENTSET;

class DMSG_HMI_TRREQUIPMENTSETTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_TRREQUIPMENTSET);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_TRREQUIPMENTSET");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("byTWTPower", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byEmergencyManageMode", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byRadiationControl", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byRadarSilence", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byDirector", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byJoystick", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_TRRTRACKINGSET{
	char byHandTracking;
	char byHandRegulation;
	char bySecondaryTarget;
	int32_t nRangeGateMoveCtr;
	char byRangeGateCtr;
	char byLowAltitudeTracking;
	char byFlightTarget;
	char byFilter;
}DMSG_HMI_TRRTRACKINGSET;

class DMSG_HMI_TRRTRACKINGSETTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_TRRTRACKINGSET);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_TRRTRACKINGSET");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("byHandTracking", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byHandRegulation", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("bySecondaryTarget", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nRangeGateMoveCtr", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byRangeGateCtr", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byLowAltitudeTracking", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byFlightTarget", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byFilter", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_TRRVIDEOREQ{
	char cRequestVideo;
}DMSG_HMI_TRRVIDEOREQ;

class DMSG_HMI_TRRVIDEOREQTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_TRRVIDEOREQ);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_TRRVIDEOREQ");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cRequestVideo", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

