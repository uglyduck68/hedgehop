// Security.cc -- 
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
// $Log: Security.cc,v $
// Revision 1.1.1.1  2001/02/12 00:00:17  ravshank
// Start of Spring 2001
//
// Revision 1.20  2000/11/13 20:57:36  phoebe
// Security had the same memory leak but it's fixed now
//
// Revision 1.19  2000/11/01 23:24:30  phoebe
// Hash and sign of checkpoints is working. Also as checkpoints are cleaned up, so are the signed hashes corresponding to the checkpoints (this was not done earlier.)
//
// Revision 1.18  2000/11/01 16:35:31  phoebe
// Working on getting security to work again with the redesigned system. Message encryption, either full or only egida messages, is working now.
//
// Revision 1.17  2000/08/09 15:32:54  phoebe
// Changed the buffer size in CkptImpl.cc to be a #define instead of being hardwired to 4096. Also made fix in DetStore.cc and EventStore.cc that will allow both writing dets one at at time and in lists to be viable when hashing is turned on. Before this would have caused problems.
//
// Revision 1.16  2000/06/27 20:15:52  phoebe
// Cleaned up Makefiles. Made DebugTrace into a proper class. Fixed the communication tracking part of Stats.cc.
//
// Revision 1.15  2000/06/27 13:23:14  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.14  2000/06/23 02:47:48  phoebe
// Wrapped all the statistics taking calls in all the functions so that they can either be turned on or off when desired.
//
// Revision 1.13  2000/06/22 23:09:10  phoebe
// Changed Security namespace into a proper class.
//
// Revision 1.12  2000/06/22 20:59:10  phoebe
// Merged the function ComputeTimeDiff into the Timer namespace. Got rid of the TimeDiff.cc and TimeDiff.H files.
//
// Revision 1.11  2000/06/02 22:43:06  phoebe
// Added Encryption and Hash and Sign handling to PurgeDetsOnDisk subroutine in DetStore.cc but when testing on cg.B.4 with SBP logging it ran out of memory (the famous p4_shmalloc error)...so need to figure out where the leak is.
//
// Revision 1.10  2000/06/02 19:55:09  phoebe
// The code now compiles with the Encryption and the Hash and Sign functionality added to EventStore's PurgeOnDisk subroutine. Still need to test that it will run, and need to add same functionality to DetStore.cc
//
// Revision 1.9  2000/06/02 05:47:27  phoebe
// Hash and Sign of EventInfo working and it will restart and check fine. I think the modification I made to EventInfo for Reads (it's commented as a change in the code...I used << and >> instead of the commented out code) is preventing restart. Need to make sure I understand what is going on with that later.
//
// Revision 1.8  2000/06/02 04:13:18  phoebe
// Encryption of EventInfo now working.
//
// Revision 1.7  2000/04/20 20:57:58  phoebe
// Integrated Stats to track hash and sign functions.
//
// Revision 1.6  2000/04/14 16:34:44  phoebe
// Put in more stats to track encryption/decryption times. Also modified Communication.cc to have a cleaner interface for Message encryption/decryption so it would be easier to track with Stats...meaning I added a wrapper function call. Stats::Init is being done in Egida_PostInit which means the first checkpoint is being missed.
//
// Revision 1.5  2000/03/17 21:37:18  phoebe
// Hashing and signing determinants working now. All security hooks should be done and reintegrated.
//
// Revision 1.4  2000/03/17 18:08:52  phoebe
// Encryption of determinants is now in place. Also I added members to DetStore.H class to handle the upcoming hash and sign hooks that will be needed for that functionality with determinants.
//
// Revision 1.3  2000/03/16 17:18:00  phoebe
// Re-integrated the hash and sign functions into CkptImpl and Security files. Did not turn on any of the hooks for these functions. Just put the code in and made sure that things were still going to run.
//
// Revision 1.2  2000/03/07 00:10:46  phoebe
// Channel Encryption now working. Init now does Security::Init and Security::Reinit. Communication.cc modified to call security functions (obviously). Tested with normal run and restart of Egida_Object_Init-default.cc.
//
// Revision 1.1  2000/03/06 20:43:57  phoebe
// Contains Security.cc and Security.H with no hooks in the code. Just changed the
// Makefile to compile and add Security to the libEgida.a
//
// $Id: Security.cc,v 1.1.1.1 2001/02/12 00:00:17 ravshank Exp $
// Author          : Phoebe Weidmann
// Created On      : Thu Oct 28 18:44:24 CDT 1999
// Last Modified By: Phoebe Weidmann
// Last Modified On: Thu Dec 21 10:26:19 CST 1999
// Update Count    : 30
// Status          : Unknown, Use with caution!
//


#include <iostream>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/utsname.h>
#include <fcntl.h>
#include <string.h>
#include <strstream>

#include "CkptImpl.H"
#include "Globals.H"
#include "Security.H"
#include "Stats.H"
#include "Timer.H"


//variables used by Security
RSA * Security::RSA_key;
int Security::RSA_SIG_LENGTH; //if this is > 256, need to up size of RSA_BUF_SIZE
int Security::MAX_MSG_SIZE_FOR_RSA;
char Security::RSAkeyFileName[RSA_BUF_SIZE];

des_key_schedule Security::DES_key;
des_cblock Security::ivecDES;
int Security::ivecNumberDES;

BF_KEY Security::BF_key;
unsigned char Security::ivecBF[10];
int Security::ivecNumberBF;

MD5_CTX Security::md;
MD5_CTX Security::detMD;
MD5_CTX Security::singleDetMD;
MD5_CTX Security::evInfoMD;
MD5_CTX Security::singleEvInfoMD;


void Security::Init()
{
  struct utsname machineName;
  uname(&machineName);

  std::cout << std::endl;
  std::cout << "Security variables initialized on ";
  std::cout << machineName.nodename;
  std::cout << std::endl << std::endl;

  //Set up DES key
  char keyString[] = "phoebe";
  des_cblock keyCblock;
  des_string_to_key(keyString, &keyCblock);
  des_set_key(&keyCblock, DES_key);

  //Set up BF key
  unsigned char BFkeyString[] = "phoebe kay weidmann";
  BF_set_key(&BF_key, 16, BFkeyString);


  //Set up RSA key 
  RSA_key = RSA_new();
  int bits = 1024;
  unsigned long pub = 3; //this is the public key
  RSA_key = RSA_generate_key(bits, pub, NULL, NULL);
  
  RSA_SIG_LENGTH = RSA_size(RSA_key);
  MAX_MSG_SIZE_FOR_RSA = RSA_SIG_LENGTH - 11;

}

void Security::Terminate()
{
  //possibly clean up security structures?
}

void Security::ReInit()
{  
  struct utsname machineName;
  uname(&machineName);

  std::cout << std::endl;
  std::cout << "Security variables re-initialized on ";
  std::cout << machineName.nodename;
  std::cout << std::endl << std::endl;

  //Set up DES key
  char keyString[] = "phoebe";
  des_cblock keyCblock;
  des_string_to_key(keyString, &keyCblock);
  des_set_key(&keyCblock, DES_key);

  //Set up BF key
  unsigned char BFkeyString[] = "phoebe kay weidmann";
  BF_set_key(&BF_key, 16, BFkeyString);


  //Set up RSA key  
  RSA_key = RSA_new();
  int bits = 1024;
  unsigned long pub = 3; //this is the public key
  RSA_key = RSA_generate_key(bits, pub, NULL, NULL);
  
  RSA_SIG_LENGTH = RSA_size(RSA_key);
  MAX_MSG_SIZE_FOR_RSA = RSA_SIG_LENGTH - 11;

}



void Security::EncryptWithDES (char * encMsg, // The result of encryption.
			       char * msg,    // The input message.
			       int msgSize)   // length of msg, in chars.
{
  //vector used for chaining in DES function
  memset(ivecDES, 0, sizeof(ivecDES));
  ivecNumberDES = 0;

  des_cfb64_encrypt((unsigned char *) msg,
		    (unsigned char *) encMsg,
		    (long) msgSize,
		    DES_key,
		    &ivecDES,
		    &ivecNumberDES,
		    DES_ENCRYPT);
}


void Security::DecryptWithDES (char * decMsg, // The result of decryption.
			       char * msg,    // The input message.
			       int msgSize)   // length of msg, in chars.
{
  //vector used for chaining in DES function
  memset(ivecDES, 0, sizeof(ivecDES));
  ivecNumberDES = 0;

  des_cfb64_encrypt((unsigned char *) msg,
		    (unsigned char *) decMsg,
		    (long) msgSize,
		    DES_key,
		    &ivecDES,
		    &ivecNumberDES,
		    DES_DECRYPT);
}


void Security::EncryptMessage(char * encMsg, char * msg, int msgSize)
{
  struct timeval timeStart, timeEnd;
  double timeSpent = 0.0;

  if(COLLECTING_STATS) {
    gettimeofday(&timeStart, NULL);
  }

  EncryptWithDES(encMsg, msg, msgSize);

  if(COLLECTING_STATS) {
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_MSG_ENCRYPTION_STAT, msgSize, timeSpent);
  }
}


void Security::DecryptMessage(char * decMsg, char * msg, int msgSize)
{
  struct timeval timeStart, timeEnd;
  double timeSpent = 0.0;

  if(COLLECTING_STATS) {
    gettimeofday(&timeStart, NULL);
  }

  DecryptWithDES(decMsg, msg, msgSize);

  if(COLLECTING_STATS) {
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_MSG_DECRYPTION_STAT, msgSize, timeSpent);
  }
}


void Security::EncryptDeterminant(Determinant * result, //result det after enc 
				  Determinant * d) //input det
{
  int * intBuf = new int[4];
  int * intBuf2 = new int[4];

  struct timeval timeStart, timeEnd;
  double timeSpent = 0.0;

  if(COLLECTING_STATS) {
    gettimeofday(&timeStart, NULL);
  }

  intBuf[0] = d->source;
  intBuf[1] = d->dest;
  intBuf[2] = d->s_esn;
  intBuf[3] = d->d_esn;
  
  EncryptWithDES((char*)intBuf2, (char *)intBuf, (4 * sizeof(int)));

  result->source = intBuf2[0];
  result->dest   = intBuf2[1];
  result->s_esn  = intBuf2[2];
  result->d_esn  = intBuf2[3];

  result->eventSpecificSize = d->eventSpecificSize;

  if(d->eventSpecificSize > 0) {
    char * buf = new char[d->eventSpecificSize];
    EncryptWithDES(buf, d->eventSpecific, d->eventSpecificSize);
    result->eventSpecific = buf;
  }
  delete [] intBuf;
  delete [] intBuf2;

  if(COLLECTING_STATS) {
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_DETERMINANT_ENCRYPTION_STAT, 
		  4*sizeof(int) + d->eventSpecificSize, timeSpent);
  }

}



void Security::DecryptDeterminant(Determinant * result, //result det after dec
				  Determinant * d) //input det
{
  int * intBuf = new int[4];
  int * intBuf2 = new int[4];

  struct timeval timeStart, timeEnd;
  double timeSpent = 0.0;

  if(COLLECTING_STATS) {
    gettimeofday(&timeStart, NULL);
  }

  intBuf[0] = d->source;
  intBuf[1] = d->dest;
  intBuf[2] = d->s_esn;
  intBuf[3] = d->d_esn;
  
  DecryptWithDES((char *)intBuf2, (char*)intBuf, (4 * sizeof(int)));

  result->source = intBuf2[0];
  result->dest   = intBuf2[1];
  result->s_esn  = intBuf2[2];
  result->d_esn  = intBuf2[3];


  result->eventSpecificSize = d->eventSpecificSize;

  if(d->eventSpecificSize > 0) {
    char * buf = new char[d->eventSpecificSize];
    DecryptWithDES(buf, d->eventSpecific, d->eventSpecificSize);
    result->eventSpecific = buf;
  }
  delete [] intBuf;
  delete [] intBuf2;

  if(COLLECTING_STATS) {
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_DETERMINANT_DECRYPTION_STAT, 
		  4*sizeof(int) + d->eventSpecificSize, timeSpent);
  }

}


void Security::EncryptEventInfo(EventInfo * result, //result eInfo after enc 
				EventInfo * e) //input eInfo
{
  int * intBuf = new int[4];
  int * intBuf2 = new int[4];

  struct timeval timeStart, timeEnd;
  double timeSpent = 0.0;

  if(COLLECTING_STATS) {
    gettimeofday(&timeStart, NULL);
  }

  intBuf[0] = e->source;
  intBuf[1] = e->sourceEventId;
  intBuf[2] = e->otherProc;
  intBuf[3] = e->otherProcEventId;
  
  EncryptWithDES((char*)intBuf2, (char *)intBuf, (4 * sizeof(int)));

  result->source = intBuf2[0];
  result->sourceEventId = intBuf2[1];
  result->otherProc = intBuf2[2];
  result->otherProcEventId = intBuf2[3];

  result->pbSize = e->pbSize;
  result->infoSize = e->infoSize;

  if(e->pbSize > 0) {
    char * buf = p4_msg_alloc(e->pbSize);
    EncryptWithDES(buf, e->pb, e->pbSize);
    result->pb = buf;
  }

  if(e->infoSize > 0) {
    char * buf2 =  p4_msg_alloc(e->infoSize);
    EncryptWithDES(buf2, e->info, e->infoSize);
    result->info = buf2;
  }

  delete [] intBuf;
  delete [] intBuf2;

  if(COLLECTING_STATS) {
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_EVENT_INFO_ENCRYPTION_STAT, 
		  4*sizeof(int) + e->pbSize + e->infoSize, timeSpent);
  }

}



void Security::DecryptEventInfo(EventInfo * result, //result eInfo after dec
				EventInfo * e) //input eInfo
{
  int * intBuf = new int[4];
  int * intBuf2 = new int[4];

  struct timeval timeStart, timeEnd;
  double timeSpent = 0.0;

  if(COLLECTING_STATS) {
    gettimeofday(&timeStart, NULL);
  }

  intBuf[0] = e->source;
  intBuf[1] = e->sourceEventId;
  intBuf[2] = e->otherProc;
  intBuf[3] = e->otherProcEventId;
  
  DecryptWithDES((char *)intBuf2, (char*)intBuf, (4 * sizeof(int)));

  result->source = intBuf2[0];
  result->sourceEventId = intBuf2[1];
  result->otherProc = intBuf2[2];
  result->otherProcEventId = intBuf2[3];


  result->pbSize = e->pbSize;
  result->infoSize = e->infoSize;

  if(e->pbSize > 0) {
    char * buf =  p4_msg_alloc(e->pbSize);
    DecryptWithDES(buf, e->pb, e->pbSize);
    result->pb = buf;
  }

  if(e->infoSize > 0) {
    char * buf2 =  p4_msg_alloc(e->infoSize);
    DecryptWithDES(buf2, e->info, e->infoSize);
    result->info = buf2;
  }

  delete [] intBuf;
  delete [] intBuf2;

  if(COLLECTING_STATS) {
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_EVENT_INFO_DECRYPTION_STAT, 
		  4*sizeof(int) + e->pbSize + e->infoSize, timeSpent);
  }

}



void Security::ResetIVECforBF()
{
  //vector used for chaining in DES function
  memset(ivecBF, 0, sizeof(ivecBF));
  ivecNumberBF = 0;
}  


void Security::EncryptWithBF(char * encMsg, // The result of the encryption.
			     char * msg,    // The input message.
			     int msgSize)   // length of msg,in chars.
{
  BF_cfb64_encrypt((unsigned char *) msg,
		   (unsigned char *) encMsg,
		   (long) msgSize,
		   &BF_key,
		   (unsigned char *) &ivecBF,
		   &ivecNumberBF,
		   BF_ENCRYPT);
}


void Security::DecryptWithBF(char * decMsg, // The result of the decryption.
			     char * msg,    // The input message.
			     int msgSize)   // The length of msg, in chars.
{
  BF_cfb64_encrypt((unsigned char *) msg,
		   (unsigned char *) decMsg,
		   (long) msgSize,
		   &BF_key,
		   (unsigned char *) &ivecBF,
		   &ivecNumberBF,
		   BF_DECRYPT);
}




long Security::EncryptWrite(int fd, void * v_buf, size_t nbyte)
{
  long retVal = 0;
  long index = 0;
  long totalRetVal = 0;
  int keepGoing = 1;
  int pieceSize = 0;

  struct timeval timeStart, timeEnd;
  double timeSpent = 0.0;

  if(COLLECTING_STATS) {
    gettimeofday(&timeStart, NULL);
  }

  unsigned char * buf = (unsigned char *)v_buf;

  unsigned char encBuf[1024];

  ResetIVECforBF();

  while(keepGoing) {
    if(index + 1024 < nbyte) {
      pieceSize = 1024;
    }
    else {
      keepGoing = 0; //this is the last chunk of the input
      pieceSize = nbyte - index;
    }
    
    EncryptWithBF((char *) &encBuf, (char *) &buf[index], pieceSize);

    retVal = write(fd, &encBuf, pieceSize);
    totalRetVal += retVal;

    index += pieceSize;
  }

  if(COLLECTING_STATS) {
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_CKPT_ENCRYPTION_STAT, nbyte, timeSpent);
  }

  return(totalRetVal);

}


long Security::DecryptRead(int fd, void * v_buf, size_t nbyte)
{
  long retVal = 0;
  long totalRetVal = 0;
  long index = 0;
  int keepGoing = 1;
  int pieceSize = 0;
  unsigned char decBuf[1024];
  struct timeval timeStart, timeEnd;
  double timeSpent = 0.0;
  unsigned char * buf = (unsigned char *)v_buf;

  if(COLLECTING_STATS) {
    gettimeofday(&timeStart, NULL);
  }

  ResetIVECforBF();

  while(keepGoing) {
    if(index + 1024 < nbyte) {
      pieceSize = 1024;
    }
    else {
      keepGoing = 0; //this is the last piece needing decryption
      pieceSize = nbyte - index;
    }

    retVal = read(fd, &decBuf, pieceSize);
    totalRetVal += retVal;

    DecryptWithBF((char *) &buf[index],(char *) &decBuf, pieceSize);

    index += pieceSize;
  }

  if(COLLECTING_STATS) {
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_CKPT_DECRYPTION_STAT, nbyte, timeSpent);
  }

  return(totalRetVal);

}



void Security::RetrieveRSAkey()
{
  //need to recover the first key used to encrypt stuff.
  char rsaFileName[EGIDA_FILENAME_LEN];
  struct utsname machineName;
  uname(&machineName);
  sprintf(rsaFileName, "%s/%s.Dir/RSAkeyFile.%s", 
	  EGIDA_CKPT_DIR, machineName.nodename, machineName.nodename);

  //open the file
  int fd = open(rsaFileName, O_RDONLY, S_IRUSR, S_IWUSR);
  //read in the key
  BigNumRead(fd, RSA_key->n);
  BigNumRead(fd, RSA_key->e);
  BigNumRead(fd, RSA_key->d);
  BigNumRead(fd, RSA_key->p);
  BigNumRead(fd, RSA_key->q);
  BigNumRead(fd, RSA_key->dmp1);
  BigNumRead(fd, RSA_key->dmq1);
  BigNumRead(fd, RSA_key->iqmp);
  
  //close the file
  close(fd);

}


int Security::BigNumRead(int fd, BIGNUM * bn)
{
  int totalBytes = 0;
  int readRetVal = 0;
  int tempMAX = 0;

  //make sure the regenerated key has the same indexes as stored key
  read(fd, &tempMAX, sizeof(int));
  if(bn->max != tempMAX) {
    std::cout << "++++Could not read in BIGNUM from file...BAD MAX VALUE.+++"
	      << std::endl;
  }
  else {
    read(fd, &bn->top, sizeof(int));
    
    for(int i=0; i < bn->max; i++) {
      readRetVal = read(fd, &bn->d[i], sizeof(long unsigned int));
      totalBytes += readRetVal;
    }
  }
  return(totalBytes);
}


int Security::BigNumWrite(int fd, BIGNUM * bn)
{
  int totalBytes = 0;
  int writeRetVal = 0;
  
  //to make sure the key has the same indexes
  write(fd, &bn->max, sizeof(int));
  write(fd, &bn->top, sizeof(int));

  for(int i=0; i < bn->max; i++) {
    writeRetVal = write(fd, &bn->d[i], sizeof(long unsigned int));
    totalBytes += writeRetVal;
  }
  return(totalBytes);
}


void Security::WriteRSAkeyToFile()
{
  char rsaFileName[EGIDA_FILENAME_LEN];
  struct utsname machineName;
  uname(&machineName);
  sprintf(rsaFileName, "%s/%s.Dir/RSAkeyFile.%s", 
	  EGIDA_CKPT_DIR, machineName.nodename, machineName.nodename);

  //open the file
  int fd = open(rsaFileName, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
  //write out the key
  BigNumWrite(fd, RSA_key->n);
  BigNumWrite(fd, RSA_key->e);
  BigNumWrite(fd, RSA_key->d);
  BigNumWrite(fd, RSA_key->p);
  BigNumWrite(fd, RSA_key->q);
  BigNumWrite(fd, RSA_key->dmp1);
  BigNumWrite(fd, RSA_key->dmq1);
  BigNumWrite(fd, RSA_key->iqmp);

  //close the file
  close(fd);

}





//returns -1 if unsuccessful or -2 if improper size
int Security::EncryptWithRSA(int msgSize, 
			     unsigned char * msg, 
			     unsigned char * encMsg)
{
  int bytesEncrypted = -2;

  if(msgSize <= MAX_MSG_SIZE_FOR_RSA) {
    bytesEncrypted = RSA_private_encrypt(msgSize, msg, encMsg, RSA_key, 1);
  }

  return(bytesEncrypted);
}


//returns -1 if unsuccessful and -2 if not correct size
int Security::DecryptWithRSA(int msgSize, 
			     unsigned char * msg, 
			     unsigned char * decMsg)
{
  int bytesDecrypted = -2;

  //no guarantees if msgSize is not RSA_SIG_LENGTH so check...
  if(msgSize == RSA_SIG_LENGTH) {  
    //it's a proper signature
    bytesDecrypted = RSA_public_decrypt(msgSize, msg, decMsg, RSA_key, 1);
  }

  return(bytesDecrypted);
}


//returns  false = "bad", true = "good"
bool Security::ReadAndVerifySignature(char * ckptFileName, 
				      bool fullCkpt, char * sigFileName)
{
  struct timeval timeStart, timeEnd;
  double timeSpent = 0.0;
  unsigned char hash[MD5_DIGEST_LENGTH];
  FullCkpt fckpt;
  IncrCkpt ickpt;

  if(COLLECTING_STATS) {
    gettimeofday(&timeStart, NULL);
  }

  HashInit();

  if(fullCkpt)
    fckpt.ReadCkptFileandHash(ckptFileName);
  else
    ickpt.ReadCkptFileandHash(ckptFileName);

  //create hash from file reader fcn
  HashFinal((unsigned char *) hash);

  bool verifyFlag = false; 
  int numBytes = 0;
  
  //get the previously computed signature
  unsigned char signature[RSA_BUF_SIZE];
  unsigned char temp[RSA_BUF_SIZE];
  
  //open the file
  int sigFd = open(sigFileName, O_RDONLY, S_IRUSR, S_IWUSR);
  //read the signature
  read(sigFd, signature, RSA_SIG_LENGTH);
  //close the file
  close(sigFd);
  
  RetrieveRSAkey();

  //first need to decrypt signed hash
  numBytes = DecryptWithRSA(RSA_SIG_LENGTH,
				      (unsigned char *)signature,
				      (unsigned char *)temp);
  
  //now check to find out if they are the same
  if(numBytes == MD5_DIGEST_LENGTH) {
    //it's a proper hash, so now we need to check it
    verifyFlag = true;
    for(int i=0; i < numBytes; i++) {
      verifyFlag = verifyFlag && (hash[i] == temp[i]);
    }
  }

  if(COLLECTING_STATS) {
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_CKPT_CHECK_HASH_STAT, 0, timeSpent);
  }

  return(verifyFlag);
  
}


void Security::SignAndRecordHash(char * sigFileName)
{
  struct timeval timeStart, timeEnd;
  double timeSpent = 0.0;

  if(COLLECTING_STATS) {
    gettimeofday(&timeStart, NULL);
  }

  //finalize out the hash function
  unsigned char hash[MD5_DIGEST_LENGTH];
  HashFinal((unsigned char *)hash);

  //signature is changed to the signed hash with numBytes length
  int numBytes = 0; 
  //create the signature
  unsigned char signature[RSA_BUF_SIZE];

  RetrieveRSAkey();

  //need to sign the digest;
  numBytes = EncryptWithRSA(MD5_DIGEST_LENGTH, 
				     (unsigned char *)hash, 
				     (unsigned char *)signature);

  //open the file
  int fd = open(sigFileName, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
  //write out the signature
  write(fd, signature, numBytes);
  //close the file
  close(fd);

  if(COLLECTING_STATS) {
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_CKPT_HASH_STAT, 0, timeSpent);
  }
}



//used by checkpoints
void Security::HashInit()
{  
  struct timeval timeStart, timeEnd;
  double timeSpent = 0.0;

  if(COLLECTING_STATS) {
    gettimeofday(&timeStart, NULL);
  }

  MD5_Init(&md);

  if(COLLECTING_STATS) {
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_CKPT_HASH_STAT, 0, timeSpent);
  }
}

//used by checkpoints
void Security::HashUpdate(void * data, 
			  unsigned long dataLength)
{
  struct timeval timeStart, timeEnd;
  double timeSpent = 0.0;

  if(COLLECTING_STATS) {
    gettimeofday(&timeStart, NULL);
  }

  MD5_Update(&md, (unsigned char *)data, dataLength);

  if(COLLECTING_STATS) {
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_CKPT_HASH_STAT, 0, timeSpent);
  }
}

//used by checkpoints
void Security::HashFinal(unsigned char * digest)
{  
  struct timeval timeStart, timeEnd;
  double timeSpent = 0.0;

  if(COLLECTING_STATS) {
    gettimeofday(&timeStart, NULL);
  }

  MD5_Final(digest, &md);

  if(COLLECTING_STATS) {
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_CKPT_HASH_STAT, 0, timeSpent);
  }
}




bool Security::VerifyDetChunksInFile(char * logFile) 
{
  struct timeval timeStart, timeEnd;
  double timeSpent = 0.0;
  bool result = true;
  int numDets = 0;
  int encBytes = 0;
  unsigned char * signature = new unsigned char[RSA_BUF_SIZE];
  unsigned char * encDigest = new unsigned char[RSA_BUF_SIZE];
  unsigned char * createdDigest = new unsigned char[MD5_DIGEST_LENGTH];
  Determinant d, temp;
  char * detBuf;
  struct stat fileInfo;

  if(COLLECTING_STATS) {
    gettimeofday(&timeStart, NULL);
  }

  int ifd = open(logFile, O_RDONLY, S_IRUSR | S_IWUSR);
  stat(logFile, &fileInfo);
  detBuf = mmap(NULL, fileInfo.st_size, PROT_READ, MAP_PRIVATE, ifd, 0);
  close(ifd);

  std::istrstream is(detBuf, fileInfo.st_size);

  char * sigFile = new char[EGIDA_FILENAME_LEN];
  sprintf(sigFile, "%s.%s", logFile, "hashes");
  int fd = open(sigFile, O_RDONLY, S_IRUSR, S_IWUSR);
  delete [] sigFile;

  while(1) {
    if(read(fd, &numDets, sizeof(int)) < sizeof(int))
      break;
    read(fd, signature, RSA_BUF_SIZE);
    encBytes = DecryptWithRSA(RSA_SIG_LENGTH, signature, encDigest);

    if(encBytes != MD5_DIGEST_LENGTH) {
      result = false;
      break;
    }

    MD5_Init(&detMD);

    for(int i=0; i < numDets; i++){

      d.Clear();

      if(ENCRYPT_DETERMINANTS) {
	temp.Clear();
	is >> temp;
	DecryptDeterminant(&d, &temp);
      }
      else {
	is >> d;
      }

      HashDetStruct(&d, detMD);
    }
    
    MD5_Final(createdDigest, &detMD);
    for(int j=0; j < MD5_DIGEST_LENGTH; j++) {
      result = result && (encDigest[j] == createdDigest[j]);
    }
    if(!result)
      break;
  }

  close(fd);
  delete [] createdDigest;
  delete [] encDigest;
  delete [] signature;

  if(COLLECTING_STATS) {
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_DETERMINANT_CHECK_HASH_STAT, 0, timeSpent);
  }

  return(result);
}
  


void Security::HashAndSignDetList(const Determinant_List &dl, 
				  unsigned char * signature, 
				  int & numDets)
{
  struct timeval timeStart, timeEnd;
  double timeSpent = 0.0;
  numDets = 0;
  Determinant_ListConstIterator e;
  Determinant *d;

  if(COLLECTING_STATS) {
    gettimeofday(&timeStart, NULL);
  }

  MD5_Init(&detMD);
  for(e = dl.begin(); e != dl.end(); e++) {
    d = *e;
    HashDetStruct(d, detMD);
    numDets++;
  }
  if(numDets > 0) {
    unsigned char * digest = new unsigned char[MD5_DIGEST_LENGTH];
    MD5_Final(digest, &detMD);
    EncryptWithRSA(MD5_DIGEST_LENGTH, 
			     (unsigned char *)digest, 
			     (unsigned char *)signature);
    delete [] digest;
  }

  if(COLLECTING_STATS) {
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_DETERMINANT_HASH_STAT, 0, timeSpent);
  }
}




void Security::HashSingleDetInit(void) 
{
  struct timeval timeStart, timeEnd;
  double timeSpent = 0.0;

  if(COLLECTING_STATS) {
    gettimeofday(&timeStart, NULL);
  }

  MD5_Init(&singleDetMD);

  if(COLLECTING_STATS) {
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_DETERMINANT_HASH_STAT, 0, timeSpent);
  }
}

void Security::HashSingleDet( Determinant * det)
{
  struct timeval timeStart, timeEnd;
  double timeSpent = 0.0;

  if(COLLECTING_STATS) {
    gettimeofday(&timeStart, NULL);
  }

  HashDetStruct(det, singleDetMD);

  if(COLLECTING_STATS) {
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_DETERMINANT_HASH_STAT, 0, timeSpent);
  }
}

void Security::HashSingleDetFinal(unsigned char * digest) 
{  
  struct timeval timeStart, timeEnd;
  double timeSpent = 0.0;

  if(COLLECTING_STATS) {
    gettimeofday(&timeStart, NULL);
  }

  MD5_Final(digest, &singleDetMD);

  if(COLLECTING_STATS) {
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_DETERMINANT_HASH_STAT, 0, timeSpent);
  }
}


void Security::RecreateHashDetInit(void) 
{
  struct timeval timeStart, timeEnd;
  double timeSpent = 0.0;

  if(COLLECTING_STATS) {
    gettimeofday(&timeStart, NULL);
  }

  MD5_Init(&detMD);

  if(COLLECTING_STATS) {
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_DETERMINANT_HASH_STAT, 0, timeSpent);
  }
}

void Security::RecreateHashSingleDet( Determinant * det)
{
  struct timeval timeStart, timeEnd;
  double timeSpent = 0.0;

  if(COLLECTING_STATS) {
    gettimeofday(&timeStart, NULL);
  }

  HashDetStruct(det, detMD);

  if(COLLECTING_STATS) {
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_DETERMINANT_HASH_STAT, 0, timeSpent);
  }
}

void Security::RecreateHashDetFinal(unsigned char * digest) 
{  
  struct timeval timeStart, timeEnd;
  double timeSpent = 0.0;

  if(COLLECTING_STATS) {
    gettimeofday(&timeStart, NULL);
  }

  MD5_Final(digest, &detMD);

  if(COLLECTING_STATS) {
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_DETERMINANT_HASH_STAT, 0, timeSpent);
  }
}


void Security::HashDetStruct(Determinant * d, MD5_CTX m)
{
  MD5_Update(&m, (unsigned char *) &d->source, sizeof(int));
  MD5_Update(&m, (unsigned char *) &d->dest, sizeof(int));
  MD5_Update(&m, (unsigned char *) &d->s_esn, sizeof(int));
  MD5_Update(&m, (unsigned char *) &d->d_esn, sizeof(int));
  if(d->eventSpecificSize > 0)
    MD5_Update(&m, (unsigned char *) d->eventSpecific, d->eventSpecificSize);
}





bool Security::VerifyEvInfoChunksInFile(char * logFile) 
{
  struct timeval timeStart, timeEnd;
  double timeSpent = 0.0;
  bool result = true;
  int numDets = 0;
  int encBytes = 0;
  unsigned char * signature = new unsigned char[RSA_BUF_SIZE];
  unsigned char * encDigest = new unsigned char[RSA_BUF_SIZE];
  unsigned char * createdDigest = new unsigned char[MD5_DIGEST_LENGTH];
  EventInfo e, temp;
  char * detBuf;
  struct stat fileInfo;

  if(COLLECTING_STATS) {
    gettimeofday(&timeStart, NULL);
  }

  int ifd = open(logFile, O_RDONLY, S_IRUSR | S_IWUSR);
  stat(logFile, &fileInfo);
  detBuf = mmap(NULL, fileInfo.st_size, PROT_READ, MAP_PRIVATE, ifd, 0);
  close(ifd);

  std::istrstream is(detBuf, fileInfo.st_size);

  char * sigFile = new char[EGIDA_FILENAME_LEN];
  sprintf(sigFile, "%s.%s", logFile, "hashes");

  int fd = open(sigFile, O_RDONLY, S_IRUSR, S_IWUSR);
  delete [] sigFile;

  while(1) {
    if(read(fd, &numDets, sizeof(int)) < sizeof(int))
      break;
    read(fd, signature, RSA_BUF_SIZE);
    encBytes = DecryptWithRSA(RSA_SIG_LENGTH, signature, encDigest);

    if(encBytes != MD5_DIGEST_LENGTH) {
      result = false;
      break;
    }

    MD5_Init(&evInfoMD);

    for(int i=0; i < numDets; i++){

      e.Clear();

      if(ENCRYPT_DETERMINANTS) {
	temp.Clear();
	is >> temp;
	DecryptEventInfo(&e, &temp);
      }
      else {
	is >> e;
      }

      HashEvInfoStruct(&e, detMD);
    }
    
    MD5_Final(createdDigest, &evInfoMD);
    for(int j=0; j < MD5_DIGEST_LENGTH; j++) {
      result = result && (encDigest[j] == createdDigest[j]);
    }
    if(!result)
      break;
  }

  close(fd);
  delete [] createdDigest;
  delete [] encDigest;
  delete [] signature;

  if(COLLECTING_STATS) {
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_EVENT_INFO_CHECK_HASH_STAT, 0, timeSpent);
  }
  return(result);
}
  


void Security::HashAndSignEvInfoList(const EventInfo_List &el, 
				     unsigned char * signature, 
				     int & numDets)
{
  struct timeval timeStart, timeEnd;
  double timeSpent = 0.0;
  numDets = 0;
  EventInfo_ListConstIterator lci;
  EventInfo *e;

  if(COLLECTING_STATS) {
    gettimeofday(&timeStart, NULL);
  }

  MD5_Init(&evInfoMD);
  for(lci = el.begin(); lci != el.end(); lci++) {
    e = *lci;
    HashEvInfoStruct(e, evInfoMD);
    numDets++;
  }
  if(numDets > 0) {
    unsigned char * digest = new unsigned char[MD5_DIGEST_LENGTH];
    MD5_Final(digest, &evInfoMD);
    EncryptWithRSA(MD5_DIGEST_LENGTH, 
			     (unsigned char *)digest, 
			     (unsigned char *)signature);
    delete [] digest;
  }

  if(COLLECTING_STATS) {
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_EVENT_INFO_HASH_STAT, 0, timeSpent);
  }
}




void Security::HashSingleEvInfoInit(void) 
{
  struct timeval timeStart, timeEnd;
  double timeSpent = 0.0;

  if(COLLECTING_STATS) {
    gettimeofday(&timeStart, NULL);
  }

  MD5_Init(&singleEvInfoMD);

  if(COLLECTING_STATS) {
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_EVENT_INFO_HASH_STAT, 0, timeSpent);
  }
}

void Security::HashSingleEvInfo( EventInfo * e)
{
  struct timeval timeStart, timeEnd;
  double timeSpent = 0.0;

  if(COLLECTING_STATS) {
    gettimeofday(&timeStart, NULL);
  }

  HashEvInfoStruct(e, singleEvInfoMD);

  if(COLLECTING_STATS) {
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_EVENT_INFO_HASH_STAT, 0, timeSpent);
  }
}

void Security::HashSingleEvInfoFinal(unsigned char * digest) 
{  
  struct timeval timeStart, timeEnd;
  double timeSpent = 0.0;

  if(COLLECTING_STATS) {
    gettimeofday(&timeStart, NULL);
  }
  MD5_Final(digest, &singleEvInfoMD);

  if(COLLECTING_STATS) {
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_EVENT_INFO_HASH_STAT, 0, timeSpent);
  }
}


void Security::RecreateHashEvInfoInit(void) 
{
  struct timeval timeStart, timeEnd;
  double timeSpent = 0.0;

  if(COLLECTING_STATS) {
    gettimeofday(&timeStart, NULL);
  }

  MD5_Init(&evInfoMD);

  if(COLLECTING_STATS) {
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_EVENT_INFO_HASH_STAT, 0, timeSpent);
  }
}

void Security::RecreateHashSingleEvInfo( EventInfo * e)
{
  struct timeval timeStart, timeEnd;
  double timeSpent = 0.0;

  if(COLLECTING_STATS) {
    gettimeofday(&timeStart, NULL);
  }

  HashEvInfoStruct(e, evInfoMD);

  if(COLLECTING_STATS) {
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_EVENT_INFO_HASH_STAT, 0, timeSpent);
  }
}


void Security::RecreateHashEvInfoFinal(unsigned char * digest) 
{  
  struct timeval timeStart, timeEnd;
  double timeSpent = 0.0;

  if(COLLECTING_STATS) {
    gettimeofday(&timeStart, NULL);
  }

  MD5_Final(digest, &evInfoMD);

  if(COLLECTING_STATS) {
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_EVENT_INFO_HASH_STAT, 0, timeSpent);
  }
}


void Security::HashEvInfoStruct(EventInfo * e, MD5_CTX m)
{
  MD5_Update(&m, (unsigned char *) &e->source, sizeof(int));
  MD5_Update(&m, (unsigned char *) &e->sourceEventId, sizeof(int));
  MD5_Update(&m, (unsigned char *) &e->otherProc, sizeof(int));
  MD5_Update(&m, (unsigned char *) &e->otherProcEventId, sizeof(int));
  if(e->pbSize > 0)
    MD5_Update(&m, (unsigned char *) e->pb, e->pbSize);
  if(e->infoSize > 0)
    MD5_Update(&m, (unsigned char *) e->info, e->infoSize);
}


