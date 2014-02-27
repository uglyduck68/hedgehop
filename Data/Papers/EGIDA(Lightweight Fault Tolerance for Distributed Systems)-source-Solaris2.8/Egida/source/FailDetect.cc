// FailDetect.cc -- 
//  Copyright (c) Sriram Rao
//                This source is provided as is without any express or
//                written warranty.  Permission to use, copy, modify, and 
//                distribute this software for any purpose without fee is
//                hereby granted, provided that this entire notice is 
//                included in all copies of any software which is or includes
//                a copy or modification of this software and in all copies
//                of the supporting documentation for such software.
//                All Rights Reserved.
// $Locker:  $
// $Log: FailDetect.cc,v $
// Revision 1.1.1.1  2001/02/12 00:00:19  ravshank
// Start of Spring 2001
//
// Revision 1.6  2000/10/24 16:32:28  phoebe
// Garbage collection of the sentLog is now happening but sometimes it doesn't recover...think it's a problem with multiple recoveries and not flushing some info. Will check into it. Fixed the memcpy core dump on taking a checkpoint...it was a problem with the fact that we were using a signed int to track the segment size and should have been using an unsigned int so that we didn't get overflow problem.
//
// Revision 1.5  2000/10/17 15:02:32  phoebe
// Stable code checkin. RBP is extremely stable except if you kill the master and slave at exactly the same time....it will hang in ReplayDeliver. SBP cannot support concurrent failures due to the lost control messages or hanging in ReplayDeliver. Causal can do +concurrent+ failures as long as control messages are not lost....so the restart must be staggered. Causal seems to suffer the same RBP problem with a master/slave pair, but unsure if this is the problem or if I didn't set numfailures=2...think the later would fix this. All the sentLog protocols (SBP and Causal) suffer from processes dumping core during WriteCkpt if they have been running for a long time since we are not flushing volatile memory at the moment. Should go away with the proper sentLog class fix.
//
// Revision 1.4  2000/09/29 00:20:13  phoebe
// Optimistic will now recover from the first failure...but not multiple sequential failures.
//
// Revision 1.3  2000/07/11 22:20:05  phoebe
// Did several things: Streamlined DebugTrace so that Egida_Object's RestoreDone didnt' need to call it (got rid of a small memory leak by doing this.) It's less efficient, but then debugging code shouldn't be in the release copy anyway. Two...moved the -recover string to the proper place in the failuredetector so that on a subsequent restart (multiple restarts of one process) it will correctly identify which checkpoint it should be rolling back to. Third...moved growing of the heap in CkptImpl to the RestoreHeapData segs for FullCkpt and put it in the RestoreCkpt for Incremental (in the loop). This is in hopes of being able to restart from in incremental checkpoint. At the moment still can't restart multilple times and can't restart from an incremental checkpoint.
//
// Revision 1.2  2000/06/30 21:00:23  phoebe
// Changed when the FailureDetector is notified of the new checkpoint. It's now in a place where we could delete checkpoint files without any repercussions since the cleanup would be in the pbLog object most likely. Also, the failure detector now re-establishes the socket parameters after a failure whereas before it did not.
//
// Revision 1.1  2000/06/27 13:23:07  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.4  2000/06/26 21:31:08  phoebe
// Egida_Internal functions are now part of the Egida class and thus are contained in Egida_Object.cc. All data memebers of the Egida class are now private.
//
// Revision 1.3  2000/06/26 14:56:02  phoebe
// More slight changes. Cleaned up Init.cc by moving path definitions to Egida_Globals.H. There are also some other small changes that I can't remember at the moment.
//
// Revision 1.2  2000/06/23 00:18:09  phoebe
// Made namespace Egida_FailDetect into proper class called FailDetect.
//
// Revision 1.1.1.1  2000/03/06 20:00:18  phoebe
// Sriram's original code with no modifications
//
// $Id: FailDetect.cc,v 1.1.1.1 2001/02/12 00:00:19 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Sun Apr 25 16:12:14 1999
// Last Modified By: Sriram Rao
// Last Modified On: Thu Aug 26 13:20:01 1999
// Update Count    : 77
// Status          : Unknown, Use with caution!
// PURPOSE
// 	Egida's side of the failure detector code.  The failure
// 	detector program has its own main---the code for that is in
// 	FailureDetector.cc 

#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <iostream>
#include <strstream>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <unistd.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/utsname.h>

#include "FailDetect.H"
#include "Globals.H"
#include "SocketUtil.H"


//static data members of FailDetect
int FailDetect::failureDetectSkt = -1;

void FailDetect::Setup_FailureDetector(const char *programName)
{
  int skt;
  char fileName[EGIDA_FILENAME_LEN], portName[EGIDA_FILENAME_LEN];
  char execName[EGIDA_FILENAME_LEN];
  int fromlen;
  struct sockaddr from;
  struct sockaddr_in ourAddr;

  // create a socket and bind it to a port.
  memset(&ourAddr, 0, sizeof(struct sockaddr_in));
  ourAddr.sin_family = AF_INET;
  ourAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  ourAddr.sin_port = htons(0); // server will put the address here

  skt = socket(PF_INET, SOCK_STREAM, 0);
  bind(skt, (struct sockaddr *) &ourAddr, sizeof(ourAddr));
  listen(skt, 1);

  if (fork() == 0) {
    if (chdir(EGIDA_APPL_BIN_DIR) != 0) {
      std::cout << "Chdir to: " << EGIDA_APPL_BIN_DIR << " didn't work! " << 
	errno << std::endl;
    }

    fromlen = sizeof(struct sockaddr_in);
    getsockname(skt,(struct sockaddr *)&ourAddr, &fromlen);
    sprintf(portName, "%d", ntohs(ourAddr.sin_port));
    strcpy(execName, "FailureDetector");
#if 0
    // doesn't work with execlp on mriga
    if (execlp(execName, execName, programName, portName, NULL) < 0) {
      std::cout << "trouble firing off the failure detector.." << errno << std::endl;
    }
#else
    FailureDetector(programName, portName);
#endif
    _exit(0);
  }
  else {
    fromlen = sizeof(struct sockaddr);
    if ((failureDetectSkt = accept(skt, (struct sockaddr *)
				    &from, &fromlen)) < 0) {
      std::cout << "Parent having trouble connecting to failure detector " << errno << std::endl;
      _exit(0);
    }
    fromlen = 65536;
    WriteBytes(failureDetectSkt, (const char *) &fromlen, sizeof(int));

    setsockopt(failureDetectSkt, SOL_SOCKET, SO_RCVBUF, 
	       (const char *) &fromlen, sizeof(int));
    setsockopt(failureDetectSkt, SOL_SOCKET, SO_SNDBUF, 
	       (const char *) &fromlen, sizeof(int));
    
  }
}

void FailDetect::Resetup_FailureDetector()
{
  char hostName[MAXHOSTNAMELEN], fileName[2 * MAXHOSTNAMELEN];
  struct in_addr inetAddr;
  struct sockaddr_in destAddr;
  struct hostent *hostInfo;
  int fromlen;
  int fd, portNo;

  // read the port # from the file that the failure detector wrote for us
  gethostname(hostName, MAXHOSTNAMELEN);
  sprintf(fileName, "%s.fdPort", hostName);
  if ((fd = open(fileName, O_RDONLY)) < 0) {
    std::cout << "Unable to connect back to failure detector" <<
      std::endl;
    std::cout << "Failure detector isn't running?" << std::endl;
    return;
  }
  read(fd, &portNo, sizeof(int));
  close(fd);
  unlink(fileName);
  // do the connect stuff
  hostInfo = gethostbyname(hostName);
  // convert the name to inet "." format
  memcpy(&inetAddr.s_addr, *hostInfo->h_addr_list, 
         sizeof(inetAddr.s_addr));
  strncpy(hostName, (char *) inet_ntoa(inetAddr), 
          MAXHOSTNAMELEN * sizeof(char));

  memset(&destAddr, 0, sizeof(struct sockaddr_in));
  // fill in the fields for calling connect
  destAddr.sin_family = AF_INET;
  destAddr.sin_addr.s_addr = inet_addr(hostName);
  destAddr.sin_port = htons(portNo);

  failureDetectSkt = socket(PF_INET, SOCK_STREAM, 0);

  if ((connect(failureDetectSkt, 
	       (struct sockaddr *) &destAddr, sizeof(struct sockaddr_in))) < 0) {
    std::cout << "trouble connecting failure detector back to parent..." << 
      std::endl;
    _exit(0);
  }
  fromlen = 65536;
  setsockopt(failureDetectSkt, SOL_SOCKET, SO_RCVBUF, (const char *) &fromlen,
	     sizeof(int));
  setsockopt(failureDetectSkt, SOL_SOCKET, SO_SNDBUF, (const char *) &fromlen,
	     sizeof(int));
  free(hostInfo);
}

void FailDetect::SendCkptFileName(const char *ckptFileName)
{
  int ckptMessage = EGIDA_FAIL_DETECT_CKPT_FILE_MSG;
  int parentPid = getpid();

  if (failureDetectSkt > 0) {
    WriteBytes(failureDetectSkt, (const char *) &ckptMessage,
	       sizeof(int));
    WriteBytes(failureDetectSkt, (const char *) &parentPid,
	       sizeof(int));
    WriteBytes(failureDetectSkt, ckptFileName,
	       EGIDA_FILENAME_LEN);
  }
}


void FailDetect::SendRollbackMsg(const char *ckptFileName)
{
  int rollbackMessage = EGIDA_FAIL_DETECT_ROLLBACK_MSG;
  int parentPid = getpid();

  if (failureDetectSkt > 0) {
    WriteBytes(failureDetectSkt, (const char *) &rollbackMessage,
	       sizeof(int));
    WriteBytes(failureDetectSkt, (const char *) &parentPid,
	       sizeof(int));
    WriteBytes(failureDetectSkt, ckptFileName,
	       EGIDA_FILENAME_LEN);
  }
}


void FailDetect::Terminate()
{
  int dieMessage = EGIDA_FAIL_DETECT_DIE_MSG;

  if (failureDetectSkt > 0) {
    WriteBytes(failureDetectSkt, (const char *) &dieMessage,
	       sizeof(int));
    close(failureDetectSkt);
    failureDetectSkt = -1;
  }
}

void FailDetect::FailureDetector(const char *programName, const char *pName)
{
  int portNo, watchedProcId;
  fd_set readFds;
  int i, fd, fdPort, nfds, skt;
  int status, msgType = 0;
  char fileName[EGIDA_FILENAME_LEN];
  char portFileName[EGIDA_FILENAME_LEN];
  char parentProg[EGIDA_FILENAME_LEN], hostName[MAXHOSTNAMELEN], portName[MAXHOSTNAMELEN];
  struct in_addr inetAddr;
  struct sockaddr_in destAddr, ourAddr;
  struct sockaddr from;
  struct hostent *hostInfo;
  int fromlen, myParentId;
  bool failureDetected = false;
  bool rollbackFlag = false;
  std::ostrstream os;
  struct sigaction act;
  struct timeval timeout;

#if 0
  parentProg = argv[1];
  portNo = atoi(argv[2]);
#else
  strcpy(parentProg, programName);
  portNo = atoi(pName);
#endif
  watchedProcId = getppid();
  // ignore SIGHUP which gets sent to us when the parent dies
      
  signal(SIGHUP, SIG_IGN);
  // ignore SIGPIPE that is sent to us when the socket breaks
  signal(SIGPIPE, SIG_IGN);
  // connect back to the parent
  gethostname(hostName, MAXHOSTNAMELEN);

  memset(fileName, 0, EGIDA_FILENAME_LEN);

  std::cout << "failure detector started on " << hostName << ' ' <<
      getpid() << ' ' << watchedProcId << std::endl;

  hostInfo = gethostbyname(hostName);
  // convert the name to inet "." format
  memcpy(&inetAddr.s_addr, *hostInfo->h_addr_list, 
         sizeof(inetAddr.s_addr));
  strncpy(hostName, (char *) inet_ntoa(inetAddr), 
          MAXHOSTNAMELEN * sizeof(char));

  memset(&destAddr, 0, sizeof(struct sockaddr_in));
  // fill in the fields for calling connect
  destAddr.sin_family = AF_INET;
  destAddr.sin_addr.s_addr = inet_addr(hostName);
  destAddr.sin_port = htons(portNo);

  fd = socket(PF_INET, SOCK_STREAM, 0);

  if ((connect(fd, (struct sockaddr *) &destAddr, sizeof(struct sockaddr_in))) < 0) {
    std::cout << "trouble connecting failure detector back to parent..." << 
      std::endl;
    _exit(0);
  }
  ReadBytes(fd, (char *) &i, sizeof(int));
  fromlen = 65536;
  setsockopt(fd, SOL_SOCKET, SO_RCVBUF, (const char *) &fromlen,
	     sizeof(int));
  setsockopt(fd, SOL_SOCKET, SO_SNDBUF, (const char *) &fromlen,
	     sizeof(int));
  while (1) {
    FD_ZERO(&readFds);
    FD_SET(fd, &readFds);
    // wait infinitely.  select checks in the range of 0 to fd and fd
    // is the one we want tested.
    timeout.tv_sec = 5;
    timeout.tv_usec = 0;
    nfds = select(fd + 1, &readFds, 0, 0, &timeout);
    if (((status = sigsend(P_PID, watchedProcId, 0)) < 0) &&
	(errno == ESRCH)) 
      std::cout << "Parent is dead???: nfds = " << nfds << std::endl;

    if (FD_ISSET(fd, &readFds)) {
      if ((status = ReadBytes(fd, (char *) &msgType, sizeof(int))) ==
	  sizeof(int)) {
	switch(msgType) {
	case EGIDA_FAIL_DETECT_DIE_MSG:
	  std::cout << "failure detector dying..." << std::endl;
	  sleep(2);
	  close(fd);
	  _exit(0);
	case EGIDA_FAIL_DETECT_CKPT_FILE_MSG:
	  ReadBytes(fd, (char *)&myParentId, sizeof(int));
	  ReadBytes(fd, fileName, EGIDA_FILENAME_LEN);
	  if (myParentId != watchedProcId)
	   watchedProcId = myParentId;
	  // std::cout << "filename command: " << fileName << std::endl;
	  break;
	case EGIDA_FAIL_DETECT_ROLLBACK_MSG:
	  ReadBytes(fd, (char *)&myParentId, sizeof(int));
	  ReadBytes(fd, fileName, EGIDA_FILENAME_LEN);
	  if (myParentId != watchedProcId)
	   watchedProcId = myParentId;
	  rollbackFlag = true;
	  break;
	default:
	  std::cout << "unknown command..." << std::endl;
	  break;
	}
      }
    }

    if(!rollbackFlag) {      
      // whoa ... the parent might be dead
      if (((status = sigsend(P_PID, watchedProcId, 0)) < 0) &&
	  (errno == ESRCH)) {
	failureDetected = true;

	//we need to be REALLY SURE that the parent is dead????
	for (i = 0; i < 10; i++) {
	  if (((status = sigsend(P_PID, watchedProcId, 0)) < 0) &&
	      (errno == ESRCH)) {
	    sleep(1);
	    continue;
	  }
	  else
	    failureDetected = false;

	  if (!failureDetected)
	    continue;
	}
      
	skt = socket(PF_INET, SOCK_STREAM, 0);
	// have to bind the socket and make it listenable.
	memset(&ourAddr, 0, sizeof(struct sockaddr_in));
	ourAddr.sin_family = AF_INET;
	ourAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	ourAddr.sin_port = htons(0); // server will put the address here
	bind(skt, (struct sockaddr *) &ourAddr, sizeof(ourAddr));
	listen(skt, 1);
	
	// restart the watchedProcess
	std::cout << "parent died.  need to restart" << std::endl;
	if ((watchedProcId = fork()) == 0) {
	  // we are in the child
	  
	  os << "-recover=" << fileName << std::ends;
	  fromlen = sizeof(struct sockaddr_in);
	  getsockname(skt,(struct sockaddr *)&ourAddr, &fromlen);
	  gethostname(hostName, MAXHOSTNAMELEN);
	  sprintf(fileName, "%s.fdPort", hostName);
	  if ((fd = open(fileName, O_CREAT | O_WRONLY, S_IRUSR |
			 S_IWUSR)) < 0) {
	    assert(0);
	  }
	  fdPort = ntohs(ourAddr.sin_port);
	  write(fd, &fdPort, sizeof(int));
	  close(fd);
	  
	  std::cout << "restarting : " << parentProg << std::endl;
	  
	  if (execlp(parentProg, parentProg, os.str(), NULL) < 0)
	    {
	      std::cout << "unable to restart file name" << std::endl;
	      _exit(0);
	    }
	}
	else {

	  // re-establish the socket.
	  close(fd);
	  fromlen = sizeof(struct sockaddr);
	  fd = accept(skt, (struct sockaddr *) &from, &fromlen);
	  setsockopt(fd, SOL_SOCKET, SO_RCVBUF, (const char *) &fromlen,
		     sizeof(int));
	  setsockopt(fd, SOL_SOCKET, SO_SNDBUF, (const char *) &fromlen,
		     sizeof(int));
	}
      } 
    }
    else { //rollback flag is true      
      int fileDescriptor;

      skt = socket(PF_INET, SOCK_STREAM, 0);
      // have to bind the socket and make it listenable.
      memset(&ourAddr, 0, sizeof(struct sockaddr_in));
      ourAddr.sin_family = AF_INET;
      ourAddr.sin_addr.s_addr = htonl(INADDR_ANY);
      ourAddr.sin_port = htons(0); // server will put the address here
      bind(skt, (struct sockaddr *) &ourAddr, sizeof(ourAddr));
      listen(skt, 1);

      getsockname(skt,(struct sockaddr *)&ourAddr, &fromlen);
      gethostname(hostName, MAXHOSTNAMELEN);
      sprintf(portFileName, "%s.fdPort", hostName);
      if ((fileDescriptor = open(portFileName, O_CREAT | O_WRONLY, S_IRUSR |
		     S_IWUSR)) < 0) {
	assert(0);
      }
      fdPort = ntohs(ourAddr.sin_port);
      write(fileDescriptor, &fdPort, sizeof(int));
      close(fileDescriptor);

      // re-establish the socket.
      fromlen = sizeof(struct sockaddr);
      fd = accept(skt, (struct sockaddr *) &from, &fromlen);
      setsockopt(fd, SOL_SOCKET, SO_RCVBUF, (const char *) &fromlen,
		 sizeof(int));
      setsockopt(fd, SOL_SOCKET, SO_SNDBUF, (const char *) &fromlen,
		 sizeof(int));
      rollbackFlag = false;
    }
  }
}
  



