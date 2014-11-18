#include <core.h>
#include <cpsdcps.h>
#include <dcps_func.h>

typedef struct DMSG_OSSMMI_SENSORSTATE{
	char gpsStatus;
	char gyroStatus;
	char emLogStatus;
	char anemometerStatus;
	char airStatus;
}DMSG_OSSMMI_SENSORSTATE;

class DMSG_OSSMMI_SENSORSTATETypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_OSSMMI_SENSORSTATE);
			fooTS->register_type(fooTS,p_Participant,"DMSG_OSSMMI_SENSORSTATE");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("gpsStatus", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("gyroStatus", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("emLogStatus", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("anemometerStatus", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("airStatus", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_OSSMMI_GPS{
	double latitude;
	double longitude;
	uint16_t year;
	char month;
	char day;
	uint32_t sec;
}DMSG_OSSMMI_GPS;

class DMSG_OSSMMI_GPSTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_OSSMMI_GPS);
			fooTS->register_type(fooTS,p_Participant,"DMSG_OSSMMI_GPS");
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
#if 0 // byungung, 20140414
			//dds_parameter_t *p_para = get_new_parameter("year", DDS_SHORT_TYPE,sizeof(int16_t));
			dds_parameter_t *p_para = get_new_parameter("year", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
#else
			dds_parameter_t *p_para = get_new_parameter("year", DDS_SHORT_TYPE,sizeof(uint16_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
#endif
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
			dds_parameter_t *p_para = get_new_parameter("sec", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_OSSMMI_GYRO{
	double heading;
	double roll;
	double pitch;
	int32_t rate_heading;
	int32_t rate_roll;
	int32_t rate_pitch;
}DMSG_OSSMMI_GYRO;

class DMSG_OSSMMI_GYROTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_OSSMMI_GYRO);
			fooTS->register_type(fooTS,p_Participant,"DMSG_OSSMMI_GYRO");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("heading", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("roll", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("pitch", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("rate_heading", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("rate_roll", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("rate_pitch", DDS_INTEGER_TYPE,sizeof(int32_t));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_OSSMMI_EMLOG{
	double velocity_north;
	double velocity_east;
	double velocity_down;
	double accel_nort;
	double accel_east;
	double accel_down;
}DMSG_OSSMMI_EMLOG;

class DMSG_OSSMMI_EMLOGTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_OSSMMI_EMLOG);
			fooTS->register_type(fooTS,p_Participant,"DMSG_OSSMMI_EMLOG");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("velocity_north", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("velocity_east", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("velocity_down", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("accel_nort", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("accel_east", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("accel_down", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_OSSMMI_WIND{
	double wind_direction;
	double wind_speed;
}DMSG_OSSMMI_WIND;

class DMSG_OSSMMI_WINDTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_OSSMMI_WIND);
			fooTS->register_type(fooTS,p_Participant,"DMSG_OSSMMI_WIND");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("wind_direction", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("wind_speed", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_OSSMMI_TEMP{
	double temp;
	double pressure;
	double humidity;
}DMSG_OSSMMI_TEMP;

class DMSG_OSSMMI_TEMPTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_OSSMMI_TEMP);
			fooTS->register_type(fooTS,p_Participant,"DMSG_OSSMMI_TEMP");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("temp", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("pressure", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("humidity", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_OSSMMI_ECHO{
	double dWaterDepth;
	double dDivingDepth;
}DMSG_OSSMMI_ECHO;

class DMSG_OSSMMI_ECHOTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_OSSMMI_ECHO);
			fooTS->register_type(fooTS,p_Participant,"DMSG_OSSMMI_ECHO");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("dWaterDepth", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
		{
			dds_parameter_t *p_para = get_new_parameter("dDivingDepth", DDS_FLOAT_TYPE,sizeof(double));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_OSSMMI_PLATFORM{
	char byPlatform;
}DMSG_OSSMMI_PLATFORM;

class DMSG_OSSMMI_PLATFORMTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_OSSMMI_PLATFORM);
			fooTS->register_type(fooTS,p_Participant,"DMSG_OSSMMI_PLATFORM");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("byPlatform", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

typedef struct DMSG_OSSMMI_PLATFORMREQ{
	char byPlatformReq;
}DMSG_OSSMMI_PLATFORMREQ;

class DMSG_OSSMMI_PLATFORMREQTypeSupport
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
			fooTS->i_size = sizeof(struct DMSG_OSSMMI_PLATFORMREQ);
			fooTS->register_type(fooTS,p_Participant,"DMSG_OSSMMI_PLATFORMREQ");
		}
	}

	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{
			dds_parameter_t *p_para = get_new_parameter("byPlatformReq", DDS_CHARACTER_TYPE,sizeof(char));
			INSERT_PARAM(fooTS->pp_parameters,fooTS->i_parameters, fooTS->i_parameters, p_para);
		}
	}
};

