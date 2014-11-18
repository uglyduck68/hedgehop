
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from DDS_TDSRMMI.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Data Distribution Service manual.
*/

#ifndef DDS_TDSRMMIPlugin_1808377665_h
#define DDS_TDSRMMIPlugin_1808377665_h

#include "DDS_TDSRMMI.h"




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


#define DMSG_TDSR_FIELDSETRESULTPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_TDSR_FIELDSETRESULTPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_TDSR_FIELDSETRESULTPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_TDSR_FIELDSETRESULTPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_TDSR_FIELDSETRESULTPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_TDSR_FIELDSETRESULTPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_TDSR_FIELDSETRESULT*
DMSG_TDSR_FIELDSETRESULTPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_TDSR_FIELDSETRESULT*
DMSG_TDSR_FIELDSETRESULTPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_FIELDSETRESULTPluginSupport_copy_data(
    DMSG_TDSR_FIELDSETRESULT *out,
    const DMSG_TDSR_FIELDSETRESULT *in);

NDDSUSERDllExport extern void 
DMSG_TDSR_FIELDSETRESULTPluginSupport_destroy_data_ex(
    DMSG_TDSR_FIELDSETRESULT *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_TDSR_FIELDSETRESULTPluginSupport_destroy_data(
    DMSG_TDSR_FIELDSETRESULT *sample);

NDDSUSERDllExport extern void 
DMSG_TDSR_FIELDSETRESULTPluginSupport_print_data(
    const DMSG_TDSR_FIELDSETRESULT *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_TDSR_FIELDSETRESULTPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_TDSR_FIELDSETRESULTPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_TDSR_FIELDSETRESULTPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_TDSR_FIELDSETRESULTPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_FIELDSETRESULTPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TDSR_FIELDSETRESULT *out,
    const DMSG_TDSR_FIELDSETRESULT *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_FIELDSETRESULTPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_TDSR_FIELDSETRESULT *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_FIELDSETRESULTPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TDSR_FIELDSETRESULT *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_FIELDSETRESULTPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TDSR_FIELDSETRESULT **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_TDSR_FIELDSETRESULTPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_TDSR_FIELDSETRESULTPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_TDSR_FIELDSETRESULTPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_TDSR_FIELDSETRESULTPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_TDSR_FIELDSETRESULT * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_TDSR_FIELDSETRESULTPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_TDSR_FIELDSETRESULTPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_FIELDSETRESULTPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_TDSR_FIELDSETRESULT *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_FIELDSETRESULTPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TDSR_FIELDSETRESULT * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_FIELDSETRESULTPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TDSR_FIELDSETRESULT ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_TDSR_FIELDSETRESULTPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TDSR_FIELDSETRESULT *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_TDSR_FIELDSETRESULTPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_TDSR_FIELDSETRESULTPlugin_delete(struct PRESTypePlugin *);


#define DMSG_TDSR_JAMMINGPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_TDSR_JAMMINGPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_TDSR_JAMMINGPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_TDSR_JAMMINGPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_TDSR_JAMMINGPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_TDSR_JAMMINGPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_TDSR_JAMMING*
DMSG_TDSR_JAMMINGPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_TDSR_JAMMING*
DMSG_TDSR_JAMMINGPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_JAMMINGPluginSupport_copy_data(
    DMSG_TDSR_JAMMING *out,
    const DMSG_TDSR_JAMMING *in);

NDDSUSERDllExport extern void 
DMSG_TDSR_JAMMINGPluginSupport_destroy_data_ex(
    DMSG_TDSR_JAMMING *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_TDSR_JAMMINGPluginSupport_destroy_data(
    DMSG_TDSR_JAMMING *sample);

NDDSUSERDllExport extern void 
DMSG_TDSR_JAMMINGPluginSupport_print_data(
    const DMSG_TDSR_JAMMING *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_TDSR_JAMMINGPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_TDSR_JAMMINGPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_TDSR_JAMMINGPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_TDSR_JAMMINGPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_JAMMINGPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TDSR_JAMMING *out,
    const DMSG_TDSR_JAMMING *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_JAMMINGPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_TDSR_JAMMING *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_JAMMINGPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TDSR_JAMMING *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_JAMMINGPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TDSR_JAMMING **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_TDSR_JAMMINGPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_TDSR_JAMMINGPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_TDSR_JAMMINGPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_TDSR_JAMMINGPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_TDSR_JAMMING * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_TDSR_JAMMINGPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_TDSR_JAMMINGPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_JAMMINGPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_TDSR_JAMMING *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_JAMMINGPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TDSR_JAMMING * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_JAMMINGPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TDSR_JAMMING ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_TDSR_JAMMINGPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TDSR_JAMMING *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_TDSR_JAMMINGPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_TDSR_JAMMINGPlugin_delete(struct PRESTypePlugin *);


#define DMSG_TDSR_STATEPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_TDSR_STATEPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_TDSR_STATEPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_TDSR_STATEPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_TDSR_STATEPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_TDSR_STATEPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_TDSR_STATE*
DMSG_TDSR_STATEPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_TDSR_STATE*
DMSG_TDSR_STATEPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_STATEPluginSupport_copy_data(
    DMSG_TDSR_STATE *out,
    const DMSG_TDSR_STATE *in);

NDDSUSERDllExport extern void 
DMSG_TDSR_STATEPluginSupport_destroy_data_ex(
    DMSG_TDSR_STATE *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_TDSR_STATEPluginSupport_destroy_data(
    DMSG_TDSR_STATE *sample);

NDDSUSERDllExport extern void 
DMSG_TDSR_STATEPluginSupport_print_data(
    const DMSG_TDSR_STATE *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_TDSR_STATEPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_TDSR_STATEPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_TDSR_STATEPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_TDSR_STATEPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_STATEPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TDSR_STATE *out,
    const DMSG_TDSR_STATE *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_STATEPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_TDSR_STATE *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_STATEPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TDSR_STATE *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_STATEPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TDSR_STATE **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_TDSR_STATEPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_TDSR_STATEPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_TDSR_STATEPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_TDSR_STATEPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_TDSR_STATE * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_TDSR_STATEPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_TDSR_STATEPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_STATEPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_TDSR_STATE *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_STATEPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TDSR_STATE * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_STATEPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TDSR_STATE ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_TDSR_STATEPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TDSR_STATE *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_TDSR_STATEPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_TDSR_STATEPlugin_delete(struct PRESTypePlugin *);


#define DMSG_TDSR_TARGETPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_TDSR_TARGETPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_TDSR_TARGETPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_TDSR_TARGETPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_TDSR_TARGETPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_TDSR_TARGETPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_TDSR_TARGET*
DMSG_TDSR_TARGETPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_TDSR_TARGET*
DMSG_TDSR_TARGETPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_TARGETPluginSupport_copy_data(
    DMSG_TDSR_TARGET *out,
    const DMSG_TDSR_TARGET *in);

NDDSUSERDllExport extern void 
DMSG_TDSR_TARGETPluginSupport_destroy_data_ex(
    DMSG_TDSR_TARGET *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_TDSR_TARGETPluginSupport_destroy_data(
    DMSG_TDSR_TARGET *sample);

NDDSUSERDllExport extern void 
DMSG_TDSR_TARGETPluginSupport_print_data(
    const DMSG_TDSR_TARGET *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_TDSR_TARGETPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_TDSR_TARGETPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_TDSR_TARGETPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_TDSR_TARGETPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_TARGETPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TDSR_TARGET *out,
    const DMSG_TDSR_TARGET *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_TARGETPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_TDSR_TARGET *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_TARGETPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TDSR_TARGET *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_TARGETPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TDSR_TARGET **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_TDSR_TARGETPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_TDSR_TARGETPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_TDSR_TARGETPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_TDSR_TARGETPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_TDSR_TARGET * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_TDSR_TARGETPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_TDSR_TARGETPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_TARGETPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_TDSR_TARGET *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_TARGETPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TDSR_TARGET * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_TARGETPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TDSR_TARGET ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_TDSR_TARGETPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TDSR_TARGET *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_TDSR_TARGETPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_TDSR_TARGETPlugin_delete(struct PRESTypePlugin *);


#define DMSG_TDSR_BSCOPEPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_TDSR_BSCOPEPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_TDSR_BSCOPEPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_TDSR_BSCOPEPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_TDSR_BSCOPEPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_TDSR_BSCOPEPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_TDSR_BSCOPE*
DMSG_TDSR_BSCOPEPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_TDSR_BSCOPE*
DMSG_TDSR_BSCOPEPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_BSCOPEPluginSupport_copy_data(
    DMSG_TDSR_BSCOPE *out,
    const DMSG_TDSR_BSCOPE *in);

NDDSUSERDllExport extern void 
DMSG_TDSR_BSCOPEPluginSupport_destroy_data_ex(
    DMSG_TDSR_BSCOPE *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_TDSR_BSCOPEPluginSupport_destroy_data(
    DMSG_TDSR_BSCOPE *sample);

NDDSUSERDllExport extern void 
DMSG_TDSR_BSCOPEPluginSupport_print_data(
    const DMSG_TDSR_BSCOPE *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_TDSR_BSCOPEPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_TDSR_BSCOPEPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_TDSR_BSCOPEPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_TDSR_BSCOPEPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_BSCOPEPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TDSR_BSCOPE *out,
    const DMSG_TDSR_BSCOPE *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_BSCOPEPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_TDSR_BSCOPE *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_BSCOPEPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TDSR_BSCOPE *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_BSCOPEPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TDSR_BSCOPE **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_TDSR_BSCOPEPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_TDSR_BSCOPEPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_TDSR_BSCOPEPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_TDSR_BSCOPEPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_TDSR_BSCOPE * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_TDSR_BSCOPEPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_TDSR_BSCOPEPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_BSCOPEPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_TDSR_BSCOPE *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_BSCOPEPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TDSR_BSCOPE * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_BSCOPEPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TDSR_BSCOPE ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_TDSR_BSCOPEPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TDSR_BSCOPE *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_TDSR_BSCOPEPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_TDSR_BSCOPEPlugin_delete(struct PRESTypePlugin *);


#define DMSG_TDSR_COLUMNOFWATERPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_TDSR_COLUMNOFWATERPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_TDSR_COLUMNOFWATERPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_TDSR_COLUMNOFWATERPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_TDSR_COLUMNOFWATERPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_TDSR_COLUMNOFWATERPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_TDSR_COLUMNOFWATER*
DMSG_TDSR_COLUMNOFWATERPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_TDSR_COLUMNOFWATER*
DMSG_TDSR_COLUMNOFWATERPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_COLUMNOFWATERPluginSupport_copy_data(
    DMSG_TDSR_COLUMNOFWATER *out,
    const DMSG_TDSR_COLUMNOFWATER *in);

NDDSUSERDllExport extern void 
DMSG_TDSR_COLUMNOFWATERPluginSupport_destroy_data_ex(
    DMSG_TDSR_COLUMNOFWATER *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_TDSR_COLUMNOFWATERPluginSupport_destroy_data(
    DMSG_TDSR_COLUMNOFWATER *sample);

NDDSUSERDllExport extern void 
DMSG_TDSR_COLUMNOFWATERPluginSupport_print_data(
    const DMSG_TDSR_COLUMNOFWATER *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_TDSR_COLUMNOFWATERPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_TDSR_COLUMNOFWATERPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_TDSR_COLUMNOFWATERPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_TDSR_COLUMNOFWATERPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_COLUMNOFWATERPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TDSR_COLUMNOFWATER *out,
    const DMSG_TDSR_COLUMNOFWATER *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_COLUMNOFWATERPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_TDSR_COLUMNOFWATER *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_COLUMNOFWATERPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TDSR_COLUMNOFWATER *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_COLUMNOFWATERPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TDSR_COLUMNOFWATER **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_TDSR_COLUMNOFWATERPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_TDSR_COLUMNOFWATERPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_TDSR_COLUMNOFWATERPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_TDSR_COLUMNOFWATERPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_TDSR_COLUMNOFWATER * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_TDSR_COLUMNOFWATERPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_TDSR_COLUMNOFWATERPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_COLUMNOFWATERPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_TDSR_COLUMNOFWATER *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_COLUMNOFWATERPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TDSR_COLUMNOFWATER * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_COLUMNOFWATERPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TDSR_COLUMNOFWATER ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_TDSR_COLUMNOFWATERPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TDSR_COLUMNOFWATER *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_TDSR_COLUMNOFWATERPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_TDSR_COLUMNOFWATERPlugin_delete(struct PRESTypePlugin *);


#define DMSG_TDSR_TWSTRACKINGPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_TDSR_TWSTRACKINGPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_TDSR_TWSTRACKINGPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_TDSR_TWSTRACKINGPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_TDSR_TWSTRACKINGPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_TDSR_TWSTRACKINGPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_TDSR_TWSTRACKING*
DMSG_TDSR_TWSTRACKINGPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_TDSR_TWSTRACKING*
DMSG_TDSR_TWSTRACKINGPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_TWSTRACKINGPluginSupport_copy_data(
    DMSG_TDSR_TWSTRACKING *out,
    const DMSG_TDSR_TWSTRACKING *in);

NDDSUSERDllExport extern void 
DMSG_TDSR_TWSTRACKINGPluginSupport_destroy_data_ex(
    DMSG_TDSR_TWSTRACKING *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_TDSR_TWSTRACKINGPluginSupport_destroy_data(
    DMSG_TDSR_TWSTRACKING *sample);

NDDSUSERDllExport extern void 
DMSG_TDSR_TWSTRACKINGPluginSupport_print_data(
    const DMSG_TDSR_TWSTRACKING *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_TDSR_TWSTRACKINGPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_TDSR_TWSTRACKINGPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_TDSR_TWSTRACKINGPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_TDSR_TWSTRACKINGPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_TWSTRACKINGPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TDSR_TWSTRACKING *out,
    const DMSG_TDSR_TWSTRACKING *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_TWSTRACKINGPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_TDSR_TWSTRACKING *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_TWSTRACKINGPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TDSR_TWSTRACKING *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_TWSTRACKINGPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TDSR_TWSTRACKING **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_TDSR_TWSTRACKINGPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_TDSR_TWSTRACKINGPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_TDSR_TWSTRACKINGPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_TDSR_TWSTRACKINGPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_TDSR_TWSTRACKING * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_TDSR_TWSTRACKINGPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_TDSR_TWSTRACKINGPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_TWSTRACKINGPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_TDSR_TWSTRACKING *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_TWSTRACKINGPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TDSR_TWSTRACKING * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_TDSR_TWSTRACKINGPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TDSR_TWSTRACKING ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_TDSR_TWSTRACKINGPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TDSR_TWSTRACKING *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_TDSR_TWSTRACKINGPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_TDSR_TWSTRACKINGPlugin_delete(struct PRESTypePlugin *);


#define DMSG_HMI_TDSRANTENNACTRLPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_HMI_TDSRANTENNACTRLPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_HMI_TDSRANTENNACTRLPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_HMI_TDSRANTENNACTRLPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_HMI_TDSRANTENNACTRLPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_HMI_TDSRANTENNACTRLPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_HMI_TDSRANTENNACTRL*
DMSG_HMI_TDSRANTENNACTRLPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_HMI_TDSRANTENNACTRL*
DMSG_HMI_TDSRANTENNACTRLPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRANTENNACTRLPluginSupport_copy_data(
    DMSG_HMI_TDSRANTENNACTRL *out,
    const DMSG_HMI_TDSRANTENNACTRL *in);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRANTENNACTRLPluginSupport_destroy_data_ex(
    DMSG_HMI_TDSRANTENNACTRL *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRANTENNACTRLPluginSupport_destroy_data(
    DMSG_HMI_TDSRANTENNACTRL *sample);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRANTENNACTRLPluginSupport_print_data(
    const DMSG_HMI_TDSRANTENNACTRL *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_HMI_TDSRANTENNACTRLPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRANTENNACTRLPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_HMI_TDSRANTENNACTRLPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRANTENNACTRLPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRANTENNACTRLPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRANTENNACTRL *out,
    const DMSG_HMI_TDSRANTENNACTRL *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRANTENNACTRLPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TDSRANTENNACTRL *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRANTENNACTRLPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRANTENNACTRL *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRANTENNACTRLPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRANTENNACTRL **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_HMI_TDSRANTENNACTRLPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRANTENNACTRLPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRANTENNACTRLPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_HMI_TDSRANTENNACTRLPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_HMI_TDSRANTENNACTRL * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_HMI_TDSRANTENNACTRLPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRANTENNACTRLPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRANTENNACTRLPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TDSRANTENNACTRL *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRANTENNACTRLPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRANTENNACTRL * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRANTENNACTRLPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRANTENNACTRL ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_HMI_TDSRANTENNACTRLPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRANTENNACTRL *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_HMI_TDSRANTENNACTRLPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_HMI_TDSRANTENNACTRLPlugin_delete(struct PRESTypePlugin *);


#define DMSG_HMI_TDSRBATTLESHORTCMDPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_HMI_TDSRBATTLESHORTCMDPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_HMI_TDSRBATTLESHORTCMDPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_HMI_TDSRBATTLESHORTCMDPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_HMI_TDSRBATTLESHORTCMDPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_HMI_TDSRBATTLESHORTCMDPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_HMI_TDSRBATTLESHORTCMD*
DMSG_HMI_TDSRBATTLESHORTCMDPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_HMI_TDSRBATTLESHORTCMD*
DMSG_HMI_TDSRBATTLESHORTCMDPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRBATTLESHORTCMDPluginSupport_copy_data(
    DMSG_HMI_TDSRBATTLESHORTCMD *out,
    const DMSG_HMI_TDSRBATTLESHORTCMD *in);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRBATTLESHORTCMDPluginSupport_destroy_data_ex(
    DMSG_HMI_TDSRBATTLESHORTCMD *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRBATTLESHORTCMDPluginSupport_destroy_data(
    DMSG_HMI_TDSRBATTLESHORTCMD *sample);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRBATTLESHORTCMDPluginSupport_print_data(
    const DMSG_HMI_TDSRBATTLESHORTCMD *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_HMI_TDSRBATTLESHORTCMDPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRBATTLESHORTCMDPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_HMI_TDSRBATTLESHORTCMDPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRBATTLESHORTCMDPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRBATTLESHORTCMDPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRBATTLESHORTCMD *out,
    const DMSG_HMI_TDSRBATTLESHORTCMD *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRBATTLESHORTCMDPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TDSRBATTLESHORTCMD *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRBATTLESHORTCMDPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRBATTLESHORTCMD *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRBATTLESHORTCMDPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRBATTLESHORTCMD **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_HMI_TDSRBATTLESHORTCMDPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRBATTLESHORTCMDPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRBATTLESHORTCMDPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_HMI_TDSRBATTLESHORTCMDPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_HMI_TDSRBATTLESHORTCMD * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_HMI_TDSRBATTLESHORTCMDPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRBATTLESHORTCMDPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRBATTLESHORTCMDPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TDSRBATTLESHORTCMD *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRBATTLESHORTCMDPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRBATTLESHORTCMD * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRBATTLESHORTCMDPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRBATTLESHORTCMD ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_HMI_TDSRBATTLESHORTCMDPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRBATTLESHORTCMD *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_HMI_TDSRBATTLESHORTCMDPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_HMI_TDSRBATTLESHORTCMDPlugin_delete(struct PRESTypePlugin *);


#define DMSG_HMI_TDSRTRANSMITTERCTRLPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_HMI_TDSRTRANSMITTERCTRLPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_HMI_TDSRTRANSMITTERCTRLPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_HMI_TDSRTRANSMITTERCTRLPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_HMI_TDSRTRANSMITTERCTRLPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_HMI_TDSRTRANSMITTERCTRLPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_HMI_TDSRTRANSMITTERCTRL*
DMSG_HMI_TDSRTRANSMITTERCTRLPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_HMI_TDSRTRANSMITTERCTRL*
DMSG_HMI_TDSRTRANSMITTERCTRLPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRTRANSMITTERCTRLPluginSupport_copy_data(
    DMSG_HMI_TDSRTRANSMITTERCTRL *out,
    const DMSG_HMI_TDSRTRANSMITTERCTRL *in);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRTRANSMITTERCTRLPluginSupport_destroy_data_ex(
    DMSG_HMI_TDSRTRANSMITTERCTRL *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRTRANSMITTERCTRLPluginSupport_destroy_data(
    DMSG_HMI_TDSRTRANSMITTERCTRL *sample);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRTRANSMITTERCTRLPluginSupport_print_data(
    const DMSG_HMI_TDSRTRANSMITTERCTRL *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_HMI_TDSRTRANSMITTERCTRLPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRTRANSMITTERCTRLPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_HMI_TDSRTRANSMITTERCTRLPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRTRANSMITTERCTRLPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRTRANSMITTERCTRLPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRTRANSMITTERCTRL *out,
    const DMSG_HMI_TDSRTRANSMITTERCTRL *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRTRANSMITTERCTRLPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TDSRTRANSMITTERCTRL *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRTRANSMITTERCTRLPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRTRANSMITTERCTRL *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRTRANSMITTERCTRLPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRTRANSMITTERCTRL **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_HMI_TDSRTRANSMITTERCTRLPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRTRANSMITTERCTRLPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRTRANSMITTERCTRLPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_HMI_TDSRTRANSMITTERCTRLPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_HMI_TDSRTRANSMITTERCTRL * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_HMI_TDSRTRANSMITTERCTRLPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRTRANSMITTERCTRLPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRTRANSMITTERCTRLPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TDSRTRANSMITTERCTRL *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRTRANSMITTERCTRLPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRTRANSMITTERCTRL * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRTRANSMITTERCTRLPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRTRANSMITTERCTRL ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_HMI_TDSRTRANSMITTERCTRLPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRTRANSMITTERCTRL *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_HMI_TDSRTRANSMITTERCTRLPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_HMI_TDSRTRANSMITTERCTRLPlugin_delete(struct PRESTypePlugin *);


#define DMSG_OSM_TDSRFIELDSETPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_OSM_TDSRFIELDSETPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_OSM_TDSRFIELDSETPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_OSM_TDSRFIELDSETPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_OSM_TDSRFIELDSETPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_OSM_TDSRFIELDSETPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_OSM_TDSRFIELDSET*
DMSG_OSM_TDSRFIELDSETPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_OSM_TDSRFIELDSET*
DMSG_OSM_TDSRFIELDSETPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_OSM_TDSRFIELDSETPluginSupport_copy_data(
    DMSG_OSM_TDSRFIELDSET *out,
    const DMSG_OSM_TDSRFIELDSET *in);

NDDSUSERDllExport extern void 
DMSG_OSM_TDSRFIELDSETPluginSupport_destroy_data_ex(
    DMSG_OSM_TDSRFIELDSET *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_OSM_TDSRFIELDSETPluginSupport_destroy_data(
    DMSG_OSM_TDSRFIELDSET *sample);

NDDSUSERDllExport extern void 
DMSG_OSM_TDSRFIELDSETPluginSupport_print_data(
    const DMSG_OSM_TDSRFIELDSET *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_OSM_TDSRFIELDSETPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_OSM_TDSRFIELDSETPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_OSM_TDSRFIELDSETPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_OSM_TDSRFIELDSETPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_OSM_TDSRFIELDSETPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSM_TDSRFIELDSET *out,
    const DMSG_OSM_TDSRFIELDSET *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_OSM_TDSRFIELDSETPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_OSM_TDSRFIELDSET *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_OSM_TDSRFIELDSETPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSM_TDSRFIELDSET *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_OSM_TDSRFIELDSETPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSM_TDSRFIELDSET **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_OSM_TDSRFIELDSETPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_OSM_TDSRFIELDSETPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_OSM_TDSRFIELDSETPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_OSM_TDSRFIELDSETPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_OSM_TDSRFIELDSET * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_OSM_TDSRFIELDSETPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_OSM_TDSRFIELDSETPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_OSM_TDSRFIELDSETPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_OSM_TDSRFIELDSET *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_OSM_TDSRFIELDSETPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSM_TDSRFIELDSET * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_OSM_TDSRFIELDSETPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSM_TDSRFIELDSET ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_OSM_TDSRFIELDSETPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_OSM_TDSRFIELDSET *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_OSM_TDSRFIELDSETPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_OSM_TDSRFIELDSETPlugin_delete(struct PRESTypePlugin *);


#define DMSG_HMI_TDSRSURFACETRACKCTRLPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_HMI_TDSRSURFACETRACKCTRLPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_HMI_TDSRSURFACETRACKCTRLPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_HMI_TDSRSURFACETRACKCTRLPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_HMI_TDSRSURFACETRACKCTRLPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_HMI_TDSRSURFACETRACKCTRLPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_HMI_TDSRSURFACETRACKCTRL*
DMSG_HMI_TDSRSURFACETRACKCTRLPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_HMI_TDSRSURFACETRACKCTRL*
DMSG_HMI_TDSRSURFACETRACKCTRLPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRSURFACETRACKCTRLPluginSupport_copy_data(
    DMSG_HMI_TDSRSURFACETRACKCTRL *out,
    const DMSG_HMI_TDSRSURFACETRACKCTRL *in);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRSURFACETRACKCTRLPluginSupport_destroy_data_ex(
    DMSG_HMI_TDSRSURFACETRACKCTRL *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRSURFACETRACKCTRLPluginSupport_destroy_data(
    DMSG_HMI_TDSRSURFACETRACKCTRL *sample);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRSURFACETRACKCTRLPluginSupport_print_data(
    const DMSG_HMI_TDSRSURFACETRACKCTRL *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_HMI_TDSRSURFACETRACKCTRLPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRSURFACETRACKCTRLPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_HMI_TDSRSURFACETRACKCTRLPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRSURFACETRACKCTRLPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRSURFACETRACKCTRLPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRSURFACETRACKCTRL *out,
    const DMSG_HMI_TDSRSURFACETRACKCTRL *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRSURFACETRACKCTRLPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TDSRSURFACETRACKCTRL *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRSURFACETRACKCTRLPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRSURFACETRACKCTRL *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRSURFACETRACKCTRLPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRSURFACETRACKCTRL **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_HMI_TDSRSURFACETRACKCTRLPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRSURFACETRACKCTRLPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRSURFACETRACKCTRLPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_HMI_TDSRSURFACETRACKCTRLPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_HMI_TDSRSURFACETRACKCTRL * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_HMI_TDSRSURFACETRACKCTRLPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRSURFACETRACKCTRLPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRSURFACETRACKCTRLPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TDSRSURFACETRACKCTRL *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRSURFACETRACKCTRLPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRSURFACETRACKCTRL * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRSURFACETRACKCTRLPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRSURFACETRACKCTRL ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_HMI_TDSRSURFACETRACKCTRLPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRSURFACETRACKCTRL *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_HMI_TDSRSURFACETRACKCTRLPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_HMI_TDSRSURFACETRACKCTRLPlugin_delete(struct PRESTypePlugin *);


#define DMSG_HMI_TDSRRDRSILENCECTRLPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_HMI_TDSRRDRSILENCECTRLPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_HMI_TDSRRDRSILENCECTRLPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_HMI_TDSRRDRSILENCECTRLPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_HMI_TDSRRDRSILENCECTRLPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_HMI_TDSRRDRSILENCECTRLPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_HMI_TDSRRDRSILENCECTRL*
DMSG_HMI_TDSRRDRSILENCECTRLPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_HMI_TDSRRDRSILENCECTRL*
DMSG_HMI_TDSRRDRSILENCECTRLPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRRDRSILENCECTRLPluginSupport_copy_data(
    DMSG_HMI_TDSRRDRSILENCECTRL *out,
    const DMSG_HMI_TDSRRDRSILENCECTRL *in);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRRDRSILENCECTRLPluginSupport_destroy_data_ex(
    DMSG_HMI_TDSRRDRSILENCECTRL *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRRDRSILENCECTRLPluginSupport_destroy_data(
    DMSG_HMI_TDSRRDRSILENCECTRL *sample);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRRDRSILENCECTRLPluginSupport_print_data(
    const DMSG_HMI_TDSRRDRSILENCECTRL *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_HMI_TDSRRDRSILENCECTRLPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRRDRSILENCECTRLPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_HMI_TDSRRDRSILENCECTRLPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRRDRSILENCECTRLPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRRDRSILENCECTRLPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRRDRSILENCECTRL *out,
    const DMSG_HMI_TDSRRDRSILENCECTRL *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRRDRSILENCECTRLPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TDSRRDRSILENCECTRL *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRRDRSILENCECTRLPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRRDRSILENCECTRL *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRRDRSILENCECTRLPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRRDRSILENCECTRL **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_HMI_TDSRRDRSILENCECTRLPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRRDRSILENCECTRLPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRRDRSILENCECTRLPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_HMI_TDSRRDRSILENCECTRLPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_HMI_TDSRRDRSILENCECTRL * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_HMI_TDSRRDRSILENCECTRLPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRRDRSILENCECTRLPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRRDRSILENCECTRLPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TDSRRDRSILENCECTRL *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRRDRSILENCECTRLPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRRDRSILENCECTRL * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRRDRSILENCECTRLPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRRDRSILENCECTRL ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_HMI_TDSRRDRSILENCECTRLPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRRDRSILENCECTRL *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_HMI_TDSRRDRSILENCECTRLPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_HMI_TDSRRDRSILENCECTRLPlugin_delete(struct PRESTypePlugin *);


#define DMSG_HMI_TDSRSENDCHANNELSETPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_HMI_TDSRSENDCHANNELSETPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_HMI_TDSRSENDCHANNELSETPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_HMI_TDSRSENDCHANNELSETPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_HMI_TDSRSENDCHANNELSETPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_HMI_TDSRSENDCHANNELSETPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_HMI_TDSRSENDCHANNELSET*
DMSG_HMI_TDSRSENDCHANNELSETPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_HMI_TDSRSENDCHANNELSET*
DMSG_HMI_TDSRSENDCHANNELSETPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRSENDCHANNELSETPluginSupport_copy_data(
    DMSG_HMI_TDSRSENDCHANNELSET *out,
    const DMSG_HMI_TDSRSENDCHANNELSET *in);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRSENDCHANNELSETPluginSupport_destroy_data_ex(
    DMSG_HMI_TDSRSENDCHANNELSET *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRSENDCHANNELSETPluginSupport_destroy_data(
    DMSG_HMI_TDSRSENDCHANNELSET *sample);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRSENDCHANNELSETPluginSupport_print_data(
    const DMSG_HMI_TDSRSENDCHANNELSET *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_HMI_TDSRSENDCHANNELSETPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRSENDCHANNELSETPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_HMI_TDSRSENDCHANNELSETPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRSENDCHANNELSETPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRSENDCHANNELSETPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRSENDCHANNELSET *out,
    const DMSG_HMI_TDSRSENDCHANNELSET *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRSENDCHANNELSETPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TDSRSENDCHANNELSET *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRSENDCHANNELSETPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRSENDCHANNELSET *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRSENDCHANNELSETPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRSENDCHANNELSET **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_HMI_TDSRSENDCHANNELSETPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRSENDCHANNELSETPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRSENDCHANNELSETPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_HMI_TDSRSENDCHANNELSETPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_HMI_TDSRSENDCHANNELSET * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_HMI_TDSRSENDCHANNELSETPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRSENDCHANNELSETPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRSENDCHANNELSETPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TDSRSENDCHANNELSET *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRSENDCHANNELSETPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRSENDCHANNELSET * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRSENDCHANNELSETPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRSENDCHANNELSET ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_HMI_TDSRSENDCHANNELSETPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRSENDCHANNELSET *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_HMI_TDSRSENDCHANNELSETPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_HMI_TDSRSENDCHANNELSETPlugin_delete(struct PRESTypePlugin *);


#define DMSG_HMI_TDSRSENDRFMODEPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_HMI_TDSRSENDRFMODEPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_HMI_TDSRSENDRFMODEPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_HMI_TDSRSENDRFMODEPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_HMI_TDSRSENDRFMODEPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_HMI_TDSRSENDRFMODEPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_HMI_TDSRSENDRFMODE*
DMSG_HMI_TDSRSENDRFMODEPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_HMI_TDSRSENDRFMODE*
DMSG_HMI_TDSRSENDRFMODEPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRSENDRFMODEPluginSupport_copy_data(
    DMSG_HMI_TDSRSENDRFMODE *out,
    const DMSG_HMI_TDSRSENDRFMODE *in);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRSENDRFMODEPluginSupport_destroy_data_ex(
    DMSG_HMI_TDSRSENDRFMODE *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRSENDRFMODEPluginSupport_destroy_data(
    DMSG_HMI_TDSRSENDRFMODE *sample);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRSENDRFMODEPluginSupport_print_data(
    const DMSG_HMI_TDSRSENDRFMODE *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_HMI_TDSRSENDRFMODEPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRSENDRFMODEPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_HMI_TDSRSENDRFMODEPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRSENDRFMODEPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRSENDRFMODEPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRSENDRFMODE *out,
    const DMSG_HMI_TDSRSENDRFMODE *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRSENDRFMODEPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TDSRSENDRFMODE *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRSENDRFMODEPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRSENDRFMODE *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRSENDRFMODEPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRSENDRFMODE **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_HMI_TDSRSENDRFMODEPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRSENDRFMODEPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRSENDRFMODEPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_HMI_TDSRSENDRFMODEPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_HMI_TDSRSENDRFMODE * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_HMI_TDSRSENDRFMODEPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRSENDRFMODEPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRSENDRFMODEPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TDSRSENDRFMODE *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRSENDRFMODEPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRSENDRFMODE * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRSENDRFMODEPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRSENDRFMODE ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_HMI_TDSRSENDRFMODEPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRSENDRFMODE *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_HMI_TDSRSENDRFMODEPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_HMI_TDSRSENDRFMODEPlugin_delete(struct PRESTypePlugin *);


#define DMSG_HMI_TDSRBLANKSECTORCTRLPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_HMI_TDSRBLANKSECTORCTRLPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_HMI_TDSRBLANKSECTORCTRLPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_HMI_TDSRBLANKSECTORCTRLPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_HMI_TDSRBLANKSECTORCTRLPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_HMI_TDSRBLANKSECTORCTRLPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_HMI_TDSRBLANKSECTORCTRL*
DMSG_HMI_TDSRBLANKSECTORCTRLPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_HMI_TDSRBLANKSECTORCTRL*
DMSG_HMI_TDSRBLANKSECTORCTRLPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRBLANKSECTORCTRLPluginSupport_copy_data(
    DMSG_HMI_TDSRBLANKSECTORCTRL *out,
    const DMSG_HMI_TDSRBLANKSECTORCTRL *in);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRBLANKSECTORCTRLPluginSupport_destroy_data_ex(
    DMSG_HMI_TDSRBLANKSECTORCTRL *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRBLANKSECTORCTRLPluginSupport_destroy_data(
    DMSG_HMI_TDSRBLANKSECTORCTRL *sample);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRBLANKSECTORCTRLPluginSupport_print_data(
    const DMSG_HMI_TDSRBLANKSECTORCTRL *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_HMI_TDSRBLANKSECTORCTRLPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRBLANKSECTORCTRLPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_HMI_TDSRBLANKSECTORCTRLPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRBLANKSECTORCTRLPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRBLANKSECTORCTRLPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRBLANKSECTORCTRL *out,
    const DMSG_HMI_TDSRBLANKSECTORCTRL *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRBLANKSECTORCTRLPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TDSRBLANKSECTORCTRL *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRBLANKSECTORCTRLPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRBLANKSECTORCTRL *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRBLANKSECTORCTRLPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRBLANKSECTORCTRL **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_HMI_TDSRBLANKSECTORCTRLPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRBLANKSECTORCTRLPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRBLANKSECTORCTRLPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_HMI_TDSRBLANKSECTORCTRLPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_HMI_TDSRBLANKSECTORCTRL * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_HMI_TDSRBLANKSECTORCTRLPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRBLANKSECTORCTRLPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRBLANKSECTORCTRLPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TDSRBLANKSECTORCTRL *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRBLANKSECTORCTRLPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRBLANKSECTORCTRL * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRBLANKSECTORCTRLPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRBLANKSECTORCTRL ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_HMI_TDSRBLANKSECTORCTRLPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRBLANKSECTORCTRL *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_HMI_TDSRBLANKSECTORCTRLPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_HMI_TDSRBLANKSECTORCTRLPlugin_delete(struct PRESTypePlugin *);


#define DMSG_HMI_TDSRVIDEOSETPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_HMI_TDSRVIDEOSETPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_HMI_TDSRVIDEOSETPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_HMI_TDSRVIDEOSETPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_HMI_TDSRVIDEOSETPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_HMI_TDSRVIDEOSETPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_HMI_TDSRVIDEOSET*
DMSG_HMI_TDSRVIDEOSETPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_HMI_TDSRVIDEOSET*
DMSG_HMI_TDSRVIDEOSETPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRVIDEOSETPluginSupport_copy_data(
    DMSG_HMI_TDSRVIDEOSET *out,
    const DMSG_HMI_TDSRVIDEOSET *in);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRVIDEOSETPluginSupport_destroy_data_ex(
    DMSG_HMI_TDSRVIDEOSET *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRVIDEOSETPluginSupport_destroy_data(
    DMSG_HMI_TDSRVIDEOSET *sample);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRVIDEOSETPluginSupport_print_data(
    const DMSG_HMI_TDSRVIDEOSET *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_HMI_TDSRVIDEOSETPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRVIDEOSETPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_HMI_TDSRVIDEOSETPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRVIDEOSETPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRVIDEOSETPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRVIDEOSET *out,
    const DMSG_HMI_TDSRVIDEOSET *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRVIDEOSETPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TDSRVIDEOSET *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRVIDEOSETPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRVIDEOSET *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRVIDEOSETPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRVIDEOSET **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_HMI_TDSRVIDEOSETPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRVIDEOSETPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRVIDEOSETPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_HMI_TDSRVIDEOSETPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_HMI_TDSRVIDEOSET * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_HMI_TDSRVIDEOSETPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRVIDEOSETPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRVIDEOSETPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TDSRVIDEOSET *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRVIDEOSETPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRVIDEOSET * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRVIDEOSETPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRVIDEOSET ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_HMI_TDSRVIDEOSETPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRVIDEOSET *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_HMI_TDSRVIDEOSETPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_HMI_TDSRVIDEOSETPlugin_delete(struct PRESTypePlugin *);


#define DMSG_HMI_TDSRVIDEOREQPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_HMI_TDSRVIDEOREQPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_HMI_TDSRVIDEOREQPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_HMI_TDSRVIDEOREQPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_HMI_TDSRVIDEOREQPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_HMI_TDSRVIDEOREQPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_HMI_TDSRVIDEOREQ*
DMSG_HMI_TDSRVIDEOREQPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_HMI_TDSRVIDEOREQ*
DMSG_HMI_TDSRVIDEOREQPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRVIDEOREQPluginSupport_copy_data(
    DMSG_HMI_TDSRVIDEOREQ *out,
    const DMSG_HMI_TDSRVIDEOREQ *in);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRVIDEOREQPluginSupport_destroy_data_ex(
    DMSG_HMI_TDSRVIDEOREQ *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRVIDEOREQPluginSupport_destroy_data(
    DMSG_HMI_TDSRVIDEOREQ *sample);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRVIDEOREQPluginSupport_print_data(
    const DMSG_HMI_TDSRVIDEOREQ *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_HMI_TDSRVIDEOREQPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRVIDEOREQPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_HMI_TDSRVIDEOREQPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRVIDEOREQPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRVIDEOREQPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRVIDEOREQ *out,
    const DMSG_HMI_TDSRVIDEOREQ *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRVIDEOREQPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TDSRVIDEOREQ *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRVIDEOREQPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRVIDEOREQ *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRVIDEOREQPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRVIDEOREQ **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_HMI_TDSRVIDEOREQPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRVIDEOREQPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRVIDEOREQPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_HMI_TDSRVIDEOREQPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_HMI_TDSRVIDEOREQ * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_HMI_TDSRVIDEOREQPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRVIDEOREQPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRVIDEOREQPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TDSRVIDEOREQ *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRVIDEOREQPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRVIDEOREQ * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRVIDEOREQPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRVIDEOREQ ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_HMI_TDSRVIDEOREQPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRVIDEOREQ *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_HMI_TDSRVIDEOREQPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_HMI_TDSRVIDEOREQPlugin_delete(struct PRESTypePlugin *);


#define DMSG_HMI_TDSRRDRMODESETPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_HMI_TDSRRDRMODESETPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_HMI_TDSRRDRMODESETPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_HMI_TDSRRDRMODESETPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_HMI_TDSRRDRMODESETPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_HMI_TDSRRDRMODESETPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_HMI_TDSRRDRMODESET*
DMSG_HMI_TDSRRDRMODESETPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_HMI_TDSRRDRMODESET*
DMSG_HMI_TDSRRDRMODESETPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRRDRMODESETPluginSupport_copy_data(
    DMSG_HMI_TDSRRDRMODESET *out,
    const DMSG_HMI_TDSRRDRMODESET *in);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRRDRMODESETPluginSupport_destroy_data_ex(
    DMSG_HMI_TDSRRDRMODESET *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRRDRMODESETPluginSupport_destroy_data(
    DMSG_HMI_TDSRRDRMODESET *sample);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRRDRMODESETPluginSupport_print_data(
    const DMSG_HMI_TDSRRDRMODESET *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_HMI_TDSRRDRMODESETPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRRDRMODESETPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_HMI_TDSRRDRMODESETPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRRDRMODESETPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRRDRMODESETPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRRDRMODESET *out,
    const DMSG_HMI_TDSRRDRMODESET *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRRDRMODESETPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TDSRRDRMODESET *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRRDRMODESETPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRRDRMODESET *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRRDRMODESETPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRRDRMODESET **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_HMI_TDSRRDRMODESETPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRRDRMODESETPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRRDRMODESETPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_HMI_TDSRRDRMODESETPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_HMI_TDSRRDRMODESET * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_HMI_TDSRRDRMODESETPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRRDRMODESETPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRRDRMODESETPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TDSRRDRMODESET *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRRDRMODESETPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRRDRMODESET * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRRDRMODESETPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRRDRMODESET ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_HMI_TDSRRDRMODESETPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRRDRMODESET *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_HMI_TDSRRDRMODESETPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_HMI_TDSRRDRMODESETPlugin_delete(struct PRESTypePlugin *);


#define DMSG_HMI_TDSRAIRTRACKINGSETPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_HMI_TDSRAIRTRACKINGSETPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_HMI_TDSRAIRTRACKINGSETPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_HMI_TDSRAIRTRACKINGSETPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_HMI_TDSRAIRTRACKINGSETPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_HMI_TDSRAIRTRACKINGSETPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_HMI_TDSRAIRTRACKINGSET*
DMSG_HMI_TDSRAIRTRACKINGSETPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_HMI_TDSRAIRTRACKINGSET*
DMSG_HMI_TDSRAIRTRACKINGSETPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRAIRTRACKINGSETPluginSupport_copy_data(
    DMSG_HMI_TDSRAIRTRACKINGSET *out,
    const DMSG_HMI_TDSRAIRTRACKINGSET *in);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRAIRTRACKINGSETPluginSupport_destroy_data_ex(
    DMSG_HMI_TDSRAIRTRACKINGSET *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRAIRTRACKINGSETPluginSupport_destroy_data(
    DMSG_HMI_TDSRAIRTRACKINGSET *sample);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRAIRTRACKINGSETPluginSupport_print_data(
    const DMSG_HMI_TDSRAIRTRACKINGSET *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_HMI_TDSRAIRTRACKINGSETPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRAIRTRACKINGSETPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_HMI_TDSRAIRTRACKINGSETPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRAIRTRACKINGSETPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRAIRTRACKINGSETPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRAIRTRACKINGSET *out,
    const DMSG_HMI_TDSRAIRTRACKINGSET *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRAIRTRACKINGSETPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TDSRAIRTRACKINGSET *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRAIRTRACKINGSETPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRAIRTRACKINGSET *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRAIRTRACKINGSETPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRAIRTRACKINGSET **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_HMI_TDSRAIRTRACKINGSETPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRAIRTRACKINGSETPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRAIRTRACKINGSETPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_HMI_TDSRAIRTRACKINGSETPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_HMI_TDSRAIRTRACKINGSET * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_HMI_TDSRAIRTRACKINGSETPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRAIRTRACKINGSETPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRAIRTRACKINGSETPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TDSRAIRTRACKINGSET *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRAIRTRACKINGSETPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRAIRTRACKINGSET * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRAIRTRACKINGSETPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRAIRTRACKINGSET ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_HMI_TDSRAIRTRACKINGSETPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRAIRTRACKINGSET *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_HMI_TDSRAIRTRACKINGSETPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_HMI_TDSRAIRTRACKINGSETPlugin_delete(struct PRESTypePlugin *);


#define DMSG_HMI_TDSRSHIPTRACKINGSETPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_HMI_TDSRSHIPTRACKINGSETPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_HMI_TDSRSHIPTRACKINGSETPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_HMI_TDSRSHIPTRACKINGSETPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_HMI_TDSRSHIPTRACKINGSETPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_HMI_TDSRSHIPTRACKINGSETPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_HMI_TDSRSHIPTRACKINGSET*
DMSG_HMI_TDSRSHIPTRACKINGSETPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_HMI_TDSRSHIPTRACKINGSET*
DMSG_HMI_TDSRSHIPTRACKINGSETPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRSHIPTRACKINGSETPluginSupport_copy_data(
    DMSG_HMI_TDSRSHIPTRACKINGSET *out,
    const DMSG_HMI_TDSRSHIPTRACKINGSET *in);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRSHIPTRACKINGSETPluginSupport_destroy_data_ex(
    DMSG_HMI_TDSRSHIPTRACKINGSET *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRSHIPTRACKINGSETPluginSupport_destroy_data(
    DMSG_HMI_TDSRSHIPTRACKINGSET *sample);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRSHIPTRACKINGSETPluginSupport_print_data(
    const DMSG_HMI_TDSRSHIPTRACKINGSET *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_HMI_TDSRSHIPTRACKINGSETPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRSHIPTRACKINGSETPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_HMI_TDSRSHIPTRACKINGSETPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRSHIPTRACKINGSETPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRSHIPTRACKINGSETPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRSHIPTRACKINGSET *out,
    const DMSG_HMI_TDSRSHIPTRACKINGSET *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRSHIPTRACKINGSETPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TDSRSHIPTRACKINGSET *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRSHIPTRACKINGSETPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRSHIPTRACKINGSET *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRSHIPTRACKINGSETPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRSHIPTRACKINGSET **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_HMI_TDSRSHIPTRACKINGSETPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRSHIPTRACKINGSETPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRSHIPTRACKINGSETPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_HMI_TDSRSHIPTRACKINGSETPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_HMI_TDSRSHIPTRACKINGSET * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_HMI_TDSRSHIPTRACKINGSETPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRSHIPTRACKINGSETPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRSHIPTRACKINGSETPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TDSRSHIPTRACKINGSET *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRSHIPTRACKINGSETPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRSHIPTRACKINGSET * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRSHIPTRACKINGSETPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRSHIPTRACKINGSET ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_HMI_TDSRSHIPTRACKINGSETPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRSHIPTRACKINGSET *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_HMI_TDSRSHIPTRACKINGSETPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_HMI_TDSRSHIPTRACKINGSETPlugin_delete(struct PRESTypePlugin *);


#define DMSG_HMI_TDSRJAMMINGDETECTSETPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_HMI_TDSRJAMMINGDETECTSETPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_HMI_TDSRJAMMINGDETECTSETPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_HMI_TDSRJAMMINGDETECTSETPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_HMI_TDSRJAMMINGDETECTSETPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_HMI_TDSRJAMMINGDETECTSETPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_HMI_TDSRJAMMINGDETECTSET*
DMSG_HMI_TDSRJAMMINGDETECTSETPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_HMI_TDSRJAMMINGDETECTSET*
DMSG_HMI_TDSRJAMMINGDETECTSETPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRJAMMINGDETECTSETPluginSupport_copy_data(
    DMSG_HMI_TDSRJAMMINGDETECTSET *out,
    const DMSG_HMI_TDSRJAMMINGDETECTSET *in);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRJAMMINGDETECTSETPluginSupport_destroy_data_ex(
    DMSG_HMI_TDSRJAMMINGDETECTSET *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRJAMMINGDETECTSETPluginSupport_destroy_data(
    DMSG_HMI_TDSRJAMMINGDETECTSET *sample);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRJAMMINGDETECTSETPluginSupport_print_data(
    const DMSG_HMI_TDSRJAMMINGDETECTSET *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_HMI_TDSRJAMMINGDETECTSETPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRJAMMINGDETECTSETPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_HMI_TDSRJAMMINGDETECTSETPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRJAMMINGDETECTSETPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRJAMMINGDETECTSETPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRJAMMINGDETECTSET *out,
    const DMSG_HMI_TDSRJAMMINGDETECTSET *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRJAMMINGDETECTSETPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TDSRJAMMINGDETECTSET *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRJAMMINGDETECTSETPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRJAMMINGDETECTSET *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRJAMMINGDETECTSETPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRJAMMINGDETECTSET **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_HMI_TDSRJAMMINGDETECTSETPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRJAMMINGDETECTSETPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRJAMMINGDETECTSETPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_HMI_TDSRJAMMINGDETECTSETPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_HMI_TDSRJAMMINGDETECTSET * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_HMI_TDSRJAMMINGDETECTSETPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRJAMMINGDETECTSETPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRJAMMINGDETECTSETPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TDSRJAMMINGDETECTSET *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRJAMMINGDETECTSETPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRJAMMINGDETECTSET * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRJAMMINGDETECTSETPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRJAMMINGDETECTSET ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_HMI_TDSRJAMMINGDETECTSETPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRJAMMINGDETECTSET *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_HMI_TDSRJAMMINGDETECTSETPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_HMI_TDSRJAMMINGDETECTSETPlugin_delete(struct PRESTypePlugin *);


#define DMSG_HMI_TDSRLOWSPEEDDETECTSETPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_HMI_TDSRLOWSPEEDDETECTSETPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_HMI_TDSRLOWSPEEDDETECTSETPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_HMI_TDSRLOWSPEEDDETECTSETPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_HMI_TDSRLOWSPEEDDETECTSETPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_HMI_TDSRLOWSPEEDDETECTSETPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_HMI_TDSRLOWSPEEDDETECTSET*
DMSG_HMI_TDSRLOWSPEEDDETECTSETPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_HMI_TDSRLOWSPEEDDETECTSET*
DMSG_HMI_TDSRLOWSPEEDDETECTSETPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRLOWSPEEDDETECTSETPluginSupport_copy_data(
    DMSG_HMI_TDSRLOWSPEEDDETECTSET *out,
    const DMSG_HMI_TDSRLOWSPEEDDETECTSET *in);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRLOWSPEEDDETECTSETPluginSupport_destroy_data_ex(
    DMSG_HMI_TDSRLOWSPEEDDETECTSET *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRLOWSPEEDDETECTSETPluginSupport_destroy_data(
    DMSG_HMI_TDSRLOWSPEEDDETECTSET *sample);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRLOWSPEEDDETECTSETPluginSupport_print_data(
    const DMSG_HMI_TDSRLOWSPEEDDETECTSET *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_HMI_TDSRLOWSPEEDDETECTSETPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRLOWSPEEDDETECTSETPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_HMI_TDSRLOWSPEEDDETECTSETPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRLOWSPEEDDETECTSETPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRLOWSPEEDDETECTSETPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRLOWSPEEDDETECTSET *out,
    const DMSG_HMI_TDSRLOWSPEEDDETECTSET *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRLOWSPEEDDETECTSETPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TDSRLOWSPEEDDETECTSET *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRLOWSPEEDDETECTSETPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRLOWSPEEDDETECTSET *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRLOWSPEEDDETECTSETPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRLOWSPEEDDETECTSET **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_HMI_TDSRLOWSPEEDDETECTSETPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRLOWSPEEDDETECTSETPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRLOWSPEEDDETECTSETPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_HMI_TDSRLOWSPEEDDETECTSETPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_HMI_TDSRLOWSPEEDDETECTSET * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_HMI_TDSRLOWSPEEDDETECTSETPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRLOWSPEEDDETECTSETPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRLOWSPEEDDETECTSETPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TDSRLOWSPEEDDETECTSET *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRLOWSPEEDDETECTSETPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRLOWSPEEDDETECTSET * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRLOWSPEEDDETECTSETPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRLOWSPEEDDETECTSET ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_HMI_TDSRLOWSPEEDDETECTSETPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRLOWSPEEDDETECTSET *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_HMI_TDSRLOWSPEEDDETECTSETPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_HMI_TDSRLOWSPEEDDETECTSETPlugin_delete(struct PRESTypePlugin *);


#define DMSG_HMI_TDSRLOWALTDETECTSETPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_HMI_TDSRLOWALTDETECTSETPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_HMI_TDSRLOWALTDETECTSETPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_HMI_TDSRLOWALTDETECTSETPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_HMI_TDSRLOWALTDETECTSETPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_HMI_TDSRLOWALTDETECTSETPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_HMI_TDSRLOWALTDETECTSET*
DMSG_HMI_TDSRLOWALTDETECTSETPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_HMI_TDSRLOWALTDETECTSET*
DMSG_HMI_TDSRLOWALTDETECTSETPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRLOWALTDETECTSETPluginSupport_copy_data(
    DMSG_HMI_TDSRLOWALTDETECTSET *out,
    const DMSG_HMI_TDSRLOWALTDETECTSET *in);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRLOWALTDETECTSETPluginSupport_destroy_data_ex(
    DMSG_HMI_TDSRLOWALTDETECTSET *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRLOWALTDETECTSETPluginSupport_destroy_data(
    DMSG_HMI_TDSRLOWALTDETECTSET *sample);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRLOWALTDETECTSETPluginSupport_print_data(
    const DMSG_HMI_TDSRLOWALTDETECTSET *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_HMI_TDSRLOWALTDETECTSETPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRLOWALTDETECTSETPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_HMI_TDSRLOWALTDETECTSETPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRLOWALTDETECTSETPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRLOWALTDETECTSETPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRLOWALTDETECTSET *out,
    const DMSG_HMI_TDSRLOWALTDETECTSET *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRLOWALTDETECTSETPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TDSRLOWALTDETECTSET *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRLOWALTDETECTSETPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRLOWALTDETECTSET *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRLOWALTDETECTSETPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRLOWALTDETECTSET **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_HMI_TDSRLOWALTDETECTSETPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRLOWALTDETECTSETPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRLOWALTDETECTSETPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_HMI_TDSRLOWALTDETECTSETPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_HMI_TDSRLOWALTDETECTSET * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_HMI_TDSRLOWALTDETECTSETPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRLOWALTDETECTSETPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRLOWALTDETECTSETPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TDSRLOWALTDETECTSET *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRLOWALTDETECTSETPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRLOWALTDETECTSET * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRLOWALTDETECTSETPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRLOWALTDETECTSET ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_HMI_TDSRLOWALTDETECTSETPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRLOWALTDETECTSET *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_HMI_TDSRLOWALTDETECTSETPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_HMI_TDSRLOWALTDETECTSETPlugin_delete(struct PRESTypePlugin *);


#define DMSG_HMI_TDSRSIDELOBEBLOCKPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_HMI_TDSRSIDELOBEBLOCKPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_HMI_TDSRSIDELOBEBLOCKPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_HMI_TDSRSIDELOBEBLOCKPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_HMI_TDSRSIDELOBEBLOCKPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_HMI_TDSRSIDELOBEBLOCKPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_HMI_TDSRSIDELOBEBLOCK*
DMSG_HMI_TDSRSIDELOBEBLOCKPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_HMI_TDSRSIDELOBEBLOCK*
DMSG_HMI_TDSRSIDELOBEBLOCKPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRSIDELOBEBLOCKPluginSupport_copy_data(
    DMSG_HMI_TDSRSIDELOBEBLOCK *out,
    const DMSG_HMI_TDSRSIDELOBEBLOCK *in);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRSIDELOBEBLOCKPluginSupport_destroy_data_ex(
    DMSG_HMI_TDSRSIDELOBEBLOCK *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRSIDELOBEBLOCKPluginSupport_destroy_data(
    DMSG_HMI_TDSRSIDELOBEBLOCK *sample);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRSIDELOBEBLOCKPluginSupport_print_data(
    const DMSG_HMI_TDSRSIDELOBEBLOCK *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_HMI_TDSRSIDELOBEBLOCKPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRSIDELOBEBLOCKPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_HMI_TDSRSIDELOBEBLOCKPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSRSIDELOBEBLOCKPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRSIDELOBEBLOCKPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRSIDELOBEBLOCK *out,
    const DMSG_HMI_TDSRSIDELOBEBLOCK *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRSIDELOBEBLOCKPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TDSRSIDELOBEBLOCK *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRSIDELOBEBLOCKPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRSIDELOBEBLOCK *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRSIDELOBEBLOCKPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRSIDELOBEBLOCK **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_HMI_TDSRSIDELOBEBLOCKPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRSIDELOBEBLOCKPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRSIDELOBEBLOCKPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_HMI_TDSRSIDELOBEBLOCKPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_HMI_TDSRSIDELOBEBLOCK * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_HMI_TDSRSIDELOBEBLOCKPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSRSIDELOBEBLOCKPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRSIDELOBEBLOCKPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TDSRSIDELOBEBLOCK *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRSIDELOBEBLOCKPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRSIDELOBEBLOCK * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSRSIDELOBEBLOCKPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRSIDELOBEBLOCK ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_HMI_TDSRSIDELOBEBLOCKPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSRSIDELOBEBLOCK *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_HMI_TDSRSIDELOBEBLOCKPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_HMI_TDSRSIDELOBEBLOCKPlugin_delete(struct PRESTypePlugin *);


#define DMSG_HMI_TDSREQUIPQUITSETPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_HMI_TDSREQUIPQUITSETPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_HMI_TDSREQUIPQUITSETPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_HMI_TDSREQUIPQUITSETPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_HMI_TDSREQUIPQUITSETPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_HMI_TDSREQUIPQUITSETPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_HMI_TDSREQUIPQUITSET*
DMSG_HMI_TDSREQUIPQUITSETPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_HMI_TDSREQUIPQUITSET*
DMSG_HMI_TDSREQUIPQUITSETPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSREQUIPQUITSETPluginSupport_copy_data(
    DMSG_HMI_TDSREQUIPQUITSET *out,
    const DMSG_HMI_TDSREQUIPQUITSET *in);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSREQUIPQUITSETPluginSupport_destroy_data_ex(
    DMSG_HMI_TDSREQUIPQUITSET *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSREQUIPQUITSETPluginSupport_destroy_data(
    DMSG_HMI_TDSREQUIPQUITSET *sample);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSREQUIPQUITSETPluginSupport_print_data(
    const DMSG_HMI_TDSREQUIPQUITSET *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_HMI_TDSREQUIPQUITSETPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSREQUIPQUITSETPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_HMI_TDSREQUIPQUITSETPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_HMI_TDSREQUIPQUITSETPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSREQUIPQUITSETPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSREQUIPQUITSET *out,
    const DMSG_HMI_TDSREQUIPQUITSET *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSREQUIPQUITSETPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TDSREQUIPQUITSET *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSREQUIPQUITSETPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSREQUIPQUITSET *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSREQUIPQUITSETPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSREQUIPQUITSET **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_HMI_TDSREQUIPQUITSETPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSREQUIPQUITSETPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSREQUIPQUITSETPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_HMI_TDSREQUIPQUITSETPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_HMI_TDSREQUIPQUITSET * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_HMI_TDSREQUIPQUITSETPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TDSREQUIPQUITSETPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSREQUIPQUITSETPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TDSREQUIPQUITSET *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSREQUIPQUITSETPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSREQUIPQUITSET * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TDSREQUIPQUITSETPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSREQUIPQUITSET ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_HMI_TDSREQUIPQUITSETPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TDSREQUIPQUITSET *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_HMI_TDSREQUIPQUITSETPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_HMI_TDSREQUIPQUITSETPlugin_delete(struct PRESTypePlugin *);


#define DMSG_EC_TDSRTWSTARGETDESIGPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_EC_TDSRTWSTARGETDESIGPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_EC_TDSRTWSTARGETDESIGPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_EC_TDSRTWSTARGETDESIGPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_EC_TDSRTWSTARGETDESIGPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_EC_TDSRTWSTARGETDESIGPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_EC_TDSRTWSTARGETDESIG*
DMSG_EC_TDSRTWSTARGETDESIGPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_EC_TDSRTWSTARGETDESIG*
DMSG_EC_TDSRTWSTARGETDESIGPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_EC_TDSRTWSTARGETDESIGPluginSupport_copy_data(
    DMSG_EC_TDSRTWSTARGETDESIG *out,
    const DMSG_EC_TDSRTWSTARGETDESIG *in);

NDDSUSERDllExport extern void 
DMSG_EC_TDSRTWSTARGETDESIGPluginSupport_destroy_data_ex(
    DMSG_EC_TDSRTWSTARGETDESIG *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_EC_TDSRTWSTARGETDESIGPluginSupport_destroy_data(
    DMSG_EC_TDSRTWSTARGETDESIG *sample);

NDDSUSERDllExport extern void 
DMSG_EC_TDSRTWSTARGETDESIGPluginSupport_print_data(
    const DMSG_EC_TDSRTWSTARGETDESIG *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_EC_TDSRTWSTARGETDESIGPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_EC_TDSRTWSTARGETDESIGPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_EC_TDSRTWSTARGETDESIGPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_EC_TDSRTWSTARGETDESIGPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_EC_TDSRTWSTARGETDESIGPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_EC_TDSRTWSTARGETDESIG *out,
    const DMSG_EC_TDSRTWSTARGETDESIG *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_EC_TDSRTWSTARGETDESIGPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_EC_TDSRTWSTARGETDESIG *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_EC_TDSRTWSTARGETDESIGPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_EC_TDSRTWSTARGETDESIG *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_EC_TDSRTWSTARGETDESIGPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_EC_TDSRTWSTARGETDESIG **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_EC_TDSRTWSTARGETDESIGPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_EC_TDSRTWSTARGETDESIGPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_EC_TDSRTWSTARGETDESIGPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_EC_TDSRTWSTARGETDESIGPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_EC_TDSRTWSTARGETDESIG * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_EC_TDSRTWSTARGETDESIGPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_EC_TDSRTWSTARGETDESIGPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_EC_TDSRTWSTARGETDESIGPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_EC_TDSRTWSTARGETDESIG *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_EC_TDSRTWSTARGETDESIGPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_EC_TDSRTWSTARGETDESIG * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_EC_TDSRTWSTARGETDESIGPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_EC_TDSRTWSTARGETDESIG ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_EC_TDSRTWSTARGETDESIGPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_EC_TDSRTWSTARGETDESIG *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_EC_TDSRTWSTARGETDESIGPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_EC_TDSRTWSTARGETDESIGPlugin_delete(struct PRESTypePlugin *);

#ifdef __cplusplus
}
#endif

        
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif        

#endif /* DDS_TDSRMMIPlugin_1808377665_h */
