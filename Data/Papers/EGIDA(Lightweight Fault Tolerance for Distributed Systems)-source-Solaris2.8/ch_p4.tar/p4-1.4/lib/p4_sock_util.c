#include "p4.h"
#include "p4_sys.h"
/* p4_net_utils.h generally would suffice here */

/* extern int errno; -- errno.h is included in p4.h*/
/*  removed 11/27/94 by RL.  Causes problems in FreeBSD and is not used.
extern char *sys_errlist[];
*/

/* getenv is part of stdlib.h */
#ifndef HAVE_STDLIB_H
extern char *getenv();
#endif

/*
 *    Utility routines for socket hacking in p4:
 *        P4VOID net_set_sockbuf_size(size, skt)
 *        P4VOID net_setup_listener(backlog, port, skt)
 *        P4VOID net_setup_anon_listener(backlog, port, skt)
 *        int net_accept(skt)
 *        int net_conn_to_listener(hostname, port)
 *        int net_recv(fd, buf, size)
 *        P4VOID net_send(fd, buf, size)
 *        get_inet_addr(addr)
 *        get_inet_addr_str(str)
 *        dump_sockaddr(who, sa)
 *        dump_sockinfo(msg, fd)
 */

/*
 *    Setup a listener:
 *        get a socket
 *        get a port
 *        listen on the port
 *
 *    Note that this does NOT actually start a listener process, but
 *    merely does the listen command.  It might be executed by a
 *    listener process, but we commonly use it prior to actually
 *    forking off the listener.
 */


P4VOID net_set_sockbuf_size(size, skt)	/* 7/12/95, bri@sgi.com */
int size;
int skt;
{
    int rc;
    char *env_value;
    int rsz,ssz,dummy;
#ifdef TCP_WINSHIFT
    int shft; /* Window shift; helpful on CRAY */
#endif
    /*
     * Need big honking socket buffers for fast honking networks.  It
     * would be nice if these would "autotune" for the underlying network,
     * but until then, we'll let the user specify socket send/recv buffer
     * sizes with P4_SOCKBUFSIZE.
     *
     */

#ifdef CAN_DO_SETSOCKOPT
    /* For the environment variables to work, the user really needs to
       set them in their .cshrc file (otherwise, the spawned processes
       may not get the correct values).

       Rumor has it that 0x40000 is a good size for AIX 4.x
     */
    /* 
     * Take the size either from the environment variable or from the
     * default set in p4_sock_util.h .
     */
    if (size <= 0)
    {
#if 1
	    env_value = getenv("P4_SOCKBUFSIZE");
#else
	    env_value = 0;
#endif
	    if (env_value) 
		size = atoi(env_value);
	    else 
		size = SOCK_BUFF_SIZE;
#ifdef TCP_WINSHIFT
	    shft = 0;
            env_value = getenv("P4_WINSHIFT");
            if (env_value) shft = atoi(env_value);
#endif
    }

    if (size > 0)
    {
	    	/* Set Send & Receive Socket Buffers */

	    SYSCALL_P4(rc, setsockopt(skt,SOL_SOCKET,SO_SNDBUF,(char *)&size,sizeof(size)));
	    /* These should only generate informational messages ..., 
	       particularly for something like ENOBUFS */
	    if (rc < 0) {
		perror( "Set SO_SNDBUF" );
		p4_error("net_set_sockbuf_size socket", skt);
		}
	    SYSCALL_P4(rc, setsockopt(skt,SOL_SOCKET,SO_RCVBUF,(char *)&size,sizeof(size)));
	    if (rc < 0) {
		perror( "Set SO_RCVBUF" );
		p4_error("net_set_sockbuf_size socket", skt);
		}

	    	/* Fetch Back the Newly Set Sizes */

            dummy = sizeof(ssz);
            rc = getsockopt(skt,SOL_SOCKET,SO_SNDBUF,(char *)&ssz,&dummy);
            dummy = sizeof(rsz);
            rc = getsockopt(skt,SOL_SOCKET,SO_RCVBUF,(char *)&rsz,&dummy);

	    p4_dprintfl(80,
			"net_set_sockbuf_size: skt %d, new sizes = [%d,%d]\n",
			skt,ssz,rsz);
    }

#ifdef TCP_WINSHIFT
    /* 
       This code came from Dan Anderson (anderson@ncar.ucar.edu) for the
       CRAYs.  This is for systems that don't handle buffer sizes greater
       than 16 bits by default. An alternate mechanism is to do something
       like this:

	winshift = 0;
	bufsiz = SOCK_BUFF_SIZE; (use the actual size)
	while (bufsiz > 0XFFFF) {
		bufsiz >>= 1;
		++winshift;
	}

     */
    if ( shft > 0)
    {
    int wsarray[3];
    char hostname[MAXHOSTNAMELEN];

                /* Set socket WINSHIFT */
        dummy = sizeof(wsarray);
        getsockopt(skt,IPPROTO_TCP,TCP_WINSHIFT,&wsarray,&dummy);
        if(wsarray[1] != shft){

                dummy = sizeof(shft);

            SYSCALL_P4(rc, setsockopt(skt,IPPROTO_TCP,TCP_WINSHIFT,&shft,dummy));
            if (rc < 0) {gethostname(hostname,255);
			 fprintf(stdout,
                        "ERROR_WINSHIFT in %s rc=%d, shft=%d, size_shft=%d \n",
                        hostname, rc,shft,dummy);
                         p4_error("net_set_WINSHIFT socket", skt);}

                /* Fetch Back the Newly Set Sizes */

            dummy = sizeof(wsarray);
            rc = getsockopt(skt,IPPROTO_TCP,TCP_WINSHIFT,&wsarray,&dummy);

            p4_dprintfl(80,
                "net_set_sockbuf_WINSHIFT: skt %d, new values = [%x,%d,%d]\n",
                        skt,wsarray[0],wsarray[1],wsarray[2]);
        }
      }

#endif

#endif
}

P4VOID net_setup_listener(backlog, port, skt)
int backlog;
int port;
int *skt;
{
    struct sockaddr_in sin;
    int rc, optval = P4_TRUE;

    SYSCALL_P4(*skt, socket(AF_INET, SOCK_STREAM, 0));
    if (*skt < 0)
	p4_error("net_setup_listener socket", *skt);

#ifdef CAN_DO_SETSOCKOPT
    net_set_sockbuf_size(-1,*skt);     /* 7/12/95, bri@sgi.com */
#endif

#ifdef CAN_DO_SETSOCKOPT
    SYSCALL_P4(rc,setsockopt(*skt, IPPROTO_TCP, TCP_NODELAY, (char *) &optval, sizeof(optval)));
#endif

    sin.sin_family	= AF_INET;
    sin.sin_addr.s_addr	= INADDR_ANY;
    sin.sin_port	= htons(port);

    SYSCALL_P4(rc, bind(*skt, (struct sockaddr *) & sin, sizeof(sin)));
    if (rc < 0)
	p4_error("net_setup_listener bind", -1);

    SYSCALL_P4(rc, listen(*skt, backlog));
    if (rc < 0)
	p4_error("net_setup_listener listen", -1);
}

P4VOID net_setup_anon_listener(backlog, port, skt)
int backlog;
int *port;
int *skt;
{
    int rc, sinlen;
    struct sockaddr_in sin;
    int optval = P4_TRUE;

    SYSCALL_P4(*skt, socket(AF_INET, SOCK_STREAM, 0));
    if (*skt < 0)
	p4_error("net_setup_anon_listener socket", *skt);

#ifdef CAN_DO_SETSOCKOPT
    net_set_sockbuf_size(-1,*skt);	/* 7/12/95, bri@sgi.com */
#endif

#ifdef CAN_DO_SETSOCKOPT
    SYSCALL_P4(rc, setsockopt(*skt, IPPROTO_TCP, TCP_NODELAY, (char *) &optval, sizeof(optval)));
#endif

    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(0);

    sinlen = sizeof(sin);

    SYSCALL_P4(rc, bind(*skt, (struct sockaddr *) & sin, sizeof(sin)));
    if (rc < 0)
	p4_error("net_setup_anon_listener bind", -1);

    SYSCALL_P4(rc, listen(*skt, backlog));
    if (rc < 0)
	p4_error("net_setup_anon_listener listen", -1);

    getsockname(*skt, (struct sockaddr *) & sin, &sinlen);
    *port = ntohs(sin.sin_port);
}

/*
  Accept a connection on socket skt and return fd of new connection.
  */
int net_accept(skt)
int skt;
{
    struct sockaddr_in from;
    int rc, flags, fromlen, skt2, gotit, sockbuffsize;
    int optval = P4_TRUE;

    /* dump_sockinfo("net_accept call of dumpsockinfo \n",skt); */
    fromlen = sizeof(from);
    gotit = 0;
    while (!gotit)
    {
	p4_dprintfl(60, "net_accept - waiting for accept on %d.\n",skt);
	SYSCALL_P4(skt2, accept(skt, (struct sockaddr *) &from, &fromlen));
	if (skt2 < 0)
	    p4_error("net_accept accept", skt2);
	else
	    gotit = 1;
	p4_dprintfl(60, "net_accept - got accept\n");
    }

#if defined(CAN_DO_SETSOCKOPT) && !defined(SET_SOCK_BUF_SIZE)
    net_set_sockbuf_size(-1,skt2);     /* 7/12/95, bri@sgi.com */
#endif

#ifdef CAN_DO_SETSOCKOPT
    SYSCALL_P4(rc, setsockopt(skt2, IPPROTO_TCP, TCP_NODELAY, (char *) &optval, sizeof(optval)));

    sockbuffsize = SOCK_BUFF_SIZE;

#ifdef SET_SOCK_BUF_SIZE
      if (setsockopt(skt2,SOL_SOCKET,SO_RCVBUF,(char *)&sockbuffsize,sizeof(sockbuffsize)))
      p4_dprintf("net_accept: setsockopt rcvbuf failed\n");
      if (setsockopt(skt2,SOL_SOCKET,SO_SNDBUF,(char *)&sockbuffsize,sizeof(sockbuffsize)))
      p4_dprintf("net_accept: setsockopt sndbuf failed\n");
#endif

#endif
    /* Peter Krauss suggested eliminating these lines for HPs  */
    flags = fcntl(skt2, F_GETFL, 0);
    if (flags < 0)
	p4_error("net_accept fcntl1", flags);
#   if defined(HP)
    flags |= O_NONBLOCK;
#   else
    flags |= O_NDELAY;
#   endif
#   if defined(RS6000)
    flags |= O_NONBLOCK;
#   endif
    flags = fcntl(skt2, F_SETFL, flags);
    if (flags < 0)
	p4_error("net_accept fcntl2", flags);
    return (skt2);
}

void get_sock_info_by_hostname(hostname,sockinfo)
char *hostname;
struct sockaddr_in **sockinfo;
{
    int i;

    p4_dprintfl( 91, "Starting get_sock_info_by_hostname\n");
    if (p4_global) {
	p4_dprintfl( 90, "looking at %d hosts\n", 
		    p4_global->num_in_proctable );
	for (i = 0; i < p4_global->num_in_proctable; i++) {
	    p4_dprintfl(90,"looking up (%s), looking at (%s)\n",
			hostname,p4_global->proctable[i].host_name);
	    if (strcmp(p4_global->proctable[i].host_name,hostname) == 0) {
		if (p4_global->proctable[i].sockaddr.sin_port == 0)
		    p4_error( "Uninitialized sockaddr port",i);
		*sockinfo = &(p4_global->proctable[i].sockaddr);
		return;
		}
	    }
	}

/* Error, no sockinfo.
   Try to get it from the hostname (this is NOT signal safe, so we 
   had better not be in a signal handler.  This MAY be ok for the listener) */
    {
    struct hostent *hp = gethostbyname_p4( hostname );
    static struct sockaddr_in listener;
    if (hp) {
	bzero((P4VOID *) &listener, sizeof(listener));
	bcopy((P4VOID *) hp->h_addr, (P4VOID *) &listener.sin_addr, 
	      hp->h_length);
	listener.sin_family = hp->h_addrtype;
	*sockinfo = &listener;
	return;
	}
    }

*sockinfo = 0;
p4_error("Unknown host in getting sockinfo from proctable",-1);
}

int net_conn_to_listener(hostname, port, num_tries)
char *hostname;
int port, num_tries;
{
    int flags, rc, s;
/* RL
    struct sockaddr_in listener;
*/
    struct sockaddr_in *sockinfo;
/*    struct hostent *hp; */
    P4BOOL optval = P4_TRUE;
    P4BOOL connected = P4_FALSE;

    p4_dprintfl(80, "net_conn_to_listener: host=%s port=%d\n", hostname, port);
    /* gethostchange -RL */
/*
    bzero((P4VOID *) &listener, sizeof(listener));
    bcopy((P4VOID *) hp->h_addr, (P4VOID *) &listener.sin_addr, hp->h_length);
    listener.sin_family = hp->h_addrtype;
    listener.sin_port = htons(port);
*/
    get_sock_info_by_hostname(hostname,&sockinfo);
    sockinfo->sin_port = htons(port);
#if !defined(CRAY)
    dump_sockaddr("sockinfo",sockinfo);
#endif
    connected = P4_FALSE;
    while (!connected && num_tries)
    {
	SYSCALL_P4(s, socket(AF_INET, SOCK_STREAM, 0));
	if (s < 0)
	    p4_error("net_conn_to_listener socket", s);

#ifdef CAN_DO_SETSOCKOPT
        net_set_sockbuf_size(-1,s);    /* 7/12/95, bri@sgi.com */
#endif

#       ifdef CAN_DO_SETSOCKOPT
	SYSCALL_P4(rc, setsockopt(s,IPPROTO_TCP,TCP_NODELAY,(char *) &optval,sizeof(optval)));
#       endif

/*  RL
	SYSCALL_P4(rc, connect(s, (struct sockaddr *) &listener, sizeof(listener)));
*/
	SYSCALL_P4(rc, connect(s, (struct sockaddr *) sockinfo,
			       sizeof(struct sockaddr_in)));
	if (rc < 0)
	{
	    close(s);
	    if (--num_tries)
	    {
		p4_dprintfl(60,"net_conn_to_listener: connect to %s failed; will try %d more times \n",hostname,num_tries);
		sleep(2);
	    }
	}
	else
	{
	    connected = P4_TRUE;
	    p4_dprintfl(70,"net_conn_to_listener: connected to %s\n",hostname);
	}
    }
    if (!connected)
	return(-1);
    /* Peter Krauss suggested eliminating these lines for HPs */
    flags = fcntl(s, F_GETFL, 0);
    if (flags < 0)
	p4_error("net_conn_to_listener fcntl1", flags);
#   if defined(HP)
    flags |= O_NONBLOCK;
#   else
    flags |= O_NDELAY;
#   endif
#   if defined(RS6000)
    flags |= O_NONBLOCK;
#   endif
    flags = fcntl(s, F_SETFL, flags);
    if (flags < 0)
	p4_error("net_conn_to_listener fcntl2", flags);
    return (s);
}

/* If the return value is > 0, then the recv succeeded and the return
 * value is the # of bytes received.  If return value is < 0, then the 
 * recv failed.
*/
int net_recv(fd, in_buf, size)
int fd;
P4VOID *in_buf;
int size;
{
    int recvd = 0;
    int n;
    int read_counter = 0;
    int block_counter = 0;
    int eof_counter = 0;
    char *buf = (char *)in_buf;
#ifdef P4SYSV
    int n1 = 0;
    struct timeval tv;
    fd_set read_fds;
    int rc;
    char tempbuf[1];
#endif

    p4_dprintfl( 99, "Beginning net_recv of %d on fd %d\n", size, fd );
    while (recvd < size)
    {
	read_counter++;

	errno = 0;
	/* SYSCALL_P4(n, read(fd, buf + recvd, size - recvd)); */
	n = read(fd, buf + recvd, size - recvd);
	if ((n < 0) && (errno == EINTR))
	  continue;

#if 0
	if ((n != size) && (errno != 0))
	  printf("asked to read: %d, got: %d, errno: %d \n", size, n, errno);
#endif

	if (n == 0)		/* maybe EOF, maybe not */
#if defined(P4SYSV)
	{
	    eof_counter++;

	    tv.tv_sec = 5;
	    tv.tv_usec = 0;
	    FD_ZERO(&read_fds);
	    FD_SET(fd, &read_fds);
	    SYSCALL_P4(n1, select(fd+1, &read_fds, 0, 0, &tv));
	    if (n1 == 1  &&  FD_ISSET(fd, &read_fds))
	    {
		rc = recv(fd, tempbuf, 1, MSG_PEEK);
		if (rc == -1)
		{
		  /* Modifed by Sriram---7/17/99 */
		  /* -1 indicates ewouldblock (eagain) (check errno) */
		  /* p4_error("net_recv recv:  got -1", -1); */
		  printf("net_recv recv:  got -1", -1);
		}
		if (rc == 0)	/* if eof */
		{
		  /* Modifed by Sriram---7/17/99 */
		  /* eof; a process has closed its socket; may have died */
		  /* p4_error("net_recv recv:  EOF on socket",
		     read_counter); */
		  printf("net_recv recv:  EOF on socket \n",
			 read_counter); 
		  fflush(stdout);
		}
		else
		    continue;
	    }
	    sleep(1);
	    if (eof_counter < 5)
		continue;
	    else {
	      /* Modifed by Sriram---7/17/99 */
	      /* p4_error("net_recv read:  probable EOF on socket",
		 read_counter); */
	      printf("%s net_recv read:  probable EOF on socket \n",
		     whoami_p4, read_counter);
	      fflush(stdout);
	      n = -1;
	      recvd = -1;
	      break;
	    }
	}
#else
	{
	    /* Except on SYSV, n == 0 is EOF */
	    p4_error("net_recv read:  probable EOF on socket", read_counter);
        }
#endif
	if (n < 0)
	{
	    /* EAGAIN is really POSIX, so we check for either EAGAIN 
	       or EWOULDBLOCK.  Note some systems set EAGAIN == EWOULDBLOCK
	     */
	    /* Solaris 2.5 occasionally sets n == -1 and errno == 0 (!!).
	       since n == -1 and errno == 0 is invalid (i.e., a bug in read),
	       it should be safe to treat it as EAGAIN and to try the
	       read once more 
	     */
	    if ((errno == EAGAIN) || (errno == EWOULDBLOCK) || (errno == 0))
	    {
		block_counter++;
		/* Consider doing a select here to wait for more data
		   to arrive.  This may give better performance, 
		   particularly when the system is actively involved in
		   trying to get the message to us
		 */
#ifdef FOO
		tv.tv_sec = 5;
		tv.tv_usec = 0;
		FD_ZERO(&read_fds);
		FD_SET(fd, &read_fds);
		SYSCALL_P4(n1, select(fd+1, &read_fds, 0, 0, &tv));
#endif
		continue;
	    }
	    else {
		/* A closed socket can cause this to happen. */
		printf( "%s net_recv failed for fd = %d, errno=%d\n", 
			    whoami_p4, fd, errno );
		/* p4_error("net_recv read, errno = ", errno); */
		break;
	    }
	}
	recvd += n;
    }
    /* Modified by Sriram---7/17/99 */
    if (n < 0)
      recvd = -1;

    p4_dprintfl( 99, 
		"Ending net_recv of %d on fd %d (eof_c = %d, block = %d)\n", 
		 size, fd, eof_counter, block_counter );
    return (recvd);
}

int net_send(fd, in_buf, size, flag)
int fd;
P4VOID *in_buf;
int size;
int flag;  
/* flag --> fromid < toid; tie-breaker to avoid 2 procs rcving at same time */
/* typically set false for small internal messages, esp. when ids may not */
/*     yet be available */
/* set true for user msgs which may be quite large */
{
    struct p4_msg *dmsg;
    int n, sent = 0;
    int write_counter = 0;
    int block_counter = 0;
    int trial_size = size;
    char *buf = (char *)in_buf;

    /* trial_size lets us back off from sending huge messages in a single
       write without making many expensive calls to socket_msgs_available
       (select).  But we have to set it large enough to let us do
       long writes (since each write is itself expensive).
       The backoff size should not be shorter than the socket_buffer_size.
     */
    p4_dprintfl( 99, "Starting net_send of %d on fd %d\n", size, fd );
    while (sent < size)
    {
	write_counter++;		/* for debugging */
	if (size - sent < trial_size) trial_size = size - sent;
	/* SYSCALL_P4(n, write(fd, buf + sent, trial_size)); */
	n = write(fd, buf + sent, trial_size);
	if ((n < 0) && (errno == EINTR))
	  continue;

	if (n < 0)
	{
	    /* See net_read; these are often the same and EAGAIN is POSIX */
	  /* due the solaris 2.5 problem, i added errno == 0 -- Sriram */
	    if ((errno == EAGAIN || errno == EWOULDBLOCK) || (errno == 0))
	    {
/*	        
                p4_dprintfl( 90, "write net_send in EAGAIN with %d left", 
			     size ); 
*/
		block_counter++;
		if (flag)
		{
		    /* First, try sending the message in shorter bursts */
#ifdef FOO
		    if (trial_size > 16 * SOCK_BUFF_SIZE) 
			trial_size = trial_size / 2;
		    else 
#endif

		      {
			/* Someone may be writing to us ... */
			if (socket_msgs_available())
			  {
			    dmsg = socket_recv( P4_FALSE );
			    /* close of a connection may return a null msg */
			    if (dmsg) 
			      queue_p4_message(dmsg, 
					       p4_local->queued_messages);
			    /* Reset the trial_size to the amount remaining */
			    trial_size = size - sent;
			  }
		      }
		}
		continue;
	    }
	    else
	    {
	      p4_dprintf("%s net_send of fd %d: could not write, errno = %d\n", whoami_p4, fd, errno);
	      /* Changed by Sriram -- 9/9/98 */
	      /* p4_error("net_send write", n); */
	      break;
	    }
	}
	/* Added by Sriram---7/17/98 */
	if (n < 0) {
	  sent = -1;
	  printf("%s Net_send failed on fd = %d: error = %d",
		 whoami_p4, fd, errno);
	  fflush(stdout);
	  break;
	}
	else {
	  sent += n;
	  /* Go back to full size */
	  trial_size = size - sent;
	}
    }
    p4_dprintfl( 99, "Ending net_send of %d on fd %d (blocked %d times)\n", 
		 size, fd, block_counter );
    return (sent);
}

/* This can FAIL if the host name is invalid.  For that reason, there is
   a timeout in the test, with a failure return if the entry cannot be found 
 */
#include <sys/time.h>
#ifndef TIMEOUT_VALUE 
#define TIMEOUT_VALUE 60
#endif
struct hostent *gethostbyname_p4(hostname)
char *hostname;
{
    struct hostent *hp;
    int i = 100;
    time_t start_time, cur_time;

    start_time = time( (time_t) 0 );

    while ((hp = gethostbyname(hostname)) == NULL)
    {
	if (!--i)
	{
	    i = 100;
	    p4_dprintfl(00,"gethostbyname failed 100 times for host %s\n",
			hostname);
	    cur_time = time( (time_t) 0 );
	    if (cur_time - start_time > TIMEOUT_VALUE) {
		/* Dump out current procgroup */
		if (p4_local && p4_local->procgroup) 
		    dump_procgroup(p4_local->procgroup,00);

		p4_error("Could not gethostbyname; may be invalid name\n",
			 cur_time - start_time);
		return 0;
	    }
	}
    }
    return(hp);
}

P4VOID get_inet_addr(addr)
struct in_addr *addr;
{
    char hostname[100];
    struct hostent *hp;

    hostname[0] = '\0';
    get_qualified_hostname(hostname);
    hp = gethostbyname_p4(hostname);
    bcopy(hp->h_addr, addr, hp->h_length);
}

P4VOID get_inet_addr_str(str)
char *str;
{
    struct in_addr addr;

    get_inet_addr(&addr);
    strcpy(str, (char *) inet_ntoa(addr));
}

#if !defined(CRAY)
/* cray complains about addr being addr of bit field */
/* can probably get around this problem if ever necessary */

P4VOID dump_sockaddr(who,sa)
char *who;
struct sockaddr_in *sa;
{
    unsigned char *addr;

    addr = (unsigned char *) &(sa->sin_addr.s_addr);

    p4_dprintfl(90,"%s: family=%d port=%d addr=%d.%d.%d.%d\n",
		who,
                ntohs(sa->sin_family),
                ntohs(sa->sin_port),
                addr[0], addr[1], addr[2], addr[3]);
}

P4VOID dump_sockinfo(msg, fd)
char *msg;
int fd;
{
    int nl;
    struct sockaddr_in peer, me;

    p4_dprintfl(00, "Dumping sockinfo for fd=%d: %s\n", fd, msg);

    nl = sizeof(me);
    getsockname(fd, (struct sockaddr *) &me, &nl);
    dump_sockaddr("Me", &me);
	   
    nl = sizeof(peer);
    getpeername(fd, (struct sockaddr *) &peer, &nl);
    dump_sockaddr("Peer",&peer);
}

#endif
