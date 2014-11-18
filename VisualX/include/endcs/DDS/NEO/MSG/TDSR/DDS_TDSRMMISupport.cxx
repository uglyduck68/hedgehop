
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from DDS_TDSRMMI.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Data Distribution Service manual.
*/

#include "DDS_TDSRMMISupport.h"
#include "DDS_TDSRMMIPlugin.h"



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

   Configure and implement 'DMSG_TDSR_FIELDSETRESULT' support classes.

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
#define TTYPENAME   DMSG_TDSR_FIELDSETRESULTTYPENAME

/* Defines */
#define TDataWriter DMSG_TDSR_FIELDSETRESULTDataWriter
#define TData       DMSG_TDSR_FIELDSETRESULT


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
#define TTYPENAME   DMSG_TDSR_FIELDSETRESULTTYPENAME

/* Defines */
#define TDataReader DMSG_TDSR_FIELDSETRESULTDataReader
#define TDataSeq    DMSG_TDSR_FIELDSETRESULTSeq
#define TData       DMSG_TDSR_FIELDSETRESULT


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
#define TTYPENAME    DMSG_TDSR_FIELDSETRESULTTYPENAME
#define TPlugin_new  DMSG_TDSR_FIELDSETRESULTPlugin_new
#define TPlugin_delete  DMSG_TDSR_FIELDSETRESULTPlugin_delete

/* Defines */
#define TTypeSupport DMSG_TDSR_FIELDSETRESULTTypeSupport
#define TData        DMSG_TDSR_FIELDSETRESULT
#define TDataReader  DMSG_TDSR_FIELDSETRESULTDataReader
#define TDataWriter  DMSG_TDSR_FIELDSETRESULTDataWriter
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

   Configure and implement 'DMSG_TDSR_JAMMING' support classes.

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
#define TTYPENAME   DMSG_TDSR_JAMMINGTYPENAME

/* Defines */
#define TDataWriter DMSG_TDSR_JAMMINGDataWriter
#define TData       DMSG_TDSR_JAMMING


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
#define TTYPENAME   DMSG_TDSR_JAMMINGTYPENAME

/* Defines */
#define TDataReader DMSG_TDSR_JAMMINGDataReader
#define TDataSeq    DMSG_TDSR_JAMMINGSeq
#define TData       DMSG_TDSR_JAMMING


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
#define TTYPENAME    DMSG_TDSR_JAMMINGTYPENAME
#define TPlugin_new  DMSG_TDSR_JAMMINGPlugin_new
#define TPlugin_delete  DMSG_TDSR_JAMMINGPlugin_delete

/* Defines */
#define TTypeSupport DMSG_TDSR_JAMMINGTypeSupport
#define TData        DMSG_TDSR_JAMMING
#define TDataReader  DMSG_TDSR_JAMMINGDataReader
#define TDataWriter  DMSG_TDSR_JAMMINGDataWriter
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

   Configure and implement 'DMSG_TDSR_STATE' support classes.

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
#define TTYPENAME   DMSG_TDSR_STATETYPENAME

/* Defines */
#define TDataWriter DMSG_TDSR_STATEDataWriter
#define TData       DMSG_TDSR_STATE


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
#define TTYPENAME   DMSG_TDSR_STATETYPENAME

/* Defines */
#define TDataReader DMSG_TDSR_STATEDataReader
#define TDataSeq    DMSG_TDSR_STATESeq
#define TData       DMSG_TDSR_STATE


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
#define TTYPENAME    DMSG_TDSR_STATETYPENAME
#define TPlugin_new  DMSG_TDSR_STATEPlugin_new
#define TPlugin_delete  DMSG_TDSR_STATEPlugin_delete

/* Defines */
#define TTypeSupport DMSG_TDSR_STATETypeSupport
#define TData        DMSG_TDSR_STATE
#define TDataReader  DMSG_TDSR_STATEDataReader
#define TDataWriter  DMSG_TDSR_STATEDataWriter
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

   Configure and implement 'DMSG_TDSR_TARGET' support classes.

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
#define TTYPENAME   DMSG_TDSR_TARGETTYPENAME

/* Defines */
#define TDataWriter DMSG_TDSR_TARGETDataWriter
#define TData       DMSG_TDSR_TARGET


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
#define TTYPENAME   DMSG_TDSR_TARGETTYPENAME

/* Defines */
#define TDataReader DMSG_TDSR_TARGETDataReader
#define TDataSeq    DMSG_TDSR_TARGETSeq
#define TData       DMSG_TDSR_TARGET


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
#define TTYPENAME    DMSG_TDSR_TARGETTYPENAME
#define TPlugin_new  DMSG_TDSR_TARGETPlugin_new
#define TPlugin_delete  DMSG_TDSR_TARGETPlugin_delete

/* Defines */
#define TTypeSupport DMSG_TDSR_TARGETTypeSupport
#define TData        DMSG_TDSR_TARGET
#define TDataReader  DMSG_TDSR_TARGETDataReader
#define TDataWriter  DMSG_TDSR_TARGETDataWriter
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

   Configure and implement 'DMSG_TDSR_BSCOPE' support classes.

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
#define TTYPENAME   DMSG_TDSR_BSCOPETYPENAME

/* Defines */
#define TDataWriter DMSG_TDSR_BSCOPEDataWriter
#define TData       DMSG_TDSR_BSCOPE


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
#define TTYPENAME   DMSG_TDSR_BSCOPETYPENAME

/* Defines */
#define TDataReader DMSG_TDSR_BSCOPEDataReader
#define TDataSeq    DMSG_TDSR_BSCOPESeq
#define TData       DMSG_TDSR_BSCOPE


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
#define TTYPENAME    DMSG_TDSR_BSCOPETYPENAME
#define TPlugin_new  DMSG_TDSR_BSCOPEPlugin_new
#define TPlugin_delete  DMSG_TDSR_BSCOPEPlugin_delete

/* Defines */
#define TTypeSupport DMSG_TDSR_BSCOPETypeSupport
#define TData        DMSG_TDSR_BSCOPE
#define TDataReader  DMSG_TDSR_BSCOPEDataReader
#define TDataWriter  DMSG_TDSR_BSCOPEDataWriter
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

   Configure and implement 'DMSG_TDSR_COLUMNOFWATER' support classes.

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
#define TTYPENAME   DMSG_TDSR_COLUMNOFWATERTYPENAME

/* Defines */
#define TDataWriter DMSG_TDSR_COLUMNOFWATERDataWriter
#define TData       DMSG_TDSR_COLUMNOFWATER


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
#define TTYPENAME   DMSG_TDSR_COLUMNOFWATERTYPENAME

/* Defines */
#define TDataReader DMSG_TDSR_COLUMNOFWATERDataReader
#define TDataSeq    DMSG_TDSR_COLUMNOFWATERSeq
#define TData       DMSG_TDSR_COLUMNOFWATER


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
#define TTYPENAME    DMSG_TDSR_COLUMNOFWATERTYPENAME
#define TPlugin_new  DMSG_TDSR_COLUMNOFWATERPlugin_new
#define TPlugin_delete  DMSG_TDSR_COLUMNOFWATERPlugin_delete

/* Defines */
#define TTypeSupport DMSG_TDSR_COLUMNOFWATERTypeSupport
#define TData        DMSG_TDSR_COLUMNOFWATER
#define TDataReader  DMSG_TDSR_COLUMNOFWATERDataReader
#define TDataWriter  DMSG_TDSR_COLUMNOFWATERDataWriter
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

   Configure and implement 'DMSG_TDSR_TWSTRACKING' support classes.

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
#define TTYPENAME   DMSG_TDSR_TWSTRACKINGTYPENAME

/* Defines */
#define TDataWriter DMSG_TDSR_TWSTRACKINGDataWriter
#define TData       DMSG_TDSR_TWSTRACKING


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
#define TTYPENAME   DMSG_TDSR_TWSTRACKINGTYPENAME

/* Defines */
#define TDataReader DMSG_TDSR_TWSTRACKINGDataReader
#define TDataSeq    DMSG_TDSR_TWSTRACKINGSeq
#define TData       DMSG_TDSR_TWSTRACKING


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
#define TTYPENAME    DMSG_TDSR_TWSTRACKINGTYPENAME
#define TPlugin_new  DMSG_TDSR_TWSTRACKINGPlugin_new
#define TPlugin_delete  DMSG_TDSR_TWSTRACKINGPlugin_delete

/* Defines */
#define TTypeSupport DMSG_TDSR_TWSTRACKINGTypeSupport
#define TData        DMSG_TDSR_TWSTRACKING
#define TDataReader  DMSG_TDSR_TWSTRACKINGDataReader
#define TDataWriter  DMSG_TDSR_TWSTRACKINGDataWriter
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

   Configure and implement 'DMSG_HMI_TDSRANTENNACTRL' support classes.

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
#define TTYPENAME   DMSG_HMI_TDSRANTENNACTRLTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_TDSRANTENNACTRLDataWriter
#define TData       DMSG_HMI_TDSRANTENNACTRL


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
#define TTYPENAME   DMSG_HMI_TDSRANTENNACTRLTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_TDSRANTENNACTRLDataReader
#define TDataSeq    DMSG_HMI_TDSRANTENNACTRLSeq
#define TData       DMSG_HMI_TDSRANTENNACTRL


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
#define TTYPENAME    DMSG_HMI_TDSRANTENNACTRLTYPENAME
#define TPlugin_new  DMSG_HMI_TDSRANTENNACTRLPlugin_new
#define TPlugin_delete  DMSG_HMI_TDSRANTENNACTRLPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_TDSRANTENNACTRLTypeSupport
#define TData        DMSG_HMI_TDSRANTENNACTRL
#define TDataReader  DMSG_HMI_TDSRANTENNACTRLDataReader
#define TDataWriter  DMSG_HMI_TDSRANTENNACTRLDataWriter
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

   Configure and implement 'DMSG_HMI_TDSRBATTLESHORTCMD' support classes.

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
#define TTYPENAME   DMSG_HMI_TDSRBATTLESHORTCMDTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_TDSRBATTLESHORTCMDDataWriter
#define TData       DMSG_HMI_TDSRBATTLESHORTCMD


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
#define TTYPENAME   DMSG_HMI_TDSRBATTLESHORTCMDTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_TDSRBATTLESHORTCMDDataReader
#define TDataSeq    DMSG_HMI_TDSRBATTLESHORTCMDSeq
#define TData       DMSG_HMI_TDSRBATTLESHORTCMD


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
#define TTYPENAME    DMSG_HMI_TDSRBATTLESHORTCMDTYPENAME
#define TPlugin_new  DMSG_HMI_TDSRBATTLESHORTCMDPlugin_new
#define TPlugin_delete  DMSG_HMI_TDSRBATTLESHORTCMDPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_TDSRBATTLESHORTCMDTypeSupport
#define TData        DMSG_HMI_TDSRBATTLESHORTCMD
#define TDataReader  DMSG_HMI_TDSRBATTLESHORTCMDDataReader
#define TDataWriter  DMSG_HMI_TDSRBATTLESHORTCMDDataWriter
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

   Configure and implement 'DMSG_HMI_TDSRTRANSMITTERCTRL' support classes.

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
#define TTYPENAME   DMSG_HMI_TDSRTRANSMITTERCTRLTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_TDSRTRANSMITTERCTRLDataWriter
#define TData       DMSG_HMI_TDSRTRANSMITTERCTRL


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
#define TTYPENAME   DMSG_HMI_TDSRTRANSMITTERCTRLTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_TDSRTRANSMITTERCTRLDataReader
#define TDataSeq    DMSG_HMI_TDSRTRANSMITTERCTRLSeq
#define TData       DMSG_HMI_TDSRTRANSMITTERCTRL


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
#define TTYPENAME    DMSG_HMI_TDSRTRANSMITTERCTRLTYPENAME
#define TPlugin_new  DMSG_HMI_TDSRTRANSMITTERCTRLPlugin_new
#define TPlugin_delete  DMSG_HMI_TDSRTRANSMITTERCTRLPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_TDSRTRANSMITTERCTRLTypeSupport
#define TData        DMSG_HMI_TDSRTRANSMITTERCTRL
#define TDataReader  DMSG_HMI_TDSRTRANSMITTERCTRLDataReader
#define TDataWriter  DMSG_HMI_TDSRTRANSMITTERCTRLDataWriter
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

   Configure and implement 'DMSG_OSM_TDSRFIELDSET' support classes.

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
#define TTYPENAME   DMSG_OSM_TDSRFIELDSETTYPENAME

/* Defines */
#define TDataWriter DMSG_OSM_TDSRFIELDSETDataWriter
#define TData       DMSG_OSM_TDSRFIELDSET


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
#define TTYPENAME   DMSG_OSM_TDSRFIELDSETTYPENAME

/* Defines */
#define TDataReader DMSG_OSM_TDSRFIELDSETDataReader
#define TDataSeq    DMSG_OSM_TDSRFIELDSETSeq
#define TData       DMSG_OSM_TDSRFIELDSET


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
#define TTYPENAME    DMSG_OSM_TDSRFIELDSETTYPENAME
#define TPlugin_new  DMSG_OSM_TDSRFIELDSETPlugin_new
#define TPlugin_delete  DMSG_OSM_TDSRFIELDSETPlugin_delete

/* Defines */
#define TTypeSupport DMSG_OSM_TDSRFIELDSETTypeSupport
#define TData        DMSG_OSM_TDSRFIELDSET
#define TDataReader  DMSG_OSM_TDSRFIELDSETDataReader
#define TDataWriter  DMSG_OSM_TDSRFIELDSETDataWriter
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

   Configure and implement 'DMSG_HMI_TDSRSURFACETRACKCTRL' support classes.

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
#define TTYPENAME   DMSG_HMI_TDSRSURFACETRACKCTRLTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_TDSRSURFACETRACKCTRLDataWriter
#define TData       DMSG_HMI_TDSRSURFACETRACKCTRL


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
#define TTYPENAME   DMSG_HMI_TDSRSURFACETRACKCTRLTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_TDSRSURFACETRACKCTRLDataReader
#define TDataSeq    DMSG_HMI_TDSRSURFACETRACKCTRLSeq
#define TData       DMSG_HMI_TDSRSURFACETRACKCTRL


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
#define TTYPENAME    DMSG_HMI_TDSRSURFACETRACKCTRLTYPENAME
#define TPlugin_new  DMSG_HMI_TDSRSURFACETRACKCTRLPlugin_new
#define TPlugin_delete  DMSG_HMI_TDSRSURFACETRACKCTRLPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_TDSRSURFACETRACKCTRLTypeSupport
#define TData        DMSG_HMI_TDSRSURFACETRACKCTRL
#define TDataReader  DMSG_HMI_TDSRSURFACETRACKCTRLDataReader
#define TDataWriter  DMSG_HMI_TDSRSURFACETRACKCTRLDataWriter
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

   Configure and implement 'DMSG_HMI_TDSRRDRSILENCECTRL' support classes.

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
#define TTYPENAME   DMSG_HMI_TDSRRDRSILENCECTRLTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_TDSRRDRSILENCECTRLDataWriter
#define TData       DMSG_HMI_TDSRRDRSILENCECTRL


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
#define TTYPENAME   DMSG_HMI_TDSRRDRSILENCECTRLTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_TDSRRDRSILENCECTRLDataReader
#define TDataSeq    DMSG_HMI_TDSRRDRSILENCECTRLSeq
#define TData       DMSG_HMI_TDSRRDRSILENCECTRL


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
#define TTYPENAME    DMSG_HMI_TDSRRDRSILENCECTRLTYPENAME
#define TPlugin_new  DMSG_HMI_TDSRRDRSILENCECTRLPlugin_new
#define TPlugin_delete  DMSG_HMI_TDSRRDRSILENCECTRLPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_TDSRRDRSILENCECTRLTypeSupport
#define TData        DMSG_HMI_TDSRRDRSILENCECTRL
#define TDataReader  DMSG_HMI_TDSRRDRSILENCECTRLDataReader
#define TDataWriter  DMSG_HMI_TDSRRDRSILENCECTRLDataWriter
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

   Configure and implement 'DMSG_HMI_TDSRSENDCHANNELSET' support classes.

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
#define TTYPENAME   DMSG_HMI_TDSRSENDCHANNELSETTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_TDSRSENDCHANNELSETDataWriter
#define TData       DMSG_HMI_TDSRSENDCHANNELSET


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
#define TTYPENAME   DMSG_HMI_TDSRSENDCHANNELSETTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_TDSRSENDCHANNELSETDataReader
#define TDataSeq    DMSG_HMI_TDSRSENDCHANNELSETSeq
#define TData       DMSG_HMI_TDSRSENDCHANNELSET


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
#define TTYPENAME    DMSG_HMI_TDSRSENDCHANNELSETTYPENAME
#define TPlugin_new  DMSG_HMI_TDSRSENDCHANNELSETPlugin_new
#define TPlugin_delete  DMSG_HMI_TDSRSENDCHANNELSETPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_TDSRSENDCHANNELSETTypeSupport
#define TData        DMSG_HMI_TDSRSENDCHANNELSET
#define TDataReader  DMSG_HMI_TDSRSENDCHANNELSETDataReader
#define TDataWriter  DMSG_HMI_TDSRSENDCHANNELSETDataWriter
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

   Configure and implement 'DMSG_HMI_TDSRSENDRFMODE' support classes.

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
#define TTYPENAME   DMSG_HMI_TDSRSENDRFMODETYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_TDSRSENDRFMODEDataWriter
#define TData       DMSG_HMI_TDSRSENDRFMODE


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
#define TTYPENAME   DMSG_HMI_TDSRSENDRFMODETYPENAME

/* Defines */
#define TDataReader DMSG_HMI_TDSRSENDRFMODEDataReader
#define TDataSeq    DMSG_HMI_TDSRSENDRFMODESeq
#define TData       DMSG_HMI_TDSRSENDRFMODE


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
#define TTYPENAME    DMSG_HMI_TDSRSENDRFMODETYPENAME
#define TPlugin_new  DMSG_HMI_TDSRSENDRFMODEPlugin_new
#define TPlugin_delete  DMSG_HMI_TDSRSENDRFMODEPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_TDSRSENDRFMODETypeSupport
#define TData        DMSG_HMI_TDSRSENDRFMODE
#define TDataReader  DMSG_HMI_TDSRSENDRFMODEDataReader
#define TDataWriter  DMSG_HMI_TDSRSENDRFMODEDataWriter
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

   Configure and implement 'DMSG_HMI_TDSRBLANKSECTORCTRL' support classes.

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
#define TTYPENAME   DMSG_HMI_TDSRBLANKSECTORCTRLTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_TDSRBLANKSECTORCTRLDataWriter
#define TData       DMSG_HMI_TDSRBLANKSECTORCTRL


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
#define TTYPENAME   DMSG_HMI_TDSRBLANKSECTORCTRLTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_TDSRBLANKSECTORCTRLDataReader
#define TDataSeq    DMSG_HMI_TDSRBLANKSECTORCTRLSeq
#define TData       DMSG_HMI_TDSRBLANKSECTORCTRL


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
#define TTYPENAME    DMSG_HMI_TDSRBLANKSECTORCTRLTYPENAME
#define TPlugin_new  DMSG_HMI_TDSRBLANKSECTORCTRLPlugin_new
#define TPlugin_delete  DMSG_HMI_TDSRBLANKSECTORCTRLPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_TDSRBLANKSECTORCTRLTypeSupport
#define TData        DMSG_HMI_TDSRBLANKSECTORCTRL
#define TDataReader  DMSG_HMI_TDSRBLANKSECTORCTRLDataReader
#define TDataWriter  DMSG_HMI_TDSRBLANKSECTORCTRLDataWriter
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

   Configure and implement 'DMSG_HMI_TDSRVIDEOSET' support classes.

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
#define TTYPENAME   DMSG_HMI_TDSRVIDEOSETTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_TDSRVIDEOSETDataWriter
#define TData       DMSG_HMI_TDSRVIDEOSET


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
#define TTYPENAME   DMSG_HMI_TDSRVIDEOSETTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_TDSRVIDEOSETDataReader
#define TDataSeq    DMSG_HMI_TDSRVIDEOSETSeq
#define TData       DMSG_HMI_TDSRVIDEOSET


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
#define TTYPENAME    DMSG_HMI_TDSRVIDEOSETTYPENAME
#define TPlugin_new  DMSG_HMI_TDSRVIDEOSETPlugin_new
#define TPlugin_delete  DMSG_HMI_TDSRVIDEOSETPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_TDSRVIDEOSETTypeSupport
#define TData        DMSG_HMI_TDSRVIDEOSET
#define TDataReader  DMSG_HMI_TDSRVIDEOSETDataReader
#define TDataWriter  DMSG_HMI_TDSRVIDEOSETDataWriter
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

   Configure and implement 'DMSG_HMI_TDSRVIDEOREQ' support classes.

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
#define TTYPENAME   DMSG_HMI_TDSRVIDEOREQTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_TDSRVIDEOREQDataWriter
#define TData       DMSG_HMI_TDSRVIDEOREQ


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
#define TTYPENAME   DMSG_HMI_TDSRVIDEOREQTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_TDSRVIDEOREQDataReader
#define TDataSeq    DMSG_HMI_TDSRVIDEOREQSeq
#define TData       DMSG_HMI_TDSRVIDEOREQ


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
#define TTYPENAME    DMSG_HMI_TDSRVIDEOREQTYPENAME
#define TPlugin_new  DMSG_HMI_TDSRVIDEOREQPlugin_new
#define TPlugin_delete  DMSG_HMI_TDSRVIDEOREQPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_TDSRVIDEOREQTypeSupport
#define TData        DMSG_HMI_TDSRVIDEOREQ
#define TDataReader  DMSG_HMI_TDSRVIDEOREQDataReader
#define TDataWriter  DMSG_HMI_TDSRVIDEOREQDataWriter
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

   Configure and implement 'DMSG_HMI_TDSRRDRMODESET' support classes.

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
#define TTYPENAME   DMSG_HMI_TDSRRDRMODESETTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_TDSRRDRMODESETDataWriter
#define TData       DMSG_HMI_TDSRRDRMODESET


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
#define TTYPENAME   DMSG_HMI_TDSRRDRMODESETTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_TDSRRDRMODESETDataReader
#define TDataSeq    DMSG_HMI_TDSRRDRMODESETSeq
#define TData       DMSG_HMI_TDSRRDRMODESET


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
#define TTYPENAME    DMSG_HMI_TDSRRDRMODESETTYPENAME
#define TPlugin_new  DMSG_HMI_TDSRRDRMODESETPlugin_new
#define TPlugin_delete  DMSG_HMI_TDSRRDRMODESETPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_TDSRRDRMODESETTypeSupport
#define TData        DMSG_HMI_TDSRRDRMODESET
#define TDataReader  DMSG_HMI_TDSRRDRMODESETDataReader
#define TDataWriter  DMSG_HMI_TDSRRDRMODESETDataWriter
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

   Configure and implement 'DMSG_HMI_TDSRAIRTRACKINGSET' support classes.

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
#define TTYPENAME   DMSG_HMI_TDSRAIRTRACKINGSETTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_TDSRAIRTRACKINGSETDataWriter
#define TData       DMSG_HMI_TDSRAIRTRACKINGSET


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
#define TTYPENAME   DMSG_HMI_TDSRAIRTRACKINGSETTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_TDSRAIRTRACKINGSETDataReader
#define TDataSeq    DMSG_HMI_TDSRAIRTRACKINGSETSeq
#define TData       DMSG_HMI_TDSRAIRTRACKINGSET


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
#define TTYPENAME    DMSG_HMI_TDSRAIRTRACKINGSETTYPENAME
#define TPlugin_new  DMSG_HMI_TDSRAIRTRACKINGSETPlugin_new
#define TPlugin_delete  DMSG_HMI_TDSRAIRTRACKINGSETPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_TDSRAIRTRACKINGSETTypeSupport
#define TData        DMSG_HMI_TDSRAIRTRACKINGSET
#define TDataReader  DMSG_HMI_TDSRAIRTRACKINGSETDataReader
#define TDataWriter  DMSG_HMI_TDSRAIRTRACKINGSETDataWriter
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

   Configure and implement 'DMSG_HMI_TDSRSHIPTRACKINGSET' support classes.

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
#define TTYPENAME   DMSG_HMI_TDSRSHIPTRACKINGSETTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_TDSRSHIPTRACKINGSETDataWriter
#define TData       DMSG_HMI_TDSRSHIPTRACKINGSET


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
#define TTYPENAME   DMSG_HMI_TDSRSHIPTRACKINGSETTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_TDSRSHIPTRACKINGSETDataReader
#define TDataSeq    DMSG_HMI_TDSRSHIPTRACKINGSETSeq
#define TData       DMSG_HMI_TDSRSHIPTRACKINGSET


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
#define TTYPENAME    DMSG_HMI_TDSRSHIPTRACKINGSETTYPENAME
#define TPlugin_new  DMSG_HMI_TDSRSHIPTRACKINGSETPlugin_new
#define TPlugin_delete  DMSG_HMI_TDSRSHIPTRACKINGSETPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_TDSRSHIPTRACKINGSETTypeSupport
#define TData        DMSG_HMI_TDSRSHIPTRACKINGSET
#define TDataReader  DMSG_HMI_TDSRSHIPTRACKINGSETDataReader
#define TDataWriter  DMSG_HMI_TDSRSHIPTRACKINGSETDataWriter
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

   Configure and implement 'DMSG_HMI_TDSRJAMMINGDETECTSET' support classes.

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
#define TTYPENAME   DMSG_HMI_TDSRJAMMINGDETECTSETTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_TDSRJAMMINGDETECTSETDataWriter
#define TData       DMSG_HMI_TDSRJAMMINGDETECTSET


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
#define TTYPENAME   DMSG_HMI_TDSRJAMMINGDETECTSETTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_TDSRJAMMINGDETECTSETDataReader
#define TDataSeq    DMSG_HMI_TDSRJAMMINGDETECTSETSeq
#define TData       DMSG_HMI_TDSRJAMMINGDETECTSET


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
#define TTYPENAME    DMSG_HMI_TDSRJAMMINGDETECTSETTYPENAME
#define TPlugin_new  DMSG_HMI_TDSRJAMMINGDETECTSETPlugin_new
#define TPlugin_delete  DMSG_HMI_TDSRJAMMINGDETECTSETPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_TDSRJAMMINGDETECTSETTypeSupport
#define TData        DMSG_HMI_TDSRJAMMINGDETECTSET
#define TDataReader  DMSG_HMI_TDSRJAMMINGDETECTSETDataReader
#define TDataWriter  DMSG_HMI_TDSRJAMMINGDETECTSETDataWriter
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

   Configure and implement 'DMSG_HMI_TDSRLOWSPEEDDETECTSET' support classes.

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
#define TTYPENAME   DMSG_HMI_TDSRLOWSPEEDDETECTSETTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_TDSRLOWSPEEDDETECTSETDataWriter
#define TData       DMSG_HMI_TDSRLOWSPEEDDETECTSET


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
#define TTYPENAME   DMSG_HMI_TDSRLOWSPEEDDETECTSETTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_TDSRLOWSPEEDDETECTSETDataReader
#define TDataSeq    DMSG_HMI_TDSRLOWSPEEDDETECTSETSeq
#define TData       DMSG_HMI_TDSRLOWSPEEDDETECTSET


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
#define TTYPENAME    DMSG_HMI_TDSRLOWSPEEDDETECTSETTYPENAME
#define TPlugin_new  DMSG_HMI_TDSRLOWSPEEDDETECTSETPlugin_new
#define TPlugin_delete  DMSG_HMI_TDSRLOWSPEEDDETECTSETPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_TDSRLOWSPEEDDETECTSETTypeSupport
#define TData        DMSG_HMI_TDSRLOWSPEEDDETECTSET
#define TDataReader  DMSG_HMI_TDSRLOWSPEEDDETECTSETDataReader
#define TDataWriter  DMSG_HMI_TDSRLOWSPEEDDETECTSETDataWriter
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

   Configure and implement 'DMSG_HMI_TDSRLOWALTDETECTSET' support classes.

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
#define TTYPENAME   DMSG_HMI_TDSRLOWALTDETECTSETTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_TDSRLOWALTDETECTSETDataWriter
#define TData       DMSG_HMI_TDSRLOWALTDETECTSET


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
#define TTYPENAME   DMSG_HMI_TDSRLOWALTDETECTSETTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_TDSRLOWALTDETECTSETDataReader
#define TDataSeq    DMSG_HMI_TDSRLOWALTDETECTSETSeq
#define TData       DMSG_HMI_TDSRLOWALTDETECTSET


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
#define TTYPENAME    DMSG_HMI_TDSRLOWALTDETECTSETTYPENAME
#define TPlugin_new  DMSG_HMI_TDSRLOWALTDETECTSETPlugin_new
#define TPlugin_delete  DMSG_HMI_TDSRLOWALTDETECTSETPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_TDSRLOWALTDETECTSETTypeSupport
#define TData        DMSG_HMI_TDSRLOWALTDETECTSET
#define TDataReader  DMSG_HMI_TDSRLOWALTDETECTSETDataReader
#define TDataWriter  DMSG_HMI_TDSRLOWALTDETECTSETDataWriter
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

   Configure and implement 'DMSG_HMI_TDSRSIDELOBEBLOCK' support classes.

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
#define TTYPENAME   DMSG_HMI_TDSRSIDELOBEBLOCKTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_TDSRSIDELOBEBLOCKDataWriter
#define TData       DMSG_HMI_TDSRSIDELOBEBLOCK


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
#define TTYPENAME   DMSG_HMI_TDSRSIDELOBEBLOCKTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_TDSRSIDELOBEBLOCKDataReader
#define TDataSeq    DMSG_HMI_TDSRSIDELOBEBLOCKSeq
#define TData       DMSG_HMI_TDSRSIDELOBEBLOCK


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
#define TTYPENAME    DMSG_HMI_TDSRSIDELOBEBLOCKTYPENAME
#define TPlugin_new  DMSG_HMI_TDSRSIDELOBEBLOCKPlugin_new
#define TPlugin_delete  DMSG_HMI_TDSRSIDELOBEBLOCKPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_TDSRSIDELOBEBLOCKTypeSupport
#define TData        DMSG_HMI_TDSRSIDELOBEBLOCK
#define TDataReader  DMSG_HMI_TDSRSIDELOBEBLOCKDataReader
#define TDataWriter  DMSG_HMI_TDSRSIDELOBEBLOCKDataWriter
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

   Configure and implement 'DMSG_HMI_TDSREQUIPQUITSET' support classes.

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
#define TTYPENAME   DMSG_HMI_TDSREQUIPQUITSETTYPENAME

/* Defines */
#define TDataWriter DMSG_HMI_TDSREQUIPQUITSETDataWriter
#define TData       DMSG_HMI_TDSREQUIPQUITSET


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
#define TTYPENAME   DMSG_HMI_TDSREQUIPQUITSETTYPENAME

/* Defines */
#define TDataReader DMSG_HMI_TDSREQUIPQUITSETDataReader
#define TDataSeq    DMSG_HMI_TDSREQUIPQUITSETSeq
#define TData       DMSG_HMI_TDSREQUIPQUITSET


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
#define TTYPENAME    DMSG_HMI_TDSREQUIPQUITSETTYPENAME
#define TPlugin_new  DMSG_HMI_TDSREQUIPQUITSETPlugin_new
#define TPlugin_delete  DMSG_HMI_TDSREQUIPQUITSETPlugin_delete

/* Defines */
#define TTypeSupport DMSG_HMI_TDSREQUIPQUITSETTypeSupport
#define TData        DMSG_HMI_TDSREQUIPQUITSET
#define TDataReader  DMSG_HMI_TDSREQUIPQUITSETDataReader
#define TDataWriter  DMSG_HMI_TDSREQUIPQUITSETDataWriter
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

   Configure and implement 'DMSG_EC_TDSRTWSTARGETDESIG' support classes.

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
#define TTYPENAME   DMSG_EC_TDSRTWSTARGETDESIGTYPENAME

/* Defines */
#define TDataWriter DMSG_EC_TDSRTWSTARGETDESIGDataWriter
#define TData       DMSG_EC_TDSRTWSTARGETDESIG


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
#define TTYPENAME   DMSG_EC_TDSRTWSTARGETDESIGTYPENAME

/* Defines */
#define TDataReader DMSG_EC_TDSRTWSTARGETDESIGDataReader
#define TDataSeq    DMSG_EC_TDSRTWSTARGETDESIGSeq
#define TData       DMSG_EC_TDSRTWSTARGETDESIG


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
#define TTYPENAME    DMSG_EC_TDSRTWSTARGETDESIGTYPENAME
#define TPlugin_new  DMSG_EC_TDSRTWSTARGETDESIGPlugin_new
#define TPlugin_delete  DMSG_EC_TDSRTWSTARGETDESIGPlugin_delete

/* Defines */
#define TTypeSupport DMSG_EC_TDSRTWSTARGETDESIGTypeSupport
#define TData        DMSG_EC_TDSRTWSTARGETDESIG
#define TDataReader  DMSG_EC_TDSRTWSTARGETDESIGDataReader
#define TDataWriter  DMSG_EC_TDSRTWSTARGETDESIGDataWriter
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


