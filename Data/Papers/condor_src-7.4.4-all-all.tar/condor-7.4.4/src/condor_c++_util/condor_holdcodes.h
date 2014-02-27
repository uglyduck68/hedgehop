/***************************************************************
 *
 * Copyright (C) 1990-2007, Condor Team, Computer Sciences Department,
 * University of Wisconsin-Madison, WI.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License"); you
 * may not use this file except in compliance with the License.  You may
 * obtain a copy of the License at
 * 
 *    http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ***************************************************************/


#ifndef CONDOR_HOLDCODES_H
#define CONDOR_HOLDCODES_H

/* This file contains hold reason codes.
 */

//There may still be some lingering cases that result in this
//unspecified hold code.  Hopefully they will be eliminated soon.
const int CONDOR_HOLD_CODE_Unspecified = 0;

//User put the job on hold with condor_hold
const int CONDOR_HOLD_CODE_UserRequest = 1;

//Globus reported an error.  The subcode is the GRAM error number.
const int CONDOR_HOLD_CODE_GlobusGramError = 2;

//The periodic hold expression evaluated to true
const int CONDOR_HOLD_CODE_JobPolicy   = 3;

//The credentials for the job (e.g. X509 proxy file) are invalid.
const int CONDOR_HOLD_CODE_CorruptedCredential = 4;

//A job policy expression (such as PeriodicHold) evaluated to UNDEFINED.
const int CONDOR_HOLD_CODE_JobPolicyUndefined   = 5;

//The condor_starter failed to start the executable.
//The subcode will contain the unix errno.
const int CONDOR_HOLD_CODE_FailedToCreateProcess = 6;

//The standard output file for the job could not be opened.
//The subcode will contain the unix errno.
const int CONDOR_HOLD_CODE_UnableToOpenOutput = 7;

//The standard input file for the job could not be opened.
//The subcode will contain the unix errno.
const int CONDOR_HOLD_CODE_UnableToOpenInput = 8;

//The standard output stream for the job could not be opened.
//The subcode will contain the unix errno.
const int CONDOR_HOLD_CODE_UnableToOpenOutputStream = 9;

//The standard input stream for the job could not be opened.
//The subcode will contain the unix errno.
const int CONDOR_HOLD_CODE_UnableToOpenInputStream = 10;

//An internal Condor protocol error was encountered when transferring files.
const int CONDOR_HOLD_CODE_InvalidTransferAck = 11;

//The condor_starter failed to download input files.
//The subcode will contain the unix errno.
const int CONDOR_HOLD_CODE_DownloadFileError = 12;

//The condor_starter failed to upload output files.
//The subcode will contain the unix errno.
const int CONDOR_HOLD_CODE_UploadFileError = 13;

//The initial working directory of the job cannot be accessed.
//The subcode will contain the unix errno.
const int CONDOR_HOLD_CODE_IwdError = 14;

//The user requested the job be submitted on hold.
const int CONDOR_HOLD_CODE_SubmittedOnHold = 15;

//Input files are being spooled.
const int CONDOR_HOLD_CODE_SpoolingInput = 16;

//In the standard universe, the job and shadows versions aren't
//compatible.
const int CONDOR_HOLD_CODE_JobShadowMismatch = 17;

//An internal Condor protocol error was encountered when transferring files.
const int CONDOR_HOLD_CODE_InvalidTransferGoAhead = 18;

#if HAVE_JOB_HOOKS
/**
   HOOK_PREPARE_JOB was defined but couldn't execute or returned failure.
   The hold subcode will be 0 if we failed to execute, the exit status
   if it exited with a failure code, or a negative number with the signal
   number if it was killed by a signal (e.g. -9).
*/
const int CONDOR_HOLD_CODE_HookPrepareJobFailure = 19;
#endif /* HAVE_JOB_HOOKS */

const int CONDOR_HOLD_CODE_MissedDeferredExecutionTime = 20;

const int CONDOR_HOLD_CODE_StartdHeldJob = 21;

// There was a problem opening or otherwise initializing
// the user log for writing.
const int CONDOR_HOLD_CODE_UnableToInitUserLog = 22;

#endif
