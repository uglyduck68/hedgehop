#include "p4.h"
#include "p4_sys.h"
#include "p4_reg_server.h"

struct p4_reg_server_info p4_reg_server;

void create_reg_server(int bm_port, int *reg_server_port)
{
  int conn_fd, reg_server_fd, cmd;
  char bm_host_name[MAXHOSTNAMELEN];
  int child_pid, bm_pid;

  net_setup_anon_listener(10, &p4_reg_server.bm_port, &reg_server_fd);
  *reg_server_port = p4_reg_server.bm_port;

  strcpy(p4_reg_server.bm_host_name, p4_global->proctable[0].host_name);
  strcpy(bm_host_name, p4_global->proctable[0].host_name);
  bm_pid = getpid();
  child_pid = fork_p4();
  if (child_pid == 0) {
    setup_sighup_handler();
    printf("\n reg server pid: \n", getpid());
    /* in the child -- reg server */
    /* in a loop, accept connection; process command and shut down socket */
    while (1) {
      conn_fd = net_accept(reg_server_fd);
      net_recv(conn_fd, &cmd, sizeof(int));
      switch(cmd) {
      case GET_BM_INFO:
	net_send(conn_fd, bm_host_name, MAXHOSTNAMELEN, P4_FALSE);
	net_send(conn_fd, &bm_port, sizeof(int), P4_FALSE);
	net_send(conn_fd, &bm_pid, sizeof(int), P4_FALSE);
	break;
      case UPDATE_BM_INFO:
	net_recv(conn_fd, bm_host_name, MAXHOSTNAMELEN);
	net_recv(conn_fd, &bm_port, sizeof(int));
	net_recv(conn_fd, &bm_pid, sizeof(int));
	break;
      case KILL_REG_SERVER:
	printf("\n reg server dying... \n");
	close(conn_fd);
	exit(0);
      default:
	/* what kind of command is that??? */
	break;
      }
      close(conn_fd);
    }
  }
}

void initialize_reg_server_info(char *reg_server_host, int reg_server_port)
{
  strcpy(p4_reg_server.bm_host_name, reg_server_host);
  p4_reg_server.bm_port = reg_server_port;
}

void get_bm_location(char *bm_server_host, int *bm_server_port, int *bm_pid)
{
  int conn_fd;
  int cmd = GET_BM_INFO;

  conn_fd = net_conn_to_listener(p4_reg_server.bm_host_name, p4_reg_server.bm_port, 1);
  if (conn_fd < 0)
    p4_error("get_bm_location: unable to locate reg server! ", p4_reg_server.bm_port);

  net_send(conn_fd, &cmd, sizeof(int), P4_FALSE);
  net_recv(conn_fd, bm_server_host, MAXHOSTNAMELEN);
  net_recv(conn_fd, bm_server_port, sizeof(int));
  net_recv(conn_fd, bm_pid, sizeof(int));
  close(conn_fd);
}

void update_bm_location(char *bm_host_name, int bm_port)
{
  int conn_fd;
  int cmd = UPDATE_BM_INFO;
  int bm_pid = getpid();
  

  conn_fd = net_conn_to_listener(p4_reg_server.bm_host_name, p4_reg_server.bm_port, 1);
  if (conn_fd < 0)
    p4_error("get_bm_location: unable to locate reg server! ", p4_reg_server.bm_port);

  net_send(conn_fd, &cmd, sizeof(int), P4_FALSE);
  net_send(conn_fd, bm_host_name, MAXHOSTNAMELEN, P4_FALSE);
  net_send(conn_fd, &bm_port, sizeof(int), P4_FALSE);
  net_send(conn_fd, &bm_pid, sizeof(int), P4_FALSE);
  close(conn_fd);
}

void kill_reg_server()
{
  int conn_fd;
  int cmd = KILL_REG_SERVER;

  conn_fd = net_conn_to_listener(p4_reg_server.bm_host_name, p4_reg_server.bm_port, 1);
  if (conn_fd < 0)
    p4_error("get_bm_location: unable to locate reg server! ", p4_reg_server.bm_port);

  net_send(conn_fd, &cmd, sizeof(int), P4_FALSE);
  close(conn_fd);
}
