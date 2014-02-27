// Security.H -- 
//  Copyright (c) Phoebe Weidmann
//                This source is provided as is without any express or
//                written warranty.  Permission to use, copy, modify, and 
//                distribute this software for any purpose without fee is
//                hereby granted, provided that this entire notice is 
//                included in all copies of any software which is or includes
//                a copy or modification of this software and in all copies
//                of the supporting documentation for such software.
//                All Rights Reserved.
// $Locker:  $
// $Log: Security.H,v $
// Revision 1.1.1.1  2001/02/12 00:00:14  ravshank
// Start of Spring 2001
//
// Revision 1.35  2000/11/15 22:12:26  phoebe
// Sanity check.
//
// Revision 1.34  2000/11/13 20:57:32  phoebe
// Security had the same memory leak but it's fixed now
//
// Revision 1.33  2000/11/10 15:48:48  phoebe
// Checkpoint memory leak is now solved, and so is the memcpy core dump on some checkpoints.
//
// Revision 1.32  2000/11/06 23:07:10  phoebe
// Encryption of checkpoints is working again. We still have the memcpy problem, but it seems to be less frequent. It's still a bit of a mystery as to why it's happening, and although the core is always dropped on a memcpy in WriteCkpt, it's not deterministic when it happens.
//
// Revision 1.31  2000/11/01 23:24:27  phoebe
// Hash and sign of checkpoints is working. Also as checkpoints are cleaned up, so are the signed hashes corresponding to the checkpoints (this was not done earlier.)
//
// Revision 1.30  2000/11/01 19:49:38  phoebe
// Hashing determinants now works again.
//
// Revision 1.29  2000/11/01 16:35:23  phoebe
// Working on getting security to work again with the redesigned system. Message encryption, either full or only egida messages, is working now.
//
// Revision 1.28  2000/10/03 22:56:21  phoebe
// Optimistic will now reliably restart once. Still fails multiple sequential failures.
//
// Revision 1.27  2000/06/27 13:22:52  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.26  2000/06/22 23:09:09  phoebe
// Changed Security namespace into a proper class.
//
// Revision 1.25  2000/06/22 22:23:02  phoebe
// Changed the Timer namespace to a proper class. Put all the global timers into Timer class as private data members.
//
// Revision 1.24  2000/06/02 22:43:01  phoebe
// Added Encryption and Hash and Sign handling to PurgeDetsOnDisk subroutine in DetStore.cc but when testing on cg.B.4 with SBP logging it ran out of memory (the famous p4_shmalloc error)...so need to figure out where the leak is.
//
// Revision 1.23  2000/06/02 19:55:06  phoebe
// The code now compiles with the Encryption and the Hash and Sign functionality added to EventStore's PurgeOnDisk subroutine. Still need to test that it will run, and need to add same functionality to DetStore.cc
//
// Revision 1.22  2000/06/02 05:47:24  phoebe
// Hash and Sign of EventInfo working and it will restart and check fine. I think the modification I made to EventInfo for Reads (it's commented as a change in the code...I used << and >> instead of the commented out code) is preventing restart. Need to make sure I understand what is going on with that later.
//
// Revision 1.21  2000/06/02 04:13:13  phoebe
// Encryption of EventInfo now working.
//
// Revision 1.20  2000/06/02 01:06:28  phoebe
// Changed egida.pbLog to be correct type for both pessimistic logging types in Egida_Object_Init.cc
//
// Revision 1.19  2000/05/23 21:59:43  phoebe
// Realized a bug in the way deliveredLog was being flushed in Egida_Object_Init.cc and fixed it.
//
// Revision 1.18  2000/05/17 21:03:10  phoebe
// Sanity check to make sure all the little tweaks I've done in the last couple of days get saved.
//
// Revision 1.17  2000/04/28 20:08:16  phoebe
// Got Async Checkpoints to return micro-measurements.
//
// Revision 1.16  2000/04/21 15:07:21  phoebe
// Made the make-deps file more up to date.
//
// Revision 1.15  2000/04/20 21:49:44  phoebe
// Added Default protocol to Egida_Object_Init.cc
//
// Revision 1.14  2000/04/17 21:37:46  phoebe
// Combined all the init files for Egida_Object_Init.cc into a single file to make things easier to define. Optimistic logging option is still crashing.
//
// Revision 1.13  2000/04/14 16:34:41  phoebe
// Put in more stats to track encryption/decryption times. Also modified Communication.cc to have a cleaner interface for Message encryption/decryption so it would be easier to track with Stats...meaning I added a wrapper function call. Stats::Init is being done in Egida_PostInit which means the first checkpoint is being missed.
//
// Revision 1.12  2000/04/11 19:49:32  phoebe
// pound defined the loop iteration print statement off.
//
// Revision 1.11  2000/03/29 15:58:39  phoebe
// Added the functionality to just encrypt Egida messages and not Application messages.
//
// Revision 1.10  2000/03/17 21:37:15  phoebe
// Hashing and signing determinants working now. All security hooks should be done and reintegrated.
//
// Revision 1.9  2000/03/17 18:08:47  phoebe
// Encryption of determinants is now in place. Also I added members to DetStore.H class to handle the upcoming hash and sign hooks that will be needed for that functionality with determinants.
//
// Revision 1.8  2000/03/16 21:36:08  phoebe
// Hash and signing of checkpoints now back online. Both partial and full hash and sign.
//
// Revision 1.7  2000/03/16 16:35:01  phoebe
// Changed the writes in WriteCkpt to capture memory dumps in a buffer before writing to file. Memory changes between the initiatiation and termination of a call to write so to be able to hash appropriate values the write function and the hash function should not look directly at memory dumps but rather fixed buffer values.
//
// Revision 1.6  2000/03/16 16:13:38  phoebe
// Can now encrypt only the first checkpoint (the full ckpt) and none of the incremental checkpoints.
//
// Revision 1.5  2000/03/15 17:57:17  phoebe
// Partial checkpoint encryption is working. Tested with all three segment types. Still get the weird assert failing on EventStore.cc but generally it does not happen on loop 4...and when it does you can fail on loop 5 and it seems to be fine.
//
// Revision 1.4  2000/03/15 16:16:18  phoebe
// Full encryption of checkpoints is working.
//
// Revision 1.3  2000/03/07 16:24:50  phoebe
// Was able to restart causal logging by slightly modifying the Egida_Object_Init.cc file to distributed recovery and by tweaking StableDetStore::CkptDone function in DetStore.cc to check whether ofs was NULL before flushing. I restarted the causal protocol after the fourth loop iteration.
//
// Revision 1.2  2000/03/07 00:11:17  phoebe
// Channel Encryption now working. Init now does Security::Init and Security::Reinit. Communication.cc modified to call security functions (obviously). Tested with normal run and restart of Egida_Object_Init-default.cc.
//
// Revision 1.1  2000/03/06 20:43:43  phoebe
// Contains Security.cc and Security.H with no hooks in the code. Just changed the
// Makefile to compile and add Security to the libEgida.a
//
// $Id: Security.H,v 1.1.1.1 2001/02/12 00:00:14 ravshank Exp $
// Author          : Phoebe Weidmann
// Created On      : Thu Oct 28 18:44:24 CDT 1999
// Last Modified By: Phoebe Weidmann
// Last Modified On: Fri Dec 10 18:44:24 CDT 1999
// Update Count    : 15
// Status          : Unknown, Use with caution!
// PURPOSE
//      To supply the function interfaces that classes will
//      use to take advantage of security functionality in Egida

#if defined(__cplusplus) && !defined(_SECURITY_H)
#define _SECURITY_H

#include <unistd.h>

#include <bn.h>
#include <des.h>
#include <rsa.h>
#include <md5.h>
#include <blowfish.h>

#include "Globals.H"
#include "Determinant.H"
#include "EventInfo.H"

//--------------------HOOKS---------------------
//encryption for messages
#define ENCRYPT_ALL_MESSAGES 0
#define ENCRYPT_EGIDA_MESSAGES 0


//encryption for determinants
#define ENCRYPT_DETERMINANTS 0


//hash and signatures for determinants
#define HASH_DETERMINANTS 0
  //determinants can be written to file in two ways
  //...either through a list or one at a time. You turn
  //hashing on for both types but must 
  //choose how many single dets are in a list.
#define HASH_LIST_SIZE 10


//encryption for checkpoints
  //this will fully encrypt only the FullCkpt checkpoints
  //which is guaranteed to always be at least the first checkpoint
#define ENCRYPT_FULL_CKPTS_ONLY 0
  //
  //this will fully encrypt all checkpoints
#define TOTAL_CKPT_ENCRYPT 0
  //
  //this will partially encrypt all checkpoints
#define PARTIAL_CKPT_ENCRYPT 0
  //seg = EGIDA_STACK_SEG | EGIDA_DATA_SEG | EGIDA_HEAP_SEG
#define PRIVATE_CKPT_SEG EGIDA_HEAP_SEG


//hash and signature for checkpoints
#define HASH_AND_SIGN_CKPT 0
  //
#define PARTIAL_HASH_AND_SIGN_CKPT 0
  //seg = EGIDA_STACK_SEG | EGIDA_DATA_SEG | EGIDA_HEAP_SEG
#define SIGNED_CKPT_SEG EGIDA_STACK_SEG
//----------------------------------------------


//------------------FIXED VALUES----------------
#define MD5_DIGEST_LENGTH 16
  //this is defined as the 2 X length of the modulus...it's dependent
  //on the number of bits in the RSA key.
#define RSA_BUF_SIZE 256
  //special segment type for partial encryption
#define SEGMENT_TAG -1
  //checkpoint type markers
#define BOTH_CKPT_MARKER  0
#define FULL_CKPT_MARKER 2
#define INCR_CKPT_MARKER 4
//----------------------------------------------


class Security {
public:
  static void Init(void);
  static void ReInit(void);
  static void Terminate(void);

  //functions that use DES
  static void EncryptMessage (char * encMsg, char * msg, int msgSize);	
  static void DecryptMessage (char * decMsg, char * msg, int msgSize);	  
  static void EncryptDeterminant( Determinant * encDet, Determinant * det);
  static void DecryptDeterminant( Determinant * decDet, Determinant * det);
  static void EncryptEventInfo( EventInfo * encEinfo, EventInfo * eInfo);
  static void DecryptEventInfo( EventInfo * decEinfo, EventInfo * eInfo);

  //functions that use BlowFish
  static long EncryptWrite(int fd, void * buf, size_t nbyte);
  static long DecryptRead(int fd, void * buf, size_t nbyte);
  

  //with any RSA function the max size of msgSize must be less or equal
  // RSA_SIG_SIZE - 11
  static int EncryptWithRSA(int msgSize, unsigned char * msg, unsigned char * encMsg);  
  static int DecryptWithRSA(int msgSize, unsigned char * msg, unsigned char * decMsg);
  static bool ReadAndVerifySignature(char * ckptFileName, bool fullCkpt, 
			      char * sigFileName);
  static void SignAndRecordHash(char * sigFileName);
  

  //outputs the hash which is MD5_DIGEST_LENGTH = 16
  //In order to use MD5...you do the following sequence of events
  // Init, Update, Update,..., Update, Final
  static void HashInit(void);
  static void HashUpdate(void * data, unsigned long dataLength);
  static void HashFinal(unsigned char * digest); 

  static void HashAndSignDetList(const Determinant_List & dl, 
				 unsigned char * digest, 
				 int & numDets);
  static bool VerifyDetChunksInFile(char * logFile);
  static void HashSingleDetInit(void);
  static void HashSingleDet( Determinant * det);
  static void HashSingleDetFinal(unsigned char * digest);
  static void RecreateHashDetInit(void);
  static void RecreateHashSingleDet( Determinant * det);
  static void RecreateHashDetFinal(unsigned char * digest);


  static void HashAndSignEvInfoList(const EventInfo_List & el, 
			     unsigned char * digest, 
			     int & numDets);
  static bool VerifyEvInfoChunksInFile(char * logFile);
  static void HashSingleEvInfoInit(void);
  static void HashSingleEvInfo( EventInfo * e);
  static void HashSingleEvInfoFinal(unsigned char * digest);
  static void RecreateHashEvInfoInit(void);
  static void RecreateHashSingleEvInfo( EventInfo * e);
  static void RecreateHashEvInfoFinal(unsigned char * digest);

private:
  static void ResetIVECforBF(void);
  static void EncryptWithBF(char * encMsg, char * msg, int msgSize);
  static void DecryptWithBF(char * decMsg, char * msg, int msgSize);

  static void EncryptWithDES (char * encMsg, char * msg, int msgSize);	
  static void DecryptWithDES (char * decMsg, char * msg, int msgSize);	  

  static int BigNumRead(int fd, BIGNUM * bn);
  static int BigNumWrite(int fd, BIGNUM * bn);
  static void RetrieveRSAkey(void);
  static void WriteRSAkeyToFile(void);

  static void HashDetStruct(Determinant * d, MD5_CTX m);
  static void HashEvInfoStruct( EventInfo * e, MD5_CTX m);

  //data members 
  static RSA * RSA_key;
  static int RSA_SIG_LENGTH; //if this is > 256, need to up size of RSA_BUF_SIZE
  static int MAX_MSG_SIZE_FOR_RSA;
  static char RSAkeyFileName[RSA_BUF_SIZE];
  
  static des_key_schedule DES_key;
  static des_cblock ivecDES;
  static int ivecNumberDES;
  
  static BF_KEY BF_key;
  static unsigned char ivecBF[10];
  static int ivecNumberBF;
  
  static MD5_CTX md;
  static MD5_CTX detMD;
  static MD5_CTX singleDetMD;
  static MD5_CTX evInfoMD;
  static MD5_CTX singleEvInfoMD;
};

#endif






