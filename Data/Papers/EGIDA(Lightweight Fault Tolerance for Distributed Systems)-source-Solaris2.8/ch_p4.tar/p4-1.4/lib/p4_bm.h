
#ifndef _P4_BM_H
#define _P4_BM_H
/* These are all the functions I added to p4_bm.c */
P4VOID ReDistributeProcTable(int id);
void ReSendTableInfo(int slave_idx, int fd);
int bm_restart(void);
void p4_restartup(struct p4_procgroup *pg);
int re_create_bm_processes(struct p4_procgroup *pg);

#endif
