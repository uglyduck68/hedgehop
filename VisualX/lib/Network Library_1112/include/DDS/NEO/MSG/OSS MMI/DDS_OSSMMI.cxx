
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from DDS_OSSMMI.idl using "rtiddsgen".
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



#include "DDS_OSSMMI.h"

/* ========================================================================= */
const char *DMSG_OSSMMI_SENSORSTATETYPENAME = "DMSG_OSSMMI_SENSORSTATE";

DDS_TypeCode* DMSG_OSSMMI_SENSORSTATE_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_OSSMMI_SENSORSTATE_g_tc_members[5]=
    {
        {
            (char *)"gpsStatus",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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
            (char *)"gyroStatus",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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
            (char *)"emLogStatus",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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
            (char *)"anemometerStatus",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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
            (char *)"airStatus",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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

    static DDS_TypeCode DMSG_OSSMMI_SENSORSTATE_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_OSSMMI_SENSORSTATE", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        5, /* Number of members */
        DMSG_OSSMMI_SENSORSTATE_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_OSSMMI_SENSORSTATE*/

    if (is_initialized) {
        return &DMSG_OSSMMI_SENSORSTATE_g_tc;
    }


    DMSG_OSSMMI_SENSORSTATE_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_OSSMMI_SENSORSTATE_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_OSSMMI_SENSORSTATE_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_OSSMMI_SENSORSTATE_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_OSSMMI_SENSORSTATE_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;

    is_initialized = RTI_TRUE;

    return &DMSG_OSSMMI_SENSORSTATE_g_tc;
}


RTIBool DMSG_OSSMMI_SENSORSTATE_initialize(
    DMSG_OSSMMI_SENSORSTATE* sample) {
  return DMSG_OSSMMI_SENSORSTATE_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_OSSMMI_SENSORSTATE_initialize_ex(
    DMSG_OSSMMI_SENSORSTATE* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initChar(&sample->gpsStatus)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->gyroStatus)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->emLogStatus)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->anemometerStatus)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->airStatus)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_OSSMMI_SENSORSTATE_finalize(
    DMSG_OSSMMI_SENSORSTATE* sample)
{
    DMSG_OSSMMI_SENSORSTATE_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_OSSMMI_SENSORSTATE_finalize_ex(
    DMSG_OSSMMI_SENSORSTATE* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_OSSMMI_SENSORSTATE_copy(
    DMSG_OSSMMI_SENSORSTATE* dst,
    const DMSG_OSSMMI_SENSORSTATE* src)
{        

    if (!RTICdrType_copyChar(
        &dst->gpsStatus, &src->gpsStatus)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->gyroStatus, &src->gyroStatus)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->emLogStatus, &src->emLogStatus)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->anemometerStatus, &src->anemometerStatus)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->airStatus, &src->airStatus)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_OSSMMI_SENSORSTATE' sequence class.
 */
#define T DMSG_OSSMMI_SENSORSTATE
#define TSeq DMSG_OSSMMI_SENSORSTATESeq
#define T_initialize_ex DMSG_OSSMMI_SENSORSTATE_initialize_ex
#define T_finalize_ex   DMSG_OSSMMI_SENSORSTATE_finalize_ex
#define T_copy       DMSG_OSSMMI_SENSORSTATE_copy

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
const char *DMSG_OSSMMI_GPSTYPENAME = "DMSG_OSSMMI_GPS";

DDS_TypeCode* DMSG_OSSMMI_GPS_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_OSSMMI_GPS_g_tc_members[6]=
    {
        {
            (char *)"latitude",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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
            (char *)"longitude",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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
            (char *)"year",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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
            (char *)"month",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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
            (char *)"day",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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
            (char *)"sec",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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

    static DDS_TypeCode DMSG_OSSMMI_GPS_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_OSSMMI_GPS", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        6, /* Number of members */
        DMSG_OSSMMI_GPS_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_OSSMMI_GPS*/

    if (is_initialized) {
        return &DMSG_OSSMMI_GPS_g_tc;
    }


    DMSG_OSSMMI_GPS_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_OSSMMI_GPS_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_OSSMMI_GPS_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;
    DMSG_OSSMMI_GPS_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_OSSMMI_GPS_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;
    DMSG_OSSMMI_GPS_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;

    is_initialized = RTI_TRUE;

    return &DMSG_OSSMMI_GPS_g_tc;
}


RTIBool DMSG_OSSMMI_GPS_initialize(
    DMSG_OSSMMI_GPS* sample) {
  return DMSG_OSSMMI_GPS_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_OSSMMI_GPS_initialize_ex(
    DMSG_OSSMMI_GPS* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initDouble(&sample->latitude)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->longitude)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initUnsignedShort(&sample->year)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->month)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initChar(&sample->day)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initUnsignedLong(&sample->sec)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_OSSMMI_GPS_finalize(
    DMSG_OSSMMI_GPS* sample)
{
    DMSG_OSSMMI_GPS_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_OSSMMI_GPS_finalize_ex(
    DMSG_OSSMMI_GPS* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_OSSMMI_GPS_copy(
    DMSG_OSSMMI_GPS* dst,
    const DMSG_OSSMMI_GPS* src)
{        

    if (!RTICdrType_copyDouble(
        &dst->latitude, &src->latitude)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->longitude, &src->longitude)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyUnsignedShort(
        &dst->year, &src->year)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->month, &src->month)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyChar(
        &dst->day, &src->day)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyUnsignedLong(
        &dst->sec, &src->sec)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_OSSMMI_GPS' sequence class.
 */
#define T DMSG_OSSMMI_GPS
#define TSeq DMSG_OSSMMI_GPSSeq
#define T_initialize_ex DMSG_OSSMMI_GPS_initialize_ex
#define T_finalize_ex   DMSG_OSSMMI_GPS_finalize_ex
#define T_copy       DMSG_OSSMMI_GPS_copy

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
const char *DMSG_OSSMMI_GYROTYPENAME = "DMSG_OSSMMI_GYRO";

DDS_TypeCode* DMSG_OSSMMI_GYRO_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_OSSMMI_GYRO_g_tc_members[6]=
    {
        {
            (char *)"heading",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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
            (char *)"roll",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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
            (char *)"pitch",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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
            (char *)"rate_heading",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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
            (char *)"rate_roll",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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
            (char *)"rate_pitch",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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

    static DDS_TypeCode DMSG_OSSMMI_GYRO_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_OSSMMI_GYRO", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        6, /* Number of members */
        DMSG_OSSMMI_GYRO_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_OSSMMI_GYRO*/

    if (is_initialized) {
        return &DMSG_OSSMMI_GYRO_g_tc;
    }


    DMSG_OSSMMI_GYRO_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_OSSMMI_GYRO_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_OSSMMI_GYRO_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_OSSMMI_GYRO_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    DMSG_OSSMMI_GYRO_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    DMSG_OSSMMI_GYRO_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

    is_initialized = RTI_TRUE;

    return &DMSG_OSSMMI_GYRO_g_tc;
}


RTIBool DMSG_OSSMMI_GYRO_initialize(
    DMSG_OSSMMI_GYRO* sample) {
  return DMSG_OSSMMI_GYRO_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_OSSMMI_GYRO_initialize_ex(
    DMSG_OSSMMI_GYRO* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initDouble(&sample->heading)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->roll)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->pitch)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initLong(&sample->rate_heading)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initLong(&sample->rate_roll)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initLong(&sample->rate_pitch)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_OSSMMI_GYRO_finalize(
    DMSG_OSSMMI_GYRO* sample)
{
    DMSG_OSSMMI_GYRO_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_OSSMMI_GYRO_finalize_ex(
    DMSG_OSSMMI_GYRO* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_OSSMMI_GYRO_copy(
    DMSG_OSSMMI_GYRO* dst,
    const DMSG_OSSMMI_GYRO* src)
{        

    if (!RTICdrType_copyDouble(
        &dst->heading, &src->heading)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->roll, &src->roll)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->pitch, &src->pitch)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyLong(
        &dst->rate_heading, &src->rate_heading)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyLong(
        &dst->rate_roll, &src->rate_roll)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyLong(
        &dst->rate_pitch, &src->rate_pitch)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_OSSMMI_GYRO' sequence class.
 */
#define T DMSG_OSSMMI_GYRO
#define TSeq DMSG_OSSMMI_GYROSeq
#define T_initialize_ex DMSG_OSSMMI_GYRO_initialize_ex
#define T_finalize_ex   DMSG_OSSMMI_GYRO_finalize_ex
#define T_copy       DMSG_OSSMMI_GYRO_copy

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
const char *DMSG_OSSMMI_EMLOGTYPENAME = "DMSG_OSSMMI_EMLOG";

DDS_TypeCode* DMSG_OSSMMI_EMLOG_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_OSSMMI_EMLOG_g_tc_members[6]=
    {
        {
            (char *)"velocity_north",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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
            (char *)"velocity_east",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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
            (char *)"velocity_down",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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
            (char *)"accel_nort",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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
            (char *)"accel_east",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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
            (char *)"accel_down",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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

    static DDS_TypeCode DMSG_OSSMMI_EMLOG_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_OSSMMI_EMLOG", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        6, /* Number of members */
        DMSG_OSSMMI_EMLOG_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_OSSMMI_EMLOG*/

    if (is_initialized) {
        return &DMSG_OSSMMI_EMLOG_g_tc;
    }


    DMSG_OSSMMI_EMLOG_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_OSSMMI_EMLOG_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_OSSMMI_EMLOG_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_OSSMMI_EMLOG_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_OSSMMI_EMLOG_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_OSSMMI_EMLOG_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;

    is_initialized = RTI_TRUE;

    return &DMSG_OSSMMI_EMLOG_g_tc;
}


RTIBool DMSG_OSSMMI_EMLOG_initialize(
    DMSG_OSSMMI_EMLOG* sample) {
  return DMSG_OSSMMI_EMLOG_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_OSSMMI_EMLOG_initialize_ex(
    DMSG_OSSMMI_EMLOG* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initDouble(&sample->velocity_north)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->velocity_east)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->velocity_down)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->accel_nort)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->accel_east)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->accel_down)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_OSSMMI_EMLOG_finalize(
    DMSG_OSSMMI_EMLOG* sample)
{
    DMSG_OSSMMI_EMLOG_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_OSSMMI_EMLOG_finalize_ex(
    DMSG_OSSMMI_EMLOG* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_OSSMMI_EMLOG_copy(
    DMSG_OSSMMI_EMLOG* dst,
    const DMSG_OSSMMI_EMLOG* src)
{        

    if (!RTICdrType_copyDouble(
        &dst->velocity_north, &src->velocity_north)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->velocity_east, &src->velocity_east)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->velocity_down, &src->velocity_down)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->accel_nort, &src->accel_nort)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->accel_east, &src->accel_east)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->accel_down, &src->accel_down)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_OSSMMI_EMLOG' sequence class.
 */
#define T DMSG_OSSMMI_EMLOG
#define TSeq DMSG_OSSMMI_EMLOGSeq
#define T_initialize_ex DMSG_OSSMMI_EMLOG_initialize_ex
#define T_finalize_ex   DMSG_OSSMMI_EMLOG_finalize_ex
#define T_copy       DMSG_OSSMMI_EMLOG_copy

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
const char *DMSG_OSSMMI_WINDTYPENAME = "DMSG_OSSMMI_WIND";

DDS_TypeCode* DMSG_OSSMMI_WIND_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_OSSMMI_WIND_g_tc_members[2]=
    {
        {
            (char *)"wind_direction",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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
            (char *)"wind_speed",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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

    static DDS_TypeCode DMSG_OSSMMI_WIND_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_OSSMMI_WIND", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        2, /* Number of members */
        DMSG_OSSMMI_WIND_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_OSSMMI_WIND*/

    if (is_initialized) {
        return &DMSG_OSSMMI_WIND_g_tc;
    }


    DMSG_OSSMMI_WIND_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;
    DMSG_OSSMMI_WIND_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    is_initialized = RTI_TRUE;

    return &DMSG_OSSMMI_WIND_g_tc;
}


RTIBool DMSG_OSSMMI_WIND_initialize(
    DMSG_OSSMMI_WIND* sample) {
  return DMSG_OSSMMI_WIND_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_OSSMMI_WIND_initialize_ex(
    DMSG_OSSMMI_WIND* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initFloat(&sample->wind_direction)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initFloat(&sample->wind_speed)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_OSSMMI_WIND_finalize(
    DMSG_OSSMMI_WIND* sample)
{
    DMSG_OSSMMI_WIND_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_OSSMMI_WIND_finalize_ex(
    DMSG_OSSMMI_WIND* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_OSSMMI_WIND_copy(
    DMSG_OSSMMI_WIND* dst,
    const DMSG_OSSMMI_WIND* src)
{        

    if (!RTICdrType_copyFloat(
        &dst->wind_direction, &src->wind_direction)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyFloat(
        &dst->wind_speed, &src->wind_speed)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_OSSMMI_WIND' sequence class.
 */
#define T DMSG_OSSMMI_WIND
#define TSeq DMSG_OSSMMI_WINDSeq
#define T_initialize_ex DMSG_OSSMMI_WIND_initialize_ex
#define T_finalize_ex   DMSG_OSSMMI_WIND_finalize_ex
#define T_copy       DMSG_OSSMMI_WIND_copy

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
const char *DMSG_OSSMMI_TEMPTYPENAME = "DMSG_OSSMMI_TEMP";

DDS_TypeCode* DMSG_OSSMMI_TEMP_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_OSSMMI_TEMP_g_tc_members[3]=
    {
        {
            (char *)"temp",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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
            (char *)"pressure",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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
            (char *)"humidity",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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

    static DDS_TypeCode DMSG_OSSMMI_TEMP_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_OSSMMI_TEMP", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        3, /* Number of members */
        DMSG_OSSMMI_TEMP_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_OSSMMI_TEMP*/

    if (is_initialized) {
        return &DMSG_OSSMMI_TEMP_g_tc;
    }


    DMSG_OSSMMI_TEMP_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;
    DMSG_OSSMMI_TEMP_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;
    DMSG_OSSMMI_TEMP_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    is_initialized = RTI_TRUE;

    return &DMSG_OSSMMI_TEMP_g_tc;
}


RTIBool DMSG_OSSMMI_TEMP_initialize(
    DMSG_OSSMMI_TEMP* sample) {
  return DMSG_OSSMMI_TEMP_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_OSSMMI_TEMP_initialize_ex(
    DMSG_OSSMMI_TEMP* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initFloat(&sample->temp)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initFloat(&sample->pressure)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initFloat(&sample->humidity)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_OSSMMI_TEMP_finalize(
    DMSG_OSSMMI_TEMP* sample)
{
    DMSG_OSSMMI_TEMP_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_OSSMMI_TEMP_finalize_ex(
    DMSG_OSSMMI_TEMP* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_OSSMMI_TEMP_copy(
    DMSG_OSSMMI_TEMP* dst,
    const DMSG_OSSMMI_TEMP* src)
{        

    if (!RTICdrType_copyFloat(
        &dst->temp, &src->temp)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyFloat(
        &dst->pressure, &src->pressure)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyFloat(
        &dst->humidity, &src->humidity)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_OSSMMI_TEMP' sequence class.
 */
#define T DMSG_OSSMMI_TEMP
#define TSeq DMSG_OSSMMI_TEMPSeq
#define T_initialize_ex DMSG_OSSMMI_TEMP_initialize_ex
#define T_finalize_ex   DMSG_OSSMMI_TEMP_finalize_ex
#define T_copy       DMSG_OSSMMI_TEMP_copy

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
const char *DMSG_OSSMMI_ECHOTYPENAME = "DMSG_OSSMMI_ECHO";

DDS_TypeCode* DMSG_OSSMMI_ECHO_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_OSSMMI_ECHO_g_tc_members[2]=
    {
        {
            (char *)"dWaterDepth",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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
            (char *)"dDivingDepth",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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

    static DDS_TypeCode DMSG_OSSMMI_ECHO_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_OSSMMI_ECHO", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        2, /* Number of members */
        DMSG_OSSMMI_ECHO_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_OSSMMI_ECHO*/

    if (is_initialized) {
        return &DMSG_OSSMMI_ECHO_g_tc;
    }


    DMSG_OSSMMI_ECHO_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    DMSG_OSSMMI_ECHO_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;

    is_initialized = RTI_TRUE;

    return &DMSG_OSSMMI_ECHO_g_tc;
}


RTIBool DMSG_OSSMMI_ECHO_initialize(
    DMSG_OSSMMI_ECHO* sample) {
  return DMSG_OSSMMI_ECHO_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_OSSMMI_ECHO_initialize_ex(
    DMSG_OSSMMI_ECHO* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initDouble(&sample->dWaterDepth)) {
        return RTI_FALSE;
    }                
            
    if (!RTICdrType_initDouble(&sample->dDivingDepth)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_OSSMMI_ECHO_finalize(
    DMSG_OSSMMI_ECHO* sample)
{
    DMSG_OSSMMI_ECHO_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_OSSMMI_ECHO_finalize_ex(
    DMSG_OSSMMI_ECHO* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_OSSMMI_ECHO_copy(
    DMSG_OSSMMI_ECHO* dst,
    const DMSG_OSSMMI_ECHO* src)
{        

    if (!RTICdrType_copyDouble(
        &dst->dWaterDepth, &src->dWaterDepth)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyDouble(
        &dst->dDivingDepth, &src->dDivingDepth)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_OSSMMI_ECHO' sequence class.
 */
#define T DMSG_OSSMMI_ECHO
#define TSeq DMSG_OSSMMI_ECHOSeq
#define T_initialize_ex DMSG_OSSMMI_ECHO_initialize_ex
#define T_finalize_ex   DMSG_OSSMMI_ECHO_finalize_ex
#define T_copy       DMSG_OSSMMI_ECHO_copy

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
const char *DMSG_OSSMMI_PLATFORMTYPENAME = "DMSG_OSSMMI_PLATFORM";

DDS_TypeCode* DMSG_OSSMMI_PLATFORM_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_OSSMMI_PLATFORM_g_tc_members[1]=
    {
        {
            (char *)"byPlatform",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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

    static DDS_TypeCode DMSG_OSSMMI_PLATFORM_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_OSSMMI_PLATFORM", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        1, /* Number of members */
        DMSG_OSSMMI_PLATFORM_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_OSSMMI_PLATFORM*/

    if (is_initialized) {
        return &DMSG_OSSMMI_PLATFORM_g_tc;
    }


    DMSG_OSSMMI_PLATFORM_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;

    is_initialized = RTI_TRUE;

    return &DMSG_OSSMMI_PLATFORM_g_tc;
}


RTIBool DMSG_OSSMMI_PLATFORM_initialize(
    DMSG_OSSMMI_PLATFORM* sample) {
  return DMSG_OSSMMI_PLATFORM_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_OSSMMI_PLATFORM_initialize_ex(
    DMSG_OSSMMI_PLATFORM* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initChar(&sample->byPlatform)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_OSSMMI_PLATFORM_finalize(
    DMSG_OSSMMI_PLATFORM* sample)
{
    DMSG_OSSMMI_PLATFORM_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_OSSMMI_PLATFORM_finalize_ex(
    DMSG_OSSMMI_PLATFORM* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_OSSMMI_PLATFORM_copy(
    DMSG_OSSMMI_PLATFORM* dst,
    const DMSG_OSSMMI_PLATFORM* src)
{        

    if (!RTICdrType_copyChar(
        &dst->byPlatform, &src->byPlatform)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_OSSMMI_PLATFORM' sequence class.
 */
#define T DMSG_OSSMMI_PLATFORM
#define TSeq DMSG_OSSMMI_PLATFORMSeq
#define T_initialize_ex DMSG_OSSMMI_PLATFORM_initialize_ex
#define T_finalize_ex   DMSG_OSSMMI_PLATFORM_finalize_ex
#define T_copy       DMSG_OSSMMI_PLATFORM_copy

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
const char *DMSG_OSSMMI_PLATFORMREQTYPENAME = "DMSG_OSSMMI_PLATFORMREQ";

DDS_TypeCode* DMSG_OSSMMI_PLATFORMREQ_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;


    static DDS_TypeCode_Member DMSG_OSSMMI_PLATFORMREQ_g_tc_members[1]=
    {
        {
            (char *)"byPlatformReq",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
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

    static DDS_TypeCode DMSG_OSSMMI_PLATFORMREQ_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"DMSG_OSSMMI_PLATFORMREQ", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        1, /* Number of members */
        DMSG_OSSMMI_PLATFORMREQ_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for DMSG_OSSMMI_PLATFORMREQ*/

    if (is_initialized) {
        return &DMSG_OSSMMI_PLATFORMREQ_g_tc;
    }


    DMSG_OSSMMI_PLATFORMREQ_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_char;

    is_initialized = RTI_TRUE;

    return &DMSG_OSSMMI_PLATFORMREQ_g_tc;
}


RTIBool DMSG_OSSMMI_PLATFORMREQ_initialize(
    DMSG_OSSMMI_PLATFORMREQ* sample) {
  return DMSG_OSSMMI_PLATFORMREQ_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool DMSG_OSSMMI_PLATFORMREQ_initialize_ex(
    DMSG_OSSMMI_PLATFORMREQ* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initChar(&sample->byPlatformReq)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void DMSG_OSSMMI_PLATFORMREQ_finalize(
    DMSG_OSSMMI_PLATFORMREQ* sample)
{
    DMSG_OSSMMI_PLATFORMREQ_finalize_ex(sample,RTI_TRUE);
}
        
void DMSG_OSSMMI_PLATFORMREQ_finalize_ex(
    DMSG_OSSMMI_PLATFORMREQ* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


}

RTIBool DMSG_OSSMMI_PLATFORMREQ_copy(
    DMSG_OSSMMI_PLATFORMREQ* dst,
    const DMSG_OSSMMI_PLATFORMREQ* src)
{        

    if (!RTICdrType_copyChar(
        &dst->byPlatformReq, &src->byPlatformReq)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'DMSG_OSSMMI_PLATFORMREQ' sequence class.
 */
#define T DMSG_OSSMMI_PLATFORMREQ
#define TSeq DMSG_OSSMMI_PLATFORMREQSeq
#define T_initialize_ex DMSG_OSSMMI_PLATFORMREQ_initialize_ex
#define T_finalize_ex   DMSG_OSSMMI_PLATFORMREQ_finalize_ex
#define T_copy       DMSG_OSSMMI_PLATFORMREQ_copy

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

