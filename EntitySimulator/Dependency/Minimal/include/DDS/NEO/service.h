/*
	서비스 관련 헤더
	작성자 : 
	이력
	2010-07-24 : 시작 일단 윈도우만 우선 선언 어느 정도 되면 다른 플랫폼 추가

*/

#if !defined(__SERVICE_H)
#define __SERVICE_H

typedef struct service_sys_t service_sys_t;

#ifndef ENTITY_DEFINE
        #define ENTITY_DEFINE 1
        typedef struct Entity Entity;
#endif

#ifndef DOMAINPARTICIPANT_DEFINE
        #define DOMAINPARTICIPANT_DEFINE 1
        typedef struct DomainParticipant DomainParticipant;
#endif

#ifndef RTPS_WRITER_T_DEFINE
        #define RTPS_WRITER_T_DEFINE 1
        typedef struct rtps_writer_t rtps_writer_t;
#endif

#ifndef HANDLE_TYPE_NATIVE
	#define HANDLE_TYPE_NATIVE long
#endif
#ifndef HANDLE_TYPE_NATIVE_DEFINE
        #define HANDLE_TYPE_NATIVE_DEFINE 1
        typedef HANDLE_TYPE_NATIVE InstanceHandle_t;
#endif

#ifndef DATAREADER_DEFINE
	#define DATAREADER_DEFINE 1
	typedef struct DataReader DataReader;
#endif


#ifndef TIME_STRUCT_T
	#define TIME_STRUCT_T
	typedef struct Time_t Time_t;
	struct Time_t {
		int32_t sec;
		uint32_t nanosec;
	};
	typedef struct Duration_t {
		int32_t sec;
		uint32_t nanosec;
	}Duration_t;
#endif

enum SERVICE_ACCESS_OUT_TYPE
{
	SPDP_OUT_TYPE,
	SEDP_OUT_TYPE,
	DEFAULT_OUT_TYPE
};

#ifndef DCPS_STATE_DEFINE
#define DCPS_STATE_DEFINE 1

// Sample states to support reads
typedef uint32_t SampleStateKind;
static const SampleStateKind READ_SAMPLE_STATE = 0x0001 << 0;
static const SampleStateKind NOT_READ_SAMPLE_STATE = 0x0001 << 1;
// This is a bit-mask SampleStateKind
typedef uint32_t SampleStateMask;
static const SampleStateMask ANY_SAMPLE_STATE = 0xffff;
// View states to support reads
typedef uint32_t ViewStateKind;
static const ViewStateKind NEW_VIEW_STATE = 0x0001 << 0;
static const ViewStateKind NOT_NEW_VIEW_STATE = 0x0001 << 1;
// This is a bit-mask ViewStateKind
typedef uint32_t ViewStateMask;
static const ViewStateMask ANY_VIEW_STATE = 0xffff;
// Instance states to support reads
typedef uint32_t InstanceStateKind;
static const InstanceStateKind ALIVE_INSTANCE_STATE = 0x0001 << 0;
static const InstanceStateKind NOT_ALIVE_DISPOSED_INSTANCE_STATE = 0x0001 << 1;
static const InstanceStateKind NOT_ALIVE_NO_WRITERS_INSTANCE_STATE = 0x0001 << 2;
// This is a bit-mask InstanceStateKind
typedef uint32_t InstanceStateMask;
static const InstanceStateMask ANY_INSTANCE_STATE = 0xffff;
static const InstanceStateMask NOT_ALIVE_INSTANCE_STATE = 0x006;

//static const StatusMask ANY_STATUS_STATE = 0xffff;

#endif

struct service_t
{
    MODULE_COMMON_FIELD

	moduleload_t*	p_moduleload;
	
	int				(*add_entity)(module_object_t* p_this, Entity* p_entity);
	int				(*remove_entity)(module_object_t* p_this, Entity* p_entity);
	void*			(*write)(module_object_t * p_this, rtps_writer_t *p_writer, message_t *p_message);
	void*			(*dispose)(module_object_t * p_this, rtps_writer_t *p_writer, void *v_data, InstanceHandle_t handle);
	void*			(*unregister)(module_object_t * p_this, rtps_writer_t *p_writer, void *v_data, InstanceHandle_t handle, bool b_dispose);
	access_out_t*	(*getaccessout)(module_object_t * p_this, int type);
	message_t**		(*read)(module_object_t * p_this, DataReader *p_datareader, int32_t max_samples, int *p_size, SampleStateMask sample_states, ViewStateMask view_states, InstanceStateMask instance_states);
	message_t**		(*take)(module_object_t * p_this, DataReader *p_datareader, int32_t max_samples, int *p_size, SampleStateMask sample_states, ViewStateMask view_states, InstanceStateMask instance_states);
	message_t**		(*read_instance)(module_object_t * p_this, DataReader *p_datareader, InstanceHandle_t handle, int32_t max_samples, int *p_size, SampleStateMask sample_states, ViewStateMask view_states, InstanceStateMask instance_states);
	message_t**		(*take_instance)(module_object_t * p_this, DataReader *p_datareader, InstanceHandle_t handle, int32_t max_samples, int *p_size, SampleStateMask sample_states, ViewStateMask view_states, InstanceStateMask instance_states);
	void*			(*write_timestamp)(module_object_t * p_this, rtps_writer_t *p_writer, message_t *p_message, Time_t source_timestamp);
	void*			(*dispose_timestamp)(module_object_t * p_this, rtps_writer_t *p_writer, void *v_data, InstanceHandle_t handle, Time_t source_timestamp);
	void*			(*unregister_timestamp)(module_object_t * p_this, rtps_writer_t *p_writer, void *v_data, InstanceHandle_t handle, Time_t source_timestamp);
	
	int				(*add_thread)(module_object_t* p_this, Entity* p_entity);

	data_fifo_t*	p_network_fifo;
	service_sys_t*	p_sys;
#ifndef _JWKIM_141211_EXIT_ISSUE	//jwkim : Read관련인 NetworkThread만 종료시 기존 b_end 사용시 ThreadWrite2도 중지되어 종료 메시지를 못보내기 때문에 NetworkThread만 먼저 죽이기 위해 별도로 구성
	bool b_end_for_NetworkThread;
#endif //_JWKIM_141211_EXIT_ISSUE
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef DDS_147_JWKIM_141204_MULTI_DOMAIN	//jwkim : Service 모듈을 domainID에 따라 런칭할 수 있도록 수정
	int launch_service_module(module_object_t* p_this);
#else
	int launch_service_module(module_object_t* p_this, int32_t domainID);
#endif //DDS_147_JWKIM_141204_MULTI_DOMAIN
	
	void add_entity_to_service(Entity* p_entity);
	void remove_entity_to_service(Entity* p_entity);
#ifdef DDS_147_JWKIM_141204_MULTI_DOMAIN	//jwkim : 각 서비스모듈 함수에 DomainID로 처리할 수 있도록 수정
	void write_to_service(rtps_writer_t* p_rtps_writer, message_t* p_message);
	void dispose_to_service(rtps_writer_t* p_rtps_writer, void* v_data, InstanceHandle_t handle);
	void dispose_to_service_timestamp(rtps_writer_t* p_rtps_writer, void* v_data, InstanceHandle_t handle, Time_t source_timestamp);
	void unregister_to_service(rtps_writer_t* p_rtps_writer, void* v_data, InstanceHandle_t handle, bool b_dispose);
	void unregister_to_service_timestamp(rtps_writer_t* p_rtps_writer, void* v_data, InstanceHandle_t handle, Time_t source_timestamp);
#else
	void write_to_service(rtps_writer_t* p_rtps_writer, message_t* p_message, int32_t domainID);
	void dispose_to_service(rtps_writer_t* p_rtps_writer, void* v_data, InstanceHandle_t handle, int32_t domainID);
	void dispose_to_service_timestamp(rtps_writer_t* p_rtps_writer, void* v_data, InstanceHandle_t handle, Time_t source_timestamp, int32_t domainID);
	void unregister_to_service(rtps_writer_t* p_rtps_writer, void* v_data, InstanceHandle_t handle, bool b_dispose, int32_t domainID);
	void unregister_to_service_timestamp(rtps_writer_t* p_rtps_writer, void* v_data, InstanceHandle_t handle, Time_t source_timestamp, int32_t domainID);
#endif //DDS_147_JWKIM_141204_MULTI_DOMAIN

#ifndef DDS_147_JWKIM_141204_MULTI_DOMAIN	//jwkim : domainID로 서비스 모듈을 얻어올 수 있도록 함수 추가
	service_t * getServiseModule(int32_t domainID);
#endif	//DDS_147_JWKIM_141204_MULTI_DOMAIN
	

	message_t** message_read_from_service(DataReader* p_datareader, int32_t max_samples, int* p_count, SampleStateMask sample_states, ViewStateMask view_states, InstanceStateMask instance_states);
	message_t** message_take_from_service(DataReader* p_datareader, int32_t max_samples, int* p_count, SampleStateMask sample_states, ViewStateMask view_states, InstanceStateMask instance_states);
	message_t** message_read_instance_from_service(DataReader* p_datareader, InstanceHandle_t handle, int32_t max_samples, int* p_count, SampleStateMask sample_states, ViewStateMask view_states, InstanceStateMask instance_states);
	message_t** message_take_instance_from_service(DataReader* p_datareader, InstanceHandle_t handle, int32_t max_samples, int* p_count, SampleStateMask sample_states, ViewStateMask view_states, InstanceStateMask instance_states);

	void add_thread_to_service(Entity* p_entity);

#ifdef __cplusplus
}
#endif

#define DEFAULT_MTU 32000


#endif
