
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from DDS_GUNMMI.idl using "rtiddsgen".
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



#include "DDS_GUNMMI.h"

/* ========================================================================= */
const char *DMSG_GFC_FIREDATATYPENAME = "DMSG_GFC_FIREDATA";

DDS_TypeCode* DMSG_GFC_FIREDATA_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_GFC_FIREDATA_g_tc_members[4]=
    {
        {
            (char *)"dAoS",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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
            (char *)"dEle",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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
            (char *)"dAzi",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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
            (char *)"dToF",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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

    static DDS_TypeCode DMSG_GFC_FIREDATA_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_GFC_FIREDATA", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        4, /* Number of members */
        DMSG_GFC_FIREDATA_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_GFC_FIREDATA*/

    if (is_initialized) {
        return &DMSG_GFC_FIREDATA_g_tc;
    }


    DMSG_GFC_FIREDATA_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_GFC_FIREDATA_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_GFC_FIREDATA_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_GFC_FIREDATA_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;

    is_initialized = RTI_TRUE;

    return &DMSG_GFC_FIREDATA_g_tc;
}


RTIBool DMSG_GFC_FIREDATA_initialize(
    DMSG_GFC_FIREDATA* sample) {
  return DMSG_GFC_FIREDATA_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_GFC_FIREDATA_initialize_ex(
    DMSG_GFC_FIREDATA* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initDouble(&sample->dAoS)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dEle)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dAzi)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dToF)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_GFC_FIREDATA_finalize(
    DMSG_GFC_FIREDATA* sample)
{
    DMSG_GFC_FIREDATA_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_GFC_FIREDATA_finalize_ex(
    DMSG_GFC_FIREDATA* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_GFC_FIREDATA_copy(
    DMSG_GFC_FIREDATA* dst,
    const DMSG_GFC_FIREDATA* src)
{        

    if (!RTICdrType_copyDouble(
        &dst->dAoS, &src->dAoS)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dEle, &src->dEle)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dAzi, &src->dAzi)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dToF, &src->dToF)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_GFC_FIREDATA' sequence class.
 */
#define T DMSG_GFC_FIREDATA
#define TSeq DMSG_GFC_FIREDATASeq
#define T_initialize_ex DMSG_GFC_FIREDATA_initialize_ex
#define T_finalize_ex   DMSG_GFC_FIREDATA_finalize_ex
#define T_copy       DMSG_GFC_FIREDATA_copy

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
const char *DMSG_EC_FIRINGCMDTYPENAME = "DMSG_EC_FIRINGCMD";

DDS_TypeCode* DMSG_EC_FIRINGCMD_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_EC_FIRINGCMD_g_tc_members[1]=
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
        }
    };

    static DDS_TypeCode DMSG_EC_FIRINGCMD_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_EC_FIRINGCMD", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        1, /* Number of members */
        DMSG_EC_FIRINGCMD_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_EC_FIRINGCMD*/

    if (is_initialized) {
        return &DMSG_EC_FIRINGCMD_g_tc;
    }


    DMSG_EC_FIRINGCMD_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;

    is_initialized = RTI_TRUE;

    return &DMSG_EC_FIRINGCMD_g_tc;
}


RTIBool DMSG_EC_FIRINGCMD_initialize(
    DMSG_EC_FIRINGCMD* sample) {
  return DMSG_EC_FIRINGCMD_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_EC_FIRINGCMD_initialize_ex(
    DMSG_EC_FIRINGCMD* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initChar(&sample->command)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_EC_FIRINGCMD_finalize(
    DMSG_EC_FIRINGCMD* sample)
{
    DMSG_EC_FIRINGCMD_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_EC_FIRINGCMD_finalize_ex(
    DMSG_EC_FIRINGCMD* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_EC_FIRINGCMD_copy(
    DMSG_EC_FIRINGCMD* dst,
    const DMSG_EC_FIRINGCMD* src)
{        

    if (!RTICdrType_copyChar(
        &dst->command, &src->command)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_EC_FIRINGCMD' sequence class.
 */
#define T DMSG_EC_FIRINGCMD
#define TSeq DMSG_EC_FIRINGCMDSeq
#define T_initialize_ex DMSG_EC_FIRINGCMD_initialize_ex
#define T_finalize_ex   DMSG_EC_FIRINGCMD_finalize_ex
#define T_copy       DMSG_EC_FIRINGCMD_copy

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
const char *DMSG_GFC_HITEXPECTTYPENAME = "DMSG_GFC_HITEXPECT";

DDS_TypeCode* DMSG_GFC_HITEXPECT_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_GFC_HITEXPECT_g_tc_members[3]=
    {
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

    static DDS_TypeCode DMSG_GFC_HITEXPECT_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_GFC_HITEXPECT", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        3, /* Number of members */
        DMSG_GFC_HITEXPECT_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_GFC_HITEXPECT*/

    if (is_initialized) {
        return &DMSG_GFC_HITEXPECT_g_tc;
    }


    DMSG_GFC_HITEXPECT_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_GFC_HITEXPECT_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_GFC_HITEXPECT_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;

    is_initialized = RTI_TRUE;

    return &DMSG_GFC_HITEXPECT_g_tc;
}


RTIBool DMSG_GFC_HITEXPECT_initialize(
    DMSG_GFC_HITEXPECT* sample) {
  return DMSG_GFC_HITEXPECT_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_GFC_HITEXPECT_initialize_ex(
    DMSG_GFC_HITEXPECT* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


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

void DMSG_GFC_HITEXPECT_finalize(
    DMSG_GFC_HITEXPECT* sample)
{
    DMSG_GFC_HITEXPECT_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_GFC_HITEXPECT_finalize_ex(
    DMSG_GFC_HITEXPECT* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_GFC_HITEXPECT_copy(
    DMSG_GFC_HITEXPECT* dst,
    const DMSG_GFC_HITEXPECT* src)
{        

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
 * Configure and implement 'DMSG_GFC_HITEXPECT' sequence class.
 */
#define T DMSG_GFC_HITEXPECT
#define TSeq DMSG_GFC_HITEXPECTSeq
#define T_initialize_ex DMSG_GFC_HITEXPECT_initialize_ex
#define T_finalize_ex   DMSG_GFC_HITEXPECT_finalize_ex
#define T_copy       DMSG_GFC_HITEXPECT_copy

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
const char *DMSG_GUN_STATETYPENAME = "DMSG_GUN_STATE";

DDS_TypeCode* DMSG_GUN_STATE_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_GUN_STATE_g_tc_members[19]=
    {
        {
            (char *)"bMotorState",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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
            (char *)"bControlMode",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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
            (char *)"bGunState",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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
            (char *)"bServerState",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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
            (char *)"bAngleModeState",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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
            (char *)"bAlignedState",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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
            (char *)"bFireAuthorizedState",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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
            (char *)"bAssignedState",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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
            (char *)"bFiringState",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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
            (char *)"byAimingMode",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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
            (char *)"bFuzeSetter",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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
            (char *)"nInventoryInfo",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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
            (char *)"dAngle",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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
            (char *)"fTimeOfFlight",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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
            (char *)"dTellbackMuzzleVelocity",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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
            (char *)"dTellbackPropellantsTemp",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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
            (char *)"dTellbackRatateAngle",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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
            (char *)"dTellbackElevation",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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

    static DDS_TypeCode DMSG_GUN_STATE_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_GUN_STATE", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        19, /* Number of members */
        DMSG_GUN_STATE_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_GUN_STATE*/

    if (is_initialized) {
        return &DMSG_GUN_STATE_g_tc;
    }


    DMSG_GUN_STATE_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_GUN_STATE_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_GUN_STATE_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_GUN_STATE_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_GUN_STATE_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_GUN_STATE_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_GUN_STATE_g_tc_members[6]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_GUN_STATE_g_tc_members[7]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_GUN_STATE_g_tc_members[8]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_GUN_STATE_g_tc_members[9]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_GUN_STATE_g_tc_members[10]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_GUN_STATE_g_tc_members[11]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;
    DMSG_GUN_STATE_g_tc_members[12]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_GUN_STATE_g_tc_members[13]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_GUN_STATE_g_tc_members[14]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;
    DMSG_GUN_STATE_g_tc_members[15]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_GUN_STATE_g_tc_members[16]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_GUN_STATE_g_tc_members[17]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_GUN_STATE_g_tc_members[18]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;

    is_initialized = RTI_TRUE;

    return &DMSG_GUN_STATE_g_tc;
}


RTIBool DMSG_GUN_STATE_initialize(
    DMSG_GUN_STATE* sample) {
  return DMSG_GUN_STATE_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_GUN_STATE_initialize_ex(
    DMSG_GUN_STATE* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initChar(&sample->bMotorState)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->bControlMode)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->bGunState)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->bServerState)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->bAngleModeState)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->bAlignedState)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->bFireAuthorizedState)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->bAssignedState)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->bFiringState)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->byAimingMode)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->bFuzeSetter)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initUnsignedLong(&sample->nInventoryInfo)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dAngle)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dElevation)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initFloat(&sample->fTimeOfFlight)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dTellbackMuzzleVelocity)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dTellbackPropellantsTemp)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dTellbackRatateAngle)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dTellbackElevation)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_GUN_STATE_finalize(
    DMSG_GUN_STATE* sample)
{
    DMSG_GUN_STATE_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_GUN_STATE_finalize_ex(
    DMSG_GUN_STATE* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_GUN_STATE_copy(
    DMSG_GUN_STATE* dst,
    const DMSG_GUN_STATE* src)
{        

    if (!RTICdrType_copyChar(
        &dst->bMotorState, &src->bMotorState)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->bControlMode, &src->bControlMode)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->bGunState, &src->bGunState)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->bServerState, &src->bServerState)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->bAngleModeState, &src->bAngleModeState)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->bAlignedState, &src->bAlignedState)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->bFireAuthorizedState, &src->bFireAuthorizedState)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->bAssignedState, &src->bAssignedState)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->bFiringState, &src->bFiringState)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->byAimingMode, &src->byAimingMode)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->bFuzeSetter, &src->bFuzeSetter)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyUnsignedLong(
        &dst->nInventoryInfo, &src->nInventoryInfo)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dAngle, &src->dAngle)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dElevation, &src->dElevation)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyFloat(
        &dst->fTimeOfFlight, &src->fTimeOfFlight)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dTellbackMuzzleVelocity, &src->dTellbackMuzzleVelocity)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dTellbackPropellantsTemp, &src->dTellbackPropellantsTemp)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dTellbackRatateAngle, &src->dTellbackRatateAngle)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dTellbackElevation, &src->dTellbackElevation)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_GUN_STATE' sequence class.
 */
#define T DMSG_GUN_STATE
#define TSeq DMSG_GUN_STATESeq
#define T_initialize_ex DMSG_GUN_STATE_initialize_ex
#define T_finalize_ex   DMSG_GUN_STATE_finalize_ex
#define T_copy       DMSG_GUN_STATE_copy

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

