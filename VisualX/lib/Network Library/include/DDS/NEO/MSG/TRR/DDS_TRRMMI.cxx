
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from DDS_TRRMMI.idl using "rtiddsgen".
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



#include "DDS_TRRMMI.h"

/* ========================================================================= */
const char *DMSG_TRR_TARGETTYPENAME = "DMSG_TRR_TARGET";

DDS_TypeCode* DMSG_TRR_TARGET_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_TRR_TARGET_g_tc_members[9]=
    {
        {
            (char *)"nTargetNum",/* Member name */
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
            (char *)"byTargetCategory",/* Member name */
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
            (char *)"byIsValidTarget",/* Member name */
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

    static DDS_TypeCode DMSG_TRR_TARGET_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_TRR_TARGET", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        9, /* Number of members */
        DMSG_TRR_TARGET_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_TRR_TARGET*/

    if (is_initialized) {
        return &DMSG_TRR_TARGET_g_tc;
    }


    DMSG_TRR_TARGET_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;
    DMSG_TRR_TARGET_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_TRR_TARGET_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_TRR_TARGET_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_TRR_TARGET_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_TRR_TARGET_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_TRR_TARGET_g_tc_members[6]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_TRR_TARGET_g_tc_members[7]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_TRR_TARGET_g_tc_members[8]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;

    is_initialized = RTI_TRUE;

    return &DMSG_TRR_TARGET_g_tc;
}


RTIBool DMSG_TRR_TARGET_initialize(
    DMSG_TRR_TARGET* sample) {
  return DMSG_TRR_TARGET_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_TRR_TARGET_initialize_ex(
    DMSG_TRR_TARGET* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initUnsignedLong(&sample->nTargetNum)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->byTargetCategory)) {
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
            
    if (!RTICdrType_initChar(&sample->byIsValidTarget)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_TRR_TARGET_finalize(
    DMSG_TRR_TARGET* sample)
{
    DMSG_TRR_TARGET_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_TRR_TARGET_finalize_ex(
    DMSG_TRR_TARGET* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_TRR_TARGET_copy(
    DMSG_TRR_TARGET* dst,
    const DMSG_TRR_TARGET* src)
{        

    if (!RTICdrType_copyUnsignedLong(
        &dst->nTargetNum, &src->nTargetNum)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->byTargetCategory, &src->byTargetCategory)) {
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
            
    if (!RTICdrType_copyChar(
        &dst->byIsValidTarget, &src->byIsValidTarget)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_TRR_TARGET' sequence class.
 */
#define T DMSG_TRR_TARGET
#define TSeq DMSG_TRR_TARGETSeq
#define T_initialize_ex DMSG_TRR_TARGET_initialize_ex
#define T_finalize_ex   DMSG_TRR_TARGET_finalize_ex
#define T_copy       DMSG_TRR_TARGET_copy

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
const char *DMSG_TRR_DIRECTORTYPENAME = "DMSG_TRR_DIRECTOR";

DDS_TypeCode* DMSG_TRR_DIRECTOR_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_TRR_DIRECTOR_g_tc_members[3]=
    {
        {
            (char *)"dDirectorTraverse",/* Member name */
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
            (char *)"dDirectorBearing",/* Member name */
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
            (char *)"dDirectorElevation",/* Member name */
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

    static DDS_TypeCode DMSG_TRR_DIRECTOR_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_TRR_DIRECTOR", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        3, /* Number of members */
        DMSG_TRR_DIRECTOR_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_TRR_DIRECTOR*/

    if (is_initialized) {
        return &DMSG_TRR_DIRECTOR_g_tc;
    }


    DMSG_TRR_DIRECTOR_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_TRR_DIRECTOR_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_TRR_DIRECTOR_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;

    is_initialized = RTI_TRUE;

    return &DMSG_TRR_DIRECTOR_g_tc;
}


RTIBool DMSG_TRR_DIRECTOR_initialize(
    DMSG_TRR_DIRECTOR* sample) {
  return DMSG_TRR_DIRECTOR_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_TRR_DIRECTOR_initialize_ex(
    DMSG_TRR_DIRECTOR* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initDouble(&sample->dDirectorTraverse)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dDirectorBearing)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dDirectorElevation)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_TRR_DIRECTOR_finalize(
    DMSG_TRR_DIRECTOR* sample)
{
    DMSG_TRR_DIRECTOR_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_TRR_DIRECTOR_finalize_ex(
    DMSG_TRR_DIRECTOR* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_TRR_DIRECTOR_copy(
    DMSG_TRR_DIRECTOR* dst,
    const DMSG_TRR_DIRECTOR* src)
{        

    if (!RTICdrType_copyDouble(
        &dst->dDirectorTraverse, &src->dDirectorTraverse)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dDirectorBearing, &src->dDirectorBearing)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dDirectorElevation, &src->dDirectorElevation)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_TRR_DIRECTOR' sequence class.
 */
#define T DMSG_TRR_DIRECTOR
#define TSeq DMSG_TRR_DIRECTORSeq
#define T_initialize_ex DMSG_TRR_DIRECTOR_initialize_ex
#define T_finalize_ex   DMSG_TRR_DIRECTOR_finalize_ex
#define T_copy       DMSG_TRR_DIRECTOR_copy

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
const char *DMSG_TRR_TRACKINGTYPENAME = "DMSG_TRR_TRACKING";

DDS_TypeCode* DMSG_TRR_TRACKING_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_TRR_TRACKING_g_tc_members[5]=
    {
        {
            (char *)"nTargetNum",/* Member name */
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
            (char *)"bySourceTrack",/* Member name */
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
            (char *)"byKillAssessment",/* Member name */
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
            (char *)"byRadiationAuthority",/* Member name */
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

    static DDS_TypeCode DMSG_TRR_TRACKING_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_TRR_TRACKING", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        5, /* Number of members */
        DMSG_TRR_TRACKING_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_TRR_TRACKING*/

    if (is_initialized) {
        return &DMSG_TRR_TRACKING_g_tc;
    }


    DMSG_TRR_TRACKING_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    DMSG_TRR_TRACKING_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_TRR_TRACKING_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_TRR_TRACKING_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_TRR_TRACKING_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;

    is_initialized = RTI_TRUE;

    return &DMSG_TRR_TRACKING_g_tc;
}


RTIBool DMSG_TRR_TRACKING_initialize(
    DMSG_TRR_TRACKING* sample) {
  return DMSG_TRR_TRACKING_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_TRR_TRACKING_initialize_ex(
    DMSG_TRR_TRACKING* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initLong(&sample->nTargetNum)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->byTrackingStatus)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->bySourceTrack)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->byKillAssessment)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->byRadiationAuthority)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_TRR_TRACKING_finalize(
    DMSG_TRR_TRACKING* sample)
{
    DMSG_TRR_TRACKING_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_TRR_TRACKING_finalize_ex(
    DMSG_TRR_TRACKING* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_TRR_TRACKING_copy(
    DMSG_TRR_TRACKING* dst,
    const DMSG_TRR_TRACKING* src)
{        

    if (!RTICdrType_copyLong(
        &dst->nTargetNum, &src->nTargetNum)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->byTrackingStatus, &src->byTrackingStatus)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->bySourceTrack, &src->bySourceTrack)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->byKillAssessment, &src->byKillAssessment)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->byRadiationAuthority, &src->byRadiationAuthority)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_TRR_TRACKING' sequence class.
 */
#define T DMSG_TRR_TRACKING
#define TSeq DMSG_TRR_TRACKINGSeq
#define T_initialize_ex DMSG_TRR_TRACKING_initialize_ex
#define T_finalize_ex   DMSG_TRR_TRACKING_finalize_ex
#define T_copy       DMSG_TRR_TRACKING_copy

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
const char *DMSG_TRR_SHOOTDOWNRESULTTYPENAME = "DMSG_TRR_SHOOTDOWNRESULT";

DDS_TypeCode* DMSG_TRR_SHOOTDOWNRESULT_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_TRR_SHOOTDOWNRESULT_g_tc_members[2]=
    {
        {
            (char *)"nTargetNum",/* Member name */
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
            (char *)"byshootdownResult",/* Member name */
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

    static DDS_TypeCode DMSG_TRR_SHOOTDOWNRESULT_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_TRR_SHOOTDOWNRESULT", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        2, /* Number of members */
        DMSG_TRR_SHOOTDOWNRESULT_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_TRR_SHOOTDOWNRESULT*/

    if (is_initialized) {
        return &DMSG_TRR_SHOOTDOWNRESULT_g_tc;
    }


    DMSG_TRR_SHOOTDOWNRESULT_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;
    DMSG_TRR_SHOOTDOWNRESULT_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;

    is_initialized = RTI_TRUE;

    return &DMSG_TRR_SHOOTDOWNRESULT_g_tc;
}


RTIBool DMSG_TRR_SHOOTDOWNRESULT_initialize(
    DMSG_TRR_SHOOTDOWNRESULT* sample) {
  return DMSG_TRR_SHOOTDOWNRESULT_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_TRR_SHOOTDOWNRESULT_initialize_ex(
    DMSG_TRR_SHOOTDOWNRESULT* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initUnsignedLong(&sample->nTargetNum)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->byshootdownResult)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_TRR_SHOOTDOWNRESULT_finalize(
    DMSG_TRR_SHOOTDOWNRESULT* sample)
{
    DMSG_TRR_SHOOTDOWNRESULT_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_TRR_SHOOTDOWNRESULT_finalize_ex(
    DMSG_TRR_SHOOTDOWNRESULT* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_TRR_SHOOTDOWNRESULT_copy(
    DMSG_TRR_SHOOTDOWNRESULT* dst,
    const DMSG_TRR_SHOOTDOWNRESULT* src)
{        

    if (!RTICdrType_copyUnsignedLong(
        &dst->nTargetNum, &src->nTargetNum)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->byshootdownResult, &src->byshootdownResult)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_TRR_SHOOTDOWNRESULT' sequence class.
 */
#define T DMSG_TRR_SHOOTDOWNRESULT
#define TSeq DMSG_TRR_SHOOTDOWNRESULTSeq
#define T_initialize_ex DMSG_TRR_SHOOTDOWNRESULT_initialize_ex
#define T_finalize_ex   DMSG_TRR_SHOOTDOWNRESULT_finalize_ex
#define T_copy       DMSG_TRR_SHOOTDOWNRESULT_copy

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
const char *DMSG_TRR_SETRESULTTYPENAME = "DMSG_TRR_SETRESULT";

DDS_TypeCode* DMSG_TRR_SETRESULT_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_TRR_SETRESULT_g_tc_members[2]=
    {
        {
            (char *)"bySettingCategory",/* Member name */
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
            (char *)"bySettingResult",/* Member name */
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

    static DDS_TypeCode DMSG_TRR_SETRESULT_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_TRR_SETRESULT", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        2, /* Number of members */
        DMSG_TRR_SETRESULT_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_TRR_SETRESULT*/

    if (is_initialized) {
        return &DMSG_TRR_SETRESULT_g_tc;
    }


    DMSG_TRR_SETRESULT_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_TRR_SETRESULT_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;

    is_initialized = RTI_TRUE;

    return &DMSG_TRR_SETRESULT_g_tc;
}


RTIBool DMSG_TRR_SETRESULT_initialize(
    DMSG_TRR_SETRESULT* sample) {
  return DMSG_TRR_SETRESULT_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_TRR_SETRESULT_initialize_ex(
    DMSG_TRR_SETRESULT* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initChar(&sample->bySettingCategory)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->bySettingResult)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_TRR_SETRESULT_finalize(
    DMSG_TRR_SETRESULT* sample)
{
    DMSG_TRR_SETRESULT_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_TRR_SETRESULT_finalize_ex(
    DMSG_TRR_SETRESULT* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_TRR_SETRESULT_copy(
    DMSG_TRR_SETRESULT* dst,
    const DMSG_TRR_SETRESULT* src)
{        

    if (!RTICdrType_copyChar(
        &dst->bySettingCategory, &src->bySettingCategory)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->bySettingResult, &src->bySettingResult)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_TRR_SETRESULT' sequence class.
 */
#define T DMSG_TRR_SETRESULT
#define TSeq DMSG_TRR_SETRESULTSeq
#define T_initialize_ex DMSG_TRR_SETRESULT_initialize_ex
#define T_finalize_ex   DMSG_TRR_SETRESULT_finalize_ex
#define T_copy       DMSG_TRR_SETRESULT_copy

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
const char *DMSG_TRR_ASCOPETYPENAME = "DMSG_TRR_ASCOPE";

DDS_TypeCode* DMSG_TRR_ASCOPE_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode DMSG_TRR_ASCOPE_g_tc_nSignalPower_array = DDS_INITIALIZE_ARRAY_TYPECODE(1,100,NULL,NULL);

    static DDS_TypeCode_Member DMSG_TRR_ASCOPE_g_tc_members[4]=
    {
        {
            (char *)"nSamplingNum",/* Member name */
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
            (char *)"nSignalPower",/* Member name */
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
            (char *)"nScaleX",/* Member name */
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
            (char *)"nScaleY",/* Member name */
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

    static DDS_TypeCode DMSG_TRR_ASCOPE_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_TRR_ASCOPE", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        4, /* Number of members */
        DMSG_TRR_ASCOPE_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_TRR_ASCOPE*/

    if (is_initialized) {
        return &DMSG_TRR_ASCOPE_g_tc;
    }

    DMSG_TRR_ASCOPE_g_tc_nSignalPower_array._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

    DMSG_TRR_ASCOPE_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    DMSG_TRR_ASCOPE_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DMSG_TRR_ASCOPE_g_tc_nSignalPower_array;
    DMSG_TRR_ASCOPE_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    DMSG_TRR_ASCOPE_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

    is_initialized = RTI_TRUE;

    return &DMSG_TRR_ASCOPE_g_tc;
}


RTIBool DMSG_TRR_ASCOPE_initialize(
    DMSG_TRR_ASCOPE* sample) {
  return DMSG_TRR_ASCOPE_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_TRR_ASCOPE_initialize_ex(
    DMSG_TRR_ASCOPE* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initLong(&sample->nSamplingNum)) {
        return RTI_FALSE;
    }                
                
    if (!RTICdrType_initArray(
        sample->nSignalPower, (100), RTI_CDR_LONG_SIZE)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_initLong(&sample->nScaleX)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initLong(&sample->nScaleY)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_TRR_ASCOPE_finalize(
    DMSG_TRR_ASCOPE* sample)
{
    DMSG_TRR_ASCOPE_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_TRR_ASCOPE_finalize_ex(
    DMSG_TRR_ASCOPE* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_TRR_ASCOPE_copy(
    DMSG_TRR_ASCOPE* dst,
    const DMSG_TRR_ASCOPE* src)
{        

    if (!RTICdrType_copyLong(
        &dst->nSamplingNum, &src->nSamplingNum)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyArray(
        dst->nSignalPower, src->nSignalPower, (100), RTI_CDR_LONG_SIZE)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyLong(
        &dst->nScaleX, &src->nScaleX)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyLong(
        &dst->nScaleY, &src->nScaleY)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_TRR_ASCOPE' sequence class.
 */
#define T DMSG_TRR_ASCOPE
#define TSeq DMSG_TRR_ASCOPESeq
#define T_initialize_ex DMSG_TRR_ASCOPE_initialize_ex
#define T_finalize_ex   DMSG_TRR_ASCOPE_finalize_ex
#define T_copy       DMSG_TRR_ASCOPE_copy

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
const char *DMSG_TRR_STATETYPENAME = "DMSG_TRR_STATE";

DDS_TypeCode* DMSG_TRR_STATE_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_TRR_STATE_g_tc_members[2]=
    {
        {
            (char *)"byInterlockState",/* Member name */
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
            (char *)"byAvailableState",/* Member name */
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

    static DDS_TypeCode DMSG_TRR_STATE_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_TRR_STATE", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        2, /* Number of members */
        DMSG_TRR_STATE_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_TRR_STATE*/

    if (is_initialized) {
        return &DMSG_TRR_STATE_g_tc;
    }


    DMSG_TRR_STATE_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_TRR_STATE_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;

    is_initialized = RTI_TRUE;

    return &DMSG_TRR_STATE_g_tc;
}


RTIBool DMSG_TRR_STATE_initialize(
    DMSG_TRR_STATE* sample) {
  return DMSG_TRR_STATE_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_TRR_STATE_initialize_ex(
    DMSG_TRR_STATE* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initChar(&sample->byInterlockState)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->byAvailableState)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_TRR_STATE_finalize(
    DMSG_TRR_STATE* sample)
{
    DMSG_TRR_STATE_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_TRR_STATE_finalize_ex(
    DMSG_TRR_STATE* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_TRR_STATE_copy(
    DMSG_TRR_STATE* dst,
    const DMSG_TRR_STATE* src)
{        

    if (!RTICdrType_copyChar(
        &dst->byInterlockState, &src->byInterlockState)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->byAvailableState, &src->byAvailableState)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_TRR_STATE' sequence class.
 */
#define T DMSG_TRR_STATE
#define TSeq DMSG_TRR_STATESeq
#define T_initialize_ex DMSG_TRR_STATE_initialize_ex
#define T_finalize_ex   DMSG_TRR_STATE_finalize_ex
#define T_copy       DMSG_TRR_STATE_copy

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
const char *DMSG_HMI_TRRRDRCHECKREQTYPENAME = "DMSG_HMI_TRRRDRCHECKREQ";

DDS_TypeCode* DMSG_HMI_TRRRDRCHECKREQ_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_HMI_TRRRDRCHECKREQ_g_tc_members[1]=
    {
        {
            (char *)"cRadarTest",/* Member name */
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

    static DDS_TypeCode DMSG_HMI_TRRRDRCHECKREQ_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_HMI_TRRRDRCHECKREQ", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        1, /* Number of members */
        DMSG_HMI_TRRRDRCHECKREQ_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_HMI_TRRRDRCHECKREQ*/

    if (is_initialized) {
        return &DMSG_HMI_TRRRDRCHECKREQ_g_tc;
    }


    DMSG_HMI_TRRRDRCHECKREQ_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;

    is_initialized = RTI_TRUE;

    return &DMSG_HMI_TRRRDRCHECKREQ_g_tc;
}


RTIBool DMSG_HMI_TRRRDRCHECKREQ_initialize(
    DMSG_HMI_TRRRDRCHECKREQ* sample) {
  return DMSG_HMI_TRRRDRCHECKREQ_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_HMI_TRRRDRCHECKREQ_initialize_ex(
    DMSG_HMI_TRRRDRCHECKREQ* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initChar(&sample->cRadarTest)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_HMI_TRRRDRCHECKREQ_finalize(
    DMSG_HMI_TRRRDRCHECKREQ* sample)
{
    DMSG_HMI_TRRRDRCHECKREQ_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_HMI_TRRRDRCHECKREQ_finalize_ex(
    DMSG_HMI_TRRRDRCHECKREQ* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_HMI_TRRRDRCHECKREQ_copy(
    DMSG_HMI_TRRRDRCHECKREQ* dst,
    const DMSG_HMI_TRRRDRCHECKREQ* src)
{        

    if (!RTICdrType_copyChar(
        &dst->cRadarTest, &src->cRadarTest)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_HMI_TRRRDRCHECKREQ' sequence class.
 */
#define T DMSG_HMI_TRRRDRCHECKREQ
#define TSeq DMSG_HMI_TRRRDRCHECKREQSeq
#define T_initialize_ex DMSG_HMI_TRRRDRCHECKREQ_initialize_ex
#define T_finalize_ex   DMSG_HMI_TRRRDRCHECKREQ_finalize_ex
#define T_copy       DMSG_HMI_TRRRDRCHECKREQ_copy

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
const char *DMSG_EC_TRRTRACKINGCMDTYPENAME = "DMSG_EC_TRRTRACKINGCMD";

DDS_TypeCode* DMSG_EC_TRRTRACKINGCMD_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_EC_TRRTRACKINGCMD_g_tc_members[5]=
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
            (char *)"nTargetNum",/* Member name */
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
        },
        {
            (char *)"dDistance",/* Member name */
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

    static DDS_TypeCode DMSG_EC_TRRTRACKINGCMD_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_EC_TRRTRACKINGCMD", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        5, /* Number of members */
        DMSG_EC_TRRTRACKINGCMD_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_EC_TRRTRACKINGCMD*/

    if (is_initialized) {
        return &DMSG_EC_TRRTRACKINGCMD_g_tc;
    }


    DMSG_EC_TRRTRACKINGCMD_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_EC_TRRTRACKINGCMD_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;
    DMSG_EC_TRRTRACKINGCMD_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_EC_TRRTRACKINGCMD_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_EC_TRRTRACKINGCMD_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;

    is_initialized = RTI_TRUE;

    return &DMSG_EC_TRRTRACKINGCMD_g_tc;
}


RTIBool DMSG_EC_TRRTRACKINGCMD_initialize(
    DMSG_EC_TRRTRACKINGCMD* sample) {
  return DMSG_EC_TRRTRACKINGCMD_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_EC_TRRTRACKINGCMD_initialize_ex(
    DMSG_EC_TRRTRACKINGCMD* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initChar(&sample->byTrackingStatus)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initUnsignedLong(&sample->nTargetNum)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dBearing)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dElevation)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dDistance)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_EC_TRRTRACKINGCMD_finalize(
    DMSG_EC_TRRTRACKINGCMD* sample)
{
    DMSG_EC_TRRTRACKINGCMD_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_EC_TRRTRACKINGCMD_finalize_ex(
    DMSG_EC_TRRTRACKINGCMD* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_EC_TRRTRACKINGCMD_copy(
    DMSG_EC_TRRTRACKINGCMD* dst,
    const DMSG_EC_TRRTRACKINGCMD* src)
{        

    if (!RTICdrType_copyChar(
        &dst->byTrackingStatus, &src->byTrackingStatus)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyUnsignedLong(
        &dst->nTargetNum, &src->nTargetNum)) {
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
            
    if (!RTICdrType_copyDouble(
        &dst->dDistance, &src->dDistance)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_EC_TRRTRACKINGCMD' sequence class.
 */
#define T DMSG_EC_TRRTRACKINGCMD
#define TSeq DMSG_EC_TRRTRACKINGCMDSeq
#define T_initialize_ex DMSG_EC_TRRTRACKINGCMD_initialize_ex
#define T_finalize_ex   DMSG_EC_TRRTRACKINGCMD_finalize_ex
#define T_copy       DMSG_EC_TRRTRACKINGCMD_copy

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
const char *DMSG_HMI_TRRSHOOTDOWNRESULTREQTYPENAME = "DMSG_HMI_TRRSHOOTDOWNRESULTREQ";

DDS_TypeCode* DMSG_HMI_TRRSHOOTDOWNRESULTREQ_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_HMI_TRRSHOOTDOWNRESULTREQ_g_tc_members[2]=
    {
        {
            (char *)"nTargetNum",/* Member name */
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
            (char *)"byRequestStatus",/* Member name */
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

    static DDS_TypeCode DMSG_HMI_TRRSHOOTDOWNRESULTREQ_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_HMI_TRRSHOOTDOWNRESULTREQ", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        2, /* Number of members */
        DMSG_HMI_TRRSHOOTDOWNRESULTREQ_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_HMI_TRRSHOOTDOWNRESULTREQ*/

    if (is_initialized) {
        return &DMSG_HMI_TRRSHOOTDOWNRESULTREQ_g_tc;
    }


    DMSG_HMI_TRRSHOOTDOWNRESULTREQ_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;
    DMSG_HMI_TRRSHOOTDOWNRESULTREQ_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;

    is_initialized = RTI_TRUE;

    return &DMSG_HMI_TRRSHOOTDOWNRESULTREQ_g_tc;
}


RTIBool DMSG_HMI_TRRSHOOTDOWNRESULTREQ_initialize(
    DMSG_HMI_TRRSHOOTDOWNRESULTREQ* sample) {
  return DMSG_HMI_TRRSHOOTDOWNRESULTREQ_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_HMI_TRRSHOOTDOWNRESULTREQ_initialize_ex(
    DMSG_HMI_TRRSHOOTDOWNRESULTREQ* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initUnsignedLong(&sample->nTargetNum)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->byRequestStatus)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_HMI_TRRSHOOTDOWNRESULTREQ_finalize(
    DMSG_HMI_TRRSHOOTDOWNRESULTREQ* sample)
{
    DMSG_HMI_TRRSHOOTDOWNRESULTREQ_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_HMI_TRRSHOOTDOWNRESULTREQ_finalize_ex(
    DMSG_HMI_TRRSHOOTDOWNRESULTREQ* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_HMI_TRRSHOOTDOWNRESULTREQ_copy(
    DMSG_HMI_TRRSHOOTDOWNRESULTREQ* dst,
    const DMSG_HMI_TRRSHOOTDOWNRESULTREQ* src)
{        

    if (!RTICdrType_copyUnsignedLong(
        &dst->nTargetNum, &src->nTargetNum)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->byRequestStatus, &src->byRequestStatus)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_HMI_TRRSHOOTDOWNRESULTREQ' sequence class.
 */
#define T DMSG_HMI_TRRSHOOTDOWNRESULTREQ
#define TSeq DMSG_HMI_TRRSHOOTDOWNRESULTREQSeq
#define T_initialize_ex DMSG_HMI_TRRSHOOTDOWNRESULTREQ_initialize_ex
#define T_finalize_ex   DMSG_HMI_TRRSHOOTDOWNRESULTREQ_finalize_ex
#define T_copy       DMSG_HMI_TRRSHOOTDOWNRESULTREQ_copy

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
const char *DMSG_HMI_TRRRDRSETTYPENAME = "DMSG_HMI_TRRRDRSET";

DDS_TypeCode* DMSG_HMI_TRRRDRSET_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_HMI_TRRRDRSET_g_tc_members[3]=
    {
        {
            (char *)"byTWTConfig",/* Member name */
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
            (char *)"byTransmitMode",/* Member name */
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
            (char *)"byDecreaseMode",/* Member name */
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

    static DDS_TypeCode DMSG_HMI_TRRRDRSET_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_HMI_TRRRDRSET", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        3, /* Number of members */
        DMSG_HMI_TRRRDRSET_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_HMI_TRRRDRSET*/

    if (is_initialized) {
        return &DMSG_HMI_TRRRDRSET_g_tc;
    }


    DMSG_HMI_TRRRDRSET_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_HMI_TRRRDRSET_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_HMI_TRRRDRSET_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;

    is_initialized = RTI_TRUE;

    return &DMSG_HMI_TRRRDRSET_g_tc;
}


RTIBool DMSG_HMI_TRRRDRSET_initialize(
    DMSG_HMI_TRRRDRSET* sample) {
  return DMSG_HMI_TRRRDRSET_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_HMI_TRRRDRSET_initialize_ex(
    DMSG_HMI_TRRRDRSET* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initChar(&sample->byTWTConfig)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->byTransmitMode)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->byDecreaseMode)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_HMI_TRRRDRSET_finalize(
    DMSG_HMI_TRRRDRSET* sample)
{
    DMSG_HMI_TRRRDRSET_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_HMI_TRRRDRSET_finalize_ex(
    DMSG_HMI_TRRRDRSET* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_HMI_TRRRDRSET_copy(
    DMSG_HMI_TRRRDRSET* dst,
    const DMSG_HMI_TRRRDRSET* src)
{        

    if (!RTICdrType_copyChar(
        &dst->byTWTConfig, &src->byTWTConfig)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->byTransmitMode, &src->byTransmitMode)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->byDecreaseMode, &src->byDecreaseMode)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_HMI_TRRRDRSET' sequence class.
 */
#define T DMSG_HMI_TRRRDRSET
#define TSeq DMSG_HMI_TRRRDRSETSeq
#define T_initialize_ex DMSG_HMI_TRRRDRSET_initialize_ex
#define T_finalize_ex   DMSG_HMI_TRRRDRSET_finalize_ex
#define T_copy       DMSG_HMI_TRRRDRSET_copy

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
const char *DMSG_HMI_TRRVIDEOSETTYPENAME = "DMSG_HMI_TRRVIDEOSET";

DDS_TypeCode* DMSG_HMI_TRRVIDEOSET_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_HMI_TRRVIDEOSET_g_tc_members[4]=
    {
        {
            (char *)"byAScopeSTC",/* Member name */
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
            (char *)"byAScopeVideo",/* Member name */
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
            (char *)"byNoiseThreshold",/* Member name */
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
            (char *)"byDisplayThreshold",/* Member name */
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

    static DDS_TypeCode DMSG_HMI_TRRVIDEOSET_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_HMI_TRRVIDEOSET", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        4, /* Number of members */
        DMSG_HMI_TRRVIDEOSET_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_HMI_TRRVIDEOSET*/

    if (is_initialized) {
        return &DMSG_HMI_TRRVIDEOSET_g_tc;
    }


    DMSG_HMI_TRRVIDEOSET_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_HMI_TRRVIDEOSET_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_HMI_TRRVIDEOSET_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_HMI_TRRVIDEOSET_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;

    is_initialized = RTI_TRUE;

    return &DMSG_HMI_TRRVIDEOSET_g_tc;
}


RTIBool DMSG_HMI_TRRVIDEOSET_initialize(
    DMSG_HMI_TRRVIDEOSET* sample) {
  return DMSG_HMI_TRRVIDEOSET_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_HMI_TRRVIDEOSET_initialize_ex(
    DMSG_HMI_TRRVIDEOSET* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initChar(&sample->byAScopeSTC)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->byAScopeVideo)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->byNoiseThreshold)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->byDisplayThreshold)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_HMI_TRRVIDEOSET_finalize(
    DMSG_HMI_TRRVIDEOSET* sample)
{
    DMSG_HMI_TRRVIDEOSET_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_HMI_TRRVIDEOSET_finalize_ex(
    DMSG_HMI_TRRVIDEOSET* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_HMI_TRRVIDEOSET_copy(
    DMSG_HMI_TRRVIDEOSET* dst,
    const DMSG_HMI_TRRVIDEOSET* src)
{        

    if (!RTICdrType_copyChar(
        &dst->byAScopeSTC, &src->byAScopeSTC)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->byAScopeVideo, &src->byAScopeVideo)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->byNoiseThreshold, &src->byNoiseThreshold)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->byDisplayThreshold, &src->byDisplayThreshold)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_HMI_TRRVIDEOSET' sequence class.
 */
#define T DMSG_HMI_TRRVIDEOSET
#define TSeq DMSG_HMI_TRRVIDEOSETSeq
#define T_initialize_ex DMSG_HMI_TRRVIDEOSET_initialize_ex
#define T_finalize_ex   DMSG_HMI_TRRVIDEOSET_finalize_ex
#define T_copy       DMSG_HMI_TRRVIDEOSET_copy

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
const char *DMSG_HMI_TRRMANAGESETTYPENAME = "DMSG_HMI_TRRMANAGESET";

DDS_TypeCode* DMSG_HMI_TRRMANAGESET_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_HMI_TRRMANAGESET_g_tc_members[4]=
    {
        {
            (char *)"nInitAltitude",/* Member name */
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
            (char *)"nShipTrackAltitude",/* Member name */
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
            (char *)"bySeaState",/* Member name */
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
            (char *)"nMaxAltitude",/* Member name */
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

    static DDS_TypeCode DMSG_HMI_TRRMANAGESET_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_HMI_TRRMANAGESET", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        4, /* Number of members */
        DMSG_HMI_TRRMANAGESET_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_HMI_TRRMANAGESET*/

    if (is_initialized) {
        return &DMSG_HMI_TRRMANAGESET_g_tc;
    }


    DMSG_HMI_TRRMANAGESET_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    DMSG_HMI_TRRMANAGESET_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    DMSG_HMI_TRRMANAGESET_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_HMI_TRRMANAGESET_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

    is_initialized = RTI_TRUE;

    return &DMSG_HMI_TRRMANAGESET_g_tc;
}


RTIBool DMSG_HMI_TRRMANAGESET_initialize(
    DMSG_HMI_TRRMANAGESET* sample) {
  return DMSG_HMI_TRRMANAGESET_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_HMI_TRRMANAGESET_initialize_ex(
    DMSG_HMI_TRRMANAGESET* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initLong(&sample->nInitAltitude)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initLong(&sample->nShipTrackAltitude)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->bySeaState)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initLong(&sample->nMaxAltitude)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_HMI_TRRMANAGESET_finalize(
    DMSG_HMI_TRRMANAGESET* sample)
{
    DMSG_HMI_TRRMANAGESET_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_HMI_TRRMANAGESET_finalize_ex(
    DMSG_HMI_TRRMANAGESET* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_HMI_TRRMANAGESET_copy(
    DMSG_HMI_TRRMANAGESET* dst,
    const DMSG_HMI_TRRMANAGESET* src)
{        

    if (!RTICdrType_copyLong(
        &dst->nInitAltitude, &src->nInitAltitude)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyLong(
        &dst->nShipTrackAltitude, &src->nShipTrackAltitude)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->bySeaState, &src->bySeaState)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyLong(
        &dst->nMaxAltitude, &src->nMaxAltitude)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_HMI_TRRMANAGESET' sequence class.
 */
#define T DMSG_HMI_TRRMANAGESET
#define TSeq DMSG_HMI_TRRMANAGESETSeq
#define T_initialize_ex DMSG_HMI_TRRMANAGESET_initialize_ex
#define T_finalize_ex   DMSG_HMI_TRRMANAGESET_finalize_ex
#define T_copy       DMSG_HMI_TRRMANAGESET_copy

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
const char *DMSG_HMI_TRRCAUTIONSETTYPENAME = "DMSG_HMI_TRRCAUTIONSET";

DDS_TypeCode* DMSG_HMI_TRRCAUTIONSET_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_HMI_TRRCAUTIONSET_g_tc_members[2]=
    {
        {
            (char *)"bMissileCaution",/* Member name */
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
            (char *)"bJammerTracking",/* Member name */
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

    static DDS_TypeCode DMSG_HMI_TRRCAUTIONSET_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_HMI_TRRCAUTIONSET", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        2, /* Number of members */
        DMSG_HMI_TRRCAUTIONSET_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_HMI_TRRCAUTIONSET*/

    if (is_initialized) {
        return &DMSG_HMI_TRRCAUTIONSET_g_tc;
    }


    DMSG_HMI_TRRCAUTIONSET_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;
    DMSG_HMI_TRRCAUTIONSET_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

    is_initialized = RTI_TRUE;

    return &DMSG_HMI_TRRCAUTIONSET_g_tc;
}


RTIBool DMSG_HMI_TRRCAUTIONSET_initialize(
    DMSG_HMI_TRRCAUTIONSET* sample) {
  return DMSG_HMI_TRRCAUTIONSET_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_HMI_TRRCAUTIONSET_initialize_ex(
    DMSG_HMI_TRRCAUTIONSET* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initBoolean(&sample->bMissileCaution)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initBoolean(&sample->bJammerTracking)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_HMI_TRRCAUTIONSET_finalize(
    DMSG_HMI_TRRCAUTIONSET* sample)
{
    DMSG_HMI_TRRCAUTIONSET_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_HMI_TRRCAUTIONSET_finalize_ex(
    DMSG_HMI_TRRCAUTIONSET* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_HMI_TRRCAUTIONSET_copy(
    DMSG_HMI_TRRCAUTIONSET* dst,
    const DMSG_HMI_TRRCAUTIONSET* src)
{        

    if (!RTICdrType_copyBoolean(
        &dst->bMissileCaution, &src->bMissileCaution)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyBoolean(
        &dst->bJammerTracking, &src->bJammerTracking)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_HMI_TRRCAUTIONSET' sequence class.
 */
#define T DMSG_HMI_TRRCAUTIONSET
#define TSeq DMSG_HMI_TRRCAUTIONSETSeq
#define T_initialize_ex DMSG_HMI_TRRCAUTIONSET_initialize_ex
#define T_finalize_ex   DMSG_HMI_TRRCAUTIONSET_finalize_ex
#define T_copy       DMSG_HMI_TRRCAUTIONSET_copy

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
const char *DMSG_HMI_TRREQUIPMENTSETTYPENAME = "DMSG_HMI_TRREQUIPMENTSET";

DDS_TypeCode* DMSG_HMI_TRREQUIPMENTSET_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_HMI_TRREQUIPMENTSET_g_tc_members[6]=
    {
        {
            (char *)"byTWTPower",/* Member name */
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
            (char *)"byEmergencyManageMode",/* Member name */
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
            (char *)"byRadiationControl",/* Member name */
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
            (char *)"byRadarSilence",/* Member name */
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
            (char *)"byDirector",/* Member name */
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
            (char *)"byJoystick",/* Member name */
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

    static DDS_TypeCode DMSG_HMI_TRREQUIPMENTSET_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_HMI_TRREQUIPMENTSET", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        6, /* Number of members */
        DMSG_HMI_TRREQUIPMENTSET_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_HMI_TRREQUIPMENTSET*/

    if (is_initialized) {
        return &DMSG_HMI_TRREQUIPMENTSET_g_tc;
    }


    DMSG_HMI_TRREQUIPMENTSET_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_HMI_TRREQUIPMENTSET_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_HMI_TRREQUIPMENTSET_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_HMI_TRREQUIPMENTSET_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_HMI_TRREQUIPMENTSET_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_HMI_TRREQUIPMENTSET_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;

    is_initialized = RTI_TRUE;

    return &DMSG_HMI_TRREQUIPMENTSET_g_tc;
}


RTIBool DMSG_HMI_TRREQUIPMENTSET_initialize(
    DMSG_HMI_TRREQUIPMENTSET* sample) {
  return DMSG_HMI_TRREQUIPMENTSET_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_HMI_TRREQUIPMENTSET_initialize_ex(
    DMSG_HMI_TRREQUIPMENTSET* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initChar(&sample->byTWTPower)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->byEmergencyManageMode)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->byRadiationControl)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->byRadarSilence)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->byDirector)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->byJoystick)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_HMI_TRREQUIPMENTSET_finalize(
    DMSG_HMI_TRREQUIPMENTSET* sample)
{
    DMSG_HMI_TRREQUIPMENTSET_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_HMI_TRREQUIPMENTSET_finalize_ex(
    DMSG_HMI_TRREQUIPMENTSET* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_HMI_TRREQUIPMENTSET_copy(
    DMSG_HMI_TRREQUIPMENTSET* dst,
    const DMSG_HMI_TRREQUIPMENTSET* src)
{        

    if (!RTICdrType_copyChar(
        &dst->byTWTPower, &src->byTWTPower)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->byEmergencyManageMode, &src->byEmergencyManageMode)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->byRadiationControl, &src->byRadiationControl)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->byRadarSilence, &src->byRadarSilence)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->byDirector, &src->byDirector)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->byJoystick, &src->byJoystick)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_HMI_TRREQUIPMENTSET' sequence class.
 */
#define T DMSG_HMI_TRREQUIPMENTSET
#define TSeq DMSG_HMI_TRREQUIPMENTSETSeq
#define T_initialize_ex DMSG_HMI_TRREQUIPMENTSET_initialize_ex
#define T_finalize_ex   DMSG_HMI_TRREQUIPMENTSET_finalize_ex
#define T_copy       DMSG_HMI_TRREQUIPMENTSET_copy

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
const char *DMSG_HMI_TRRTRACKINGSETTYPENAME = "DMSG_HMI_TRRTRACKINGSET";

DDS_TypeCode* DMSG_HMI_TRRTRACKINGSET_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_HMI_TRRTRACKINGSET_g_tc_members[8]=
    {
        {
            (char *)"byHandTracking",/* Member name */
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
            (char *)"byHandRegulation",/* Member name */
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
            (char *)"bySecondaryTarget",/* Member name */
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
            (char *)"nRangeGateMoveCtr",/* Member name */
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
            (char *)"byRangeGateCtr",/* Member name */
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
            (char *)"byLowAltitudeTracking",/* Member name */
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
            (char *)"byFlightTarget",/* Member name */
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
            (char *)"byFilter",/* Member name */
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

    static DDS_TypeCode DMSG_HMI_TRRTRACKINGSET_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_HMI_TRRTRACKINGSET", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        8, /* Number of members */
        DMSG_HMI_TRRTRACKINGSET_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_HMI_TRRTRACKINGSET*/

    if (is_initialized) {
        return &DMSG_HMI_TRRTRACKINGSET_g_tc;
    }


    DMSG_HMI_TRRTRACKINGSET_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_HMI_TRRTRACKINGSET_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_HMI_TRRTRACKINGSET_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_HMI_TRRTRACKINGSET_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    DMSG_HMI_TRRTRACKINGSET_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_HMI_TRRTRACKINGSET_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_HMI_TRRTRACKINGSET_g_tc_members[6]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_HMI_TRRTRACKINGSET_g_tc_members[7]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;

    is_initialized = RTI_TRUE;

    return &DMSG_HMI_TRRTRACKINGSET_g_tc;
}


RTIBool DMSG_HMI_TRRTRACKINGSET_initialize(
    DMSG_HMI_TRRTRACKINGSET* sample) {
  return DMSG_HMI_TRRTRACKINGSET_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_HMI_TRRTRACKINGSET_initialize_ex(
    DMSG_HMI_TRRTRACKINGSET* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initChar(&sample->byHandTracking)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->byHandRegulation)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->bySecondaryTarget)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initLong(&sample->nRangeGateMoveCtr)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->byRangeGateCtr)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->byLowAltitudeTracking)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->byFlightTarget)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->byFilter)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_HMI_TRRTRACKINGSET_finalize(
    DMSG_HMI_TRRTRACKINGSET* sample)
{
    DMSG_HMI_TRRTRACKINGSET_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_HMI_TRRTRACKINGSET_finalize_ex(
    DMSG_HMI_TRRTRACKINGSET* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_HMI_TRRTRACKINGSET_copy(
    DMSG_HMI_TRRTRACKINGSET* dst,
    const DMSG_HMI_TRRTRACKINGSET* src)
{        

    if (!RTICdrType_copyChar(
        &dst->byHandTracking, &src->byHandTracking)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->byHandRegulation, &src->byHandRegulation)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->bySecondaryTarget, &src->bySecondaryTarget)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyLong(
        &dst->nRangeGateMoveCtr, &src->nRangeGateMoveCtr)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->byRangeGateCtr, &src->byRangeGateCtr)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->byLowAltitudeTracking, &src->byLowAltitudeTracking)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->byFlightTarget, &src->byFlightTarget)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->byFilter, &src->byFilter)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_HMI_TRRTRACKINGSET' sequence class.
 */
#define T DMSG_HMI_TRRTRACKINGSET
#define TSeq DMSG_HMI_TRRTRACKINGSETSeq
#define T_initialize_ex DMSG_HMI_TRRTRACKINGSET_initialize_ex
#define T_finalize_ex   DMSG_HMI_TRRTRACKINGSET_finalize_ex
#define T_copy       DMSG_HMI_TRRTRACKINGSET_copy

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
const char *DMSG_HMI_TRRVIDEOREQTYPENAME = "DMSG_HMI_TRRVIDEOREQ";

DDS_TypeCode* DMSG_HMI_TRRVIDEOREQ_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_HMI_TRRVIDEOREQ_g_tc_members[1]=
    {
        {
            (char *)"cRequestVideo",/* Member name */
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

    static DDS_TypeCode DMSG_HMI_TRRVIDEOREQ_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_HMI_TRRVIDEOREQ", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        1, /* Number of members */
        DMSG_HMI_TRRVIDEOREQ_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_HMI_TRRVIDEOREQ*/

    if (is_initialized) {
        return &DMSG_HMI_TRRVIDEOREQ_g_tc;
    }


    DMSG_HMI_TRRVIDEOREQ_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;

    is_initialized = RTI_TRUE;

    return &DMSG_HMI_TRRVIDEOREQ_g_tc;
}


RTIBool DMSG_HMI_TRRVIDEOREQ_initialize(
    DMSG_HMI_TRRVIDEOREQ* sample) {
  return DMSG_HMI_TRRVIDEOREQ_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_HMI_TRRVIDEOREQ_initialize_ex(
    DMSG_HMI_TRRVIDEOREQ* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initChar(&sample->cRequestVideo)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_HMI_TRRVIDEOREQ_finalize(
    DMSG_HMI_TRRVIDEOREQ* sample)
{
    DMSG_HMI_TRRVIDEOREQ_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_HMI_TRRVIDEOREQ_finalize_ex(
    DMSG_HMI_TRRVIDEOREQ* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_HMI_TRRVIDEOREQ_copy(
    DMSG_HMI_TRRVIDEOREQ* dst,
    const DMSG_HMI_TRRVIDEOREQ* src)
{        

    if (!RTICdrType_copyChar(
        &dst->cRequestVideo, &src->cRequestVideo)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_HMI_TRRVIDEOREQ' sequence class.
 */
#define T DMSG_HMI_TRRVIDEOREQ
#define TSeq DMSG_HMI_TRRVIDEOREQSeq
#define T_initialize_ex DMSG_HMI_TRRVIDEOREQ_initialize_ex
#define T_finalize_ex   DMSG_HMI_TRRVIDEOREQ_finalize_ex
#define T_copy       DMSG_HMI_TRRVIDEOREQ_copy

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

