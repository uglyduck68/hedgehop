/*
 * Egida_API.h -- 
 *  Copyright (c) Sriram Rao
 *                This source is provided as is without any express or
 *                written warranty.  Permission to use, copy, modify, and 
 *                distribute this software for any purpose without fee is
 *                hereby granted, provided that this entire notice is 
 *                included in all copies of any software which is or includes
 *                a copy or modification of this software and in all copies
 *                of the supporting documentation for such software.
 *                All Rights Reserved.
 * $Locker:  $
 * $Log: Egida_API.h,v $
 * Revision 1.1.1.1  2001/02/12 00:00:13  ravshank
 * Start of Spring 2001
 *
 * Revision 1.1.1.1  2000/03/06 20:00:16  phoebe
 * Sriram's original code with no modifications
 *
 * $Id: Egida_API.h,v 1.1.1.1 2001/02/12 00:00:13 ravshank Exp $
 * Author          : Sriram Rao
 * Created On      : Thu Apr 29 15:33:13 1999
 * Last Modified By: Sriram Rao
 * Last Modified On: Wed Aug  4 21:48:25 1999
 * Update Count    : 31
 * Status          : Unknown, Use with caution!
 * PURPOSE
 * 	API exported by Egida.
 */

#ifndef _EGIDA_EXTERNAL_H
#define _EGIDA_EXTERNAL_H

#ifdef  __cplusplus
extern "C" {
#endif

  /* The arguments are input/output parameters */

void Egida_PreInit(int *argc, char ***argv);
void Egida_PostInit(int *argc, char ***argv);
void Egida_Terminate(void);

void egida_apploopstart_(void);
void Egida_AppLoopStart(void);

void Egida_Send(int dest, int tag, char *msg, int msgSize, int dataType);
  /* 
   * source, tag are input/output parameters.
   * source = -1 means any source; tag = -1 means any tag
   */
void Egida_Receive(int *source, int *tag, char **msg, int *msgSize);
void Egida_LogDeliveredMsg(char *msg);

int Egida_Msgs_Avail(int *from, int *tag);
void Egida_Broadcast(int type, char *msg, int msgSize, int dataType);

#ifdef  __cplusplus
}
#endif

#endif
