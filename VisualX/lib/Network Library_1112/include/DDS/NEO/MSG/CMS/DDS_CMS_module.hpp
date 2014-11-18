#include <core.h>
#include <cpsdcps.h>
#include <dcps_func.h>

typedef struct TrkNoSys{
	uint16_t trkNo;
	uint16_t trkNoLINK;
	uint16_t trkNoTDSR;
	char trkNoTRR;
	char trkNoEOTS;
	char trkNoEW;
	char trkNoPERI;
	char trkNoOMS;
	char trkNoNAVR;
	char trkNoSONAR;
	char trkNoMAN;
}TrkNoSys;

class TrkNoSysTypeSupport
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
			fooTS->i_size = sizeof(struct TrkNoSys);
			fooTS->register_type(fooTS,p_Participant,"TrkNoSys");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("trkNoLINK", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("trkNoTDSR", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("trkNoTRR", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("trkNoEOTS", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("trkNoEW", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("trkNoPERI", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("trkNoOMS", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("trkNoNAVR", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("trkNoSONAR", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("trkNoMAN", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct stDate{
	uint16_t yy;
	char mm;
	char dd;
}stDate;

class stDateTypeSupport
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
			fooTS->i_size = sizeof(struct stDate);
			fooTS->register_type(fooTS,p_Participant,"stDate");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("yy", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("mm", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dd", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct stTime{
	char hh;
	char mm;
}stTime;

class stTimeTypeSupport
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
			fooTS->i_size = sizeof(struct stTime);
			fooTS->register_type(fooTS,p_Participant,"stTime");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("hh", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("mm", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct time1{
	char hh;
	char mm;
	char ss;
}time1;

class time1TypeSupport
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
			fooTS->i_size = sizeof(struct time1);
			fooTS->register_type(fooTS,p_Participant,"time1");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("hh", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("mm", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("ss", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct time2{
	char hh;
	char mm;
	char ss;
	char ms;
}time2;

class time2TypeSupport
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
			fooTS->i_size = sizeof(struct time2);
			fooTS->register_type(fooTS,p_Participant,"time2");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("hh", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("mm", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("ss", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("ms", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct coordiSys{
	double latitude;
	double longitude;
}coordiSys;

class coordiSysTypeSupport
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
			fooTS->i_size = sizeof(struct coordiSys);
			fooTS->register_type(fooTS,p_Participant,"coordiSys");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("latitude", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("longitude", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct coordiHSys{
	double latitude;
	double longitude;
	double hgt;
}coordiHSys;

class coordiHSysTypeSupport
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
			fooTS->i_size = sizeof(struct coordiHSys);
			fooTS->register_type(fooTS,p_Participant,"coordiHSys");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("latitude", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("longitude", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("hgt", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct coordiRSys{
	double latitude;
	double longitude;
	uint16_t radius;
}coordiRSys;

class coordiRSysTypeSupport
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
			fooTS->i_size = sizeof(struct coordiRSys);
			fooTS->register_type(fooTS,p_Participant,"coordiRSys");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("latitude", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("longitude", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("radius", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct rectSys{
	double x;
	double z;
}rectSys;

class rectSysTypeSupport
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
			fooTS->i_size = sizeof(struct rectSys);
			fooTS->register_type(fooTS,p_Participant,"rectSys");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("x", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("z", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct rectHSys{
	double x;
	double y;
	double z;
}rectHSys;

class rectHSysTypeSupport
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
			fooTS->i_size = sizeof(struct rectHSys);
			fooTS->register_type(fooTS,p_Participant,"rectHSys");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("x", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("y", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("z", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct rectRSys{
	double x;
	double z;
	uint16_t radius;
}rectRSys;

class rectRSysTypeSupport
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
			fooTS->i_size = sizeof(struct rectRSys);
			fooTS->register_type(fooTS,p_Participant,"rectRSys");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("x", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("z", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("radius", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct velocity3D{
	double hh;
	double mm;
}velocity3D;

class velocity3DTypeSupport
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
			fooTS->i_size = sizeof(struct velocity3D);
			fooTS->register_type(fooTS,p_Participant,"velocity3D");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("hh", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("mm", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct SonarTrack{
	char cSensor;
	char cTargetState;
	char cTrackingMode;
	double fBearing;
	double fBearingRate;
	double fSignalToNoiseRation;
	double fRange;
	double fCourse;
	double fSpeed;
}SonarTrack;

class SonarTrackTypeSupport
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
			fooTS->i_size = sizeof(struct SonarTrack);
			fooTS->register_type(fooTS,p_Participant,"SonarTrack");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cSensor", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTargetState", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTrackingMode", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fBearing", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fBearingRate", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fSignalToNoiseRation", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fRange", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fCourse", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fSpeed", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct stWake{
	double dLat[30];
	double dLon[30];
	int32_t nLatIndex;
	int32_t nLonIndex;
}stWake;

class stWakeTypeSupport
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
			fooTS->i_size = sizeof(struct stWake);
			fooTS->register_type(fooTS,p_Participant,"stWake");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("dLat", DDS_FLOAT_TYPE,sizeof(double)*30);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dLon", DDS_FLOAT_TYPE,sizeof(double)*30);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nLatIndex", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nLonIndex", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct stSubSysTrackID{
	uint32_t nTrkNo;
	uint32_t nPrsTrkNo;
	uint32_t nCasBdtTrkNo;
	uint32_t nFasBdtTrkNo;
	uint32_t nCasDemTrkNo;
	uint32_t nFasLdtTrkNo;
	uint32_t nFasDemTrkNo;
	uint32_t nNavrTrkNo;
	uint32_t nPeriTrkNo;
	uint32_t nOmsTrkNo;
	uint32_t nManTrkNo;
	uint32_t nTorpTrkNo;
	uint32_t nIpsTrkNo;
	uint32_t nEsmTrkNo;
	uint32_t nLinkTrkNo;
}stSubSysTrackID;

class stSubSysTrackIDTypeSupport
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
			fooTS->i_size = sizeof(struct stSubSysTrackID);
			fooTS->register_type(fooTS,p_Participant,"stSubSysTrackID");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("nTrkNo", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nPrsTrkNo", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nCasBdtTrkNo", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nFasBdtTrkNo", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nCasDemTrkNo", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nFasLdtTrkNo", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nFasDemTrkNo", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nNavrTrkNo", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nPeriTrkNo", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nOmsTrkNo", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nManTrkNo", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nTorpTrkNo", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nIpsTrkNo", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nEsmTrkNo", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nLinkTrkNo", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct stFullTime{
	uint16_t year;
	char month;
	char day;
	char hour;
	char minute;
	char sec;
	char msec;
}stFullTime;

class stFullTimeTypeSupport
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
			fooTS->i_size = sizeof(struct stFullTime);
			fooTS->register_type(fooTS,p_Participant,"stFullTime");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("year", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("month", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("day", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("hour", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("minute", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("sec", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("msec", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_OSM_SENSORSTATE{
	int32_t nTrackRadarID;
	char bInterFaceInfo;
	char bAvailable;
	char bCh1_available;
	char bCh2_available;
}DMSG_OSM_SENSORSTATE;

class DMSG_OSM_SENSORSTATETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_OSM_SENSORSTATE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_OSM_SENSORSTATE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("nTrackRadarID", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("bInterFaceInfo", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("bAvailable", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("bCh1_available", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("bCh2_available", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_OSM_WEAPONSTATE{
	int32_t nWeaponID;
	char bInterFace;
	char bAvailable;
}DMSG_OSM_WEAPONSTATE;

class DMSG_OSM_WEAPONSTATETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_OSM_WEAPONSTATE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_OSM_WEAPONSTATE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("nWeaponID", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("bInterFace", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("bAvailable", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_REQMISSILEENGAGEPLAN{
	char cConsoleID;
	char cTubeID;
	TrkNoSys trkNo;
}DMSG_HMI_REQMISSILEENGAGEPLAN;

class DMSG_HMI_REQMISSILEENGAGEPLANTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_REQMISSILEENGAGEPLAN);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_REQMISSILEENGAGEPLAN");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cConsoleID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTubeID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_SUBHMI_SYSCTRLMODE{
	uint32_t consoleID;
	uint32_t mode;
}DMSG_SUBHMI_SYSCTRLMODE;

class DMSG_SUBHMI_SYSCTRLMODETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_SUBHMI_SYSCTRLMODE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_SUBHMI_SYSCTRLMODE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("consoleID", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("mode", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_WEAPONLIMITSET{
	uint32_t trkNo;
	char cWeaponLimit;
}DMSG_HMI_WEAPONLIMITSET;

class DMSG_HMI_WEAPONLIMITSETTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_WEAPONLIMITSET);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_WEAPONLIMITSET");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cWeaponLimit", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_CREATEMANUALTRACK{
	char cTrackForm;
	char cTrackType;
	char cTrackIdentity;
	char cTrackCategory;
	uint16_t sIdentificationDetailType;
	uint16_t sIdentificationDetailMajor;
	uint16_t sIdentificationDetailMinor;
	double fCourse;
	double fSpeed;
	coordiHSys positionCHSys;
}DMSG_HMI_CREATEMANUALTRACK;

class DMSG_HMI_CREATEMANUALTRACKTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_CREATEMANUALTRACK);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_CREATEMANUALTRACK");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cTrackForm", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTrackType", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTrackIdentity", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTrackCategory", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("sIdentificationDetailType", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("sIdentificationDetailMajor", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("sIdentificationDetailMinor", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fCourse", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fSpeed", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("positionCHSys", DDS_STRUCT_TYPE,sizeof(coordiHSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_TARGETIDENTITYSET{
	uint32_t trkNo;
	char cTrackIdentity;
}DMSG_HMI_TARGETIDENTITYSET;

class DMSG_HMI_TARGETIDENTITYSETTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_TARGETIDENTITYSET);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_TARGETIDENTITYSET");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTrackIdentity", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_TARGETCATEGORYSET{
	uint32_t trkNo;
	char cTrackCategory;
}DMSG_HMI_TARGETCATEGORYSET;

class DMSG_HMI_TARGETCATEGORYSETTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_TARGETCATEGORYSET);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_TARGETCATEGORYSET");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTrackCategory", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_TARGETNAMESET{
	uint32_t trkNo;
	char cTrackName[30];
}DMSG_HMI_TARGETNAMESET;

class DMSG_HMI_TARGETNAMESETTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_TARGETNAMESET);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_TARGETNAMESET");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTrackName", DDS_CHARACTER_TYPE,sizeof(char)*30);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_ENGAGESET{
	uint32_t trkNo;
	char cEngageState;
}DMSG_HMI_ENGAGESET;

class DMSG_HMI_ENGAGESETTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_ENGAGESET);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_ENGAGESET");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cEngageState", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_MANUALSELECTSET{
	uint32_t trkNo;
	char cThreatEvaluation;
}DMSG_HMI_MANUALSELECTSET;

class DMSG_HMI_MANUALSELECTSETTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_MANUALSELECTSET);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_MANUALSELECTSET");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cThreatEvaluation", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_IDENTITYDETAILSET{
	uint32_t trkNo;
	uint16_t sIdentificationDetailType;
	uint16_t sIdentificationDetailMajor;
	uint16_t sIdentificationDetailMinor;
}DMSG_HMI_IDENTITYDETAILSET;

class DMSG_HMI_IDENTITYDETAILSETTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_IDENTITYDETAILSET);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_IDENTITYDETAILSET");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("sIdentificationDetailType", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("sIdentificationDetailMajor", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("sIdentificationDetailMinor", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_WEAPONCAPABILITYSET{
	uint32_t trkNo;
	uint16_t sWeaponCapability;
	double fWeaponMaxRange;
}DMSG_HMI_WEAPONCAPABILITYSET;

class DMSG_HMI_WEAPONCAPABILITYSETTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_WEAPONCAPABILITYSET);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_WEAPONCAPABILITYSET");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("sWeaponCapability", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fWeaponMaxRange", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_DATUMSET{
	uint32_t trkNo;
	double fDatumSpd;
	double fDatumErr;
}DMSG_HMI_DATUMSET;

class DMSG_HMI_DATUMSETTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_DATUMSET);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_DATUMSET");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fDatumSpd", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fDatumErr", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_SYSTRACKDEL{
	uint32_t DelTrkNo;
}DMSG_HMI_SYSTRACKDEL;

class DMSG_HMI_SYSTRACKDELTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_SYSTRACKDEL);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_SYSTRACKDEL");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("DelTrkNo", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_PAIRINGSET{
	char cPairingType;
	TrkNoSys PairingTrkNo;
	TrkNoSys NetTrkNo;
}DMSG_HMI_PAIRINGSET;

class DMSG_HMI_PAIRINGSETTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_PAIRINGSET);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_PAIRINGSET");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cPairingType", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("PairingTrkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("NetTrkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_ASSOCIATIONSET{
	char cAssociationType;
	TrkNoSys MainTrkNo;
	TrkNoSys MinortrkNo;
}DMSG_HMI_ASSOCIATIONSET;

class DMSG_HMI_ASSOCIATIONSETTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_ASSOCIATIONSET);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_ASSOCIATIONSET");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cAssociationType", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("MainTrkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("MinortrkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_CORRELATIONSET{
	TrkNoSys KeeptrkNo;
	TrkNoSys DeltrkNo;
}DMSG_HMI_CORRELATIONSET;

class DMSG_HMI_CORRELATIONSETTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_CORRELATIONSET);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_CORRELATIONSET");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("KeeptrkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("DeltrkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_CORRELATIONCLEAR{
	TrkNoSys trkNo;
}DMSG_HMI_CORRELATIONCLEAR;

class DMSG_HMI_CORRELATIONCLEARTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_CORRELATIONCLEAR);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_CORRELATIONCLEAR");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_TRACECHANGE{
	uint32_t trkNo;
	uint32_t nSensorType;
}DMSG_HMI_TRACECHANGE;

class DMSG_HMI_TRACECHANGETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_TRACECHANGE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_TRACECHANGE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nSensorType", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_TRACKWEAPONRANGE{
	TrkNoSys trkNo;
	double fRange;
}DMSG_HMI_TRACKWEAPONRANGE;

class DMSG_HMI_TRACKWEAPONRANGETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_TRACKWEAPONRANGE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_TRACKWEAPONRANGE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fRange", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_TRACKSENSORRANGE{
	TrkNoSys trkNo;
	double fRange;
}DMSG_HMI_TRACKSENSORRANGE;

class DMSG_HMI_TRACKSENSORRANGETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_TRACKSENSORRANGE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_TRACKSENSORRANGE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fRange", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_ANTIWEAPONWEIGHT{
	TrkNoSys trkNo;
	int32_t nWeight;
}DMSG_HMI_ANTIWEAPONWEIGHT;

class DMSG_HMI_ANTIWEAPONWEIGHTTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_ANTIWEAPONWEIGHT);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_ANTIWEAPONWEIGHT");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nWeight", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_TAGSET{
	uint32_t trkNo;
	char cTagSet[6];
}DMSG_HMI_TAGSET;

class DMSG_HMI_TAGSETTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_TAGSET);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_TAGSET");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTagSet", DDS_CHARACTER_TYPE,sizeof(char)*6);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_SONARSET{
	uint32_t trkNo;
	char cValid;
	double fRange;
}DMSG_HMI_SONARSET;

class DMSG_HMI_SONARSETTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_SONARSET);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_SONARSET");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cValid", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fRange", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_WEAPONSET{
	uint32_t trkNo;
	char cValid;
	double fRange;
}DMSG_HMI_WEAPONSET;

class DMSG_HMI_WEAPONSETTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_WEAPONSET);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_WEAPONSET");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cValid", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fRange", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_SUBCORRELATIONSET{
	uint32_t KeeptrkNo;
	uint32_t DeltrkNo;
}DMSG_HMI_SUBCORRELATIONSET;

class DMSG_HMI_SUBCORRELATIONSETTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_SUBCORRELATIONSET);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_SUBCORRELATIONSET");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("KeeptrkNo", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("DeltrkNo", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_SUBCORRELATIONCLEAR{
	stSubSysTrackID sSysTrkID;
}DMSG_HMI_SUBCORRELATIONCLEAR;

class DMSG_HMI_SUBCORRELATIONCLEARTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_SUBCORRELATIONCLEAR);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_SUBCORRELATIONCLEAR");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("sSysTrkID", DDS_STRUCT_TYPE,sizeof(stSubSysTrackID));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_TM_SYSTRACKDEL{
	TrkNoSys trkNo;
}DMSG_TM_SYSTRACKDEL;

class DMSG_TM_SYSTRACKDELTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_TM_SYSTRACKDEL);
			fooTS->register_type(fooTS,p_Participant,"DMSG_TM_SYSTRACKDEL");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_TM_SYSTRACK{
	TrkNoSys trkNo;
	char cWeaponLimit;
	char cEngageState;
	char cThreatEvaluation;
	char cEngageResult;
	uint32_t nCreatedTimeTag;
	uint32_t nUpdatedTimeTag;
	char cTrackType;
	char cTrackCategory;
	char cTrackIdentity;
	char cIFFMode1;
	uint16_t sIFFMode2;
	uint16_t sIFFMode3;
	uint16_t sIFFModeC;
	char cIFFMode4;
	char cTrackName[30];
	uint16_t sTrackNationality;
	char cTrackForm;
	rectHSys position;
	coordiHSys positionCHSys;
	char cTrackQuality;
	char cWeaponCapability;
	double fWeaponMaxRange;
	double fDatumSpd;
	double fDatumErr;
	uint16_t sIdentificationDetailType;
	uint16_t sIdentificationDetailMajor;
	uint16_t sIdentificationDetailMinor;
	double fBearing;
	double fRange;
	double fCourse;
	double fSpeed;
	char ctag[6];
	char cLinkAlert;
	char cMissleCheck;
	double fElevation;
	double fBearingRate;
	char cSensorType;
	double fROC;
	char cLinkState;
	TrkNoSys pairingTrk[4];
	TrkNoSys associationTrk[4];
}DMSG_TM_SYSTRACK;

class DMSG_TM_SYSTRACKTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_TM_SYSTRACK);
			fooTS->register_type(fooTS,p_Participant,"DMSG_TM_SYSTRACK");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cWeaponLimit", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cEngageState", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cThreatEvaluation", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cEngageResult", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nCreatedTimeTag", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nUpdatedTimeTag", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTrackType", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTrackCategory", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTrackIdentity", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cIFFMode1", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("sIFFMode2", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("sIFFMode3", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("sIFFModeC", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cIFFMode4", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTrackName", DDS_CHARACTER_TYPE,sizeof(char)*30);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("sTrackNationality", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTrackForm", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("position", DDS_STRUCT_TYPE,sizeof(rectHSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("positionCHSys", DDS_STRUCT_TYPE,sizeof(coordiHSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTrackQuality", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cWeaponCapability", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fWeaponMaxRange", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fDatumSpd", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fDatumErr", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("sIdentificationDetailType", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("sIdentificationDetailMajor", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("sIdentificationDetailMinor", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fBearing", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fRange", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fCourse", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fSpeed", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("ctag", DDS_CHARACTER_TYPE,sizeof(char)*6);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cLinkAlert", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cMissleCheck", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fElevation", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fBearingRate", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cSensorType", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fROC", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cLinkState", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
#if 0 // byungung, 20140415
		{
			dds_parameter_t *p_para = get_new_parameter("pairingTrk", DDS_STRING_TYPE,sizeof(TrkNoSys)*4);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("associationTrk", DDS_STRING_TYPE,sizeof(TrkNoSys)*4);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
#else
		{
			dds_parameter_t *p_para = get_new_parameter("pairingTrk", DDS_STRUCT_TYPE,sizeof(TrkNoSys)*4);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("associationTrk", DDS_STRUCT_TYPE,sizeof(TrkNoSys)*4);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
#endif
	}
};

typedef struct DMSG_TM_SWSTATE{
	char cSoftwareState;
}DMSG_TM_SWSTATE;

class DMSG_TM_SWSTATETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_TM_SWSTATE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_TM_SWSTATE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cSoftwareState", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_TM_SUBSYSTEMTRACK{
	stSubSysTrackID sSysTrkID;
	int32_t nRepresentativeSensor;
	char cLinkState;
	stFullTime sCreatedTime;
	stFullTime sUpdatedTime;
	char nTrackSource;
	char nTrackType;
	char cTrackCategory;
	char cTrackIdentity;
	char cTrackName[30];
	uint16_t sIdentificationDetailType;
	uint16_t sIdentificationDetailMajor;
	uint16_t sIdentificationDetailMinor;
	char cTag[6];
	double fBearing;
	double fBearingRate;
	double fRange;
	double fCourse;
	double fSpeed;
	coordiHSys positionCHSys;
	char cSNRatio;
	char cPulseLv;
	double fAOB;
	char cSonarValid;
	double fSonarRange;
	char cWeaponValid;
	double fWeaponRange;
}DMSG_TM_SUBSYSTEMTRACK;

class DMSG_TM_SUBSYSTEMTRACKTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_TM_SUBSYSTEMTRACK);
			fooTS->register_type(fooTS,p_Participant,"DMSG_TM_SUBSYSTEMTRACK");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("sSysTrkID", DDS_STRUCT_TYPE,sizeof(stSubSysTrackID));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nRepresentativeSensor", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cLinkState", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("sCreatedTime", DDS_STRUCT_TYPE,sizeof(stFullTime));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("sUpdatedTime", DDS_STRUCT_TYPE,sizeof(stFullTime));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nTrackSource", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nTrackType", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTrackCategory", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTrackIdentity", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTrackName", DDS_CHARACTER_TYPE,sizeof(char)*30);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("sIdentificationDetailType", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("sIdentificationDetailMajor", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("sIdentificationDetailMinor", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTag", DDS_CHARACTER_TYPE,sizeof(char)*6);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fBearing", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fBearingRate", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fRange", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fCourse", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fSpeed", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("positionCHSys", DDS_STRUCT_TYPE,sizeof(coordiHSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cSNRatio", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cPulseLv", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fAOB", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cSonarValid", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fSonarRange", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cWeaponValid", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fWeaponRange", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_TM_SUBSYSTRACKDEL{
	stSubSysTrackID sSysTrkID;
}DMSG_TM_SUBSYSTRACKDEL;

class DMSG_TM_SUBSYSTRACKDELTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_TM_SUBSYSTRACKDEL);
			fooTS->register_type(fooTS,p_Participant,"DMSG_TM_SUBSYSTRACKDEL");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("sSysTrkID", DDS_STRUCT_TYPE,sizeof(stSubSysTrackID));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_WEAPONCTRL{
	char cWeaponCtrl;
}DMSG_HMI_WEAPONCTRL;

class DMSG_HMI_WEAPONCTRLTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_WEAPONCTRL);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_WEAPONCTRL");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cWeaponCtrl", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_FASTRESPONSEMODE{
	char cFastResponseMode;
}DMSG_HMI_FASTRESPONSEMODE;

class DMSG_HMI_FASTRESPONSEMODETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_FASTRESPONSEMODE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_FASTRESPONSEMODE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cFastResponseMode", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_WEAPONUSELIMIT{
	TrkNoSys trkNo;
	char cWeaponLimit;
}DMSG_HMI_WEAPONUSELIMIT;

class DMSG_HMI_WEAPONUSELIMITTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_WEAPONUSELIMIT);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_WEAPONUSELIMIT");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cWeaponLimit", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_ENGAGEMODESET{
	char cMode;
}DMSG_HMI_ENGAGEMODESET;

class DMSG_HMI_ENGAGEMODESETTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_ENGAGEMODESET);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_ENGAGEMODESET");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cMode", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_ENGAGEADVICEREQ{
	char cEngageType;
	TrkNoSys trkNo;
}DMSG_HMI_ENGAGEADVICEREQ;

class DMSG_HMI_ENGAGEADVICEREQTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_ENGAGEADVICEREQ);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_ENGAGEADVICEREQ");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cEngageType", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_THREATDICISION{
	char cEngageType;
	char cTrackIdentity;
	double fMinRange;
	double fMaxRange;
	double fMinBearing;
	double fMaxBearing;
	double fMinSpd;
	double fMaxSpd;
	double fElevation;
}DMSG_HMI_THREATDICISION;

class DMSG_HMI_THREATDICISIONTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_THREATDICISION);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_THREATDICISION");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cEngageType", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTrackIdentity", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fMinRange", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fMaxRange", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fMinBearing", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fMaxBearing", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fMinSpd", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fMaxSpd", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fElevation", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_WEAPONRANGE{
	char cWeaponID;
	uint16_t sAirMinRange;
	uint16_t sAirMaxRange;
	uint16_t sMinRange;
	uint16_t sMaxRange;
	uint16_t sMaxFireRate;
	uint16_t sMaxInventory;
}DMSG_HMI_WEAPONRANGE;

class DMSG_HMI_WEAPONRANGETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_WEAPONRANGE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_WEAPONRANGE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cWeaponID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("sAirMinRange", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("sAirMaxRange", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("sMinRange", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("sMaxRange", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("sMaxFireRate", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("sMaxInventory", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_SENSORRANGE{
	char cSensorID;
	uint16_t sAirMinRange;
	uint16_t sAirMaxRange;
	uint16_t sMinRange;
	uint16_t sMaxRange;
	uint16_t sAntenna;
	uint16_t sFrequency;
	uint16_t sPulsePeriod;
	uint16_t sPulseWidth;
}DMSG_HMI_SENSORRANGE;

class DMSG_HMI_SENSORRANGETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_SENSORRANGE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_SENSORRANGE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cSensorID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("sAirMinRange", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("sAirMaxRange", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("sMinRange", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("sMaxRange", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("sAntenna", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("sFrequency", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("sPulsePeriod", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("sPulseWidth", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_ENGAGEADVICEMODIFY{
	TrkNoSys trkNo;
	char cEngageType;
	char cTrackRdrID;
	char cRdrType;
	char cChannelID;
	char cWeaponID;
	char cConsoleID;
}DMSG_HMI_ENGAGEADVICEMODIFY;

class DMSG_HMI_ENGAGEADVICEMODIFYTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_ENGAGEADVICEMODIFY);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_ENGAGEADVICEMODIFY");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cEngageType", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTrackRdrID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cRdrType", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cChannelID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cWeaponID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cConsoleID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_CLEARENGAGEASSIGN{
	char cEngageType;
	TrkNoSys trkNo;
	char cReleaseType;
	char cTrackRdrID;
	char cRdrType;
	char cChannelID;
	char cWeaponID;
	char cConsoleID;
	char bUnit;
	char cUnitID;
}DMSG_HMI_CLEARENGAGEASSIGN;

class DMSG_HMI_CLEARENGAGEASSIGNTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_CLEARENGAGEASSIGN);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_CLEARENGAGEASSIGN");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cEngageType", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cReleaseType", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTrackRdrID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cRdrType", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cChannelID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cWeaponID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cConsoleID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("bUnit", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cUnitID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_THREATWEIGHT{
	TrkNoSys trkNo;
	char cWeight;
}DMSG_HMI_THREATWEIGHT;

class DMSG_HMI_THREATWEIGHTTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_THREATWEIGHT);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_THREATWEIGHT");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cWeight", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_DEFENSEMODE{
	char cDefenseMode;
}DMSG_HMI_DEFENSEMODE;

class DMSG_HMI_DEFENSEMODETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_DEFENSEMODE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_DEFENSEMODE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cDefenseMode", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_FIREPERMIT{
	char cWeaponID;
	char cFire;
}DMSG_HMI_FIREPERMIT;

class DMSG_HMI_FIREPERMITTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_FIREPERMIT);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_FIREPERMIT");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cWeaponID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cFire", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_ENGAGECANCEL{
	uint16_t AssignNum;
}DMSG_HMI_ENGAGECANCEL;

class DMSG_HMI_ENGAGECANCELTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_ENGAGECANCEL);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_ENGAGECANCEL");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("AssignNum", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_HITEVALUATIONSET{
	TrkNoSys trkNo;
	uint16_t AssignNum;
	char cKillResult;
}DMSG_HMI_HITEVALUATIONSET;

class DMSG_HMI_HITEVALUATIONSETTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_HITEVALUATIONSET);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_HITEVALUATIONSET");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("AssignNum", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cKillResult", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_ASSIGNCONSOLE{
	char cConsoleID;
	char byTube;
	char byTubeNum;
}DMSG_HMI_ASSIGNCONSOLE;

class DMSG_HMI_ASSIGNCONSOLETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_ASSIGNCONSOLE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_ASSIGNCONSOLE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cConsoleID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byTube", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byTubeNum", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_GUIDEDWEAPONPERMIT{
	char cConsoleID;
	char cTubeID;
	char byFireOk;
}DMSG_HMI_GUIDEDWEAPONPERMIT;

class DMSG_HMI_GUIDEDWEAPONPERMITTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_GUIDEDWEAPONPERMIT);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_GUIDEDWEAPONPERMIT");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cConsoleID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTubeID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byFireOk", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_ASSIGNTUBE{
	char cConsoleID;
	TrkNoSys trkNo;
	char byTube;
	char byTubeNum;
}DMSG_HMI_ASSIGNTUBE;

class DMSG_HMI_ASSIGNTUBETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_ASSIGNTUBE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_ASSIGNTUBE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cConsoleID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byTube", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byTubeNum", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_ENGAGEPLANSET{
	char cEngagePlanCtrl;
	TrkNoSys trkNo;
}DMSG_HMI_ENGAGEPLANSET;

class DMSG_HMI_ENGAGEPLANSETTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_ENGAGEPLANSET);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_ENGAGEPLANSET");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cEngagePlanCtrl", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_FIREPERMITKEYSTATE{
	char cFirePermitKey;
}DMSG_HMI_FIREPERMITKEYSTATE;

class DMSG_HMI_FIREPERMITKEYSTATETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_FIREPERMITKEYSTATE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_FIREPERMITKEYSTATE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cFirePermitKey", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_FIREPERMITBTNSTATE{
	char cFirePermitBtn;
}DMSG_HMI_FIREPERMITBTNSTATE;

class DMSG_HMI_FIREPERMITBTNSTATETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_FIREPERMITBTNSTATE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_FIREPERMITBTNSTATE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cFirePermitBtn", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_FIRECMD{
	char byConsoleID;
	char byTubeNum;
	char byLinkTubeNum;
	char byTubeType;
	char byFirectrl;
}DMSG_HMI_FIRECMD;

class DMSG_HMI_FIRECMDTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_FIRECMD);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_FIRECMD");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("byConsoleID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byTubeNum", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byLinkTubeNum", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byTubeType", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byFirectrl", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_ENGAGEASSIGNCMD{
	TrkNoSys trkNo;
	int32_t nAssignmentPlanID;
}DMSG_HMI_ENGAGEASSIGNCMD;

class DMSG_HMI_ENGAGEASSIGNCMDTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_ENGAGEASSIGNCMD);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_ENGAGEASSIGNCMD");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nAssignmentPlanID", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_FIRINGCMD{
	uint32_t trkNo;
	char cWeaponID;
	char cFireCommand;
}DMSG_HMI_FIRINGCMD;

class DMSG_HMI_FIRINGCMDTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_FIRINGCMD);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_FIRINGCMD");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cWeaponID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cFireCommand", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_EC_ENGAGEDEL{
	TrkNoSys trkNo;
	uint16_t AssignNum;
}DMSG_EC_ENGAGEDEL;

class DMSG_EC_ENGAGEDELTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_EC_ENGAGEDEL);
			fooTS->register_type(fooTS,p_Participant,"DMSG_EC_ENGAGEDEL");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("AssignNum", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_MANUALENGAGEASSIGN{
	char cEngageType;
	TrkNoSys trkNo;
	char cTrackRdrID;
	char cRdrType;
	char cChannelID;
	char cWeaponID;
	char cConsoleID;
	time1 EngageTime[6];
}DMSG_HMI_MANUALENGAGEASSIGN;

class DMSG_HMI_MANUALENGAGEASSIGNTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_MANUALENGAGEASSIGN);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_MANUALENGAGEASSIGN");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cEngageType", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTrackRdrID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cRdrType", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cChannelID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cWeaponID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cConsoleID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("EngageTime", DDS_STRING_TYPE,sizeof(time1)*6);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_EMERGENCYFIRE{
	TrkNoSys trkNo;
	char weapon_id;
}DMSG_HMI_EMERGENCYFIRE;

class DMSG_HMI_EMERGENCYFIRETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_EMERGENCYFIRE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_EMERGENCYFIRE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("weapon_id", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_SAMTARGETDESIG{
	int32_t nSysTrackNum;
	char byMissileCnt;
	char byAttackMode;
	char byLaunchMode;
	char byAttackType;
	char byAttackTimeType;
	char byAttackTimeHour;
	char byAttackTimeMin;
	char byEngagementMode;
	char byEngagementCommand;
	char byPositionValid;
	double dLat;
	double dLon;
	char byBearingValid;
	double fBearing;
	char byRangeValid;
	double fRange;
	char byCourseValid;
	double fCourse;
	char bySpeedValid;
	double fSpeed;
	char byTargetForm;
	char byTargetType;
	char byDetectSource;
	char byPlatform[10];
}DMSG_HMI_SAMTARGETDESIG;

class DMSG_HMI_SAMTARGETDESIGTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_SAMTARGETDESIG);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_SAMTARGETDESIG");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("nSysTrackNum", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byMissileCnt", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byAttackMode", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byLaunchMode", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byAttackType", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byAttackTimeType", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byAttackTimeHour", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byAttackTimeMin", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byEngagementMode", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byEngagementCommand", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byPositionValid", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dLat", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dLon", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byBearingValid", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fBearing", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byRangeValid", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fRange", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byCourseValid", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fCourse", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("bySpeedValid", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fSpeed", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byTargetForm", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byTargetType", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byDetectSource", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byPlatform", DDS_CHARACTER_TYPE,sizeof(char)*10);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_EC_GUIDEDWEAPONPERMIT{
	char byTubeNum;
	char byFireOk;
}DMSG_EC_GUIDEDWEAPONPERMIT;

class DMSG_EC_GUIDEDWEAPONPERMITTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_EC_GUIDEDWEAPONPERMIT);
			fooTS->register_type(fooTS,p_Participant,"DMSG_EC_GUIDEDWEAPONPERMIT");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("byTubeNum", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byFireOk", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_TRRTRACKINGCMD{
	TrkNoSys trkNo;
	char byTrackingStatus;
	double dBearing;
	double dElevation;
	double dDistance;
}DMSG_HMI_TRRTRACKINGCMD;

class DMSG_HMI_TRRTRACKINGCMDTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_TRRTRACKINGCMD);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_TRRTRACKINGCMD");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byTrackingStatus", DDS_CHARACTER_TYPE,sizeof(char));
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

typedef struct DMSG_HMI_EOTSSUBTRACKINGSET{
	TrkNoSys trkNo;
	char bySubTracking;
	double dBearing;
	double dAltitude;
	char bySubTrackingSensor;
}DMSG_HMI_EOTSSUBTRACKINGSET;

class DMSG_HMI_EOTSSUBTRACKINGSETTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_EOTSSUBTRACKINGSET);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_EOTSSUBTRACKINGSET");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("bySubTracking", DDS_CHARACTER_TYPE,sizeof(char));
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
		{
			dds_parameter_t *p_para = get_new_parameter("bySubTrackingSensor", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_TDSRTWSTARGETDESIG{
	TrkNoSys trkNo;
	char byTrackingStatus;
	char TrackingChannel;
	double dPosX;
	double dPosY;
	double dPosZ;
}DMSG_HMI_TDSRTWSTARGETDESIG;

class DMSG_HMI_TDSRTWSTARGETDESIGTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_TDSRTWSTARGETDESIG);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_TDSRTWSTARGETDESIG");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byTrackingStatus", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("TrackingChannel", DDS_CHARACTER_TYPE,sizeof(char));
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

typedef struct DMSG_HMISUB_ENGAGECANCEL{
	TrkNoSys trkNo;
	char byTubeID;
	char byTube;
}DMSG_HMISUB_ENGAGECANCEL;

class DMSG_HMISUB_ENGAGECANCELTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMISUB_ENGAGECANCEL);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMISUB_ENGAGECANCEL");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byTubeID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byTube", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_EC_SUBENGAGEDEL{
	TrkNoSys trkNo;
	char byTubeID;
	char byTube;
}DMSG_EC_SUBENGAGEDEL;

class DMSG_EC_SUBENGAGEDELTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_EC_SUBENGAGEDEL);
			fooTS->register_type(fooTS,p_Participant,"DMSG_EC_SUBENGAGEDEL");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byTubeID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byTube", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_FIREMODE{
	char cMode;
}DMSG_HMI_FIREMODE;

class DMSG_HMI_FIREMODETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_FIREMODE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_FIREMODE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cMode", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_ASSIGNSLTSTUBE{
	char cTubeID;
	char cTubeDirection;
}DMSG_HMI_ASSIGNSLTSTUBE;

class DMSG_HMI_ASSIGNSLTSTUBETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_ASSIGNSLTSTUBE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_ASSIGNSLTSTUBE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cTubeID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTubeDirection", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_TEWA_ENGAGEADVICEDEL{
	TrkNoSys trkNo;
}DMSG_TEWA_ENGAGEADVICEDEL;

class DMSG_TEWA_ENGAGEADVICEDELTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_TEWA_ENGAGEADVICEDEL);
			fooTS->register_type(fooTS,p_Participant,"DMSG_TEWA_ENGAGEADVICEDEL");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_TEWA_FASTRESPONSECHANNEL{
	char cEngageType;
	TrkNoSys trkNo;
	char cTrackRdrID;
	char cChannelID;
	char cWeaponID;
	char cConsoleID;
}DMSG_TEWA_FASTRESPONSECHANNEL;

class DMSG_TEWA_FASTRESPONSECHANNELTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_TEWA_FASTRESPONSECHANNEL);
			fooTS->register_type(fooTS,p_Participant,"DMSG_TEWA_FASTRESPONSECHANNEL");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cEngageType", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTrackRdrID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cChannelID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cWeaponID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cConsoleID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_TEWA_ENGAGEADVICE{
	char cEngageType;
	TrkNoSys trkNo;
	char cEngageAvailability;
	char cTrackRdrID;
	char cChannelID;
	char cWeaponID;
	char cConsoleID;
	char cPriority;
	time1 EngageTime[6];
}DMSG_TEWA_ENGAGEADVICE;

class DMSG_TEWA_ENGAGEADVICETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_TEWA_ENGAGEADVICE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_TEWA_ENGAGEADVICE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cEngageType", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cEngageAvailability", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTrackRdrID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cChannelID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cWeaponID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cConsoleID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cPriority", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("EngageTime", DDS_STRING_TYPE,sizeof(time1)*6);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_TEWA_THREATDEL{
	TrkNoSys trkNo;
}DMSG_TEWA_THREATDEL;

class DMSG_TEWA_THREATDELTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_TEWA_THREATDEL);
			fooTS->register_type(fooTS,p_Participant,"DMSG_TEWA_THREATDEL");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_TEWA_AIRTHREATEVALUATION{
	TrkNoSys trkNo;
	char cEngageType;
	char cPriority;
	uint16_t sScore;
	uint16_t sWeight;
	uint16_t sTimeToGo;
	char cEngageAvailability;
}DMSG_TEWA_AIRTHREATEVALUATION;

class DMSG_TEWA_AIRTHREATEVALUATIONTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_TEWA_AIRTHREATEVALUATION);
			fooTS->register_type(fooTS,p_Participant,"DMSG_TEWA_AIRTHREATEVALUATION");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cEngageType", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cPriority", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("sScore", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("sWeight", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("sTimeToGo", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cEngageAvailability", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_TEWA_SHIPTHREATEVALUATION{
	TrkNoSys trkNo;
	char cEngageType;
	char cPriority;
	double fMaxEffectiveRange;
	uint16_t sWeaponCapability[10];
	double fRange;
	char cEngageAvailability;
}DMSG_TEWA_SHIPTHREATEVALUATION;

class DMSG_TEWA_SHIPTHREATEVALUATIONTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_TEWA_SHIPTHREATEVALUATION);
			fooTS->register_type(fooTS,p_Participant,"DMSG_TEWA_SHIPTHREATEVALUATION");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cEngageType", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cPriority", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fMaxEffectiveRange", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("sWeaponCapability", DDS_SHORT_TYPE,sizeof(int16_t)*10);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fRange", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cEngageAvailability", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_TEWA_SUBTHREATEVALUATION{
	TrkNoSys trkNo;
	char cEngageType;
	char cPriority;
	char cThreatType;
	double fRange;
	double fDoppler;
	uint16_t sIdentity;
	char cEngageAvailability;
	double fBearing;
	uint32_t nFirstOccurenceTime;
}DMSG_TEWA_SUBTHREATEVALUATION;

class DMSG_TEWA_SUBTHREATEVALUATIONTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_TEWA_SUBTHREATEVALUATION);
			fooTS->register_type(fooTS,p_Participant,"DMSG_TEWA_SUBTHREATEVALUATION");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cEngageType", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cPriority", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cThreatType", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fRange", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fDoppler", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("sIdentity", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cEngageAvailability", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fBearing", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nFirstOccurenceTime", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_TEWA_ENGAGEPOSSIBILITY{
	char TBD;
}DMSG_TEWA_ENGAGEPOSSIBILITY;

class DMSG_TEWA_ENGAGEPOSSIBILITYTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_TEWA_ENGAGEPOSSIBILITY);
			fooTS->register_type(fooTS,p_Participant,"DMSG_TEWA_ENGAGEPOSSIBILITY");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("TBD", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_TEWA_SWSTATE{
	char cSoftwareState;
}DMSG_TEWA_SWSTATE;

class DMSG_TEWA_SWSTATETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_TEWA_SWSTATE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_TEWA_SWSTATE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cSoftwareState", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_TEWA_TORPEDOALERT{
	TrkNoSys trkNo;
	char bAlert;
}DMSG_TEWA_TORPEDOALERT;

class DMSG_TEWA_TORPEDOALERTTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_TEWA_TORPEDOALERT);
			fooTS->register_type(fooTS,p_Participant,"DMSG_TEWA_TORPEDOALERT");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("bAlert", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_TEWA_DIRECTENGAGEADVICE{
	int32_t nWeaponID;
	int32_t nTrackRadarID;
	int16_t sRadarType;
	int32_t nChannelID;
	double dLat;
	double dLong;
	double dAlt;
	uint16_t wEngagement_Availability;
}DMSG_TEWA_DIRECTENGAGEADVICE;

class DMSG_TEWA_DIRECTENGAGEADVICETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_TEWA_DIRECTENGAGEADVICE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_TEWA_DIRECTENGAGEADVICE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("nWeaponID", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nTrackRadarID", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("sRadarType", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nChannelID", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dLat", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dLong", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dAlt", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("wEngagement_Availability", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_TEWA_SENSORWEAPONREQ{
	int32_t nWeaponID;
	int32_t nSensorID;
}DMSG_TEWA_SENSORWEAPONREQ;

class DMSG_TEWA_SENSORWEAPONREQTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_TEWA_SENSORWEAPONREQ);
			fooTS->register_type(fooTS,p_Participant,"DMSG_TEWA_SENSORWEAPONREQ");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("nWeaponID", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nSensorID", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_EC_HITEVALUATIONSRESULT{
	TrkNoSys trkNo;
	char cKillResult;
}DMSG_EC_HITEVALUATIONSRESULT;

class DMSG_EC_HITEVALUATIONSRESULTTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_EC_HITEVALUATIONSRESULT);
			fooTS->register_type(fooTS,p_Participant,"DMSG_EC_HITEVALUATIONSRESULT");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cKillResult", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_EC_ENGAGEINFO{
	char cEngageType;
	TrkNoSys trkNo;
	uint16_t assignNum;
	char cTrackRdrID;
	char cRdrType;
	char cChannelID;
	char cWeaponID;
	char cConsoleID;
	char cEngageInfo;
	time1 EngageTime[6];
}DMSG_EC_ENGAGEINFO;

class DMSG_EC_ENGAGEINFOTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_EC_ENGAGEINFO);
			fooTS->register_type(fooTS,p_Participant,"DMSG_EC_ENGAGEINFO");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cEngageType", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("assignNum", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTrackRdrID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cRdrType", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cChannelID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cWeaponID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cConsoleID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cEngageInfo", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("EngageTime", DDS_STRING_TYPE,sizeof(time1)*6);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_EC_ENGAGEASSIGN{
	char cEngageType;
	TrkNoSys trkNo;
	uint16_t assignNum;
	char cTrackRdrID;
	char cRdrType;
	char cChannelID;
	char cWeaponID;
	char cConsoleID;
	time1 EngageTime[6];
	double dLatitude;
	double dLongitude;
	double dAltitude;
	double fRange;
	double fBearing;
}DMSG_EC_ENGAGEASSIGN;

class DMSG_EC_ENGAGEASSIGNTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_EC_ENGAGEASSIGN);
			fooTS->register_type(fooTS,p_Participant,"DMSG_EC_ENGAGEASSIGN");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cEngageType", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("assignNum", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTrackRdrID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cRdrType", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cChannelID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cWeaponID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cConsoleID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("EngageTime", DDS_STRING_TYPE,sizeof(time1)*6);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dLatitude", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dLongitude", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dAltitude", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fRange", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fBearing", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_EC_ENGAGEPLANSET{
	char cEngagePlanCtrl;
	TrkNoSys trkNo;
}DMSG_EC_ENGAGEPLANSET;

class DMSG_EC_ENGAGEPLANSETTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_EC_ENGAGEPLANSET);
			fooTS->register_type(fooTS,p_Participant,"DMSG_EC_ENGAGEPLANSET");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cEngagePlanCtrl", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_EC_FIREPERMITKEYSTATE{
	char cFirePermitKey;
}DMSG_EC_FIREPERMITKEYSTATE;

class DMSG_EC_FIREPERMITKEYSTATETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_EC_FIREPERMITKEYSTATE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_EC_FIREPERMITKEYSTATE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cFirePermitKey", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_EC_ENGAGESTATE{
	TrkNoSys trkNo;
	char byTube;
	char byTubeNum;
	char byEngageState;
}DMSG_EC_ENGAGESTATE;

class DMSG_EC_ENGAGESTATETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_EC_ENGAGESTATE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_EC_ENGAGESTATE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byTube", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byTubeNum", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byEngageState", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_EC_SWSTATE{
	char cSoftwareState;
}DMSG_EC_SWSTATE;

class DMSG_EC_SWSTATETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_EC_SWSTATE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_EC_SWSTATE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cSoftwareState", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_EC_WEAPONCTRLMODE{
	char cControlMode;
}DMSG_EC_WEAPONCTRLMODE;

class DMSG_EC_WEAPONCTRLMODETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_EC_WEAPONCTRLMODE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_EC_WEAPONCTRLMODE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cControlMode", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_EC_HORTUBEASSIGN{
	char cConsoleID;
	TrkNoSys trkNo;
	char byTubeNum;
}DMSG_EC_HORTUBEASSIGN;

class DMSG_EC_HORTUBEASSIGNTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_EC_HORTUBEASSIGN);
			fooTS->register_type(fooTS,p_Participant,"DMSG_EC_HORTUBEASSIGN");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cConsoleID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byTubeNum", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_EC_VERTUBEASSIGN{
	char cConsoleID;
	TrkNoSys trkNo;
	char byLauncherNum;
}DMSG_EC_VERTUBEASSIGN;

class DMSG_EC_VERTUBEASSIGNTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_EC_VERTUBEASSIGN);
			fooTS->register_type(fooTS,p_Participant,"DMSG_EC_VERTUBEASSIGN");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cConsoleID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byLauncherNum", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_EC_WEAPONFIRESTATE{
	char cWeaponID;
	char cFireState;
}DMSG_EC_WEAPONFIRESTATE;

class DMSG_EC_WEAPONFIRESTATETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_EC_WEAPONFIRESTATE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_EC_WEAPONFIRESTATE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cWeaponID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cFireState", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_EC_FIRECMD{
	char cConsoleID;
	char cLauncherNum;
	char cLinkLauncherNum;
	char cFireCmd;
}DMSG_EC_FIRECMD;

class DMSG_EC_FIRECMDTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_EC_FIRECMD);
			fooTS->register_type(fooTS,p_Participant,"DMSG_EC_FIRECMD");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cConsoleID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cLauncherNum", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cLinkLauncherNum", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cFireCmd", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_TACTICORDER{
	int32_t nTacticOrder;
}DMSG_HMI_TACTICORDER;

class DMSG_HMI_TACTICORDERTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_TACTICORDER);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_TACTICORDER");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("nTacticOrder", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_DCOYLAUNCHMODE{
	int32_t nDecoyLaunchMode;
}DMSG_HMI_DCOYLAUNCHMODE;

class DMSG_HMI_DCOYLAUNCHMODETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_DCOYLAUNCHMODE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_DCOYLAUNCHMODE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("nDecoyLaunchMode", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_DCOYTUBESET{
	char cLauncherID;
	char cTubeID;
}DMSG_HMI_DCOYTUBESET;

class DMSG_HMI_DCOYTUBESETTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_DCOYTUBESET);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_DCOYTUBESET");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cLauncherID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTubeID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_MISSILECTRL{
	char byLauncherNum;
	char byCtrlCmd;
}DMSG_HMI_MISSILECTRL;

class DMSG_HMI_MISSILECTRLTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_MISSILECTRL);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_MISSILECTRL");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("byLauncherNum", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byCtrlCmd", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_MISSILEENGAGEPLAN{
	char cConsoleID;
	char byMissileNum;
	char cTubeID;
	int32_t nWpCnt;
	TrkNoSys trkNo;
	double dWP1Lat;
	double dWP1Lon;
	double dWP2Lat;
	double dWP2Lon;
	double dWP3Lat;
	double dWP3Lon;
	double dWP4Lat;
	double dWP4Lon;
	double dWP5Lat;
	double dWP5Lon;
	double dWP6Lat;
	double dWP6Lon;
	double dWP7Lat;
	double dWP7Lon;
	double dWP8Lat;
	double dWP8Lon;
	int32_t nStaccatoVolley;
	int32_t nAttackMissileCnt;
	int32_t nAttackMode;
	int32_t nSearchType;
	int32_t nAttackType;
}DMSG_HMI_MISSILEENGAGEPLAN;

class DMSG_HMI_MISSILEENGAGEPLANTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_MISSILEENGAGEPLAN);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_MISSILEENGAGEPLAN");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cConsoleID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byMissileNum", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTubeID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nWpCnt", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dWP1Lat", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dWP1Lon", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dWP2Lat", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dWP2Lon", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dWP3Lat", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dWP3Lon", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dWP4Lat", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dWP4Lon", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dWP5Lat", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dWP5Lon", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dWP6Lat", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dWP6Lon", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dWP7Lat", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dWP7Lon", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dWP8Lat", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dWP8Lon", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nStaccatoVolley", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nAttackMissileCnt", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nAttackMode", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nSearchType", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nAttackType", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_TORPEDOENGAGEPLAN{
	TrkNoSys trkNo;
	char cTargetType;
	char cInductionMode;
	char cGuidanceMode;
	int32_t nRouteNum;
	double fRouteLat;
	double fRouteLon;
	double fRouteDepth;
	double fRouteSpeed;
	double fTorpDepth;
	double fDounLimitDepth;
	double fUpLimitDepth;
	double fRunDepth;
	double fPreOderSpeed;
	double fDetectionRange;
	double fDefaultRange;
	double fSearchSector;
	double fLinkDetectionRange;
	double fLinkDefaultRange;
	double fLinkSearchSector;
	char bSonarOder;
	char bRouteSensorOder;
	char bHitEvasionSet;
	char bTropLinkFire;
	double fHorLinkOffset;
	double fVerLinkOffset;
	int32_t nTorpExpectFiretimeMin;
	int32_t nTorpExpectFiretimeSec;
	int32_t nTorpRuntimeMin;
	int32_t nTorpRuntimeSec;
	char cTubeID;
	char cConsoleID;
	char bLinkedLaunch;
	int32_t nLinkedDistance;
	int32_t nLinkedTime;
	int32_t n2ndTubeNum;
}DMSG_HMI_TORPEDOENGAGEPLAN;

class DMSG_HMI_TORPEDOENGAGEPLANTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_TORPEDOENGAGEPLAN);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_TORPEDOENGAGEPLAN");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTargetType", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cInductionMode", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cGuidanceMode", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nRouteNum", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fRouteLat", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fRouteLon", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fRouteDepth", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fRouteSpeed", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fTorpDepth", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fDounLimitDepth", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fUpLimitDepth", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fRunDepth", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fPreOderSpeed", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fDetectionRange", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fDefaultRange", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fSearchSector", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fLinkDetectionRange", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fLinkDefaultRange", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fLinkSearchSector", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("bSonarOder", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("bRouteSensorOder", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("bHitEvasionSet", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("bTropLinkFire", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fHorLinkOffset", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fVerLinkOffset", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nTorpExpectFiretimeMin", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nTorpExpectFiretimeSec", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nTorpRuntimeMin", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nTorpRuntimeSec", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTubeID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cConsoleID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("bLinkedLaunch", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nLinkedDistance", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nLinkedTime", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("n2ndTubeNum", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_RESERVEDENGAGEPLAN{
	TrkNoSys trkNo;
	char cTargetType;
	char cInductionMode;
	char cGuidanceMode;
	int32_t nRouteNum;
	double fRouteLat;
	double fRouteLon;
	double fRouteDepth;
	double fRouteSpeed;
	double fTorpDepth;
	double fDounLimitDepth;
	double fUpLimitDepth;
	double fRunDepth;
	double fPreOderSpeed;
	double fDetectionRange;
	double fDefaultRange;
	double fSearchSector;
	double fLinkDetectionRange;
	double fLinkDefaultRange;
	double fLinkSearchSector;
	char bSonarOder;
	char bRouteSensorOder;
	char bHitEvasionSet;
	char bTropLinkFire;
	double fHorLinkOffset;
	double fVerLinkOffset;
	int32_t nTorpExpectFiretimeMin;
	int32_t nTorpExpectFiretimeSec;
	int32_t nTorpRuntimeMin;
	int32_t nTorpRuntimeSec;
	char cTubeID;
	char cConsoleID;
	char bLinkedLaunch;
	int32_t nLinkedDistance;
	int32_t nLinkedTime;
	int32_t n2ndTubeNum;
}DMSG_HMI_RESERVEDENGAGEPLAN;

class DMSG_HMI_RESERVEDENGAGEPLANTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_RESERVEDENGAGEPLAN);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_RESERVEDENGAGEPLAN");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTargetType", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cInductionMode", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cGuidanceMode", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nRouteNum", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fRouteLat", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fRouteLon", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fRouteDepth", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fRouteSpeed", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fTorpDepth", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fDounLimitDepth", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fUpLimitDepth", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fRunDepth", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fPreOderSpeed", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fDetectionRange", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fDefaultRange", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fSearchSector", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fLinkDetectionRange", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fLinkDefaultRange", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fLinkSearchSector", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("bSonarOder", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("bRouteSensorOder", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("bHitEvasionSet", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("bTropLinkFire", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fHorLinkOffset", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fVerLinkOffset", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nTorpExpectFiretimeMin", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nTorpExpectFiretimeSec", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nTorpRuntimeMin", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nTorpRuntimeSec", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTubeID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cConsoleID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("bLinkedLaunch", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nLinkedDistance", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nLinkedTime", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("n2ndTubeNum", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_TORPCTRL{
	char cTubeID;
	char cTorpCtrl;
}DMSG_HMI_TORPCTRL;

class DMSG_HMI_TORPCTRLTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_TORPCTRL);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_TORPCTRL");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cTubeID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTorpCtrl", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_SHOOTMODIFY{
	double dBearingError;
	int32_t nDistanceError;
}DMSG_HMI_SHOOTMODIFY;

class DMSG_HMI_SHOOTMODIFYTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_SHOOTMODIFY);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_SHOOTMODIFY");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("dBearingError", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nDistanceError", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_CORRECT{
	double dBearing;
	double dAltitude;
}DMSG_HMI_CORRECT;

class DMSG_HMI_CORRECTTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_CORRECT);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_CORRECT");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
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

typedef struct DMSG_HMI_SENSORWEAPONPOS{
	char bySensorCategory;
	char bySensorPos;
	char byWeaponPos;
}DMSG_HMI_SENSORWEAPONPOS;

class DMSG_HMI_SENSORWEAPONPOSTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_SENSORWEAPONPOS);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_SENSORWEAPONPOS");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("bySensorCategory", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("bySensorPos", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byWeaponPos", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_BLINDNESSFIRE{
	double dPosX;
	double dPosY;
	double dPosZ;
}DMSG_HMI_BLINDNESSFIRE;

class DMSG_HMI_BLINDNESSFIRETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_BLINDNESSFIRE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_BLINDNESSFIRE");
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

typedef struct DMSG_HMI_DIRECTFIRE{
	double dLat;
	double dLong;
	double dAlt;
}DMSG_HMI_DIRECTFIRE;

class DMSG_HMI_DIRECTFIRETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_DIRECTFIRE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_DIRECTFIRE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("dLat", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dLong", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dAlt", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_TORPMANUALWAYPOINT{
	char byTorpNum;
	int32_t nWpCnt;
	TrkNoSys trkNo;
	double dWP1Lat;
	double dWP1Lon;
	double dWP2Lat;
	double dWP2Lon;
	double dWP3Lat;
	double dWP3Lon;
	double dWP4Lat;
	double dWP4Lon;
	double dWP5Lat;
	double dWP5Lon;
	double dWP6Lat;
	double dWP6Lon;
	double dWP7Lat;
	double dWP7Lon;
	double dWP8Lat;
	double dWP8Lon;
	int32_t nStaccatoVolley;
	char cTubeID;
	char cConsoleID;
}DMSG_HMI_TORPMANUALWAYPOINT;

class DMSG_HMI_TORPMANUALWAYPOINTTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_TORPMANUALWAYPOINT);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_TORPMANUALWAYPOINT");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("byTorpNum", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nWpCnt", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dWP1Lat", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dWP1Lon", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dWP2Lat", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dWP2Lon", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dWP3Lat", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dWP3Lon", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dWP4Lat", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dWP4Lon", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dWP5Lat", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dWP5Lon", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dWP6Lat", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dWP6Lon", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dWP7Lat", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dWP7Lon", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dWP8Lat", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dWP8Lon", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nStaccatoVolley", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTubeID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cConsoleID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_TORPBREAKENGAGE{
	char byTorpNum;
	char byAction;
}DMSG_HMI_TORPBREAKENGAGE;

class DMSG_HMI_TORPBREAKENGAGETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_TORPBREAKENGAGE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_TORPBREAKENGAGE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("byTorpNum", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byAction", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_RESERVEDCOPY{
	char cConsoleID;
	char cTubeID;
	char cCopy;
}DMSG_HMI_RESERVEDCOPY;

class DMSG_HMI_RESERVEDCOPYTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_RESERVEDCOPY);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_RESERVEDCOPY");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cConsoleID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTubeID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cCopy", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_TFC_FIRINGDATA{
	uint16_t nConsoleID;
	char byTorpNum;
	char bLinkedLaunch;
	double fTorpCommLine;
	double fShipCommLine;
	double fTorpCommLineMax;
	double fShipCommLineMax;
	int32_t nBattery;
	double fBatteryDistance;
	int32_t nTropFireMin;
	int32_t nTropFireSec;
	char TBD;
	int32_t nReAttackNum;
	double fAdviceCrs;
	double fHitRange;
	int32_t nHitTime;
	double fTgtObtainProbability;
	coordiHSys HitPt;
	coordiHSys AQPt;
	double fAQDistance;
	double fTorpDistance;
	double fExpcLat[4];
	double fExpcLon[4];
	double fExpcDepth[4];
	int32_t nPtCount;
	double fTorpRouteLat[1000];
	double fTorpRouteLon[1000];
	double fTorpRouteDepth[1000];
	int32_t nBatteryTime;
	int32_t nOwnShipWireTime;
	int32_t nTorpWireTime;
	double fRemainHitRange;
	char bReservedPlan;
	uint32_t nRunningTime;
}DMSG_TFC_FIRINGDATA;

class DMSG_TFC_FIRINGDATATypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_TFC_FIRINGDATA);
			fooTS->register_type(fooTS,p_Participant,"DMSG_TFC_FIRINGDATA");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("nConsoleID", DDS_SHORT_TYPE,sizeof(int16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byTorpNum", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("bLinkedLaunch", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fTorpCommLine", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fShipCommLine", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fTorpCommLineMax", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fShipCommLineMax", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nBattery", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fBatteryDistance", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nTropFireMin", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nTropFireSec", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("TBD", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nReAttackNum", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fAdviceCrs", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fHitRange", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nHitTime", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fTgtObtainProbability", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("HitPt", DDS_STRUCT_TYPE,sizeof(coordiHSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("AQPt", DDS_STRUCT_TYPE,sizeof(coordiHSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fAQDistance", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fTorpDistance", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fExpcLat", DDS_FLOAT_TYPE,sizeof(double)*4);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fExpcLon", DDS_FLOAT_TYPE,sizeof(double)*4);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fExpcDepth", DDS_FLOAT_TYPE,sizeof(double)*4);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nPtCount", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fTorpRouteLat", DDS_FLOAT_TYPE,sizeof(double)*1000);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fTorpRouteLon", DDS_FLOAT_TYPE,sizeof(double)*1000);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fTorpRouteDepth", DDS_FLOAT_TYPE,sizeof(double)*1000);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nBatteryTime", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nOwnShipWireTime", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nTorpWireTime", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fRemainHitRange", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("bReservedPlan", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nRunningTime", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_TFC_TORPSTATE{
	char byImpressedPower;
	char byFireSignal;
	char cTorpConnect;
	char cTorpSetState;
	double fTropCeiling;
	double fTropFloor;
}DMSG_TFC_TORPSTATE;

class DMSG_TFC_TORPSTATETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_TFC_TORPSTATE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_TFC_TORPSTATE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("byImpressedPower", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byFireSignal", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTorpConnect", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTorpSetState", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fTropCeiling", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fTropFloor", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_TFC_TORPMANEUVER{
	double fLat;
	double fLon;
	double fCourse;
	double fDepth;
	double fSpeed;
}DMSG_TFC_TORPMANEUVER;

class DMSG_TFC_TORPMANEUVERTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_TFC_TORPMANEUVER);
			fooTS->register_type(fooTS,p_Participant,"DMSG_TFC_TORPMANEUVER");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("fLat", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fLon", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fCourse", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fDepth", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fSpeed", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_TFC_CHECKRESULT{
	char byErr;
	char byPartState[16];
}DMSG_TFC_CHECKRESULT;

class DMSG_TFC_CHECKRESULTTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_TFC_CHECKRESULT);
			fooTS->register_type(fooTS,p_Participant,"DMSG_TFC_CHECKRESULT");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("byErr", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byPartState", DDS_CHARACTER_TYPE,sizeof(char)*16);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_TFC_INTERLOCK{
	char cDiscreteSig_Err;
	char cTargetAssignInfo_Err;
	char cBattlePlan_Data_Err;
	char cLimitDepth_Err;
	char cBattleSolution_Err;
	char cWeaponControl_Err;
	char cCommunication_Err;
	char cPower_Err;
	char cPreFire_Err;
	char cHorizonStatus_Err;
	char cHorizonControlStatus_Err;
	char cOwnshipSafe_Err;
	char cFirePermit_Key_Err;
	char cOtherWeapon_Fire;
	char cLinkWeapon_FireRady_Err;
	char cFireStep_Err;
	char cOverride;
}DMSG_TFC_INTERLOCK;

class DMSG_TFC_INTERLOCKTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_TFC_INTERLOCK);
			fooTS->register_type(fooTS,p_Participant,"DMSG_TFC_INTERLOCK");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cDiscreteSig_Err", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTargetAssignInfo_Err", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cBattlePlan_Data_Err", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cLimitDepth_Err", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cBattleSolution_Err", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cWeaponControl_Err", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cCommunication_Err", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cPower_Err", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cPreFire_Err", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cHorizonStatus_Err", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cHorizonControlStatus_Err", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cOwnshipSafe_Err", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cFirePermit_Key_Err", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cOtherWeapon_Fire", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cLinkWeapon_FireRady_Err", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cFireStep_Err", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cOverride", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_TFC_TORPSONAR{
	char cTropedoSonarState;
	char cSonarSignal[16];
}DMSG_TFC_TORPSONAR;

class DMSG_TFC_TORPSONARTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_TFC_TORPSONAR);
			fooTS->register_type(fooTS,p_Participant,"DMSG_TFC_TORPSONAR");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cTropedoSonarState", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cSonarSignal", DDS_CHARACTER_TYPE,sizeof(char)*16);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_TFC_TORPTARGET{
	char byTargetID;
	char byTargetType;
	double fTargetAltitude;
	double fTargetBearing;
	char bySonarBeam[16];
}DMSG_TFC_TORPTARGET;

class DMSG_TFC_TORPTARGETTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_TFC_TORPTARGET);
			fooTS->register_type(fooTS,p_Participant,"DMSG_TFC_TORPTARGET");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("byTargetID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byTargetType", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fTargetAltitude", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fTargetBearing", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("bySonarBeam", DDS_CHARACTER_TYPE,sizeof(char)*16);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_TFC_TORPEDOAVAILABILITY{
	char cState;
	char cTubeNum;
}DMSG_TFC_TORPEDOAVAILABILITY;

class DMSG_TFC_TORPEDOAVAILABILITYTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_TFC_TORPEDOAVAILABILITY);
			fooTS->register_type(fooTS,p_Participant,"DMSG_TFC_TORPEDOAVAILABILITY");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cState", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTubeNum", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_TFC_ENGAGESTATE{
	TrkNoSys trkNo;
	char cTubeNum;
	char cEngageState;
}DMSG_TFC_ENGAGESTATE;

class DMSG_TFC_ENGAGESTATETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_TFC_ENGAGESTATE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_TFC_ENGAGESTATE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTubeNum", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cEngageState", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_TFC_SWSTATE{
	char cSoftwareState;
}DMSG_TFC_SWSTATE;

class DMSG_TFC_SWSTATETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_TFC_SWSTATE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_TFC_SWSTATE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cSoftwareState", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_TFC_HLTCTRL{
	char byTubeNum;
	char byCtrlCmd;
}DMSG_TFC_HLTCTRL;

class DMSG_TFC_HLTCTRLTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_TFC_HLTCTRL);
			fooTS->register_type(fooTS,p_Participant,"DMSG_TFC_HLTCTRL");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("byTubeNum", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byCtrlCmd", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_MFC_SUMSTATE{
	char byPower;
	char byFireSig;
	char byFire;
}DMSG_MFC_SUMSTATE;

class DMSG_MFC_SUMSTATETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_MFC_SUMSTATE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_MFC_SUMSTATE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("byPower", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byFireSig", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byFire", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_MFC_FIRINGDATA{
	double dTgtLat;
	double dTgtLon;
	int32_t nFlightTime;
	double dFireAvailableLat;
	double dFireAvailableLon;
	double dAdvicedCrs;
	double dExpectFlightLat;
	double dExpectFlightLon;
	double dFlightLat;
	double dFlightLon;
}DMSG_MFC_FIRINGDATA;

class DMSG_MFC_FIRINGDATATypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_MFC_FIRINGDATA);
			fooTS->register_type(fooTS,p_Participant,"DMSG_MFC_FIRINGDATA");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("dTgtLat", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dTgtLon", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nFlightTime", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dFireAvailableLat", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dFireAvailableLon", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dAdvicedCrs", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dExpectFlightLat", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dExpectFlightLon", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dFlightLat", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dFlightLon", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_MFC_INTERLOCK{
	char cOverRideSet;
	char cDiscreteSig_Err;
	char cMissionPermit;
	char cSwitch_Err;
	char cPower_Err;
	char cFlightCrs_Err;
	char cPreFire_Err;
	char cVLTStatus_Err;
	char cFirePassWord_Err;
	char cShipSafeCondition_Err;
	char cFirePermit_Key_Err;
	char cFireStep_Err;
	char cLauncherNum;
}DMSG_MFC_INTERLOCK;

class DMSG_MFC_INTERLOCKTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_MFC_INTERLOCK);
			fooTS->register_type(fooTS,p_Participant,"DMSG_MFC_INTERLOCK");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cOverRideSet", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cDiscreteSig_Err", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cMissionPermit", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cSwitch_Err", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cPower_Err", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cFlightCrs_Err", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cPreFire_Err", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cVLTStatus_Err", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cFirePassWord_Err", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cShipSafeCondition_Err", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cFirePermit_Key_Err", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cFireStep_Err", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cLauncherNum", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_MFC_SAFETYSWITCHSTATE{
	char cLauncherNum;
	char cSwitchState;
}DMSG_MFC_SAFETYSWITCHSTATE;

class DMSG_MFC_SAFETYSWITCHSTATETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_MFC_SAFETYSWITCHSTATE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_MFC_SAFETYSWITCHSTATE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cLauncherNum", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cSwitchState", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_MFC_SUMTESTRESULT{
	char cErr;
}DMSG_MFC_SUMTESTRESULT;

class DMSG_MFC_SUMTESTRESULTTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_MFC_SUMTESTRESULT);
			fooTS->register_type(fooTS,p_Participant,"DMSG_MFC_SUMTESTRESULT");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cErr", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_MFC_ENGAGESTATE{
	TrkNoSys trkNo;
	char cTubeNum;
	char cEngageState;
}DMSG_MFC_ENGAGESTATE;

class DMSG_MFC_ENGAGESTATETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_MFC_ENGAGESTATE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_MFC_ENGAGESTATE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("trkNo", DDS_STRUCT_TYPE,sizeof(TrkNoSys));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTubeNum", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cEngageState", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_MFC_MISSILEAVAILABILITY{
	char cTubeNum;
	char cTubeState;
}DMSG_MFC_MISSILEAVAILABILITY;

class DMSG_MFC_MISSILEAVAILABILITYTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_MFC_MISSILEAVAILABILITY);
			fooTS->register_type(fooTS,p_Participant,"DMSG_MFC_MISSILEAVAILABILITY");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cTubeNum", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTubeState", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_MFC_SWSTATE{
	char cSoftwareState;
}DMSG_MFC_SWSTATE;

class DMSG_MFC_SWSTATETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_MFC_SWSTATE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_MFC_SWSTATE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cSoftwareState", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_MFC_COUNTDOWNSTATE{
	char cConsoleID;
	char cTubeNum;
	char byCountdown1;
	char byCountdown2;
	char byCountdown3;
	char byCountdown4;
	char byCountdown5;
	char byCountdown6;
	char byCountdown7;
	char byCountdown8;
}DMSG_MFC_COUNTDOWNSTATE;

class DMSG_MFC_COUNTDOWNSTATETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_MFC_COUNTDOWNSTATE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_MFC_COUNTDOWNSTATE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cConsoleID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTubeNum", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byCountdown1", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byCountdown2", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byCountdown3", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byCountdown4", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byCountdown5", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byCountdown6", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byCountdown7", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("byCountdown8", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_DFC_MANOEUVRE{
	double dManoeuvreTime[5];
	double dManoeuvreHeading[5];
	double dManoeuvreSpd[5];
	double dManoeuvreDepth[5];
}DMSG_DFC_MANOEUVRE;

class DMSG_DFC_MANOEUVRETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_DFC_MANOEUVRE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_DFC_MANOEUVRE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("dManoeuvreTime", DDS_FLOAT_TYPE,sizeof(double)*5);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dManoeuvreHeading", DDS_FLOAT_TYPE,sizeof(double)*5);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dManoeuvreSpd", DDS_FLOAT_TYPE,sizeof(double)*5);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dManoeuvreDepth", DDS_FLOAT_TYPE,sizeof(double)*5);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_DFC_TACTICINFO{
	int32_t nTacticListID;
	char chTacticName[20];
}DMSG_DFC_TACTICINFO;

class DMSG_DFC_TACTICINFOTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_DFC_TACTICINFO);
			fooTS->register_type(fooTS,p_Participant,"DMSG_DFC_TACTICINFO");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("nTacticListID", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("chTacticName", DDS_CHARACTER_TYPE,sizeof(char)*20);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_DFC_LOADING{
	char cLauncherID[49];
	char cTubeID[49];
	char cDecoyType[49];
	char cTubeState[49];
	char cAcouMode[49];
	int32_t nDecoySetDepth[49];
	char cMDMobileType[49];
	int32_t nDecoyLifeTime[49];
}DMSG_DFC_LOADING;

class DMSG_DFC_LOADINGTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_DFC_LOADING);
			fooTS->register_type(fooTS,p_Participant,"DMSG_DFC_LOADING");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cLauncherID", DDS_CHARACTER_TYPE,sizeof(char)*49);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTubeID", DDS_CHARACTER_TYPE,sizeof(char)*49);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cDecoyType", DDS_CHARACTER_TYPE,sizeof(char)*49);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTubeState", DDS_CHARACTER_TYPE,sizeof(char)*49);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cAcouMode", DDS_CHARACTER_TYPE,sizeof(char)*49);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nDecoySetDepth", DDS_INTEGER_TYPE,sizeof(int32_t)*49);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cMDMobileType", DDS_CHARACTER_TYPE,sizeof(char)*49);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nDecoyLifeTime", DDS_INTEGER_TYPE,sizeof(int32_t)*49);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_DFC_PREDICTPOS{
	int32_t nLaunchNum;
	char cLcDecoyType;
	double dLcPredictPosLat;
	double dLcPredictPosLon;
	int32_t nLcPredictDepth;
}DMSG_DFC_PREDICTPOS;

class DMSG_DFC_PREDICTPOSTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_DFC_PREDICTPOS);
			fooTS->register_type(fooTS,p_Participant,"DMSG_DFC_PREDICTPOS");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("nLaunchNum", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cLcDecoyType", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dLcPredictPosLat", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dLcPredictPosLon", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nLcPredictDepth", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_DFC_PERFORM{
	double dPerformLBound[8];
	double dPerformUBound[8];
	char cPerformLv[8];
	int32_t nPerformEff[8];
}DMSG_DFC_PERFORM;

class DMSG_DFC_PERFORMTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_DFC_PERFORM);
			fooTS->register_type(fooTS,p_Participant,"DMSG_DFC_PERFORM");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("dPerformLBound", DDS_FLOAT_TYPE,sizeof(double)*8);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dPerformUBound", DDS_FLOAT_TYPE,sizeof(double)*8);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cPerformLv", DDS_CHARACTER_TYPE,sizeof(char)*8);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nPerformEff", DDS_INTEGER_TYPE,sizeof(int32_t)*8);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_DFC_EXPECTROUTE{
	int32_t nLauncherID;
	int32_t nTubeID;
	double fExpecLat[100];
	double fExpecLon[100];
	double fExpecDepth[100];
}DMSG_DFC_EXPECTROUTE;

class DMSG_DFC_EXPECTROUTETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_DFC_EXPECTROUTE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_DFC_EXPECTROUTE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("nLauncherID", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nTubeID", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fExpecLat", DDS_FLOAT_TYPE,sizeof(double)*100);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fExpecLon", DDS_FLOAT_TYPE,sizeof(double)*100);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("fExpecDepth", DDS_FLOAT_TYPE,sizeof(double)*100);
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_DFC_SUBDCOYFIREPLAN{
	char cLauncherID;
	char cTubeID;
	char cDecoyType;
}DMSG_DFC_SUBDCOYFIREPLAN;

class DMSG_DFC_SUBDCOYFIREPLANTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_DFC_SUBDCOYFIREPLAN);
			fooTS->register_type(fooTS,p_Participant,"DMSG_DFC_SUBDCOYFIREPLAN");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cLauncherID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cTubeID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cDecoyType", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_DFC_ENGAGESTATE{
	char cLaunchDecoy;
}DMSG_DFC_ENGAGESTATE;

class DMSG_DFC_ENGAGESTATETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_DFC_ENGAGESTATE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_DFC_ENGAGESTATE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cLaunchDecoy", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_SELECTEDSENSOR{
	char cConsoleID;
	char cSensorNum;
}DMSG_HMI_SELECTEDSENSOR;

class DMSG_HMI_SELECTEDSENSORTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_SELECTEDSENSOR);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_SELECTEDSENSOR");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cConsoleID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cSensorNum", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_SELECTEDWEAPON{
	char cConsoleID;
	char cWeaponNum;
}DMSG_HMI_SELECTEDWEAPON;

class DMSG_HMI_SELECTEDWEAPONTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_SELECTEDWEAPON);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_SELECTEDWEAPON");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cConsoleID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cWeaponNum", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_PA_SENSORRANGERESULT{
	char cConsoleID;
	char cSensorNum;
	int32_t nResult;
}DMSG_PA_SENSORRANGERESULT;

class DMSG_PA_SENSORRANGERESULTTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_PA_SENSORRANGERESULT);
			fooTS->register_type(fooTS,p_Participant,"DMSG_PA_SENSORRANGERESULT");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cConsoleID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cSensorNum", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nResult", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_PA_WEAPONRANGERESULT{
	char cConsoleID;
	char cWeaponNum;
	int32_t nResult;
}DMSG_PA_WEAPONRANGERESULT;

class DMSG_PA_WEAPONRANGERESULTTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_PA_WEAPONRANGERESULT);
			fooTS->register_type(fooTS,p_Participant,"DMSG_PA_WEAPONRANGERESULT");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("cConsoleID", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cWeaponNum", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nResult", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_SMS_CONNECT{
	int32_t nID;
	char cIsConnect;
}DMSG_SMS_CONNECT;

class DMSG_SMS_CONNECTTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_SMS_CONNECT);
			fooTS->register_type(fooTS,p_Participant,"DMSG_SMS_CONNECT");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("nID", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cIsConnect", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_MMI_CONNECTREPLY{
	int32_t nID;
	char cConnectReply;
}DMSG_MMI_CONNECTREPLY;

class DMSG_MMI_CONNECTREPLYTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_MMI_CONNECTREPLY);
			fooTS->register_type(fooTS,p_Participant,"DMSG_MMI_CONNECTREPLY");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("nID", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("cConnectReply", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_SMS_INIT{
	char bInit;
}DMSG_SMS_INIT;

class DMSG_SMS_INITTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_SMS_INIT);
			fooTS->register_type(fooTS,p_Participant,"DMSG_SMS_INIT");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("bInit", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_SMS_DDSTEST{
	int32_t nRecvID;
	int32_t nSendID;
	char bcheck;
}DMSG_SMS_DDSTEST;

class DMSG_SMS_DDSTESTTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_SMS_DDSTEST);
			fooTS->register_type(fooTS,p_Participant,"DMSG_SMS_DDSTEST");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("nRecvID", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("nSendID", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("bcheck", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_HMI_SAVECYCLESET{
	uint32_t nSec;
}DMSG_HMI_SAVECYCLESET;

class DMSG_HMI_SAVECYCLESETTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_HMI_SAVECYCLESET);
			fooTS->register_type(fooTS,p_Participant,"DMSG_HMI_SAVECYCLESET");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("nSec", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

