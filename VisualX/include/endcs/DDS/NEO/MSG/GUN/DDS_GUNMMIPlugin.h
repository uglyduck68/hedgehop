
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from DDS_GUNMMI.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Data Distribution Service manual.
*/

#ifndef DDS_GUNMMIPlugin_731994764_h
#define DDS_GUNMMIPlugin_731994764_h

#include "DDS_GUNMMI.h"




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


#define DMSG_GFC_FIREDATAPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_GFC_FIREDATAPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_GFC_FIREDATAPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_GFC_FIREDATAPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_GFC_FIREDATAPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_GFC_FIREDATAPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_GFC_FIREDATA*
DMSG_GFC_FIREDATAPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_GFC_FIREDATA*
DMSG_GFC_FIREDATAPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_GFC_FIREDATAPluginSupport_copy_data(
    DMSG_GFC_FIREDATA *out,
    const DMSG_GFC_FIREDATA *in);

NDDSUSERDllExport extern void 
DMSG_GFC_FIREDATAPluginSupport_destroy_data_ex(
    DMSG_GFC_FIREDATA *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_GFC_FIREDATAPluginSupport_destroy_data(
    DMSG_GFC_FIREDATA *sample);

NDDSUSERDllExport extern void 
DMSG_GFC_FIREDATAPluginSupport_print_data(
    const DMSG_GFC_FIREDATA *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_GFC_FIREDATAPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_GFC_FIREDATAPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_GFC_FIREDATAPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_GFC_FIREDATAPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_GFC_FIREDATAPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_GFC_FIREDATA *out,
    const DMSG_GFC_FIREDATA *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_GFC_FIREDATAPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_GFC_FIREDATA *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_GFC_FIREDATAPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_GFC_FIREDATA *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_GFC_FIREDATAPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_GFC_FIREDATA **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_GFC_FIREDATAPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_GFC_FIREDATAPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_GFC_FIREDATAPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_GFC_FIREDATAPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_GFC_FIREDATA * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_GFC_FIREDATAPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_GFC_FIREDATAPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_GFC_FIREDATAPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_GFC_FIREDATA *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_GFC_FIREDATAPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_GFC_FIREDATA * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_GFC_FIREDATAPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_GFC_FIREDATA ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_GFC_FIREDATAPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_GFC_FIREDATA *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_GFC_FIREDATAPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_GFC_FIREDATAPlugin_delete(struct PRESTypePlugin *);


#define DMSG_EC_FIRINGCMDPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_EC_FIRINGCMDPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_EC_FIRINGCMDPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_EC_FIRINGCMDPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_EC_FIRINGCMDPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_EC_FIRINGCMDPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_EC_FIRINGCMD*
DMSG_EC_FIRINGCMDPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_EC_FIRINGCMD*
DMSG_EC_FIRINGCMDPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_EC_FIRINGCMDPluginSupport_copy_data(
    DMSG_EC_FIRINGCMD *out,
    const DMSG_EC_FIRINGCMD *in);

NDDSUSERDllExport extern void 
DMSG_EC_FIRINGCMDPluginSupport_destroy_data_ex(
    DMSG_EC_FIRINGCMD *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_EC_FIRINGCMDPluginSupport_destroy_data(
    DMSG_EC_FIRINGCMD *sample);

NDDSUSERDllExport extern void 
DMSG_EC_FIRINGCMDPluginSupport_print_data(
    const DMSG_EC_FIRINGCMD *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_EC_FIRINGCMDPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_EC_FIRINGCMDPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_EC_FIRINGCMDPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_EC_FIRINGCMDPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_EC_FIRINGCMDPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_EC_FIRINGCMD *out,
    const DMSG_EC_FIRINGCMD *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_EC_FIRINGCMDPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_EC_FIRINGCMD *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_EC_FIRINGCMDPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_EC_FIRINGCMD *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_EC_FIRINGCMDPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_EC_FIRINGCMD **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_EC_FIRINGCMDPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_EC_FIRINGCMDPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_EC_FIRINGCMDPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_EC_FIRINGCMDPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_EC_FIRINGCMD * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_EC_FIRINGCMDPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_EC_FIRINGCMDPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_EC_FIRINGCMDPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_EC_FIRINGCMD *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_EC_FIRINGCMDPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_EC_FIRINGCMD * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_EC_FIRINGCMDPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_EC_FIRINGCMD ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_EC_FIRINGCMDPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_EC_FIRINGCMD *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_EC_FIRINGCMDPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_EC_FIRINGCMDPlugin_delete(struct PRESTypePlugin *);


#define DMSG_GFC_HITEXPECTPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_GFC_HITEXPECTPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_GFC_HITEXPECTPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_GFC_HITEXPECTPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_GFC_HITEXPECTPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_GFC_HITEXPECTPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_GFC_HITEXPECT*
DMSG_GFC_HITEXPECTPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_GFC_HITEXPECT*
DMSG_GFC_HITEXPECTPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_GFC_HITEXPECTPluginSupport_copy_data(
    DMSG_GFC_HITEXPECT *out,
    const DMSG_GFC_HITEXPECT *in);

NDDSUSERDllExport extern void 
DMSG_GFC_HITEXPECTPluginSupport_destroy_data_ex(
    DMSG_GFC_HITEXPECT *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_GFC_HITEXPECTPluginSupport_destroy_data(
    DMSG_GFC_HITEXPECT *sample);

NDDSUSERDllExport extern void 
DMSG_GFC_HITEXPECTPluginSupport_print_data(
    const DMSG_GFC_HITEXPECT *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_GFC_HITEXPECTPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_GFC_HITEXPECTPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_GFC_HITEXPECTPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_GFC_HITEXPECTPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_GFC_HITEXPECTPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_GFC_HITEXPECT *out,
    const DMSG_GFC_HITEXPECT *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_GFC_HITEXPECTPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_GFC_HITEXPECT *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_GFC_HITEXPECTPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_GFC_HITEXPECT *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_GFC_HITEXPECTPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_GFC_HITEXPECT **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_GFC_HITEXPECTPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_GFC_HITEXPECTPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_GFC_HITEXPECTPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_GFC_HITEXPECTPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_GFC_HITEXPECT * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_GFC_HITEXPECTPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_GFC_HITEXPECTPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_GFC_HITEXPECTPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_GFC_HITEXPECT *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_GFC_HITEXPECTPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_GFC_HITEXPECT * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_GFC_HITEXPECTPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_GFC_HITEXPECT ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_GFC_HITEXPECTPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_GFC_HITEXPECT *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_GFC_HITEXPECTPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_GFC_HITEXPECTPlugin_delete(struct PRESTypePlugin *);


#define DMSG_GUN_STATEPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DMSG_GUN_STATEPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DMSG_GUN_STATEPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DMSG_GUN_STATEPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define DMSG_GUN_STATEPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DMSG_GUN_STATEPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DMSG_GUN_STATE*
DMSG_GUN_STATEPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DMSG_GUN_STATE*
DMSG_GUN_STATEPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DMSG_GUN_STATEPluginSupport_copy_data(
    DMSG_GUN_STATE *out,
    const DMSG_GUN_STATE *in);

NDDSUSERDllExport extern void 
DMSG_GUN_STATEPluginSupport_destroy_data_ex(
    DMSG_GUN_STATE *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DMSG_GUN_STATEPluginSupport_destroy_data(
    DMSG_GUN_STATE *sample);

NDDSUSERDllExport extern void 
DMSG_GUN_STATEPluginSupport_print_data(
    const DMSG_GUN_STATE *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DMSG_GUN_STATEPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DMSG_GUN_STATEPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
DMSG_GUN_STATEPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DMSG_GUN_STATEPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
DMSG_GUN_STATEPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_GUN_STATE *out,
    const DMSG_GUN_STATE *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
DMSG_GUN_STATEPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_GUN_STATE *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_GUN_STATEPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_GUN_STATE *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_GUN_STATEPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_GUN_STATE **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
DMSG_GUN_STATEPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
DMSG_GUN_STATEPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DMSG_GUN_STATEPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
DMSG_GUN_STATEPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_GUN_STATE * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
DMSG_GUN_STATEPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DMSG_GUN_STATEPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DMSG_GUN_STATEPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_GUN_STATE *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
DMSG_GUN_STATEPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_GUN_STATE * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
DMSG_GUN_STATEPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_GUN_STATE ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
DMSG_GUN_STATEPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_GUN_STATE *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DMSG_GUN_STATEPlugin_new(void);

NDDSUSERDllExport extern void
DMSG_GUN_STATEPlugin_delete(struct PRESTypePlugin *);

#ifdef __cplusplus
}
#endif

        
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif        

#endif /* DDS_GUNMMIPlugin_731994764_h */
