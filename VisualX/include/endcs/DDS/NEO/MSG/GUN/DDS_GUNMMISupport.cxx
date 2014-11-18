
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from DDS_GUNMMI.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Data Distribution Service manual.
*/

#include "DDS_GUNMMISupport.h"
#include "DDS_GUNMMIPlugin.h"



#ifdef __cplusplus  
    #ifndef dds_c_log_impl_h              
         #include "dds_c/dds_c_log_impl.h"                                
    #endif        
#endif        




/* ========================================================================= */
/**
   <<IMPLEMENTATION>>

   Defines:   TData,
              TDataWriter,
              TDataReader,
              TTypeSupport

   Configure and implement 'DMSG_GFC_FIREDATA' support classes.

   Note: Only the #defined classes get defined
*/

/* ----------------------------------------------------------------- */
/* DDSDataWriter
*/

/**
  <<IMPLEMENTATION >>

   Defines:   TDataWriter, TData
*/

/* Requires */
#define TTYPENAME   DMSG_GFC_FIREDATATYPENAME

/* Defines */
#define TDataWriter DMSG_GFC_FIREDATADataWriter
#define TData       DMSG_GFC_FIREDATA


#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_data_TDataWriter.gen"
#else
#include "dds_c/generic/dds_c_data_TDataWriter.gen"
#endif


#undef TDataWriter
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* DDSDataReader
*/

/**
  <<IMPLEMENTATION >>

   Defines:   TDataReader, TDataSeq, TData
*/

/* Requires */
#define TTYPENAME   DMSG_GFC_FIREDATATYPENAME

/* Defines */
#define TDataReader DMSG_GFC_FIREDATADataReader
#define TDataSeq    DMSG_GFC_FIREDATASeq
#define TData       DMSG_GFC_FIREDATA


#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_data_TDataReader.gen"
#else
#include "dds_c/generic/dds_c_data_TDataReader.gen"
#endif


#undef TDataReader
#undef TDataSeq
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* TypeSupport

  <<IMPLEMENTATION >>

   Requires:  TTYPENAME,
              TPlugin_new
              TPlugin_delete
   Defines:   TTypeSupport, TData, TDataReader, TDataWriter
*/

/* Requires */
#define TTYPENAME    DMSG_GFC_FIREDATATYPENAME
#define TPlugin_new  DMSG_GFC_FIREDATAPlugin_new
#define TPlugin_delete  DMSG_GFC_FIREDATAPlugin_delete

/* Defines */
#define TTypeSupport DMSG_GFC_FIREDATATypeSupport
#define TData        DMSG_GFC_FIREDATA
#define TDataReader  DMSG_GFC_FIREDATADataReader
#define TDataWriter  DMSG_GFC_FIREDATADataWriter
#ifdef __cplusplus



#include "dds_cpp/generic/dds_cpp_data_TTypeSupport.gen"



#else
#include "dds_c/generic/dds_c_data_TTypeSupport.gen"
#endif
#undef TTypeSupport
#undef TData
#undef TDataReader
#undef TDataWriter

#undef TTYPENAME
#undef TPlugin_new
#undef TPlugin_delete





/* ========================================================================= */
/**
   <<IMPLEMENTATION>>

   Defines:   TData,
              TDataWriter,
              TDataReader,
              TTypeSupport

   Configure and implement 'DMSG_EC_FIRINGCMD' support classes.

   Note: Only the #defined classes get defined
*/

/* ----------------------------------------------------------------- */
/* DDSDataWriter
*/

/**
  <<IMPLEMENTATION >>

   Defines:   TDataWriter, TData
*/

/* Requires */
#define TTYPENAME   DMSG_EC_FIRINGCMDTYPENAME

/* Defines */
#define TDataWriter DMSG_EC_FIRINGCMDDataWriter
#define TData       DMSG_EC_FIRINGCMD


#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_data_TDataWriter.gen"
#else
#include "dds_c/generic/dds_c_data_TDataWriter.gen"
#endif


#undef TDataWriter
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* DDSDataReader
*/

/**
  <<IMPLEMENTATION >>

   Defines:   TDataReader, TDataSeq, TData
*/

/* Requires */
#define TTYPENAME   DMSG_EC_FIRINGCMDTYPENAME

/* Defines */
#define TDataReader DMSG_EC_FIRINGCMDDataReader
#define TDataSeq    DMSG_EC_FIRINGCMDSeq
#define TData       DMSG_EC_FIRINGCMD


#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_data_TDataReader.gen"
#else
#include "dds_c/generic/dds_c_data_TDataReader.gen"
#endif


#undef TDataReader
#undef TDataSeq
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* TypeSupport

  <<IMPLEMENTATION >>

   Requires:  TTYPENAME,
              TPlugin_new
              TPlugin_delete
   Defines:   TTypeSupport, TData, TDataReader, TDataWriter
*/

/* Requires */
#define TTYPENAME    DMSG_EC_FIRINGCMDTYPENAME
#define TPlugin_new  DMSG_EC_FIRINGCMDPlugin_new
#define TPlugin_delete  DMSG_EC_FIRINGCMDPlugin_delete

/* Defines */
#define TTypeSupport DMSG_EC_FIRINGCMDTypeSupport
#define TData        DMSG_EC_FIRINGCMD
#define TDataReader  DMSG_EC_FIRINGCMDDataReader
#define TDataWriter  DMSG_EC_FIRINGCMDDataWriter
#ifdef __cplusplus



#include "dds_cpp/generic/dds_cpp_data_TTypeSupport.gen"



#else
#include "dds_c/generic/dds_c_data_TTypeSupport.gen"
#endif
#undef TTypeSupport
#undef TData
#undef TDataReader
#undef TDataWriter

#undef TTYPENAME
#undef TPlugin_new
#undef TPlugin_delete





/* ========================================================================= */
/**
   <<IMPLEMENTATION>>

   Defines:   TData,
              TDataWriter,
              TDataReader,
              TTypeSupport

   Configure and implement 'DMSG_GFC_HITEXPECT' support classes.

   Note: Only the #defined classes get defined
*/

/* ----------------------------------------------------------------- */
/* DDSDataWriter
*/

/**
  <<IMPLEMENTATION >>

   Defines:   TDataWriter, TData
*/

/* Requires */
#define TTYPENAME   DMSG_GFC_HITEXPECTTYPENAME

/* Defines */
#define TDataWriter DMSG_GFC_HITEXPECTDataWriter
#define TData       DMSG_GFC_HITEXPECT


#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_data_TDataWriter.gen"
#else
#include "dds_c/generic/dds_c_data_TDataWriter.gen"
#endif


#undef TDataWriter
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* DDSDataReader
*/

/**
  <<IMPLEMENTATION >>

   Defines:   TDataReader, TDataSeq, TData
*/

/* Requires */
#define TTYPENAME   DMSG_GFC_HITEXPECTTYPENAME

/* Defines */
#define TDataReader DMSG_GFC_HITEXPECTDataReader
#define TDataSeq    DMSG_GFC_HITEXPECTSeq
#define TData       DMSG_GFC_HITEXPECT


#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_data_TDataReader.gen"
#else
#include "dds_c/generic/dds_c_data_TDataReader.gen"
#endif


#undef TDataReader
#undef TDataSeq
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* TypeSupport

  <<IMPLEMENTATION >>

   Requires:  TTYPENAME,
              TPlugin_new
              TPlugin_delete
   Defines:   TTypeSupport, TData, TDataReader, TDataWriter
*/

/* Requires */
#define TTYPENAME    DMSG_GFC_HITEXPECTTYPENAME
#define TPlugin_new  DMSG_GFC_HITEXPECTPlugin_new
#define TPlugin_delete  DMSG_GFC_HITEXPECTPlugin_delete

/* Defines */
#define TTypeSupport DMSG_GFC_HITEXPECTTypeSupport
#define TData        DMSG_GFC_HITEXPECT
#define TDataReader  DMSG_GFC_HITEXPECTDataReader
#define TDataWriter  DMSG_GFC_HITEXPECTDataWriter
#ifdef __cplusplus



#include "dds_cpp/generic/dds_cpp_data_TTypeSupport.gen"



#else
#include "dds_c/generic/dds_c_data_TTypeSupport.gen"
#endif
#undef TTypeSupport
#undef TData
#undef TDataReader
#undef TDataWriter

#undef TTYPENAME
#undef TPlugin_new
#undef TPlugin_delete





/* ========================================================================= */
/**
   <<IMPLEMENTATION>>

   Defines:   TData,
              TDataWriter,
              TDataReader,
              TTypeSupport

   Configure and implement 'DMSG_GUN_STATE' support classes.

   Note: Only the #defined classes get defined
*/

/* ----------------------------------------------------------------- */
/* DDSDataWriter
*/

/**
  <<IMPLEMENTATION >>

   Defines:   TDataWriter, TData
*/

/* Requires */
#define TTYPENAME   DMSG_GUN_STATETYPENAME

/* Defines */
#define TDataWriter DMSG_GUN_STATEDataWriter
#define TData       DMSG_GUN_STATE


#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_data_TDataWriter.gen"
#else
#include "dds_c/generic/dds_c_data_TDataWriter.gen"
#endif


#undef TDataWriter
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* DDSDataReader
*/

/**
  <<IMPLEMENTATION >>

   Defines:   TDataReader, TDataSeq, TData
*/

/* Requires */
#define TTYPENAME   DMSG_GUN_STATETYPENAME

/* Defines */
#define TDataReader DMSG_GUN_STATEDataReader
#define TDataSeq    DMSG_GUN_STATESeq
#define TData       DMSG_GUN_STATE


#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_data_TDataReader.gen"
#else
#include "dds_c/generic/dds_c_data_TDataReader.gen"
#endif


#undef TDataReader
#undef TDataSeq
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* TypeSupport

  <<IMPLEMENTATION >>

   Requires:  TTYPENAME,
              TPlugin_new
              TPlugin_delete
   Defines:   TTypeSupport, TData, TDataReader, TDataWriter
*/

/* Requires */
#define TTYPENAME    DMSG_GUN_STATETYPENAME
#define TPlugin_new  DMSG_GUN_STATEPlugin_new
#define TPlugin_delete  DMSG_GUN_STATEPlugin_delete

/* Defines */
#define TTypeSupport DMSG_GUN_STATETypeSupport
#define TData        DMSG_GUN_STATE
#define TDataReader  DMSG_GUN_STATEDataReader
#define TDataWriter  DMSG_GUN_STATEDataWriter
#ifdef __cplusplus



#include "dds_cpp/generic/dds_cpp_data_TTypeSupport.gen"



#else
#include "dds_c/generic/dds_c_data_TTypeSupport.gen"
#endif
#undef TTypeSupport
#undef TData
#undef TDataReader
#undef TDataWriter

#undef TTYPENAME
#undef TPlugin_new
#undef TPlugin_delete


