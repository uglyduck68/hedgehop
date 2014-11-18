/*
	Foo 관련 헤더
	작성자 : 
	이력
	2010-08-7 : 시작

*/

#if !defined(__FOO_H)
#define __FOO_H


struct Foo
{
	int32_t dummy;
};

//typedef sequence<Foo> FooSeq;

typedef struct FooSeq
{
	int32_t i_seq;
	Foo** pp_foo;
} FooSeq;


static FooSeq INIT_FOOSEQ = {0, NULL};

////////////////////////////////////////////////////////////////////
typedef struct TypeSupport TypeSupport;

#ifndef FOOTYPESUPPORT_DEFINE
	#define FOOTYPESUPPORT_DEFINE 1
	typedef struct FooTypeSupport FooTypeSupport;
#endif

typedef struct FooDataWriter FooDataWriter;
typedef struct FooDataReader FooDataReader;

////////////////////////////////////////////////////////////////////

/***************************************************************
# 작성자: byungung.min (byungung@mdstec.com)
# 이력  :
 [2013-11-21]
  - LIG IDL에 맞게 short 타입 추가
 [2013-12-06]
  - 수정인: eunji.you (eunji@mdstec.com)
  - v1.0 수정사항v1.1 에적용	
***************************************************************/

typedef enum SUPPORT_TYPE
{
	DDS_STRING_TYPE,
	DDS_INTEGER_TYPE,
	DDS_FLOAT_TYPE,
	DDS_CHARACTER_TYPE,
	DDS_STRUCT_TYPE,
#if 1 // MDS, 20131121
	DDS_SHORT_TYPE
#endif
} SUPPORT_TYPE;

struct dds_parameter_t
{
	SUPPORT_TYPE	type;
	int				i_size;
	char*			p_field_name;
	union
	{
		char*		string_mds;
		long		integer;
		double		real;
		char		character;
	} value;
	bool			is_key;
	long			id;
	int				offset;
};



#define I_PARAMETER(foots, p_field_name, type, size) \
	{\
		dds_parameter_t *p_para = get_new_parameter(p_field_name, type, size);\
		INSERT_PARAM(##foots->pp_parameters,##foots->i_parameters, ##foots->i_parameters, p_para);\
	}

static inline dds_parameter_t* get_new_parameter(char* p_field_name, SUPPORT_TYPE type, int i_size)
{
	dds_parameter_t *p_parameter = (dds_parameter_t *)malloc(sizeof(dds_parameter_t));
	p_parameter->i_size = i_size;
	p_parameter->type = type;

	p_parameter->is_key = false;
	p_parameter->offset = 0;


	if(p_field_name)p_parameter->p_field_name = strdup(p_field_name);
	else p_parameter->p_field_name = NULL;

	return p_parameter;
}


static long PARAMETERKEY = 0;


static inline dds_parameter_t *get_new_parameter_key(char* p_field_name, SUPPORT_TYPE type, int i_size)
{
	dds_parameter_t *p_parameter = (dds_parameter_t *)malloc(sizeof(dds_parameter_t));
	p_parameter->i_size = i_size;
	p_parameter->type = type;
	p_parameter->is_key = true;


	if (p_field_name) p_parameter->p_field_name = strdup(p_field_name);
	else p_parameter->p_field_name = NULL;

	p_parameter->id = ++PARAMETERKEY;

	return p_parameter;
}



////////////////////////////////////////////////////////////////////


//interface FooTypeSupport : DDS::TypeSupport {
//	DDS::ReturnCode_t register_type(in_mds DDS::DomainParticipant participant, in_mds string_mds type_name);
//	string_mds get_type_name();
//};

struct FooTypeSupport
{
	TYPESUPPORT_BODY
	ReturnCode_t (*register_type)(FooTypeSupport *p_fooTypeSupport, in_mds DomainParticipant *p_participant, in_mds string_mds type_name);
	string_mds (*get_type_name)(FooTypeSupport *p_fooTypeSupport);
};

//interface FooDataWriter : DDS::DataWriter {
//	DDS::InstanceHandle_t register_instance(in_mds Foo instance_data);
//	DDS::InstanceHandle_t register_instance_w_timestamp(in_mds Foo instance_data,in_mds DDS::Time_t source_timestamp);
//	DDS::ReturnCode_t unregister_instance(in_mds Foo instance_data, in_mds DDS::InstanceHandle_t handle);
//	DDS::ReturnCode_t unregister_instance_w_timestamp(in_mds Foo instance_data, in_mds DDS::InstanceHandle_t handle, in_mds DDS::Time_t source_timestamp);
//	DDS::ReturnCode_t write( in_mds Foo instance_data, in_mds DDS::InstanceHandle_t handle);
//	DDS::ReturnCode_t write_w_timestamp( in_mds Foo instance_data, in_mds DDS::InstanceHandle_t handle, in_mds DDS::Time_t source_timestamp);
//	DDS::ReturnCode_t dispose( in_mds Foo instance_data, in_mds DDS::InstanceHandle_t instance_handle);
//	DDS::ReturnCode_t dispose_w_timestamp(in_mds Foo instance_data, in_mds DDS::InstanceHandle_t instance_handle, in_mds DDS::Time_t source_timestamp);
//	DDS::ReturnCode_t get_key_value(inout_mds Foo key_holder, in_mds DDS::InstanceHandle_t handle);
//	DDS::InstanceHandle_t lookup_instance(in_mds Foo key_holder);
//};

struct FooDataWriter
{
	DATAWRITER_BODY
	bool b_write_blocked;//by kki...(reliability)(Reliable로 설정되었을때 HistoryCache가 가득차서, block된 것을 표시하기 위한 플래그)
	InstanceHandle_t (*register_instance)(FooDataWriter *p_fooDataWriter, in_mds Foo *p_instance_data);
	InstanceHandle_t (*register_instance_w_timestamp)(FooDataWriter *p_fooDataWriter,in_mds Foo *instance_data,in_mds Time_t source_timestamp);
	ReturnCode_t (*unregister_instance)(FooDataWriter *p_fooDataWriter, in_mds Foo *instance_data, in_mds InstanceHandle_t handle);
	ReturnCode_t (*unregister_instance_w_timestamp)(FooDataWriter *p_fooDataWriter, in_mds Foo *instance_data, in_mds InstanceHandle_t handle, in_mds Time_t source_timestamp);
	ReturnCode_t (*write)(FooDataWriter *p_fooDataWriter, in_mds Foo *p_instance_data, in_mds InstanceHandle_t handle);
	ReturnCode_t (*write_w_timestamp)(FooDataWriter *p_fooDataWriter, in_mds Foo *instance_data, in_mds InstanceHandle_t handle, in_mds Time_t source_timestamp);
	ReturnCode_t (*dispose)(FooDataWriter *p_fooDataWriter, in_mds Foo *instance_data, in_mds InstanceHandle_t instance_handle);
	ReturnCode_t (*dispose_w_timestamp)(FooDataWriter *p_fooDataWriter, in_mds Foo *instance_data, in_mds InstanceHandle_t instance_handle, in_mds Time_t source_timestamp);
	ReturnCode_t (*get_key_value)(FooDataWriter *p_fooDataWriter,inout_mds Foo *key_holder, in_mds InstanceHandle_t handle);
	InstanceHandle_t (*lookup_instance)(FooDataWriter *p_fooDataWriter,in_mds Foo *key_holder);
};


//interface FooDataReader : DDS::DataReader {
//	DDS::ReturnCode_t read(inout_mds FooSeq data_values, inout_mds DDS::SampleInfoSeq sample_infos, in_mds long max_samples, in_mds DDS::SampleStateMask sample_states, in_mds DDS::ViewStateMask view_states, in_mds DDS::InstanceStateMask instance_states);
//	DDS::ReturnCode_t take(inout_mds FooSeq data_values, inout_mds DDS::SampleInfoSeq sample_infos, in_mds long max_samples, in_mds DDS::SampleStateMask sample_states, in_mds DDS::ViewStateMask view_states, in_mds DDS::InstanceStateMask instance_states);
//	DDS::ReturnCode_t read_w_condition(inout_mds FooSeq data_values,inout_mds DDS::SampleInfoSeq sample_infos, in_mds long max_samples, in_mds DDS::ReadCondition a_condition);
//	DDS::ReturnCode_t take_w_condition(inout_mds FooSeq data_values,inout_mds DDS::SampleInfoSeq sample_infos,in_mds long max_samples,in_mds DDS::ReadCondition a_condition);
//	DDS::ReturnCode_t read_next_sample(inout_mds Foo data_value,inout_mds DDS::SampleInfo sample_info);
//	DDS::ReturnCode_t take_next_sample(inout_mds Foo data_value,inout_mds DDS::SampleInfo sample_info);
//	DDS::ReturnCode_t read_instance(inout_mds FooSeq data_values,inout_mds DDS::SampleInfoSeq sample_infos,in_mds long max_samples,in_mds DDS::InstanceHandle_t a_handle,in_mds DDS::SampleStateMask sample_states,in_mds DDS::ViewStateMask view_states, in_mds DDS::InstanceStateMask instance_states);
//	DDS::ReturnCode_t take_instance(inout_mds FooSeq data_values,inout_mds DDS::SampleInfoSeq sample_infos,in_mds long max_samples,in_mds DDS::InstanceHandle_t a_handle,in_mds DDS::SampleStateMask sample_states,in_mds DDS::ViewStateMask view_states,in_mds DDS::InstanceStateMask instance_states);
//	DDS::ReturnCode_t read_next_instance(inout_mds FooSeq data_values,inout_mds DDS::SampleInfoSeq sample_infos,in_mds long max_samples,in_mds DDS::InstanceHandle_t previous_handle,in_mds DDS::SampleStateMask sample_states,in_mds DDS::ViewStateMask view_states,in_mds DDS::InstanceStateMask instance_states);
//	DDS::ReturnCode_t take_next_instance(inout_mds FooSeq data_values,inout_mds DDS::SampleInfoSeq sample_infos,in_mds long max_samples,in_mds DDS::InstanceHandle_t previous_handle,in_mds DDS::SampleStateMask sample_states,in_mds DDS::ViewStateMask view_states,in_mds DDS::InstanceStateMask instance_states);
//};

struct FooDataReader
{
	DATAREADER_BODY
	ReturnCode_t (*read)(FooDataReader *p_fooDataReader, inout_mds FooSeq *p_data_values, inout_mds SampleInfoSeq *p_sample_infos, in_mds long max_samples, in_mds SampleStateMask sample_states, in_mds ViewStateMask view_states, in_mds InstanceStateMask instance_states);
	ReturnCode_t (*take)(FooDataReader *p_fooDataReader, inout_mds FooSeq *p_data_values, inout_mds SampleInfoSeq *p_sample_infos, in_mds long max_samples, in_mds SampleStateMask sample_states, in_mds ViewStateMask view_states, in_mds InstanceStateMask instance_states);
	ReturnCode_t (*read_w_condition)(FooDataReader *p_fooDataReader, inout_mds FooSeq *p_data_values,inout_mds SampleInfoSeq *p_sample_infos, in_mds long max_samples, in_mds ReadCondition *p_condition);
	ReturnCode_t (*take_w_condition)(FooDataReader *p_fooDataReader, inout_mds FooSeq *p_data_values,inout_mds SampleInfoSeq *p_sample_infos,in_mds long max_samples,in_mds ReadCondition *p_condition);
	ReturnCode_t (*read_next_sample)(FooDataReader *p_fooDataReader, inout_mds Foo **data_value,inout_mds SampleInfo **sample_info);
	ReturnCode_t (*take_next_sample)(FooDataReader *p_fooDataReader, inout_mds Foo **data_value,inout_mds SampleInfo **sample_info);
	ReturnCode_t (*read_instance)(FooDataReader *p_fooDataReader, inout_mds FooSeq *data_values,inout_mds SampleInfoSeq *sample_infos,in_mds long max_samples,in_mds InstanceHandle_t a_handle,in_mds SampleStateMask sample_states,in_mds ViewStateMask view_states, in_mds InstanceStateMask instance_states);
	ReturnCode_t (*take_instance)(FooDataReader *p_fooDataReader, inout_mds FooSeq *data_values,inout_mds SampleInfoSeq *sample_infos,in_mds long max_samples,in_mds InstanceHandle_t a_handle,in_mds SampleStateMask sample_states,in_mds ViewStateMask view_states,in_mds InstanceStateMask instance_states);
	ReturnCode_t (*read_next_instance)(FooDataReader *p_fooDataReader, inout_mds FooSeq *data_values,inout_mds SampleInfoSeq *sample_infos,in_mds long max_samples,in_mds InstanceHandle_t *previous_handle,in_mds SampleStateMask sample_states,in_mds ViewStateMask view_states,in_mds InstanceStateMask instance_states);
	ReturnCode_t (*take_next_instance)(FooDataReader *p_fooDataReader, inout_mds FooSeq *data_values,inout_mds SampleInfoSeq *sample_infos,in_mds long max_samples,in_mds InstanceHandle_t *previous_handle,in_mds SampleStateMask sample_states,in_mds ViewStateMask view_states,in_mds InstanceStateMask instance_states);
	// added by sean, DDSE_F_DCPS_0188, DDSE_F_DCPS_0189
	ReturnCode_t(*read_next_instance_w_condition)(FooDataReader *p_fooDataReader, inout_mds FooSeq *data_values, inout_mds SampleInfoSeq *sample_infos, in_mds long max_samples, in_mds InstanceHandle_t *previous_handle, in_mds ReadCondition *p_condition);
	ReturnCode_t(*take_next_instance_w_condition)(FooDataReader *p_fooDataReader, inout_mds FooSeq *data_values, inout_mds SampleInfoSeq *sample_infos, in_mds long max_samples, in_mds InstanceHandle_t *previous_handle, in_mds ReadCondition *p_condition);
	//.. added by sean, DDSE_F_DCPS_0190
	ReturnCode_t (*return_loan)(FooDataReader *p_fooDataReader, inout_mds FooSeq *data_values, inout_mds SampleInfoSeq *sample_infos);
	ReturnCode_t (*get_key_value)(FooDataReader *p_fooDataReader, inout_mds Foo *key_holder, in_mds InstanceHandle_t handle);
	InstanceHandle_t (*lookup_instance)(FooDataReader *p_fooDataReader, in_mds Foo *key_holder);
};

#ifdef __cplusplus
extern "C" {
#endif
	Duration_t current_duration();
	Time_t currenTime();

	void init_foo_type_support(FooTypeSupport* p_foo_type_support);
	void init_foo_datawriter(FooDataWriter* p_foo_datawriter);
	void init_foo_datareader(FooDataReader* p_foo_datareader);
	FooTypeSupport* get_new_foo_type_support();

	void  register_type(module_object_t* p_this, FooTypeSupport* p_foo_type_support, in_mds DomainParticipant* p_participant, in_mds string_mds type_name);
	string_mds get_type_name(module_object_t* p_this, FooTypeSupport* p_foo_type_support);
	FooTypeSupport* domain_participant_find_support_type(module_object_t* p_this, DomainParticipant* p_participant, string_mds type_name);
	FooTypeSupport* get_type_support(string_mds type_name);
	void remove_foo_seq(FooSeq* p_fseq, int index);
	//.. added by sean
	void remove_sample_seq(SampleInfoSeq* p_sampleseq, int index);
#ifdef __cplusplus
}
#endif

#endif
