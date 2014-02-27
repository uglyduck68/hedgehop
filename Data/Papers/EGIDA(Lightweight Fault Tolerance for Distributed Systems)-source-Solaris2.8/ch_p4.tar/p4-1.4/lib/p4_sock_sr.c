
#include "p4.h"
#include "p4_sys.h"

/* Look for u_int xdr_len; some systems define as u_int, others as int */

#ifdef CAN_DO_XDR
int xdr_send(type, from, to, msg, len, data_type, ack_req)
char *msg;
int type, from, to, len, data_type, ack_req;
{
    int nbytes_written = 0;
    int flag, fd, myid;
    struct p4_net_msg_hdr nmsg;
    XDR *xdr_enc;
    xdrproc_t xdr_proc;
    char *xdr_buff;
    int xdr_elsize, els_per_buf, xdr_numels;
    int xdr_len1, len_bytes;
#if defined(SUN_SOLARIS) || defined(CRAY) || defined(SGI)
    u_int xdr_len;
#else
    int xdr_len;
#endif

    p4_dprintfl(20, "sending msg of type %d from %d to %d via xdr\n",
		type,from,to);

    myid = p4_get_my_id();
    fd = p4_local->conntab[to].port;

    nmsg.msg_type = p4_i_to_n(type);
    nmsg.to = p4_i_to_n(to);
    nmsg.from = p4_i_to_n(from);
    nmsg.imm_from = p4_i_to_n(p4_local->my_id);
    p4_dprintfl(30,"setting imm_from: to = %d, from = %d, imm_from = %d, p4_i_to_n(imm_from) =%d in xdr_send\n", to, from, p4_local->my_id, p4_i_to_n(p4_local->my_id));
    switch (data_type)
    {
      case P4INT:
	xdr_proc = xdr_int;
	xdr_elsize = XDR_INT_LEN;
	break;
      case P4LNG:
	xdr_proc = xdr_long;
	xdr_elsize = XDR_LNG_LEN;
	break;
      case P4FLT:
	xdr_proc = xdr_float;
	xdr_elsize = XDR_FLT_LEN;
	break;
      case P4DBL:
	xdr_proc = xdr_double;
	xdr_elsize = XDR_DBL_LEN;
	break;
      default:
	p4_dprintf("xdr_send: invalid data type %d\n", data_type);
	return (-1);
    }
    xdr_numels = len / xdr_elsize;
    nmsg.msg_len = p4_i_to_n(xdr_numels);
    nmsg.ack_req = p4_i_to_n(ack_req);
    nmsg.data_type = p4_i_to_n(data_type);

    flag = (myid < to) ? P4_TRUE : P4_FALSE;
    net_send(fd, &nmsg, sizeof(struct p4_net_msg_hdr), flag);

    xdr_enc = &(p4_local->xdr_enc);
    xdr_buff = p4_local->xdr_buff;
    els_per_buf = (XDR_BUFF_LEN - XDR_PAD) / xdr_elsize;
    while (xdr_numels > 0)
    {
	if (xdr_numels > els_per_buf)
	    xdr_len = els_per_buf;
	else
	    xdr_len = xdr_numels;
	xdr_len1 = xdr_len;	/* remember xdr_len */
	if (!xdr_setpos(xdr_enc, 0))
	{
	    p4_dprintf("xdr_send: xdr_setpos failed\n");
	    return (-1);
	}
	if (!xdr_array(xdr_enc, &msg, &xdr_len, XDR_BUFF_LEN,
		       xdr_elsize, xdr_proc))
	{
	    p4_dprintf("xdr_send: xdr_array failed\n");
	    return (-1);
	}
	len_bytes = xdr_getpos(xdr_enc);

	net_send(fd, xdr_buff, len_bytes, flag);

	nbytes_written += len_bytes;
	xdr_numels -= xdr_len1;
	msg = msg + len_bytes - XDR_PAD;
    }

    if (ack_req & P4_ACK_REQ_MASK)
    {
	wait_for_ack(fd);
    }
    p4_dprintfl(10, "sent msg of type %d from %d to %d via xdr\n",type,from,to);
    return (nbytes_written);
}
#endif

int socket_send(type, from, to, msg, len, data_type, ack_req)
int type, from, to, len, data_type, ack_req;
char *msg;
{
    int fd, flag;
    int sent = 0;
    int n;
    struct p4_net_msg_hdr nmsg;

    p4_dprintfl(20, "sending msg of type %d from %d to %d via socket\n",type,from,to);

    if (CHECKNODE(to) || CHECKNODE(from))
	p4_error("socket_send: bad header: to/from node is out of range",
		 to * 10000 + from);

    fd = p4_local->conntab[to].port;

    nmsg.msg_type = p4_i_to_n(type);
    nmsg.to = p4_i_to_n(to);
    nmsg.from = p4_i_to_n(from);
    nmsg.imm_from = p4_i_to_n(p4_local->my_id);
    nmsg.msg_len = p4_i_to_n(len);
    nmsg.ack_req = p4_i_to_n(ack_req);
    nmsg.data_type = p4_i_to_n(data_type);
    p4_dprintfl(30,"setting imm_from: to = %d, from = %d, imm_from = %d, p4_i_to_n(imm_from) =%d in socket_send\n", to, from, p4_local->my_id, p4_i_to_n(p4_local->my_id));
    flag = (from < to) ? P4_TRUE : P4_FALSE;
    n = net_send(fd, &nmsg, sizeof(struct p4_net_msg_hdr), flag);
    p4_dprintfl(20, "sent hdr for type %d from %d to %d via socket\n",type,from,to);

#ifdef OLD_SEND_CODE
    while (sent < len)
    {
	int nleft;
	if ((len - sent) > SOCK_BUFF_SIZE)
	    nleft = SOCK_BUFF_SIZE;
	else
	    nleft = len - sent;
	n = net_send(fd, ((char *) msg) + sent, nleft, flag);
	sent += n;
    }
#else
    /* Net_send now has backoff code for sending smaller blocks;
       this puts the "SOCK_BUFF_SIZE" dependencies into the net_send
       code, where they belong - WDG */
    if (n >= 0) {
      n = net_send(fd, (char *) msg, len, flag);
      sent += n;
    }
#endif
    /* Changed by Sriram---7/17/99 */
    /* Added n>=0 test;  if the receiver dies in the midst of the
     * send, net_send will return -1.  We don't want this process to
     * wait for an ack that may never show up.
    */
    if ((n >= 0) && (ack_req & P4_ACK_REQ_MASK))
    {
	wait_for_ack(fd);
    }

    p4_dprintfl(10, "sent msg of type %d from %d to %d via socket %d\n",type,from,to,fd);
    return (sent);
}

int socket_close_conn( fd )
int fd;
{
    struct p4_net_msg_hdr nmsg;

    printf("closing connection on fd: %d\n", fd);

    /* Most of this is ignored */
    nmsg.msg_type  = p4_i_to_n(0);
    nmsg.to	   = p4_i_to_n(0);
    /* The from fields may be tested, and it is useful to have them 
       anyway */
    nmsg.from	   = p4_i_to_n(p4_local->my_id);
    nmsg.imm_from  = p4_i_to_n(p4_local->my_id);
    nmsg.msg_len   = p4_i_to_n(0);
    nmsg.ack_req   = p4_i_to_n(P4_CLOSE_MASK);
    nmsg.data_type = p4_i_to_n(0);

    net_send(fd, &nmsg, sizeof(struct p4_net_msg_hdr), P4_FALSE );

    close( fd );

    return 0;
}

/*
   This code introduces some subtle problems.  The timeout on the select 
   is needed to catch changes in the established connections, but in this
   case, we need EINTR (interrupted system call) from the select to 
   just restart the call AFTER we've recomputed the read_fds.

   Changed by Sriram---7/17/99
   This function returns NULL if a failure is detected in the midst of a 
   receive.  That is, this calls socket_recv_on_fd to fetch messages
   and if that call fails, then this function returns NULL.
 */
struct p4_msg *socket_recv( is_blocking )
int is_blocking;
{
    int    i, fd, nfds;
    struct p4_msg *tmsg = NULL;
    P4BOOL found = P4_FALSE;
    struct timeval tv;
    fd_set read_fds;
    int    nactive;
    int    found_cmd = 0;
    int    timeout_sec = 9;

    while (!found)
    {

	tv.tv_sec = timeout_sec;
	tv.tv_usec = 0;  /* RMB */
	FD_ZERO(&read_fds);
	nactive = 0;
	for (i = 0; !tmsg && i < p4_global->num_in_proctable; i++)
	{
	    if (p4_local->conntab[i].type == CONN_REMOTE_EST)
	    {
		fd = p4_local->conntab[i].port;
		FD_SET(fd, &read_fds);
		nactive++;
	    }
	}
	/* If there is only one process, there will NEVER be any active
	   connections.  
	   Question: does this cover the case of multiple processes but
	   little communication between them, since the connections
	   are established dynamically? 
	 */
	if (!nactive && p4_global->num_in_proctable > 1)
	{
	    /* If we read a "close" and there are no connections left, 
	       silently exit */
	    if (found_cmd) return 0;

#if 1
	    /* Changed by Sriram -- 7/22/98 */
	    if (!is_blocking)
	      return 0;
	    /* wait and try again */
	    sleep(1);
	    continue;

#else
	    /* There are no active connections! If this is because
	       the active connections have all died, then we should exit.
	       Question: what if one connection has died "irregularly"? */
	    p4_dprintf(
"Trying to receive a message when there are no connections; Bailing out\n");
            p4_wait_for_end();
	    exit(0);
#endif
	}
	/* Run select; if interrupted, get read_fds (in case a connection
	   has occurred) and restart the connection */
	nfds = select(p4_global->max_connections, &read_fds, 0, 0, &tv);
	timeout_sec = 9;
	if (nfds == -1 && errno == EINTR) continue;

	if (nfds)
	{
	    for (i = 0; !tmsg && i < p4_global->num_in_proctable; i++)
	    {
		if (p4_local->conntab[i].type == CONN_REMOTE_EST)
		{
		    fd = p4_local->conntab[i].port;
		    if (FD_ISSET(fd,&read_fds)  &&  sock_msg_avail_on_fd(fd))
		    {
			tmsg = socket_recv_on_fd(fd);
			/* tmsg == NULL happens only if process i is dead */
			/* Added by Sriram---7/17/99 */
			if (tmsg == NULL)
			  return NULL;

			found = P4_TRUE;
			if (tmsg->ack_req & P4_ACK_REQ_MASK)
			{
			    send_ack(fd, tmsg->from);
			}
			if (tmsg->ack_req & P4_CLOSE_MASK) 
			{
			    p4_dprintfl(20,"Received close connection on %d\n",
					i );
			    p4_local->conntab[i].type = CONN_REMOTE_CLOSED;
			    /* Discard the message */
			    free_p4_msg( tmsg );
			    tmsg      = 0;
			    found     = P4_FALSE;
			    /* Remember that we found a command (see
			       code above for no connections) */
			    found_cmd = P4_TRUE;
			    /* Note that if we called this because we
			       found a message available, we may want
			       to return a "no more messages" without
			       doing a long wait. 
			     */
			    timeout_sec = 0;
			}
		    }
		}
	    }
	}
	else
	    if (found_cmd && !is_blocking) break;

    }
    return (tmsg);
}

struct p4_msg *socket_recv_on_fd(fd)
int fd;
{
    int n, data_type, msg_len;
    struct p4_msg *tmsg = NULL;
    struct p4_net_msg_hdr nmsg;

    n = net_recv(fd, &nmsg, sizeof(struct p4_net_msg_hdr));
    /* Modified by Sriram---7/17/99 */
    if (n < 0)
      return NULL;

    data_type = p4_n_to_i(nmsg.data_type);
    if (data_type == P4NOX)
	msg_len = p4_n_to_i(nmsg.msg_len);
    else
    {
	switch (data_type)
	{
	  case P4INT:
	    msg_len = p4_n_to_i(nmsg.msg_len) * XDR_INT_LEN;
	    break;
	  case P4LNG:
	    msg_len = p4_n_to_i(nmsg.msg_len) * XDR_LNG_LEN;
	    break;
	  case P4FLT:
	    msg_len = p4_n_to_i(nmsg.msg_len) * XDR_FLT_LEN;
	    break;
	  case P4DBL:
	    msg_len = p4_n_to_i(nmsg.msg_len) * XDR_DBL_LEN;
	    break;
	  default:
	    p4_error("socket_recv_on_fd: invalid data type %d\n", data_type);
	}
    }

    tmsg = alloc_p4_msg(msg_len);
    tmsg->type = p4_n_to_i(nmsg.msg_type);
    tmsg->to = p4_n_to_i(nmsg.to);
    tmsg->from = p4_n_to_i(nmsg.from);
    tmsg->len = p4_n_to_i(nmsg.msg_len);	/* chgd by xdr_recv below */
    tmsg->data_type = p4_n_to_i(nmsg.data_type);
    tmsg->ack_req = p4_n_to_i(nmsg.ack_req);
    p4_dprintfl(30,"recving imm_from: to = %d, from = %d, imm_from = %d, p4_n_to_i(imm_from) =%d in sock_recv_of_fd\n", tmsg->to, tmsg->from, nmsg.imm_from, p4_n_to_i(nmsg.imm_from));
    p4_dprintfl(30,"data_type = %d, same_rep = %d\n", tmsg->data_type,
		p4_local->conntab[p4_n_to_i(nmsg.imm_from)].same_data_rep);
    if (tmsg->data_type == P4NOX || 
	p4_local->conntab[p4_n_to_i(nmsg.imm_from)].same_data_rep)
    {
	n = net_recv(fd, (char *) &(tmsg->msg), tmsg->len);
	/* Modified by Sriram---7/17/99 */
	if (n < 0) {
	  free_p4_msg(tmsg);
	  tmsg = NULL;
	}
    }
    else
    {
#       ifdef CAN_DO_XDR
	n = xdr_recv(fd, tmsg);
#       else
	p4_error("cannot do xdr recvs\n",0);
#       endif
    }
    return (tmsg);
}

P4BOOL socket_msgs_available()
{
    int i, fd;
    int ndown = 0;

    for (i = 0; i < p4_global->num_in_proctable; i++)
    {
	if (p4_local->conntab[i].type == CONN_REMOTE_EST)
	{
	    fd = p4_local->conntab[i].port;
	    if (sock_msg_avail_on_fd(fd))
	    {
		return (P4_TRUE);
	    }
	}
	else if (p4_local->conntab[i].type == CONN_REMOTE_DYING) {
	    /* We need to detect that some are down... */
	    ndown++;
	    /* Now, what to do ? */
	    }
    }
    return (P4_FALSE);
}

/* Returns TRUE if a message available; returns TRUE if the socket is
 * dead.  It is upto the caller to figure out what to do.
*/
P4BOOL sock_msg_avail_on_fd(fd)
int fd;
{
    int i, rc, nfds;
    struct timeval tv;
    fd_set read_fds;
    char tempbuf[2];
    int tryCount = 0;

    rc = P4_FALSE;
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    FD_ZERO(&read_fds);
    FD_SET(fd, &read_fds);
    SYSCALL_P4(nfds, select(p4_global->max_connections, &read_fds, 0, 0, &tv));

    if (nfds == -1)
    {
	p4_error("sock_msg_avail_on_fd select", nfds);
    }
    if (nfds)			/* true even for eof */
    {
	/* see if data is on the socket or merely an eof condition */
	/* this should not loop long because the select succeeded */
	while ((rc = recv(fd, tempbuf, 1, MSG_PEEK)) == -1) {
          /*  this is a strange condition that can happen when
	   * a process fails.  
	   * we come in with an fd
	   * and the process that died is back up and
	   * the fd has changed.  we are now looking
	   * at fd that is invalid!  
	   * to get out of
	   * this loop, try a bunch of times and then
	   * give up.  */
	  tryCount++;
	  if (tryCount > 100) 
	    return P4_TRUE;
	}
	
	if (rc == 0)	/* if eof */
	{
	    /* eof; a process has closed its socket; may have died */
	    for (i = 0; i < p4_global->num_in_proctable; i++)
		if (p4_local->conntab[i].port == fd)
		{
		    p4_local->conntab[i].type = CONN_REMOTE_DYING;
		    printf("%s process %d is dead \n", whoami_p4,
			       i);
		    fflush(stdout);
		    /*
		    p4_error("tried to read from dead process",-1);
		    */
		}
	}
	else
	    rc = P4_TRUE;
    }
    return (rc);
}

#ifdef CAN_DO_XDR
int xdr_recv(fd, rmsg)
int fd;
struct p4_msg *rmsg;
{
    xdrproc_t xdr_proc;
    XDR *xdr_dec;
    char *xdr_buff, *msg;
    int n;
    int msg_len = 0, nbytes_read = 0;
    int xdr_elsize, els_per_buf, xdr_numels;
    int xdr_len1, len_bytes;
#if defined(SUN_SOLARIS) || defined(CRAY) || defined(SGI)
    u_int xdr_len;
#else
    int xdr_len;
#endif

    msg = (char *) &(rmsg->msg);

    xdr_dec = &(p4_local->xdr_dec);
    xdr_buff = p4_local->xdr_buff;
    switch (rmsg->data_type)
    {
      case P4INT:
	xdr_proc = xdr_int;
	xdr_elsize = XDR_INT_LEN;
	break;
      case P4LNG:
	xdr_proc = xdr_long;
	xdr_elsize = XDR_LNG_LEN;
	break;
      case P4FLT:
	xdr_proc = xdr_float;
	xdr_elsize = XDR_FLT_LEN;
	break;
      case P4DBL:
	xdr_proc = xdr_double;
	xdr_elsize = XDR_DBL_LEN;
	break;
      default:
	p4_dprintf("xdr_recv: invalid data type %d\n", rmsg->data_type);
	return (-1);
    }
    xdr_numels = rmsg->len;
    els_per_buf = (XDR_BUFF_LEN - XDR_PAD) / xdr_elsize;
    while (xdr_numels > 0)
    {
	if (xdr_numels > els_per_buf)
	    xdr_len = els_per_buf;
	else
	    xdr_len = xdr_numels;
	xdr_len1 = xdr_len;	/* remember xdr_len */

	len_bytes = (xdr_len * xdr_elsize) + XDR_PAD;
    	p4_dprintfl(90, "xdr_recv: reading %d bytes from %d\n", len_bytes, fd);
	n = net_recv(fd, xdr_buff, len_bytes);
	p4_dprintfl(90, "xdr_recv: read %d bytes \n", n);

	if (n < 0)
	{
	    p4_error("xdr_recv net_recv", n);
	}

	if (!xdr_setpos(xdr_dec, 0))
	{
	    p4_dprintf("xdr_recv: xdr_setpos failed\n");
	    return (-1);
	}

	if (!xdr_array(xdr_dec, &msg, &xdr_len, XDR_BUFF_LEN,
		       xdr_elsize, xdr_proc))
	{
	    p4_dprintf("xdr_recv: xdr_array failed\n");
	    return (-1);
	}

	nbytes_read += len_bytes;
	xdr_numels -= xdr_len1;
	msg = msg + len_bytes - XDR_PAD;
	msg_len = msg_len + len_bytes - XDR_PAD;
    }
    rmsg->len = msg_len;
    return (msg_len);
}
#endif

P4VOID wait_for_ack(fd)
int fd;
{
    struct p4_msg *ack;

    p4_dprintfl(30, "waiting for ack \n");
    ack = socket_recv_on_fd(fd);
    while (!(ack->ack_req & P4_ACK_REPLY_MASK))
    {
	queue_p4_message(ack, p4_local->queued_messages);
	ack = socket_recv_on_fd(fd);
    }
    ack->msg_id = (-1);
    free_p4_msg(ack);
    p4_dprintfl(30, "received ack from %d\n", ack->from);
}

P4VOID send_ack(fd, to)
int fd, to;
{
    struct p4_net_msg_hdr ack;

    p4_dprintfl(30, "sending ack to %d\n", to);
    ack.from = p4_i_to_n(p4_get_my_id());
    ack.data_type = p4_i_to_n(P4NOX);
    ack.msg_len = p4_i_to_n(0);
    ack.to = p4_i_to_n(to);
    ack.ack_req = p4_i_to_n(P4_ACK_REPLY_MASK);
    net_send(fd, &ack, sizeof(ack), P4_FALSE);
    p4_dprintfl(30, "sent ack to %d\n", to);
}

P4VOID shutdown_p4_socks()
/*
  Shutdown all sockets we know about discarding info
  in either direction.
  */
{
    int i;

    if (!p4_local)		/* Need info to be defined */
	return;
    if (!p4_local->conntab)
	return;
    if (p4_local->my_id == LISTENER_ID)
	return;

    for (i = 0; i < p4_num_total_ids(); i++)
	if (p4_local->conntab[i].type == CONN_REMOTE_EST)
	{
	    (P4VOID) shutdown(p4_local->conntab[i].port, 2);
	    (P4VOID) close(p4_local->conntab[i].port);
	}
}

/* Modified by Sriram---7/17/99 */
/* Returns true if connection to procId is dead */
P4BOOL p4_DeadConnection(int procId)
{
  if (procId < 0)
    /* what the hell is going on??? */
    return P4_FALSE;

  if ((p4_local->conntab[procId].type == CONN_REMOTE_DYING) || 
      (p4_local->conntab[procId].type == CONN_REMOTE_CLOSED))
    return P4_TRUE;

  return P4_FALSE;
}
