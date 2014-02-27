/*
* Copyright (C) 1999,2000,2001,2002,2003,2004 Samuel Godbillot <sam028@users.sourceforge.net>
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
* 
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/
#include <sys/types.h>   
#include <sys/socket.h>
#include <sys/file.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <syslog.h>
#include <glib.h>
#include <strings.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/utsname.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <cluster.h>
#include <sockhelp.h>

#define BUFSIZE   1024
#define TTL_VALUE 8 

GList *list_services=NULL;
GList *list_state=NULL;
gint shmid;
struct sendstruct to_send;
void clean_tab();
gint get_node_status(gchar*);
gchar *progname=NULL;
void sighup();
void sigterm();

int main(argc, argv)
int argc;
char *argv[]; {

struct sockaddr_in stLocal, stTo;
gint s,status;
struct ip_mreq stMreq;
gint addr_size,iTmp,i,port=-1,fd;
unsigned char ttl=6;
struct utsname tmp_name;
gchar *message, *FILE_KEY;
gchar ADDR[15];
pid_t pid;
key_t key;
gchar *shm,*SHM_KEY;

	message=g_malloc0(160);
	
	if (argc != 4) {
		fprintf(stderr,"Usage: heartd interface address port\n");
		exit(-1);
	}
	signal(SIGTERM,sigterm);
	daemonize("heartd");
	Setenv("PROGNAME","heartd",1);
	strncpy(ADDR,argv[2],15);
	FILE_KEY=g_strconcat(getenv("EZ_LOG"),"/proc/",ADDR,"-",argv[3],"-",argv[1],".key",NULL);
	pid=getpid();

	if ((fd=open(FILE_KEY,O_RDWR|O_CREAT,00644)) == -1){
		strcpy(message,"Error: unable to open key file");
		halog(LOG_ERR, "heartd", message);
		exit(-1);
	}	
	if (lockf(fd,F_TLOCK,0) != 0){
		strcpy(message,"Error: unable to lock key file");
		halog(LOG_ERR, "heartd", message);
		exit(-1);
	}

	port = atoport(argv[3], "udp");
	if (port == -1) {
		strcpy(message,"unable to find service: ");
		strcat(message,argv[3]);
		halog(LOG_ERR, "heartd", message);
		exit(EXIT_FAILURE);
	}

	/* get a datagram socket */
	s = socket(AF_INET, SOCK_DGRAM, 0);

	/* avoid EADDRINUSE error on bind() */ 
	iTmp = TRUE;
	SHM_KEY=g_strconcat(getenv("EZ_LOG"),"/proc/",ADDR,"-",argv[3],"-",argv[1],".key",NULL);
		
	if ((fd=open(SHM_KEY,O_RDWR|O_CREAT,00644)) == -1){
		message=g_strconcat("Error: unable to open SHMFILE \n",NULL);
		halog(LOG_ERR, "heartc", message);
		exit(-1);
	}	

	if (lockf(fd,F_TLOCK,0) != 0){
		message=g_strconcat("Error: unable to lock SHMFILE\n",NULL);
		halog(LOG_ERR, "heartc", message);
		exit(-1);
	}

	key=ftok(SHM_KEY,0);
	if (port == -1) {
		message=g_strconcat("Error: invalid port ",argv[3],"\n",NULL);
		halog(LOG_ERR, "heartd", message);
		exit(-1);
	}

	if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0644)) < 0) {
		message=g_strconcat("shmget failed\n",NULL);
		halog(LOG_ERR, "heartd", message);
		//perror("shmget");
		exit(-1);
	}
	if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
		message=g_strconcat("shmat failed");
		halog(LOG_ERR, "heartd", message);
		//perror("shmat");
		exit(-1);
	}

	/* name the socket */
	stLocal.sin_family =   AF_INET;
	stLocal.sin_addr.s_addr = htonl(INADDR_ANY);
	stLocal.sin_port =     htons(port);
	stLocal.sin_port =     port;
	bind(s, (struct sockaddr*) &stLocal, sizeof(stLocal));

	if (set_mcast_if(s, argv[1]) < 0) {
		strcpy(message,"Error setting outbound mcast interface: ");
		strcat(message,argv[1]);
		halog(LOG_ERR, "heartd:", message);
		exit(-1);
	}

	/* join the multicast group. */
	stMreq.imr_multiaddr.s_addr = inet_addr(argv[2]);
	stMreq.imr_interface.s_addr = INADDR_ANY;
	setsockopt(s, IPPROTO_IP, IP_ADD_MEMBERSHIP, (char *)&stMreq, sizeof(stMreq));
	
	/* assign our destination address */
	stTo.sin_family =      AF_INET;
	stTo.sin_addr.s_addr = inet_addr(argv[2]);
	stTo.sin_port =        htons(port);
	stTo.sin_port =        port;

	/* set TTL to traverse up to multiple routers */
	setsockopt(s, IPPROTO_IP, IP_MULTICAST_TTL, &ttl, sizeof(ttl));
	addr_size = sizeof(struct sockaddr_in);
	setpriority(PRIO_PROCESS,0,-15);
	to_send.hostid = gethostid();     
	uname(&tmp_name);
	strncpy(to_send.nodename,tmp_name.nodename,MAX_NODENAME_SIZE);
	pid=getpid();
	to_send.pid=pid;
	
	while(1) {
		signal(SIGALRM,sighup);
		i=0;		
		status=get_node_status(to_send.nodename);
 		to_send.elapsed = Elapsed();
 		to_send.up = TRUE;
 		to_send.pid = pid;
		memcpy(to_send.port,argv[3],5);
 		memcpy(to_send.addr,ADDR,15);
 		memcpy(shm, &to_send, sizeof(to_send));

		i = sendto(s, (const void *)&to_send, sizeof(to_send), 
				0,(struct sockaddr*)&stTo, addr_size);
		if (i < 0) {
			strcpy(message,"sento() failed");
			halog(LOG_ERR, "heartd",message);
			exit(-1);
		}

		alarm(1);
		pause();
   }
 } /* end main() */  

gint get_node_status(gchar *nodename){
	FILE *EZ_SERVICES, *FILE_STATE;
	guint i,j,list_size,LIST_NB_ITEM=5;
	gchar *FILE_NAME, STATE, *service;

	if (getenv("EZ_SERVICES") == NULL) {
		  printf("ERROR: environment variable EZ_SERVICES not defined !!!\n");
			return 0;
      //exit(-1);
    }
	if ((EZ_SERVICES = fopen(getenv("EZ_SERVICES") ,"r")) == NULL) {
		//No service(s) defined (unable to open $EZ_SERVICES file)
		return 0;
	}
	list_services=get_services_list();
	fclose(EZ_SERVICES);
	list_size = g_list_length(list_services)/LIST_NB_ITEM;
	clean_tab();
	j=0;
	for(i=0;i<list_size;i++){
		service=malloc(MAX_SERVICES_SIZE);	
		strcpy(service,(gchar*)g_list_nth_data(list_services,(i*LIST_NB_ITEM)));
		if (is_primary(nodename,service)||is_secondary(nodename,service)){
			FILE_NAME=g_strconcat(getenv("EZ"),"/services/",service,"/STATE.",nodename,NULL);
			if ((FILE_STATE=fopen((char*)FILE_NAME,"r")) == NULL) {
					perror("No service(s) defined (unable to open SERVICE STATE file)");
					exit(-1);
			}
			g_free(FILE_NAME);
			STATE = fgetc(FILE_STATE);
			fclose(FILE_STATE);
			strcpy(to_send.service_name[j],service);
			to_send.service_state[j]=STATE;
			to_send.up=TRUE;
			j++;
		}
		g_free(service);
	}
	g_list_free(list_services);
	list_services=list_state=NULL;
	return list_size;
}

void clean_tab(){
	gint i;
	for(i=0;i<MAX_SERVICES;i++){
		bzero(to_send.service_name[i],MAX_SERVICES);
		bzero(to_send.service_state,MAX_SERVICES);
	}
}

void sighup(){
}
void sigterm(){
	gchar *message;
	message=g_strconcat("SIGTERM received, exiting gracefully ...\n",NULL);
	halog(LOG_INFO,"heartd",message);
	g_free(message);
	(void)shmctl(shmid,IPC_RMID,NULL);
	exit(0);
}

