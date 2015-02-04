
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from rmOPV_Protocol.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Connext distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Connext manual.
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



#include "rmOPV_Protocol.h"

/* ========================================================================= */
const char *ST_POSITIONTYPENAME = "ST_POSITION";

DDS_TypeCode* ST_POSITION_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member ST_POSITION_g_tc_members[3]=
    {
        {
            (char *)"dLon",/* Member name */
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
            (char *)"dLat",/* Member name */
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
            (char *)"dAlt",/* Member name */
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

    static DDS_TypeCode ST_POSITION_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"ST_POSITION", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        3, /* Number of members */
        ST_POSITION_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for ST_POSITION*/

    if (is_initialized) {
        return &ST_POSITION_g_tc;
    }


    ST_POSITION_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    ST_POSITION_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    ST_POSITION_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;

    is_initialized = RTI_TRUE;

    return &ST_POSITION_g_tc;
}


RTIBool ST_POSITION_initialize(
    ST_POSITION* sample) {
  return ST_POSITION_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}
        
RTIBool ST_POSITION_initialize_ex(
    ST_POSITION* sample,RTIBool allocatePointers,RTIBool allocateMemory)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */
    if (allocateMemory) {} /* To avoid warnings */

    if (!RTICdrType_initDouble(&sample->dLon)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initDouble(&sample->dLat)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initDouble(&sample->dAlt)) {
        return RTI_FALSE;
    }                
            


    return RTI_TRUE;
}

void ST_POSITION_finalize(
    ST_POSITION* sample)
{
    ST_POSITION_finalize_ex(sample,RTI_TRUE);
}
        
void ST_POSITION_finalize_ex(
    ST_POSITION* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */





}

RTIBool ST_POSITION_copy(
    ST_POSITION* dst,
    const ST_POSITION* src)
{        

    if (!RTICdrType_copyDouble(
        &dst->dLon, &src->dLon)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyDouble(
        &dst->dLat, &src->dLat)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyDouble(
        &dst->dAlt, &src->dAlt)) {
        return RTI_FALSE;
    }
            


    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'ST_POSITION' sequence class.
 */
#define T ST_POSITION
#define TSeq ST_POSITIONSeq
#define T_initialize_ex ST_POSITION_initialize_ex
#define T_finalize_ex   ST_POSITION_finalize_ex
#define T_copy       ST_POSITION_copy

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
const char *ST_ENTITY_STATETYPENAME = "ST_ENTITY_STATE";

DDS_TypeCode* ST_ENTITY_STATE_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member ST_ENTITY_STATE_g_tc_members[10]=
    {
        {
            (char *)"stPosition",/* Member name */
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
            (char *)"dSpeed",/* Member name */
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
            (char *)"dCourse",/* Member name */
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
            (char *)"dHeading",/* Member name */
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
            (char *)"dRoll",/* Member name */
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
            (char *)"dPitch",/* Member name */
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
            (char *)"dHealthPoint",/* Member name */
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
            (char *)"bDestroyed",/* Member name */
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
            (char *)"Reserved_1",/* Member name */
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
            (char *)"Reserved_2",/* Member name */
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

    static DDS_TypeCode ST_ENTITY_STATE_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"ST_ENTITY_STATE", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        10, /* Number of members */
        ST_ENTITY_STATE_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for ST_ENTITY_STATE*/

    if (is_initialized) {
        return &ST_ENTITY_STATE_g_tc;
    }


    ST_ENTITY_STATE_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)ST_POSITION_get_typecode();
    ST_ENTITY_STATE_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    ST_ENTITY_STATE_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    ST_ENTITY_STATE_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    ST_ENTITY_STATE_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    ST_ENTITY_STATE_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    ST_ENTITY_STATE_g_tc_members[6]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    ST_ENTITY_STATE_g_tc_members[7]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;
    ST_ENTITY_STATE_g_tc_members[8]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;
    ST_ENTITY_STATE_g_tc_members[9]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;

    is_initialized = RTI_TRUE;

    return &ST_ENTITY_STATE_g_tc;
}


RTIBool ST_ENTITY_STATE_initialize(
    ST_ENTITY_STATE* sample) {
  return ST_ENTITY_STATE_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}
        
RTIBool ST_ENTITY_STATE_initialize_ex(
    ST_ENTITY_STATE* sample,RTIBool allocatePointers,RTIBool allocateMemory)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */
    if (allocateMemory) {} /* To avoid warnings */

    if (!ST_POSITION_initialize_ex(&sample->stPosition,allocatePointers,allocateMemory)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_initDouble(&sample->dSpeed)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initDouble(&sample->dCourse)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initDouble(&sample->dHeading)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initDouble(&sample->dRoll)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initDouble(&sample->dPitch)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initDouble(&sample->dHealthPoint)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initShort(&sample->bDestroyed)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initShort(&sample->Reserved_1)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initShort(&sample->Reserved_2)) {
        return RTI_FALSE;
    }                
            


    return RTI_TRUE;
}

void ST_ENTITY_STATE_finalize(
    ST_ENTITY_STATE* sample)
{
    ST_ENTITY_STATE_finalize_ex(sample,RTI_TRUE);
}
        
void ST_ENTITY_STATE_finalize_ex(
    ST_ENTITY_STATE* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


    ST_POSITION_finalize_ex(&sample->stPosition,deletePointers);
            










}

RTIBool ST_ENTITY_STATE_copy(
    ST_ENTITY_STATE* dst,
    const ST_ENTITY_STATE* src)
{        

    if (!ST_POSITION_copy(
        &dst->stPosition, &src->stPosition)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyDouble(
        &dst->dSpeed, &src->dSpeed)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyDouble(
        &dst->dCourse, &src->dCourse)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyDouble(
        &dst->dHeading, &src->dHeading)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyDouble(
        &dst->dRoll, &src->dRoll)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyDouble(
        &dst->dPitch, &src->dPitch)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyDouble(
        &dst->dHealthPoint, &src->dHealthPoint)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyShort(
        &dst->bDestroyed, &src->bDestroyed)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyShort(
        &dst->Reserved_1, &src->Reserved_1)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyShort(
        &dst->Reserved_2, &src->Reserved_2)) {
        return RTI_FALSE;
    }
            


    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'ST_ENTITY_STATE' sequence class.
 */
#define T ST_ENTITY_STATE
#define TSeq ST_ENTITY_STATESeq
#define T_initialize_ex ST_ENTITY_STATE_initialize_ex
#define T_finalize_ex   ST_ENTITY_STATE_finalize_ex
#define T_copy       ST_ENTITY_STATE_copy

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
const char *ST_ENTITY_INFOTYPENAME = "ST_ENTITY_INFO";

DDS_TypeCode* ST_ENTITY_INFO_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode ST_ENTITY_INFO_g_tc_chESM_Name_array = DDS_INITIALIZE_ARRAY_TYPECODE(1,5,NULL,NULL);
    static DDS_TypeCode ST_ENTITY_INFO_g_tc_chWeaponRadarInfo_array = DDS_INITIALIZE_ARRAY_TYPECODE(1,5,NULL,NULL);
    static DDS_TypeCode ST_ENTITY_INFO_g_tc_chSensorInfo_array = DDS_INITIALIZE_ARRAY_TYPECODE(1,5,NULL,NULL);

    static DDS_TypeCode_Member ST_ENTITY_INFO_g_tc_members[22]=
    {
        {
            (char *)"ulType",/* Member name */
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
            (char *)"chESM_Name",/* Member name */
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
            (char *)"ulPlatformClass",/* Member name */
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
            (char *)"ulPlatformKind",/* Member name */
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
            (char *)"ulPlatformMission",/* Member name */
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
            (char *)"ulIdentity",/* Member name */
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
            (char *)"nMode1",/* Member name */
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
            (char *)"nMode2",/* Member name */
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
            (char *)"nMode3A",/* Member name */
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
            (char *)"nMode4",/* Member name */
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
            (char *)"nWeaponClass",/* Member name */
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
            (char *)"chWeaponRadarInfo",/* Member name */
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
            (char *)"dWeaponRange",/* Member name */
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
            (char *)"dWeaponSpeed",/* Member name */
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
            (char *)"nWeaponOperationType",/* Member name */
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
            (char *)"nSensorClass",/* Member name */
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
            (char *)"nSensorThreatLevel",/* Member name */
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
            (char *)"chSensorInfo",/* Member name */
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
            (char *)"dSensorFreqency",/* Member name */
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
            (char *)"dSensorScanRate",/* Member name */
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
            (char *)"dSensorScanType",/* Member name */
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
            (char *)"dSensorAmplitude",/* Member name */
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

    static DDS_TypeCode ST_ENTITY_INFO_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"ST_ENTITY_INFO", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        22, /* Number of members */
        ST_ENTITY_INFO_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for ST_ENTITY_INFO*/

    if (is_initialized) {
        return &ST_ENTITY_INFO_g_tc;
    }

    ST_ENTITY_INFO_g_tc_chESM_Name_array._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    ST_ENTITY_INFO_g_tc_chWeaponRadarInfo_array._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    ST_ENTITY_INFO_g_tc_chSensorInfo_array._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;

    ST_ENTITY_INFO_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;
    ST_ENTITY_INFO_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&ST_ENTITY_INFO_g_tc_chESM_Name_array;
    ST_ENTITY_INFO_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;
    ST_ENTITY_INFO_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;
    ST_ENTITY_INFO_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;
    ST_ENTITY_INFO_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;
    ST_ENTITY_INFO_g_tc_members[6]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;
    ST_ENTITY_INFO_g_tc_members[7]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;
    ST_ENTITY_INFO_g_tc_members[8]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;
    ST_ENTITY_INFO_g_tc_members[9]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;
    ST_ENTITY_INFO_g_tc_members[10]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;
    ST_ENTITY_INFO_g_tc_members[11]._representation._typeCode = (RTICdrTypeCode *)&ST_ENTITY_INFO_g_tc_chWeaponRadarInfo_array;
    ST_ENTITY_INFO_g_tc_members[12]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    ST_ENTITY_INFO_g_tc_members[13]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    ST_ENTITY_INFO_g_tc_members[14]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;
    ST_ENTITY_INFO_g_tc_members[15]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;
    ST_ENTITY_INFO_g_tc_members[16]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;
    ST_ENTITY_INFO_g_tc_members[17]._representation._typeCode = (RTICdrTypeCode *)&ST_ENTITY_INFO_g_tc_chSensorInfo_array;
    ST_ENTITY_INFO_g_tc_members[18]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    ST_ENTITY_INFO_g_tc_members[19]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    ST_ENTITY_INFO_g_tc_members[20]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    ST_ENTITY_INFO_g_tc_members[21]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;

    is_initialized = RTI_TRUE;

    return &ST_ENTITY_INFO_g_tc;
}


RTIBool ST_ENTITY_INFO_initialize(
    ST_ENTITY_INFO* sample) {
  return ST_ENTITY_INFO_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}
        
RTIBool ST_ENTITY_INFO_initialize_ex(
    ST_ENTITY_INFO* sample,RTIBool allocatePointers,RTIBool allocateMemory)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */
    if (allocateMemory) {} /* To avoid warnings */

    if (!RTICdrType_initUnsignedLong(&sample->ulType)) {
        return RTI_FALSE;
    }                
            
    
    if (!RTICdrType_initArray(
        sample->chESM_Name, (5), RTI_CDR_CHAR_SIZE)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_initUnsignedLong(&sample->ulPlatformClass)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initUnsignedLong(&sample->ulPlatformKind)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initUnsignedLong(&sample->ulPlatformMission)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initUnsignedLong(&sample->ulIdentity)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initShort(&sample->nMode1)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initShort(&sample->nMode2)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initShort(&sample->nMode3A)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initShort(&sample->nMode4)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initShort(&sample->nWeaponClass)) {
        return RTI_FALSE;
    }                
            
    
    if (!RTICdrType_initArray(
        sample->chWeaponRadarInfo, (5), RTI_CDR_CHAR_SIZE)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_initDouble(&sample->dWeaponRange)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initDouble(&sample->dWeaponSpeed)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initShort(&sample->nWeaponOperationType)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initShort(&sample->nSensorClass)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initShort(&sample->nSensorThreatLevel)) {
        return RTI_FALSE;
    }                
            
    
    if (!RTICdrType_initArray(
        sample->chSensorInfo, (5), RTI_CDR_CHAR_SIZE)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_initDouble(&sample->dSensorFreqency)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initDouble(&sample->dSensorScanRate)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initDouble(&sample->dSensorScanType)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initDouble(&sample->dSensorAmplitude)) {
        return RTI_FALSE;
    }                
            


    return RTI_TRUE;
}

void ST_ENTITY_INFO_finalize(
    ST_ENTITY_INFO* sample)
{
    ST_ENTITY_INFO_finalize_ex(sample,RTI_TRUE);
}
        
void ST_ENTITY_INFO_finalize_ex(
    ST_ENTITY_INFO* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */
























}

RTIBool ST_ENTITY_INFO_copy(
    ST_ENTITY_INFO* dst,
    const ST_ENTITY_INFO* src)
{        

    if (!RTICdrType_copyUnsignedLong(
        &dst->ulType, &src->ulType)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyArray(
        dst->chESM_Name, src->chESM_Name, (5), RTI_CDR_CHAR_SIZE)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyUnsignedLong(
        &dst->ulPlatformClass, &src->ulPlatformClass)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyUnsignedLong(
        &dst->ulPlatformKind, &src->ulPlatformKind)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyUnsignedLong(
        &dst->ulPlatformMission, &src->ulPlatformMission)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyUnsignedLong(
        &dst->ulIdentity, &src->ulIdentity)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyShort(
        &dst->nMode1, &src->nMode1)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyShort(
        &dst->nMode2, &src->nMode2)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyShort(
        &dst->nMode3A, &src->nMode3A)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyShort(
        &dst->nMode4, &src->nMode4)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyShort(
        &dst->nWeaponClass, &src->nWeaponClass)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyArray(
        dst->chWeaponRadarInfo, src->chWeaponRadarInfo, (5), RTI_CDR_CHAR_SIZE)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyDouble(
        &dst->dWeaponRange, &src->dWeaponRange)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyDouble(
        &dst->dWeaponSpeed, &src->dWeaponSpeed)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyShort(
        &dst->nWeaponOperationType, &src->nWeaponOperationType)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyShort(
        &dst->nSensorClass, &src->nSensorClass)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyShort(
        &dst->nSensorThreatLevel, &src->nSensorThreatLevel)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyArray(
        dst->chSensorInfo, src->chSensorInfo, (5), RTI_CDR_CHAR_SIZE)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyDouble(
        &dst->dSensorFreqency, &src->dSensorFreqency)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyDouble(
        &dst->dSensorScanRate, &src->dSensorScanRate)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyDouble(
        &dst->dSensorScanType, &src->dSensorScanType)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyDouble(
        &dst->dSensorAmplitude, &src->dSensorAmplitude)) {
        return RTI_FALSE;
    }
            


    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'ST_ENTITY_INFO' sequence class.
 */
#define T ST_ENTITY_INFO
#define TSeq ST_ENTITY_INFOSeq
#define T_initialize_ex ST_ENTITY_INFO_initialize_ex
#define T_finalize_ex   ST_ENTITY_INFO_finalize_ex
#define T_copy       ST_ENTITY_INFO_copy

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
const char *ST_ENTITY_ATTRIBUTETYPENAME = "ST_ENTITY_ATTRIBUTE";

DDS_TypeCode* ST_ENTITY_ATTRIBUTE_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member ST_ENTITY_ATTRIBUTE_g_tc_members[11]=
    {
        {
            (char *)"dTurnRate",/* Member name */
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
            (char *)"dRiseRate",/* Member name */
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
            (char *)"dMaxAltitude",/* Member name */
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
            (char *)"dMaxSpeed",/* Member name */
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
            (char *)"dMaxAcceleration",/* Member name */
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
            (char *)"dMaxHealthPoint",/* Member name */
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
            (char *)"dLength",/* Member name */
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
            (char *)"dWidth",/* Member name */
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
            (char *)"dHeight",/* Member name */
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
            (char *)"dWeight",/* Member name */
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
            (char *)"Reserved",/* Member name */
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

    static DDS_TypeCode ST_ENTITY_ATTRIBUTE_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"ST_ENTITY_ATTRIBUTE", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        11, /* Number of members */
        ST_ENTITY_ATTRIBUTE_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for ST_ENTITY_ATTRIBUTE*/

    if (is_initialized) {
        return &ST_ENTITY_ATTRIBUTE_g_tc;
    }


    ST_ENTITY_ATTRIBUTE_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    ST_ENTITY_ATTRIBUTE_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    ST_ENTITY_ATTRIBUTE_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    ST_ENTITY_ATTRIBUTE_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    ST_ENTITY_ATTRIBUTE_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    ST_ENTITY_ATTRIBUTE_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    ST_ENTITY_ATTRIBUTE_g_tc_members[6]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    ST_ENTITY_ATTRIBUTE_g_tc_members[7]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    ST_ENTITY_ATTRIBUTE_g_tc_members[8]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    ST_ENTITY_ATTRIBUTE_g_tc_members[9]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    ST_ENTITY_ATTRIBUTE_g_tc_members[10]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;

    is_initialized = RTI_TRUE;

    return &ST_ENTITY_ATTRIBUTE_g_tc;
}


RTIBool ST_ENTITY_ATTRIBUTE_initialize(
    ST_ENTITY_ATTRIBUTE* sample) {
  return ST_ENTITY_ATTRIBUTE_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}
        
RTIBool ST_ENTITY_ATTRIBUTE_initialize_ex(
    ST_ENTITY_ATTRIBUTE* sample,RTIBool allocatePointers,RTIBool allocateMemory)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */
    if (allocateMemory) {} /* To avoid warnings */

    if (!RTICdrType_initDouble(&sample->dTurnRate)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initDouble(&sample->dRiseRate)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initDouble(&sample->dMaxAltitude)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initDouble(&sample->dMaxSpeed)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initDouble(&sample->dMaxAcceleration)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initDouble(&sample->dMaxHealthPoint)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initDouble(&sample->dLength)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initDouble(&sample->dWidth)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initDouble(&sample->dHeight)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initDouble(&sample->dWeight)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initShort(&sample->Reserved)) {
        return RTI_FALSE;
    }                
            


    return RTI_TRUE;
}

void ST_ENTITY_ATTRIBUTE_finalize(
    ST_ENTITY_ATTRIBUTE* sample)
{
    ST_ENTITY_ATTRIBUTE_finalize_ex(sample,RTI_TRUE);
}
        
void ST_ENTITY_ATTRIBUTE_finalize_ex(
    ST_ENTITY_ATTRIBUTE* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */













}

RTIBool ST_ENTITY_ATTRIBUTE_copy(
    ST_ENTITY_ATTRIBUTE* dst,
    const ST_ENTITY_ATTRIBUTE* src)
{        

    if (!RTICdrType_copyDouble(
        &dst->dTurnRate, &src->dTurnRate)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyDouble(
        &dst->dRiseRate, &src->dRiseRate)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyDouble(
        &dst->dMaxAltitude, &src->dMaxAltitude)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyDouble(
        &dst->dMaxSpeed, &src->dMaxSpeed)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyDouble(
        &dst->dMaxAcceleration, &src->dMaxAcceleration)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyDouble(
        &dst->dMaxHealthPoint, &src->dMaxHealthPoint)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyDouble(
        &dst->dLength, &src->dLength)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyDouble(
        &dst->dWidth, &src->dWidth)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyDouble(
        &dst->dHeight, &src->dHeight)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyDouble(
        &dst->dWeight, &src->dWeight)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyShort(
        &dst->Reserved, &src->Reserved)) {
        return RTI_FALSE;
    }
            


    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'ST_ENTITY_ATTRIBUTE' sequence class.
 */
#define T ST_ENTITY_ATTRIBUTE
#define TSeq ST_ENTITY_ATTRIBUTESeq
#define T_initialize_ex ST_ENTITY_ATTRIBUTE_initialize_ex
#define T_finalize_ex   ST_ENTITY_ATTRIBUTE_finalize_ex
#define T_copy       ST_ENTITY_ATTRIBUTE_copy

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
const char *ST_MISSILE_DATATYPENAME = "ST_MISSILE_DATA";

DDS_TypeCode* ST_MISSILE_DATA_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member ST_MISSILE_DATA_g_tc_members[8]=
    {
        {
            (char *)"nMissileType",/* Member name */
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
            (char *)"nMissileCategory",/* Member name */
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
            (char *)"dWeight",/* Member name */
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
            (char *)"dDamage",/* Member name */
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
            (char *)"dSpeed",/* Member name */
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
            (char *)"dTurnRate",/* Member name */
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
            (char *)"dSeekerAngle",/* Member name */
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
            (char *)"dSeekerRange",/* Member name */
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

    static DDS_TypeCode ST_MISSILE_DATA_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"ST_MISSILE_DATA", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        8, /* Number of members */
        ST_MISSILE_DATA_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for ST_MISSILE_DATA*/

    if (is_initialized) {
        return &ST_MISSILE_DATA_g_tc;
    }


    ST_MISSILE_DATA_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    ST_MISSILE_DATA_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    ST_MISSILE_DATA_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    ST_MISSILE_DATA_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    ST_MISSILE_DATA_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    ST_MISSILE_DATA_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    ST_MISSILE_DATA_g_tc_members[6]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    ST_MISSILE_DATA_g_tc_members[7]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;

    is_initialized = RTI_TRUE;

    return &ST_MISSILE_DATA_g_tc;
}


RTIBool ST_MISSILE_DATA_initialize(
    ST_MISSILE_DATA* sample) {
  return ST_MISSILE_DATA_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}
        
RTIBool ST_MISSILE_DATA_initialize_ex(
    ST_MISSILE_DATA* sample,RTIBool allocatePointers,RTIBool allocateMemory)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */
    if (allocateMemory) {} /* To avoid warnings */

    if (!RTICdrType_initDouble(&sample->nMissileType)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initDouble(&sample->nMissileCategory)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initDouble(&sample->dWeight)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initDouble(&sample->dDamage)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initDouble(&sample->dSpeed)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initDouble(&sample->dTurnRate)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initDouble(&sample->dSeekerAngle)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initDouble(&sample->dSeekerRange)) {
        return RTI_FALSE;
    }                
            


    return RTI_TRUE;
}

void ST_MISSILE_DATA_finalize(
    ST_MISSILE_DATA* sample)
{
    ST_MISSILE_DATA_finalize_ex(sample,RTI_TRUE);
}
        
void ST_MISSILE_DATA_finalize_ex(
    ST_MISSILE_DATA* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */










}

RTIBool ST_MISSILE_DATA_copy(
    ST_MISSILE_DATA* dst,
    const ST_MISSILE_DATA* src)
{        

    if (!RTICdrType_copyDouble(
        &dst->nMissileType, &src->nMissileType)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyDouble(
        &dst->nMissileCategory, &src->nMissileCategory)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyDouble(
        &dst->dWeight, &src->dWeight)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyDouble(
        &dst->dDamage, &src->dDamage)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyDouble(
        &dst->dSpeed, &src->dSpeed)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyDouble(
        &dst->dTurnRate, &src->dTurnRate)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyDouble(
        &dst->dSeekerAngle, &src->dSeekerAngle)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyDouble(
        &dst->dSeekerRange, &src->dSeekerRange)) {
        return RTI_FALSE;
    }
            


    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'ST_MISSILE_DATA' sequence class.
 */
#define T ST_MISSILE_DATA
#define TSeq ST_MISSILE_DATASeq
#define T_initialize_ex ST_MISSILE_DATA_initialize_ex
#define T_finalize_ex   ST_MISSILE_DATA_finalize_ex
#define T_copy       ST_MISSILE_DATA_copy

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
const char *ST_AMMUNITION_DATATYPENAME = "ST_AMMUNITION_DATA";

DDS_TypeCode* ST_AMMUNITION_DATA_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member ST_AMMUNITION_DATA_g_tc_members[5]=
    {
        {
            (char *)"nAmmunitionType",/* Member name */
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
            (char *)"nAmmunitionCategory",/* Member name */
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
            (char *)"dWeight",/* Member name */
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
            (char *)"dMuzzleVelocity",/* Member name */
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
            (char *)"nSimulatorManagementCommand",/* Member name */
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

    static DDS_TypeCode ST_AMMUNITION_DATA_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"ST_AMMUNITION_DATA", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        5, /* Number of members */
        ST_AMMUNITION_DATA_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for ST_AMMUNITION_DATA*/

    if (is_initialized) {
        return &ST_AMMUNITION_DATA_g_tc;
    }


    ST_AMMUNITION_DATA_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;
    ST_AMMUNITION_DATA_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;
    ST_AMMUNITION_DATA_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    ST_AMMUNITION_DATA_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    ST_AMMUNITION_DATA_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;

    is_initialized = RTI_TRUE;

    return &ST_AMMUNITION_DATA_g_tc;
}


RTIBool ST_AMMUNITION_DATA_initialize(
    ST_AMMUNITION_DATA* sample) {
  return ST_AMMUNITION_DATA_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}
        
RTIBool ST_AMMUNITION_DATA_initialize_ex(
    ST_AMMUNITION_DATA* sample,RTIBool allocatePointers,RTIBool allocateMemory)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */
    if (allocateMemory) {} /* To avoid warnings */

    if (!RTICdrType_initShort(&sample->nAmmunitionType)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initShort(&sample->nAmmunitionCategory)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initDouble(&sample->dWeight)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initDouble(&sample->dMuzzleVelocity)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initShort(&sample->nSimulatorManagementCommand)) {
        return RTI_FALSE;
    }                
            


    return RTI_TRUE;
}

void ST_AMMUNITION_DATA_finalize(
    ST_AMMUNITION_DATA* sample)
{
    ST_AMMUNITION_DATA_finalize_ex(sample,RTI_TRUE);
}
        
void ST_AMMUNITION_DATA_finalize_ex(
    ST_AMMUNITION_DATA* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */







}

RTIBool ST_AMMUNITION_DATA_copy(
    ST_AMMUNITION_DATA* dst,
    const ST_AMMUNITION_DATA* src)
{        

    if (!RTICdrType_copyShort(
        &dst->nAmmunitionType, &src->nAmmunitionType)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyShort(
        &dst->nAmmunitionCategory, &src->nAmmunitionCategory)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyDouble(
        &dst->dWeight, &src->dWeight)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyDouble(
        &dst->dMuzzleVelocity, &src->dMuzzleVelocity)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyShort(
        &dst->nSimulatorManagementCommand, &src->nSimulatorManagementCommand)) {
        return RTI_FALSE;
    }
            


    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'ST_AMMUNITION_DATA' sequence class.
 */
#define T ST_AMMUNITION_DATA
#define TSeq ST_AMMUNITION_DATASeq
#define T_initialize_ex ST_AMMUNITION_DATA_initialize_ex
#define T_finalize_ex   ST_AMMUNITION_DATA_finalize_ex
#define T_copy       ST_AMMUNITION_DATA_copy

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
const char *SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKTYPENAME = "SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK";

DDS_TypeCode* SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK_g_tc_members[2]=
    {
        {
            (char *)"nSimulatorID",/* Member name */
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
            (char *)"nSimulatorManagementCommand",/* Member name */
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

    static DDS_TypeCode SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        2, /* Number of members */
        SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK*/

    if (is_initialized) {
        return &SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK_g_tc;
    }


    SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;
    SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;

    is_initialized = RTI_TRUE;

    return &SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK_g_tc;
}


RTIBool SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK_initialize(
    SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK* sample) {
  return SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}
        
RTIBool SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK_initialize_ex(
    SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK* sample,RTIBool allocatePointers,RTIBool allocateMemory)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */
    if (allocateMemory) {} /* To avoid warnings */

    if (!RTICdrType_initShort(&sample->nSimulatorID)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initShort(&sample->nSimulatorManagementCommand)) {
        return RTI_FALSE;
    }                
            


    return RTI_TRUE;
}

void SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK_finalize(
    SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK* sample)
{
    SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK_finalize_ex(sample,RTI_TRUE);
}
        
void SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK_finalize_ex(
    SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */




}

RTIBool SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK_copy(
    SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK* dst,
    const SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK* src)
{        

    if (!RTICdrType_copyShort(
        &dst->nSimulatorID, &src->nSimulatorID)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyShort(
        &dst->nSimulatorManagementCommand, &src->nSimulatorManagementCommand)) {
        return RTI_FALSE;
    }
            


    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK' sequence class.
 */
#define T SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK
#define TSeq SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACKSeq
#define T_initialize_ex SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK_initialize_ex
#define T_finalize_ex   SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK_finalize_ex
#define T_copy       SER_SC_SIMULATOR_MANAGEMENT_COMMAND_ACK_copy

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
const char *SIM_SC_SIMULATOR_STATUS_REPORTTYPENAME = "SIM_SC_SIMULATOR_STATUS_REPORT";

DDS_TypeCode* SIM_SC_SIMULATOR_STATUS_REPORT_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member SIM_SC_SIMULATOR_STATUS_REPORT_g_tc_members[2]=
    {
        {
            (char *)"nSimulatorID",/* Member name */
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
            (char *)"nSimulatorStatus",/* Member name */
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

    static DDS_TypeCode SIM_SC_SIMULATOR_STATUS_REPORT_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"SIM_SC_SIMULATOR_STATUS_REPORT", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        2, /* Number of members */
        SIM_SC_SIMULATOR_STATUS_REPORT_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for SIM_SC_SIMULATOR_STATUS_REPORT*/

    if (is_initialized) {
        return &SIM_SC_SIMULATOR_STATUS_REPORT_g_tc;
    }


    SIM_SC_SIMULATOR_STATUS_REPORT_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;
    SIM_SC_SIMULATOR_STATUS_REPORT_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;

    is_initialized = RTI_TRUE;

    return &SIM_SC_SIMULATOR_STATUS_REPORT_g_tc;
}


RTIBool SIM_SC_SIMULATOR_STATUS_REPORT_initialize(
    SIM_SC_SIMULATOR_STATUS_REPORT* sample) {
  return SIM_SC_SIMULATOR_STATUS_REPORT_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}
        
RTIBool SIM_SC_SIMULATOR_STATUS_REPORT_initialize_ex(
    SIM_SC_SIMULATOR_STATUS_REPORT* sample,RTIBool allocatePointers,RTIBool allocateMemory)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */
    if (allocateMemory) {} /* To avoid warnings */

    if (!RTICdrType_initShort(&sample->nSimulatorID)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initShort(&sample->nSimulatorStatus)) {
        return RTI_FALSE;
    }                
            


    return RTI_TRUE;
}

void SIM_SC_SIMULATOR_STATUS_REPORT_finalize(
    SIM_SC_SIMULATOR_STATUS_REPORT* sample)
{
    SIM_SC_SIMULATOR_STATUS_REPORT_finalize_ex(sample,RTI_TRUE);
}
        
void SIM_SC_SIMULATOR_STATUS_REPORT_finalize_ex(
    SIM_SC_SIMULATOR_STATUS_REPORT* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */




}

RTIBool SIM_SC_SIMULATOR_STATUS_REPORT_copy(
    SIM_SC_SIMULATOR_STATUS_REPORT* dst,
    const SIM_SC_SIMULATOR_STATUS_REPORT* src)
{        

    if (!RTICdrType_copyShort(
        &dst->nSimulatorID, &src->nSimulatorID)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyShort(
        &dst->nSimulatorStatus, &src->nSimulatorStatus)) {
        return RTI_FALSE;
    }
            


    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'SIM_SC_SIMULATOR_STATUS_REPORT' sequence class.
 */
#define T SIM_SC_SIMULATOR_STATUS_REPORT
#define TSeq SIM_SC_SIMULATOR_STATUS_REPORTSeq
#define T_initialize_ex SIM_SC_SIMULATOR_STATUS_REPORT_initialize_ex
#define T_finalize_ex   SIM_SC_SIMULATOR_STATUS_REPORT_finalize_ex
#define T_copy       SIM_SC_SIMULATOR_STATUS_REPORT_copy

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
const char *SC_SER_LINK_CONNECTION_COMMANDTYPENAME = "SC_SER_LINK_CONNECTION_COMMAND";

DDS_TypeCode* SC_SER_LINK_CONNECTION_COMMAND_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member SC_SER_LINK_CONNECTION_COMMAND_g_tc_members[1]=
    {
        {
            (char *)"nLinkConnectionCommand",/* Member name */
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

    static DDS_TypeCode SC_SER_LINK_CONNECTION_COMMAND_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"SC_SER_LINK_CONNECTION_COMMAND", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        1, /* Number of members */
        SC_SER_LINK_CONNECTION_COMMAND_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for SC_SER_LINK_CONNECTION_COMMAND*/

    if (is_initialized) {
        return &SC_SER_LINK_CONNECTION_COMMAND_g_tc;
    }


    SC_SER_LINK_CONNECTION_COMMAND_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;

    is_initialized = RTI_TRUE;

    return &SC_SER_LINK_CONNECTION_COMMAND_g_tc;
}


RTIBool SC_SER_LINK_CONNECTION_COMMAND_initialize(
    SC_SER_LINK_CONNECTION_COMMAND* sample) {
  return SC_SER_LINK_CONNECTION_COMMAND_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}
        
RTIBool SC_SER_LINK_CONNECTION_COMMAND_initialize_ex(
    SC_SER_LINK_CONNECTION_COMMAND* sample,RTIBool allocatePointers,RTIBool allocateMemory)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */
    if (allocateMemory) {} /* To avoid warnings */

    if (!RTICdrType_initShort(&sample->nLinkConnectionCommand)) {
        return RTI_FALSE;
    }                
            


    return RTI_TRUE;
}

void SC_SER_LINK_CONNECTION_COMMAND_finalize(
    SC_SER_LINK_CONNECTION_COMMAND* sample)
{
    SC_SER_LINK_CONNECTION_COMMAND_finalize_ex(sample,RTI_TRUE);
}
        
void SC_SER_LINK_CONNECTION_COMMAND_finalize_ex(
    SC_SER_LINK_CONNECTION_COMMAND* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */



}

RTIBool SC_SER_LINK_CONNECTION_COMMAND_copy(
    SC_SER_LINK_CONNECTION_COMMAND* dst,
    const SC_SER_LINK_CONNECTION_COMMAND* src)
{        

    if (!RTICdrType_copyShort(
        &dst->nLinkConnectionCommand, &src->nLinkConnectionCommand)) {
        return RTI_FALSE;
    }
            


    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'SC_SER_LINK_CONNECTION_COMMAND' sequence class.
 */
#define T SC_SER_LINK_CONNECTION_COMMAND
#define TSeq SC_SER_LINK_CONNECTION_COMMANDSeq
#define T_initialize_ex SC_SER_LINK_CONNECTION_COMMAND_initialize_ex
#define T_finalize_ex   SC_SER_LINK_CONNECTION_COMMAND_finalize_ex
#define T_copy       SC_SER_LINK_CONNECTION_COMMAND_copy

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
const char *SER_SC_LINK_CONNECTION_COMMAND_ACKTYPENAME = "SER_SC_LINK_CONNECTION_COMMAND_ACK";

DDS_TypeCode* SER_SC_LINK_CONNECTION_COMMAND_ACK_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member SER_SC_LINK_CONNECTION_COMMAND_ACK_g_tc_members[1]=
    {
        {
            (char *)"nLinkConnectionCommand",/* Member name */
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

    static DDS_TypeCode SER_SC_LINK_CONNECTION_COMMAND_ACK_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"SER_SC_LINK_CONNECTION_COMMAND_ACK", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        1, /* Number of members */
        SER_SC_LINK_CONNECTION_COMMAND_ACK_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for SER_SC_LINK_CONNECTION_COMMAND_ACK*/

    if (is_initialized) {
        return &SER_SC_LINK_CONNECTION_COMMAND_ACK_g_tc;
    }


    SER_SC_LINK_CONNECTION_COMMAND_ACK_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;

    is_initialized = RTI_TRUE;

    return &SER_SC_LINK_CONNECTION_COMMAND_ACK_g_tc;
}


RTIBool SER_SC_LINK_CONNECTION_COMMAND_ACK_initialize(
    SER_SC_LINK_CONNECTION_COMMAND_ACK* sample) {
  return SER_SC_LINK_CONNECTION_COMMAND_ACK_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}
        
RTIBool SER_SC_LINK_CONNECTION_COMMAND_ACK_initialize_ex(
    SER_SC_LINK_CONNECTION_COMMAND_ACK* sample,RTIBool allocatePointers,RTIBool allocateMemory)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */
    if (allocateMemory) {} /* To avoid warnings */

    if (!RTICdrType_initShort(&sample->nLinkConnectionCommand)) {
        return RTI_FALSE;
    }                
            


    return RTI_TRUE;
}

void SER_SC_LINK_CONNECTION_COMMAND_ACK_finalize(
    SER_SC_LINK_CONNECTION_COMMAND_ACK* sample)
{
    SER_SC_LINK_CONNECTION_COMMAND_ACK_finalize_ex(sample,RTI_TRUE);
}
        
void SER_SC_LINK_CONNECTION_COMMAND_ACK_finalize_ex(
    SER_SC_LINK_CONNECTION_COMMAND_ACK* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */



}

RTIBool SER_SC_LINK_CONNECTION_COMMAND_ACK_copy(
    SER_SC_LINK_CONNECTION_COMMAND_ACK* dst,
    const SER_SC_LINK_CONNECTION_COMMAND_ACK* src)
{        

    if (!RTICdrType_copyShort(
        &dst->nLinkConnectionCommand, &src->nLinkConnectionCommand)) {
        return RTI_FALSE;
    }
            


    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'SER_SC_LINK_CONNECTION_COMMAND_ACK' sequence class.
 */
#define T SER_SC_LINK_CONNECTION_COMMAND_ACK
#define TSeq SER_SC_LINK_CONNECTION_COMMAND_ACKSeq
#define T_initialize_ex SER_SC_LINK_CONNECTION_COMMAND_ACK_initialize_ex
#define T_finalize_ex   SER_SC_LINK_CONNECTION_COMMAND_ACK_finalize_ex
#define T_copy       SER_SC_LINK_CONNECTION_COMMAND_ACK_copy

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
const char *SC_SIM_SIMULATION_MANAGEMENT_COMMANDTYPENAME = "SC_SIM_SIMULATION_MANAGEMENT_COMMAND";

DDS_TypeCode* SC_SIM_SIMULATION_MANAGEMENT_COMMAND_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member SC_SIM_SIMULATION_MANAGEMENT_COMMAND_g_tc_members[1]=
    {
        {
            (char *)"nSimulationManagementCommand",/* Member name */
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

    static DDS_TypeCode SC_SIM_SIMULATION_MANAGEMENT_COMMAND_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"SC_SIM_SIMULATION_MANAGEMENT_COMMAND", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        1, /* Number of members */
        SC_SIM_SIMULATION_MANAGEMENT_COMMAND_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for SC_SIM_SIMULATION_MANAGEMENT_COMMAND*/

    if (is_initialized) {
        return &SC_SIM_SIMULATION_MANAGEMENT_COMMAND_g_tc;
    }


    SC_SIM_SIMULATION_MANAGEMENT_COMMAND_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;

    is_initialized = RTI_TRUE;

    return &SC_SIM_SIMULATION_MANAGEMENT_COMMAND_g_tc;
}


RTIBool SC_SIM_SIMULATION_MANAGEMENT_COMMAND_initialize(
    SC_SIM_SIMULATION_MANAGEMENT_COMMAND* sample) {
  return SC_SIM_SIMULATION_MANAGEMENT_COMMAND_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}
        
RTIBool SC_SIM_SIMULATION_MANAGEMENT_COMMAND_initialize_ex(
    SC_SIM_SIMULATION_MANAGEMENT_COMMAND* sample,RTIBool allocatePointers,RTIBool allocateMemory)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */
    if (allocateMemory) {} /* To avoid warnings */

    if (!RTICdrType_initShort(&sample->nSimulationManagementCommand)) {
        return RTI_FALSE;
    }                
            


    return RTI_TRUE;
}

void SC_SIM_SIMULATION_MANAGEMENT_COMMAND_finalize(
    SC_SIM_SIMULATION_MANAGEMENT_COMMAND* sample)
{
    SC_SIM_SIMULATION_MANAGEMENT_COMMAND_finalize_ex(sample,RTI_TRUE);
}
        
void SC_SIM_SIMULATION_MANAGEMENT_COMMAND_finalize_ex(
    SC_SIM_SIMULATION_MANAGEMENT_COMMAND* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */



}

RTIBool SC_SIM_SIMULATION_MANAGEMENT_COMMAND_copy(
    SC_SIM_SIMULATION_MANAGEMENT_COMMAND* dst,
    const SC_SIM_SIMULATION_MANAGEMENT_COMMAND* src)
{        

    if (!RTICdrType_copyShort(
        &dst->nSimulationManagementCommand, &src->nSimulationManagementCommand)) {
        return RTI_FALSE;
    }
            


    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'SC_SIM_SIMULATION_MANAGEMENT_COMMAND' sequence class.
 */
#define T SC_SIM_SIMULATION_MANAGEMENT_COMMAND
#define TSeq SC_SIM_SIMULATION_MANAGEMENT_COMMANDSeq
#define T_initialize_ex SC_SIM_SIMULATION_MANAGEMENT_COMMAND_initialize_ex
#define T_finalize_ex   SC_SIM_SIMULATION_MANAGEMENT_COMMAND_finalize_ex
#define T_copy       SC_SIM_SIMULATION_MANAGEMENT_COMMAND_copy

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
const char *SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKTYPENAME = "SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK";

DDS_TypeCode* SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK_g_tc_members[2]=
    {
        {
            (char *)"nSimulatorID",/* Member name */
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
            (char *)"nSimulationManagementCommand",/* Member name */
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

    static DDS_TypeCode SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        2, /* Number of members */
        SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK*/

    if (is_initialized) {
        return &SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK_g_tc;
    }


    SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;
    SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;

    is_initialized = RTI_TRUE;

    return &SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK_g_tc;
}


RTIBool SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK_initialize(
    SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK* sample) {
  return SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}
        
RTIBool SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK_initialize_ex(
    SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK* sample,RTIBool allocatePointers,RTIBool allocateMemory)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */
    if (allocateMemory) {} /* To avoid warnings */

    if (!RTICdrType_initShort(&sample->nSimulatorID)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initShort(&sample->nSimulationManagementCommand)) {
        return RTI_FALSE;
    }                
            


    return RTI_TRUE;
}

void SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK_finalize(
    SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK* sample)
{
    SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK_finalize_ex(sample,RTI_TRUE);
}
        
void SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK_finalize_ex(
    SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */




}

RTIBool SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK_copy(
    SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK* dst,
    const SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK* src)
{        

    if (!RTICdrType_copyShort(
        &dst->nSimulatorID, &src->nSimulatorID)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyShort(
        &dst->nSimulationManagementCommand, &src->nSimulationManagementCommand)) {
        return RTI_FALSE;
    }
            


    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK' sequence class.
 */
#define T SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK
#define TSeq SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACKSeq
#define T_initialize_ex SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK_initialize_ex
#define T_finalize_ex   SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK_finalize_ex
#define T_copy       SIM_SC_SIMULATION_MANAGEMENT_COMMAND_ACK_copy

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
const char *SC_SIM_PARAMETER_DISTRIBUTION_COMMANDTYPENAME = "SC_SIM_PARAMETER_DISTRIBUTION_COMMAND";

DDS_TypeCode* SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_g_tc_members[1]=
    {
        {
            (char *)"eParameterDistributionCommand",/* Member name */
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

    static DDS_TypeCode SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"SC_SIM_PARAMETER_DISTRIBUTION_COMMAND", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        1, /* Number of members */
        SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for SC_SIM_PARAMETER_DISTRIBUTION_COMMAND*/

    if (is_initialized) {
        return &SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_g_tc;
    }


    SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;

    is_initialized = RTI_TRUE;

    return &SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_g_tc;
}


RTIBool SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_initialize(
    SC_SIM_PARAMETER_DISTRIBUTION_COMMAND* sample) {
  return SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}
        
RTIBool SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_initialize_ex(
    SC_SIM_PARAMETER_DISTRIBUTION_COMMAND* sample,RTIBool allocatePointers,RTIBool allocateMemory)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */
    if (allocateMemory) {} /* To avoid warnings */

    if (!RTICdrType_initShort(&sample->eParameterDistributionCommand)) {
        return RTI_FALSE;
    }                
            


    return RTI_TRUE;
}

void SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_finalize(
    SC_SIM_PARAMETER_DISTRIBUTION_COMMAND* sample)
{
    SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_finalize_ex(sample,RTI_TRUE);
}
        
void SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_finalize_ex(
    SC_SIM_PARAMETER_DISTRIBUTION_COMMAND* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */



}

RTIBool SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_copy(
    SC_SIM_PARAMETER_DISTRIBUTION_COMMAND* dst,
    const SC_SIM_PARAMETER_DISTRIBUTION_COMMAND* src)
{        

    if (!RTICdrType_copyShort(
        &dst->eParameterDistributionCommand, &src->eParameterDistributionCommand)) {
        return RTI_FALSE;
    }
            


    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'SC_SIM_PARAMETER_DISTRIBUTION_COMMAND' sequence class.
 */
#define T SC_SIM_PARAMETER_DISTRIBUTION_COMMAND
#define TSeq SC_SIM_PARAMETER_DISTRIBUTION_COMMANDSeq
#define T_initialize_ex SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_initialize_ex
#define T_finalize_ex   SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_finalize_ex
#define T_copy       SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_copy

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
const char *SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKTYPENAME = "SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK";

DDS_TypeCode* SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK_g_tc_members[1]=
    {
        {
            (char *)"eParameterDistributionCommand",/* Member name */
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

    static DDS_TypeCode SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        1, /* Number of members */
        SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK*/

    if (is_initialized) {
        return &SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK_g_tc;
    }


    SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;

    is_initialized = RTI_TRUE;

    return &SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK_g_tc;
}


RTIBool SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK_initialize(
    SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK* sample) {
  return SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}
        
RTIBool SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK_initialize_ex(
    SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK* sample,RTIBool allocatePointers,RTIBool allocateMemory)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */
    if (allocateMemory) {} /* To avoid warnings */

    if (!RTICdrType_initShort(&sample->eParameterDistributionCommand)) {
        return RTI_FALSE;
    }                
            


    return RTI_TRUE;
}

void SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK_finalize(
    SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK* sample)
{
    SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK_finalize_ex(sample,RTI_TRUE);
}
        
void SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK_finalize_ex(
    SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */



}

RTIBool SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK_copy(
    SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK* dst,
    const SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK* src)
{        

    if (!RTICdrType_copyShort(
        &dst->eParameterDistributionCommand, &src->eParameterDistributionCommand)) {
        return RTI_FALSE;
    }
            


    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK' sequence class.
 */
#define T SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK
#define TSeq SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACKSeq
#define T_initialize_ex SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK_initialize_ex
#define T_finalize_ex   SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK_finalize_ex
#define T_copy       SC_SIM_PARAMETER_DISTRIBUTION_COMMAND_ACK_copy

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
const char *SC_SIM_SIMULATOR_PARAMETERTYPENAME = "SC_SIM_SIMULATOR_PARAMETER";

DDS_TypeCode* SC_SIM_SIMULATOR_PARAMETER_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode SC_SIM_SIMULATOR_PARAMETER_g_tc_chParameterXML_array = DDS_INITIALIZE_ARRAY_TYPECODE(1,2048,NULL,NULL);

    static DDS_TypeCode_Member SC_SIM_SIMULATOR_PARAMETER_g_tc_members[1]=
    {
        {
            (char *)"chParameterXML",/* Member name */
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

    static DDS_TypeCode SC_SIM_SIMULATOR_PARAMETER_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"SC_SIM_SIMULATOR_PARAMETER", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        1, /* Number of members */
        SC_SIM_SIMULATOR_PARAMETER_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for SC_SIM_SIMULATOR_PARAMETER*/

    if (is_initialized) {
        return &SC_SIM_SIMULATOR_PARAMETER_g_tc;
    }

    SC_SIM_SIMULATOR_PARAMETER_g_tc_chParameterXML_array._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;

    SC_SIM_SIMULATOR_PARAMETER_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&SC_SIM_SIMULATOR_PARAMETER_g_tc_chParameterXML_array;

    is_initialized = RTI_TRUE;

    return &SC_SIM_SIMULATOR_PARAMETER_g_tc;
}


RTIBool SC_SIM_SIMULATOR_PARAMETER_initialize(
    SC_SIM_SIMULATOR_PARAMETER* sample) {
  return SC_SIM_SIMULATOR_PARAMETER_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}
        
RTIBool SC_SIM_SIMULATOR_PARAMETER_initialize_ex(
    SC_SIM_SIMULATOR_PARAMETER* sample,RTIBool allocatePointers,RTIBool allocateMemory)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */
    if (allocateMemory) {} /* To avoid warnings */
    
    if (!RTICdrType_initArray(
        sample->chParameterXML, (2048), RTI_CDR_CHAR_SIZE)) {
        return RTI_FALSE;
    }
            


    return RTI_TRUE;
}

void SC_SIM_SIMULATOR_PARAMETER_finalize(
    SC_SIM_SIMULATOR_PARAMETER* sample)
{
    SC_SIM_SIMULATOR_PARAMETER_finalize_ex(sample,RTI_TRUE);
}
        
void SC_SIM_SIMULATOR_PARAMETER_finalize_ex(
    SC_SIM_SIMULATOR_PARAMETER* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */



}

RTIBool SC_SIM_SIMULATOR_PARAMETER_copy(
    SC_SIM_SIMULATOR_PARAMETER* dst,
    const SC_SIM_SIMULATOR_PARAMETER* src)
{        

    if (!RTICdrType_copyArray(
        dst->chParameterXML, src->chParameterXML, (2048), RTI_CDR_CHAR_SIZE)) {
        return RTI_FALSE;
    }
            


    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'SC_SIM_SIMULATOR_PARAMETER' sequence class.
 */
#define T SC_SIM_SIMULATOR_PARAMETER
#define TSeq SC_SIM_SIMULATOR_PARAMETERSeq
#define T_initialize_ex SC_SIM_SIMULATOR_PARAMETER_initialize_ex
#define T_finalize_ex   SC_SIM_SIMULATOR_PARAMETER_finalize_ex
#define T_copy       SC_SIM_SIMULATOR_PARAMETER_copy

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
const char *SIM_SC_SIMULATOR_PARAMETER_ACKTYPENAME = "SIM_SC_SIMULATOR_PARAMETER_ACK";

DDS_TypeCode* SIM_SC_SIMULATOR_PARAMETER_ACK_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member SIM_SC_SIMULATOR_PARAMETER_ACK_g_tc_members[2]=
    {
        {
            (char *)"nSimulatorID",/* Member name */
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
            (char *)"nSimulatorParameterAckState",/* Member name */
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

    static DDS_TypeCode SIM_SC_SIMULATOR_PARAMETER_ACK_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"SIM_SC_SIMULATOR_PARAMETER_ACK", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        2, /* Number of members */
        SIM_SC_SIMULATOR_PARAMETER_ACK_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for SIM_SC_SIMULATOR_PARAMETER_ACK*/

    if (is_initialized) {
        return &SIM_SC_SIMULATOR_PARAMETER_ACK_g_tc;
    }


    SIM_SC_SIMULATOR_PARAMETER_ACK_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;
    SIM_SC_SIMULATOR_PARAMETER_ACK_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;

    is_initialized = RTI_TRUE;

    return &SIM_SC_SIMULATOR_PARAMETER_ACK_g_tc;
}


RTIBool SIM_SC_SIMULATOR_PARAMETER_ACK_initialize(
    SIM_SC_SIMULATOR_PARAMETER_ACK* sample) {
  return SIM_SC_SIMULATOR_PARAMETER_ACK_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}
        
RTIBool SIM_SC_SIMULATOR_PARAMETER_ACK_initialize_ex(
    SIM_SC_SIMULATOR_PARAMETER_ACK* sample,RTIBool allocatePointers,RTIBool allocateMemory)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */
    if (allocateMemory) {} /* To avoid warnings */

    if (!RTICdrType_initShort(&sample->nSimulatorID)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initShort(&sample->nSimulatorParameterAckState)) {
        return RTI_FALSE;
    }                
            


    return RTI_TRUE;
}

void SIM_SC_SIMULATOR_PARAMETER_ACK_finalize(
    SIM_SC_SIMULATOR_PARAMETER_ACK* sample)
{
    SIM_SC_SIMULATOR_PARAMETER_ACK_finalize_ex(sample,RTI_TRUE);
}
        
void SIM_SC_SIMULATOR_PARAMETER_ACK_finalize_ex(
    SIM_SC_SIMULATOR_PARAMETER_ACK* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */




}

RTIBool SIM_SC_SIMULATOR_PARAMETER_ACK_copy(
    SIM_SC_SIMULATOR_PARAMETER_ACK* dst,
    const SIM_SC_SIMULATOR_PARAMETER_ACK* src)
{        

    if (!RTICdrType_copyShort(
        &dst->nSimulatorID, &src->nSimulatorID)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyShort(
        &dst->nSimulatorParameterAckState, &src->nSimulatorParameterAckState)) {
        return RTI_FALSE;
    }
            


    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'SIM_SC_SIMULATOR_PARAMETER_ACK' sequence class.
 */
#define T SIM_SC_SIMULATOR_PARAMETER_ACK
#define TSeq SIM_SC_SIMULATOR_PARAMETER_ACKSeq
#define T_initialize_ex SIM_SC_SIMULATOR_PARAMETER_ACK_initialize_ex
#define T_finalize_ex   SIM_SC_SIMULATOR_PARAMETER_ACK_finalize_ex
#define T_copy       SIM_SC_SIMULATOR_PARAMETER_ACK_copy

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
const char *SC_SIM_ENVIRONMENTTYPENAME = "SC_SIM_ENVIRONMENT";

DDS_TypeCode* SC_SIM_ENVIRONMENT_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member SC_SIM_ENVIRONMENT_g_tc_members[9]=
    {
        {
            (char *)"nWeather",/* Member name */
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
            (char *)"dTemparature",/* Member name */
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
            (char *)"dAirPressure",/* Member name */
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
            (char *)"dHumidity",/* Member name */
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
            (char *)"dVisibility",/* Member name */
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
            (char *)"dWindDirection",/* Member name */
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
            (char *)"dWindSpeed",/* Member name */
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
            (char *)"dWaterDirection",/* Member name */
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
            (char *)"dWaterSpeed",/* Member name */
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

    static DDS_TypeCode SC_SIM_ENVIRONMENT_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"SC_SIM_ENVIRONMENT", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        9, /* Number of members */
        SC_SIM_ENVIRONMENT_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for SC_SIM_ENVIRONMENT*/

    if (is_initialized) {
        return &SC_SIM_ENVIRONMENT_g_tc;
    }


    SC_SIM_ENVIRONMENT_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;
    SC_SIM_ENVIRONMENT_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    SC_SIM_ENVIRONMENT_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    SC_SIM_ENVIRONMENT_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    SC_SIM_ENVIRONMENT_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    SC_SIM_ENVIRONMENT_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    SC_SIM_ENVIRONMENT_g_tc_members[6]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    SC_SIM_ENVIRONMENT_g_tc_members[7]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    SC_SIM_ENVIRONMENT_g_tc_members[8]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;

    is_initialized = RTI_TRUE;

    return &SC_SIM_ENVIRONMENT_g_tc;
}


RTIBool SC_SIM_ENVIRONMENT_initialize(
    SC_SIM_ENVIRONMENT* sample) {
  return SC_SIM_ENVIRONMENT_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}
        
RTIBool SC_SIM_ENVIRONMENT_initialize_ex(
    SC_SIM_ENVIRONMENT* sample,RTIBool allocatePointers,RTIBool allocateMemory)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */
    if (allocateMemory) {} /* To avoid warnings */

    if (!RTICdrType_initShort(&sample->nWeather)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initDouble(&sample->dTemparature)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initDouble(&sample->dAirPressure)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initDouble(&sample->dHumidity)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initDouble(&sample->dVisibility)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initDouble(&sample->dWindDirection)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initDouble(&sample->dWindSpeed)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initDouble(&sample->dWaterDirection)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initDouble(&sample->dWaterSpeed)) {
        return RTI_FALSE;
    }                
            


    return RTI_TRUE;
}

void SC_SIM_ENVIRONMENT_finalize(
    SC_SIM_ENVIRONMENT* sample)
{
    SC_SIM_ENVIRONMENT_finalize_ex(sample,RTI_TRUE);
}
        
void SC_SIM_ENVIRONMENT_finalize_ex(
    SC_SIM_ENVIRONMENT* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */











}

RTIBool SC_SIM_ENVIRONMENT_copy(
    SC_SIM_ENVIRONMENT* dst,
    const SC_SIM_ENVIRONMENT* src)
{        

    if (!RTICdrType_copyShort(
        &dst->nWeather, &src->nWeather)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyDouble(
        &dst->dTemparature, &src->dTemparature)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyDouble(
        &dst->dAirPressure, &src->dAirPressure)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyDouble(
        &dst->dHumidity, &src->dHumidity)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyDouble(
        &dst->dVisibility, &src->dVisibility)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyDouble(
        &dst->dWindDirection, &src->dWindDirection)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyDouble(
        &dst->dWindSpeed, &src->dWindSpeed)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyDouble(
        &dst->dWaterDirection, &src->dWaterDirection)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyDouble(
        &dst->dWaterSpeed, &src->dWaterSpeed)) {
        return RTI_FALSE;
    }
            


    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'SC_SIM_ENVIRONMENT' sequence class.
 */
#define T SC_SIM_ENVIRONMENT
#define TSeq SC_SIM_ENVIRONMENTSeq
#define T_initialize_ex SC_SIM_ENVIRONMENT_initialize_ex
#define T_finalize_ex   SC_SIM_ENVIRONMENT_finalize_ex
#define T_copy       SC_SIM_ENVIRONMENT_copy

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
const char *SC_SIM_ENTITYTYPENAME = "SC_SIM_ENTITY";

DDS_TypeCode* SC_SIM_ENTITY_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member SC_SIM_ENTITY_g_tc_members[4]=
    {
        {
            (char *)"unEntityID",/* Member name */
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
            (char *)"stEntityInfo",/* Member name */
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
            (char *)"stEntityAttribute",/* Member name */
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
            (char *)"stEntityState",/* Member name */
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

    static DDS_TypeCode SC_SIM_ENTITY_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"SC_SIM_ENTITY", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        4, /* Number of members */
        SC_SIM_ENTITY_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for SC_SIM_ENTITY*/

    if (is_initialized) {
        return &SC_SIM_ENTITY_g_tc;
    }


    SC_SIM_ENTITY_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;
    SC_SIM_ENTITY_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)ST_ENTITY_INFO_get_typecode();
    SC_SIM_ENTITY_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)ST_ENTITY_ATTRIBUTE_get_typecode();
    SC_SIM_ENTITY_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)ST_ENTITY_STATE_get_typecode();

    is_initialized = RTI_TRUE;

    return &SC_SIM_ENTITY_g_tc;
}


RTIBool SC_SIM_ENTITY_initialize(
    SC_SIM_ENTITY* sample) {
  return SC_SIM_ENTITY_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}
        
RTIBool SC_SIM_ENTITY_initialize_ex(
    SC_SIM_ENTITY* sample,RTIBool allocatePointers,RTIBool allocateMemory)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */
    if (allocateMemory) {} /* To avoid warnings */

    if (!RTICdrType_initUnsignedShort(&sample->unEntityID)) {
        return RTI_FALSE;
    }                
            

    if (!ST_ENTITY_INFO_initialize_ex(&sample->stEntityInfo,allocatePointers,allocateMemory)) {
        return RTI_FALSE;
    }
            

    if (!ST_ENTITY_ATTRIBUTE_initialize_ex(&sample->stEntityAttribute,allocatePointers,allocateMemory)) {
        return RTI_FALSE;
    }
            

    if (!ST_ENTITY_STATE_initialize_ex(&sample->stEntityState,allocatePointers,allocateMemory)) {
        return RTI_FALSE;
    }
            


    return RTI_TRUE;
}

void SC_SIM_ENTITY_finalize(
    SC_SIM_ENTITY* sample)
{
    SC_SIM_ENTITY_finalize_ex(sample,RTI_TRUE);
}
        
void SC_SIM_ENTITY_finalize_ex(
    SC_SIM_ENTITY* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */



    ST_ENTITY_INFO_finalize_ex(&sample->stEntityInfo,deletePointers);
            

    ST_ENTITY_ATTRIBUTE_finalize_ex(&sample->stEntityAttribute,deletePointers);
            

    ST_ENTITY_STATE_finalize_ex(&sample->stEntityState,deletePointers);
            

}

RTIBool SC_SIM_ENTITY_copy(
    SC_SIM_ENTITY* dst,
    const SC_SIM_ENTITY* src)
{        

    if (!RTICdrType_copyUnsignedShort(
        &dst->unEntityID, &src->unEntityID)) {
        return RTI_FALSE;
    }
            

    if (!ST_ENTITY_INFO_copy(
        &dst->stEntityInfo, &src->stEntityInfo)) {
        return RTI_FALSE;
    }
            

    if (!ST_ENTITY_ATTRIBUTE_copy(
        &dst->stEntityAttribute, &src->stEntityAttribute)) {
        return RTI_FALSE;
    }
            

    if (!ST_ENTITY_STATE_copy(
        &dst->stEntityState, &src->stEntityState)) {
        return RTI_FALSE;
    }
            


    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'SC_SIM_ENTITY' sequence class.
 */
#define T SC_SIM_ENTITY
#define TSeq SC_SIM_ENTITYSeq
#define T_initialize_ex SC_SIM_ENTITY_initialize_ex
#define T_finalize_ex   SC_SIM_ENTITY_finalize_ex
#define T_copy       SC_SIM_ENTITY_copy

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
const char *SC_SIM_ENTITY_STATETYPENAME = "SC_SIM_ENTITY_STATE";

DDS_TypeCode* SC_SIM_ENTITY_STATE_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member SC_SIM_ENTITY_STATE_g_tc_members[2]=
    {
        {
            (char *)"unEntityID",/* Member name */
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
            (char *)"stEntityState",/* Member name */
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

    static DDS_TypeCode SC_SIM_ENTITY_STATE_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"SC_SIM_ENTITY_STATE", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        2, /* Number of members */
        SC_SIM_ENTITY_STATE_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for SC_SIM_ENTITY_STATE*/

    if (is_initialized) {
        return &SC_SIM_ENTITY_STATE_g_tc;
    }


    SC_SIM_ENTITY_STATE_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;
    SC_SIM_ENTITY_STATE_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)ST_ENTITY_STATE_get_typecode();

    is_initialized = RTI_TRUE;

    return &SC_SIM_ENTITY_STATE_g_tc;
}


RTIBool SC_SIM_ENTITY_STATE_initialize(
    SC_SIM_ENTITY_STATE* sample) {
  return SC_SIM_ENTITY_STATE_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}
        
RTIBool SC_SIM_ENTITY_STATE_initialize_ex(
    SC_SIM_ENTITY_STATE* sample,RTIBool allocatePointers,RTIBool allocateMemory)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */
    if (allocateMemory) {} /* To avoid warnings */

    if (!RTICdrType_initUnsignedShort(&sample->unEntityID)) {
        return RTI_FALSE;
    }                
            

    if (!ST_ENTITY_STATE_initialize_ex(&sample->stEntityState,allocatePointers,allocateMemory)) {
        return RTI_FALSE;
    }
            


    return RTI_TRUE;
}

void SC_SIM_ENTITY_STATE_finalize(
    SC_SIM_ENTITY_STATE* sample)
{
    SC_SIM_ENTITY_STATE_finalize_ex(sample,RTI_TRUE);
}
        
void SC_SIM_ENTITY_STATE_finalize_ex(
    SC_SIM_ENTITY_STATE* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */



    ST_ENTITY_STATE_finalize_ex(&sample->stEntityState,deletePointers);
            

}

RTIBool SC_SIM_ENTITY_STATE_copy(
    SC_SIM_ENTITY_STATE* dst,
    const SC_SIM_ENTITY_STATE* src)
{        

    if (!RTICdrType_copyUnsignedShort(
        &dst->unEntityID, &src->unEntityID)) {
        return RTI_FALSE;
    }
            

    if (!ST_ENTITY_STATE_copy(
        &dst->stEntityState, &src->stEntityState)) {
        return RTI_FALSE;
    }
            


    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'SC_SIM_ENTITY_STATE' sequence class.
 */
#define T SC_SIM_ENTITY_STATE
#define TSeq SC_SIM_ENTITY_STATESeq
#define T_initialize_ex SC_SIM_ENTITY_STATE_initialize_ex
#define T_finalize_ex   SC_SIM_ENTITY_STATE_finalize_ex
#define T_copy       SC_SIM_ENTITY_STATE_copy

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
const char *SC_SIM_OWNSHIPTYPENAME = "SC_SIM_OWNSHIP";

DDS_TypeCode* SC_SIM_OWNSHIP_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member SC_SIM_OWNSHIP_g_tc_members[4]=
    {
        {
            (char *)"unEntityID",/* Member name */
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
            (char *)"stEntityInfo",/* Member name */
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
            (char *)"stEntityAttribute",/* Member name */
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
            (char *)"stEntityState",/* Member name */
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

    static DDS_TypeCode SC_SIM_OWNSHIP_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"SC_SIM_OWNSHIP", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        4, /* Number of members */
        SC_SIM_OWNSHIP_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for SC_SIM_OWNSHIP*/

    if (is_initialized) {
        return &SC_SIM_OWNSHIP_g_tc;
    }


    SC_SIM_OWNSHIP_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;
    SC_SIM_OWNSHIP_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)ST_ENTITY_INFO_get_typecode();
    SC_SIM_OWNSHIP_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)ST_ENTITY_ATTRIBUTE_get_typecode();
    SC_SIM_OWNSHIP_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)ST_ENTITY_STATE_get_typecode();

    is_initialized = RTI_TRUE;

    return &SC_SIM_OWNSHIP_g_tc;
}


RTIBool SC_SIM_OWNSHIP_initialize(
    SC_SIM_OWNSHIP* sample) {
  return SC_SIM_OWNSHIP_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}
        
RTIBool SC_SIM_OWNSHIP_initialize_ex(
    SC_SIM_OWNSHIP* sample,RTIBool allocatePointers,RTIBool allocateMemory)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */
    if (allocateMemory) {} /* To avoid warnings */

    if (!RTICdrType_initUnsignedShort(&sample->unEntityID)) {
        return RTI_FALSE;
    }                
            

    if (!ST_ENTITY_INFO_initialize_ex(&sample->stEntityInfo,allocatePointers,allocateMemory)) {
        return RTI_FALSE;
    }
            

    if (!ST_ENTITY_ATTRIBUTE_initialize_ex(&sample->stEntityAttribute,allocatePointers,allocateMemory)) {
        return RTI_FALSE;
    }
            

    if (!ST_ENTITY_STATE_initialize_ex(&sample->stEntityState,allocatePointers,allocateMemory)) {
        return RTI_FALSE;
    }
            


    return RTI_TRUE;
}

void SC_SIM_OWNSHIP_finalize(
    SC_SIM_OWNSHIP* sample)
{
    SC_SIM_OWNSHIP_finalize_ex(sample,RTI_TRUE);
}
        
void SC_SIM_OWNSHIP_finalize_ex(
    SC_SIM_OWNSHIP* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */



    ST_ENTITY_INFO_finalize_ex(&sample->stEntityInfo,deletePointers);
            

    ST_ENTITY_ATTRIBUTE_finalize_ex(&sample->stEntityAttribute,deletePointers);
            

    ST_ENTITY_STATE_finalize_ex(&sample->stEntityState,deletePointers);
            

}

RTIBool SC_SIM_OWNSHIP_copy(
    SC_SIM_OWNSHIP* dst,
    const SC_SIM_OWNSHIP* src)
{        

    if (!RTICdrType_copyUnsignedShort(
        &dst->unEntityID, &src->unEntityID)) {
        return RTI_FALSE;
    }
            

    if (!ST_ENTITY_INFO_copy(
        &dst->stEntityInfo, &src->stEntityInfo)) {
        return RTI_FALSE;
    }
            

    if (!ST_ENTITY_ATTRIBUTE_copy(
        &dst->stEntityAttribute, &src->stEntityAttribute)) {
        return RTI_FALSE;
    }
            

    if (!ST_ENTITY_STATE_copy(
        &dst->stEntityState, &src->stEntityState)) {
        return RTI_FALSE;
    }
            


    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'SC_SIM_OWNSHIP' sequence class.
 */
#define T SC_SIM_OWNSHIP
#define TSeq SC_SIM_OWNSHIPSeq
#define T_initialize_ex SC_SIM_OWNSHIP_initialize_ex
#define T_finalize_ex   SC_SIM_OWNSHIP_finalize_ex
#define T_copy       SC_SIM_OWNSHIP_copy

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
const char *SC_SIM_OWNSHIP_STATETYPENAME = "SC_SIM_OWNSHIP_STATE";

DDS_TypeCode* SC_SIM_OWNSHIP_STATE_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member SC_SIM_OWNSHIP_STATE_g_tc_members[2]=
    {
        {
            (char *)"unEntityID",/* Member name */
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
            (char *)"stEntityState",/* Member name */
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

    static DDS_TypeCode SC_SIM_OWNSHIP_STATE_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"SC_SIM_OWNSHIP_STATE", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        2, /* Number of members */
        SC_SIM_OWNSHIP_STATE_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for SC_SIM_OWNSHIP_STATE*/

    if (is_initialized) {
        return &SC_SIM_OWNSHIP_STATE_g_tc;
    }


    SC_SIM_OWNSHIP_STATE_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;
    SC_SIM_OWNSHIP_STATE_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)ST_ENTITY_STATE_get_typecode();

    is_initialized = RTI_TRUE;

    return &SC_SIM_OWNSHIP_STATE_g_tc;
}


RTIBool SC_SIM_OWNSHIP_STATE_initialize(
    SC_SIM_OWNSHIP_STATE* sample) {
  return SC_SIM_OWNSHIP_STATE_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}
        
RTIBool SC_SIM_OWNSHIP_STATE_initialize_ex(
    SC_SIM_OWNSHIP_STATE* sample,RTIBool allocatePointers,RTIBool allocateMemory)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */
    if (allocateMemory) {} /* To avoid warnings */

    if (!RTICdrType_initUnsignedShort(&sample->unEntityID)) {
        return RTI_FALSE;
    }                
            

    if (!ST_ENTITY_STATE_initialize_ex(&sample->stEntityState,allocatePointers,allocateMemory)) {
        return RTI_FALSE;
    }
            


    return RTI_TRUE;
}

void SC_SIM_OWNSHIP_STATE_finalize(
    SC_SIM_OWNSHIP_STATE* sample)
{
    SC_SIM_OWNSHIP_STATE_finalize_ex(sample,RTI_TRUE);
}
        
void SC_SIM_OWNSHIP_STATE_finalize_ex(
    SC_SIM_OWNSHIP_STATE* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */



    ST_ENTITY_STATE_finalize_ex(&sample->stEntityState,deletePointers);
            

}

RTIBool SC_SIM_OWNSHIP_STATE_copy(
    SC_SIM_OWNSHIP_STATE* dst,
    const SC_SIM_OWNSHIP_STATE* src)
{        

    if (!RTICdrType_copyUnsignedShort(
        &dst->unEntityID, &src->unEntityID)) {
        return RTI_FALSE;
    }
            

    if (!ST_ENTITY_STATE_copy(
        &dst->stEntityState, &src->stEntityState)) {
        return RTI_FALSE;
    }
            


    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'SC_SIM_OWNSHIP_STATE' sequence class.
 */
#define T SC_SIM_OWNSHIP_STATE
#define TSeq SC_SIM_OWNSHIP_STATESeq
#define T_initialize_ex SC_SIM_OWNSHIP_STATE_initialize_ex
#define T_finalize_ex   SC_SIM_OWNSHIP_STATE_finalize_ex
#define T_copy       SC_SIM_OWNSHIP_STATE_copy

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
const char *SIM_SC_MISSILE_CREATIONTYPENAME = "SIM_SC_MISSILE_CREATION";

DDS_TypeCode* SIM_SC_MISSILE_CREATION_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode SIM_SC_MISSILE_CREATION_g_tc_stWaypointCoordinate_array = DDS_INITIALIZE_ARRAY_TYPECODE(1,8,NULL,NULL);

    static DDS_TypeCode_Member SIM_SC_MISSILE_CREATION_g_tc_members[3]=
    {
        {
            (char *)"lTimeToFire",/* Member name */
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
            (char *)"stMissileData",/* Member name */
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
            (char *)"stWaypointCoordinate",/* Member name */
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

    static DDS_TypeCode SIM_SC_MISSILE_CREATION_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"SIM_SC_MISSILE_CREATION", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        3, /* Number of members */
        SIM_SC_MISSILE_CREATION_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for SIM_SC_MISSILE_CREATION*/

    if (is_initialized) {
        return &SIM_SC_MISSILE_CREATION_g_tc;
    }

    SIM_SC_MISSILE_CREATION_g_tc_stWaypointCoordinate_array._data._typeCode = (RTICdrTypeCode *)ST_POSITION_get_typecode();

    SIM_SC_MISSILE_CREATION_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    SIM_SC_MISSILE_CREATION_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)ST_MISSILE_DATA_get_typecode();
    SIM_SC_MISSILE_CREATION_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&SIM_SC_MISSILE_CREATION_g_tc_stWaypointCoordinate_array;

    is_initialized = RTI_TRUE;

    return &SIM_SC_MISSILE_CREATION_g_tc;
}


RTIBool SIM_SC_MISSILE_CREATION_initialize(
    SIM_SC_MISSILE_CREATION* sample) {
  return SIM_SC_MISSILE_CREATION_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}
        
RTIBool SIM_SC_MISSILE_CREATION_initialize_ex(
    SIM_SC_MISSILE_CREATION* sample,RTIBool allocatePointers,RTIBool allocateMemory)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */
    if (allocateMemory) {} /* To avoid warnings */

    if (!RTICdrType_initLong(&sample->lTimeToFire)) {
        return RTI_FALSE;
    }                
            

    if (!ST_MISSILE_DATA_initialize_ex(&sample->stMissileData,allocatePointers,allocateMemory)) {
        return RTI_FALSE;
    }
            

    
    {
        int i = 0;
        ST_POSITION* elem =
            (ST_POSITION*) &sample->stWaypointCoordinate[0];

        for (i = 0; i < (int)((8)); ++i, ++elem) {
            if (!ST_POSITION_initialize_ex(elem,allocatePointers,allocateMemory)) {
                return RTI_FALSE;
            }
        }
    }
            


    return RTI_TRUE;
}

void SIM_SC_MISSILE_CREATION_finalize(
    SIM_SC_MISSILE_CREATION* sample)
{
    SIM_SC_MISSILE_CREATION_finalize_ex(sample,RTI_TRUE);
}
        
void SIM_SC_MISSILE_CREATION_finalize_ex(
    SIM_SC_MISSILE_CREATION* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */



    ST_MISSILE_DATA_finalize_ex(&sample->stMissileData,deletePointers);
            

    
    {
        int i = 0;
        ST_POSITION* elem =
            (ST_POSITION*) &sample->stWaypointCoordinate[0];

        for (i = 0; i < (int)((8)); ++i, ++elem) {
            ST_POSITION_finalize_ex(elem,deletePointers);
        }
    }
            

}

RTIBool SIM_SC_MISSILE_CREATION_copy(
    SIM_SC_MISSILE_CREATION* dst,
    const SIM_SC_MISSILE_CREATION* src)
{        

    if (!RTICdrType_copyLong(
        &dst->lTimeToFire, &src->lTimeToFire)) {
        return RTI_FALSE;
    }
            

    if (!ST_MISSILE_DATA_copy(
        &dst->stMissileData, &src->stMissileData)) {
        return RTI_FALSE;
    }
            

    
    {
        int i = 0;
        ST_POSITION* elemOut = (ST_POSITION*) &dst->stWaypointCoordinate[0];
        const ST_POSITION* elemIn = (const ST_POSITION*) &src->stWaypointCoordinate[0];

        for (i = 0; i < (int)((8));
             ++i, ++elemOut, ++elemIn) {
            if (!ST_POSITION_copy(elemOut,(const ST_POSITION*)elemIn)) {
                return RTI_FALSE;
            }
        }
    }
            


    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'SIM_SC_MISSILE_CREATION' sequence class.
 */
#define T SIM_SC_MISSILE_CREATION
#define TSeq SIM_SC_MISSILE_CREATIONSeq
#define T_initialize_ex SIM_SC_MISSILE_CREATION_initialize_ex
#define T_finalize_ex   SIM_SC_MISSILE_CREATION_finalize_ex
#define T_copy       SIM_SC_MISSILE_CREATION_copy

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
const char *SIM_SC_SHELL_CREATIONTYPENAME = "SIM_SC_SHELL_CREATION";

DDS_TypeCode* SIM_SC_SHELL_CREATION_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member SIM_SC_SHELL_CREATION_g_tc_members[4]=
    {
        {
            (char *)"lTimeToFire",/* Member name */
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
            (char *)"stAmmunitionData",/* Member name */
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
            (char *)"dElevation",/* Member name */
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

    static DDS_TypeCode SIM_SC_SHELL_CREATION_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"SIM_SC_SHELL_CREATION", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        4, /* Number of members */
        SIM_SC_SHELL_CREATION_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for SIM_SC_SHELL_CREATION*/

    if (is_initialized) {
        return &SIM_SC_SHELL_CREATION_g_tc;
    }


    SIM_SC_SHELL_CREATION_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    SIM_SC_SHELL_CREATION_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)ST_AMMUNITION_DATA_get_typecode();
    SIM_SC_SHELL_CREATION_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    SIM_SC_SHELL_CREATION_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;

    is_initialized = RTI_TRUE;

    return &SIM_SC_SHELL_CREATION_g_tc;
}


RTIBool SIM_SC_SHELL_CREATION_initialize(
    SIM_SC_SHELL_CREATION* sample) {
  return SIM_SC_SHELL_CREATION_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}
        
RTIBool SIM_SC_SHELL_CREATION_initialize_ex(
    SIM_SC_SHELL_CREATION* sample,RTIBool allocatePointers,RTIBool allocateMemory)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */
    if (allocateMemory) {} /* To avoid warnings */

    if (!RTICdrType_initLong(&sample->lTimeToFire)) {
        return RTI_FALSE;
    }                
            

    if (!ST_AMMUNITION_DATA_initialize_ex(&sample->stAmmunitionData,allocatePointers,allocateMemory)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_initDouble(&sample->dBearing)) {
        return RTI_FALSE;
    }                
            

    if (!RTICdrType_initDouble(&sample->dElevation)) {
        return RTI_FALSE;
    }                
            


    return RTI_TRUE;
}

void SIM_SC_SHELL_CREATION_finalize(
    SIM_SC_SHELL_CREATION* sample)
{
    SIM_SC_SHELL_CREATION_finalize_ex(sample,RTI_TRUE);
}
        
void SIM_SC_SHELL_CREATION_finalize_ex(
    SIM_SC_SHELL_CREATION* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */



    ST_AMMUNITION_DATA_finalize_ex(&sample->stAmmunitionData,deletePointers);
            



}

RTIBool SIM_SC_SHELL_CREATION_copy(
    SIM_SC_SHELL_CREATION* dst,
    const SIM_SC_SHELL_CREATION* src)
{        

    if (!RTICdrType_copyLong(
        &dst->lTimeToFire, &src->lTimeToFire)) {
        return RTI_FALSE;
    }
            

    if (!ST_AMMUNITION_DATA_copy(
        &dst->stAmmunitionData, &src->stAmmunitionData)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyDouble(
        &dst->dBearing, &src->dBearing)) {
        return RTI_FALSE;
    }
            

    if (!RTICdrType_copyDouble(
        &dst->dElevation, &src->dElevation)) {
        return RTI_FALSE;
    }
            


    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'SIM_SC_SHELL_CREATION' sequence class.
 */
#define T SIM_SC_SHELL_CREATION
#define TSeq SIM_SC_SHELL_CREATIONSeq
#define T_initialize_ex SIM_SC_SHELL_CREATION_initialize_ex
#define T_finalize_ex   SIM_SC_SHELL_CREATION_finalize_ex
#define T_copy       SIM_SC_SHELL_CREATION_copy

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

