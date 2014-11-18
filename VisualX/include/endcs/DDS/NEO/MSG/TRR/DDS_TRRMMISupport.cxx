
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from DDS_TRRMMI.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Data Distribution Service manual.
*/

#include "DDS_TRRMMISupport.h"
#include "DDS_TRRMMIPlugin.h"



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

   Configure and implement 'DMSG_TRR_TARGET' support classes.

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
#define TTYPENAME   DMSG_TRR_TARGETTYPENAME

/* Defines */
#define TDataWriter DMSG_TRR_TARGETDataWriter
#define TData       DMSG_TRR_TARGET


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
#define TTYPENAME   DMSG_TRR_TARGETTYPENAME

/* Defines */
#define TDataReader DMSG_TRR_TARGETDataReader
#define TDataSeq    DMSG_TRR_TARGETSeq
#define TData       DMSG_TRR_TARGET


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
#define TTYPENAME    DMSG_TRR_TARGETTYPENAME
#define TPlugin_new  DMSG_TRR_TARGETPlugin_new
#define TPlugin_delete  DMSG_TRR_TARGETPlugin_delete

/* Defines */
#define TTypeSupport DMSG_TRR_TARGETTypeSupport
#define TData        DMSG_TRR_TARGET
#define TDataReader  DMSG_TRR_TARGETDataReader
#define TDataWriter  DMSG_TRR_TARGETDataWriter
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

   Configure and implement 'DMSG_TRR_DIRECTOR' support classes.

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
#define TTYPENAME   DMSG_TRR_DIRECTORTYPENAME

/* Defines */
#define TDataWriter DMSG_TRR_DIRECTORDataWriter
#define TData       DMSG_TRR_DIRECTOR


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
#define TTYPENAME   DMSG_TRR_DIRECTORTYPENAME

/* Defines */
#define TDataReader DMSG_TRR_DIRECTORDataReader
#define TDataSeq    DMSG_TRR_DIRECTORSeq
#define TData       DMSG_TRR_DIRECTOR


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
#define TTYPENAME    DMSG_TRR_DIRECTORTYPENAME
#define TPlugin_new  DMSG_TRR_DIRECTORPlugin_new
#define TPlugin_delete  DMSG_TRR_DIRECTORPlugin_delete

/* Defines */
#define TTypeSupport DMSG_TRR_DIRECTORTypeSupport
#define TData        DMSG_TRR_DIRECTOR
#define TDataReader  DMSG_TRR_DIRECTORDataReader
#define TDataWriter  DMSG_TRR_DIRECTORDataWriter
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

   Configure and implement 'DMSG_TRR_TRACKING' support classes.

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
#define TTYPENAME   DMSG_TRR_TRACKINGTYPENAME

/* Defines */
#define TDataWriter DMSG_TRR_TRACKINGDataWriter
#define TData       DMSG_TRR_TRACKING


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
#define TTYPENAME   DMSG_TRR_TRACKINGTYPENAME

/* Defines */
#define TDataReader DMSG_TRR_TRACKINGDataReader
#define TDataSeq    DMSG_TRR_TRACKINGSeq
#define TData       DMSG_TRR_TRACKING


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
#define TTYPENAME    DMSG_TRR_TRACKINGTYPENAME
#define TPlugin_new  DMSG_TRR_TRACKINGPlugin_new
#define TPlugin_delete  DMSG_TRR_TRACKINGPlugin_delete

/* Defines */
#define TTypeSupport DMSG_TRR_TRACKINGTypeSupport
#define TData        DMSG_TRR_TRACKING
#define TDataReader  DMSG_TRR_TRACKINGDataReader
#define TDataWriter  DMSG_TRR_TRACKINGDataWriter
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

   Configure and implement 'DMSG_TRR_SHOOTDOWNRESULT' support classes.

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
#define TTYPENAME   DMSG_TRR_SHOOTDOWNRESULTTYPENAME

/* Defines */
#define TDataWriter DMSG_TRR_SHOOTDOWNRESULTDataWriter
#define TData       DMSG_TRR_SHOOTDOWNRESULT


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
#define TTYPENAME   DMSG_TRR_SHOOTDOWNRESULTTYPENAME

/* Defines */
#define TDataReader DMSG_TRR_SHOOTDOWNRESULTDataReader
#define TDataSeq    DMSG_TRR_SHOOTDOWNRESULTSeq
#define TData       DMSG_TRR_SHOOTDOWNRESULT


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
#define TTYPENAME    DMSG_TRR_SHOOTDOWNRESULTTYPENAME
#define TPlugin_new  DMSG_TRR_SHOOTDOWNRESULTPlugin_new
#define TPlugin_delete  DMSG_TRR_SHOOTDOWNRESULTPlugin_delete

/* Defines */
#define TTypeSupport DMSG_TRR_SHOOTDOWNRESULTTypeSupport
#define TData        DMSG_TRR_SHOOTDOWNRESULT
#define TDataReader  DMSG_TRR_SHOOTDOWNRESULTDataReader
#define TDataWriter  DMSG_TRR_SHOOTDOWNRESULTDataWriter
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

   Configure and implement 'DMSG_TRR_SETRESULT' support classes.

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
#define TTYPENAME   DMSG_TRR_SETRESULTTYPENAME

/* Defines */
#define TDataWriter DMSG_TRR_SETRESULTDataWriter
#define TData       DMSG_TRR_SETRESULT


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
#define TTYPENAME   DMSG_TRR_SETRESULTTYPENAME

/* Defines */
#define TDataReader DMSG_TRR_SETRESULTDataReader
#define TDataSeq    DMSG_TRR_SETRESULTSeq
#define TData       DMSG_TRR_SETRESULT


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
#define TTYPENAME    DMSG_TRR_SETRESULTTYPENAME
#define TPlugin_new  DMSG_TRR_SETRESULTPlugin_new
#define TPlugin_delete  DMSG_TRR_SETRESULTPlugin_delete

/* Defines */
#define TTypeSupport DMSG_TRR_SETRESULTTypeSupport
#define TData        DMSG_TRR_SETRESULT
#define TDataReader  DMSG_TRR_SETRESULTDataReader
#define TDataWriter  DMSG_TRR_SETRESULTDataWriter
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

   Configure and implement 'DMSG_TRR_ASCOPE' support classes.

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
#define TTYPENAME   DMSG_TRR_ASCOPETYPENAME

/* Defines */
#define TDataWriter DMSG_TRR_ASCOPEDataWriter
#define TData       DMSG_TRR_ASCOPE


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
#define TTYPENAME   DMSG_TRR_ASCOPETYPENAME

/* Defines */
#define TDataReader DMSG_TRR_ASCOPEDataReader
#define TDataSeq    DMSG_TRR_ASCOPESeq
#define TData       DMSG_TRR_ASCOPE


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
#define TTYPENAME    DMSG_TRR_ASCOPETYPENAME
#define TPlugin_new  DMSG_TRR_ASCOPEPlugin_new
#define TPlugin_delete  DMSG_TRR_ASCOPEPlugin_delete

/* Defines */
#define TTypeSupport DMSG_TRR_ASCOPETypeSupport
#define TData        DMSG_TRR_ASCOPE
#define TDataReader  DMSG_TRR_ASCOPEDataReader
#define TDataWriter  DMSG_TRR_ASCOPEDataWriter
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

   Configure and implement 'DMSG_TRR_STATE' support classes.

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
#define TTYPENAME   DMSG_TRR_STATETYPENAME

/* Defines */
#define TDataWriter DMSG_TRR_STATEDataWriter
#define TData       DMSG_TRR_STATE


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
#define TTYPENAME   DMSG_TRR_STATETYPENAME

/* Defines */
#define TDataReader DMSG_TRR_STATEDataReader
#define TDataSeq    DMSG_TRR_STATESeq
#define TData       DMSG_TRR_STATE


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
#define TTYPENAME    DMSG_TRR_STATETYPENAME
#define TPlugin_new  DMSG_TRR_STATEPlugin_new
#define TPlugin_delete  DMSG_TRR_STATEPlugin_delete

/* Defines */
#define TTypeSupport DMSG_TRR_STATETypeSupport
#define TData        DMSG_TRR_STATE
#define TDataReader  DMSG_TRR_STATEDataReader
#define TDataWriter  DMSG_TRR_STATEDataWriter
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

   Configure and implement 'DMSG_HMI_TRRRDRCHECKREQ' support classes.

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
#define TTYPENAME   DMSG_HMI_TRRRDRCHECKREQTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_TRRRDRCHECKREQDataWriter
#define TData       DMSG_HMI_TRRRDRCHECKREQ


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
#define TTYPENAME   DMSG_HMI_TRRRDRCHECKREQTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_TRRRDRCHECKREQDataReader
#define TDataSeq    DMSG_HMI_TRRRDRCHECKREQSeq
#define TData       DMSG_HMI_TRRRDRCHECKREQ


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
#define TTYPENAME    DMSG_HMI_TRRRDRCHECKREQTYPENAME
#define TPlugin_new  DMSG_HMI_TRRRDRCHECKREQPlugin_new
#define TPlugin_delete  DMSG_HMI_TRRRDRCHECKREQPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_TRRRDRCHECKREQTypeSupport
#define TData        DMSG_HMI_TRRRDRCHECKREQ
#define TDataReader  DMSG_HMI_TRRRDRCHECKREQDataReader
#define TDataWriter  DMSG_HMI_TRRRDRCHECKREQDataWriter
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

   Configure and implement 'DMSG_EC_TRRTRACKINGCMD' support classes.

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
#define TTYPENAME   DMSG_EC_TRRTRACKINGCMDTYPENAME

/* Defines */
#define TDataWriter DMSG_EC_TRRTRACKINGCMDDataWriter
#define TData       DMSG_EC_TRRTRACKINGCMD


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
#define TTYPENAME   DMSG_EC_TRRTRACKINGCMDTYPENAME

/* Defines */
#define TDataReader DMSG_EC_TRRTRACKINGCMDDataReader
#define TDataSeq    DMSG_EC_TRRTRACKINGCMDSeq
#define TData       DMSG_EC_TRRTRACKINGCMD


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
#define TTYPENAME    DMSG_EC_TRRTRACKINGCMDTYPENAME
#define TPlugin_new  DMSG_EC_TRRTRACKINGCMDPlugin_new
#define TPlugin_delete  DMSG_EC_TRRTRACKINGCMDPlugin_delete

/* Defines */
#define TTypeSupport DMSG_EC_TRRTRACKINGCMDTypeSupport
#define TData        DMSG_EC_TRRTRACKINGCMD
#define TDataReader  DMSG_EC_TRRTRACKINGCMDDataReader
#define TDataWriter  DMSG_EC_TRRTRACKINGCMDDataWriter
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

   Configure and implement 'DMSG_HMI_TRRSHOOTDOWNRESULTREQ' support classes.

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
#define TTYPENAME   DMSG_HMI_TRRSHOOTDOWNRESULTREQTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_TRRSHOOTDOWNRESULTREQDataWriter
#define TData       DMSG_HMI_TRRSHOOTDOWNRESULTREQ


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
#define TTYPENAME   DMSG_HMI_TRRSHOOTDOWNRESULTREQTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_TRRSHOOTDOWNRESULTREQDataReader
#define TDataSeq    DMSG_HMI_TRRSHOOTDOWNRESULTREQSeq
#define TData       DMSG_HMI_TRRSHOOTDOWNRESULTREQ


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
#define TTYPENAME    DMSG_HMI_TRRSHOOTDOWNRESULTREQTYPENAME
#define TPlugin_new  DMSG_HMI_TRRSHOOTDOWNRESULTREQPlugin_new
#define TPlugin_delete  DMSG_HMI_TRRSHOOTDOWNRESULTREQPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_TRRSHOOTDOWNRESULTREQTypeSupport
#define TData        DMSG_HMI_TRRSHOOTDOWNRESULTREQ
#define TDataReader  DMSG_HMI_TRRSHOOTDOWNRESULTREQDataReader
#define TDataWriter  DMSG_HMI_TRRSHOOTDOWNRESULTREQDataWriter
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

   Configure and implement 'DMSG_HMI_TRRRDRSET' support classes.

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
#define TTYPENAME   DMSG_HMI_TRRRDRSETTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_TRRRDRSETDataWriter
#define TData       DMSG_HMI_TRRRDRSET


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
#define TTYPENAME   DMSG_HMI_TRRRDRSETTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_TRRRDRSETDataReader
#define TDataSeq    DMSG_HMI_TRRRDRSETSeq
#define TData       DMSG_HMI_TRRRDRSET


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
#define TTYPENAME    DMSG_HMI_TRRRDRSETTYPENAME
#define TPlugin_new  DMSG_HMI_TRRRDRSETPlugin_new
#define TPlugin_delete  DMSG_HMI_TRRRDRSETPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_TRRRDRSETTypeSupport
#define TData        DMSG_HMI_TRRRDRSET
#define TDataReader  DMSG_HMI_TRRRDRSETDataReader
#define TDataWriter  DMSG_HMI_TRRRDRSETDataWriter
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

   Configure and implement 'DMSG_HMI_TRRVIDEOSET' support classes.

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
#define TTYPENAME   DMSG_HMI_TRRVIDEOSETTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_TRRVIDEOSETDataWriter
#define TData       DMSG_HMI_TRRVIDEOSET


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
#define TTYPENAME   DMSG_HMI_TRRVIDEOSETTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_TRRVIDEOSETDataReader
#define TDataSeq    DMSG_HMI_TRRVIDEOSETSeq
#define TData       DMSG_HMI_TRRVIDEOSET


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
#define TTYPENAME    DMSG_HMI_TRRVIDEOSETTYPENAME
#define TPlugin_new  DMSG_HMI_TRRVIDEOSETPlugin_new
#define TPlugin_delete  DMSG_HMI_TRRVIDEOSETPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_TRRVIDEOSETTypeSupport
#define TData        DMSG_HMI_TRRVIDEOSET
#define TDataReader  DMSG_HMI_TRRVIDEOSETDataReader
#define TDataWriter  DMSG_HMI_TRRVIDEOSETDataWriter
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

   Configure and implement 'DMSG_HMI_TRRMANAGESET' support classes.

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
#define TTYPENAME   DMSG_HMI_TRRMANAGESETTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_TRRMANAGESETDataWriter
#define TData       DMSG_HMI_TRRMANAGESET


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
#define TTYPENAME   DMSG_HMI_TRRMANAGESETTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_TRRMANAGESETDataReader
#define TDataSeq    DMSG_HMI_TRRMANAGESETSeq
#define TData       DMSG_HMI_TRRMANAGESET


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
#define TTYPENAME    DMSG_HMI_TRRMANAGESETTYPENAME
#define TPlugin_new  DMSG_HMI_TRRMANAGESETPlugin_new
#define TPlugin_delete  DMSG_HMI_TRRMANAGESETPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_TRRMANAGESETTypeSupport
#define TData        DMSG_HMI_TRRMANAGESET
#define TDataReader  DMSG_HMI_TRRMANAGESETDataReader
#define TDataWriter  DMSG_HMI_TRRMANAGESETDataWriter
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

   Configure and implement 'DMSG_HMI_TRRCAUTIONSET' support classes.

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
#define TTYPENAME   DMSG_HMI_TRRCAUTIONSETTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_TRRCAUTIONSETDataWriter
#define TData       DMSG_HMI_TRRCAUTIONSET


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
#define TTYPENAME   DMSG_HMI_TRRCAUTIONSETTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_TRRCAUTIONSETDataReader
#define TDataSeq    DMSG_HMI_TRRCAUTIONSETSeq
#define TData       DMSG_HMI_TRRCAUTIONSET


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
#define TTYPENAME    DMSG_HMI_TRRCAUTIONSETTYPENAME
#define TPlugin_new  DMSG_HMI_TRRCAUTIONSETPlugin_new
#define TPlugin_delete  DMSG_HMI_TRRCAUTIONSETPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_TRRCAUTIONSETTypeSupport
#define TData        DMSG_HMI_TRRCAUTIONSET
#define TDataReader  DMSG_HMI_TRRCAUTIONSETDataReader
#define TDataWriter  DMSG_HMI_TRRCAUTIONSETDataWriter
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

   Configure and implement 'DMSG_HMI_TRREQUIPMENTSET' support classes.

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
#define TTYPENAME   DMSG_HMI_TRREQUIPMENTSETTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_TRREQUIPMENTSETDataWriter
#define TData       DMSG_HMI_TRREQUIPMENTSET


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
#define TTYPENAME   DMSG_HMI_TRREQUIPMENTSETTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_TRREQUIPMENTSETDataReader
#define TDataSeq    DMSG_HMI_TRREQUIPMENTSETSeq
#define TData       DMSG_HMI_TRREQUIPMENTSET


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
#define TTYPENAME    DMSG_HMI_TRREQUIPMENTSETTYPENAME
#define TPlugin_new  DMSG_HMI_TRREQUIPMENTSETPlugin_new
#define TPlugin_delete  DMSG_HMI_TRREQUIPMENTSETPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_TRREQUIPMENTSETTypeSupport
#define TData        DMSG_HMI_TRREQUIPMENTSET
#define TDataReader  DMSG_HMI_TRREQUIPMENTSETDataReader
#define TDataWriter  DMSG_HMI_TRREQUIPMENTSETDataWriter
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

   Configure and implement 'DMSG_HMI_TRRTRACKINGSET' support classes.

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
#define TTYPENAME   DMSG_HMI_TRRTRACKINGSETTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_TRRTRACKINGSETDataWriter
#define TData       DMSG_HMI_TRRTRACKINGSET


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
#define TTYPENAME   DMSG_HMI_TRRTRACKINGSETTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_TRRTRACKINGSETDataReader
#define TDataSeq    DMSG_HMI_TRRTRACKINGSETSeq
#define TData       DMSG_HMI_TRRTRACKINGSET


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
#define TTYPENAME    DMSG_HMI_TRRTRACKINGSETTYPENAME
#define TPlugin_new  DMSG_HMI_TRRTRACKINGSETPlugin_new
#define TPlugin_delete  DMSG_HMI_TRRTRACKINGSETPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_TRRTRACKINGSETTypeSupport
#define TData        DMSG_HMI_TRRTRACKINGSET
#define TDataReader  DMSG_HMI_TRRTRACKINGSETDataReader
#define TDataWriter  DMSG_HMI_TRRTRACKINGSETDataWriter
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

   Configure and implement 'DMSG_HMI_TRRVIDEOREQ' support classes.

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
#define TTYPENAME   DMSG_HMI_TRRVIDEOREQTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_TRRVIDEOREQDataWriter
#define TData       DMSG_HMI_TRRVIDEOREQ


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
#define TTYPENAME   DMSG_HMI_TRRVIDEOREQTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_TRRVIDEOREQDataReader
#define TDataSeq    DMSG_HMI_TRRVIDEOREQSeq
#define TData       DMSG_HMI_TRRVIDEOREQ


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
#define TTYPENAME    DMSG_HMI_TRRVIDEOREQTYPENAME
#define TPlugin_new  DMSG_HMI_TRRVIDEOREQPlugin_new
#define TPlugin_delete  DMSG_HMI_TRRVIDEOREQPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_TRRVIDEOREQTypeSupport
#define TData        DMSG_HMI_TRRVIDEOREQ
#define TDataReader  DMSG_HMI_TRRVIDEOREQDataReader
#define TDataWriter  DMSG_HMI_TRRVIDEOREQDataWriter
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


