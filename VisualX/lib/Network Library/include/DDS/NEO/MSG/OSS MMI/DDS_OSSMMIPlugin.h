
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from DDS_OSSMMI.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Data Distribution Service manual.
*/

#ifndef DDS_OSSMMIPlugin_1396059854_h
#define DDS_OSSMMIPlugin_1396059854_h

#include "DDS_OSSMMI.h"




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


#define DMSG_OSSMMI_SENSORSTATEPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_OSSMMI_SENSORSTATEPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_OSSMMI_SENSORSTATEPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_OSSMMI_SENSORSTATEPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_OSSMMI_SENSORSTATEPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_OSSMMI_SENSORSTATEPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_OSSMMI_SENSORSTATE*
DMSG_OSSMMI_SENSORSTATEPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_OSSMMI_SENSORSTATE*
DMSG_OSSMMI_SENSORSTATEPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_SENSORSTATEPluginSupport_copy_data(
    DMSG_OSSMMI_SENSORSTATE *out,
    const DMSG_OSSMMI_SENSORSTATE *in);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_SENSORSTATEPluginSupport_destroy_data_ex(
    DMSG_OSSMMI_SENSORSTATE *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_SENSORSTATEPluginSupport_destroy_data(
    DMSG_OSSMMI_SENSORSTATE *sample);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_SENSORSTATEPluginSupport_print_data(
    const DMSG_OSSMMI_SENSORSTATE *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_OSSMMI_SENSORSTATEPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_SENSORSTATEPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_OSSMMI_SENSORSTATEPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_SENSORSTATEPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_SENSORSTATEPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_SENSORSTATE *out,
    const DMSG_OSSMMI_SENSORSTATE *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_SENSORSTATEPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_OSSMMI_SENSORSTATE *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_SENSORSTATEPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_SENSORSTATE *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_SENSORSTATEPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_SENSORSTATE **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_OSSMMI_SENSORSTATEPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_OSSMMI_SENSORSTATEPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_OSSMMI_SENSORSTATEPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_OSSMMI_SENSORSTATEPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_OSSMMI_SENSORSTATE * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_OSSMMI_SENSORSTATEPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_OSSMMI_SENSORSTATEPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_SENSORSTATEPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_OSSMMI_SENSORSTATE *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_SENSORSTATEPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_SENSORSTATE * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_SENSORSTATEPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_SENSORSTATE ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_OSSMMI_SENSORSTATEPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_SENSORSTATE *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_OSSMMI_SENSORSTATEPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_OSSMMI_SENSORSTATEPlugin_delete(struct PRESTypePlugin *);


#define DMSG_OSSMMI_GPSPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_OSSMMI_GPSPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_OSSMMI_GPSPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_OSSMMI_GPSPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_OSSMMI_GPSPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_OSSMMI_GPSPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_OSSMMI_GPS*
DMSG_OSSMMI_GPSPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_OSSMMI_GPS*
DMSG_OSSMMI_GPSPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_GPSPluginSupport_copy_data(
    DMSG_OSSMMI_GPS *out,
    const DMSG_OSSMMI_GPS *in);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_GPSPluginSupport_destroy_data_ex(
    DMSG_OSSMMI_GPS *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_GPSPluginSupport_destroy_data(
    DMSG_OSSMMI_GPS *sample);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_GPSPluginSupport_print_data(
    const DMSG_OSSMMI_GPS *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_OSSMMI_GPSPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_GPSPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_OSSMMI_GPSPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_GPSPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_GPSPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_GPS *out,
    const DMSG_OSSMMI_GPS *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_GPSPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_OSSMMI_GPS *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_GPSPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_GPS *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_GPSPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_GPS **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_OSSMMI_GPSPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_OSSMMI_GPSPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_OSSMMI_GPSPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_OSSMMI_GPSPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_OSSMMI_GPS * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_OSSMMI_GPSPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_OSSMMI_GPSPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_GPSPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_OSSMMI_GPS *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_GPSPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_GPS * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_GPSPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_GPS ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_OSSMMI_GPSPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_GPS *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_OSSMMI_GPSPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_OSSMMI_GPSPlugin_delete(struct PRESTypePlugin *);


#define DMSG_OSSMMI_GYROPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_OSSMMI_GYROPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_OSSMMI_GYROPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_OSSMMI_GYROPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_OSSMMI_GYROPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_OSSMMI_GYROPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_OSSMMI_GYRO*
DMSG_OSSMMI_GYROPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_OSSMMI_GYRO*
DMSG_OSSMMI_GYROPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_GYROPluginSupport_copy_data(
    DMSG_OSSMMI_GYRO *out,
    const DMSG_OSSMMI_GYRO *in);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_GYROPluginSupport_destroy_data_ex(
    DMSG_OSSMMI_GYRO *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_GYROPluginSupport_destroy_data(
    DMSG_OSSMMI_GYRO *sample);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_GYROPluginSupport_print_data(
    const DMSG_OSSMMI_GYRO *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_OSSMMI_GYROPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_GYROPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_OSSMMI_GYROPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_GYROPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_GYROPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_GYRO *out,
    const DMSG_OSSMMI_GYRO *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_GYROPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_OSSMMI_GYRO *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_GYROPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_GYRO *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_GYROPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_GYRO **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_OSSMMI_GYROPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_OSSMMI_GYROPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_OSSMMI_GYROPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_OSSMMI_GYROPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_OSSMMI_GYRO * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_OSSMMI_GYROPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_OSSMMI_GYROPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_GYROPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_OSSMMI_GYRO *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_GYROPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_GYRO * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_GYROPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_GYRO ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_OSSMMI_GYROPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_GYRO *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_OSSMMI_GYROPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_OSSMMI_GYROPlugin_delete(struct PRESTypePlugin *);


#define DMSG_OSSMMI_EMLOGPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_OSSMMI_EMLOGPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_OSSMMI_EMLOGPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_OSSMMI_EMLOGPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_OSSMMI_EMLOGPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_OSSMMI_EMLOGPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_OSSMMI_EMLOG*
DMSG_OSSMMI_EMLOGPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_OSSMMI_EMLOG*
DMSG_OSSMMI_EMLOGPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_EMLOGPluginSupport_copy_data(
    DMSG_OSSMMI_EMLOG *out,
    const DMSG_OSSMMI_EMLOG *in);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_EMLOGPluginSupport_destroy_data_ex(
    DMSG_OSSMMI_EMLOG *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_EMLOGPluginSupport_destroy_data(
    DMSG_OSSMMI_EMLOG *sample);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_EMLOGPluginSupport_print_data(
    const DMSG_OSSMMI_EMLOG *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_OSSMMI_EMLOGPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_EMLOGPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_OSSMMI_EMLOGPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_EMLOGPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_EMLOGPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_EMLOG *out,
    const DMSG_OSSMMI_EMLOG *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_EMLOGPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_OSSMMI_EMLOG *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_EMLOGPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_EMLOG *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_EMLOGPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_EMLOG **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_OSSMMI_EMLOGPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_OSSMMI_EMLOGPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_OSSMMI_EMLOGPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_OSSMMI_EMLOGPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_OSSMMI_EMLOG * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_OSSMMI_EMLOGPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_OSSMMI_EMLOGPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_EMLOGPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_OSSMMI_EMLOG *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_EMLOGPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_EMLOG * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_EMLOGPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_EMLOG ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_OSSMMI_EMLOGPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_EMLOG *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_OSSMMI_EMLOGPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_OSSMMI_EMLOGPlugin_delete(struct PRESTypePlugin *);


#define DMSG_OSSMMI_WINDPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_OSSMMI_WINDPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_OSSMMI_WINDPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_OSSMMI_WINDPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_OSSMMI_WINDPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_OSSMMI_WINDPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_OSSMMI_WIND*
DMSG_OSSMMI_WINDPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_OSSMMI_WIND*
DMSG_OSSMMI_WINDPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_WINDPluginSupport_copy_data(
    DMSG_OSSMMI_WIND *out,
    const DMSG_OSSMMI_WIND *in);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_WINDPluginSupport_destroy_data_ex(
    DMSG_OSSMMI_WIND *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_WINDPluginSupport_destroy_data(
    DMSG_OSSMMI_WIND *sample);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_WINDPluginSupport_print_data(
    const DMSG_OSSMMI_WIND *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_OSSMMI_WINDPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_WINDPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_OSSMMI_WINDPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_WINDPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_WINDPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_WIND *out,
    const DMSG_OSSMMI_WIND *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_WINDPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_OSSMMI_WIND *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_WINDPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_WIND *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_WINDPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_WIND **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_OSSMMI_WINDPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_OSSMMI_WINDPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_OSSMMI_WINDPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_OSSMMI_WINDPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_OSSMMI_WIND * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_OSSMMI_WINDPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_OSSMMI_WINDPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_WINDPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_OSSMMI_WIND *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_WINDPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_WIND * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_WINDPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_WIND ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_OSSMMI_WINDPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_WIND *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_OSSMMI_WINDPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_OSSMMI_WINDPlugin_delete(struct PRESTypePlugin *);


#define DMSG_OSSMMI_TEMPPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_OSSMMI_TEMPPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_OSSMMI_TEMPPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_OSSMMI_TEMPPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_OSSMMI_TEMPPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_OSSMMI_TEMPPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_OSSMMI_TEMP*
DMSG_OSSMMI_TEMPPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_OSSMMI_TEMP*
DMSG_OSSMMI_TEMPPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_TEMPPluginSupport_copy_data(
    DMSG_OSSMMI_TEMP *out,
    const DMSG_OSSMMI_TEMP *in);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_TEMPPluginSupport_destroy_data_ex(
    DMSG_OSSMMI_TEMP *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_TEMPPluginSupport_destroy_data(
    DMSG_OSSMMI_TEMP *sample);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_TEMPPluginSupport_print_data(
    const DMSG_OSSMMI_TEMP *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_OSSMMI_TEMPPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_TEMPPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_OSSMMI_TEMPPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_TEMPPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_TEMPPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_TEMP *out,
    const DMSG_OSSMMI_TEMP *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_TEMPPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_OSSMMI_TEMP *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_TEMPPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_TEMP *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_TEMPPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_TEMP **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_OSSMMI_TEMPPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_OSSMMI_TEMPPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_OSSMMI_TEMPPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_OSSMMI_TEMPPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_OSSMMI_TEMP * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_OSSMMI_TEMPPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_OSSMMI_TEMPPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_TEMPPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_OSSMMI_TEMP *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_TEMPPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_TEMP * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_TEMPPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_TEMP ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_OSSMMI_TEMPPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_TEMP *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_OSSMMI_TEMPPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_OSSMMI_TEMPPlugin_delete(struct PRESTypePlugin *);


#define DMSG_OSSMMI_ECHOPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_OSSMMI_ECHOPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_OSSMMI_ECHOPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_OSSMMI_ECHOPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_OSSMMI_ECHOPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_OSSMMI_ECHOPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_OSSMMI_ECHO*
DMSG_OSSMMI_ECHOPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_OSSMMI_ECHO*
DMSG_OSSMMI_ECHOPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_ECHOPluginSupport_copy_data(
    DMSG_OSSMMI_ECHO *out,
    const DMSG_OSSMMI_ECHO *in);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_ECHOPluginSupport_destroy_data_ex(
    DMSG_OSSMMI_ECHO *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_ECHOPluginSupport_destroy_data(
    DMSG_OSSMMI_ECHO *sample);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_ECHOPluginSupport_print_data(
    const DMSG_OSSMMI_ECHO *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_OSSMMI_ECHOPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_ECHOPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_OSSMMI_ECHOPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_ECHOPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_ECHOPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_ECHO *out,
    const DMSG_OSSMMI_ECHO *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_ECHOPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_OSSMMI_ECHO *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_ECHOPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_ECHO *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_ECHOPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_ECHO **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_OSSMMI_ECHOPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_OSSMMI_ECHOPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_OSSMMI_ECHOPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_OSSMMI_ECHOPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_OSSMMI_ECHO * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_OSSMMI_ECHOPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_OSSMMI_ECHOPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_ECHOPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_OSSMMI_ECHO *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_ECHOPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_ECHO * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_ECHOPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_ECHO ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_OSSMMI_ECHOPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_ECHO *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_OSSMMI_ECHOPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_OSSMMI_ECHOPlugin_delete(struct PRESTypePlugin *);


#define DMSG_OSSMMI_PLATFORMPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_OSSMMI_PLATFORMPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_OSSMMI_PLATFORMPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_OSSMMI_PLATFORMPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_OSSMMI_PLATFORMPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_OSSMMI_PLATFORMPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_OSSMMI_PLATFORM*
DMSG_OSSMMI_PLATFORMPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_OSSMMI_PLATFORM*
DMSG_OSSMMI_PLATFORMPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_PLATFORMPluginSupport_copy_data(
    DMSG_OSSMMI_PLATFORM *out,
    const DMSG_OSSMMI_PLATFORM *in);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_PLATFORMPluginSupport_destroy_data_ex(
    DMSG_OSSMMI_PLATFORM *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_PLATFORMPluginSupport_destroy_data(
    DMSG_OSSMMI_PLATFORM *sample);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_PLATFORMPluginSupport_print_data(
    const DMSG_OSSMMI_PLATFORM *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_OSSMMI_PLATFORMPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_PLATFORMPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_OSSMMI_PLATFORMPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_PLATFORMPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_PLATFORMPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_PLATFORM *out,
    const DMSG_OSSMMI_PLATFORM *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_PLATFORMPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_OSSMMI_PLATFORM *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_PLATFORMPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_PLATFORM *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_PLATFORMPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_PLATFORM **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_OSSMMI_PLATFORMPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_OSSMMI_PLATFORMPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_OSSMMI_PLATFORMPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_OSSMMI_PLATFORMPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_OSSMMI_PLATFORM * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_OSSMMI_PLATFORMPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_OSSMMI_PLATFORMPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_PLATFORMPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_OSSMMI_PLATFORM *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_PLATFORMPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_PLATFORM * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_PLATFORMPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_PLATFORM ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_OSSMMI_PLATFORMPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_PLATFORM *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_OSSMMI_PLATFORMPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_OSSMMI_PLATFORMPlugin_delete(struct PRESTypePlugin *);


#define DMSG_OSSMMI_PLATFORMREQPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_OSSMMI_PLATFORMREQPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_OSSMMI_PLATFORMREQPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_OSSMMI_PLATFORMREQPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_OSSMMI_PLATFORMREQPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_OSSMMI_PLATFORMREQPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_OSSMMI_PLATFORMREQ*
DMSG_OSSMMI_PLATFORMREQPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_OSSMMI_PLATFORMREQ*
DMSG_OSSMMI_PLATFORMREQPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_PLATFORMREQPluginSupport_copy_data(
    DMSG_OSSMMI_PLATFORMREQ *out,
    const DMSG_OSSMMI_PLATFORMREQ *in);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_PLATFORMREQPluginSupport_destroy_data_ex(
    DMSG_OSSMMI_PLATFORMREQ *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_PLATFORMREQPluginSupport_destroy_data(
    DMSG_OSSMMI_PLATFORMREQ *sample);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_PLATFORMREQPluginSupport_print_data(
    const DMSG_OSSMMI_PLATFORMREQ *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_OSSMMI_PLATFORMREQPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_PLATFORMREQPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_OSSMMI_PLATFORMREQPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_OSSMMI_PLATFORMREQPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_PLATFORMREQPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_PLATFORMREQ *out,
    const DMSG_OSSMMI_PLATFORMREQ *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_PLATFORMREQPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_OSSMMI_PLATFORMREQ *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_PLATFORMREQPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_PLATFORMREQ *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_PLATFORMREQPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_PLATFORMREQ **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_OSSMMI_PLATFORMREQPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_OSSMMI_PLATFORMREQPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_OSSMMI_PLATFORMREQPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_OSSMMI_PLATFORMREQPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_OSSMMI_PLATFORMREQ * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_OSSMMI_PLATFORMREQPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_OSSMMI_PLATFORMREQPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_PLATFORMREQPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_OSSMMI_PLATFORMREQ *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_PLATFORMREQPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_PLATFORMREQ * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_OSSMMI_PLATFORMREQPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_PLATFORMREQ ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_OSSMMI_PLATFORMREQPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSSMMI_PLATFORMREQ *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_OSSMMI_PLATFORMREQPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_OSSMMI_PLATFORMREQPlugin_delete(struct PRESTypePlugin *);

#ifdef __cplusplus
}
#endif

        
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif        

#endif /* DDS_OSSMMIPlugin_1396059854_h */
