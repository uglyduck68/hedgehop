
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from DDS_OSSMMI.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Data Distribution Service manual.
*/

#ifndef DDS_OSSMMI_1396059854_h
#define DDS_OSSMMI_1396059854_h

#ifndef NDDS_STANDALONE_TYPE
    #ifdef __cplusplus
        #ifndef ndds_cpp_h
            #include "ndds/ndds_cpp.h"
        #endif
    #else
        #ifndef ndds_c_h
            #include "ndds/ndds_c.h"
        #endif
    #endif
#else
    #include "ndds_standalone_type.h"
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_OSSMMI_SENSORSTATETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_OSSMMI_SENSORSTATE
{
    DDS_Char  gpsStatus;
    DDS_Char  gyroStatus;
    DDS_Char  emLogStatus;
    DDS_Char  anemometerStatus;
    DDS_Char  airStatus;

} DMSG_OSSMMI_SENSORSTATE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_OSSMMI_SENSORSTATE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_OSSMMI_SENSORSTATESeq, DMSG_OSSMMI_SENSORSTATE);
        
NDDSUSERDllExport
RTIBool DMSG_OSSMMI_SENSORSTATE_initialize(
        DMSG_OSSMMI_SENSORSTATE* self);
        
NDDSUSERDllExport
RTIBool DMSG_OSSMMI_SENSORSTATE_initialize_ex(
        DMSG_OSSMMI_SENSORSTATE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_OSSMMI_SENSORSTATE_finalize(
        DMSG_OSSMMI_SENSORSTATE* self);
                        
NDDSUSERDllExport
void DMSG_OSSMMI_SENSORSTATE_finalize_ex(
        DMSG_OSSMMI_SENSORSTATE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_OSSMMI_SENSORSTATE_copy(
        DMSG_OSSMMI_SENSORSTATE* dst,
        const DMSG_OSSMMI_SENSORSTATE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_OSSMMI_GPSTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_OSSMMI_GPS
{
    DDS_Double  latitude;
    DDS_Double  longitude;
    DDS_UnsignedShort  year;
    DDS_Char  month;
    DDS_Char  day;
    DDS_UnsignedLong  sec;

} DMSG_OSSMMI_GPS;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_OSSMMI_GPS_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_OSSMMI_GPSSeq, DMSG_OSSMMI_GPS);
        
NDDSUSERDllExport
RTIBool DMSG_OSSMMI_GPS_initialize(
        DMSG_OSSMMI_GPS* self);
        
NDDSUSERDllExport
RTIBool DMSG_OSSMMI_GPS_initialize_ex(
        DMSG_OSSMMI_GPS* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_OSSMMI_GPS_finalize(
        DMSG_OSSMMI_GPS* self);
                        
NDDSUSERDllExport
void DMSG_OSSMMI_GPS_finalize_ex(
        DMSG_OSSMMI_GPS* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_OSSMMI_GPS_copy(
        DMSG_OSSMMI_GPS* dst,
        const DMSG_OSSMMI_GPS* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_OSSMMI_GYROTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_OSSMMI_GYRO
{
    DDS_Double  heading;
    DDS_Double  roll;
    DDS_Double  pitch;
    DDS_Long  rate_heading;
    DDS_Long  rate_roll;
    DDS_Long  rate_pitch;

} DMSG_OSSMMI_GYRO;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_OSSMMI_GYRO_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_OSSMMI_GYROSeq, DMSG_OSSMMI_GYRO);
        
NDDSUSERDllExport
RTIBool DMSG_OSSMMI_GYRO_initialize(
        DMSG_OSSMMI_GYRO* self);
        
NDDSUSERDllExport
RTIBool DMSG_OSSMMI_GYRO_initialize_ex(
        DMSG_OSSMMI_GYRO* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_OSSMMI_GYRO_finalize(
        DMSG_OSSMMI_GYRO* self);
                        
NDDSUSERDllExport
void DMSG_OSSMMI_GYRO_finalize_ex(
        DMSG_OSSMMI_GYRO* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_OSSMMI_GYRO_copy(
        DMSG_OSSMMI_GYRO* dst,
        const DMSG_OSSMMI_GYRO* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_OSSMMI_EMLOGTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_OSSMMI_EMLOG
{
    DDS_Double  velocity_north;
    DDS_Double  velocity_east;
    DDS_Double  velocity_down;
    DDS_Double  accel_nort;
    DDS_Double  accel_east;
    DDS_Double  accel_down;

} DMSG_OSSMMI_EMLOG;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_OSSMMI_EMLOG_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_OSSMMI_EMLOGSeq, DMSG_OSSMMI_EMLOG);
        
NDDSUSERDllExport
RTIBool DMSG_OSSMMI_EMLOG_initialize(
        DMSG_OSSMMI_EMLOG* self);
        
NDDSUSERDllExport
RTIBool DMSG_OSSMMI_EMLOG_initialize_ex(
        DMSG_OSSMMI_EMLOG* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_OSSMMI_EMLOG_finalize(
        DMSG_OSSMMI_EMLOG* self);
                        
NDDSUSERDllExport
void DMSG_OSSMMI_EMLOG_finalize_ex(
        DMSG_OSSMMI_EMLOG* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_OSSMMI_EMLOG_copy(
        DMSG_OSSMMI_EMLOG* dst,
        const DMSG_OSSMMI_EMLOG* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_OSSMMI_WINDTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_OSSMMI_WIND
{
    DDS_Float  wind_direction;
    DDS_Float  wind_speed;

} DMSG_OSSMMI_WIND;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_OSSMMI_WIND_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_OSSMMI_WINDSeq, DMSG_OSSMMI_WIND);
        
NDDSUSERDllExport
RTIBool DMSG_OSSMMI_WIND_initialize(
        DMSG_OSSMMI_WIND* self);
        
NDDSUSERDllExport
RTIBool DMSG_OSSMMI_WIND_initialize_ex(
        DMSG_OSSMMI_WIND* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_OSSMMI_WIND_finalize(
        DMSG_OSSMMI_WIND* self);
                        
NDDSUSERDllExport
void DMSG_OSSMMI_WIND_finalize_ex(
        DMSG_OSSMMI_WIND* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_OSSMMI_WIND_copy(
        DMSG_OSSMMI_WIND* dst,
        const DMSG_OSSMMI_WIND* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_OSSMMI_TEMPTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_OSSMMI_TEMP
{
    DDS_Float  temp;
    DDS_Float  pressure;
    DDS_Float  humidity;

} DMSG_OSSMMI_TEMP;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_OSSMMI_TEMP_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_OSSMMI_TEMPSeq, DMSG_OSSMMI_TEMP);
        
NDDSUSERDllExport
RTIBool DMSG_OSSMMI_TEMP_initialize(
        DMSG_OSSMMI_TEMP* self);
        
NDDSUSERDllExport
RTIBool DMSG_OSSMMI_TEMP_initialize_ex(
        DMSG_OSSMMI_TEMP* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_OSSMMI_TEMP_finalize(
        DMSG_OSSMMI_TEMP* self);
                        
NDDSUSERDllExport
void DMSG_OSSMMI_TEMP_finalize_ex(
        DMSG_OSSMMI_TEMP* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_OSSMMI_TEMP_copy(
        DMSG_OSSMMI_TEMP* dst,
        const DMSG_OSSMMI_TEMP* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_OSSMMI_ECHOTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_OSSMMI_ECHO
{
    DDS_Double  dWaterDepth;
    DDS_Double  dDivingDepth;

} DMSG_OSSMMI_ECHO;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_OSSMMI_ECHO_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_OSSMMI_ECHOSeq, DMSG_OSSMMI_ECHO);
        
NDDSUSERDllExport
RTIBool DMSG_OSSMMI_ECHO_initialize(
        DMSG_OSSMMI_ECHO* self);
        
NDDSUSERDllExport
RTIBool DMSG_OSSMMI_ECHO_initialize_ex(
        DMSG_OSSMMI_ECHO* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_OSSMMI_ECHO_finalize(
        DMSG_OSSMMI_ECHO* self);
                        
NDDSUSERDllExport
void DMSG_OSSMMI_ECHO_finalize_ex(
        DMSG_OSSMMI_ECHO* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_OSSMMI_ECHO_copy(
        DMSG_OSSMMI_ECHO* dst,
        const DMSG_OSSMMI_ECHO* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_OSSMMI_PLATFORMTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_OSSMMI_PLATFORM
{
    DDS_Char  byPlatform;

} DMSG_OSSMMI_PLATFORM;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_OSSMMI_PLATFORM_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_OSSMMI_PLATFORMSeq, DMSG_OSSMMI_PLATFORM);
        
NDDSUSERDllExport
RTIBool DMSG_OSSMMI_PLATFORM_initialize(
        DMSG_OSSMMI_PLATFORM* self);
        
NDDSUSERDllExport
RTIBool DMSG_OSSMMI_PLATFORM_initialize_ex(
        DMSG_OSSMMI_PLATFORM* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_OSSMMI_PLATFORM_finalize(
        DMSG_OSSMMI_PLATFORM* self);
                        
NDDSUSERDllExport
void DMSG_OSSMMI_PLATFORM_finalize_ex(
        DMSG_OSSMMI_PLATFORM* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_OSSMMI_PLATFORM_copy(
        DMSG_OSSMMI_PLATFORM* dst,
        const DMSG_OSSMMI_PLATFORM* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_OSSMMI_PLATFORMREQTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_OSSMMI_PLATFORMREQ
{
    DDS_Char  byPlatformReq;

} DMSG_OSSMMI_PLATFORMREQ;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_OSSMMI_PLATFORMREQ_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_OSSMMI_PLATFORMREQSeq, DMSG_OSSMMI_PLATFORMREQ);
        
NDDSUSERDllExport
RTIBool DMSG_OSSMMI_PLATFORMREQ_initialize(
        DMSG_OSSMMI_PLATFORMREQ* self);
        
NDDSUSERDllExport
RTIBool DMSG_OSSMMI_PLATFORMREQ_initialize_ex(
        DMSG_OSSMMI_PLATFORMREQ* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_OSSMMI_PLATFORMREQ_finalize(
        DMSG_OSSMMI_PLATFORMREQ* self);
                        
NDDSUSERDllExport
void DMSG_OSSMMI_PLATFORMREQ_finalize_ex(
        DMSG_OSSMMI_PLATFORMREQ* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_OSSMMI_PLATFORMREQ_copy(
        DMSG_OSSMMI_PLATFORMREQ* dst,
        const DMSG_OSSMMI_PLATFORMREQ* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif



#endif /* DDS_OSSMMI_1396059854_h */
