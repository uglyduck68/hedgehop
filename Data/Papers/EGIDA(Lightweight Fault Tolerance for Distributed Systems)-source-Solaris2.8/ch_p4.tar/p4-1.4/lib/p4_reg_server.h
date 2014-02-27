
#ifndef _P4_REG_SERVER_H
#define _P4_REG_SERVER_H

#include <netdb.h>

#define GET_BM_INFO 10
#define UPDATE_BM_INFO 20
#define KILL_REG_SERVER 30

struct p4_reg_server_info {
  char bm_host_name[MAXHOSTNAMELEN];
  int  bm_port;
  int  bm_pid;
};

extern struct p4_reg_server_info p4_reg_server;

void create_reg_server(int bm_port, int *reg_server_port);
void initialize_reg_server_info(char *reg_server_host, int reg_server_port);
void get_bm_location(char *bm_server_host, int *bm_server_port, int *bm_pid);
void update_bm_location(char *bm_host_name, int bm_port);
void kill_reg_server(void);

#endif
