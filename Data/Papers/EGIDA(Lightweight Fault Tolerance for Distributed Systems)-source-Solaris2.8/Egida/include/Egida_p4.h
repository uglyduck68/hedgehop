/* Egida_p4.h -- 
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
 * $Log: Egida_p4.h,v $
 * Revision 1.1.1.1  2001/02/12 00:00:13  ravshank
 * Start of Spring 2001
 *
 * Revision 1.3  2000/10/12 19:50:49  phoebe
 * Optimistic is still not working for more than one failure, but the incarnation number is now working correctly, and on the second failure it hangs in exactly the same spot every time. Also...optimistic is now rolling back a checkpoint file instead of doing the exec-ing that it was doing before. Additionally, during some of the debugging process, checkpoints are now shrinking heap sizes correctly (we thought they were doing it before, but they weren't.)
 *
 * Revision 1.2  2000/06/23 02:47:25  phoebe
 * Wrapped all the statistics taking calls in all the functions so that they can either be turned on or off when desired.
 *
 * Revision 1.1.1.1  2000/03/06 20:00:16  phoebe
 * Sriram's original code with no modifications
 *
 * $Id: Egida_p4.h,v 1.1.1.1 2001/02/12 00:00:13 ravshank Exp $
 * Author          : Sriram Rao
 * Created On      : Sat May  1 12:02:56 1999
 * Last Modified By: Sriram Rao
 * Last Modified On: Fri Jul 16 16:04:37 1999
 * Update Count    : 18
 * Status          : Unknown, Use with caution!
 * PURPOSE
 * 	Function prototypes for the p4 functions used in Egida.
 */

#ifndef _EGIDA_P4_H
#define _EGIDA_P4_H

#ifdef  __cplusplus
extern "C" {
#endif

#include "p4_config.h"
#include "p4_MD.h"
#include "p4_sr_external.h"

  /* lifted from p4.h */
#define P4_TRUE 1
#define P4_FALSE 0 

#define MSG_OTHER P4NOX

  /* lifted from p4_funcs.h */
int p4_get_my_id(void);
int p4_num_total_slaves(void);
char *p4_msg_alloc(int msglen);
P4VOID p4_msg_free(char *m);
  //shouldn't we ahve p4_sendx here? like below....
  //int p4_sendx(int type, int to, char *msg, int len, int data_type);
  //   however...won't compile if I put this in.  PK 6-22-00
int send_message(int type, int from, int to, char *msg, int len, 
	   	 int data_type, P4BOOL ack_req, P4BOOL p4_buff_ind); 
int p4_broadcastx(int type, P4VOID *msg, int data_len, int data_type);
int p4_recv(int *req_type, int *req_from, char **msg, int *len_rcvd);
P4BOOL p4_messages_available(int *req_type, int *req_from);

void MPID_ArgSqueeze(int *argc, char **argv);
  /* My stuff */
void p4_DoRecovery(void);
void p4_RollbackActions(void);
void p4_post_init(void);
void recreate_rm_listener(void);
#ifdef  __cplusplus

};
#endif
#endif






