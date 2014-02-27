#include "p4.h"
#include "p4_sys.h"

#include <assert.h>

/* This routine gies us a way to timeout a loop */
#include <sys/time.h>
#ifndef TIMEOUT_VALUE 
#define TIMEOUT_VALUE 300
#endif
int p4_has_timedout ANSI_ARGS(( int ));
int p4_establish_all_conns ANSI_ARGS(( void ));

int p4_has_timedout( flag )
int flag;
{
    static time_t start_time;
    time_t curtime;
    curtime = time((time_t)0);
    if (flag) {
	if (curtime - start_time > TIMEOUT_VALUE) return 1;
    }
    else
	start_time = curtime;
    return 0;
}

int p4_establish_all_conns()
{
    int myid = p4_get_my_id();
    int i, old_debug_level = p4_debug_level;

    /* to avoid crashes due to failed processes */
    signal(SIGPIPE, SIG_IGN);

    /* p4_debug_level = 100; */
    for (i = 0; i < p4_global->num_in_proctable; i++) {
	printf("establishing early connection to %d\n",i);
	if (!in_same_cluster(i,myid)) {
	    p4_dprintfl(20,"establishing early connection to %d\n",i);
	    printf("establishing early connection to %d\n",i);
	    /* establish_connection(i); */
	    /* Added by Sriram on 7/21/98 */
	    while (1) {
	      establish_connection(i);
	      if (p4_local->conntab[i].type == CONN_REMOTE_EST) {
		p4_dprintfl(20, "%s connection to %d established! \n", whoami_p4,i);
		printf("%s connection to %d established! \n", whoami_p4,i);
		break;
	      }
	      /* wait for a sec... */
	      /*
	      else
		sleep(1);
	      */
	    }
	}
    }
    p4_debug_level = old_debug_level;

    return 0;
}

int establish_connection(dest_id)
int dest_id;
{
    int myid = p4_get_my_id();

    p4_global->dest_id[myid] = dest_id;
    request_connection(dest_id);
    p4_global->dest_id[myid] = (-1);

    if (myid > dest_id)
    {
	/* following should not spin long */
        p4_has_timedout( 0 );
	while (p4_local->conntab[dest_id].type == CONN_REMOTE_NON_EST) {
	  /* p4_dprintfl(70, "waiting for interrupt handler to do its job\n"); */
	  if (p4_has_timedout( 1 )) {
	    /* p4_error( "Timeout in establishing connection to remote process", 0 ); */
	    printf("Timeout in establishing connection to remote process %d \n", dest_id); 
	  }
	}
    }
    return (P4_TRUE);
}


P4VOID request_connection(dest_id)
int dest_id;
{
    struct proc_info *my_pi, *dest_pi;
    char *my_host, *dest_host;
    int my_id;
    struct slave_listener_msg msg;
    int connection_fd;
    int dest_listener_con_fd;
    int my_listener, dest_listener;
    int new_listener_port, new_listener_fd;
    int oldmask;
    int num_tries;

#   ifdef P4SYSV
    sighold(LISTENER_ATTN_SIGNAL);
#   else
    oldmask = sigblock(sigmask(LISTENER_ATTN_SIGNAL));
#   endif

    /* Get some initial information */
    my_id = p4_get_my_id();
    my_pi = get_proc_info(my_id);
    my_host = my_pi->host_name;
    my_listener = my_pi->port;

    dest_pi = get_proc_info(dest_id);
    dest_host = dest_pi->host_name;
    dest_listener = dest_pi->port;

    /*    printf("request_connection: dest_id=%d, dest_host=%s \n", dest_id, dest_host); */

    p4_dprintfl(70, "request_connection: my_id=%d my_host=%s my_listener=%d dest_id=%d dest_host=%s dest_listener=%d\n",
	    my_id, my_host, my_listener, dest_id, dest_host, dest_listener);
    
    if (my_id != 0)
      printf("request_connection: my_id=%d my_host=%s my_listener=%d dest_id=%d dest_host=%s dest_listener=%d\n",
	     my_id, my_host, my_listener, dest_id, dest_host, dest_listener);

    /* Have we already connected?? */
    if (p4_local->conntab[dest_id].type == CONN_REMOTE_EST)
    {
	p4_dprintfl(70,"request_connection %d: already connected\n", dest_id);
#       ifdef P4SYSV
        sigrelse(LISTENER_ATTN_SIGNAL);
#       else
	sigsetmask(oldmask);
#       endif
	return;
    }

    p4_dprintfl(70, "enter loop to connect to dest listener %s\n",dest_host);
    /* Connect to dest listener */
    num_tries = 1;
    p4_has_timedout( 0 );
    while((dest_listener_con_fd = net_conn_to_listener(dest_host,dest_listener,1)) == -1) {
	num_tries++;
#if 0
	/* This was in the originial distribution -- Sriram 7/21/98 */
	if (p4_has_timedout( 1 )) {
	    p4_error( "Timeout in establishing connection to remote process", 0 );
	    }
#else
	/* try connecting a few times; if it fails return */
	if ((num_tries > 3) || (p4_has_timedout( 1 ))) {
	  /* since we are enabling the handle_connection_interrupt, turn */
	  /* off the claim that we were trying to connect to dest */
	  p4_global->dest_id[my_id] = (-1);
#       ifdef P4SYSV
	  sigrelse(LISTENER_ATTN_SIGNAL);
#       else
	  sigsetmask(oldmask);
#       endif
	  if (errno == ECONNREFUSED) {
	    printf("%s net-conn-to-list failed: %d \n", whoami_p4, errno);
	    printf("request_connection: my_id=%d my_host=%s my_listener=%d dest_id=%d dest_host=%s dest_listener=%d\n",
		   my_id, my_host, my_listener, dest_id, dest_host, dest_listener);
	    sleep(5);
	  }
	  return;
	}
#endif
    }
    p4_dprintfl(70, "conn_to_proc_contd: connected after %d tries, dest_listener_con_fd=%d\n",num_tries, dest_listener_con_fd);


    /* Setup a listener to accept the connection to dest_id */
    net_setup_anon_listener(1, &new_listener_port, &new_listener_fd);

    /* Construct a connection request message */
    msg.type = p4_i_to_n(CONNECTION_REQUEST);
    msg.from = p4_i_to_n(my_id);
    msg.lport = p4_i_to_n(new_listener_port);
    msg.to = p4_i_to_n(dest_id);
    msg.to_pid = p4_i_to_n(dest_pi->unix_id);
    /* Added by Sriram---7/16/99 */
    strcpy(msg.host_name, my_host);

    /* Send it to dest_id's listener */
    p4_dprintfl(70, "request_connection: sending CONNECTION_REQUEST to %d on fd=%d size=%d\n",
		dest_id,dest_listener_con_fd,sizeof(msg));
    net_send(dest_listener_con_fd, &msg, sizeof(msg), P4_FALSE);
    p4_dprintfl(70, "request_connection: sent CONNECTION_REQUEST to dest_listener\n");

    if (my_id < dest_id)
    {
	/* Wait for the remote process to connect to me */
	p4_dprintfl(70, "request_connection: waiting for accept from %d \n",dest_id);
	connection_fd = net_accept(new_listener_fd);
	p4_dprintfl(70, "request_connection: accepted from %d on %d\n", dest_id, connection_fd);

	/* Add the connection to the table */
	p4_local->conntab[dest_id].port = connection_fd;
	p4_local->conntab[dest_id].same_data_rep =
	    same_data_representation(p4_local->my_id,dest_id);
	p4_local->conntab[dest_id].type = CONN_REMOTE_EST;
    }

    close(dest_listener_con_fd);
    /* Now release the listener connections */
    close(new_listener_fd);

#   ifdef P4SYSV
    sigrelse(LISTENER_ATTN_SIGNAL);
#   else
    sigsetmask(oldmask);
#   endif

    p4_dprintfl(70, "request_connection: finished connecting\n");
    return;
}

/* sig isn't used except to match the function prototypes for POSIX
   signal handlers */
P4VOID handle_connection_interrupt( sig )
int sig;
{
    struct slave_listener_msg msg;
    int type;
    int listener_fd;
    int to, to_pid, from, lport;
    int connection_fd;
    struct proc_info *from_pi;
    int myid = p4_get_my_id();
    int num_tries;
    int dbg_level = p4_get_dbg_level();

    p4_lock(&p4_global->conntab_lock);

    /* p4_set_dbg_level(90); */
    
    listener_fd = p4_local->listener_fd;
    p4_dprintfl(70, "Inside handle_connection_interrupt, listener_fd=%d\n",
		listener_fd);

    if (net_recv(listener_fd, &msg, sizeof(msg)) == PRECV_EOF)
    {
	p4_dprintf("OOPS: got eof in handle_connection_interrupt\n");

	p4_set_dbg_level(dbg_level);
	p4_unlock(&p4_global->conntab_lock);
	return;
    }

    type = p4_n_to_i(msg.type);
    
    /* added by Sriram on 7/21/98 */
    if (type == PROC_TABLE_BEGIN) {
      printf("%s re-receving proc table \n", whoami_p4);
      re_receive_proc_table(listener_fd);
      /* dump_global(0); */

      msg.type = p4_i_to_n(IGNORE_THIS);
      
      p4_set_dbg_level(dbg_level);
      p4_unlock(&p4_global->conntab_lock);
      /* If the return from this is SIG_DFL, then there is a problem ... */
      SIGNAL_P4(LISTENER_ATTN_SIGNAL, handle_connection_interrupt);

      /*
       * Order here is important.  To avoid deadlocks, the conntab has
       * to be unlocked before a message is sent to the listener.
      */
      p4_dprintfl(70, "handle_connection_interrupt: sending IGNORE_THIS to my_listener\n");
      /* send msg to listener indicating that the interrupt has been handled */
      net_send(listener_fd, &msg, sizeof(msg), P4_FALSE);
      p4_dprintfl(70, "handle_connection_interrupt: exiting handling intr from %d\n",from);

      return;
    }

    if (type != CONNECTION_REQUEST)
    {
	p4_dprintf("handle_connection_interrupt: invalid type %d\n",
		   type);
	p4_set_dbg_level(dbg_level);
	p4_unlock(&p4_global->conntab_lock);
	return;
    }

    to = p4_n_to_i(msg.to);
    from = p4_n_to_i(msg.from);
    to_pid = p4_n_to_i(msg.to_pid);
    lport = p4_n_to_i(msg.lport);

    p4_dprintfl(70, "handle_connection_interrupt: msg contents: to=%d from=%d to_pid=%d lport=%d\n",
		to, from, to_pid, lport);

    /* Get the information for the process we're connecting to */
    from_pi = &(p4_global->proctable[from]);

    /* If we're already connected, forget about the interrupt. */
    /* what if the listener port has changed?? -- Added by Sriram 7/31/98 */
    /* 
     * Taking the "or" is due to a race condition: the global proc
     * table has potentially changed and bm hasn't yet sent us that
     * info.  Process from has the new proc table whereas we don't.  Though we 
     * think the connection is established, it needs a change
    */
    if ((p4_local->conntab[from].type != CONN_REMOTE_EST) ||
	(from_pi->port != lport))
    {
        if (myid == 0) 
	  {
	    /* we are the big master */
	    p4_dprintfl(70,"handling reconnect from = %d\n", from);
	    HandleReconnect(from, lport, msg.host_name);
	  }
	else
	if (myid < from)
	{
	    /* see if I have already started this connection */
	    p4_dprintfl(90,"myid < from, myid = %d, from = %d\n",myid,from);

	    if (p4_global->dest_id[myid] != from) {
	      if (from_pi->port != lport)
		/* Sriram -- Added on 8/7/98 */
		p4_local->conntab[from].type = CONN_REMOTE_NON_EST;
	      request_connection(from);
	    }
	}
	else
	{
	    /* Connect to the waiting process */
	    p4_dprintfl(70, "connecting to port...\n");
	    num_tries = 1;
	    /* connect to the requesting process, who is listening */
	    p4_dprintfl(70,"handling connection interrupt: connecting to %s\n",from_pi->host_name);
	    p4_has_timedout( 0 );
	    while ((connection_fd = net_conn_to_listener(from_pi->host_name,lport,1)) == -1) {
		num_tries++;
		if (p4_has_timedout( 1 )) {
		    p4_error( "Timeout in establishing connection to remote process", 0 );
		    }
		}

	    p4_dprintfl(70, "handling connection interrupt: connected after %d tries, connection_fd=%d host = %s\n",
			num_tries, connection_fd, from_pi->host_name);

	    /* We're connected, so we can add this connection to the table */
	    p4_local->conntab[from].type = CONN_REMOTE_EST;
	    p4_local->conntab[from].port = connection_fd;
	    p4_local->conntab[from].same_data_rep =
		same_data_representation(p4_local->my_id,from);
	    p4_dprintfl(70, "marked as live fd=%d from=%d\n", connection_fd, from);
	}
    }
    else
    {
	p4_dprintfl(70,"ignoring interrupt from %d\n",from);
    }

    msg.type = p4_i_to_n(IGNORE_THIS);

    p4_set_dbg_level(dbg_level);
    
    p4_unlock(&p4_global->conntab_lock);
    
    /* If the return from this is SIG_DFL, then there is a problem ... */
    SIGNAL_P4(LISTENER_ATTN_SIGNAL, handle_connection_interrupt);

    /* First unlock the conntab and then tell the listener */
    p4_dprintfl(70, "handle_connection_interrupt: sending IGNORE_THIS to my_listener\n");
    /* send msg to listener indicating I made the connection */
    net_send(listener_fd, &msg, sizeof(msg), P4_FALSE);
    p4_dprintfl(70, "handle_connection_interrupt: exiting handling intr from %d\n",from);

}

/* ------- This is my stuff to handle failures --------- */

P4VOID HandleReconnect(from, port, host_name)
int from;
int port;
char *host_name;
/*
 * we are the big master.
 */
{
  int unix_id;
  int rm_fd;
  /*
   * When we first created "from", in the function create_remote_processes(),
   * we set up a dummy port (p) and told from to connect to us there
   * Any communication between us and from happened over that p.
   * The scenario here is the opposite.  from has created a new port (p') and
   * told us to connect there.  Any communication will now take place
   * over p'.  We could have done something different -- we could
   * created another dummy  port and asked from to connect back and
   * all of that. But that'd be slow.
   *
   * To complete reconnection, we need the slave information (will
   * make sense only if we run multiple processes per machine).  Since 
   * I am assuming no slaves, there is no slave information that is
   * coming.  We have to update the process table and then broadcast it.
   */

  /* assert(p4_local->conntab[from].type != CONN_REMOTE_EST); */

  strcpy(p4_local->procgroup->entries[from].host_name, host_name);

  rm_fd = net_conn_to_listener(host_name, port, 1);

  net_recv(rm_fd, &unix_id, sizeof(int));

  p4_dprintfl(70, "handle reconnect: marked as live fd=%d from=%d\n", rm_fd, from);
  
  /* this is incorrect. the port we have is *not* the listener's port */
  /*  UpdateProcTable(from, port, unix_id, host_name); */

  /* resend slave info expects this to be set this way */
  p4_local->conntab[from].type = CONN_REMOTE_NON_EST;

  /* Need to send the initialization info */
  net_resend_slave_info(&(p4_local->procgroup->entries[from]),
			rm_outfile_head, rm_fd, from);

  ReDistributeProcTable(from);
  p4_dprintfl(70, "handle reconnect: done redist. global to: from=%d\n", rm_fd, from);
  /* dump_global(0); */
}
