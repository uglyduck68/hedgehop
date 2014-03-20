/*                poll_test.c                */

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stropts.h>
#include <poll.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/fcntl.h>


#define _POSIX_C_SOURCE 199506L 
#define __EXTENSIONS__


#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/uio.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include "thread_extensions.h"


#define BUFSIZE 70


const char      *SERV_HOST_ADDR =   "127.0.0.1";
int             TCP_PORT = 6500;
int             fd[10];
int             num_fds=10;
int             max_fd=511;
int             SLEEP = 0; SPIN= 0; N_CONSUMERS=10;
const int       MESSAGE_SIZE = 70;
const char      *NEW = 
  "New\0                                                                   ";

void process_command(char *buf, int i)
{
  printf("%s %d\n", buf, i);
}

void *monitor_fds(void *v)
{
  fd_set readset;
  int i;
  int num_ready;
  int num_now=num_fds;
  int bytes_read;
  char buf[BUFSIZE];
  struct pollfd *myfd = (void *)calloc(num_fds, sizeof(struct pollfd));
  short errormask = POLLERR|POLLHUP;


  while (TRUE) {
    for (i = 0; i < num_fds; i++) {
      (myfd + i)->fd = *(fd+i);
      (myfd + i)->events = POLLRDNORM;
      (myfd + i)->revents = 0;
    }
    if ((num_ready = poll(myfd, num_fds, INFTIM)) == -1) {
      perror("bummer");
    }

    for (i=0; i< num_fds && num_ready > 0;  i++) {
      if ((myfd+i)->revents && (myfd+i)->events) {
        if ((myfd+i)->revents & errormask) {
          num_now--;
          (myfd+i)->events = 0;
        }
        else
          if ((myfd+i)->revents & POLLRDNORM) {
          
            bytes_read = read(fd[i], buf, BUFSIZE);
            num_ready--;
            if (bytes_read > 0)
              process_command(buf, i);
            else {
              (myfd+i)->events = 0;
              num_now--;
            }
          }
      }
    }
    if (!num_now) break;
  }
}



int open_a_socket()
{int i, j, sockfd, N_SOCKETS = 1;
 pthread_attr_t attr;
 struct sockaddr_in serv_addr;
 pthread_t tid;

 memset((char *) &serv_addr, 0, sizeof(serv_addr));
 serv_addr.sin_family = AF_INET;
 serv_addr.sin_addr.s_addr = inet_addr(SERV_HOST_ADDR);
 serv_addr.sin_port = htons(TCP_PORT);

 if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
   {perror("clientsoc: can't open stream socket"); exit(0);}
 if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
   perror("clientsoc: can't connect to server"), exit(0);
 return(sockfd);
}


main(int argc, char **argv)
{
  char *file1 = "/tmp/file1", *file2 = "/tmp/file2";
int interrupt_socket;
 pthread_attr_t attr;


 PTHREAD_ATTR_INIT(&attr);
 pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
 pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);

{int i, sockfd, newsockfd, clilen;
 struct sockaddr_in cli_addr, serv_addr;
 pthread_t tid;


 if (argc > 1) TCP_PORT = atoi(argv[1]);
 if (argc > 2) SLEEP = atoi(argv[2]);
 if (argc > 3) SPIN = atoi(argv[3]);
 if (argc > 4) N_CONSUMERS = atoi(argv[4]);
 printf("TCP_PORT = %d SLEEP (ms) = %d SPIN (us) = %d N_CONSUMERS = %d\n",
        TCP_PORT, SLEEP, SPIN, N_CONSUMERS);

 if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
   fprintf(stderr,"server: can't open stream socket\n"), exit(0);
 memset((char *) &serv_addr, 0, sizeof(serv_addr));
 serv_addr.sin_family = AF_INET;
 serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
 serv_addr.sin_port = htons(TCP_PORT);
        
 if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
   fprintf(stderr,"server: can't bind local address\n"), exit(0);
    

 listen(sockfd, 5);
 interrupt_socket=open_a_socket();
    PTHREAD_CREATE(&tid, &attr, monitor_fds, (void *) NULL);

 
 for (i=0; i< 10; i++)
   {clilen = sizeof(cli_addr);
   newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
   if(newsockfd < 0)
     fprintf(stderr,"server: accept error\n"), exit(0);
   fd[i] = newsockfd;
   num_fds++;
   write(interrupt_socket, NEW, MESSAGE_SIZE);
   }
}
} 
