#include "p4.h"
#include "p4_sys.h"

#ifdef TCMP
extern struct tc_globmem *tcglob;
#endif

struct p4_procgroup *p4_alloc_procgroup()
{
    struct p4_procgroup *pg;

    if (!(pg = (struct p4_procgroup *) p4_malloc(sizeof(struct p4_procgroup))))
	p4_error("p4_alloc_procgroup: p4_malloc failed",
		 sizeof(struct p4_procgroup));

    p4_dprintfl(90, "p4_alloc_procgroup: allocing %d bytes\n",
		sizeof(struct p4_procgroup));

    pg->num_entries = 0;
    return (pg);
}

struct p4_procgroup *read_procgroup()
{
    FILE *fp;
    char buf[1024], *s;
    struct p4_procgroup_entry *pe;
    int n;
    struct p4_procgroup *pg;
    struct passwd *pwent;
    char *logname; 


    p4_dprintfl(90,"entering read_procgroup pgfname=%s\n",procgroup_file);

    pg = p4_alloc_procgroup();
    if (!pg) return 0;

#   if defined(CM5)  ||  defined(NCUBE)
    logname = '\0';
#   else
    logname = (char *) getlogin();
#   endif

    if ((fp = fopen(procgroup_file, "r")) == NULL) {
	/* Thanks to Tony Kimball <alk@think.com> for this suggestion */
#define P4_ALLOW_NP_1_DEFAULT
#ifdef P4_ALLOW_NP_1_DEFAULT
	pg->num_entries = 1;
	pe = pg->entries;
	strcpy( pe->host_name, "localhost" );
	pe->numslaves_in_group = 0;
	pe->slave_full_pathname[0] = 0;
	pe->username[0] = 0;
	return pg;
#else
	if (p4_hard_errors) {
	    char tmp[1300];
	    sprintf( tmp, 
		     "open error on procgroup file (%s)", procgroup_file );
	    p4_error(tmp,0);
	}
	/* In case p4_error doesn't return or p4_hard_errors not set */
	return 0;
#endif
    }

    pe = pg->entries;

    while (fp != NULL && fgets(buf, sizeof(buf), fp) != NULL)
    {
	for (s = buf; isspace(*s); s++)
	    ;

	if (*s == '#' || *s == '\0')	/* Ignore comments & blanks */
	    continue;

	/* Initialize fields to empty incase n < 3 */
	pe->host_name[0]	   = 0;
	pe->numslaves_in_group     = 0;
	pe->slave_full_pathname[0] = 0;
	pe->username[0]		   = 0;
	n = sscanf(buf, "%s %d %s %s",
		   pe->host_name,
		   &pe->numslaves_in_group,
		   pe->slave_full_pathname,
		   pe->username);

	if (n == 3)
	{
	    if (logname != NULL && logname[0] != '\0')
		strcpy(pe->username, logname);
	    else
	    {
#               if defined(CM5)  ||  defined(NCUBE)
                strcpy(pe->username, "cube-user");
#               else
		if ((pwent = getpwuid(getuid())) == NULL)
		    p4_error("create_procgroup: getpwuid failed", 0);
		strcpy(pe->username, pwent->pw_name);
#               endif
	    }
	}
	pe++;
	pg->num_entries++;
	if (pg->num_entries > P4_MAX_PROCGROUP_ENTRIES)
	    p4_error("read procgroup: exceeded max # of procgroup entries",
		     P4_MAX_PROCGROUP_ENTRIES);
    }

    fclose( fp );
    dump_procgroup(pg,50);
    return (pg);
}				/* read_procgroup */


int install_in_proctable(group_id,port,unix_id,host_name,
			 slv_idx,machine_type,switch_port)
int group_id;
int port;
int unix_id;
char host_name[HOSTNAME_LEN];
int slv_idx;
char machine_type[];
int switch_port;
{
    struct p4_global_data *g;
    struct proc_info *pi;
    struct hostent *hp;

    g = p4_global;
    pi = &g->proctable[g->num_installed];
    pi->group_id = group_id;
    pi->port = port;
    pi->unix_id = unix_id;
    strcpy(pi->host_name, host_name);

    /* gethostchange newstuff -RL */
    hp = gethostbyname_p4(host_name);
    bzero((P4VOID *) &pi->sockaddr, sizeof(pi->sockaddr));
    bcopy((P4VOID *) hp->h_addr, (P4VOID *) &pi->sockaddr.sin_addr, hp->h_length);
    pi->sockaddr.sin_family = hp->h_addrtype;
    pi->sockaddr.sin_port = htons(port);
    /* end of gethostchange newstuff -RL */

    strcpy(pi->machine_type,machine_type);
    pi->slave_idx = slv_idx;
    pi->switch_port = switch_port;
    g->num_installed++;
    p4_dprintfl(50, "installed in proctable num=%d port=%d host=%s unix=%d slav=%d grp=%d swport=%d\n",
		g->num_installed, port, host_name, unix_id, slv_idx, pi->group_id,pi->switch_port);
    return (g->num_installed - 1);
}

/* ------- This is my stuff to handle failures --------- */

P4VOID UpdateProcTable(id, port, unix_id, host_name)
int id;
int port;
int unix_id;
char host_name[HOSTNAME_LEN];
{
  struct proc_info *dest_pi;
  struct hostent *hp;

  dest_pi = get_proc_info(id);
  dest_pi->port =  port;
  dest_pi->unix_id = unix_id;
  strcpy(dest_pi->host_name, host_name);
  
  /* gethostchange newstuff -RL */
  hp = gethostbyname_p4(host_name);
  bzero((P4VOID *) &dest_pi->sockaddr, sizeof(dest_pi->sockaddr));
  bcopy((P4VOID *) hp->h_addr, (P4VOID *) &dest_pi->sockaddr.sin_addr, hp->h_length);
  dest_pi->sockaddr.sin_family = hp->h_addrtype;
  dest_pi->sockaddr.sin_port = htons(port);
}

WriteOutProcTable()
{
  FILE *fp;
  int ent;
  struct proc_info *pe;

  printf("\n %s writing out proc table... \n", whoami_p4);
  fp = fopen("procTable", "w");
  fprintf(fp, "%d \n", p4_global->num_in_proctable);
  for (ent = 0, pe = p4_global->proctable;
       ent < p4_global->num_in_proctable; ent++, pe++) {
    fprintf(fp, "%d %d %d %d %s \n", pe->unix_id, pe->port, pe->slave_idx,
	    pe->group_id, pe->host_name);
  }
  fclose(fp);
}

ReadInProcTable()
{
  FILE *fp;
  char ch;
  int ent;
  struct proc_info *pe;
  struct hostent *hp;

  if ((fp = fopen("procTable", "r")) == NULL)
    return;
  fscanf(fp, "%d", &ent);
  for (ent = 0, pe = p4_global->proctable;
       ent < p4_global->num_in_proctable; ent++, pe++) {
    fscanf(fp, "%d%d%d%d", &(pe->unix_id), &(pe->port), &(pe->slave_idx),
	   &(pe->group_id));
    /* skip the white space after group-id */
    fscanf(fp, "%c", &ch);
    fscanf(fp, "%s", pe->host_name);

    /* Need to adjust the sockinfo---this piece of code comes from
     * UpdateProcTable
     */
    hp = gethostbyname_p4(pe->host_name);
    bzero((P4VOID *) &pe->sockaddr, sizeof(pe->sockaddr));
    bcopy((P4VOID *) hp->h_addr, (P4VOID *) &pe->sockaddr.sin_addr, hp->h_length);
    pe->sockaddr.sin_family = hp->h_addrtype;
    pe->sockaddr.sin_port = htons(pe->port);

    printf("proc table read in: %d %d %s \n", pe->unix_id, pe->port, pe->host_name);
  }
  fclose(fp);
}

