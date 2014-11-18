
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from DDS_TRRMMI.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Data Distribution Service manual.
*/

#ifndef DDS_TRRMMIPlugin_1980992815_h
#define DDS_TRRMMIPlugin_1980992815_h

#include "DDS_TRRMMI.h"




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


#define DMSG_TRR_TARGETPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_TRR_TARGETPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_TRR_TARGETPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_TRR_TARGETPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_TRR_TARGETPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_TRR_TARGETPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_TRR_TARGET*
DMSG_TRR_TARGETPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_TRR_TARGET*
DMSG_TRR_TARGETPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_TRR_TARGETPluginSupport_copy_data(
    DMSG_TRR_TARGET *out,
    const DMSG_TRR_TARGET *in);

NDDSUSERDllExport extern void 
DMSG_TRR_TARGETPluginSupport_destroy_data_ex(
    DMSG_TRR_TARGET *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_TRR_TARGETPluginSupport_destroy_data(
    DMSG_TRR_TARGET *sample);

NDDSUSERDllExport extern void 
DMSG_TRR_TARGETPluginSupport_print_data(
    const DMSG_TRR_TARGET *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_TRR_TARGETPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_TRR_TARGETPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_TRR_TARGETPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_TRR_TARGETPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_TRR_TARGETPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TRR_TARGET *out,
    const DMSG_TRR_TARGET *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_TRR_TARGETPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_TRR_TARGET *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_TRR_TARGETPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TRR_TARGET *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_TRR_TARGETPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TRR_TARGET **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_TRR_TARGETPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_TRR_TARGETPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_TRR_TARGETPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_TRR_TARGETPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_TRR_TARGET * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_TRR_TARGETPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_TRR_TARGETPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_TRR_TARGETPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_TRR_TARGET *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_TRR_TARGETPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TRR_TARGET * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_TRR_TARGETPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TRR_TARGET ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_TRR_TARGETPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TRR_TARGET *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_TRR_TARGETPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_TRR_TARGETPlugin_delete(struct PRESTypePlugin *);


#define DMSG_TRR_DIRECTORPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_TRR_DIRECTORPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_TRR_DIRECTORPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_TRR_DIRECTORPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_TRR_DIRECTORPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_TRR_DIRECTORPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_TRR_DIRECTOR*
DMSG_TRR_DIRECTORPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_TRR_DIRECTOR*
DMSG_TRR_DIRECTORPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_TRR_DIRECTORPluginSupport_copy_data(
    DMSG_TRR_DIRECTOR *out,
    const DMSG_TRR_DIRECTOR *in);

NDDSUSERDllExport extern void 
DMSG_TRR_DIRECTORPluginSupport_destroy_data_ex(
    DMSG_TRR_DIRECTOR *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_TRR_DIRECTORPluginSupport_destroy_data(
    DMSG_TRR_DIRECTOR *sample);

NDDSUSERDllExport extern void 
DMSG_TRR_DIRECTORPluginSupport_print_data(
    const DMSG_TRR_DIRECTOR *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_TRR_DIRECTORPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_TRR_DIRECTORPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_TRR_DIRECTORPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_TRR_DIRECTORPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_TRR_DIRECTORPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TRR_DIRECTOR *out,
    const DMSG_TRR_DIRECTOR *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_TRR_DIRECTORPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_TRR_DIRECTOR *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_TRR_DIRECTORPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TRR_DIRECTOR *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_TRR_DIRECTORPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TRR_DIRECTOR **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_TRR_DIRECTORPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_TRR_DIRECTORPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_TRR_DIRECTORPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_TRR_DIRECTORPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_TRR_DIRECTOR * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_TRR_DIRECTORPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_TRR_DIRECTORPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_TRR_DIRECTORPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_TRR_DIRECTOR *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_TRR_DIRECTORPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TRR_DIRECTOR * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_TRR_DIRECTORPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TRR_DIRECTOR ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_TRR_DIRECTORPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TRR_DIRECTOR *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_TRR_DIRECTORPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_TRR_DIRECTORPlugin_delete(struct PRESTypePlugin *);


#define DMSG_TRR_TRACKINGPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_TRR_TRACKINGPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_TRR_TRACKINGPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_TRR_TRACKINGPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_TRR_TRACKINGPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_TRR_TRACKINGPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_TRR_TRACKING*
DMSG_TRR_TRACKINGPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_TRR_TRACKING*
DMSG_TRR_TRACKINGPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_TRR_TRACKINGPluginSupport_copy_data(
    DMSG_TRR_TRACKING *out,
    const DMSG_TRR_TRACKING *in);

NDDSUSERDllExport extern void 
DMSG_TRR_TRACKINGPluginSupport_destroy_data_ex(
    DMSG_TRR_TRACKING *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_TRR_TRACKINGPluginSupport_destroy_data(
    DMSG_TRR_TRACKING *sample);

NDDSUSERDllExport extern void 
DMSG_TRR_TRACKINGPluginSupport_print_data(
    const DMSG_TRR_TRACKING *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_TRR_TRACKINGPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_TRR_TRACKINGPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_TRR_TRACKINGPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_TRR_TRACKINGPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_TRR_TRACKINGPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TRR_TRACKING *out,
    const DMSG_TRR_TRACKING *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_TRR_TRACKINGPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_TRR_TRACKING *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_TRR_TRACKINGPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TRR_TRACKING *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_TRR_TRACKINGPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TRR_TRACKING **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_TRR_TRACKINGPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_TRR_TRACKINGPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_TRR_TRACKINGPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_TRR_TRACKINGPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_TRR_TRACKING * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_TRR_TRACKINGPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_TRR_TRACKINGPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_TRR_TRACKINGPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_TRR_TRACKING *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_TRR_TRACKINGPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TRR_TRACKING * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_TRR_TRACKINGPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TRR_TRACKING ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_TRR_TRACKINGPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TRR_TRACKING *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_TRR_TRACKINGPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_TRR_TRACKINGPlugin_delete(struct PRESTypePlugin *);


#define DMSG_TRR_SHOOTDOWNRESULTPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_TRR_SHOOTDOWNRESULTPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_TRR_SHOOTDOWNRESULTPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_TRR_SHOOTDOWNRESULTPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_TRR_SHOOTDOWNRESULTPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_TRR_SHOOTDOWNRESULTPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_TRR_SHOOTDOWNRESULT*
DMSG_TRR_SHOOTDOWNRESULTPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_TRR_SHOOTDOWNRESULT*
DMSG_TRR_SHOOTDOWNRESULTPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_TRR_SHOOTDOWNRESULTPluginSupport_copy_data(
    DMSG_TRR_SHOOTDOWNRESULT *out,
    const DMSG_TRR_SHOOTDOWNRESULT *in);

NDDSUSERDllExport extern void 
DMSG_TRR_SHOOTDOWNRESULTPluginSupport_destroy_data_ex(
    DMSG_TRR_SHOOTDOWNRESULT *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_TRR_SHOOTDOWNRESULTPluginSupport_destroy_data(
    DMSG_TRR_SHOOTDOWNRESULT *sample);

NDDSUSERDllExport extern void 
DMSG_TRR_SHOOTDOWNRESULTPluginSupport_print_data(
    const DMSG_TRR_SHOOTDOWNRESULT *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_TRR_SHOOTDOWNRESULTPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_TRR_SHOOTDOWNRESULTPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_TRR_SHOOTDOWNRESULTPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_TRR_SHOOTDOWNRESULTPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_TRR_SHOOTDOWNRESULTPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TRR_SHOOTDOWNRESULT *out,
    const DMSG_TRR_SHOOTDOWNRESULT *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_TRR_SHOOTDOWNRESULTPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_TRR_SHOOTDOWNRESULT *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_TRR_SHOOTDOWNRESULTPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TRR_SHOOTDOWNRESULT *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_TRR_SHOOTDOWNRESULTPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TRR_SHOOTDOWNRESULT **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_TRR_SHOOTDOWNRESULTPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_TRR_SHOOTDOWNRESULTPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_TRR_SHOOTDOWNRESULTPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_TRR_SHOOTDOWNRESULTPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_TRR_SHOOTDOWNRESULT * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_TRR_SHOOTDOWNRESULTPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_TRR_SHOOTDOWNRESULTPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_TRR_SHOOTDOWNRESULTPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_TRR_SHOOTDOWNRESULT *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_TRR_SHOOTDOWNRESULTPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TRR_SHOOTDOWNRESULT * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_TRR_SHOOTDOWNRESULTPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TRR_SHOOTDOWNRESULT ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_TRR_SHOOTDOWNRESULTPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TRR_SHOOTDOWNRESULT *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_TRR_SHOOTDOWNRESULTPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_TRR_SHOOTDOWNRESULTPlugin_delete(struct PRESTypePlugin *);


#define DMSG_TRR_SETRESULTPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_TRR_SETRESULTPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_TRR_SETRESULTPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_TRR_SETRESULTPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_TRR_SETRESULTPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_TRR_SETRESULTPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_TRR_SETRESULT*
DMSG_TRR_SETRESULTPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_TRR_SETRESULT*
DMSG_TRR_SETRESULTPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_TRR_SETRESULTPluginSupport_copy_data(
    DMSG_TRR_SETRESULT *out,
    const DMSG_TRR_SETRESULT *in);

NDDSUSERDllExport extern void 
DMSG_TRR_SETRESULTPluginSupport_destroy_data_ex(
    DMSG_TRR_SETRESULT *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_TRR_SETRESULTPluginSupport_destroy_data(
    DMSG_TRR_SETRESULT *sample);

NDDSUSERDllExport extern void 
DMSG_TRR_SETRESULTPluginSupport_print_data(
    const DMSG_TRR_SETRESULT *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_TRR_SETRESULTPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_TRR_SETRESULTPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_TRR_SETRESULTPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_TRR_SETRESULTPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_TRR_SETRESULTPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TRR_SETRESULT *out,
    const DMSG_TRR_SETRESULT *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_TRR_SETRESULTPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_TRR_SETRESULT *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_TRR_SETRESULTPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TRR_SETRESULT *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_TRR_SETRESULTPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TRR_SETRESULT **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_TRR_SETRESULTPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_TRR_SETRESULTPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_TRR_SETRESULTPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_TRR_SETRESULTPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_TRR_SETRESULT * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_TRR_SETRESULTPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_TRR_SETRESULTPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_TRR_SETRESULTPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_TRR_SETRESULT *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_TRR_SETRESULTPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TRR_SETRESULT * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_TRR_SETRESULTPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TRR_SETRESULT ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_TRR_SETRESULTPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TRR_SETRESULT *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_TRR_SETRESULTPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_TRR_SETRESULTPlugin_delete(struct PRESTypePlugin *);


#define DMSG_TRR_ASCOPEPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_TRR_ASCOPEPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_TRR_ASCOPEPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_TRR_ASCOPEPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_TRR_ASCOPEPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_TRR_ASCOPEPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_TRR_ASCOPE*
DMSG_TRR_ASCOPEPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_TRR_ASCOPE*
DMSG_TRR_ASCOPEPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_TRR_ASCOPEPluginSupport_copy_data(
    DMSG_TRR_ASCOPE *out,
    const DMSG_TRR_ASCOPE *in);

NDDSUSERDllExport extern void 
DMSG_TRR_ASCOPEPluginSupport_destroy_data_ex(
    DMSG_TRR_ASCOPE *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_TRR_ASCOPEPluginSupport_destroy_data(
    DMSG_TRR_ASCOPE *sample);

NDDSUSERDllExport extern void 
DMSG_TRR_ASCOPEPluginSupport_print_data(
    const DMSG_TRR_ASCOPE *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_TRR_ASCOPEPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_TRR_ASCOPEPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_TRR_ASCOPEPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_TRR_ASCOPEPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_TRR_ASCOPEPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TRR_ASCOPE *out,
    const DMSG_TRR_ASCOPE *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_TRR_ASCOPEPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_TRR_ASCOPE *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_TRR_ASCOPEPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TRR_ASCOPE *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_TRR_ASCOPEPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TRR_ASCOPE **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_TRR_ASCOPEPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_TRR_ASCOPEPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_TRR_ASCOPEPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_TRR_ASCOPEPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_TRR_ASCOPE * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_TRR_ASCOPEPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_TRR_ASCOPEPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_TRR_ASCOPEPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_TRR_ASCOPE *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_TRR_ASCOPEPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TRR_ASCOPE * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_TRR_ASCOPEPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TRR_ASCOPE ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_TRR_ASCOPEPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TRR_ASCOPE *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_TRR_ASCOPEPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_TRR_ASCOPEPlugin_delete(struct PRESTypePlugin *);


#define DMSG_TRR_STATEPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_TRR_STATEPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_TRR_STATEPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_TRR_STATEPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_TRR_STATEPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_TRR_STATEPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_TRR_STATE*
DMSG_TRR_STATEPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_TRR_STATE*
DMSG_TRR_STATEPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_TRR_STATEPluginSupport_copy_data(
    DMSG_TRR_STATE *out,
    const DMSG_TRR_STATE *in);

NDDSUSERDllExport extern void 
DMSG_TRR_STATEPluginSupport_destroy_data_ex(
    DMSG_TRR_STATE *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_TRR_STATEPluginSupport_destroy_data(
    DMSG_TRR_STATE *sample);

NDDSUSERDllExport extern void 
DMSG_TRR_STATEPluginSupport_print_data(
    const DMSG_TRR_STATE *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_TRR_STATEPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_TRR_STATEPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_TRR_STATEPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_TRR_STATEPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_TRR_STATEPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TRR_STATE *out,
    const DMSG_TRR_STATE *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_TRR_STATEPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_TRR_STATE *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_TRR_STATEPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TRR_STATE *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_TRR_STATEPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TRR_STATE **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_TRR_STATEPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_TRR_STATEPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_TRR_STATEPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_TRR_STATEPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_TRR_STATE * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_TRR_STATEPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_TRR_STATEPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_TRR_STATEPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_TRR_STATE *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_TRR_STATEPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TRR_STATE * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_TRR_STATEPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TRR_STATE ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_TRR_STATEPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_TRR_STATE *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_TRR_STATEPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_TRR_STATEPlugin_delete(struct PRESTypePlugin *);


#define DMSG_HMI_TRRRDRCHECKREQPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_HMI_TRRRDRCHECKREQPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_HMI_TRRRDRCHECKREQPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_HMI_TRRRDRCHECKREQPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_HMI_TRRRDRCHECKREQPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_HMI_TRRRDRCHECKREQPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_HMI_TRRRDRCHECKREQ*
DMSG_HMI_TRRRDRCHECKREQPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_HMI_TRRRDRCHECKREQ*
DMSG_HMI_TRRRDRCHECKREQPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRRDRCHECKREQPluginSupport_copy_data(
    DMSG_HMI_TRRRDRCHECKREQ *out,
    const DMSG_HMI_TRRRDRCHECKREQ *in);

NDDSUSERDllExport extern void 
DMSG_HMI_TRRRDRCHECKREQPluginSupport_destroy_data_ex(
    DMSG_HMI_TRRRDRCHECKREQ *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_HMI_TRRRDRCHECKREQPluginSupport_destroy_data(
    DMSG_HMI_TRRRDRCHECKREQ *sample);

NDDSUSERDllExport extern void 
DMSG_HMI_TRRRDRCHECKREQPluginSupport_print_data(
    const DMSG_HMI_TRRRDRCHECKREQ *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_HMI_TRRRDRCHECKREQPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_HMI_TRRRDRCHECKREQPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_HMI_TRRRDRCHECKREQPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_HMI_TRRRDRCHECKREQPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRRDRCHECKREQPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRRDRCHECKREQ *out,
    const DMSG_HMI_TRRRDRCHECKREQ *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRRDRCHECKREQPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TRRRDRCHECKREQ *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRRDRCHECKREQPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRRDRCHECKREQ *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRRDRCHECKREQPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRRDRCHECKREQ **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_HMI_TRRRDRCHECKREQPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TRRRDRCHECKREQPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TRRRDRCHECKREQPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_HMI_TRRRDRCHECKREQPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_HMI_TRRRDRCHECKREQ * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_HMI_TRRRDRCHECKREQPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TRRRDRCHECKREQPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRRDRCHECKREQPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TRRRDRCHECKREQ *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRRDRCHECKREQPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRRDRCHECKREQ * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRRDRCHECKREQPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRRDRCHECKREQ ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_HMI_TRRRDRCHECKREQPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRRDRCHECKREQ *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_HMI_TRRRDRCHECKREQPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_HMI_TRRRDRCHECKREQPlugin_delete(struct PRESTypePlugin *);


#define DMSG_EC_TRRTRACKINGCMDPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_EC_TRRTRACKINGCMDPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_EC_TRRTRACKINGCMDPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_EC_TRRTRACKINGCMDPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_EC_TRRTRACKINGCMDPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_EC_TRRTRACKINGCMDPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_EC_TRRTRACKINGCMD*
DMSG_EC_TRRTRACKINGCMDPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_EC_TRRTRACKINGCMD*
DMSG_EC_TRRTRACKINGCMDPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_EC_TRRTRACKINGCMDPluginSupport_copy_data(
    DMSG_EC_TRRTRACKINGCMD *out,
    const DMSG_EC_TRRTRACKINGCMD *in);

NDDSUSERDllExport extern void 
DMSG_EC_TRRTRACKINGCMDPluginSupport_destroy_data_ex(
    DMSG_EC_TRRTRACKINGCMD *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_EC_TRRTRACKINGCMDPluginSupport_destroy_data(
    DMSG_EC_TRRTRACKINGCMD *sample);

NDDSUSERDllExport extern void 
DMSG_EC_TRRTRACKINGCMDPluginSupport_print_data(
    const DMSG_EC_TRRTRACKINGCMD *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_EC_TRRTRACKINGCMDPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_EC_TRRTRACKINGCMDPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_EC_TRRTRACKINGCMDPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_EC_TRRTRACKINGCMDPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_EC_TRRTRACKINGCMDPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_EC_TRRTRACKINGCMD *out,
    const DMSG_EC_TRRTRACKINGCMD *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_EC_TRRTRACKINGCMDPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_EC_TRRTRACKINGCMD *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_EC_TRRTRACKINGCMDPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_EC_TRRTRACKINGCMD *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_EC_TRRTRACKINGCMDPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_EC_TRRTRACKINGCMD **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_EC_TRRTRACKINGCMDPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_EC_TRRTRACKINGCMDPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_EC_TRRTRACKINGCMDPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_EC_TRRTRACKINGCMDPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_EC_TRRTRACKINGCMD * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_EC_TRRTRACKINGCMDPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_EC_TRRTRACKINGCMDPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_EC_TRRTRACKINGCMDPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_EC_TRRTRACKINGCMD *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_EC_TRRTRACKINGCMDPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_EC_TRRTRACKINGCMD * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_EC_TRRTRACKINGCMDPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_EC_TRRTRACKINGCMD ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_EC_TRRTRACKINGCMDPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_EC_TRRTRACKINGCMD *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_EC_TRRTRACKINGCMDPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_EC_TRRTRACKINGCMDPlugin_delete(struct PRESTypePlugin *);


#define DMSG_HMI_TRRSHOOTDOWNRESULTREQPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_HMI_TRRSHOOTDOWNRESULTREQPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_HMI_TRRSHOOTDOWNRESULTREQPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_HMI_TRRSHOOTDOWNRESULTREQPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_HMI_TRRSHOOTDOWNRESULTREQPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_HMI_TRRSHOOTDOWNRESULTREQPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_HMI_TRRSHOOTDOWNRESULTREQ*
DMSG_HMI_TRRSHOOTDOWNRESULTREQPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_HMI_TRRSHOOTDOWNRESULTREQ*
DMSG_HMI_TRRSHOOTDOWNRESULTREQPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRSHOOTDOWNRESULTREQPluginSupport_copy_data(
    DMSG_HMI_TRRSHOOTDOWNRESULTREQ *out,
    const DMSG_HMI_TRRSHOOTDOWNRESULTREQ *in);

NDDSUSERDllExport extern void 
DMSG_HMI_TRRSHOOTDOWNRESULTREQPluginSupport_destroy_data_ex(
    DMSG_HMI_TRRSHOOTDOWNRESULTREQ *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_HMI_TRRSHOOTDOWNRESULTREQPluginSupport_destroy_data(
    DMSG_HMI_TRRSHOOTDOWNRESULTREQ *sample);

NDDSUSERDllExport extern void 
DMSG_HMI_TRRSHOOTDOWNRESULTREQPluginSupport_print_data(
    const DMSG_HMI_TRRSHOOTDOWNRESULTREQ *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_HMI_TRRSHOOTDOWNRESULTREQPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_HMI_TRRSHOOTDOWNRESULTREQPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_HMI_TRRSHOOTDOWNRESULTREQPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_HMI_TRRSHOOTDOWNRESULTREQPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRSHOOTDOWNRESULTREQPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRSHOOTDOWNRESULTREQ *out,
    const DMSG_HMI_TRRSHOOTDOWNRESULTREQ *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRSHOOTDOWNRESULTREQPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TRRSHOOTDOWNRESULTREQ *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRSHOOTDOWNRESULTREQPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRSHOOTDOWNRESULTREQ *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRSHOOTDOWNRESULTREQPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRSHOOTDOWNRESULTREQ **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_HMI_TRRSHOOTDOWNRESULTREQPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TRRSHOOTDOWNRESULTREQPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TRRSHOOTDOWNRESULTREQPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_HMI_TRRSHOOTDOWNRESULTREQPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_HMI_TRRSHOOTDOWNRESULTREQ * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_HMI_TRRSHOOTDOWNRESULTREQPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TRRSHOOTDOWNRESULTREQPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRSHOOTDOWNRESULTREQPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TRRSHOOTDOWNRESULTREQ *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRSHOOTDOWNRESULTREQPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRSHOOTDOWNRESULTREQ * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRSHOOTDOWNRESULTREQPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRSHOOTDOWNRESULTREQ ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_HMI_TRRSHOOTDOWNRESULTREQPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRSHOOTDOWNRESULTREQ *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_HMI_TRRSHOOTDOWNRESULTREQPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_HMI_TRRSHOOTDOWNRESULTREQPlugin_delete(struct PRESTypePlugin *);


#define DMSG_HMI_TRRRDRSETPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_HMI_TRRRDRSETPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_HMI_TRRRDRSETPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_HMI_TRRRDRSETPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_HMI_TRRRDRSETPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_HMI_TRRRDRSETPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_HMI_TRRRDRSET*
DMSG_HMI_TRRRDRSETPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_HMI_TRRRDRSET*
DMSG_HMI_TRRRDRSETPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRRDRSETPluginSupport_copy_data(
    DMSG_HMI_TRRRDRSET *out,
    const DMSG_HMI_TRRRDRSET *in);

NDDSUSERDllExport extern void 
DMSG_HMI_TRRRDRSETPluginSupport_destroy_data_ex(
    DMSG_HMI_TRRRDRSET *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_HMI_TRRRDRSETPluginSupport_destroy_data(
    DMSG_HMI_TRRRDRSET *sample);

NDDSUSERDllExport extern void 
DMSG_HMI_TRRRDRSETPluginSupport_print_data(
    const DMSG_HMI_TRRRDRSET *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_HMI_TRRRDRSETPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_HMI_TRRRDRSETPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_HMI_TRRRDRSETPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_HMI_TRRRDRSETPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRRDRSETPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRRDRSET *out,
    const DMSG_HMI_TRRRDRSET *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRRDRSETPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TRRRDRSET *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRRDRSETPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRRDRSET *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRRDRSETPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRRDRSET **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_HMI_TRRRDRSETPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TRRRDRSETPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TRRRDRSETPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_HMI_TRRRDRSETPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_HMI_TRRRDRSET * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_HMI_TRRRDRSETPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TRRRDRSETPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRRDRSETPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TRRRDRSET *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRRDRSETPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRRDRSET * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRRDRSETPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRRDRSET ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_HMI_TRRRDRSETPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRRDRSET *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_HMI_TRRRDRSETPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_HMI_TRRRDRSETPlugin_delete(struct PRESTypePlugin *);


#define DMSG_HMI_TRRVIDEOSETPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_HMI_TRRVIDEOSETPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_HMI_TRRVIDEOSETPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_HMI_TRRVIDEOSETPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_HMI_TRRVIDEOSETPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_HMI_TRRVIDEOSETPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_HMI_TRRVIDEOSET*
DMSG_HMI_TRRVIDEOSETPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_HMI_TRRVIDEOSET*
DMSG_HMI_TRRVIDEOSETPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRVIDEOSETPluginSupport_copy_data(
    DMSG_HMI_TRRVIDEOSET *out,
    const DMSG_HMI_TRRVIDEOSET *in);

NDDSUSERDllExport extern void 
DMSG_HMI_TRRVIDEOSETPluginSupport_destroy_data_ex(
    DMSG_HMI_TRRVIDEOSET *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_HMI_TRRVIDEOSETPluginSupport_destroy_data(
    DMSG_HMI_TRRVIDEOSET *sample);

NDDSUSERDllExport extern void 
DMSG_HMI_TRRVIDEOSETPluginSupport_print_data(
    const DMSG_HMI_TRRVIDEOSET *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_HMI_TRRVIDEOSETPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_HMI_TRRVIDEOSETPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_HMI_TRRVIDEOSETPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_HMI_TRRVIDEOSETPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRVIDEOSETPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRVIDEOSET *out,
    const DMSG_HMI_TRRVIDEOSET *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRVIDEOSETPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TRRVIDEOSET *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRVIDEOSETPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRVIDEOSET *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRVIDEOSETPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRVIDEOSET **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_HMI_TRRVIDEOSETPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TRRVIDEOSETPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TRRVIDEOSETPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_HMI_TRRVIDEOSETPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_HMI_TRRVIDEOSET * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_HMI_TRRVIDEOSETPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TRRVIDEOSETPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRVIDEOSETPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TRRVIDEOSET *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRVIDEOSETPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRVIDEOSET * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRVIDEOSETPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRVIDEOSET ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_HMI_TRRVIDEOSETPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRVIDEOSET *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_HMI_TRRVIDEOSETPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_HMI_TRRVIDEOSETPlugin_delete(struct PRESTypePlugin *);


#define DMSG_HMI_TRRMANAGESETPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_HMI_TRRMANAGESETPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_HMI_TRRMANAGESETPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_HMI_TRRMANAGESETPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_HMI_TRRMANAGESETPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_HMI_TRRMANAGESETPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_HMI_TRRMANAGESET*
DMSG_HMI_TRRMANAGESETPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_HMI_TRRMANAGESET*
DMSG_HMI_TRRMANAGESETPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRMANAGESETPluginSupport_copy_data(
    DMSG_HMI_TRRMANAGESET *out,
    const DMSG_HMI_TRRMANAGESET *in);

NDDSUSERDllExport extern void 
DMSG_HMI_TRRMANAGESETPluginSupport_destroy_data_ex(
    DMSG_HMI_TRRMANAGESET *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_HMI_TRRMANAGESETPluginSupport_destroy_data(
    DMSG_HMI_TRRMANAGESET *sample);

NDDSUSERDllExport extern void 
DMSG_HMI_TRRMANAGESETPluginSupport_print_data(
    const DMSG_HMI_TRRMANAGESET *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_HMI_TRRMANAGESETPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_HMI_TRRMANAGESETPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_HMI_TRRMANAGESETPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_HMI_TRRMANAGESETPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRMANAGESETPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRMANAGESET *out,
    const DMSG_HMI_TRRMANAGESET *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRMANAGESETPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TRRMANAGESET *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRMANAGESETPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRMANAGESET *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRMANAGESETPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRMANAGESET **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_HMI_TRRMANAGESETPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TRRMANAGESETPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TRRMANAGESETPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_HMI_TRRMANAGESETPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_HMI_TRRMANAGESET * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_HMI_TRRMANAGESETPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TRRMANAGESETPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRMANAGESETPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TRRMANAGESET *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRMANAGESETPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRMANAGESET * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRMANAGESETPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRMANAGESET ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_HMI_TRRMANAGESETPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRMANAGESET *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_HMI_TRRMANAGESETPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_HMI_TRRMANAGESETPlugin_delete(struct PRESTypePlugin *);


#define DMSG_HMI_TRRCAUTIONSETPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_HMI_TRRCAUTIONSETPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_HMI_TRRCAUTIONSETPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_HMI_TRRCAUTIONSETPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_HMI_TRRCAUTIONSETPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_HMI_TRRCAUTIONSETPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_HMI_TRRCAUTIONSET*
DMSG_HMI_TRRCAUTIONSETPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_HMI_TRRCAUTIONSET*
DMSG_HMI_TRRCAUTIONSETPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRCAUTIONSETPluginSupport_copy_data(
    DMSG_HMI_TRRCAUTIONSET *out,
    const DMSG_HMI_TRRCAUTIONSET *in);

NDDSUSERDllExport extern void 
DMSG_HMI_TRRCAUTIONSETPluginSupport_destroy_data_ex(
    DMSG_HMI_TRRCAUTIONSET *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_HMI_TRRCAUTIONSETPluginSupport_destroy_data(
    DMSG_HMI_TRRCAUTIONSET *sample);

NDDSUSERDllExport extern void 
DMSG_HMI_TRRCAUTIONSETPluginSupport_print_data(
    const DMSG_HMI_TRRCAUTIONSET *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_HMI_TRRCAUTIONSETPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_HMI_TRRCAUTIONSETPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_HMI_TRRCAUTIONSETPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_HMI_TRRCAUTIONSETPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRCAUTIONSETPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRCAUTIONSET *out,
    const DMSG_HMI_TRRCAUTIONSET *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRCAUTIONSETPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TRRCAUTIONSET *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRCAUTIONSETPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRCAUTIONSET *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRCAUTIONSETPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRCAUTIONSET **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_HMI_TRRCAUTIONSETPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TRRCAUTIONSETPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TRRCAUTIONSETPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_HMI_TRRCAUTIONSETPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_HMI_TRRCAUTIONSET * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_HMI_TRRCAUTIONSETPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TRRCAUTIONSETPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRCAUTIONSETPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TRRCAUTIONSET *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRCAUTIONSETPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRCAUTIONSET * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRCAUTIONSETPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRCAUTIONSET ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_HMI_TRRCAUTIONSETPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRCAUTIONSET *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_HMI_TRRCAUTIONSETPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_HMI_TRRCAUTIONSETPlugin_delete(struct PRESTypePlugin *);


#define DMSG_HMI_TRREQUIPMENTSETPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_HMI_TRREQUIPMENTSETPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_HMI_TRREQUIPMENTSETPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_HMI_TRREQUIPMENTSETPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_HMI_TRREQUIPMENTSETPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_HMI_TRREQUIPMENTSETPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_HMI_TRREQUIPMENTSET*
DMSG_HMI_TRREQUIPMENTSETPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_HMI_TRREQUIPMENTSET*
DMSG_HMI_TRREQUIPMENTSETPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRREQUIPMENTSETPluginSupport_copy_data(
    DMSG_HMI_TRREQUIPMENTSET *out,
    const DMSG_HMI_TRREQUIPMENTSET *in);

NDDSUSERDllExport extern void 
DMSG_HMI_TRREQUIPMENTSETPluginSupport_destroy_data_ex(
    DMSG_HMI_TRREQUIPMENTSET *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_HMI_TRREQUIPMENTSETPluginSupport_destroy_data(
    DMSG_HMI_TRREQUIPMENTSET *sample);

NDDSUSERDllExport extern void 
DMSG_HMI_TRREQUIPMENTSETPluginSupport_print_data(
    const DMSG_HMI_TRREQUIPMENTSET *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_HMI_TRREQUIPMENTSETPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_HMI_TRREQUIPMENTSETPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_HMI_TRREQUIPMENTSETPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_HMI_TRREQUIPMENTSETPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRREQUIPMENTSETPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRREQUIPMENTSET *out,
    const DMSG_HMI_TRREQUIPMENTSET *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRREQUIPMENTSETPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TRREQUIPMENTSET *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRREQUIPMENTSETPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRREQUIPMENTSET *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRREQUIPMENTSETPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRREQUIPMENTSET **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_HMI_TRREQUIPMENTSETPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TRREQUIPMENTSETPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TRREQUIPMENTSETPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_HMI_TRREQUIPMENTSETPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_HMI_TRREQUIPMENTSET * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_HMI_TRREQUIPMENTSETPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TRREQUIPMENTSETPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRREQUIPMENTSETPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TRREQUIPMENTSET *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRREQUIPMENTSETPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRREQUIPMENTSET * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRREQUIPMENTSETPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRREQUIPMENTSET ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_HMI_TRREQUIPMENTSETPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRREQUIPMENTSET *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_HMI_TRREQUIPMENTSETPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_HMI_TRREQUIPMENTSETPlugin_delete(struct PRESTypePlugin *);


#define DMSG_HMI_TRRTRACKINGSETPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_HMI_TRRTRACKINGSETPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_HMI_TRRTRACKINGSETPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_HMI_TRRTRACKINGSETPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_HMI_TRRTRACKINGSETPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_HMI_TRRTRACKINGSETPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_HMI_TRRTRACKINGSET*
DMSG_HMI_TRRTRACKINGSETPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_HMI_TRRTRACKINGSET*
DMSG_HMI_TRRTRACKINGSETPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRTRACKINGSETPluginSupport_copy_data(
    DMSG_HMI_TRRTRACKINGSET *out,
    const DMSG_HMI_TRRTRACKINGSET *in);

NDDSUSERDllExport extern void 
DMSG_HMI_TRRTRACKINGSETPluginSupport_destroy_data_ex(
    DMSG_HMI_TRRTRACKINGSET *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_HMI_TRRTRACKINGSETPluginSupport_destroy_data(
    DMSG_HMI_TRRTRACKINGSET *sample);

NDDSUSERDllExport extern void 
DMSG_HMI_TRRTRACKINGSETPluginSupport_print_data(
    const DMSG_HMI_TRRTRACKINGSET *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_HMI_TRRTRACKINGSETPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_HMI_TRRTRACKINGSETPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_HMI_TRRTRACKINGSETPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_HMI_TRRTRACKINGSETPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRTRACKINGSETPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRTRACKINGSET *out,
    const DMSG_HMI_TRRTRACKINGSET *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRTRACKINGSETPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TRRTRACKINGSET *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRTRACKINGSETPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRTRACKINGSET *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRTRACKINGSETPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRTRACKINGSET **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_HMI_TRRTRACKINGSETPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TRRTRACKINGSETPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TRRTRACKINGSETPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_HMI_TRRTRACKINGSETPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_HMI_TRRTRACKINGSET * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_HMI_TRRTRACKINGSETPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TRRTRACKINGSETPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRTRACKINGSETPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TRRTRACKINGSET *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRTRACKINGSETPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRTRACKINGSET * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRTRACKINGSETPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRTRACKINGSET ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_HMI_TRRTRACKINGSETPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRTRACKINGSET *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_HMI_TRRTRACKINGSETPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_HMI_TRRTRACKINGSETPlugin_delete(struct PRESTypePlugin *);


#define DMSG_HMI_TRRVIDEOREQPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_HMI_TRRVIDEOREQPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_HMI_TRRVIDEOREQPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_HMI_TRRVIDEOREQPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_HMI_TRRVIDEOREQPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_HMI_TRRVIDEOREQPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_HMI_TRRVIDEOREQ*
DMSG_HMI_TRRVIDEOREQPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_HMI_TRRVIDEOREQ*
DMSG_HMI_TRRVIDEOREQPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRVIDEOREQPluginSupport_copy_data(
    DMSG_HMI_TRRVIDEOREQ *out,
    const DMSG_HMI_TRRVIDEOREQ *in);

NDDSUSERDllExport extern void 
DMSG_HMI_TRRVIDEOREQPluginSupport_destroy_data_ex(
    DMSG_HMI_TRRVIDEOREQ *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_HMI_TRRVIDEOREQPluginSupport_destroy_data(
    DMSG_HMI_TRRVIDEOREQ *sample);

NDDSUSERDllExport extern void 
DMSG_HMI_TRRVIDEOREQPluginSupport_print_data(
    const DMSG_HMI_TRRVIDEOREQ *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_HMI_TRRVIDEOREQPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_HMI_TRRVIDEOREQPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_HMI_TRRVIDEOREQPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_HMI_TRRVIDEOREQPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRVIDEOREQPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRVIDEOREQ *out,
    const DMSG_HMI_TRRVIDEOREQ *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRVIDEOREQPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TRRVIDEOREQ *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRVIDEOREQPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRVIDEOREQ *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRVIDEOREQPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRVIDEOREQ **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_HMI_TRRVIDEOREQPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TRRVIDEOREQPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TRRVIDEOREQPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_HMI_TRRVIDEOREQPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_HMI_TRRVIDEOREQ * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_HMI_TRRVIDEOREQPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_HMI_TRRVIDEOREQPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRVIDEOREQPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_HMI_TRRVIDEOREQ *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRVIDEOREQPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRVIDEOREQ * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_HMI_TRRVIDEOREQPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRVIDEOREQ ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_HMI_TRRVIDEOREQPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_HMI_TRRVIDEOREQ *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_HMI_TRRVIDEOREQPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_HMI_TRRVIDEOREQPlugin_delete(struct PRESTypePlugin *);

#ifdef __cplusplus
}
#endif

        
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif        

#endif /* DDS_TRRMMIPlugin_1980992815_h */
