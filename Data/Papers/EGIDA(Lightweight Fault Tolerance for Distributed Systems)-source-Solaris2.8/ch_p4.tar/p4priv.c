/* 
 * This file contains code private to the p4 implementation of the ADI device
 * Primarily, this contains the code to setup the initial environment
 * and terminate the program.
 * New additions: changed p4_broadcastx to PIbroadcast
 */
#include "mpid.h"
#include "mpiddev.h"
#include "mpimem.h"

#include <string.h>
#include <strings.h>

#include "Egida_API.h"

int __P4FROM, __P4LEN, __P4TYPE, __P4GLOBALTYPE;

static char **P4Args = 0;

void MPID_P4_Init( argc, argv )
int *argc;
char ***argv;
{
    int narg,nlen,i,*arglen;
    char *p,*argstr;
    
    Egida_PreInit(argc, argv);

    p4_initenv(argc,*argv);
    MPID_MyWorldRank = p4_get_my_id();
    if (!MPID_MyWorldRank) {
	p4_set_hard_errors( 0 );
	if (p4_create_procgroup()) {
	    /* Error creating procgroup.  Generate error message and
	       return */
	    MPID_Abort( (struct MPIR_COMMUNICATOR *)0, 1, (char *)0, 
	    "! Could not create p4 procgroup.  Possible missing file\n\
or program started without mpirun.\n" );
	    return;
	}
	p4_set_hard_errors( 1 );
    }
    p4_post_init();		/* do any special post_init stuff */

    MPID_MyWorldRank = p4_get_my_id();
    MPID_MyWorldSize = p4_num_total_slaves()+1;
    __P4GLOBALTYPE = 1010101010;
    if (MPID_MyWorldRank == 0) {
      PIbroadcast(__P4GLOBALTYPE,argc,sizeof(int),P4INT);
      /* p4_broadcastx( __P4GLOBALTYPE,argc,sizeof(int),P4INT); */
    }
    else {
	PIbrecv(__P4GLOBALTYPE,argc,sizeof(int),P4INT);
    }
    narg   = *(argc);
    arglen = (int *)MALLOC( narg * sizeof(int) );
    if (narg>0 && !arglen) { 
	p4_error( "Could not allocate memory for commandline arglen",narg);}
    if (PImytid==0) {
	for (i=0; i<narg; i++) 
	    arglen[i] = strlen((*(argv))[i]) + 1;
    }
    if (MPID_MyWorldRank == 0) {
      PIbroadcast( __P4GLOBALTYPE,arglen,sizeof(int)*narg,P4INT);
      /* p4_broadcastx( __P4GLOBALTYPE,arglen,sizeof(int)*narg,P4INT); */
    }
    else {
	PIbrecv(__P4GLOBALTYPE,arglen,sizeof(int)*narg,P4INT);
    }
    nlen = 0;
    for (i=0; i<narg; i++) 
	nlen += arglen[i];
    argstr = (char *)MALLOC( nlen );
    if (nlen>0 && !argstr) { 
	p4_error( "Could not allocate memory for commandline args",nlen);}
    if (PImytid==0) {
	p = argstr;
	for (i=0; i<narg; i++) {
	    strcpy( p, (*argv)[i] );
	    p  += arglen[i];
	}
    }
    if (MPID_MyWorldRank == 0) {
      printf("broadcasted: %s, len = %d \n", argstr, nlen);
      PIbroadcast( __P4GLOBALTYPE,argstr,nlen,P4NOX);
      /*  p4_broadcastx( __P4GLOBALTYPE,argstr,nlen,P4NOX); */
    }
    else {
	PIbrecv(__P4GLOBALTYPE,argstr,nlen,P4NOX);
        printf("received broadcast: %s, len = %d \n", argstr, nlen);
    }
    if (PImytid!=0) {
	*(argv) = (char **) MALLOC( (nlen + 1) * sizeof(char *) );
	if (nlen > 0 && !*(argv)) { 
	    p4_error( "Could not allocate memory for commandline argv",nlen);}
	p = argstr;
	(*(argv))[0] = argstr;
	for (i=0; i<narg; i++) {
	    (*(argv))[i] = p;
	    p += arglen[i];
	}
	/* Some systems expect a null terminated argument string */
	(*(argv))[narg] = '\0';
	P4Args = *argv;
    }
    else {
	FREE(argstr);
    }
    FREE(arglen);
    printf("mpid init done! \n");
    fflush(stdout);
}

void MPID_P4_End()
{
  /* Modified by Sriram 7/22/98 */
  Egida_Terminate();

    if (P4Args) {
	/* *P4Args should be the argstr that was allocated for the arguments */
	FREE( *P4Args );
	/* P4Args is the argv vector */
	FREE( P4Args );
    }
    p4_wait_for_end();
}

/* ----------- My stuff to handle failures ------------ */
void p4_DoRecovery(void)
{
  if (p4_get_my_id() == 0) {
    printf("\n calling bm restart.. \n");
    bm_restart();
  }
  else {
    printf("\n calling rm restart.. \n");
    rm_restart();
  }
  printf("coyote restart done... \n");
  fflush(stdout);
  /* a simple delay loop to handle f > 1 */
  sleep(2);
  p4_post_init();
  printf("re-connect to all done... \n");
  fflush(stdout);
}
