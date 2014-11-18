
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from DDS_GUNMMI.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Data Distribution Service manual.
*/

#ifndef DDS_GUNMMI_731994764_h
#define DDS_GUNMMI_731994764_h

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

        
extern const char *DMSG_GFC_FIREDATATYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_GFC_FIREDATA
{
    DDS_Double  dAoS;
    DDS_Double  dEle;
    DDS_Double  dAzi;
    DDS_Double  dToF;

} DMSG_GFC_FIREDATA;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_GFC_FIREDATA_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_GFC_FIREDATASeq, DMSG_GFC_FIREDATA);
        
NDDSUSERDllExport
RTIBool DMSG_GFC_FIREDATA_initialize(
        DMSG_GFC_FIREDATA* self);
        
NDDSUSERDllExport
RTIBool DMSG_GFC_FIREDATA_initialize_ex(
        DMSG_GFC_FIREDATA* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_GFC_FIREDATA_finalize(
        DMSG_GFC_FIREDATA* self);
                        
NDDSUSERDllExport
void DMSG_GFC_FIREDATA_finalize_ex(
        DMSG_GFC_FIREDATA* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_GFC_FIREDATA_copy(
        DMSG_GFC_FIREDATA* dst,
        const DMSG_GFC_FIREDATA* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_EC_FIRINGCMDTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_EC_FIRINGCMD
{
    DDS_Char  command;

} DMSG_EC_FIRINGCMD;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_EC_FIRINGCMD_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_EC_FIRINGCMDSeq, DMSG_EC_FIRINGCMD);
        
NDDSUSERDllExport
RTIBool DMSG_EC_FIRINGCMD_initialize(
        DMSG_EC_FIRINGCMD* self);
        
NDDSUSERDllExport
RTIBool DMSG_EC_FIRINGCMD_initialize_ex(
        DMSG_EC_FIRINGCMD* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_EC_FIRINGCMD_finalize(
        DMSG_EC_FIRINGCMD* self);
                        
NDDSUSERDllExport
void DMSG_EC_FIRINGCMD_finalize_ex(
        DMSG_EC_FIRINGCMD* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_EC_FIRINGCMD_copy(
        DMSG_EC_FIRINGCMD* dst,
        const DMSG_EC_FIRINGCMD* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_GFC_HITEXPECTTYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_GFC_HITEXPECT
{
    DDS_Double  dPosX;
    DDS_Double  dPosY;
    DDS_Double  dPosZ;

} DMSG_GFC_HITEXPECT;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_GFC_HITEXPECT_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_GFC_HITEXPECTSeq, DMSG_GFC_HITEXPECT);
        
NDDSUSERDllExport
RTIBool DMSG_GFC_HITEXPECT_initialize(
        DMSG_GFC_HITEXPECT* self);
        
NDDSUSERDllExport
RTIBool DMSG_GFC_HITEXPECT_initialize_ex(
        DMSG_GFC_HITEXPECT* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_GFC_HITEXPECT_finalize(
        DMSG_GFC_HITEXPECT* self);
                        
NDDSUSERDllExport
void DMSG_GFC_HITEXPECT_finalize_ex(
        DMSG_GFC_HITEXPECT* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_GFC_HITEXPECT_copy(
        DMSG_GFC_HITEXPECT* dst,
        const DMSG_GFC_HITEXPECT* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *DMSG_GUN_STATETYPENAME;
        

#ifdef __cplusplus
}
#endif

typedef struct DMSG_GUN_STATE
{
    DDS_Char  bMotorState;
    DDS_Char  bControlMode;
    DDS_Char  bGunState;
    DDS_Char  bServerState;
    DDS_Char  bAngleModeState;
    DDS_Char  bAlignedState;
    DDS_Char  bFireAuthorizedState;
    DDS_Char  bAssignedState;
    DDS_Char  bFiringState;
    DDS_Char  byAimingMode;
    DDS_Char  bFuzeSetter;
    DDS_UnsignedLong  nInventoryInfo;
    DDS_Double  dAngle;
    DDS_Double  dElevation;
    DDS_Float  fTimeOfFlight;
    DDS_Double  dTellbackMuzzleVelocity;
    DDS_Double  dTellbackPropellantsTemp;
    DDS_Double  dTellbackRatateAngle;
    DDS_Double  dTellbackElevation;

} DMSG_GUN_STATE;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* DMSG_GUN_STATE_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(DMSG_GUN_STATESeq, DMSG_GUN_STATE);
        
NDDSUSERDllExport
RTIBool DMSG_GUN_STATE_initialize(
        DMSG_GUN_STATE* self);
        
NDDSUSERDllExport
RTIBool DMSG_GUN_STATE_initialize_ex(
        DMSG_GUN_STATE* self,RTIBool allocatePointers);

NDDSUSERDllExport
void DMSG_GUN_STATE_finalize(
        DMSG_GUN_STATE* self);
                        
NDDSUSERDllExport
void DMSG_GUN_STATE_finalize_ex(
        DMSG_GUN_STATE* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool DMSG_GUN_STATE_copy(
        DMSG_GUN_STATE* dst,
        const DMSG_GUN_STATE* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif



#endif /* DDS_GUNMMI_731994764_h */
