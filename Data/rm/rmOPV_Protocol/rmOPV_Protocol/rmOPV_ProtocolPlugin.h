
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from rmOPV_Protocol.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Connext distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Connext manual.
*/

#ifndef rmOPV_ProtocolPlugin_139685288_h
#define rmOPV_ProtocolPlugin_139685288_h

#include "rmOPV_Protocol.h"




struct RTICdrStream;

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif


#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif


#ifdef __cplusplus
extern "C" {
#endif

#define ST_POSITION_LAST_MEMBER_ID 0

#define ST_POSITIONPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define ST_POSITIONPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define ST_POSITIONPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define ST_POSITIONPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define ST_POSITIONPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define ST_POSITIONPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern ST_POSITION*
ST_POSITIONPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern ST_POSITION*
ST_POSITIONPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
ST_POSITIONPluginSupport_copy_data(
    ST_POSITION *out,
    const ST_POSITION *in);

NDDSUSERDllExport extern void 
ST_POSITIONPluginSupport_destroy_data_ex(
    ST_POSITION *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
ST_POSITIONPluginSupport_destroy_data(
    ST_POSITION *sample);

NDDSUSERDllExport extern void 
ST_POSITIONPluginSupport_print_data(
    const ST_POSITION *sample,
    const char *desc,
    unsigned int indent);


/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
ST_POSITIONPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
ST_POSITIONPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
ST_POSITIONPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
ST_POSITIONPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);


NDDSUSERDllExport extern RTIBool 
ST_POSITIONPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    ST_POSITION *out,
    const ST_POSITION *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
ST_POSITIONPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const ST_POSITION *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
ST_POSITIONPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    ST_POSITION *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
ST_POSITIONPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    ST_POSITION **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);




NDDSUSERDllExport extern RTIBool
ST_POSITIONPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
ST_POSITIONPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
ST_POSITIONPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
ST_POSITIONPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const ST_POSITION * sample);



/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
ST_POSITIONPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
ST_POSITIONPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
ST_POSITIONPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const ST_POSITION *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
ST_POSITIONPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    ST_POSITION * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
ST_POSITIONPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    ST_POSITION ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
ST_POSITIONPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    ST_POSITION *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
ST_POSITIONPlugin_new(void);

NDDSUSERDllExport extern void
ST_POSITIONPlugin_delete(struct PRESTypePlugin *);

#define ST_ENTITY_STATE_LAST_MEMBER_ID 0

#define ST_ENTITY_STATEPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define ST_ENTITY_STATEPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define ST_ENTITY_STATEPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define ST_ENTITY_STATEPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define ST_ENTITY_STATEPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define ST_ENTITY_STATEPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern ST_ENTITY_STATE*
ST_ENTITY_STATEPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern ST_ENTITY_STATE*
ST_ENTITY_STATEPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
ST_ENTITY_STATEPluginSupport_copy_data(
    ST_ENTITY_STATE *out,
    const ST_ENTITY_STATE *in);

NDDSUSERDllExport extern void 
ST_ENTITY_STATEPluginSupport_destroy_data_ex(
    ST_ENTITY_STATE *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
ST_ENTITY_STATEPluginSupport_destroy_data(
    ST_ENTITY_STATE *sample);

NDDSUSERDllExport extern void 
ST_ENTITY_STATEPluginSupport_print_data(
    const ST_ENTITY_STATE *sample,
    const char *desc,
    unsigned int indent);


/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
ST_ENTITY_STATEPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
ST_ENTITY_STATEPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
ST_ENTITY_STATEPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
ST_ENTITY_STATEPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);


NDDSUSERDllExport extern RTIBool 
ST_ENTITY_STATEPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    ST_ENTITY_STATE *out,
    const ST_ENTITY_STATE *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
ST_ENTITY_STATEPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const ST_ENTITY_STATE *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
ST_ENTITY_STATEPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    ST_ENTITY_STATE *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
ST_ENTITY_STATEPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    ST_ENTITY_STATE **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);




NDDSUSERDllExport extern RTIBool
ST_ENTITY_STATEPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
ST_ENTITY_STATEPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
ST_ENTITY_STATEPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
ST_ENTITY_STATEPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const ST_ENTITY_STATE * sample);



/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
ST_ENTITY_STATEPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
ST_ENTITY_STATEPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
ST_ENTITY_STATEPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const ST_ENTITY_STATE *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
ST_ENTITY_STATEPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    ST_ENTITY_STATE * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
ST_ENTITY_STATEPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    ST_ENTITY_STATE ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
ST_ENTITY_STATEPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    ST_ENTITY_STATE *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
ST_ENTITY_STATEPlugin_new(void);

NDDSUSERDllExport extern void
ST_ENTITY_STATEPlugin_delete(struct PRESTypePlugin *);

#define ST_ENTITY_INFO_LAST_MEMBER_ID 0

#define ST_ENTITY_INFOPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define ST_ENTITY_INFOPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define ST_ENTITY_INFOPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define ST_ENTITY_INFOPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define ST_ENTITY_INFOPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define ST_ENTITY_INFOPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern ST_ENTITY_INFO*
ST_ENTITY_INFOPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern ST_ENTITY_INFO*
ST_ENTITY_INFOPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
ST_ENTITY_INFOPluginSupport_copy_data(
    ST_ENTITY_INFO *out,
    const ST_ENTITY_INFO *in);

NDDSUSERDllExport extern void 
ST_ENTITY_INFOPluginSupport_destroy_data_ex(
    ST_ENTITY_INFO *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
ST_ENTITY_INFOPluginSupport_destroy_data(
    ST_ENTITY_INFO *sample);

NDDSUSERDllExport extern void 
ST_ENTITY_INFOPluginSupport_print_data(
    const ST_ENTITY_INFO *sample,
    const char *desc,
    unsigned int indent);


/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
ST_ENTITY_INFOPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
ST_ENTITY_INFOPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
ST_ENTITY_INFOPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
ST_ENTITY_INFOPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);


NDDSUSERDllExport extern RTIBool 
ST_ENTITY_INFOPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    ST_ENTITY_INFO *out,
    const ST_ENTITY_INFO *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
ST_ENTITY_INFOPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const ST_ENTITY_INFO *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
ST_ENTITY_INFOPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    ST_ENTITY_INFO *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
ST_ENTITY_INFOPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    ST_ENTITY_INFO **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);




NDDSUSERDllExport extern RTIBool
ST_ENTITY_INFOPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
ST_ENTITY_INFOPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
ST_ENTITY_INFOPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
ST_ENTITY_INFOPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const ST_ENTITY_INFO * sample);



/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
ST_ENTITY_INFOPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
ST_ENTITY_INFOPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
ST_ENTITY_INFOPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const ST_ENTITY_INFO *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
ST_ENTITY_INFOPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    ST_ENTITY_INFO * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
ST_ENTITY_INFOPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    ST_ENTITY_INFO ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
ST_ENTITY_INFOPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    ST_ENTITY_INFO *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
ST_ENTITY_INFOPlugin_new(void);

NDDSUSERDllExport extern void
ST_ENTITY_INFOPlugin_delete(struct PRESTypePlugin *);

#define ST_ENTITY_ATTRIBUTE_LAST_MEMBER_ID 0

#define ST_ENTITY_ATTRIBUTEPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define ST_ENTITY_ATTRIBUTEPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define ST_ENTITY_ATTRIBUTEPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define ST_ENTITY_ATTRIBUTEPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define ST_ENTITY_ATTRIBUTEPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define ST_ENTITY_ATTRIBUTEPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern ST_ENTITY_ATTRIBUTE*
ST_ENTITY_ATTRIBUTEPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern ST_ENTITY_ATTRIBUTE*
ST_ENTITY_ATTRIBUTEPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
ST_ENTITY_ATTRIBUTEPluginSupport_copy_data(
    ST_ENTITY_ATTRIBUTE *out,
    const ST_ENTITY_ATTRIBUTE *in);

NDDSUSERDllExport extern void 
ST_ENTITY_ATTRIBUTEPluginSupport_destroy_data_ex(
    ST_ENTITY_ATTRIBUTE *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
ST_ENTITY_ATTRIBUTEPluginSupport_destroy_data(
    ST_ENTITY_ATTRIBUTE *sample);

NDDSUSERDllExport extern void 
ST_ENTITY_ATTRIBUTEPluginSupport_print_data(
    const ST_ENTITY_ATTRIBUTE *sample,
    const char *desc,
    unsigned int indent);


/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
ST_ENTITY_ATTRIBUTEPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
ST_ENTITY_ATTRIBUTEPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
ST_ENTITY_ATTRIBUTEPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
ST_ENTITY_ATTRIBUTEPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);


NDDSUSERDllExport extern RTIBool 
ST_ENTITY_ATTRIBUTEPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    ST_ENTITY_ATTRIBUTE *out,
    const ST_ENTITY_ATTRIBUTE *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
ST_ENTITY_ATTRIBUTEPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const ST_ENTITY_ATTRIBUTE *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
ST_ENTITY_ATTRIBUTEPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    ST_ENTITY_ATTRIBUTE *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
ST_ENTITY_ATTRIBUTEPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    ST_ENTITY_ATTRIBUTE **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);




NDDSUSERDllExport extern RTIBool
ST_ENTITY_ATTRIBUTEPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
ST_ENTITY_ATTRIBUTEPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
ST_ENTITY_ATTRIBUTEPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
ST_ENTITY_ATTRIBUTEPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const ST_ENTITY_ATTRIBUTE * sample);



/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
ST_ENTITY_ATTRIBUTEPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
ST_ENTITY_ATTRIBUTEPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
ST_ENTITY_ATTRIBUTEPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const ST_ENTITY_ATTRIBUTE *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
ST_ENTITY_ATTRIBUTEPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    ST_ENTITY_ATTRIBUTE * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
ST_ENTITY_ATTRIBUTEPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    ST_ENTITY_ATTRIBUTE ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
ST_ENTITY_ATTRIBUTEPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    ST_ENTITY_ATTRIBUTE *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
ST_ENTITY_ATTRIBUTEPlugin_new(void);

NDDSUSERDllExport extern void
ST_ENTITY_ATTRIBUTEPlugin_delete(struct PRESTypePlugin *);

#define ST_MISSILE_DATA_LAST_MEMBER_ID 0

#define ST_MISSILE_DATAPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define ST_MISSILE_DATAPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define ST_MISSILE_DATAPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define ST_MISSILE_DATAPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define ST_MISSILE_DATAPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define ST_MISSILE_DATAPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern ST_MISSILE_DATA*
ST_MISSILE_DATAPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern ST_MISSILE_DATA*
ST_MISSILE_DATAPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
ST_MISSILE_DATAPluginSupport_copy_data(
    ST_MISSILE_DATA *out,
    const ST_MISSILE_DATA *in);

NDDSUSERDllExport extern void 
ST_MISSILE_DATAPluginSupport_destroy_data_ex(
    ST_MISSILE_DATA *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
ST_MISSILE_DATAPluginSupport_destroy_data(
    ST_MISSILE_DATA *sample);

NDDSUSERDllExport extern void 
ST_MISSILE_DATAPluginSupport_print_data(
    const ST_MISSILE_DATA *sample,
    const char *desc,
    unsigned int indent);


/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
ST_MISSILE_DATAPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
ST_MISSILE_DATAPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
ST_MISSILE_DATAPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
ST_MISSILE_DATAPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);


NDDSUSERDllExport extern RTIBool 
ST_MISSILE_DATAPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    ST_MISSILE_DATA *out,
    const ST_MISSILE_DATA *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
ST_MISSILE_DATAPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const ST_MISSILE_DATA *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
ST_MISSILE_DATAPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    ST_MISSILE_DATA *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
ST_MISSILE_DATAPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    ST_MISSILE_DATA **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);




NDDSUSERDllExport extern RTIBool
ST_MISSILE_DATAPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
ST_MISSILE_DATAPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
ST_MISSILE_DATAPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
ST_MISSILE_DATAPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const ST_MISSILE_DATA * sample);



/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
ST_MISSILE_DATAPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
ST_MISSILE_DATAPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
ST_MISSILE_DATAPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const ST_MISSILE_DATA *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
ST_MISSILE_DATAPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    ST_MISSILE_DATA * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
ST_MISSILE_DATAPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    ST_MISSILE_DATA ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
ST_MISSILE_DATAPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    ST_MISSILE_DATA *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
ST_MISSILE_DATAPlugin_new(void);

NDDSUSERDllExport extern void
ST_MISSILE_DATAPlugin_delete(struct PRESTypePlugin *);

#define ST_AMMUNITION_DATA_LAST_MEMBER_ID 0

#define ST_AMMUNITION_DATAPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define ST_AMMUNITION_DATAPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define ST_AMMUNITION_DATAPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define ST_AMMUNITION_DATAPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define ST_AMMUNITION_DATAPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define ST_AMMUNITION_DATAPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern ST_AMMUNITION_DATA*
ST_AMMUNITION_DATAPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern ST_AMMUNITION_DATA*
ST_AMMUNITION_DATAPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
ST_AMMUNITION_DATAPluginSupport_copy_data(
    ST_AMMUNITION_DATA *out,
    const ST_AMMUNITION_DATA *in);

NDDSUSERDllExport extern void 
ST_AMMUNITION_DATAPluginSupport_destroy_data_ex(
    ST_AMMUNITION_DATA *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
ST_AMMUNITION_DATAPluginSupport_destroy_data(
    ST_AMMUNITION_DATA *sample);

NDDSUSERDllExport extern void 
ST_AMMUNITION_DATAPluginSupport_print_data(
    const ST_AMMUNITION_DATA *sample,
    const char *desc,
    unsigned int indent);


/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
ST_AMMUNITION_DATAPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
ST_AMMUNITION_DATAPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
ST_AMMUNITION_DATAPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
ST_AMMUNITION_DATAPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);


NDDSUSERDllExport extern RTIBool 
ST_AMMUNITION_DATAPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    ST_AMMUNITION_DATA *out,
    const ST_AMMUNITION_DATA *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
ST_AMMUNITION_DATAPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const ST_AMMUNITION_DATA *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
ST_AMMUNITION_DATAPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    ST_AMMUNITION_DATA *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
ST_AMMUNITION_DATAPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    ST_AMMUNITION_DATA **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);




NDDSUSERDllExport extern RTIBool
ST_AMMUNITION_DATAPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
ST_AMMUNITION_DATAPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
ST_AMMUNITION_DATAPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
ST_AMMUNITION_DATAPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const ST_AMMUNITION_DATA * sample);



/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
ST_AMMUNITION_DATAPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
ST_AMMUNITION_DATAPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
ST_AMMUNITION_DATAPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const ST_AMMUNITION_DATA *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
ST_AMMUNITION_DATAPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    ST_AMMUNITION_DATA * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
ST_AMMUNITION_DATAPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    ST_AMMUNITION_DATA ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
ST_AMMUNITION_DATAPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    ST_AMMUNITION_DATA *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
ST_AMMUNITION_DATAPlugin_new(void);

NDDSUSERDllExport extern void
ST_AMMUNITION_DATAPlugin_delete(struct PRESTypePlugin *);

#define SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK_LAST_MEMBER_ID 0

#define SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK*
SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK*
SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKPluginSupport_copy_data(
    SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK *out,
    const SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK *in);

NDDSUSERDllExport extern void 
SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKPluginSupport_destroy_data_ex(
    SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKPluginSupport_destroy_data(
    SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK *sample);

NDDSUSERDllExport extern void 
SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKPluginSupport_print_data(
    const SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK *sample,
    const char *desc,
    unsigned int indent);


/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);


NDDSUSERDllExport extern RTIBool 
SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK *out,
    const SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);




NDDSUSERDllExport extern RTIBool
SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK * sample);



/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKPlugin_new(void);

NDDSUSERDllExport extern void
SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKPlugin_delete(struct PRESTypePlugin *);

#define SIM_SC_SIMULATOR_STATUS_REPORT_LAST_MEMBER_ID 0

#define SIM_SC_SIMULATOR_STATUS_REPORTPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define SIM_SC_SIMULATOR_STATUS_REPORTPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define SIM_SC_SIMULATOR_STATUS_REPORTPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define SIM_SC_SIMULATOR_STATUS_REPORTPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define SIM_SC_SIMULATOR_STATUS_REPORTPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define SIM_SC_SIMULATOR_STATUS_REPORTPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern SIM_SC_SIMULATOR_STATUS_REPORT*
SIM_SC_SIMULATOR_STATUS_REPORTPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern SIM_SC_SIMULATOR_STATUS_REPORT*
SIM_SC_SIMULATOR_STATUS_REPORTPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
SIM_SC_SIMULATOR_STATUS_REPORTPluginSupport_copy_data(
    SIM_SC_SIMULATOR_STATUS_REPORT *out,
    const SIM_SC_SIMULATOR_STATUS_REPORT *in);

NDDSUSERDllExport extern void 
SIM_SC_SIMULATOR_STATUS_REPORTPluginSupport_destroy_data_ex(
    SIM_SC_SIMULATOR_STATUS_REPORT *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
SIM_SC_SIMULATOR_STATUS_REPORTPluginSupport_destroy_data(
    SIM_SC_SIMULATOR_STATUS_REPORT *sample);

NDDSUSERDllExport extern void 
SIM_SC_SIMULATOR_STATUS_REPORTPluginSupport_print_data(
    const SIM_SC_SIMULATOR_STATUS_REPORT *sample,
    const char *desc,
    unsigned int indent);


/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
SIM_SC_SIMULATOR_STATUS_REPORTPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
SIM_SC_SIMULATOR_STATUS_REPORTPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
SIM_SC_SIMULATOR_STATUS_REPORTPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
SIM_SC_SIMULATOR_STATUS_REPORTPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);


NDDSUSERDllExport extern RTIBool 
SIM_SC_SIMULATOR_STATUS_REPORTPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    SIM_SC_SIMULATOR_STATUS_REPORT *out,
    const SIM_SC_SIMULATOR_STATUS_REPORT *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
SIM_SC_SIMULATOR_STATUS_REPORTPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const SIM_SC_SIMULATOR_STATUS_REPORT *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
SIM_SC_SIMULATOR_STATUS_REPORTPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    SIM_SC_SIMULATOR_STATUS_REPORT *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
SIM_SC_SIMULATOR_STATUS_REPORTPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    SIM_SC_SIMULATOR_STATUS_REPORT **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);




NDDSUSERDllExport extern RTIBool
SIM_SC_SIMULATOR_STATUS_REPORTPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
SIM_SC_SIMULATOR_STATUS_REPORTPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
SIM_SC_SIMULATOR_STATUS_REPORTPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
SIM_SC_SIMULATOR_STATUS_REPORTPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const SIM_SC_SIMULATOR_STATUS_REPORT * sample);



/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
SIM_SC_SIMULATOR_STATUS_REPORTPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
SIM_SC_SIMULATOR_STATUS_REPORTPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
SIM_SC_SIMULATOR_STATUS_REPORTPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const SIM_SC_SIMULATOR_STATUS_REPORT *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
SIM_SC_SIMULATOR_STATUS_REPORTPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    SIM_SC_SIMULATOR_STATUS_REPORT * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
SIM_SC_SIMULATOR_STATUS_REPORTPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    SIM_SC_SIMULATOR_STATUS_REPORT ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
SIM_SC_SIMULATOR_STATUS_REPORTPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    SIM_SC_SIMULATOR_STATUS_REPORT *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
SIM_SC_SIMULATOR_STATUS_REPORTPlugin_new(void);

NDDSUSERDllExport extern void
SIM_SC_SIMULATOR_STATUS_REPORTPlugin_delete(struct PRESTypePlugin *);

#define SC_SER_LINK_CONNECTION_COMMAND_LAST_MEMBER_ID 0

#define SC_SER_LINK_CONNECTION_COMMANDPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define SC_SER_LINK_CONNECTION_COMMANDPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define SC_SER_LINK_CONNECTION_COMMANDPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define SC_SER_LINK_CONNECTION_COMMANDPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define SC_SER_LINK_CONNECTION_COMMANDPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define SC_SER_LINK_CONNECTION_COMMANDPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern SC_SER_LINK_CONNECTION_COMMAND*
SC_SER_LINK_CONNECTION_COMMANDPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern SC_SER_LINK_CONNECTION_COMMAND*
SC_SER_LINK_CONNECTION_COMMANDPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
SC_SER_LINK_CONNECTION_COMMANDPluginSupport_copy_data(
    SC_SER_LINK_CONNECTION_COMMAND *out,
    const SC_SER_LINK_CONNECTION_COMMAND *in);

NDDSUSERDllExport extern void 
SC_SER_LINK_CONNECTION_COMMANDPluginSupport_destroy_data_ex(
    SC_SER_LINK_CONNECTION_COMMAND *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
SC_SER_LINK_CONNECTION_COMMANDPluginSupport_destroy_data(
    SC_SER_LINK_CONNECTION_COMMAND *sample);

NDDSUSERDllExport extern void 
SC_SER_LINK_CONNECTION_COMMANDPluginSupport_print_data(
    const SC_SER_LINK_CONNECTION_COMMAND *sample,
    const char *desc,
    unsigned int indent);


/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
SC_SER_LINK_CONNECTION_COMMANDPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
SC_SER_LINK_CONNECTION_COMMANDPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
SC_SER_LINK_CONNECTION_COMMANDPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
SC_SER_LINK_CONNECTION_COMMANDPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);


NDDSUSERDllExport extern RTIBool 
SC_SER_LINK_CONNECTION_COMMANDPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    SC_SER_LINK_CONNECTION_COMMAND *out,
    const SC_SER_LINK_CONNECTION_COMMAND *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
SC_SER_LINK_CONNECTION_COMMANDPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const SC_SER_LINK_CONNECTION_COMMAND *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
SC_SER_LINK_CONNECTION_COMMANDPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    SC_SER_LINK_CONNECTION_COMMAND *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
SC_SER_LINK_CONNECTION_COMMANDPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    SC_SER_LINK_CONNECTION_COMMAND **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);




NDDSUSERDllExport extern RTIBool
SC_SER_LINK_CONNECTION_COMMANDPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
SC_SER_LINK_CONNECTION_COMMANDPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
SC_SER_LINK_CONNECTION_COMMANDPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
SC_SER_LINK_CONNECTION_COMMANDPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const SC_SER_LINK_CONNECTION_COMMAND * sample);



/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
SC_SER_LINK_CONNECTION_COMMANDPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
SC_SER_LINK_CONNECTION_COMMANDPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
SC_SER_LINK_CONNECTION_COMMANDPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const SC_SER_LINK_CONNECTION_COMMAND *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
SC_SER_LINK_CONNECTION_COMMANDPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    SC_SER_LINK_CONNECTION_COMMAND * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
SC_SER_LINK_CONNECTION_COMMANDPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    SC_SER_LINK_CONNECTION_COMMAND ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
SC_SER_LINK_CONNECTION_COMMANDPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    SC_SER_LINK_CONNECTION_COMMAND *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
SC_SER_LINK_CONNECTION_COMMANDPlugin_new(void);

NDDSUSERDllExport extern void
SC_SER_LINK_CONNECTION_COMMANDPlugin_delete(struct PRESTypePlugin *);

#define SER_SC_LINK_CONNECTION_COMMAND_ACK_LAST_MEMBER_ID 0

#define SER_SC_LINK_CONNECTION_COMMAND_ACKPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define SER_SC_LINK_CONNECTION_COMMAND_ACKPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define SER_SC_LINK_CONNECTION_COMMAND_ACKPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define SER_SC_LINK_CONNECTION_COMMAND_ACKPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define SER_SC_LINK_CONNECTION_COMMAND_ACKPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define SER_SC_LINK_CONNECTION_COMMAND_ACKPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern SER_SC_LINK_CONNECTION_COMMAND_ACK*
SER_SC_LINK_CONNECTION_COMMAND_ACKPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern SER_SC_LINK_CONNECTION_COMMAND_ACK*
SER_SC_LINK_CONNECTION_COMMAND_ACKPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
SER_SC_LINK_CONNECTION_COMMAND_ACKPluginSupport_copy_data(
    SER_SC_LINK_CONNECTION_COMMAND_ACK *out,
    const SER_SC_LINK_CONNECTION_COMMAND_ACK *in);

NDDSUSERDllExport extern void 
SER_SC_LINK_CONNECTION_COMMAND_ACKPluginSupport_destroy_data_ex(
    SER_SC_LINK_CONNECTION_COMMAND_ACK *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
SER_SC_LINK_CONNECTION_COMMAND_ACKPluginSupport_destroy_data(
    SER_SC_LINK_CONNECTION_COMMAND_ACK *sample);

NDDSUSERDllExport extern void 
SER_SC_LINK_CONNECTION_COMMAND_ACKPluginSupport_print_data(
    const SER_SC_LINK_CONNECTION_COMMAND_ACK *sample,
    const char *desc,
    unsigned int indent);


/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
SER_SC_LINK_CONNECTION_COMMAND_ACKPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
SER_SC_LINK_CONNECTION_COMMAND_ACKPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
SER_SC_LINK_CONNECTION_COMMAND_ACKPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
SER_SC_LINK_CONNECTION_COMMAND_ACKPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);


NDDSUSERDllExport extern RTIBool 
SER_SC_LINK_CONNECTION_COMMAND_ACKPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    SER_SC_LINK_CONNECTION_COMMAND_ACK *out,
    const SER_SC_LINK_CONNECTION_COMMAND_ACK *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
SER_SC_LINK_CONNECTION_COMMAND_ACKPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const SER_SC_LINK_CONNECTION_COMMAND_ACK *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
SER_SC_LINK_CONNECTION_COMMAND_ACKPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    SER_SC_LINK_CONNECTION_COMMAND_ACK *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
SER_SC_LINK_CONNECTION_COMMAND_ACKPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    SER_SC_LINK_CONNECTION_COMMAND_ACK **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);




NDDSUSERDllExport extern RTIBool
SER_SC_LINK_CONNECTION_COMMAND_ACKPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
SER_SC_LINK_CONNECTION_COMMAND_ACKPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
SER_SC_LINK_CONNECTION_COMMAND_ACKPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
SER_SC_LINK_CONNECTION_COMMAND_ACKPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const SER_SC_LINK_CONNECTION_COMMAND_ACK * sample);



/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
SER_SC_LINK_CONNECTION_COMMAND_ACKPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
SER_SC_LINK_CONNECTION_COMMAND_ACKPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
SER_SC_LINK_CONNECTION_COMMAND_ACKPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const SER_SC_LINK_CONNECTION_COMMAND_ACK *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
SER_SC_LINK_CONNECTION_COMMAND_ACKPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    SER_SC_LINK_CONNECTION_COMMAND_ACK * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
SER_SC_LINK_CONNECTION_COMMAND_ACKPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    SER_SC_LINK_CONNECTION_COMMAND_ACK ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
SER_SC_LINK_CONNECTION_COMMAND_ACKPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    SER_SC_LINK_CONNECTION_COMMAND_ACK *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
SER_SC_LINK_CONNECTION_COMMAND_ACKPlugin_new(void);

NDDSUSERDllExport extern void
SER_SC_LINK_CONNECTION_COMMAND_ACKPlugin_delete(struct PRESTypePlugin *);

#define SC_SIM_SIMULATION_MANAGEMENT_COMMAND_LAST_MEMBER_ID 0

#define SC_SIM_SIMULATION_MANAGEMENT_COMMANDPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define SC_SIM_SIMULATION_MANAGEMENT_COMMANDPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define SC_SIM_SIMULATION_MANAGEMENT_COMMANDPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define SC_SIM_SIMULATION_MANAGEMENT_COMMANDPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define SC_SIM_SIMULATION_MANAGEMENT_COMMANDPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define SC_SIM_SIMULATION_MANAGEMENT_COMMANDPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern SC_SIM_SIMULATION_MANAGEMENT_COMMAND*
SC_SIM_SIMULATION_MANAGEMENT_COMMANDPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern SC_SIM_SIMULATION_MANAGEMENT_COMMAND*
SC_SIM_SIMULATION_MANAGEMENT_COMMANDPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
SC_SIM_SIMULATION_MANAGEMENT_COMMANDPluginSupport_copy_data(
    SC_SIM_SIMULATION_MANAGEMENT_COMMAND *out,
    const SC_SIM_SIMULATION_MANAGEMENT_COMMAND *in);

NDDSUSERDllExport extern void 
SC_SIM_SIMULATION_MANAGEMENT_COMMANDPluginSupport_destroy_data_ex(
    SC_SIM_SIMULATION_MANAGEMENT_COMMAND *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
SC_SIM_SIMULATION_MANAGEMENT_COMMANDPluginSupport_destroy_data(
    SC_SIM_SIMULATION_MANAGEMENT_COMMAND *sample);

NDDSUSERDllExport extern void 
SC_SIM_SIMULATION_MANAGEMENT_COMMANDPluginSupport_print_data(
    const SC_SIM_SIMULATION_MANAGEMENT_COMMAND *sample,
    const char *desc,
    unsigned int indent);


/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
SC_SIM_SIMULATION_MANAGEMENT_COMMANDPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
SC_SIM_SIMULATION_MANAGEMENT_COMMANDPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
SC_SIM_SIMULATION_MANAGEMENT_COMMANDPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
SC_SIM_SIMULATION_MANAGEMENT_COMMANDPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);


NDDSUSERDllExport extern RTIBool 
SC_SIM_SIMULATION_MANAGEMENT_COMMANDPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_SIMULATION_MANAGEMENT_COMMAND *out,
    const SC_SIM_SIMULATION_MANAGEMENT_COMMAND *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
SC_SIM_SIMULATION_MANAGEMENT_COMMANDPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const SC_SIM_SIMULATION_MANAGEMENT_COMMAND *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
SC_SIM_SIMULATION_MANAGEMENT_COMMANDPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_SIMULATION_MANAGEMENT_COMMAND *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
SC_SIM_SIMULATION_MANAGEMENT_COMMANDPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_SIMULATION_MANAGEMENT_COMMAND **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);




NDDSUSERDllExport extern RTIBool
SC_SIM_SIMULATION_MANAGEMENT_COMMANDPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
SC_SIM_SIMULATION_MANAGEMENT_COMMANDPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
SC_SIM_SIMULATION_MANAGEMENT_COMMANDPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
SC_SIM_SIMULATION_MANAGEMENT_COMMANDPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const SC_SIM_SIMULATION_MANAGEMENT_COMMAND * sample);



/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
SC_SIM_SIMULATION_MANAGEMENT_COMMANDPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
SC_SIM_SIMULATION_MANAGEMENT_COMMANDPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
SC_SIM_SIMULATION_MANAGEMENT_COMMANDPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const SC_SIM_SIMULATION_MANAGEMENT_COMMAND *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
SC_SIM_SIMULATION_MANAGEMENT_COMMANDPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_SIMULATION_MANAGEMENT_COMMAND * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
SC_SIM_SIMULATION_MANAGEMENT_COMMANDPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_SIMULATION_MANAGEMENT_COMMAND ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
SC_SIM_SIMULATION_MANAGEMENT_COMMANDPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_SIMULATION_MANAGEMENT_COMMAND *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
SC_SIM_SIMULATION_MANAGEMENT_COMMANDPlugin_new(void);

NDDSUSERDllExport extern void
SC_SIM_SIMULATION_MANAGEMENT_COMMANDPlugin_delete(struct PRESTypePlugin *);

#define SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK_LAST_MEMBER_ID 0

#define SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK*
SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK*
SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKPluginSupport_copy_data(
    SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK *out,
    const SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK *in);

NDDSUSERDllExport extern void 
SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKPluginSupport_destroy_data_ex(
    SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKPluginSupport_destroy_data(
    SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK *sample);

NDDSUSERDllExport extern void 
SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKPluginSupport_print_data(
    const SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK *sample,
    const char *desc,
    unsigned int indent);


/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);


NDDSUSERDllExport extern RTIBool 
SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK *out,
    const SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);




NDDSUSERDllExport extern RTIBool
SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK * sample);



/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKPlugin_new(void);

NDDSUSERDllExport extern void
SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKPlugin_delete(struct PRESTypePlugin *);

#define SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_LAST_MEMBER_ID 0

#define SC_SIM_PARAMETER_DISTRIBUTION_COMMANDPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define SC_SIM_PARAMETER_DISTRIBUTION_COMMANDPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define SC_SIM_PARAMETER_DISTRIBUTION_COMMANDPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define SC_SIM_PARAMETER_DISTRIBUTION_COMMANDPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define SC_SIM_PARAMETER_DISTRIBUTION_COMMANDPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define SC_SIM_PARAMETER_DISTRIBUTION_COMMANDPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern SC_SIM_PARAMETER_DISTRIBUTION_COMMAND*
SC_SIM_PARAMETER_DISTRIBUTION_COMMANDPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern SC_SIM_PARAMETER_DISTRIBUTION_COMMAND*
SC_SIM_PARAMETER_DISTRIBUTION_COMMANDPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
SC_SIM_PARAMETER_DISTRIBUTION_COMMANDPluginSupport_copy_data(
    SC_SIM_PARAMETER_DISTRIBUTION_COMMAND *out,
    const SC_SIM_PARAMETER_DISTRIBUTION_COMMAND *in);

NDDSUSERDllExport extern void 
SC_SIM_PARAMETER_DISTRIBUTION_COMMANDPluginSupport_destroy_data_ex(
    SC_SIM_PARAMETER_DISTRIBUTION_COMMAND *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
SC_SIM_PARAMETER_DISTRIBUTION_COMMANDPluginSupport_destroy_data(
    SC_SIM_PARAMETER_DISTRIBUTION_COMMAND *sample);

NDDSUSERDllExport extern void 
SC_SIM_PARAMETER_DISTRIBUTION_COMMANDPluginSupport_print_data(
    const SC_SIM_PARAMETER_DISTRIBUTION_COMMAND *sample,
    const char *desc,
    unsigned int indent);


/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
SC_SIM_PARAMETER_DISTRIBUTION_COMMANDPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
SC_SIM_PARAMETER_DISTRIBUTION_COMMANDPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
SC_SIM_PARAMETER_DISTRIBUTION_COMMANDPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
SC_SIM_PARAMETER_DISTRIBUTION_COMMANDPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);


NDDSUSERDllExport extern RTIBool 
SC_SIM_PARAMETER_DISTRIBUTION_COMMANDPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_PARAMETER_DISTRIBUTION_COMMAND *out,
    const SC_SIM_PARAMETER_DISTRIBUTION_COMMAND *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
SC_SIM_PARAMETER_DISTRIBUTION_COMMANDPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const SC_SIM_PARAMETER_DISTRIBUTION_COMMAND *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
SC_SIM_PARAMETER_DISTRIBUTION_COMMANDPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_PARAMETER_DISTRIBUTION_COMMAND *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
SC_SIM_PARAMETER_DISTRIBUTION_COMMANDPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_PARAMETER_DISTRIBUTION_COMMAND **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);




NDDSUSERDllExport extern RTIBool
SC_SIM_PARAMETER_DISTRIBUTION_COMMANDPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
SC_SIM_PARAMETER_DISTRIBUTION_COMMANDPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
SC_SIM_PARAMETER_DISTRIBUTION_COMMANDPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
SC_SIM_PARAMETER_DISTRIBUTION_COMMANDPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const SC_SIM_PARAMETER_DISTRIBUTION_COMMAND * sample);



/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
SC_SIM_PARAMETER_DISTRIBUTION_COMMANDPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
SC_SIM_PARAMETER_DISTRIBUTION_COMMANDPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
SC_SIM_PARAMETER_DISTRIBUTION_COMMANDPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const SC_SIM_PARAMETER_DISTRIBUTION_COMMAND *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
SC_SIM_PARAMETER_DISTRIBUTION_COMMANDPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_PARAMETER_DISTRIBUTION_COMMAND * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
SC_SIM_PARAMETER_DISTRIBUTION_COMMANDPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_PARAMETER_DISTRIBUTION_COMMAND ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
SC_SIM_PARAMETER_DISTRIBUTION_COMMANDPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_PARAMETER_DISTRIBUTION_COMMAND *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
SC_SIM_PARAMETER_DISTRIBUTION_COMMANDPlugin_new(void);

NDDSUSERDllExport extern void
SC_SIM_PARAMETER_DISTRIBUTION_COMMANDPlugin_delete(struct PRESTypePlugin *);

#define SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK_LAST_MEMBER_ID 0

#define SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK*
SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK*
SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKPluginSupport_copy_data(
    SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK *out,
    const SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK *in);

NDDSUSERDllExport extern void 
SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKPluginSupport_destroy_data_ex(
    SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKPluginSupport_destroy_data(
    SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK *sample);

NDDSUSERDllExport extern void 
SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKPluginSupport_print_data(
    const SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK *sample,
    const char *desc,
    unsigned int indent);


/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);


NDDSUSERDllExport extern RTIBool 
SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK *out,
    const SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);




NDDSUSERDllExport extern RTIBool
SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK * sample);



/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKPlugin_new(void);

NDDSUSERDllExport extern void
SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKPlugin_delete(struct PRESTypePlugin *);

#define SC_SIM_SIMULATOR_PARAMETER_LAST_MEMBER_ID 0

#define SC_SIM_SIMULATOR_PARAMETERPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define SC_SIM_SIMULATOR_PARAMETERPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define SC_SIM_SIMULATOR_PARAMETERPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define SC_SIM_SIMULATOR_PARAMETERPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define SC_SIM_SIMULATOR_PARAMETERPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define SC_SIM_SIMULATOR_PARAMETERPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern SC_SIM_SIMULATOR_PARAMETER*
SC_SIM_SIMULATOR_PARAMETERPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern SC_SIM_SIMULATOR_PARAMETER*
SC_SIM_SIMULATOR_PARAMETERPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
SC_SIM_SIMULATOR_PARAMETERPluginSupport_copy_data(
    SC_SIM_SIMULATOR_PARAMETER *out,
    const SC_SIM_SIMULATOR_PARAMETER *in);

NDDSUSERDllExport extern void 
SC_SIM_SIMULATOR_PARAMETERPluginSupport_destroy_data_ex(
    SC_SIM_SIMULATOR_PARAMETER *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
SC_SIM_SIMULATOR_PARAMETERPluginSupport_destroy_data(
    SC_SIM_SIMULATOR_PARAMETER *sample);

NDDSUSERDllExport extern void 
SC_SIM_SIMULATOR_PARAMETERPluginSupport_print_data(
    const SC_SIM_SIMULATOR_PARAMETER *sample,
    const char *desc,
    unsigned int indent);


/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
SC_SIM_SIMULATOR_PARAMETERPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
SC_SIM_SIMULATOR_PARAMETERPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
SC_SIM_SIMULATOR_PARAMETERPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
SC_SIM_SIMULATOR_PARAMETERPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);


NDDSUSERDllExport extern RTIBool 
SC_SIM_SIMULATOR_PARAMETERPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_SIMULATOR_PARAMETER *out,
    const SC_SIM_SIMULATOR_PARAMETER *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
SC_SIM_SIMULATOR_PARAMETERPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const SC_SIM_SIMULATOR_PARAMETER *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
SC_SIM_SIMULATOR_PARAMETERPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_SIMULATOR_PARAMETER *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
SC_SIM_SIMULATOR_PARAMETERPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_SIMULATOR_PARAMETER **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);




NDDSUSERDllExport extern RTIBool
SC_SIM_SIMULATOR_PARAMETERPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
SC_SIM_SIMULATOR_PARAMETERPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
SC_SIM_SIMULATOR_PARAMETERPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
SC_SIM_SIMULATOR_PARAMETERPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const SC_SIM_SIMULATOR_PARAMETER * sample);



/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
SC_SIM_SIMULATOR_PARAMETERPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
SC_SIM_SIMULATOR_PARAMETERPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
SC_SIM_SIMULATOR_PARAMETERPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const SC_SIM_SIMULATOR_PARAMETER *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
SC_SIM_SIMULATOR_PARAMETERPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_SIMULATOR_PARAMETER * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
SC_SIM_SIMULATOR_PARAMETERPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_SIMULATOR_PARAMETER ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
SC_SIM_SIMULATOR_PARAMETERPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_SIMULATOR_PARAMETER *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
SC_SIM_SIMULATOR_PARAMETERPlugin_new(void);

NDDSUSERDllExport extern void
SC_SIM_SIMULATOR_PARAMETERPlugin_delete(struct PRESTypePlugin *);

#define SIM_SC_SIMULATOR_PARAMETER_ACK_LAST_MEMBER_ID 0

#define SIM_SC_SIMULATOR_PARAMETER_ACKPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define SIM_SC_SIMULATOR_PARAMETER_ACKPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define SIM_SC_SIMULATOR_PARAMETER_ACKPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define SIM_SC_SIMULATOR_PARAMETER_ACKPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define SIM_SC_SIMULATOR_PARAMETER_ACKPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define SIM_SC_SIMULATOR_PARAMETER_ACKPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern SIM_SC_SIMULATOR_PARAMETER_ACK*
SIM_SC_SIMULATOR_PARAMETER_ACKPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern SIM_SC_SIMULATOR_PARAMETER_ACK*
SIM_SC_SIMULATOR_PARAMETER_ACKPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
SIM_SC_SIMULATOR_PARAMETER_ACKPluginSupport_copy_data(
    SIM_SC_SIMULATOR_PARAMETER_ACK *out,
    const SIM_SC_SIMULATOR_PARAMETER_ACK *in);

NDDSUSERDllExport extern void 
SIM_SC_SIMULATOR_PARAMETER_ACKPluginSupport_destroy_data_ex(
    SIM_SC_SIMULATOR_PARAMETER_ACK *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
SIM_SC_SIMULATOR_PARAMETER_ACKPluginSupport_destroy_data(
    SIM_SC_SIMULATOR_PARAMETER_ACK *sample);

NDDSUSERDllExport extern void 
SIM_SC_SIMULATOR_PARAMETER_ACKPluginSupport_print_data(
    const SIM_SC_SIMULATOR_PARAMETER_ACK *sample,
    const char *desc,
    unsigned int indent);


/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
SIM_SC_SIMULATOR_PARAMETER_ACKPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
SIM_SC_SIMULATOR_PARAMETER_ACKPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
SIM_SC_SIMULATOR_PARAMETER_ACKPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
SIM_SC_SIMULATOR_PARAMETER_ACKPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);


NDDSUSERDllExport extern RTIBool 
SIM_SC_SIMULATOR_PARAMETER_ACKPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    SIM_SC_SIMULATOR_PARAMETER_ACK *out,
    const SIM_SC_SIMULATOR_PARAMETER_ACK *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
SIM_SC_SIMULATOR_PARAMETER_ACKPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const SIM_SC_SIMULATOR_PARAMETER_ACK *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
SIM_SC_SIMULATOR_PARAMETER_ACKPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    SIM_SC_SIMULATOR_PARAMETER_ACK *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
SIM_SC_SIMULATOR_PARAMETER_ACKPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    SIM_SC_SIMULATOR_PARAMETER_ACK **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);




NDDSUSERDllExport extern RTIBool
SIM_SC_SIMULATOR_PARAMETER_ACKPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
SIM_SC_SIMULATOR_PARAMETER_ACKPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
SIM_SC_SIMULATOR_PARAMETER_ACKPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
SIM_SC_SIMULATOR_PARAMETER_ACKPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const SIM_SC_SIMULATOR_PARAMETER_ACK * sample);



/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
SIM_SC_SIMULATOR_PARAMETER_ACKPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
SIM_SC_SIMULATOR_PARAMETER_ACKPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
SIM_SC_SIMULATOR_PARAMETER_ACKPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const SIM_SC_SIMULATOR_PARAMETER_ACK *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
SIM_SC_SIMULATOR_PARAMETER_ACKPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    SIM_SC_SIMULATOR_PARAMETER_ACK * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
SIM_SC_SIMULATOR_PARAMETER_ACKPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    SIM_SC_SIMULATOR_PARAMETER_ACK ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
SIM_SC_SIMULATOR_PARAMETER_ACKPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    SIM_SC_SIMULATOR_PARAMETER_ACK *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
SIM_SC_SIMULATOR_PARAMETER_ACKPlugin_new(void);

NDDSUSERDllExport extern void
SIM_SC_SIMULATOR_PARAMETER_ACKPlugin_delete(struct PRESTypePlugin *);

#define SC_SIM_ENVIRONMENT_LAST_MEMBER_ID 0

#define SC_SIM_ENVIRONMENTPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define SC_SIM_ENVIRONMENTPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define SC_SIM_ENVIRONMENTPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define SC_SIM_ENVIRONMENTPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define SC_SIM_ENVIRONMENTPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define SC_SIM_ENVIRONMENTPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern SC_SIM_ENVIRONMENT*
SC_SIM_ENVIRONMENTPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern SC_SIM_ENVIRONMENT*
SC_SIM_ENVIRONMENTPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
SC_SIM_ENVIRONMENTPluginSupport_copy_data(
    SC_SIM_ENVIRONMENT *out,
    const SC_SIM_ENVIRONMENT *in);

NDDSUSERDllExport extern void 
SC_SIM_ENVIRONMENTPluginSupport_destroy_data_ex(
    SC_SIM_ENVIRONMENT *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
SC_SIM_ENVIRONMENTPluginSupport_destroy_data(
    SC_SIM_ENVIRONMENT *sample);

NDDSUSERDllExport extern void 
SC_SIM_ENVIRONMENTPluginSupport_print_data(
    const SC_SIM_ENVIRONMENT *sample,
    const char *desc,
    unsigned int indent);


/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
SC_SIM_ENVIRONMENTPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
SC_SIM_ENVIRONMENTPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
SC_SIM_ENVIRONMENTPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
SC_SIM_ENVIRONMENTPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);


NDDSUSERDllExport extern RTIBool 
SC_SIM_ENVIRONMENTPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_ENVIRONMENT *out,
    const SC_SIM_ENVIRONMENT *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
SC_SIM_ENVIRONMENTPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const SC_SIM_ENVIRONMENT *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
SC_SIM_ENVIRONMENTPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_ENVIRONMENT *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
SC_SIM_ENVIRONMENTPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_ENVIRONMENT **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);




NDDSUSERDllExport extern RTIBool
SC_SIM_ENVIRONMENTPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
SC_SIM_ENVIRONMENTPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
SC_SIM_ENVIRONMENTPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
SC_SIM_ENVIRONMENTPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const SC_SIM_ENVIRONMENT * sample);



/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
SC_SIM_ENVIRONMENTPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
SC_SIM_ENVIRONMENTPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
SC_SIM_ENVIRONMENTPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const SC_SIM_ENVIRONMENT *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
SC_SIM_ENVIRONMENTPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_ENVIRONMENT * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
SC_SIM_ENVIRONMENTPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_ENVIRONMENT ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
SC_SIM_ENVIRONMENTPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_ENVIRONMENT *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
SC_SIM_ENVIRONMENTPlugin_new(void);

NDDSUSERDllExport extern void
SC_SIM_ENVIRONMENTPlugin_delete(struct PRESTypePlugin *);

#define SC_SIM_ENTITY_LAST_MEMBER_ID 0

#define SC_SIM_ENTITYPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define SC_SIM_ENTITYPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define SC_SIM_ENTITYPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define SC_SIM_ENTITYPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define SC_SIM_ENTITYPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define SC_SIM_ENTITYPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern SC_SIM_ENTITY*
SC_SIM_ENTITYPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern SC_SIM_ENTITY*
SC_SIM_ENTITYPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
SC_SIM_ENTITYPluginSupport_copy_data(
    SC_SIM_ENTITY *out,
    const SC_SIM_ENTITY *in);

NDDSUSERDllExport extern void 
SC_SIM_ENTITYPluginSupport_destroy_data_ex(
    SC_SIM_ENTITY *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
SC_SIM_ENTITYPluginSupport_destroy_data(
    SC_SIM_ENTITY *sample);

NDDSUSERDllExport extern void 
SC_SIM_ENTITYPluginSupport_print_data(
    const SC_SIM_ENTITY *sample,
    const char *desc,
    unsigned int indent);


/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
SC_SIM_ENTITYPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
SC_SIM_ENTITYPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
SC_SIM_ENTITYPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
SC_SIM_ENTITYPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);


NDDSUSERDllExport extern RTIBool 
SC_SIM_ENTITYPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_ENTITY *out,
    const SC_SIM_ENTITY *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
SC_SIM_ENTITYPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const SC_SIM_ENTITY *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
SC_SIM_ENTITYPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_ENTITY *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
SC_SIM_ENTITYPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_ENTITY **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);




NDDSUSERDllExport extern RTIBool
SC_SIM_ENTITYPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
SC_SIM_ENTITYPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
SC_SIM_ENTITYPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
SC_SIM_ENTITYPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const SC_SIM_ENTITY * sample);



/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
SC_SIM_ENTITYPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
SC_SIM_ENTITYPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
SC_SIM_ENTITYPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const SC_SIM_ENTITY *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
SC_SIM_ENTITYPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_ENTITY * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
SC_SIM_ENTITYPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_ENTITY ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
SC_SIM_ENTITYPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_ENTITY *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
SC_SIM_ENTITYPlugin_new(void);

NDDSUSERDllExport extern void
SC_SIM_ENTITYPlugin_delete(struct PRESTypePlugin *);

#define SC_SIM_ENTITY_STATE_LAST_MEMBER_ID 0

#define SC_SIM_ENTITY_STATEPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define SC_SIM_ENTITY_STATEPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define SC_SIM_ENTITY_STATEPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define SC_SIM_ENTITY_STATEPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define SC_SIM_ENTITY_STATEPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define SC_SIM_ENTITY_STATEPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern SC_SIM_ENTITY_STATE*
SC_SIM_ENTITY_STATEPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern SC_SIM_ENTITY_STATE*
SC_SIM_ENTITY_STATEPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
SC_SIM_ENTITY_STATEPluginSupport_copy_data(
    SC_SIM_ENTITY_STATE *out,
    const SC_SIM_ENTITY_STATE *in);

NDDSUSERDllExport extern void 
SC_SIM_ENTITY_STATEPluginSupport_destroy_data_ex(
    SC_SIM_ENTITY_STATE *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
SC_SIM_ENTITY_STATEPluginSupport_destroy_data(
    SC_SIM_ENTITY_STATE *sample);

NDDSUSERDllExport extern void 
SC_SIM_ENTITY_STATEPluginSupport_print_data(
    const SC_SIM_ENTITY_STATE *sample,
    const char *desc,
    unsigned int indent);


/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
SC_SIM_ENTITY_STATEPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
SC_SIM_ENTITY_STATEPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
SC_SIM_ENTITY_STATEPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
SC_SIM_ENTITY_STATEPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);


NDDSUSERDllExport extern RTIBool 
SC_SIM_ENTITY_STATEPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_ENTITY_STATE *out,
    const SC_SIM_ENTITY_STATE *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
SC_SIM_ENTITY_STATEPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const SC_SIM_ENTITY_STATE *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
SC_SIM_ENTITY_STATEPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_ENTITY_STATE *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
SC_SIM_ENTITY_STATEPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_ENTITY_STATE **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);




NDDSUSERDllExport extern RTIBool
SC_SIM_ENTITY_STATEPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
SC_SIM_ENTITY_STATEPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
SC_SIM_ENTITY_STATEPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
SC_SIM_ENTITY_STATEPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const SC_SIM_ENTITY_STATE * sample);



/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
SC_SIM_ENTITY_STATEPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
SC_SIM_ENTITY_STATEPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
SC_SIM_ENTITY_STATEPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const SC_SIM_ENTITY_STATE *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
SC_SIM_ENTITY_STATEPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_ENTITY_STATE * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
SC_SIM_ENTITY_STATEPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_ENTITY_STATE ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
SC_SIM_ENTITY_STATEPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_ENTITY_STATE *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
SC_SIM_ENTITY_STATEPlugin_new(void);

NDDSUSERDllExport extern void
SC_SIM_ENTITY_STATEPlugin_delete(struct PRESTypePlugin *);

#define SC_SIM_OWNSHIP_LAST_MEMBER_ID 0

#define SC_SIM_OWNSHIPPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define SC_SIM_OWNSHIPPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define SC_SIM_OWNSHIPPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define SC_SIM_OWNSHIPPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define SC_SIM_OWNSHIPPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define SC_SIM_OWNSHIPPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern SC_SIM_OWNSHIP*
SC_SIM_OWNSHIPPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern SC_SIM_OWNSHIP*
SC_SIM_OWNSHIPPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
SC_SIM_OWNSHIPPluginSupport_copy_data(
    SC_SIM_OWNSHIP *out,
    const SC_SIM_OWNSHIP *in);

NDDSUSERDllExport extern void 
SC_SIM_OWNSHIPPluginSupport_destroy_data_ex(
    SC_SIM_OWNSHIP *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
SC_SIM_OWNSHIPPluginSupport_destroy_data(
    SC_SIM_OWNSHIP *sample);

NDDSUSERDllExport extern void 
SC_SIM_OWNSHIPPluginSupport_print_data(
    const SC_SIM_OWNSHIP *sample,
    const char *desc,
    unsigned int indent);


/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
SC_SIM_OWNSHIPPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
SC_SIM_OWNSHIPPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
SC_SIM_OWNSHIPPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
SC_SIM_OWNSHIPPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);


NDDSUSERDllExport extern RTIBool 
SC_SIM_OWNSHIPPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_OWNSHIP *out,
    const SC_SIM_OWNSHIP *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
SC_SIM_OWNSHIPPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const SC_SIM_OWNSHIP *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
SC_SIM_OWNSHIPPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_OWNSHIP *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
SC_SIM_OWNSHIPPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_OWNSHIP **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);




NDDSUSERDllExport extern RTIBool
SC_SIM_OWNSHIPPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
SC_SIM_OWNSHIPPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
SC_SIM_OWNSHIPPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
SC_SIM_OWNSHIPPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const SC_SIM_OWNSHIP * sample);



/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
SC_SIM_OWNSHIPPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
SC_SIM_OWNSHIPPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
SC_SIM_OWNSHIPPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const SC_SIM_OWNSHIP *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
SC_SIM_OWNSHIPPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_OWNSHIP * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
SC_SIM_OWNSHIPPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_OWNSHIP ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
SC_SIM_OWNSHIPPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_OWNSHIP *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
SC_SIM_OWNSHIPPlugin_new(void);

NDDSUSERDllExport extern void
SC_SIM_OWNSHIPPlugin_delete(struct PRESTypePlugin *);

#define SC_SIM_OWNSHIP_STATE_LAST_MEMBER_ID 0

#define SC_SIM_OWNSHIP_STATEPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define SC_SIM_OWNSHIP_STATEPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define SC_SIM_OWNSHIP_STATEPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define SC_SIM_OWNSHIP_STATEPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define SC_SIM_OWNSHIP_STATEPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define SC_SIM_OWNSHIP_STATEPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern SC_SIM_OWNSHIP_STATE*
SC_SIM_OWNSHIP_STATEPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern SC_SIM_OWNSHIP_STATE*
SC_SIM_OWNSHIP_STATEPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
SC_SIM_OWNSHIP_STATEPluginSupport_copy_data(
    SC_SIM_OWNSHIP_STATE *out,
    const SC_SIM_OWNSHIP_STATE *in);

NDDSUSERDllExport extern void 
SC_SIM_OWNSHIP_STATEPluginSupport_destroy_data_ex(
    SC_SIM_OWNSHIP_STATE *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
SC_SIM_OWNSHIP_STATEPluginSupport_destroy_data(
    SC_SIM_OWNSHIP_STATE *sample);

NDDSUSERDllExport extern void 
SC_SIM_OWNSHIP_STATEPluginSupport_print_data(
    const SC_SIM_OWNSHIP_STATE *sample,
    const char *desc,
    unsigned int indent);


/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
SC_SIM_OWNSHIP_STATEPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
SC_SIM_OWNSHIP_STATEPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
SC_SIM_OWNSHIP_STATEPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
SC_SIM_OWNSHIP_STATEPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);


NDDSUSERDllExport extern RTIBool 
SC_SIM_OWNSHIP_STATEPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_OWNSHIP_STATE *out,
    const SC_SIM_OWNSHIP_STATE *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
SC_SIM_OWNSHIP_STATEPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const SC_SIM_OWNSHIP_STATE *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
SC_SIM_OWNSHIP_STATEPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_OWNSHIP_STATE *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
SC_SIM_OWNSHIP_STATEPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_OWNSHIP_STATE **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);




NDDSUSERDllExport extern RTIBool
SC_SIM_OWNSHIP_STATEPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
SC_SIM_OWNSHIP_STATEPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
SC_SIM_OWNSHIP_STATEPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
SC_SIM_OWNSHIP_STATEPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const SC_SIM_OWNSHIP_STATE * sample);



/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
SC_SIM_OWNSHIP_STATEPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
SC_SIM_OWNSHIP_STATEPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
SC_SIM_OWNSHIP_STATEPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const SC_SIM_OWNSHIP_STATE *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
SC_SIM_OWNSHIP_STATEPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_OWNSHIP_STATE * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
SC_SIM_OWNSHIP_STATEPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_OWNSHIP_STATE ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
SC_SIM_OWNSHIP_STATEPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    SC_SIM_OWNSHIP_STATE *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
SC_SIM_OWNSHIP_STATEPlugin_new(void);

NDDSUSERDllExport extern void
SC_SIM_OWNSHIP_STATEPlugin_delete(struct PRESTypePlugin *);

#define SIM_SC_MISSILE_CREATION_LAST_MEMBER_ID 0

#define SIM_SC_MISSILE_CREATIONPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define SIM_SC_MISSILE_CREATIONPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define SIM_SC_MISSILE_CREATIONPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define SIM_SC_MISSILE_CREATIONPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define SIM_SC_MISSILE_CREATIONPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define SIM_SC_MISSILE_CREATIONPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern SIM_SC_MISSILE_CREATION*
SIM_SC_MISSILE_CREATIONPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern SIM_SC_MISSILE_CREATION*
SIM_SC_MISSILE_CREATIONPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
SIM_SC_MISSILE_CREATIONPluginSupport_copy_data(
    SIM_SC_MISSILE_CREATION *out,
    const SIM_SC_MISSILE_CREATION *in);

NDDSUSERDllExport extern void 
SIM_SC_MISSILE_CREATIONPluginSupport_destroy_data_ex(
    SIM_SC_MISSILE_CREATION *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
SIM_SC_MISSILE_CREATIONPluginSupport_destroy_data(
    SIM_SC_MISSILE_CREATION *sample);

NDDSUSERDllExport extern void 
SIM_SC_MISSILE_CREATIONPluginSupport_print_data(
    const SIM_SC_MISSILE_CREATION *sample,
    const char *desc,
    unsigned int indent);


/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
SIM_SC_MISSILE_CREATIONPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
SIM_SC_MISSILE_CREATIONPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
SIM_SC_MISSILE_CREATIONPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
SIM_SC_MISSILE_CREATIONPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);


NDDSUSERDllExport extern RTIBool 
SIM_SC_MISSILE_CREATIONPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    SIM_SC_MISSILE_CREATION *out,
    const SIM_SC_MISSILE_CREATION *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
SIM_SC_MISSILE_CREATIONPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const SIM_SC_MISSILE_CREATION *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
SIM_SC_MISSILE_CREATIONPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    SIM_SC_MISSILE_CREATION *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
SIM_SC_MISSILE_CREATIONPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    SIM_SC_MISSILE_CREATION **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);




NDDSUSERDllExport extern RTIBool
SIM_SC_MISSILE_CREATIONPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
SIM_SC_MISSILE_CREATIONPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
SIM_SC_MISSILE_CREATIONPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
SIM_SC_MISSILE_CREATIONPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const SIM_SC_MISSILE_CREATION * sample);



/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
SIM_SC_MISSILE_CREATIONPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
SIM_SC_MISSILE_CREATIONPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
SIM_SC_MISSILE_CREATIONPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const SIM_SC_MISSILE_CREATION *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
SIM_SC_MISSILE_CREATIONPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    SIM_SC_MISSILE_CREATION * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
SIM_SC_MISSILE_CREATIONPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    SIM_SC_MISSILE_CREATION ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
SIM_SC_MISSILE_CREATIONPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    SIM_SC_MISSILE_CREATION *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
SIM_SC_MISSILE_CREATIONPlugin_new(void);

NDDSUSERDllExport extern void
SIM_SC_MISSILE_CREATIONPlugin_delete(struct PRESTypePlugin *);

#define SIM_SC_SHELL_CREATION_LAST_MEMBER_ID 0

#define SIM_SC_SHELL_CREATIONPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define SIM_SC_SHELL_CREATIONPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define SIM_SC_SHELL_CREATIONPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define SIM_SC_SHELL_CREATIONPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define SIM_SC_SHELL_CREATIONPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define SIM_SC_SHELL_CREATIONPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern SIM_SC_SHELL_CREATION*
SIM_SC_SHELL_CREATIONPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern SIM_SC_SHELL_CREATION*
SIM_SC_SHELL_CREATIONPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
SIM_SC_SHELL_CREATIONPluginSupport_copy_data(
    SIM_SC_SHELL_CREATION *out,
    const SIM_SC_SHELL_CREATION *in);

NDDSUSERDllExport extern void 
SIM_SC_SHELL_CREATIONPluginSupport_destroy_data_ex(
    SIM_SC_SHELL_CREATION *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
SIM_SC_SHELL_CREATIONPluginSupport_destroy_data(
    SIM_SC_SHELL_CREATION *sample);

NDDSUSERDllExport extern void 
SIM_SC_SHELL_CREATIONPluginSupport_print_data(
    const SIM_SC_SHELL_CREATION *sample,
    const char *desc,
    unsigned int indent);


/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
SIM_SC_SHELL_CREATIONPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
SIM_SC_SHELL_CREATIONPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
SIM_SC_SHELL_CREATIONPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
SIM_SC_SHELL_CREATIONPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);


NDDSUSERDllExport extern RTIBool 
SIM_SC_SHELL_CREATIONPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    SIM_SC_SHELL_CREATION *out,
    const SIM_SC_SHELL_CREATION *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
SIM_SC_SHELL_CREATIONPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const SIM_SC_SHELL_CREATION *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
SIM_SC_SHELL_CREATIONPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    SIM_SC_SHELL_CREATION *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
SIM_SC_SHELL_CREATIONPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    SIM_SC_SHELL_CREATION **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);




NDDSUSERDllExport extern RTIBool
SIM_SC_SHELL_CREATIONPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
SIM_SC_SHELL_CREATIONPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
SIM_SC_SHELL_CREATIONPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
SIM_SC_SHELL_CREATIONPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const SIM_SC_SHELL_CREATION * sample);



/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
SIM_SC_SHELL_CREATIONPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
SIM_SC_SHELL_CREATIONPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
SIM_SC_SHELL_CREATIONPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const SIM_SC_SHELL_CREATION *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
SIM_SC_SHELL_CREATIONPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    SIM_SC_SHELL_CREATION * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
SIM_SC_SHELL_CREATIONPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    SIM_SC_SHELL_CREATION ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
SIM_SC_SHELL_CREATIONPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    SIM_SC_SHELL_CREATION *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
SIM_SC_SHELL_CREATIONPlugin_new(void);

NDDSUSERDllExport extern void
SIM_SC_SHELL_CREATIONPlugin_delete(struct PRESTypePlugin *);

#ifdef __cplusplus
}
#endif

        
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif        

#endif /* rmOPV_ProtocolPlugin_139685288_h */
