
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from DDS_TDSRMMI.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Data Distribution Service manual.
*/


#ifndef NDDS_STANDALONE_TYPE
    #ifdef __cplusplus
        #ifndef ndds_cpp_h
            #include "ndds/ndds_cpp.h"
        #endif
        #ifndef dds_c_log_impl_h              
            #include "dds_c/dds_c_log_impl.h"                                
        #endif        
    #else
        #ifndef ndds_c_h
            #include "ndds/ndds_c.h"
        #endif
    #endif
    
    #ifndef cdr_type_h
        #include "cdr/cdr_type.h"
    #endif    

    #ifndef osapi_heap_h
        #include "osapi/osapi_heap.h" 
    #endif
#else
    #include "ndds_standalone_type.h"
#endif



#include "DDS_TDSRMMI.h"

/* ========================================================================= */
const char *DMSG_TDSR_FIELDSETRESULTTYPENAME = "DMSG_TDSR_FIELDSETRESULT";

DDS_TypeCode* DMSG_TDSR_FIELDSETRESULT_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_TDSR_FIELDSETRESULT_g_tc_members[10]=
    {
        {
            (char *)"byFieldCategory",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"byFieldConfig",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"bySerialNumber",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"dStartBearing",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"dEndBearing",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"dStartDistance",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"dEndDistance",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"dStartAltitude",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"dEndAltitude",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"byStandardPoint",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode DMSG_TDSR_FIELDSETRESULT_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_TDSR_FIELDSETRESULT", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        10, /* Number of members */
        DMSG_TDSR_FIELDSETRESULT_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_TDSR_FIELDSETRESULT*/

    if (is_initialized) {
        return &DMSG_TDSR_FIELDSETRESULT_g_tc;
    }


    DMSG_TDSR_FIELDSETRESULT_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_TDSR_FIELDSETRESULT_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_TDSR_FIELDSETRESULT_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_TDSR_FIELDSETRESULT_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_TDSR_FIELDSETRESULT_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_TDSR_FIELDSETRESULT_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_TDSR_FIELDSETRESULT_g_tc_members[6]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_TDSR_FIELDSETRESULT_g_tc_members[7]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_TDSR_FIELDSETRESULT_g_tc_members[8]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_TDSR_FIELDSETRESULT_g_tc_members[9]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;

    is_initialized = RTI_TRUE;

    return &DMSG_TDSR_FIELDSETRESULT_g_tc;
}


RTIBool DMSG_TDSR_FIELDSETRESULT_initialize(
    DMSG_TDSR_FIELDSETRESULT* sample) {
  return DMSG_TDSR_FIELDSETRESULT_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_TDSR_FIELDSETRESULT_initialize_ex(
    DMSG_TDSR_FIELDSETRESULT* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initChar(&sample->byFieldCategory)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->byFieldConfig)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->bySerialNumber)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dStartBearing)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dEndBearing)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dStartDistance)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dEndDistance)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dStartAltitude)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dEndAltitude)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->byStandardPoint)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_TDSR_FIELDSETRESULT_finalize(
    DMSG_TDSR_FIELDSETRESULT* sample)
{
    DMSG_TDSR_FIELDSETRESULT_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_TDSR_FIELDSETRESULT_finalize_ex(
    DMSG_TDSR_FIELDSETRESULT* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_TDSR_FIELDSETRESULT_copy(
    DMSG_TDSR_FIELDSETRESULT* dst,
    const DMSG_TDSR_FIELDSETRESULT* src)
{        

    if (!RTICdrType_copyChar(
        &dst->byFieldCategory, &src->byFieldCategory)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->byFieldConfig, &src->byFieldConfig)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->bySerialNumber, &src->bySerialNumber)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dStartBearing, &src->dStartBearing)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dEndBearing, &src->dEndBearing)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dStartDistance, &src->dStartDistance)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dEndDistance, &src->dEndDistance)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dStartAltitude, &src->dStartAltitude)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dEndAltitude, &src->dEndAltitude)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->byStandardPoint, &src->byStandardPoint)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_TDSR_FIELDSETRESULT' sequence class.
 */
#define T DMSG_TDSR_FIELDSETRESULT
#define TSeq DMSG_TDSR_FIELDSETRESULTSeq
#define T_initialize_ex DMSG_TDSR_FIELDSETRESULT_initialize_ex
#define T_finalize_ex   DMSG_TDSR_FIELDSETRESULT_finalize_ex
#define T_copy       DMSG_TDSR_FIELDSETRESULT_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *DMSG_TDSR_JAMMINGTYPENAME = "DMSG_TDSR_JAMMING";

DDS_TypeCode* DMSG_TDSR_JAMMING_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_TDSR_JAMMING_g_tc_members[4]=
    {
        {
            (char *)"dTime",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"ReceiveRFChannel",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"dBearing",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"dAltitude",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode DMSG_TDSR_JAMMING_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_TDSR_JAMMING", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        4, /* Number of members */
        DMSG_TDSR_JAMMING_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_TDSR_JAMMING*/

    if (is_initialized) {
        return &DMSG_TDSR_JAMMING_g_tc;
    }


    DMSG_TDSR_JAMMING_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_TDSR_JAMMING_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_TDSR_JAMMING_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_TDSR_JAMMING_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;

    is_initialized = RTI_TRUE;

    return &DMSG_TDSR_JAMMING_g_tc;
}


RTIBool DMSG_TDSR_JAMMING_initialize(
    DMSG_TDSR_JAMMING* sample) {
  return DMSG_TDSR_JAMMING_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_TDSR_JAMMING_initialize_ex(
    DMSG_TDSR_JAMMING* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initDouble(&sample->dTime)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->ReceiveRFChannel)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dBearing)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dAltitude)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_TDSR_JAMMING_finalize(
    DMSG_TDSR_JAMMING* sample)
{
    DMSG_TDSR_JAMMING_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_TDSR_JAMMING_finalize_ex(
    DMSG_TDSR_JAMMING* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_TDSR_JAMMING_copy(
    DMSG_TDSR_JAMMING* dst,
    const DMSG_TDSR_JAMMING* src)
{        

    if (!RTICdrType_copyDouble(
        &dst->dTime, &src->dTime)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->ReceiveRFChannel, &src->ReceiveRFChannel)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dBearing, &src->dBearing)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dAltitude, &src->dAltitude)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_TDSR_JAMMING' sequence class.
 */
#define T DMSG_TDSR_JAMMING
#define TSeq DMSG_TDSR_JAMMINGSeq
#define T_initialize_ex DMSG_TDSR_JAMMING_initialize_ex
#define T_finalize_ex   DMSG_TDSR_JAMMING_finalize_ex
#define T_copy       DMSG_TDSR_JAMMING_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *DMSG_TDSR_STATETYPENAME = "DMSG_TDSR_STATE";

DDS_TypeCode* DMSG_TDSR_STATE_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_TDSR_STATE_g_tc_members[22]=
    {
        {
            (char *)"StateInfo",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"ValidState",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"BattleShort",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"PlatformControl",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"BDriveControl",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"BDriveAngle",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"TransmitterControl",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"DuctingMode",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"RadarSlience",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"RFChannel1State",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"RFChannel2State",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"RFChannel3State",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"RFChannel4State",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"RFChannel5State",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"RFChannel6State",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"RFChannel7State",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"RFChannel8State",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"RFMode",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"VideoMode",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"VideoFilter",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"VideoSTCType",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"VideoThreshold",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode DMSG_TDSR_STATE_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_TDSR_STATE", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        22, /* Number of members */
        DMSG_TDSR_STATE_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_TDSR_STATE*/

    if (is_initialized) {
        return &DMSG_TDSR_STATE_g_tc;
    }


    DMSG_TDSR_STATE_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_TDSR_STATE_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_TDSR_STATE_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_TDSR_STATE_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_TDSR_STATE_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_TDSR_STATE_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    DMSG_TDSR_STATE_g_tc_members[6]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_TDSR_STATE_g_tc_members[7]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_TDSR_STATE_g_tc_members[8]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_TDSR_STATE_g_tc_members[9]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_TDSR_STATE_g_tc_members[10]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_TDSR_STATE_g_tc_members[11]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_TDSR_STATE_g_tc_members[12]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_TDSR_STATE_g_tc_members[13]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_TDSR_STATE_g_tc_members[14]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_TDSR_STATE_g_tc_members[15]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_TDSR_STATE_g_tc_members[16]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_TDSR_STATE_g_tc_members[17]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_TDSR_STATE_g_tc_members[18]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_TDSR_STATE_g_tc_members[19]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_TDSR_STATE_g_tc_members[20]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_TDSR_STATE_g_tc_members[21]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;

    is_initialized = RTI_TRUE;

    return &DMSG_TDSR_STATE_g_tc;
}


RTIBool DMSG_TDSR_STATE_initialize(
    DMSG_TDSR_STATE* sample) {
  return DMSG_TDSR_STATE_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_TDSR_STATE_initialize_ex(
    DMSG_TDSR_STATE* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initChar(&sample->StateInfo)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->ValidState)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->BattleShort)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->PlatformControl)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->BDriveControl)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initLong(&sample->BDriveAngle)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->TransmitterControl)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->DuctingMode)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->RadarSlience)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->RFChannel1State)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->RFChannel2State)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->RFChannel3State)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->RFChannel4State)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->RFChannel5State)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->RFChannel6State)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->RFChannel7State)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->RFChannel8State)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->RFMode)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->VideoMode)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->VideoFilter)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->VideoSTCType)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->VideoThreshold)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_TDSR_STATE_finalize(
    DMSG_TDSR_STATE* sample)
{
    DMSG_TDSR_STATE_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_TDSR_STATE_finalize_ex(
    DMSG_TDSR_STATE* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_TDSR_STATE_copy(
    DMSG_TDSR_STATE* dst,
    const DMSG_TDSR_STATE* src)
{        

    if (!RTICdrType_copyChar(
        &dst->StateInfo, &src->StateInfo)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->ValidState, &src->ValidState)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->BattleShort, &src->BattleShort)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->PlatformControl, &src->PlatformControl)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->BDriveControl, &src->BDriveControl)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyLong(
        &dst->BDriveAngle, &src->BDriveAngle)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->TransmitterControl, &src->TransmitterControl)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->DuctingMode, &src->DuctingMode)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->RadarSlience, &src->RadarSlience)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->RFChannel1State, &src->RFChannel1State)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->RFChannel2State, &src->RFChannel2State)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->RFChannel3State, &src->RFChannel3State)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->RFChannel4State, &src->RFChannel4State)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->RFChannel5State, &src->RFChannel5State)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->RFChannel6State, &src->RFChannel6State)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->RFChannel7State, &src->RFChannel7State)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->RFChannel8State, &src->RFChannel8State)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->RFMode, &src->RFMode)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->VideoMode, &src->VideoMode)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->VideoFilter, &src->VideoFilter)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->VideoSTCType, &src->VideoSTCType)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->VideoThreshold, &src->VideoThreshold)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_TDSR_STATE' sequence class.
 */
#define T DMSG_TDSR_STATE
#define TSeq DMSG_TDSR_STATESeq
#define T_initialize_ex DMSG_TDSR_STATE_initialize_ex
#define T_finalize_ex   DMSG_TDSR_STATE_finalize_ex
#define T_copy       DMSG_TDSR_STATE_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *DMSG_TDSR_TARGETTYPENAME = "DMSG_TDSR_TARGET";

DDS_TypeCode* DMSG_TDSR_TARGET_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_TDSR_TARGET_g_tc_members[13]=
    {
        {
            (char *)"nTarget_Number",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"dSystem_Time",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"Target_Category",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"dPosX",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"dPosY",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"dPosZ",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"dVelocityX",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"dVelocityY",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"dVelocityZ",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"dRange_Accuracy",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"dBearing_Accuracy",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"dElevation_Accuracy",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"Track_Phase",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode DMSG_TDSR_TARGET_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_TDSR_TARGET", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        13, /* Number of members */
        DMSG_TDSR_TARGET_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_TDSR_TARGET*/

    if (is_initialized) {
        return &DMSG_TDSR_TARGET_g_tc;
    }


    DMSG_TDSR_TARGET_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    DMSG_TDSR_TARGET_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_TDSR_TARGET_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_TDSR_TARGET_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_TDSR_TARGET_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_TDSR_TARGET_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_TDSR_TARGET_g_tc_members[6]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_TDSR_TARGET_g_tc_members[7]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_TDSR_TARGET_g_tc_members[8]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_TDSR_TARGET_g_tc_members[9]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_TDSR_TARGET_g_tc_members[10]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_TDSR_TARGET_g_tc_members[11]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_TDSR_TARGET_g_tc_members[12]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;

    is_initialized = RTI_TRUE;

    return &DMSG_TDSR_TARGET_g_tc;
}


RTIBool DMSG_TDSR_TARGET_initialize(
    DMSG_TDSR_TARGET* sample) {
  return DMSG_TDSR_TARGET_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_TDSR_TARGET_initialize_ex(
    DMSG_TDSR_TARGET* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initLong(&sample->nTarget_Number)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dSystem_Time)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->Target_Category)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dPosX)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dPosY)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dPosZ)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dVelocityX)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dVelocityY)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dVelocityZ)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dRange_Accuracy)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dBearing_Accuracy)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dElevation_Accuracy)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->Track_Phase)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_TDSR_TARGET_finalize(
    DMSG_TDSR_TARGET* sample)
{
    DMSG_TDSR_TARGET_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_TDSR_TARGET_finalize_ex(
    DMSG_TDSR_TARGET* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_TDSR_TARGET_copy(
    DMSG_TDSR_TARGET* dst,
    const DMSG_TDSR_TARGET* src)
{        

    if (!RTICdrType_copyLong(
        &dst->nTarget_Number, &src->nTarget_Number)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dSystem_Time, &src->dSystem_Time)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->Target_Category, &src->Target_Category)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dPosX, &src->dPosX)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dPosY, &src->dPosY)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dPosZ, &src->dPosZ)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dVelocityX, &src->dVelocityX)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dVelocityY, &src->dVelocityY)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dVelocityZ, &src->dVelocityZ)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dRange_Accuracy, &src->dRange_Accuracy)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dBearing_Accuracy, &src->dBearing_Accuracy)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dElevation_Accuracy, &src->dElevation_Accuracy)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->Track_Phase, &src->Track_Phase)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_TDSR_TARGET' sequence class.
 */
#define T DMSG_TDSR_TARGET
#define TSeq DMSG_TDSR_TARGETSeq
#define T_initialize_ex DMSG_TDSR_TARGET_initialize_ex
#define T_finalize_ex   DMSG_TDSR_TARGET_finalize_ex
#define T_copy       DMSG_TDSR_TARGET_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *DMSG_TDSR_BSCOPETYPENAME = "DMSG_TDSR_BSCOPE";

DDS_TypeCode* DMSG_TDSR_BSCOPE_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode DMSG_TDSR_BSCOPE_g_tc_cGreen_array = DDS_INITIALIZE_ARRAY_TYPECODE(1,40000,NULL,NULL);

    static DDS_TypeCode_Member DMSG_TDSR_BSCOPE_g_tc_members[2]=
    {
        {
            (char *)"nTWS_ID",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"cGreen",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode DMSG_TDSR_BSCOPE_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_TDSR_BSCOPE", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        2, /* Number of members */
        DMSG_TDSR_BSCOPE_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_TDSR_BSCOPE*/

    if (is_initialized) {
        return &DMSG_TDSR_BSCOPE_g_tc;
    }

    DMSG_TDSR_BSCOPE_g_tc_cGreen_array._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;

    DMSG_TDSR_BSCOPE_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    DMSG_TDSR_BSCOPE_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DMSG_TDSR_BSCOPE_g_tc_cGreen_array;

    is_initialized = RTI_TRUE;

    return &DMSG_TDSR_BSCOPE_g_tc;
}


RTIBool DMSG_TDSR_BSCOPE_initialize(
    DMSG_TDSR_BSCOPE* sample) {
  return DMSG_TDSR_BSCOPE_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_TDSR_BSCOPE_initialize_ex(
    DMSG_TDSR_BSCOPE* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initLong(&sample->nTWS_ID)) {
        return RTI_FALSE;
    }                
                
    if (!RTICdrType_initArray(
        sample->cGreen, (40000), RTI_CDR_CHAR_SIZE)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}

void DMSG_TDSR_BSCOPE_finalize(
    DMSG_TDSR_BSCOPE* sample)
{
    DMSG_TDSR_BSCOPE_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_TDSR_BSCOPE_finalize_ex(
    DMSG_TDSR_BSCOPE* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_TDSR_BSCOPE_copy(
    DMSG_TDSR_BSCOPE* dst,
    const DMSG_TDSR_BSCOPE* src)
{        

    if (!RTICdrType_copyLong(
        &dst->nTWS_ID, &src->nTWS_ID)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyArray(
        dst->cGreen, src->cGreen, (40000), RTI_CDR_CHAR_SIZE)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_TDSR_BSCOPE' sequence class.
 */
#define T DMSG_TDSR_BSCOPE
#define TSeq DMSG_TDSR_BSCOPESeq
#define T_initialize_ex DMSG_TDSR_BSCOPE_initialize_ex
#define T_finalize_ex   DMSG_TDSR_BSCOPE_finalize_ex
#define T_copy       DMSG_TDSR_BSCOPE_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *DMSG_TDSR_COLUMNOFWATERTYPENAME = "DMSG_TDSR_COLUMNOFWATER";

DDS_TypeCode* DMSG_TDSR_COLUMNOFWATER_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_TDSR_COLUMNOFWATER_g_tc_members[4]=
    {
        {
            (char *)"nTWS_ID",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"nID",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"dDegree",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"dRange",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode DMSG_TDSR_COLUMNOFWATER_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_TDSR_COLUMNOFWATER", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        4, /* Number of members */
        DMSG_TDSR_COLUMNOFWATER_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_TDSR_COLUMNOFWATER*/

    if (is_initialized) {
        return &DMSG_TDSR_COLUMNOFWATER_g_tc;
    }


    DMSG_TDSR_COLUMNOFWATER_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    DMSG_TDSR_COLUMNOFWATER_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    DMSG_TDSR_COLUMNOFWATER_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_TDSR_COLUMNOFWATER_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;

    is_initialized = RTI_TRUE;

    return &DMSG_TDSR_COLUMNOFWATER_g_tc;
}


RTIBool DMSG_TDSR_COLUMNOFWATER_initialize(
    DMSG_TDSR_COLUMNOFWATER* sample) {
  return DMSG_TDSR_COLUMNOFWATER_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_TDSR_COLUMNOFWATER_initialize_ex(
    DMSG_TDSR_COLUMNOFWATER* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initLong(&sample->nTWS_ID)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initLong(&sample->nID)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dDegree)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dRange)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_TDSR_COLUMNOFWATER_finalize(
    DMSG_TDSR_COLUMNOFWATER* sample)
{
    DMSG_TDSR_COLUMNOFWATER_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_TDSR_COLUMNOFWATER_finalize_ex(
    DMSG_TDSR_COLUMNOFWATER* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_TDSR_COLUMNOFWATER_copy(
    DMSG_TDSR_COLUMNOFWATER* dst,
    const DMSG_TDSR_COLUMNOFWATER* src)
{        

    if (!RTICdrType_copyLong(
        &dst->nTWS_ID, &src->nTWS_ID)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyLong(
        &dst->nID, &src->nID)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dDegree, &src->dDegree)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dRange, &src->dRange)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_TDSR_COLUMNOFWATER' sequence class.
 */
#define T DMSG_TDSR_COLUMNOFWATER
#define TSeq DMSG_TDSR_COLUMNOFWATERSeq
#define T_initialize_ex DMSG_TDSR_COLUMNOFWATER_initialize_ex
#define T_finalize_ex   DMSG_TDSR_COLUMNOFWATER_finalize_ex
#define T_copy       DMSG_TDSR_COLUMNOFWATER_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *DMSG_TDSR_TWSTRACKINGTYPENAME = "DMSG_TDSR_TWSTRACKING";

DDS_TypeCode* DMSG_TDSR_TWSTRACKING_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_TDSR_TWSTRACKING_g_tc_members[14]=
    {
        {
            (char *)"nTWS_TrackingInfo",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"nTarget_Number",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"dSystem_Time",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"cTarget_Category",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"dPosX",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"dPosY",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"dPosZ",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"dVelocityX",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"dVelocityY",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"dVelocityZ",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"dRange_Accuracy",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"dBearing_Accuracy",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"dElevation_Accuracy",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"cTrack_Phase",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode DMSG_TDSR_TWSTRACKING_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_TDSR_TWSTRACKING", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        14, /* Number of members */
        DMSG_TDSR_TWSTRACKING_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_TDSR_TWSTRACKING*/

    if (is_initialized) {
        return &DMSG_TDSR_TWSTRACKING_g_tc;
    }


    DMSG_TDSR_TWSTRACKING_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    DMSG_TDSR_TWSTRACKING_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    DMSG_TDSR_TWSTRACKING_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_TDSR_TWSTRACKING_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_TDSR_TWSTRACKING_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_TDSR_TWSTRACKING_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_TDSR_TWSTRACKING_g_tc_members[6]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_TDSR_TWSTRACKING_g_tc_members[7]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_TDSR_TWSTRACKING_g_tc_members[8]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_TDSR_TWSTRACKING_g_tc_members[9]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_TDSR_TWSTRACKING_g_tc_members[10]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_TDSR_TWSTRACKING_g_tc_members[11]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_TDSR_TWSTRACKING_g_tc_members[12]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_TDSR_TWSTRACKING_g_tc_members[13]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;

    is_initialized = RTI_TRUE;

    return &DMSG_TDSR_TWSTRACKING_g_tc;
}


RTIBool DMSG_TDSR_TWSTRACKING_initialize(
    DMSG_TDSR_TWSTRACKING* sample) {
  return DMSG_TDSR_TWSTRACKING_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_TDSR_TWSTRACKING_initialize_ex(
    DMSG_TDSR_TWSTRACKING* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initLong(&sample->nTWS_TrackingInfo)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initLong(&sample->nTarget_Number)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dSystem_Time)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->cTarget_Category)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dPosX)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dPosY)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dPosZ)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dVelocityX)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dVelocityY)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dVelocityZ)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dRange_Accuracy)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dBearing_Accuracy)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dElevation_Accuracy)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->cTrack_Phase)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_TDSR_TWSTRACKING_finalize(
    DMSG_TDSR_TWSTRACKING* sample)
{
    DMSG_TDSR_TWSTRACKING_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_TDSR_TWSTRACKING_finalize_ex(
    DMSG_TDSR_TWSTRACKING* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_TDSR_TWSTRACKING_copy(
    DMSG_TDSR_TWSTRACKING* dst,
    const DMSG_TDSR_TWSTRACKING* src)
{        

    if (!RTICdrType_copyLong(
        &dst->nTWS_TrackingInfo, &src->nTWS_TrackingInfo)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyLong(
        &dst->nTarget_Number, &src->nTarget_Number)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dSystem_Time, &src->dSystem_Time)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->cTarget_Category, &src->cTarget_Category)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dPosX, &src->dPosX)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dPosY, &src->dPosY)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dPosZ, &src->dPosZ)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dVelocityX, &src->dVelocityX)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dVelocityY, &src->dVelocityY)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dVelocityZ, &src->dVelocityZ)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dRange_Accuracy, &src->dRange_Accuracy)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dBearing_Accuracy, &src->dBearing_Accuracy)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dElevation_Accuracy, &src->dElevation_Accuracy)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->cTrack_Phase, &src->cTrack_Phase)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_TDSR_TWSTRACKING' sequence class.
 */
#define T DMSG_TDSR_TWSTRACKING
#define TSeq DMSG_TDSR_TWSTRACKINGSeq
#define T_initialize_ex DMSG_TDSR_TWSTRACKING_initialize_ex
#define T_finalize_ex   DMSG_TDSR_TWSTRACKING_finalize_ex
#define T_copy       DMSG_TDSR_TWSTRACKING_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *DMSG_HMI_TDSRANTENNACTRLTYPENAME = "DMSG_HMI_TDSRANTENNACTRL";

DDS_TypeCode* DMSG_HMI_TDSRANTENNACTRL_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_HMI_TDSRANTENNACTRL_g_tc_members[3]=
    {
        {
            (char *)"PlatformControl",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"BDriveControl",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"nRequiredBearing",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode DMSG_HMI_TDSRANTENNACTRL_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_HMI_TDSRANTENNACTRL", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        3, /* Number of members */
        DMSG_HMI_TDSRANTENNACTRL_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_HMI_TDSRANTENNACTRL*/

    if (is_initialized) {
        return &DMSG_HMI_TDSRANTENNACTRL_g_tc;
    }


    DMSG_HMI_TDSRANTENNACTRL_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_HMI_TDSRANTENNACTRL_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_HMI_TDSRANTENNACTRL_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

    is_initialized = RTI_TRUE;

    return &DMSG_HMI_TDSRANTENNACTRL_g_tc;
}


RTIBool DMSG_HMI_TDSRANTENNACTRL_initialize(
    DMSG_HMI_TDSRANTENNACTRL* sample) {
  return DMSG_HMI_TDSRANTENNACTRL_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_HMI_TDSRANTENNACTRL_initialize_ex(
    DMSG_HMI_TDSRANTENNACTRL* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initChar(&sample->PlatformControl)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->BDriveControl)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initLong(&sample->nRequiredBearing)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_HMI_TDSRANTENNACTRL_finalize(
    DMSG_HMI_TDSRANTENNACTRL* sample)
{
    DMSG_HMI_TDSRANTENNACTRL_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_HMI_TDSRANTENNACTRL_finalize_ex(
    DMSG_HMI_TDSRANTENNACTRL* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_HMI_TDSRANTENNACTRL_copy(
    DMSG_HMI_TDSRANTENNACTRL* dst,
    const DMSG_HMI_TDSRANTENNACTRL* src)
{        

    if (!RTICdrType_copyChar(
        &dst->PlatformControl, &src->PlatformControl)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->BDriveControl, &src->BDriveControl)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyLong(
        &dst->nRequiredBearing, &src->nRequiredBearing)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_HMI_TDSRANTENNACTRL' sequence class.
 */
#define T DMSG_HMI_TDSRANTENNACTRL
#define TSeq DMSG_HMI_TDSRANTENNACTRLSeq
#define T_initialize_ex DMSG_HMI_TDSRANTENNACTRL_initialize_ex
#define T_finalize_ex   DMSG_HMI_TDSRANTENNACTRL_finalize_ex
#define T_copy       DMSG_HMI_TDSRANTENNACTRL_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *DMSG_HMI_TDSRBATTLESHORTCMDTYPENAME = "DMSG_HMI_TDSRBATTLESHORTCMD";

DDS_TypeCode* DMSG_HMI_TDSRBATTLESHORTCMD_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_HMI_TDSRBATTLESHORTCMD_g_tc_members[1]=
    {
        {
            (char *)"BattleShot",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode DMSG_HMI_TDSRBATTLESHORTCMD_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_HMI_TDSRBATTLESHORTCMD", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        1, /* Number of members */
        DMSG_HMI_TDSRBATTLESHORTCMD_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_HMI_TDSRBATTLESHORTCMD*/

    if (is_initialized) {
        return &DMSG_HMI_TDSRBATTLESHORTCMD_g_tc;
    }


    DMSG_HMI_TDSRBATTLESHORTCMD_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;

    is_initialized = RTI_TRUE;

    return &DMSG_HMI_TDSRBATTLESHORTCMD_g_tc;
}


RTIBool DMSG_HMI_TDSRBATTLESHORTCMD_initialize(
    DMSG_HMI_TDSRBATTLESHORTCMD* sample) {
  return DMSG_HMI_TDSRBATTLESHORTCMD_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_HMI_TDSRBATTLESHORTCMD_initialize_ex(
    DMSG_HMI_TDSRBATTLESHORTCMD* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initChar(&sample->BattleShot)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_HMI_TDSRBATTLESHORTCMD_finalize(
    DMSG_HMI_TDSRBATTLESHORTCMD* sample)
{
    DMSG_HMI_TDSRBATTLESHORTCMD_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_HMI_TDSRBATTLESHORTCMD_finalize_ex(
    DMSG_HMI_TDSRBATTLESHORTCMD* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_HMI_TDSRBATTLESHORTCMD_copy(
    DMSG_HMI_TDSRBATTLESHORTCMD* dst,
    const DMSG_HMI_TDSRBATTLESHORTCMD* src)
{        

    if (!RTICdrType_copyChar(
        &dst->BattleShot, &src->BattleShot)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_HMI_TDSRBATTLESHORTCMD' sequence class.
 */
#define T DMSG_HMI_TDSRBATTLESHORTCMD
#define TSeq DMSG_HMI_TDSRBATTLESHORTCMDSeq
#define T_initialize_ex DMSG_HMI_TDSRBATTLESHORTCMD_initialize_ex
#define T_finalize_ex   DMSG_HMI_TDSRBATTLESHORTCMD_finalize_ex
#define T_copy       DMSG_HMI_TDSRBATTLESHORTCMD_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *DMSG_HMI_TDSRTRANSMITTERCTRLTYPENAME = "DMSG_HMI_TDSRTRANSMITTERCTRL";

DDS_TypeCode* DMSG_HMI_TDSRTRANSMITTERCTRL_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_HMI_TDSRTRANSMITTERCTRL_g_tc_members[1]=
    {
        {
            (char *)"TransmitterControl",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode DMSG_HMI_TDSRTRANSMITTERCTRL_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_HMI_TDSRTRANSMITTERCTRL", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        1, /* Number of members */
        DMSG_HMI_TDSRTRANSMITTERCTRL_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_HMI_TDSRTRANSMITTERCTRL*/

    if (is_initialized) {
        return &DMSG_HMI_TDSRTRANSMITTERCTRL_g_tc;
    }


    DMSG_HMI_TDSRTRANSMITTERCTRL_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;

    is_initialized = RTI_TRUE;

    return &DMSG_HMI_TDSRTRANSMITTERCTRL_g_tc;
}


RTIBool DMSG_HMI_TDSRTRANSMITTERCTRL_initialize(
    DMSG_HMI_TDSRTRANSMITTERCTRL* sample) {
  return DMSG_HMI_TDSRTRANSMITTERCTRL_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_HMI_TDSRTRANSMITTERCTRL_initialize_ex(
    DMSG_HMI_TDSRTRANSMITTERCTRL* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initChar(&sample->TransmitterControl)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_HMI_TDSRTRANSMITTERCTRL_finalize(
    DMSG_HMI_TDSRTRANSMITTERCTRL* sample)
{
    DMSG_HMI_TDSRTRANSMITTERCTRL_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_HMI_TDSRTRANSMITTERCTRL_finalize_ex(
    DMSG_HMI_TDSRTRANSMITTERCTRL* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_HMI_TDSRTRANSMITTERCTRL_copy(
    DMSG_HMI_TDSRTRANSMITTERCTRL* dst,
    const DMSG_HMI_TDSRTRANSMITTERCTRL* src)
{        

    if (!RTICdrType_copyChar(
        &dst->TransmitterControl, &src->TransmitterControl)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_HMI_TDSRTRANSMITTERCTRL' sequence class.
 */
#define T DMSG_HMI_TDSRTRANSMITTERCTRL
#define TSeq DMSG_HMI_TDSRTRANSMITTERCTRLSeq
#define T_initialize_ex DMSG_HMI_TDSRTRANSMITTERCTRL_initialize_ex
#define T_finalize_ex   DMSG_HMI_TDSRTRANSMITTERCTRL_finalize_ex
#define T_copy       DMSG_HMI_TDSRTRANSMITTERCTRL_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *DMSG_OSM_TDSRFIELDSETTYPENAME = "DMSG_OSM_TDSRFIELDSET";

DDS_TypeCode* DMSG_OSM_TDSRFIELDSET_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_OSM_TDSRFIELDSET_g_tc_members[11]=
    {
        {
            (char *)"SiteCategory",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"nID",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"OnOff",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"SerialNumber",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"dStartBearing",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"dEndBearing",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"dStartDistance",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"dEndDistance",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"dStartAltitude",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"dEndAltitude",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"StandardPoint",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode DMSG_OSM_TDSRFIELDSET_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_OSM_TDSRFIELDSET", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        11, /* Number of members */
        DMSG_OSM_TDSRFIELDSET_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_OSM_TDSRFIELDSET*/

    if (is_initialized) {
        return &DMSG_OSM_TDSRFIELDSET_g_tc;
    }


    DMSG_OSM_TDSRFIELDSET_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_OSM_TDSRFIELDSET_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;
    DMSG_OSM_TDSRFIELDSET_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_OSM_TDSRFIELDSET_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_OSM_TDSRFIELDSET_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_OSM_TDSRFIELDSET_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_OSM_TDSRFIELDSET_g_tc_members[6]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_OSM_TDSRFIELDSET_g_tc_members[7]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_OSM_TDSRFIELDSET_g_tc_members[8]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_OSM_TDSRFIELDSET_g_tc_members[9]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_OSM_TDSRFIELDSET_g_tc_members[10]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;

    is_initialized = RTI_TRUE;

    return &DMSG_OSM_TDSRFIELDSET_g_tc;
}


RTIBool DMSG_OSM_TDSRFIELDSET_initialize(
    DMSG_OSM_TDSRFIELDSET* sample) {
  return DMSG_OSM_TDSRFIELDSET_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_OSM_TDSRFIELDSET_initialize_ex(
    DMSG_OSM_TDSRFIELDSET* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initChar(&sample->SiteCategory)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initUnsignedLong(&sample->nID)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->OnOff)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->SerialNumber)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dStartBearing)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dEndBearing)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dStartDistance)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dEndDistance)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dStartAltitude)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dEndAltitude)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->StandardPoint)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_OSM_TDSRFIELDSET_finalize(
    DMSG_OSM_TDSRFIELDSET* sample)
{
    DMSG_OSM_TDSRFIELDSET_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_OSM_TDSRFIELDSET_finalize_ex(
    DMSG_OSM_TDSRFIELDSET* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_OSM_TDSRFIELDSET_copy(
    DMSG_OSM_TDSRFIELDSET* dst,
    const DMSG_OSM_TDSRFIELDSET* src)
{        

    if (!RTICdrType_copyChar(
        &dst->SiteCategory, &src->SiteCategory)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyUnsignedLong(
        &dst->nID, &src->nID)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->OnOff, &src->OnOff)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->SerialNumber, &src->SerialNumber)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dStartBearing, &src->dStartBearing)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dEndBearing, &src->dEndBearing)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dStartDistance, &src->dStartDistance)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dEndDistance, &src->dEndDistance)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dStartAltitude, &src->dStartAltitude)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dEndAltitude, &src->dEndAltitude)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->StandardPoint, &src->StandardPoint)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_OSM_TDSRFIELDSET' sequence class.
 */
#define T DMSG_OSM_TDSRFIELDSET
#define TSeq DMSG_OSM_TDSRFIELDSETSeq
#define T_initialize_ex DMSG_OSM_TDSRFIELDSET_initialize_ex
#define T_finalize_ex   DMSG_OSM_TDSRFIELDSET_finalize_ex
#define T_copy       DMSG_OSM_TDSRFIELDSET_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *DMSG_HMI_TDSRSURFACETRACKCTRLTYPENAME = "DMSG_HMI_TDSRSURFACETRACKCTRL";

DDS_TypeCode* DMSG_HMI_TDSRSURFACETRACKCTRL_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_HMI_TDSRSURFACETRACKCTRL_g_tc_members[5]=
    {
        {
            (char *)"command",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"nTrackNum",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"dPosX",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"dPosY",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"dTimeValidity",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode DMSG_HMI_TDSRSURFACETRACKCTRL_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_HMI_TDSRSURFACETRACKCTRL", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        5, /* Number of members */
        DMSG_HMI_TDSRSURFACETRACKCTRL_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_HMI_TDSRSURFACETRACKCTRL*/

    if (is_initialized) {
        return &DMSG_HMI_TDSRSURFACETRACKCTRL_g_tc;
    }


    DMSG_HMI_TDSRSURFACETRACKCTRL_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_HMI_TDSRSURFACETRACKCTRL_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    DMSG_HMI_TDSRSURFACETRACKCTRL_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_HMI_TDSRSURFACETRACKCTRL_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_HMI_TDSRSURFACETRACKCTRL_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;

    is_initialized = RTI_TRUE;

    return &DMSG_HMI_TDSRSURFACETRACKCTRL_g_tc;
}


RTIBool DMSG_HMI_TDSRSURFACETRACKCTRL_initialize(
    DMSG_HMI_TDSRSURFACETRACKCTRL* sample) {
  return DMSG_HMI_TDSRSURFACETRACKCTRL_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_HMI_TDSRSURFACETRACKCTRL_initialize_ex(
    DMSG_HMI_TDSRSURFACETRACKCTRL* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initChar(&sample->command)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initLong(&sample->nTrackNum)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dPosX)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dPosY)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dTimeValidity)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_HMI_TDSRSURFACETRACKCTRL_finalize(
    DMSG_HMI_TDSRSURFACETRACKCTRL* sample)
{
    DMSG_HMI_TDSRSURFACETRACKCTRL_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_HMI_TDSRSURFACETRACKCTRL_finalize_ex(
    DMSG_HMI_TDSRSURFACETRACKCTRL* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_HMI_TDSRSURFACETRACKCTRL_copy(
    DMSG_HMI_TDSRSURFACETRACKCTRL* dst,
    const DMSG_HMI_TDSRSURFACETRACKCTRL* src)
{        

    if (!RTICdrType_copyChar(
        &dst->command, &src->command)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyLong(
        &dst->nTrackNum, &src->nTrackNum)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dPosX, &src->dPosX)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dPosY, &src->dPosY)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dTimeValidity, &src->dTimeValidity)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_HMI_TDSRSURFACETRACKCTRL' sequence class.
 */
#define T DMSG_HMI_TDSRSURFACETRACKCTRL
#define TSeq DMSG_HMI_TDSRSURFACETRACKCTRLSeq
#define T_initialize_ex DMSG_HMI_TDSRSURFACETRACKCTRL_initialize_ex
#define T_finalize_ex   DMSG_HMI_TDSRSURFACETRACKCTRL_finalize_ex
#define T_copy       DMSG_HMI_TDSRSURFACETRACKCTRL_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *DMSG_HMI_TDSRRDRSILENCECTRLTYPENAME = "DMSG_HMI_TDSRRDRSILENCECTRL";

DDS_TypeCode* DMSG_HMI_TDSRRDRSILENCECTRL_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_HMI_TDSRRDRSILENCECTRL_g_tc_members[1]=
    {
        {
            (char *)"cCommand",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode DMSG_HMI_TDSRRDRSILENCECTRL_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_HMI_TDSRRDRSILENCECTRL", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        1, /* Number of members */
        DMSG_HMI_TDSRRDRSILENCECTRL_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_HMI_TDSRRDRSILENCECTRL*/

    if (is_initialized) {
        return &DMSG_HMI_TDSRRDRSILENCECTRL_g_tc;
    }


    DMSG_HMI_TDSRRDRSILENCECTRL_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;

    is_initialized = RTI_TRUE;

    return &DMSG_HMI_TDSRRDRSILENCECTRL_g_tc;
}


RTIBool DMSG_HMI_TDSRRDRSILENCECTRL_initialize(
    DMSG_HMI_TDSRRDRSILENCECTRL* sample) {
  return DMSG_HMI_TDSRRDRSILENCECTRL_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_HMI_TDSRRDRSILENCECTRL_initialize_ex(
    DMSG_HMI_TDSRRDRSILENCECTRL* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initChar(&sample->cCommand)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_HMI_TDSRRDRSILENCECTRL_finalize(
    DMSG_HMI_TDSRRDRSILENCECTRL* sample)
{
    DMSG_HMI_TDSRRDRSILENCECTRL_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_HMI_TDSRRDRSILENCECTRL_finalize_ex(
    DMSG_HMI_TDSRRDRSILENCECTRL* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_HMI_TDSRRDRSILENCECTRL_copy(
    DMSG_HMI_TDSRRDRSILENCECTRL* dst,
    const DMSG_HMI_TDSRRDRSILENCECTRL* src)
{        

    if (!RTICdrType_copyChar(
        &dst->cCommand, &src->cCommand)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_HMI_TDSRRDRSILENCECTRL' sequence class.
 */
#define T DMSG_HMI_TDSRRDRSILENCECTRL
#define TSeq DMSG_HMI_TDSRRDRSILENCECTRLSeq
#define T_initialize_ex DMSG_HMI_TDSRRDRSILENCECTRL_initialize_ex
#define T_finalize_ex   DMSG_HMI_TDSRRDRSILENCECTRL_finalize_ex
#define T_copy       DMSG_HMI_TDSRRDRSILENCECTRL_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *DMSG_HMI_TDSRSENDCHANNELSETTYPENAME = "DMSG_HMI_TDSRSENDCHANNELSET";

DDS_TypeCode* DMSG_HMI_TDSRSENDCHANNELSET_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_HMI_TDSRSENDCHANNELSET_g_tc_members[3]=
    {
        {
            (char *)"FreqVariableSys",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"ReceiveChannel",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"usSetRFChannel",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode DMSG_HMI_TDSRSENDCHANNELSET_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_HMI_TDSRSENDCHANNELSET", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        3, /* Number of members */
        DMSG_HMI_TDSRSENDCHANNELSET_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_HMI_TDSRSENDCHANNELSET*/

    if (is_initialized) {
        return &DMSG_HMI_TDSRSENDCHANNELSET_g_tc;
    }


    DMSG_HMI_TDSRSENDCHANNELSET_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_HMI_TDSRSENDCHANNELSET_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_HMI_TDSRSENDCHANNELSET_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;

    is_initialized = RTI_TRUE;

    return &DMSG_HMI_TDSRSENDCHANNELSET_g_tc;
}


RTIBool DMSG_HMI_TDSRSENDCHANNELSET_initialize(
    DMSG_HMI_TDSRSENDCHANNELSET* sample) {
  return DMSG_HMI_TDSRSENDCHANNELSET_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_HMI_TDSRSENDCHANNELSET_initialize_ex(
    DMSG_HMI_TDSRSENDCHANNELSET* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initChar(&sample->FreqVariableSys)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->ReceiveChannel)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initUnsignedShort(&sample->usSetRFChannel)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_HMI_TDSRSENDCHANNELSET_finalize(
    DMSG_HMI_TDSRSENDCHANNELSET* sample)
{
    DMSG_HMI_TDSRSENDCHANNELSET_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_HMI_TDSRSENDCHANNELSET_finalize_ex(
    DMSG_HMI_TDSRSENDCHANNELSET* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_HMI_TDSRSENDCHANNELSET_copy(
    DMSG_HMI_TDSRSENDCHANNELSET* dst,
    const DMSG_HMI_TDSRSENDCHANNELSET* src)
{        

    if (!RTICdrType_copyChar(
        &dst->FreqVariableSys, &src->FreqVariableSys)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->ReceiveChannel, &src->ReceiveChannel)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyUnsignedShort(
        &dst->usSetRFChannel, &src->usSetRFChannel)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_HMI_TDSRSENDCHANNELSET' sequence class.
 */
#define T DMSG_HMI_TDSRSENDCHANNELSET
#define TSeq DMSG_HMI_TDSRSENDCHANNELSETSeq
#define T_initialize_ex DMSG_HMI_TDSRSENDCHANNELSET_initialize_ex
#define T_finalize_ex   DMSG_HMI_TDSRSENDCHANNELSET_finalize_ex
#define T_copy       DMSG_HMI_TDSRSENDCHANNELSET_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *DMSG_HMI_TDSRSENDRFMODETYPENAME = "DMSG_HMI_TDSRSENDRFMODE";

DDS_TypeCode* DMSG_HMI_TDSRSENDRFMODE_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_HMI_TDSRSENDRFMODE_g_tc_members[1]=
    {
        {
            (char *)"RFMode",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode DMSG_HMI_TDSRSENDRFMODE_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_HMI_TDSRSENDRFMODE", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        1, /* Number of members */
        DMSG_HMI_TDSRSENDRFMODE_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_HMI_TDSRSENDRFMODE*/

    if (is_initialized) {
        return &DMSG_HMI_TDSRSENDRFMODE_g_tc;
    }


    DMSG_HMI_TDSRSENDRFMODE_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;

    is_initialized = RTI_TRUE;

    return &DMSG_HMI_TDSRSENDRFMODE_g_tc;
}


RTIBool DMSG_HMI_TDSRSENDRFMODE_initialize(
    DMSG_HMI_TDSRSENDRFMODE* sample) {
  return DMSG_HMI_TDSRSENDRFMODE_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_HMI_TDSRSENDRFMODE_initialize_ex(
    DMSG_HMI_TDSRSENDRFMODE* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initChar(&sample->RFMode)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_HMI_TDSRSENDRFMODE_finalize(
    DMSG_HMI_TDSRSENDRFMODE* sample)
{
    DMSG_HMI_TDSRSENDRFMODE_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_HMI_TDSRSENDRFMODE_finalize_ex(
    DMSG_HMI_TDSRSENDRFMODE* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_HMI_TDSRSENDRFMODE_copy(
    DMSG_HMI_TDSRSENDRFMODE* dst,
    const DMSG_HMI_TDSRSENDRFMODE* src)
{        

    if (!RTICdrType_copyChar(
        &dst->RFMode, &src->RFMode)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_HMI_TDSRSENDRFMODE' sequence class.
 */
#define T DMSG_HMI_TDSRSENDRFMODE
#define TSeq DMSG_HMI_TDSRSENDRFMODESeq
#define T_initialize_ex DMSG_HMI_TDSRSENDRFMODE_initialize_ex
#define T_finalize_ex   DMSG_HMI_TDSRSENDRFMODE_finalize_ex
#define T_copy       DMSG_HMI_TDSRSENDRFMODE_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *DMSG_HMI_TDSRBLANKSECTORCTRLTYPENAME = "DMSG_HMI_TDSRBLANKSECTORCTRL";

DDS_TypeCode* DMSG_HMI_TDSRBLANKSECTORCTRL_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_HMI_TDSRBLANKSECTORCTRL_g_tc_members[1]=
    {
        {
            (char *)"cBlanckSector",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode DMSG_HMI_TDSRBLANKSECTORCTRL_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_HMI_TDSRBLANKSECTORCTRL", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        1, /* Number of members */
        DMSG_HMI_TDSRBLANKSECTORCTRL_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_HMI_TDSRBLANKSECTORCTRL*/

    if (is_initialized) {
        return &DMSG_HMI_TDSRBLANKSECTORCTRL_g_tc;
    }


    DMSG_HMI_TDSRBLANKSECTORCTRL_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;

    is_initialized = RTI_TRUE;

    return &DMSG_HMI_TDSRBLANKSECTORCTRL_g_tc;
}


RTIBool DMSG_HMI_TDSRBLANKSECTORCTRL_initialize(
    DMSG_HMI_TDSRBLANKSECTORCTRL* sample) {
  return DMSG_HMI_TDSRBLANKSECTORCTRL_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_HMI_TDSRBLANKSECTORCTRL_initialize_ex(
    DMSG_HMI_TDSRBLANKSECTORCTRL* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initChar(&sample->cBlanckSector)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_HMI_TDSRBLANKSECTORCTRL_finalize(
    DMSG_HMI_TDSRBLANKSECTORCTRL* sample)
{
    DMSG_HMI_TDSRBLANKSECTORCTRL_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_HMI_TDSRBLANKSECTORCTRL_finalize_ex(
    DMSG_HMI_TDSRBLANKSECTORCTRL* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_HMI_TDSRBLANKSECTORCTRL_copy(
    DMSG_HMI_TDSRBLANKSECTORCTRL* dst,
    const DMSG_HMI_TDSRBLANKSECTORCTRL* src)
{        

    if (!RTICdrType_copyChar(
        &dst->cBlanckSector, &src->cBlanckSector)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_HMI_TDSRBLANKSECTORCTRL' sequence class.
 */
#define T DMSG_HMI_TDSRBLANKSECTORCTRL
#define TSeq DMSG_HMI_TDSRBLANKSECTORCTRLSeq
#define T_initialize_ex DMSG_HMI_TDSRBLANKSECTORCTRL_initialize_ex
#define T_finalize_ex   DMSG_HMI_TDSRBLANKSECTORCTRL_finalize_ex
#define T_copy       DMSG_HMI_TDSRBLANKSECTORCTRL_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *DMSG_HMI_TDSRVIDEOSETTYPENAME = "DMSG_HMI_TDSRVIDEOSET";

DDS_TypeCode* DMSG_HMI_TDSRVIDEOSET_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_HMI_TDSRVIDEOSET_g_tc_members[6]=
    {
        {
            (char *)"VideoMode",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"StcCurve",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"VideoClutterFilter",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"VideoLimitMode",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"nVideoLimitValue",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"DuctingConfigMode",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode DMSG_HMI_TDSRVIDEOSET_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_HMI_TDSRVIDEOSET", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        6, /* Number of members */
        DMSG_HMI_TDSRVIDEOSET_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_HMI_TDSRVIDEOSET*/

    if (is_initialized) {
        return &DMSG_HMI_TDSRVIDEOSET_g_tc;
    }


    DMSG_HMI_TDSRVIDEOSET_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_HMI_TDSRVIDEOSET_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_HMI_TDSRVIDEOSET_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_HMI_TDSRVIDEOSET_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_HMI_TDSRVIDEOSET_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    DMSG_HMI_TDSRVIDEOSET_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;

    is_initialized = RTI_TRUE;

    return &DMSG_HMI_TDSRVIDEOSET_g_tc;
}


RTIBool DMSG_HMI_TDSRVIDEOSET_initialize(
    DMSG_HMI_TDSRVIDEOSET* sample) {
  return DMSG_HMI_TDSRVIDEOSET_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_HMI_TDSRVIDEOSET_initialize_ex(
    DMSG_HMI_TDSRVIDEOSET* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initChar(&sample->VideoMode)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->StcCurve)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->VideoClutterFilter)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->VideoLimitMode)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initLong(&sample->nVideoLimitValue)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->DuctingConfigMode)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_HMI_TDSRVIDEOSET_finalize(
    DMSG_HMI_TDSRVIDEOSET* sample)
{
    DMSG_HMI_TDSRVIDEOSET_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_HMI_TDSRVIDEOSET_finalize_ex(
    DMSG_HMI_TDSRVIDEOSET* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_HMI_TDSRVIDEOSET_copy(
    DMSG_HMI_TDSRVIDEOSET* dst,
    const DMSG_HMI_TDSRVIDEOSET* src)
{        

    if (!RTICdrType_copyChar(
        &dst->VideoMode, &src->VideoMode)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->StcCurve, &src->StcCurve)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->VideoClutterFilter, &src->VideoClutterFilter)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->VideoLimitMode, &src->VideoLimitMode)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyLong(
        &dst->nVideoLimitValue, &src->nVideoLimitValue)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->DuctingConfigMode, &src->DuctingConfigMode)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_HMI_TDSRVIDEOSET' sequence class.
 */
#define T DMSG_HMI_TDSRVIDEOSET
#define TSeq DMSG_HMI_TDSRVIDEOSETSeq
#define T_initialize_ex DMSG_HMI_TDSRVIDEOSET_initialize_ex
#define T_finalize_ex   DMSG_HMI_TDSRVIDEOSET_finalize_ex
#define T_copy       DMSG_HMI_TDSRVIDEOSET_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *DMSG_HMI_TDSRVIDEOREQTYPENAME = "DMSG_HMI_TDSRVIDEOREQ";

DDS_TypeCode* DMSG_HMI_TDSRVIDEOREQ_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_HMI_TDSRVIDEOREQ_g_tc_members[1]=
    {
        {
            (char *)"VideoRequestStatus",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode DMSG_HMI_TDSRVIDEOREQ_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_HMI_TDSRVIDEOREQ", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        1, /* Number of members */
        DMSG_HMI_TDSRVIDEOREQ_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_HMI_TDSRVIDEOREQ*/

    if (is_initialized) {
        return &DMSG_HMI_TDSRVIDEOREQ_g_tc;
    }


    DMSG_HMI_TDSRVIDEOREQ_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;

    is_initialized = RTI_TRUE;

    return &DMSG_HMI_TDSRVIDEOREQ_g_tc;
}


RTIBool DMSG_HMI_TDSRVIDEOREQ_initialize(
    DMSG_HMI_TDSRVIDEOREQ* sample) {
  return DMSG_HMI_TDSRVIDEOREQ_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_HMI_TDSRVIDEOREQ_initialize_ex(
    DMSG_HMI_TDSRVIDEOREQ* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initChar(&sample->VideoRequestStatus)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_HMI_TDSRVIDEOREQ_finalize(
    DMSG_HMI_TDSRVIDEOREQ* sample)
{
    DMSG_HMI_TDSRVIDEOREQ_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_HMI_TDSRVIDEOREQ_finalize_ex(
    DMSG_HMI_TDSRVIDEOREQ* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_HMI_TDSRVIDEOREQ_copy(
    DMSG_HMI_TDSRVIDEOREQ* dst,
    const DMSG_HMI_TDSRVIDEOREQ* src)
{        

    if (!RTICdrType_copyChar(
        &dst->VideoRequestStatus, &src->VideoRequestStatus)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_HMI_TDSRVIDEOREQ' sequence class.
 */
#define T DMSG_HMI_TDSRVIDEOREQ
#define TSeq DMSG_HMI_TDSRVIDEOREQSeq
#define T_initialize_ex DMSG_HMI_TDSRVIDEOREQ_initialize_ex
#define T_finalize_ex   DMSG_HMI_TDSRVIDEOREQ_finalize_ex
#define T_copy       DMSG_HMI_TDSRVIDEOREQ_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *DMSG_HMI_TDSRRDRMODESETTYPENAME = "DMSG_HMI_TDSRRDRMODESET";

DDS_TypeCode* DMSG_HMI_TDSRRDRMODESET_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_HMI_TDSRRDRMODESET_g_tc_members[2]=
    {
        {
            (char *)"ManagementMode",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"PRF",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode DMSG_HMI_TDSRRDRMODESET_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_HMI_TDSRRDRMODESET", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        2, /* Number of members */
        DMSG_HMI_TDSRRDRMODESET_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_HMI_TDSRRDRMODESET*/

    if (is_initialized) {
        return &DMSG_HMI_TDSRRDRMODESET_g_tc;
    }


    DMSG_HMI_TDSRRDRMODESET_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_HMI_TDSRRDRMODESET_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;

    is_initialized = RTI_TRUE;

    return &DMSG_HMI_TDSRRDRMODESET_g_tc;
}


RTIBool DMSG_HMI_TDSRRDRMODESET_initialize(
    DMSG_HMI_TDSRRDRMODESET* sample) {
  return DMSG_HMI_TDSRRDRMODESET_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_HMI_TDSRRDRMODESET_initialize_ex(
    DMSG_HMI_TDSRRDRMODESET* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initChar(&sample->ManagementMode)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->PRF)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_HMI_TDSRRDRMODESET_finalize(
    DMSG_HMI_TDSRRDRMODESET* sample)
{
    DMSG_HMI_TDSRRDRMODESET_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_HMI_TDSRRDRMODESET_finalize_ex(
    DMSG_HMI_TDSRRDRMODESET* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_HMI_TDSRRDRMODESET_copy(
    DMSG_HMI_TDSRRDRMODESET* dst,
    const DMSG_HMI_TDSRRDRMODESET* src)
{        

    if (!RTICdrType_copyChar(
        &dst->ManagementMode, &src->ManagementMode)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->PRF, &src->PRF)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_HMI_TDSRRDRMODESET' sequence class.
 */
#define T DMSG_HMI_TDSRRDRMODESET
#define TSeq DMSG_HMI_TDSRRDRMODESETSeq
#define T_initialize_ex DMSG_HMI_TDSRRDRMODESET_initialize_ex
#define T_finalize_ex   DMSG_HMI_TDSRRDRMODESET_finalize_ex
#define T_copy       DMSG_HMI_TDSRRDRMODESET_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *DMSG_HMI_TDSRAIRTRACKINGSETTYPENAME = "DMSG_HMI_TDSRAIRTRACKINGSET";

DDS_TypeCode* DMSG_HMI_TDSRAIRTRACKINGSET_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_HMI_TDSRAIRTRACKINGSET_g_tc_members[1]=
    {
        {
            (char *)"Mode",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode DMSG_HMI_TDSRAIRTRACKINGSET_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_HMI_TDSRAIRTRACKINGSET", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        1, /* Number of members */
        DMSG_HMI_TDSRAIRTRACKINGSET_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_HMI_TDSRAIRTRACKINGSET*/

    if (is_initialized) {
        return &DMSG_HMI_TDSRAIRTRACKINGSET_g_tc;
    }


    DMSG_HMI_TDSRAIRTRACKINGSET_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;

    is_initialized = RTI_TRUE;

    return &DMSG_HMI_TDSRAIRTRACKINGSET_g_tc;
}


RTIBool DMSG_HMI_TDSRAIRTRACKINGSET_initialize(
    DMSG_HMI_TDSRAIRTRACKINGSET* sample) {
  return DMSG_HMI_TDSRAIRTRACKINGSET_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_HMI_TDSRAIRTRACKINGSET_initialize_ex(
    DMSG_HMI_TDSRAIRTRACKINGSET* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initChar(&sample->Mode)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_HMI_TDSRAIRTRACKINGSET_finalize(
    DMSG_HMI_TDSRAIRTRACKINGSET* sample)
{
    DMSG_HMI_TDSRAIRTRACKINGSET_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_HMI_TDSRAIRTRACKINGSET_finalize_ex(
    DMSG_HMI_TDSRAIRTRACKINGSET* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_HMI_TDSRAIRTRACKINGSET_copy(
    DMSG_HMI_TDSRAIRTRACKINGSET* dst,
    const DMSG_HMI_TDSRAIRTRACKINGSET* src)
{        

    if (!RTICdrType_copyChar(
        &dst->Mode, &src->Mode)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_HMI_TDSRAIRTRACKINGSET' sequence class.
 */
#define T DMSG_HMI_TDSRAIRTRACKINGSET
#define TSeq DMSG_HMI_TDSRAIRTRACKINGSETSeq
#define T_initialize_ex DMSG_HMI_TDSRAIRTRACKINGSET_initialize_ex
#define T_finalize_ex   DMSG_HMI_TDSRAIRTRACKINGSET_finalize_ex
#define T_copy       DMSG_HMI_TDSRAIRTRACKINGSET_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *DMSG_HMI_TDSRSHIPTRACKINGSETTYPENAME = "DMSG_HMI_TDSRSHIPTRACKINGSET";

DDS_TypeCode* DMSG_HMI_TDSRSHIPTRACKINGSET_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_HMI_TDSRSHIPTRACKINGSET_g_tc_members[1]=
    {
        {
            (char *)"Mode",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode DMSG_HMI_TDSRSHIPTRACKINGSET_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_HMI_TDSRSHIPTRACKINGSET", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        1, /* Number of members */
        DMSG_HMI_TDSRSHIPTRACKINGSET_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_HMI_TDSRSHIPTRACKINGSET*/

    if (is_initialized) {
        return &DMSG_HMI_TDSRSHIPTRACKINGSET_g_tc;
    }


    DMSG_HMI_TDSRSHIPTRACKINGSET_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;

    is_initialized = RTI_TRUE;

    return &DMSG_HMI_TDSRSHIPTRACKINGSET_g_tc;
}


RTIBool DMSG_HMI_TDSRSHIPTRACKINGSET_initialize(
    DMSG_HMI_TDSRSHIPTRACKINGSET* sample) {
  return DMSG_HMI_TDSRSHIPTRACKINGSET_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_HMI_TDSRSHIPTRACKINGSET_initialize_ex(
    DMSG_HMI_TDSRSHIPTRACKINGSET* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initChar(&sample->Mode)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_HMI_TDSRSHIPTRACKINGSET_finalize(
    DMSG_HMI_TDSRSHIPTRACKINGSET* sample)
{
    DMSG_HMI_TDSRSHIPTRACKINGSET_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_HMI_TDSRSHIPTRACKINGSET_finalize_ex(
    DMSG_HMI_TDSRSHIPTRACKINGSET* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_HMI_TDSRSHIPTRACKINGSET_copy(
    DMSG_HMI_TDSRSHIPTRACKINGSET* dst,
    const DMSG_HMI_TDSRSHIPTRACKINGSET* src)
{        

    if (!RTICdrType_copyChar(
        &dst->Mode, &src->Mode)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_HMI_TDSRSHIPTRACKINGSET' sequence class.
 */
#define T DMSG_HMI_TDSRSHIPTRACKINGSET
#define TSeq DMSG_HMI_TDSRSHIPTRACKINGSETSeq
#define T_initialize_ex DMSG_HMI_TDSRSHIPTRACKINGSET_initialize_ex
#define T_finalize_ex   DMSG_HMI_TDSRSHIPTRACKINGSET_finalize_ex
#define T_copy       DMSG_HMI_TDSRSHIPTRACKINGSET_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *DMSG_HMI_TDSRJAMMINGDETECTSETTYPENAME = "DMSG_HMI_TDSRJAMMINGDETECTSET";

DDS_TypeCode* DMSG_HMI_TDSRJAMMINGDETECTSET_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_HMI_TDSRJAMMINGDETECTSET_g_tc_members[1]=
    {
        {
            (char *)"DetectMode",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode DMSG_HMI_TDSRJAMMINGDETECTSET_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_HMI_TDSRJAMMINGDETECTSET", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        1, /* Number of members */
        DMSG_HMI_TDSRJAMMINGDETECTSET_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_HMI_TDSRJAMMINGDETECTSET*/

    if (is_initialized) {
        return &DMSG_HMI_TDSRJAMMINGDETECTSET_g_tc;
    }


    DMSG_HMI_TDSRJAMMINGDETECTSET_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;

    is_initialized = RTI_TRUE;

    return &DMSG_HMI_TDSRJAMMINGDETECTSET_g_tc;
}


RTIBool DMSG_HMI_TDSRJAMMINGDETECTSET_initialize(
    DMSG_HMI_TDSRJAMMINGDETECTSET* sample) {
  return DMSG_HMI_TDSRJAMMINGDETECTSET_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_HMI_TDSRJAMMINGDETECTSET_initialize_ex(
    DMSG_HMI_TDSRJAMMINGDETECTSET* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initChar(&sample->DetectMode)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_HMI_TDSRJAMMINGDETECTSET_finalize(
    DMSG_HMI_TDSRJAMMINGDETECTSET* sample)
{
    DMSG_HMI_TDSRJAMMINGDETECTSET_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_HMI_TDSRJAMMINGDETECTSET_finalize_ex(
    DMSG_HMI_TDSRJAMMINGDETECTSET* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_HMI_TDSRJAMMINGDETECTSET_copy(
    DMSG_HMI_TDSRJAMMINGDETECTSET* dst,
    const DMSG_HMI_TDSRJAMMINGDETECTSET* src)
{        

    if (!RTICdrType_copyChar(
        &dst->DetectMode, &src->DetectMode)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_HMI_TDSRJAMMINGDETECTSET' sequence class.
 */
#define T DMSG_HMI_TDSRJAMMINGDETECTSET
#define TSeq DMSG_HMI_TDSRJAMMINGDETECTSETSeq
#define T_initialize_ex DMSG_HMI_TDSRJAMMINGDETECTSET_initialize_ex
#define T_finalize_ex   DMSG_HMI_TDSRJAMMINGDETECTSET_finalize_ex
#define T_copy       DMSG_HMI_TDSRJAMMINGDETECTSET_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *DMSG_HMI_TDSRLOWSPEEDDETECTSETTYPENAME = "DMSG_HMI_TDSRLOWSPEEDDETECTSET";

DDS_TypeCode* DMSG_HMI_TDSRLOWSPEEDDETECTSET_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_HMI_TDSRLOWSPEEDDETECTSET_g_tc_members[1]=
    {
        {
            (char *)"LowDetectConfig",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode DMSG_HMI_TDSRLOWSPEEDDETECTSET_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_HMI_TDSRLOWSPEEDDETECTSET", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        1, /* Number of members */
        DMSG_HMI_TDSRLOWSPEEDDETECTSET_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_HMI_TDSRLOWSPEEDDETECTSET*/

    if (is_initialized) {
        return &DMSG_HMI_TDSRLOWSPEEDDETECTSET_g_tc;
    }


    DMSG_HMI_TDSRLOWSPEEDDETECTSET_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;

    is_initialized = RTI_TRUE;

    return &DMSG_HMI_TDSRLOWSPEEDDETECTSET_g_tc;
}


RTIBool DMSG_HMI_TDSRLOWSPEEDDETECTSET_initialize(
    DMSG_HMI_TDSRLOWSPEEDDETECTSET* sample) {
  return DMSG_HMI_TDSRLOWSPEEDDETECTSET_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_HMI_TDSRLOWSPEEDDETECTSET_initialize_ex(
    DMSG_HMI_TDSRLOWSPEEDDETECTSET* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initChar(&sample->LowDetectConfig)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_HMI_TDSRLOWSPEEDDETECTSET_finalize(
    DMSG_HMI_TDSRLOWSPEEDDETECTSET* sample)
{
    DMSG_HMI_TDSRLOWSPEEDDETECTSET_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_HMI_TDSRLOWSPEEDDETECTSET_finalize_ex(
    DMSG_HMI_TDSRLOWSPEEDDETECTSET* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_HMI_TDSRLOWSPEEDDETECTSET_copy(
    DMSG_HMI_TDSRLOWSPEEDDETECTSET* dst,
    const DMSG_HMI_TDSRLOWSPEEDDETECTSET* src)
{        

    if (!RTICdrType_copyChar(
        &dst->LowDetectConfig, &src->LowDetectConfig)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_HMI_TDSRLOWSPEEDDETECTSET' sequence class.
 */
#define T DMSG_HMI_TDSRLOWSPEEDDETECTSET
#define TSeq DMSG_HMI_TDSRLOWSPEEDDETECTSETSeq
#define T_initialize_ex DMSG_HMI_TDSRLOWSPEEDDETECTSET_initialize_ex
#define T_finalize_ex   DMSG_HMI_TDSRLOWSPEEDDETECTSET_finalize_ex
#define T_copy       DMSG_HMI_TDSRLOWSPEEDDETECTSET_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *DMSG_HMI_TDSRLOWALTDETECTSETTYPENAME = "DMSG_HMI_TDSRLOWALTDETECTSET";

DDS_TypeCode* DMSG_HMI_TDSRLOWALTDETECTSET_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_HMI_TDSRLOWALTDETECTSET_g_tc_members[1]=
    {
        {
            (char *)"LowAltitudeConfig",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode DMSG_HMI_TDSRLOWALTDETECTSET_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_HMI_TDSRLOWALTDETECTSET", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        1, /* Number of members */
        DMSG_HMI_TDSRLOWALTDETECTSET_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_HMI_TDSRLOWALTDETECTSET*/

    if (is_initialized) {
        return &DMSG_HMI_TDSRLOWALTDETECTSET_g_tc;
    }


    DMSG_HMI_TDSRLOWALTDETECTSET_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;

    is_initialized = RTI_TRUE;

    return &DMSG_HMI_TDSRLOWALTDETECTSET_g_tc;
}


RTIBool DMSG_HMI_TDSRLOWALTDETECTSET_initialize(
    DMSG_HMI_TDSRLOWALTDETECTSET* sample) {
  return DMSG_HMI_TDSRLOWALTDETECTSET_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_HMI_TDSRLOWALTDETECTSET_initialize_ex(
    DMSG_HMI_TDSRLOWALTDETECTSET* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initChar(&sample->LowAltitudeConfig)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_HMI_TDSRLOWALTDETECTSET_finalize(
    DMSG_HMI_TDSRLOWALTDETECTSET* sample)
{
    DMSG_HMI_TDSRLOWALTDETECTSET_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_HMI_TDSRLOWALTDETECTSET_finalize_ex(
    DMSG_HMI_TDSRLOWALTDETECTSET* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_HMI_TDSRLOWALTDETECTSET_copy(
    DMSG_HMI_TDSRLOWALTDETECTSET* dst,
    const DMSG_HMI_TDSRLOWALTDETECTSET* src)
{        

    if (!RTICdrType_copyChar(
        &dst->LowAltitudeConfig, &src->LowAltitudeConfig)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_HMI_TDSRLOWALTDETECTSET' sequence class.
 */
#define T DMSG_HMI_TDSRLOWALTDETECTSET
#define TSeq DMSG_HMI_TDSRLOWALTDETECTSETSeq
#define T_initialize_ex DMSG_HMI_TDSRLOWALTDETECTSET_initialize_ex
#define T_finalize_ex   DMSG_HMI_TDSRLOWALTDETECTSET_finalize_ex
#define T_copy       DMSG_HMI_TDSRLOWALTDETECTSET_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *DMSG_HMI_TDSRSIDELOBEBLOCKTYPENAME = "DMSG_HMI_TDSRSIDELOBEBLOCK";

DDS_TypeCode* DMSG_HMI_TDSRSIDELOBEBLOCK_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_HMI_TDSRSIDELOBEBLOCK_g_tc_members[1]=
    {
        {
            (char *)"SubLobeBlock",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode DMSG_HMI_TDSRSIDELOBEBLOCK_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_HMI_TDSRSIDELOBEBLOCK", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        1, /* Number of members */
        DMSG_HMI_TDSRSIDELOBEBLOCK_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_HMI_TDSRSIDELOBEBLOCK*/

    if (is_initialized) {
        return &DMSG_HMI_TDSRSIDELOBEBLOCK_g_tc;
    }


    DMSG_HMI_TDSRSIDELOBEBLOCK_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;

    is_initialized = RTI_TRUE;

    return &DMSG_HMI_TDSRSIDELOBEBLOCK_g_tc;
}


RTIBool DMSG_HMI_TDSRSIDELOBEBLOCK_initialize(
    DMSG_HMI_TDSRSIDELOBEBLOCK* sample) {
  return DMSG_HMI_TDSRSIDELOBEBLOCK_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_HMI_TDSRSIDELOBEBLOCK_initialize_ex(
    DMSG_HMI_TDSRSIDELOBEBLOCK* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initChar(&sample->SubLobeBlock)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_HMI_TDSRSIDELOBEBLOCK_finalize(
    DMSG_HMI_TDSRSIDELOBEBLOCK* sample)
{
    DMSG_HMI_TDSRSIDELOBEBLOCK_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_HMI_TDSRSIDELOBEBLOCK_finalize_ex(
    DMSG_HMI_TDSRSIDELOBEBLOCK* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_HMI_TDSRSIDELOBEBLOCK_copy(
    DMSG_HMI_TDSRSIDELOBEBLOCK* dst,
    const DMSG_HMI_TDSRSIDELOBEBLOCK* src)
{        

    if (!RTICdrType_copyChar(
        &dst->SubLobeBlock, &src->SubLobeBlock)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_HMI_TDSRSIDELOBEBLOCK' sequence class.
 */
#define T DMSG_HMI_TDSRSIDELOBEBLOCK
#define TSeq DMSG_HMI_TDSRSIDELOBEBLOCKSeq
#define T_initialize_ex DMSG_HMI_TDSRSIDELOBEBLOCK_initialize_ex
#define T_finalize_ex   DMSG_HMI_TDSRSIDELOBEBLOCK_finalize_ex
#define T_copy       DMSG_HMI_TDSRSIDELOBEBLOCK_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *DMSG_HMI_TDSREQUIPQUITSETTYPENAME = "DMSG_HMI_TDSREQUIPQUITSET";

DDS_TypeCode* DMSG_HMI_TDSREQUIPQUITSET_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_HMI_TDSREQUIPQUITSET_g_tc_members[1]=
    {
        {
            (char *)"EquitQuitConfig",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode DMSG_HMI_TDSREQUIPQUITSET_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_HMI_TDSREQUIPQUITSET", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        1, /* Number of members */
        DMSG_HMI_TDSREQUIPQUITSET_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_HMI_TDSREQUIPQUITSET*/

    if (is_initialized) {
        return &DMSG_HMI_TDSREQUIPQUITSET_g_tc;
    }


    DMSG_HMI_TDSREQUIPQUITSET_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;

    is_initialized = RTI_TRUE;

    return &DMSG_HMI_TDSREQUIPQUITSET_g_tc;
}


RTIBool DMSG_HMI_TDSREQUIPQUITSET_initialize(
    DMSG_HMI_TDSREQUIPQUITSET* sample) {
  return DMSG_HMI_TDSREQUIPQUITSET_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_HMI_TDSREQUIPQUITSET_initialize_ex(
    DMSG_HMI_TDSREQUIPQUITSET* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initChar(&sample->EquitQuitConfig)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_HMI_TDSREQUIPQUITSET_finalize(
    DMSG_HMI_TDSREQUIPQUITSET* sample)
{
    DMSG_HMI_TDSREQUIPQUITSET_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_HMI_TDSREQUIPQUITSET_finalize_ex(
    DMSG_HMI_TDSREQUIPQUITSET* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_HMI_TDSREQUIPQUITSET_copy(
    DMSG_HMI_TDSREQUIPQUITSET* dst,
    const DMSG_HMI_TDSREQUIPQUITSET* src)
{        

    if (!RTICdrType_copyChar(
        &dst->EquitQuitConfig, &src->EquitQuitConfig)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_HMI_TDSREQUIPQUITSET' sequence class.
 */
#define T DMSG_HMI_TDSREQUIPQUITSET
#define TSeq DMSG_HMI_TDSREQUIPQUITSETSeq
#define T_initialize_ex DMSG_HMI_TDSREQUIPQUITSET_initialize_ex
#define T_finalize_ex   DMSG_HMI_TDSREQUIPQUITSET_finalize_ex
#define T_copy       DMSG_HMI_TDSREQUIPQUITSET_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *DMSG_EC_TDSRTWSTARGETDESIGTYPENAME = "DMSG_EC_TDSRTWSTARGETDESIG";

DDS_TypeCode* DMSG_EC_TDSRTWSTARGETDESIG_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_EC_TDSRTWSTARGETDESIG_g_tc_members[6]=
    {
        {
            (char *)"byTrackingStatus",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"TrackingChannel",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"nTargetNumber",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"dPosX",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"dPosY",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"dPosZ",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode DMSG_EC_TDSRTWSTARGETDESIG_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_EC_TDSRTWSTARGETDESIG", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        6, /* Number of members */
        DMSG_EC_TDSRTWSTARGETDESIG_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_EC_TDSRTWSTARGETDESIG*/

    if (is_initialized) {
        return &DMSG_EC_TDSRTWSTARGETDESIG_g_tc;
    }


    DMSG_EC_TDSRTWSTARGETDESIG_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_EC_TDSRTWSTARGETDESIG_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_EC_TDSRTWSTARGETDESIG_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    DMSG_EC_TDSRTWSTARGETDESIG_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_EC_TDSRTWSTARGETDESIG_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_EC_TDSRTWSTARGETDESIG_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;

    is_initialized = RTI_TRUE;

    return &DMSG_EC_TDSRTWSTARGETDESIG_g_tc;
}


RTIBool DMSG_EC_TDSRTWSTARGETDESIG_initialize(
    DMSG_EC_TDSRTWSTARGETDESIG* sample) {
  return DMSG_EC_TDSRTWSTARGETDESIG_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_EC_TDSRTWSTARGETDESIG_initialize_ex(
    DMSG_EC_TDSRTWSTARGETDESIG* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initChar(&sample->byTrackingStatus)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->TrackingChannel)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initLong(&sample->nTargetNumber)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dPosX)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dPosY)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dPosZ)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_EC_TDSRTWSTARGETDESIG_finalize(
    DMSG_EC_TDSRTWSTARGETDESIG* sample)
{
    DMSG_EC_TDSRTWSTARGETDESIG_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_EC_TDSRTWSTARGETDESIG_finalize_ex(
    DMSG_EC_TDSRTWSTARGETDESIG* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_EC_TDSRTWSTARGETDESIG_copy(
    DMSG_EC_TDSRTWSTARGETDESIG* dst,
    const DMSG_EC_TDSRTWSTARGETDESIG* src)
{        

    if (!RTICdrType_copyChar(
        &dst->byTrackingStatus, &src->byTrackingStatus)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->TrackingChannel, &src->TrackingChannel)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyLong(
        &dst->nTargetNumber, &src->nTargetNumber)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dPosX, &src->dPosX)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dPosY, &src->dPosY)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dPosZ, &src->dPosZ)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_EC_TDSRTWSTARGETDESIG' sequence class.
 */
#define T DMSG_EC_TDSRTWSTARGETDESIG
#define TSeq DMSG_EC_TDSRTWSTARGETDESIGSeq
#define T_initialize_ex DMSG_EC_TDSRTWSTARGETDESIG_initialize_ex
#define T_finalize_ex   DMSG_EC_TDSRTWSTARGETDESIG_finalize_ex
#define T_copy       DMSG_EC_TDSRTWSTARGETDESIG_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

