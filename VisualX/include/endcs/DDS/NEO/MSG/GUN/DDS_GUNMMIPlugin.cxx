
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from DDS_GUNMMI.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Data Distribution Service manual.
*/


#include <string.h>

#ifdef __cplusplus
#ifndef ndds_cpp_h
  #include "ndds/ndds_cpp.h"
#endif
#else
#ifndef ndds_c_h
  #include "ndds/ndds_c.h"
#endif
#endif

#ifndef osapi_type_h
  #include "osapi/osapi_type.h"
#endif
#ifndef osapi_heap_h
  #include "osapi/osapi_heap.h"
#endif

#ifndef osapi_utility_h
  #include "osapi/osapi_utility.h"
#endif

#ifndef cdr_type_h
  #include "cdr/cdr_type.h"
#endif

#ifndef cdr_encapsulation_h
  #include "cdr/cdr_encapsulation.h"
#endif

#ifndef cdr_stream_h
  #include "cdr/cdr_stream.h"
#endif

#ifndef pres_typePlugin_h
  #include "pres/pres_typePlugin.h"
#endif



#include "DDS_GUNMMIPlugin.h"


/* --------------------------------------------------------------------------------------
 *  Type DMSG_GFC_FIREDATA
 * -------------------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

DMSG_GFC_FIREDATA *
DMSG_GFC_FIREDATAPluginSupport_create_data_ex(RTIBool allocate_pointers){
    DMSG_GFC_FIREDATA *sample = NULL;

    RTIOsapiHeap_allocateStructure(
        &sample, DMSG_GFC_FIREDATA);

    if(sample != NULL) {
        if (!DMSG_GFC_FIREDATA_initialize_ex(sample,allocate_pointers)) {
            RTIOsapiHeap_freeStructure(&sample);
            return NULL;
        }
    }
    return sample; 
}


DMSG_GFC_FIREDATA *
DMSG_GFC_FIREDATAPluginSupport_create_data(void)
{
    return DMSG_GFC_FIREDATAPluginSupport_create_data_ex(RTI_TRUE);
}


void 
DMSG_GFC_FIREDATAPluginSupport_destroy_data_ex(
    DMSG_GFC_FIREDATA *sample,RTIBool deallocate_pointers) {

    DMSG_GFC_FIREDATA_finalize_ex(sample,deallocate_pointers);

    RTIOsapiHeap_freeStructure(sample);
}


void 
DMSG_GFC_FIREDATAPluginSupport_destroy_data(
    DMSG_GFC_FIREDATA *sample) {

    DMSG_GFC_FIREDATAPluginSupport_destroy_data_ex(sample,RTI_TRUE);

}


RTIBool 
DMSG_GFC_FIREDATAPluginSupport_copy_data(
    DMSG_GFC_FIREDATA *dst,
    const DMSG_GFC_FIREDATA *src)
{
    return DMSG_GFC_FIREDATA_copy(dst,src);
}


void 
DMSG_GFC_FIREDATAPluginSupport_print_data(
    const DMSG_GFC_FIREDATA *sample,
    const char *desc,
    unsigned int indent_level)
{


    RTICdrType_printIndent(indent_level);

    if (desc != NULL) {
      RTILog_debug("%s:\n", desc);
    } else {
      RTILog_debug("\n");
    }

    if (sample == NULL) {
      RTILog_debug("NULL\n");
      return;
    }


    RTICdrType_printDouble(
        &sample->dAoS, "dAoS", indent_level + 1);
            
    RTICdrType_printDouble(
        &sample->dEle, "dEle", indent_level + 1);
            
    RTICdrType_printDouble(
        &sample->dAzi, "dAzi", indent_level + 1);
            
    RTICdrType_printDouble(
        &sample->dToF, "dToF", indent_level + 1);
            

}



/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */



PRESTypePluginParticipantData 
DMSG_GFC_FIREDATAPlugin_on_participant_attached(
    void *registration_data,
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration,
    void *container_plugin_context,
    RTICdrTypeCode *type_code)
{

    if (registration_data) {} /* To avoid warnings */
    if (participant_info) {} /* To avoid warnings */
    if (top_level_registration) {} /* To avoid warnings */
    if (container_plugin_context) {} /* To avoid warnings */
    if (type_code) {} /* To avoid warnings */
    return PRESTypePluginDefaultParticipantData_new(participant_info);

}


void 
DMSG_GFC_FIREDATAPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data)
{

  PRESTypePluginDefaultParticipantData_delete(participant_data);
}


PRESTypePluginEndpointData
DMSG_GFC_FIREDATAPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *containerPluginContext)
{
    PRESTypePluginEndpointData epd = NULL;

   if (top_level_registration) {} /* To avoid warnings */
   if (containerPluginContext) {} /* To avoid warnings */

    epd = PRESTypePluginDefaultEndpointData_new(
            participant_data,
            endpoint_info,
            (PRESTypePluginDefaultEndpointDataCreateSampleFunction)
            DMSG_GFC_FIREDATAPluginSupport_create_data,
            (PRESTypePluginDefaultEndpointDataDestroySampleFunction)
            DMSG_GFC_FIREDATAPluginSupport_destroy_data,
            NULL, NULL);

    if (epd == NULL) {
        return NULL;
    }

    
    if (endpoint_info->endpointKind == PRES_TYPEPLUGIN_ENDPOINT_WRITER) {
        if (PRESTypePluginDefaultEndpointData_createWriterPool(
                epd,
                endpoint_info,
            (PRESTypePluginGetSerializedSampleMaxSizeFunction)
                DMSG_GFC_FIREDATAPlugin_get_serialized_sample_max_size, epd,
            (PRESTypePluginGetSerializedSampleSizeFunction)
            DMSG_GFC_FIREDATAPlugin_get_serialized_sample_size,
            epd) == RTI_FALSE) {
            PRESTypePluginDefaultEndpointData_delete(epd);
            return NULL;
        }
    }
    


    return epd;    
}


void 
DMSG_GFC_FIREDATAPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data)
{  

    PRESTypePluginDefaultEndpointData_delete(endpoint_data);
}


RTIBool 
DMSG_GFC_FIREDATAPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_GFC_FIREDATA *dst,
    const DMSG_GFC_FIREDATA *src)
{
    if (endpoint_data) {} /* To avoid warnings */
    return DMSG_GFC_FIREDATAPluginSupport_copy_data(dst,src);
}

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */


RTIBool 
DMSG_GFC_FIREDATAPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_GFC_FIREDATA *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;
    RTIBool retval = RTI_TRUE;


  if (endpoint_data) {} /* To avoid warnings */
  if (endpoint_plugin_qos) {} /* To avoid warnings */


  if(serialize_encapsulation) {

    if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream, encapsulation_id)) {
        return RTI_FALSE;
    }

    position = RTICdrStream_resetAlignment(stream);

  }

  if(serialize_sample) {

    if (!RTICdrStream_serializeDouble(
        stream, &sample->dAoS)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeDouble(
        stream, &sample->dEle)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeDouble(
        stream, &sample->dAzi)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeDouble(
        stream, &sample->dToF)) {
        return RTI_FALSE;
    }
            
  }

  if(serialize_encapsulation) {
    RTICdrStream_restoreAlignment(stream,position);
  }


  return retval;
}


RTIBool 
DMSG_GFC_FIREDATAPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_GFC_FIREDATA *sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(deserialize_encapsulation) {
        /* Deserialize encapsulation */
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);

    }
    
    if(deserialize_sample) {


    if (!RTICdrStream_deserializeDouble(
        stream, &sample->dAoS)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeDouble(
        stream, &sample->dEle)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeDouble(
        stream, &sample->dAzi)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeDouble(
        stream, &sample->dToF)) {
        return RTI_FALSE;
    }
            
    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}

 
 
RTIBool 
DMSG_GFC_FIREDATAPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_GFC_FIREDATA **sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{

    if (drop_sample) {} /* To avoid warnings */

    return DMSG_GFC_FIREDATAPlugin_deserialize_sample( 
        endpoint_data, (sample != NULL)?*sample:NULL,
        stream, deserialize_encapsulation, deserialize_sample, 
        endpoint_plugin_qos);
 
}



RTIBool DMSG_GFC_FIREDATAPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream,   
    RTIBool skip_encapsulation,
    RTIBool skip_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(skip_encapsulation) {
        if (!RTICdrStream_skipEncapsulation(stream)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if (skip_sample) {

    if (!RTICdrStream_skipDouble(stream)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipDouble(stream)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipDouble(stream)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipDouble(stream)) {
        return RTI_FALSE;
    }
            
    }


    if(skip_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


unsigned int 
DMSG_GFC_FIREDATAPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment +=  RTICdrType_getDoubleMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getDoubleMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getDoubleMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getDoubleMaxSizeSerialized(
        current_alignment);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


unsigned int 
DMSG_GFC_FIREDATAPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment +=  RTICdrType_getDoubleMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getDoubleMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getDoubleMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getDoubleMaxSizeSerialized(
        current_alignment);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


/* Returns the size of the sample in its serialized form (in bytes).
 * It can also be an estimation in excess of the real buffer needed 
 * during a call to the serialize() function.
 * The value reported does not have to include the space for the
 * encapsulation flags.
 */
unsigned int
DMSG_GFC_FIREDATAPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_GFC_FIREDATA * sample) 
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */
    if (sample) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment += RTICdrType_getDoubleMaxSizeSerialized(
        current_alignment);
            
    current_alignment += RTICdrType_getDoubleMaxSizeSerialized(
        current_alignment);
            
    current_alignment += RTICdrType_getDoubleMaxSizeSerialized(
        current_alignment);
            
    current_alignment += RTICdrType_getDoubleMaxSizeSerialized(
        current_alignment);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}

/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */


PRESTypePluginKeyKind 
DMSG_GFC_FIREDATAPlugin_get_key_kind(void)
{

    return PRES_TYPEPLUGIN_NO_KEY;
     
}


RTIBool 
DMSG_GFC_FIREDATAPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_GFC_FIREDATA *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(serialize_encapsulation) {
        if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream, encapsulation_id)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if(serialize_key) {

        if (!DMSG_GFC_FIREDATAPlugin_serialize(
                endpoint_data,
                sample,
                stream,
                RTI_FALSE, encapsulation_id,
                RTI_TRUE,
                endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
    
    }


    if(serialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


RTIBool DMSG_GFC_FIREDATAPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_GFC_FIREDATA *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(deserialize_encapsulation) {
        /* Deserialize encapsulation */
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;  
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if (deserialize_key) {

        if (!DMSG_GFC_FIREDATAPlugin_deserialize_sample(
                endpoint_data, sample, stream,
                RTI_FALSE, RTI_TRUE, 
                endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
    
    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


 
RTIBool DMSG_GFC_FIREDATAPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_GFC_FIREDATA **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    if (drop_sample) {} /* To avoid warnings */
    return DMSG_GFC_FIREDATAPlugin_deserialize_key_sample(
        endpoint_data, (sample != NULL)?*sample:NULL, stream,
        deserialize_encapsulation, deserialize_key, endpoint_plugin_qos);
}



unsigned int
DMSG_GFC_FIREDATAPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int encapsulation_size = current_alignment;


    unsigned int initial_alignment = current_alignment;


    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {
        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }


        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }
        

    current_alignment += DMSG_GFC_FIREDATAPlugin_get_serialized_sample_max_size(
        endpoint_data,RTI_FALSE, encapsulation_id, current_alignment);
    
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


RTIBool 
DMSG_GFC_FIREDATAPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_GFC_FIREDATA *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;


    if(deserialize_encapsulation) {
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);

    }

    if (deserialize_key) {

        if (!DMSG_GFC_FIREDATAPlugin_deserialize_sample(
            endpoint_data, sample, stream, RTI_FALSE, 
            RTI_TRUE, endpoint_plugin_qos)) {
            return RTI_FALSE;
        }

    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}




/* ------------------------------------------------------------------------
 * Plug-in Installation Methods
 * ------------------------------------------------------------------------ */
 
struct PRESTypePlugin *DMSG_GFC_FIREDATAPlugin_new(void) 
{ 
    struct PRESTypePlugin *plugin = NULL;
    const struct PRESTypePluginVersion PLUGIN_VERSION = 
        PRES_TYPE_PLUGIN_VERSION_2_0;

    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);
    if (plugin == NULL) {
       return NULL;
    }

    plugin->version = PLUGIN_VERSION;

    /* set up parent's function pointers */
    plugin->onParticipantAttached =
        (PRESTypePluginOnParticipantAttachedCallback)
        DMSG_GFC_FIREDATAPlugin_on_participant_attached;
    plugin->onParticipantDetached =
        (PRESTypePluginOnParticipantDetachedCallback)
        DMSG_GFC_FIREDATAPlugin_on_participant_detached;
    plugin->onEndpointAttached =
        (PRESTypePluginOnEndpointAttachedCallback)
        DMSG_GFC_FIREDATAPlugin_on_endpoint_attached;
    plugin->onEndpointDetached =
        (PRESTypePluginOnEndpointDetachedCallback)
        DMSG_GFC_FIREDATAPlugin_on_endpoint_detached;

    plugin->copySampleFnc =
        (PRESTypePluginCopySampleFunction)
        DMSG_GFC_FIREDATAPlugin_copy_sample;
    plugin->createSampleFnc =
        (PRESTypePluginCreateSampleFunction)
        DMSG_GFC_FIREDATAPlugin_create_sample;
    plugin->destroySampleFnc =
        (PRESTypePluginDestroySampleFunction)
        DMSG_GFC_FIREDATAPlugin_destroy_sample;

    plugin->serializeFnc =
        (PRESTypePluginSerializeFunction)
        DMSG_GFC_FIREDATAPlugin_serialize;
    plugin->deserializeFnc =
        (PRESTypePluginDeserializeFunction)
        DMSG_GFC_FIREDATAPlugin_deserialize;
    plugin->getSerializedSampleMaxSizeFnc =
        (PRESTypePluginGetSerializedSampleMaxSizeFunction)
        DMSG_GFC_FIREDATAPlugin_get_serialized_sample_max_size;
    plugin->getSerializedSampleMinSizeFnc =
        (PRESTypePluginGetSerializedSampleMinSizeFunction)
        DMSG_GFC_FIREDATAPlugin_get_serialized_sample_min_size;


    plugin->getSampleFnc =
        (PRESTypePluginGetSampleFunction)
        DMSG_GFC_FIREDATAPlugin_get_sample;
    plugin->returnSampleFnc =
        (PRESTypePluginReturnSampleFunction)
        DMSG_GFC_FIREDATAPlugin_return_sample;

    plugin->getKeyKindFnc =
        (PRESTypePluginGetKeyKindFunction)
        DMSG_GFC_FIREDATAPlugin_get_key_kind;

 
    /* These functions are only used for keyed types. As this is not a keyed
    type they are all set to NULL
    */
    plugin->serializeKeyFnc = NULL;
    plugin->deserializeKeyFnc = NULL;
    plugin->getKeyFnc = NULL;
    plugin->returnKeyFnc = NULL;
    plugin->instanceToKeyFnc = NULL;
    plugin->keyToInstanceFnc = NULL;
    plugin->getSerializedKeyMaxSizeFnc = NULL;
    plugin->instanceToKeyHashFnc = NULL;
    plugin->serializedSampleToKeyHashFnc = NULL;
    plugin->serializedKeyToKeyHashFnc = NULL;
    
    plugin->typeCode =  (struct RTICdrTypeCode *)DMSG_GFC_FIREDATA_get_typecode();
    
    plugin->languageKind = PRES_TYPEPLUGIN_DDS_TYPE; 

    /* Serialized buffer */
    plugin->getBuffer = 
        (PRESTypePluginGetBufferFunction)
        DMSG_GFC_FIREDATAPlugin_get_buffer;
    plugin->returnBuffer = 
        (PRESTypePluginReturnBufferFunction)
        DMSG_GFC_FIREDATAPlugin_return_buffer;
    plugin->getSerializedSampleSizeFnc =
        (PRESTypePluginGetSerializedSampleSizeFunction)
        DMSG_GFC_FIREDATAPlugin_get_serialized_sample_size;

    plugin->endpointTypeName = DMSG_GFC_FIREDATATYPENAME;

    return plugin;
}

void
DMSG_GFC_FIREDATAPlugin_delete(struct PRESTypePlugin *plugin)
{
    RTIOsapiHeap_freeStructure(plugin);
} 

/* --------------------------------------------------------------------------------------
 *  Type DMSG_EC_FIRINGCMD
 * -------------------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

DMSG_EC_FIRINGCMD *
DMSG_EC_FIRINGCMDPluginSupport_create_data_ex(RTIBool allocate_pointers){
    DMSG_EC_FIRINGCMD *sample = NULL;

    RTIOsapiHeap_allocateStructure(
        &sample, DMSG_EC_FIRINGCMD);

    if(sample != NULL) {
        if (!DMSG_EC_FIRINGCMD_initialize_ex(sample,allocate_pointers)) {
            RTIOsapiHeap_freeStructure(&sample);
            return NULL;
        }
    }
    return sample; 
}


DMSG_EC_FIRINGCMD *
DMSG_EC_FIRINGCMDPluginSupport_create_data(void)
{
    return DMSG_EC_FIRINGCMDPluginSupport_create_data_ex(RTI_TRUE);
}


void 
DMSG_EC_FIRINGCMDPluginSupport_destroy_data_ex(
    DMSG_EC_FIRINGCMD *sample,RTIBool deallocate_pointers) {

    DMSG_EC_FIRINGCMD_finalize_ex(sample,deallocate_pointers);

    RTIOsapiHeap_freeStructure(sample);
}


void 
DMSG_EC_FIRINGCMDPluginSupport_destroy_data(
    DMSG_EC_FIRINGCMD *sample) {

    DMSG_EC_FIRINGCMDPluginSupport_destroy_data_ex(sample,RTI_TRUE);

}


RTIBool 
DMSG_EC_FIRINGCMDPluginSupport_copy_data(
    DMSG_EC_FIRINGCMD *dst,
    const DMSG_EC_FIRINGCMD *src)
{
    return DMSG_EC_FIRINGCMD_copy(dst,src);
}


void 
DMSG_EC_FIRINGCMDPluginSupport_print_data(
    const DMSG_EC_FIRINGCMD *sample,
    const char *desc,
    unsigned int indent_level)
{


    RTICdrType_printIndent(indent_level);

    if (desc != NULL) {
      RTILog_debug("%s:\n", desc);
    } else {
      RTILog_debug("\n");
    }

    if (sample == NULL) {
      RTILog_debug("NULL\n");
      return;
    }


    RTICdrType_printChar(
        &sample->command, "command", indent_level + 1);
            

}



/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */



PRESTypePluginParticipantData 
DMSG_EC_FIRINGCMDPlugin_on_participant_attached(
    void *registration_data,
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration,
    void *container_plugin_context,
    RTICdrTypeCode *type_code)
{

    if (registration_data) {} /* To avoid warnings */
    if (participant_info) {} /* To avoid warnings */
    if (top_level_registration) {} /* To avoid warnings */
    if (container_plugin_context) {} /* To avoid warnings */
    if (type_code) {} /* To avoid warnings */
    return PRESTypePluginDefaultParticipantData_new(participant_info);

}


void 
DMSG_EC_FIRINGCMDPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data)
{

  PRESTypePluginDefaultParticipantData_delete(participant_data);
}


PRESTypePluginEndpointData
DMSG_EC_FIRINGCMDPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *containerPluginContext)
{
    PRESTypePluginEndpointData epd = NULL;

   if (top_level_registration) {} /* To avoid warnings */
   if (containerPluginContext) {} /* To avoid warnings */

    epd = PRESTypePluginDefaultEndpointData_new(
            participant_data,
            endpoint_info,
            (PRESTypePluginDefaultEndpointDataCreateSampleFunction)
            DMSG_EC_FIRINGCMDPluginSupport_create_data,
            (PRESTypePluginDefaultEndpointDataDestroySampleFunction)
            DMSG_EC_FIRINGCMDPluginSupport_destroy_data,
            NULL, NULL);

    if (epd == NULL) {
        return NULL;
    }

    
    if (endpoint_info->endpointKind == PRES_TYPEPLUGIN_ENDPOINT_WRITER) {
        if (PRESTypePluginDefaultEndpointData_createWriterPool(
                epd,
                endpoint_info,
            (PRESTypePluginGetSerializedSampleMaxSizeFunction)
                DMSG_EC_FIRINGCMDPlugin_get_serialized_sample_max_size, epd,
            (PRESTypePluginGetSerializedSampleSizeFunction)
            DMSG_EC_FIRINGCMDPlugin_get_serialized_sample_size,
            epd) == RTI_FALSE) {
            PRESTypePluginDefaultEndpointData_delete(epd);
            return NULL;
        }
    }
    


    return epd;    
}


void 
DMSG_EC_FIRINGCMDPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data)
{  

    PRESTypePluginDefaultEndpointData_delete(endpoint_data);
}


RTIBool 
DMSG_EC_FIRINGCMDPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_EC_FIRINGCMD *dst,
    const DMSG_EC_FIRINGCMD *src)
{
    if (endpoint_data) {} /* To avoid warnings */
    return DMSG_EC_FIRINGCMDPluginSupport_copy_data(dst,src);
}

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */


RTIBool 
DMSG_EC_FIRINGCMDPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_EC_FIRINGCMD *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;
    RTIBool retval = RTI_TRUE;


  if (endpoint_data) {} /* To avoid warnings */
  if (endpoint_plugin_qos) {} /* To avoid warnings */


  if(serialize_encapsulation) {

    if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream, encapsulation_id)) {
        return RTI_FALSE;
    }

    position = RTICdrStream_resetAlignment(stream);

  }

  if(serialize_sample) {

    if (!RTICdrStream_serializeChar(
        stream, &sample->command)) {
        return RTI_FALSE;
    }
            
  }

  if(serialize_encapsulation) {
    RTICdrStream_restoreAlignment(stream,position);
  }


  return retval;
}


RTIBool 
DMSG_EC_FIRINGCMDPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_EC_FIRINGCMD *sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(deserialize_encapsulation) {
        /* Deserialize encapsulation */
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);

    }
    
    if(deserialize_sample) {


    if (!RTICdrStream_deserializeChar(
        stream, &sample->command)) {
        return RTI_FALSE;
    }
            
    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}

 
 
RTIBool 
DMSG_EC_FIRINGCMDPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_EC_FIRINGCMD **sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{

    if (drop_sample) {} /* To avoid warnings */

    return DMSG_EC_FIRINGCMDPlugin_deserialize_sample( 
        endpoint_data, (sample != NULL)?*sample:NULL,
        stream, deserialize_encapsulation, deserialize_sample, 
        endpoint_plugin_qos);
 
}



RTIBool DMSG_EC_FIRINGCMDPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream,   
    RTIBool skip_encapsulation,
    RTIBool skip_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(skip_encapsulation) {
        if (!RTICdrStream_skipEncapsulation(stream)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if (skip_sample) {

    if (!RTICdrStream_skipChar(stream)) {
        return RTI_FALSE;
    }
            
    }


    if(skip_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


unsigned int 
DMSG_EC_FIRINGCMDPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment +=  RTICdrType_getCharMaxSizeSerialized(
        current_alignment);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


unsigned int 
DMSG_EC_FIRINGCMDPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment +=  RTICdrType_getCharMaxSizeSerialized(
        current_alignment);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


/* Returns the size of the sample in its serialized form (in bytes).
 * It can also be an estimation in excess of the real buffer needed 
 * during a call to the serialize() function.
 * The value reported does not have to include the space for the
 * encapsulation flags.
 */
unsigned int
DMSG_EC_FIRINGCMDPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_EC_FIRINGCMD * sample) 
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */
    if (sample) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment += RTICdrType_getCharMaxSizeSerialized(
        current_alignment);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}

/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */


PRESTypePluginKeyKind 
DMSG_EC_FIRINGCMDPlugin_get_key_kind(void)
{

    return PRES_TYPEPLUGIN_NO_KEY;
     
}


RTIBool 
DMSG_EC_FIRINGCMDPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_EC_FIRINGCMD *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(serialize_encapsulation) {
        if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream, encapsulation_id)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if(serialize_key) {

        if (!DMSG_EC_FIRINGCMDPlugin_serialize(
                endpoint_data,
                sample,
                stream,
                RTI_FALSE, encapsulation_id,
                RTI_TRUE,
                endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
    
    }


    if(serialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


RTIBool DMSG_EC_FIRINGCMDPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_EC_FIRINGCMD *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(deserialize_encapsulation) {
        /* Deserialize encapsulation */
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;  
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if (deserialize_key) {

        if (!DMSG_EC_FIRINGCMDPlugin_deserialize_sample(
                endpoint_data, sample, stream,
                RTI_FALSE, RTI_TRUE, 
                endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
    
    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


 
RTIBool DMSG_EC_FIRINGCMDPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_EC_FIRINGCMD **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    if (drop_sample) {} /* To avoid warnings */
    return DMSG_EC_FIRINGCMDPlugin_deserialize_key_sample(
        endpoint_data, (sample != NULL)?*sample:NULL, stream,
        deserialize_encapsulation, deserialize_key, endpoint_plugin_qos);
}



unsigned int
DMSG_EC_FIRINGCMDPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int encapsulation_size = current_alignment;


    unsigned int initial_alignment = current_alignment;


    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {
        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }


        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }
        

    current_alignment += DMSG_EC_FIRINGCMDPlugin_get_serialized_sample_max_size(
        endpoint_data,RTI_FALSE, encapsulation_id, current_alignment);
    
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


RTIBool 
DMSG_EC_FIRINGCMDPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_EC_FIRINGCMD *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;


    if(deserialize_encapsulation) {
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);

    }

    if (deserialize_key) {

        if (!DMSG_EC_FIRINGCMDPlugin_deserialize_sample(
            endpoint_data, sample, stream, RTI_FALSE, 
            RTI_TRUE, endpoint_plugin_qos)) {
            return RTI_FALSE;
        }

    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}




/* ------------------------------------------------------------------------
 * Plug-in Installation Methods
 * ------------------------------------------------------------------------ */
 
struct PRESTypePlugin *DMSG_EC_FIRINGCMDPlugin_new(void) 
{ 
    struct PRESTypePlugin *plugin = NULL;
    const struct PRESTypePluginVersion PLUGIN_VERSION = 
        PRES_TYPE_PLUGIN_VERSION_2_0;

    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);
    if (plugin == NULL) {
       return NULL;
    }

    plugin->version = PLUGIN_VERSION;

    /* set up parent's function pointers */
    plugin->onParticipantAttached =
        (PRESTypePluginOnParticipantAttachedCallback)
        DMSG_EC_FIRINGCMDPlugin_on_participant_attached;
    plugin->onParticipantDetached =
        (PRESTypePluginOnParticipantDetachedCallback)
        DMSG_EC_FIRINGCMDPlugin_on_participant_detached;
    plugin->onEndpointAttached =
        (PRESTypePluginOnEndpointAttachedCallback)
        DMSG_EC_FIRINGCMDPlugin_on_endpoint_attached;
    plugin->onEndpointDetached =
        (PRESTypePluginOnEndpointDetachedCallback)
        DMSG_EC_FIRINGCMDPlugin_on_endpoint_detached;

    plugin->copySampleFnc =
        (PRESTypePluginCopySampleFunction)
        DMSG_EC_FIRINGCMDPlugin_copy_sample;
    plugin->createSampleFnc =
        (PRESTypePluginCreateSampleFunction)
        DMSG_EC_FIRINGCMDPlugin_create_sample;
    plugin->destroySampleFnc =
        (PRESTypePluginDestroySampleFunction)
        DMSG_EC_FIRINGCMDPlugin_destroy_sample;

    plugin->serializeFnc =
        (PRESTypePluginSerializeFunction)
        DMSG_EC_FIRINGCMDPlugin_serialize;
    plugin->deserializeFnc =
        (PRESTypePluginDeserializeFunction)
        DMSG_EC_FIRINGCMDPlugin_deserialize;
    plugin->getSerializedSampleMaxSizeFnc =
        (PRESTypePluginGetSerializedSampleMaxSizeFunction)
        DMSG_EC_FIRINGCMDPlugin_get_serialized_sample_max_size;
    plugin->getSerializedSampleMinSizeFnc =
        (PRESTypePluginGetSerializedSampleMinSizeFunction)
        DMSG_EC_FIRINGCMDPlugin_get_serialized_sample_min_size;


    plugin->getSampleFnc =
        (PRESTypePluginGetSampleFunction)
        DMSG_EC_FIRINGCMDPlugin_get_sample;
    plugin->returnSampleFnc =
        (PRESTypePluginReturnSampleFunction)
        DMSG_EC_FIRINGCMDPlugin_return_sample;

    plugin->getKeyKindFnc =
        (PRESTypePluginGetKeyKindFunction)
        DMSG_EC_FIRINGCMDPlugin_get_key_kind;

 
    /* These functions are only used for keyed types. As this is not a keyed
    type they are all set to NULL
    */
    plugin->serializeKeyFnc = NULL;
    plugin->deserializeKeyFnc = NULL;
    plugin->getKeyFnc = NULL;
    plugin->returnKeyFnc = NULL;
    plugin->instanceToKeyFnc = NULL;
    plugin->keyToInstanceFnc = NULL;
    plugin->getSerializedKeyMaxSizeFnc = NULL;
    plugin->instanceToKeyHashFnc = NULL;
    plugin->serializedSampleToKeyHashFnc = NULL;
    plugin->serializedKeyToKeyHashFnc = NULL;
    
    plugin->typeCode =  (struct RTICdrTypeCode *)DMSG_EC_FIRINGCMD_get_typecode();
    
    plugin->languageKind = PRES_TYPEPLUGIN_DDS_TYPE; 

    /* Serialized buffer */
    plugin->getBuffer = 
        (PRESTypePluginGetBufferFunction)
        DMSG_EC_FIRINGCMDPlugin_get_buffer;
    plugin->returnBuffer = 
        (PRESTypePluginReturnBufferFunction)
        DMSG_EC_FIRINGCMDPlugin_return_buffer;
    plugin->getSerializedSampleSizeFnc =
        (PRESTypePluginGetSerializedSampleSizeFunction)
        DMSG_EC_FIRINGCMDPlugin_get_serialized_sample_size;

    plugin->endpointTypeName = DMSG_EC_FIRINGCMDTYPENAME;

    return plugin;
}

void
DMSG_EC_FIRINGCMDPlugin_delete(struct PRESTypePlugin *plugin)
{
    RTIOsapiHeap_freeStructure(plugin);
} 

/* --------------------------------------------------------------------------------------
 *  Type DMSG_GFC_HITEXPECT
 * -------------------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

DMSG_GFC_HITEXPECT *
DMSG_GFC_HITEXPECTPluginSupport_create_data_ex(RTIBool allocate_pointers){
    DMSG_GFC_HITEXPECT *sample = NULL;

    RTIOsapiHeap_allocateStructure(
        &sample, DMSG_GFC_HITEXPECT);

    if(sample != NULL) {
        if (!DMSG_GFC_HITEXPECT_initialize_ex(sample,allocate_pointers)) {
            RTIOsapiHeap_freeStructure(&sample);
            return NULL;
        }
    }
    return sample; 
}


DMSG_GFC_HITEXPECT *
DMSG_GFC_HITEXPECTPluginSupport_create_data(void)
{
    return DMSG_GFC_HITEXPECTPluginSupport_create_data_ex(RTI_TRUE);
}


void 
DMSG_GFC_HITEXPECTPluginSupport_destroy_data_ex(
    DMSG_GFC_HITEXPECT *sample,RTIBool deallocate_pointers) {

    DMSG_GFC_HITEXPECT_finalize_ex(sample,deallocate_pointers);

    RTIOsapiHeap_freeStructure(sample);
}


void 
DMSG_GFC_HITEXPECTPluginSupport_destroy_data(
    DMSG_GFC_HITEXPECT *sample) {

    DMSG_GFC_HITEXPECTPluginSupport_destroy_data_ex(sample,RTI_TRUE);

}


RTIBool 
DMSG_GFC_HITEXPECTPluginSupport_copy_data(
    DMSG_GFC_HITEXPECT *dst,
    const DMSG_GFC_HITEXPECT *src)
{
    return DMSG_GFC_HITEXPECT_copy(dst,src);
}


void 
DMSG_GFC_HITEXPECTPluginSupport_print_data(
    const DMSG_GFC_HITEXPECT *sample,
    const char *desc,
    unsigned int indent_level)
{


    RTICdrType_printIndent(indent_level);

    if (desc != NULL) {
      RTILog_debug("%s:\n", desc);
    } else {
      RTILog_debug("\n");
    }

    if (sample == NULL) {
      RTILog_debug("NULL\n");
      return;
    }


    RTICdrType_printDouble(
        &sample->dPosX, "dPosX", indent_level + 1);
            
    RTICdrType_printDouble(
        &sample->dPosY, "dPosY", indent_level + 1);
            
    RTICdrType_printDouble(
        &sample->dPosZ, "dPosZ", indent_level + 1);
            

}



/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */



PRESTypePluginParticipantData 
DMSG_GFC_HITEXPECTPlugin_on_participant_attached(
    void *registration_data,
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration,
    void *container_plugin_context,
    RTICdrTypeCode *type_code)
{

    if (registration_data) {} /* To avoid warnings */
    if (participant_info) {} /* To avoid warnings */
    if (top_level_registration) {} /* To avoid warnings */
    if (container_plugin_context) {} /* To avoid warnings */
    if (type_code) {} /* To avoid warnings */
    return PRESTypePluginDefaultParticipantData_new(participant_info);

}


void 
DMSG_GFC_HITEXPECTPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data)
{

  PRESTypePluginDefaultParticipantData_delete(participant_data);
}


PRESTypePluginEndpointData
DMSG_GFC_HITEXPECTPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *containerPluginContext)
{
    PRESTypePluginEndpointData epd = NULL;

   if (top_level_registration) {} /* To avoid warnings */
   if (containerPluginContext) {} /* To avoid warnings */

    epd = PRESTypePluginDefaultEndpointData_new(
            participant_data,
            endpoint_info,
            (PRESTypePluginDefaultEndpointDataCreateSampleFunction)
            DMSG_GFC_HITEXPECTPluginSupport_create_data,
            (PRESTypePluginDefaultEndpointDataDestroySampleFunction)
            DMSG_GFC_HITEXPECTPluginSupport_destroy_data,
            NULL, NULL);

    if (epd == NULL) {
        return NULL;
    }

    
    if (endpoint_info->endpointKind == PRES_TYPEPLUGIN_ENDPOINT_WRITER) {
        if (PRESTypePluginDefaultEndpointData_createWriterPool(
                epd,
                endpoint_info,
            (PRESTypePluginGetSerializedSampleMaxSizeFunction)
                DMSG_GFC_HITEXPECTPlugin_get_serialized_sample_max_size, epd,
            (PRESTypePluginGetSerializedSampleSizeFunction)
            DMSG_GFC_HITEXPECTPlugin_get_serialized_sample_size,
            epd) == RTI_FALSE) {
            PRESTypePluginDefaultEndpointData_delete(epd);
            return NULL;
        }
    }
    


    return epd;    
}


void 
DMSG_GFC_HITEXPECTPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data)
{  

    PRESTypePluginDefaultEndpointData_delete(endpoint_data);
}


RTIBool 
DMSG_GFC_HITEXPECTPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_GFC_HITEXPECT *dst,
    const DMSG_GFC_HITEXPECT *src)
{
    if (endpoint_data) {} /* To avoid warnings */
    return DMSG_GFC_HITEXPECTPluginSupport_copy_data(dst,src);
}

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */


RTIBool 
DMSG_GFC_HITEXPECTPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_GFC_HITEXPECT *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;
    RTIBool retval = RTI_TRUE;


  if (endpoint_data) {} /* To avoid warnings */
  if (endpoint_plugin_qos) {} /* To avoid warnings */


  if(serialize_encapsulation) {

    if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream, encapsulation_id)) {
        return RTI_FALSE;
    }

    position = RTICdrStream_resetAlignment(stream);

  }

  if(serialize_sample) {

    if (!RTICdrStream_serializeDouble(
        stream, &sample->dPosX)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeDouble(
        stream, &sample->dPosY)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeDouble(
        stream, &sample->dPosZ)) {
        return RTI_FALSE;
    }
            
  }

  if(serialize_encapsulation) {
    RTICdrStream_restoreAlignment(stream,position);
  }


  return retval;
}


RTIBool 
DMSG_GFC_HITEXPECTPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_GFC_HITEXPECT *sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(deserialize_encapsulation) {
        /* Deserialize encapsulation */
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);

    }
    
    if(deserialize_sample) {


    if (!RTICdrStream_deserializeDouble(
        stream, &sample->dPosX)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeDouble(
        stream, &sample->dPosY)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeDouble(
        stream, &sample->dPosZ)) {
        return RTI_FALSE;
    }
            
    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}

 
 
RTIBool 
DMSG_GFC_HITEXPECTPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_GFC_HITEXPECT **sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{

    if (drop_sample) {} /* To avoid warnings */

    return DMSG_GFC_HITEXPECTPlugin_deserialize_sample( 
        endpoint_data, (sample != NULL)?*sample:NULL,
        stream, deserialize_encapsulation, deserialize_sample, 
        endpoint_plugin_qos);
 
}



RTIBool DMSG_GFC_HITEXPECTPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream,   
    RTIBool skip_encapsulation,
    RTIBool skip_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(skip_encapsulation) {
        if (!RTICdrStream_skipEncapsulation(stream)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if (skip_sample) {

    if (!RTICdrStream_skipDouble(stream)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipDouble(stream)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipDouble(stream)) {
        return RTI_FALSE;
    }
            
    }


    if(skip_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


unsigned int 
DMSG_GFC_HITEXPECTPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment +=  RTICdrType_getDoubleMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getDoubleMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getDoubleMaxSizeSerialized(
        current_alignment);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


unsigned int 
DMSG_GFC_HITEXPECTPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment +=  RTICdrType_getDoubleMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getDoubleMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getDoubleMaxSizeSerialized(
        current_alignment);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


/* Returns the size of the sample in its serialized form (in bytes).
 * It can also be an estimation in excess of the real buffer needed 
 * during a call to the serialize() function.
 * The value reported does not have to include the space for the
 * encapsulation flags.
 */
unsigned int
DMSG_GFC_HITEXPECTPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_GFC_HITEXPECT * sample) 
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */
    if (sample) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment += RTICdrType_getDoubleMaxSizeSerialized(
        current_alignment);
            
    current_alignment += RTICdrType_getDoubleMaxSizeSerialized(
        current_alignment);
            
    current_alignment += RTICdrType_getDoubleMaxSizeSerialized(
        current_alignment);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}

/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */


PRESTypePluginKeyKind 
DMSG_GFC_HITEXPECTPlugin_get_key_kind(void)
{

    return PRES_TYPEPLUGIN_NO_KEY;
     
}


RTIBool 
DMSG_GFC_HITEXPECTPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_GFC_HITEXPECT *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(serialize_encapsulation) {
        if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream, encapsulation_id)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if(serialize_key) {

        if (!DMSG_GFC_HITEXPECTPlugin_serialize(
                endpoint_data,
                sample,
                stream,
                RTI_FALSE, encapsulation_id,
                RTI_TRUE,
                endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
    
    }


    if(serialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


RTIBool DMSG_GFC_HITEXPECTPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_GFC_HITEXPECT *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(deserialize_encapsulation) {
        /* Deserialize encapsulation */
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;  
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if (deserialize_key) {

        if (!DMSG_GFC_HITEXPECTPlugin_deserialize_sample(
                endpoint_data, sample, stream,
                RTI_FALSE, RTI_TRUE, 
                endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
    
    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


 
RTIBool DMSG_GFC_HITEXPECTPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_GFC_HITEXPECT **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    if (drop_sample) {} /* To avoid warnings */
    return DMSG_GFC_HITEXPECTPlugin_deserialize_key_sample(
        endpoint_data, (sample != NULL)?*sample:NULL, stream,
        deserialize_encapsulation, deserialize_key, endpoint_plugin_qos);
}



unsigned int
DMSG_GFC_HITEXPECTPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int encapsulation_size = current_alignment;


    unsigned int initial_alignment = current_alignment;


    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {
        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }


        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }
        

    current_alignment += DMSG_GFC_HITEXPECTPlugin_get_serialized_sample_max_size(
        endpoint_data,RTI_FALSE, encapsulation_id, current_alignment);
    
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


RTIBool 
DMSG_GFC_HITEXPECTPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_GFC_HITEXPECT *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;


    if(deserialize_encapsulation) {
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);

    }

    if (deserialize_key) {

        if (!DMSG_GFC_HITEXPECTPlugin_deserialize_sample(
            endpoint_data, sample, stream, RTI_FALSE, 
            RTI_TRUE, endpoint_plugin_qos)) {
            return RTI_FALSE;
        }

    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}




/* ------------------------------------------------------------------------
 * Plug-in Installation Methods
 * ------------------------------------------------------------------------ */
 
struct PRESTypePlugin *DMSG_GFC_HITEXPECTPlugin_new(void) 
{ 
    struct PRESTypePlugin *plugin = NULL;
    const struct PRESTypePluginVersion PLUGIN_VERSION = 
        PRES_TYPE_PLUGIN_VERSION_2_0;

    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);
    if (plugin == NULL) {
       return NULL;
    }

    plugin->version = PLUGIN_VERSION;

    /* set up parent's function pointers */
    plugin->onParticipantAttached =
        (PRESTypePluginOnParticipantAttachedCallback)
        DMSG_GFC_HITEXPECTPlugin_on_participant_attached;
    plugin->onParticipantDetached =
        (PRESTypePluginOnParticipantDetachedCallback)
        DMSG_GFC_HITEXPECTPlugin_on_participant_detached;
    plugin->onEndpointAttached =
        (PRESTypePluginOnEndpointAttachedCallback)
        DMSG_GFC_HITEXPECTPlugin_on_endpoint_attached;
    plugin->onEndpointDetached =
        (PRESTypePluginOnEndpointDetachedCallback)
        DMSG_GFC_HITEXPECTPlugin_on_endpoint_detached;

    plugin->copySampleFnc =
        (PRESTypePluginCopySampleFunction)
        DMSG_GFC_HITEXPECTPlugin_copy_sample;
    plugin->createSampleFnc =
        (PRESTypePluginCreateSampleFunction)
        DMSG_GFC_HITEXPECTPlugin_create_sample;
    plugin->destroySampleFnc =
        (PRESTypePluginDestroySampleFunction)
        DMSG_GFC_HITEXPECTPlugin_destroy_sample;

    plugin->serializeFnc =
        (PRESTypePluginSerializeFunction)
        DMSG_GFC_HITEXPECTPlugin_serialize;
    plugin->deserializeFnc =
        (PRESTypePluginDeserializeFunction)
        DMSG_GFC_HITEXPECTPlugin_deserialize;
    plugin->getSerializedSampleMaxSizeFnc =
        (PRESTypePluginGetSerializedSampleMaxSizeFunction)
        DMSG_GFC_HITEXPECTPlugin_get_serialized_sample_max_size;
    plugin->getSerializedSampleMinSizeFnc =
        (PRESTypePluginGetSerializedSampleMinSizeFunction)
        DMSG_GFC_HITEXPECTPlugin_get_serialized_sample_min_size;


    plugin->getSampleFnc =
        (PRESTypePluginGetSampleFunction)
        DMSG_GFC_HITEXPECTPlugin_get_sample;
    plugin->returnSampleFnc =
        (PRESTypePluginReturnSampleFunction)
        DMSG_GFC_HITEXPECTPlugin_return_sample;

    plugin->getKeyKindFnc =
        (PRESTypePluginGetKeyKindFunction)
        DMSG_GFC_HITEXPECTPlugin_get_key_kind;

 
    /* These functions are only used for keyed types. As this is not a keyed
    type they are all set to NULL
    */
    plugin->serializeKeyFnc = NULL;
    plugin->deserializeKeyFnc = NULL;
    plugin->getKeyFnc = NULL;
    plugin->returnKeyFnc = NULL;
    plugin->instanceToKeyFnc = NULL;
    plugin->keyToInstanceFnc = NULL;
    plugin->getSerializedKeyMaxSizeFnc = NULL;
    plugin->instanceToKeyHashFnc = NULL;
    plugin->serializedSampleToKeyHashFnc = NULL;
    plugin->serializedKeyToKeyHashFnc = NULL;
    
    plugin->typeCode =  (struct RTICdrTypeCode *)DMSG_GFC_HITEXPECT_get_typecode();
    
    plugin->languageKind = PRES_TYPEPLUGIN_DDS_TYPE; 

    /* Serialized buffer */
    plugin->getBuffer = 
        (PRESTypePluginGetBufferFunction)
        DMSG_GFC_HITEXPECTPlugin_get_buffer;
    plugin->returnBuffer = 
        (PRESTypePluginReturnBufferFunction)
        DMSG_GFC_HITEXPECTPlugin_return_buffer;
    plugin->getSerializedSampleSizeFnc =
        (PRESTypePluginGetSerializedSampleSizeFunction)
        DMSG_GFC_HITEXPECTPlugin_get_serialized_sample_size;

    plugin->endpointTypeName = DMSG_GFC_HITEXPECTTYPENAME;

    return plugin;
}

void
DMSG_GFC_HITEXPECTPlugin_delete(struct PRESTypePlugin *plugin)
{
    RTIOsapiHeap_freeStructure(plugin);
} 

/* --------------------------------------------------------------------------------------
 *  Type DMSG_GUN_STATE
 * -------------------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

DMSG_GUN_STATE *
DMSG_GUN_STATEPluginSupport_create_data_ex(RTIBool allocate_pointers){
    DMSG_GUN_STATE *sample = NULL;

    RTIOsapiHeap_allocateStructure(
        &sample, DMSG_GUN_STATE);

    if(sample != NULL) {
        if (!DMSG_GUN_STATE_initialize_ex(sample,allocate_pointers)) {
            RTIOsapiHeap_freeStructure(&sample);
            return NULL;
        }
    }
    return sample; 
}


DMSG_GUN_STATE *
DMSG_GUN_STATEPluginSupport_create_data(void)
{
    return DMSG_GUN_STATEPluginSupport_create_data_ex(RTI_TRUE);
}


void 
DMSG_GUN_STATEPluginSupport_destroy_data_ex(
    DMSG_GUN_STATE *sample,RTIBool deallocate_pointers) {

    DMSG_GUN_STATE_finalize_ex(sample,deallocate_pointers);

    RTIOsapiHeap_freeStructure(sample);
}


void 
DMSG_GUN_STATEPluginSupport_destroy_data(
    DMSG_GUN_STATE *sample) {

    DMSG_GUN_STATEPluginSupport_destroy_data_ex(sample,RTI_TRUE);

}


RTIBool 
DMSG_GUN_STATEPluginSupport_copy_data(
    DMSG_GUN_STATE *dst,
    const DMSG_GUN_STATE *src)
{
    return DMSG_GUN_STATE_copy(dst,src);
}


void 
DMSG_GUN_STATEPluginSupport_print_data(
    const DMSG_GUN_STATE *sample,
    const char *desc,
    unsigned int indent_level)
{


    RTICdrType_printIndent(indent_level);

    if (desc != NULL) {
      RTILog_debug("%s:\n", desc);
    } else {
      RTILog_debug("\n");
    }

    if (sample == NULL) {
      RTILog_debug("NULL\n");
      return;
    }


    RTICdrType_printChar(
        &sample->bMotorState, "bMotorState", indent_level + 1);
            
    RTICdrType_printChar(
        &sample->bControlMode, "bControlMode", indent_level + 1);
            
    RTICdrType_printChar(
        &sample->bGunState, "bGunState", indent_level + 1);
            
    RTICdrType_printChar(
        &sample->bServerState, "bServerState", indent_level + 1);
            
    RTICdrType_printChar(
        &sample->bAngleModeState, "bAngleModeState", indent_level + 1);
            
    RTICdrType_printChar(
        &sample->bAlignedState, "bAlignedState", indent_level + 1);
            
    RTICdrType_printChar(
        &sample->bFireAuthorizedState, "bFireAuthorizedState", indent_level + 1);
            
    RTICdrType_printChar(
        &sample->bAssignedState, "bAssignedState", indent_level + 1);
            
    RTICdrType_printChar(
        &sample->bFiringState, "bFiringState", indent_level + 1);
            
    RTICdrType_printChar(
        &sample->byAimingMode, "byAimingMode", indent_level + 1);
            
    RTICdrType_printChar(
        &sample->bFuzeSetter, "bFuzeSetter", indent_level + 1);
            
    RTICdrType_printUnsignedLong(
        &sample->nInventoryInfo, "nInventoryInfo", indent_level + 1);
            
    RTICdrType_printDouble(
        &sample->dAngle, "dAngle", indent_level + 1);
            
    RTICdrType_printDouble(
        &sample->dElevation, "dElevation", indent_level + 1);
            
    RTICdrType_printFloat(
        &sample->fTimeOfFlight, "fTimeOfFlight", indent_level + 1);
            
    RTICdrType_printDouble(
        &sample->dTellbackMuzzleVelocity, "dTellbackMuzzleVelocity", indent_level + 1);
            
    RTICdrType_printDouble(
        &sample->dTellbackPropellantsTemp, "dTellbackPropellantsTemp", indent_level + 1);
            
    RTICdrType_printDouble(
        &sample->dTellbackRatateAngle, "dTellbackRatateAngle", indent_level + 1);
            
    RTICdrType_printDouble(
        &sample->dTellbackElevation, "dTellbackElevation", indent_level + 1);
            

}



/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */



PRESTypePluginParticipantData 
DMSG_GUN_STATEPlugin_on_participant_attached(
    void *registration_data,
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration,
    void *container_plugin_context,
    RTICdrTypeCode *type_code)
{

    if (registration_data) {} /* To avoid warnings */
    if (participant_info) {} /* To avoid warnings */
    if (top_level_registration) {} /* To avoid warnings */
    if (container_plugin_context) {} /* To avoid warnings */
    if (type_code) {} /* To avoid warnings */
    return PRESTypePluginDefaultParticipantData_new(participant_info);

}


void 
DMSG_GUN_STATEPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data)
{

  PRESTypePluginDefaultParticipantData_delete(participant_data);
}


PRESTypePluginEndpointData
DMSG_GUN_STATEPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *containerPluginContext)
{
    PRESTypePluginEndpointData epd = NULL;

   if (top_level_registration) {} /* To avoid warnings */
   if (containerPluginContext) {} /* To avoid warnings */

    epd = PRESTypePluginDefaultEndpointData_new(
            participant_data,
            endpoint_info,
            (PRESTypePluginDefaultEndpointDataCreateSampleFunction)
            DMSG_GUN_STATEPluginSupport_create_data,
            (PRESTypePluginDefaultEndpointDataDestroySampleFunction)
            DMSG_GUN_STATEPluginSupport_destroy_data,
            NULL, NULL);

    if (epd == NULL) {
        return NULL;
    }

    
    if (endpoint_info->endpointKind == PRES_TYPEPLUGIN_ENDPOINT_WRITER) {
        if (PRESTypePluginDefaultEndpointData_createWriterPool(
                epd,
                endpoint_info,
            (PRESTypePluginGetSerializedSampleMaxSizeFunction)
                DMSG_GUN_STATEPlugin_get_serialized_sample_max_size, epd,
            (PRESTypePluginGetSerializedSampleSizeFunction)
            DMSG_GUN_STATEPlugin_get_serialized_sample_size,
            epd) == RTI_FALSE) {
            PRESTypePluginDefaultEndpointData_delete(epd);
            return NULL;
        }
    }
    


    return epd;    
}


void 
DMSG_GUN_STATEPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data)
{  

    PRESTypePluginDefaultEndpointData_delete(endpoint_data);
}


RTIBool 
DMSG_GUN_STATEPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_GUN_STATE *dst,
    const DMSG_GUN_STATE *src)
{
    if (endpoint_data) {} /* To avoid warnings */
    return DMSG_GUN_STATEPluginSupport_copy_data(dst,src);
}

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */


RTIBool 
DMSG_GUN_STATEPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_GUN_STATE *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;
    RTIBool retval = RTI_TRUE;


  if (endpoint_data) {} /* To avoid warnings */
  if (endpoint_plugin_qos) {} /* To avoid warnings */


  if(serialize_encapsulation) {

    if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream, encapsulation_id)) {
        return RTI_FALSE;
    }

    position = RTICdrStream_resetAlignment(stream);

  }

  if(serialize_sample) {

    if (!RTICdrStream_serializeChar(
        stream, &sample->bMotorState)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeChar(
        stream, &sample->bControlMode)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeChar(
        stream, &sample->bGunState)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeChar(
        stream, &sample->bServerState)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeChar(
        stream, &sample->bAngleModeState)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeChar(
        stream, &sample->bAlignedState)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeChar(
        stream, &sample->bFireAuthorizedState)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeChar(
        stream, &sample->bAssignedState)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeChar(
        stream, &sample->bFiringState)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeChar(
        stream, &sample->byAimingMode)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeChar(
        stream, &sample->bFuzeSetter)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeUnsignedLong(
        stream, &sample->nInventoryInfo)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeDouble(
        stream, &sample->dAngle)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeDouble(
        stream, &sample->dElevation)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeFloat(
        stream, &sample->fTimeOfFlight)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeDouble(
        stream, &sample->dTellbackMuzzleVelocity)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeDouble(
        stream, &sample->dTellbackPropellantsTemp)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeDouble(
        stream, &sample->dTellbackRatateAngle)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeDouble(
        stream, &sample->dTellbackElevation)) {
        return RTI_FALSE;
    }
            
  }

  if(serialize_encapsulation) {
    RTICdrStream_restoreAlignment(stream,position);
  }


  return retval;
}


RTIBool 
DMSG_GUN_STATEPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_GUN_STATE *sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(deserialize_encapsulation) {
        /* Deserialize encapsulation */
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);

    }
    
    if(deserialize_sample) {


    if (!RTICdrStream_deserializeChar(
        stream, &sample->bMotorState)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeChar(
        stream, &sample->bControlMode)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeChar(
        stream, &sample->bGunState)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeChar(
        stream, &sample->bServerState)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeChar(
        stream, &sample->bAngleModeState)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeChar(
        stream, &sample->bAlignedState)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeChar(
        stream, &sample->bFireAuthorizedState)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeChar(
        stream, &sample->bAssignedState)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeChar(
        stream, &sample->bFiringState)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeChar(
        stream, &sample->byAimingMode)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeChar(
        stream, &sample->bFuzeSetter)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeUnsignedLong(
        stream, &sample->nInventoryInfo)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeDouble(
        stream, &sample->dAngle)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeDouble(
        stream, &sample->dElevation)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeFloat(
        stream, &sample->fTimeOfFlight)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeDouble(
        stream, &sample->dTellbackMuzzleVelocity)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeDouble(
        stream, &sample->dTellbackPropellantsTemp)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeDouble(
        stream, &sample->dTellbackRatateAngle)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeDouble(
        stream, &sample->dTellbackElevation)) {
        return RTI_FALSE;
    }
            
    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}

 
 
RTIBool 
DMSG_GUN_STATEPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_GUN_STATE **sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{

    if (drop_sample) {} /* To avoid warnings */

    return DMSG_GUN_STATEPlugin_deserialize_sample( 
        endpoint_data, (sample != NULL)?*sample:NULL,
        stream, deserialize_encapsulation, deserialize_sample, 
        endpoint_plugin_qos);
 
}



RTIBool DMSG_GUN_STATEPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream,   
    RTIBool skip_encapsulation,
    RTIBool skip_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(skip_encapsulation) {
        if (!RTICdrStream_skipEncapsulation(stream)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if (skip_sample) {

    if (!RTICdrStream_skipChar(stream)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipChar(stream)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipChar(stream)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipChar(stream)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipChar(stream)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipChar(stream)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipChar(stream)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipChar(stream)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipChar(stream)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipChar(stream)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipChar(stream)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipUnsignedLong(stream)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipDouble(stream)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipDouble(stream)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipFloat(stream)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipDouble(stream)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipDouble(stream)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipDouble(stream)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipDouble(stream)) {
        return RTI_FALSE;
    }
            
    }


    if(skip_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


unsigned int 
DMSG_GUN_STATEPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment +=  RTICdrType_getCharMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getCharMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getCharMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getCharMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getCharMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getCharMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getCharMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getCharMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getCharMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getCharMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getCharMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getUnsignedLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getDoubleMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getDoubleMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getFloatMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getDoubleMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getDoubleMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getDoubleMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getDoubleMaxSizeSerialized(
        current_alignment);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


unsigned int 
DMSG_GUN_STATEPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment +=  RTICdrType_getCharMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getCharMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getCharMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getCharMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getCharMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getCharMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getCharMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getCharMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getCharMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getCharMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getCharMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getUnsignedLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getDoubleMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getDoubleMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getFloatMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getDoubleMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getDoubleMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getDoubleMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getDoubleMaxSizeSerialized(
        current_alignment);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


/* Returns the size of the sample in its serialized form (in bytes).
 * It can also be an estimation in excess of the real buffer needed 
 * during a call to the serialize() function.
 * The value reported does not have to include the space for the
 * encapsulation flags.
 */
unsigned int
DMSG_GUN_STATEPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const DMSG_GUN_STATE * sample) 
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */
    if (sample) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment += RTICdrType_getCharMaxSizeSerialized(
        current_alignment);
            
    current_alignment += RTICdrType_getCharMaxSizeSerialized(
        current_alignment);
            
    current_alignment += RTICdrType_getCharMaxSizeSerialized(
        current_alignment);
            
    current_alignment += RTICdrType_getCharMaxSizeSerialized(
        current_alignment);
            
    current_alignment += RTICdrType_getCharMaxSizeSerialized(
        current_alignment);
            
    current_alignment += RTICdrType_getCharMaxSizeSerialized(
        current_alignment);
            
    current_alignment += RTICdrType_getCharMaxSizeSerialized(
        current_alignment);
            
    current_alignment += RTICdrType_getCharMaxSizeSerialized(
        current_alignment);
            
    current_alignment += RTICdrType_getCharMaxSizeSerialized(
        current_alignment);
            
    current_alignment += RTICdrType_getCharMaxSizeSerialized(
        current_alignment);
            
    current_alignment += RTICdrType_getCharMaxSizeSerialized(
        current_alignment);
            
    current_alignment += RTICdrType_getUnsignedLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment += RTICdrType_getDoubleMaxSizeSerialized(
        current_alignment);
            
    current_alignment += RTICdrType_getDoubleMaxSizeSerialized(
        current_alignment);
            
    current_alignment += RTICdrType_getFloatMaxSizeSerialized(
        current_alignment);
            
    current_alignment += RTICdrType_getDoubleMaxSizeSerialized(
        current_alignment);
            
    current_alignment += RTICdrType_getDoubleMaxSizeSerialized(
        current_alignment);
            
    current_alignment += RTICdrType_getDoubleMaxSizeSerialized(
        current_alignment);
            
    current_alignment += RTICdrType_getDoubleMaxSizeSerialized(
        current_alignment);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}

/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */


PRESTypePluginKeyKind 
DMSG_GUN_STATEPlugin_get_key_kind(void)
{

    return PRES_TYPEPLUGIN_NO_KEY;
     
}


RTIBool 
DMSG_GUN_STATEPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const DMSG_GUN_STATE *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(serialize_encapsulation) {
        if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream, encapsulation_id)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if(serialize_key) {

        if (!DMSG_GUN_STATEPlugin_serialize(
                endpoint_data,
                sample,
                stream,
                RTI_FALSE, encapsulation_id,
                RTI_TRUE,
                endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
    
    }


    if(serialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


RTIBool DMSG_GUN_STATEPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_GUN_STATE *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(deserialize_encapsulation) {
        /* Deserialize encapsulation */
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;  
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if (deserialize_key) {

        if (!DMSG_GUN_STATEPlugin_deserialize_sample(
                endpoint_data, sample, stream,
                RTI_FALSE, RTI_TRUE, 
                endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
    
    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


 
RTIBool DMSG_GUN_STATEPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_GUN_STATE **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    if (drop_sample) {} /* To avoid warnings */
    return DMSG_GUN_STATEPlugin_deserialize_key_sample(
        endpoint_data, (sample != NULL)?*sample:NULL, stream,
        deserialize_encapsulation, deserialize_key, endpoint_plugin_qos);
}



unsigned int
DMSG_GUN_STATEPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int encapsulation_size = current_alignment;


    unsigned int initial_alignment = current_alignment;


    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {
        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }


        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }
        

    current_alignment += DMSG_GUN_STATEPlugin_get_serialized_sample_max_size(
        endpoint_data,RTI_FALSE, encapsulation_id, current_alignment);
    
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


RTIBool 
DMSG_GUN_STATEPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    DMSG_GUN_STATE *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;


    if(deserialize_encapsulation) {
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);

    }

    if (deserialize_key) {

        if (!DMSG_GUN_STATEPlugin_deserialize_sample(
            endpoint_data, sample, stream, RTI_FALSE, 
            RTI_TRUE, endpoint_plugin_qos)) {
            return RTI_FALSE;
        }

    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}




/* ------------------------------------------------------------------------
 * Plug-in Installation Methods
 * ------------------------------------------------------------------------ */
 
struct PRESTypePlugin *DMSG_GUN_STATEPlugin_new(void) 
{ 
    struct PRESTypePlugin *plugin = NULL;
    const struct PRESTypePluginVersion PLUGIN_VERSION = 
        PRES_TYPE_PLUGIN_VERSION_2_0;

    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);
    if (plugin == NULL) {
       return NULL;
    }

    plugin->version = PLUGIN_VERSION;

    /* set up parent's function pointers */
    plugin->onParticipantAttached =
        (PRESTypePluginOnParticipantAttachedCallback)
        DMSG_GUN_STATEPlugin_on_participant_attached;
    plugin->onParticipantDetached =
        (PRESTypePluginOnParticipantDetachedCallback)
        DMSG_GUN_STATEPlugin_on_participant_detached;
    plugin->onEndpointAttached =
        (PRESTypePluginOnEndpointAttachedCallback)
        DMSG_GUN_STATEPlugin_on_endpoint_attached;
    plugin->onEndpointDetached =
        (PRESTypePluginOnEndpointDetachedCallback)
        DMSG_GUN_STATEPlugin_on_endpoint_detached;

    plugin->copySampleFnc =
        (PRESTypePluginCopySampleFunction)
        DMSG_GUN_STATEPlugin_copy_sample;
    plugin->createSampleFnc =
        (PRESTypePluginCreateSampleFunction)
        DMSG_GUN_STATEPlugin_create_sample;
    plugin->destroySampleFnc =
        (PRESTypePluginDestroySampleFunction)
        DMSG_GUN_STATEPlugin_destroy_sample;

    plugin->serializeFnc =
        (PRESTypePluginSerializeFunction)
        DMSG_GUN_STATEPlugin_serialize;
    plugin->deserializeFnc =
        (PRESTypePluginDeserializeFunction)
        DMSG_GUN_STATEPlugin_deserialize;
    plugin->getSerializedSampleMaxSizeFnc =
        (PRESTypePluginGetSerializedSampleMaxSizeFunction)
        DMSG_GUN_STATEPlugin_get_serialized_sample_max_size;
    plugin->getSerializedSampleMinSizeFnc =
        (PRESTypePluginGetSerializedSampleMinSizeFunction)
        DMSG_GUN_STATEPlugin_get_serialized_sample_min_size;


    plugin->getSampleFnc =
        (PRESTypePluginGetSampleFunction)
        DMSG_GUN_STATEPlugin_get_sample;
    plugin->returnSampleFnc =
        (PRESTypePluginReturnSampleFunction)
        DMSG_GUN_STATEPlugin_return_sample;

    plugin->getKeyKindFnc =
        (PRESTypePluginGetKeyKindFunction)
        DMSG_GUN_STATEPlugin_get_key_kind;

 
    /* These functions are only used for keyed types. As this is not a keyed
    type they are all set to NULL
    */
    plugin->serializeKeyFnc = NULL;
    plugin->deserializeKeyFnc = NULL;
    plugin->getKeyFnc = NULL;
    plugin->returnKeyFnc = NULL;
    plugin->instanceToKeyFnc = NULL;
    plugin->keyToInstanceFnc = NULL;
    plugin->getSerializedKeyMaxSizeFnc = NULL;
    plugin->instanceToKeyHashFnc = NULL;
    plugin->serializedSampleToKeyHashFnc = NULL;
    plugin->serializedKeyToKeyHashFnc = NULL;
    
    plugin->typeCode =  (struct RTICdrTypeCode *)DMSG_GUN_STATE_get_typecode();
    
    plugin->languageKind = PRES_TYPEPLUGIN_DDS_TYPE; 

    /* Serialized buffer */
    plugin->getBuffer = 
        (PRESTypePluginGetBufferFunction)
        DMSG_GUN_STATEPlugin_get_buffer;
    plugin->returnBuffer = 
        (PRESTypePluginReturnBufferFunction)
        DMSG_GUN_STATEPlugin_return_buffer;
    plugin->getSerializedSampleSizeFnc =
        (PRESTypePluginGetSerializedSampleSizeFunction)
        DMSG_GUN_STATEPlugin_get_serialized_sample_size;

    plugin->endpointTypeName = DMSG_GUN_STATETYPENAME;

    return plugin;
}

void
DMSG_GUN_STATEPlugin_delete(struct PRESTypePlugin *plugin)
{
    RTIOsapiHeap_freeStructure(plugin);
} 
