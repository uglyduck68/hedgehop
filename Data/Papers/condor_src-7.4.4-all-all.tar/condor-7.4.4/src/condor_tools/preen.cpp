/***************************************************************
 *
 * Copyright (C) 1990-2007, Condor Team, Computer Sciences Department,
 * University of Wisconsin-Madison, WI.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License"); you
 * may not use this file except in compliance with the License.  You may
 * obtain a copy of the License at
 * 
 *    http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ***************************************************************/


 

/*********************************************************************
* Find files which may have been left lying around on somebody's workstation
* by condor.  Depending on command line options we may remove the file
* and/or mail appropriate authorities about it.
*********************************************************************/

#include "condor_common.h"
#include "condor_debug.h"
#include "condor_io.h"
#include "condor_config.h"
#include "condor_uid.h"
#include "string_list.h"
#include "directory.h"
#include "condor_qmgr.h"
#include "condor_classad.h"
#include "condor_attributes.h"
#include "my_hostname.h"
#include "condor_state.h"
#include "sig_install.h"
#include "condor_email.h"
#include "daemon.h"
#include "condor_distribution.h"
#include "basename.h" // for condor_basename 
#include "extArray.h"
#include "link.h"
#include "../condor_privsep/condor_privsep.h"


State get_machine_state();


// Define this to check for memory leaks

int			MaxCkptInterval;	// max time between ckpts on this machine
char		*Spool;				// dir for condor job queue
StringList   ExecuteDirs;		// dirs for execution of condor jobs
char		*Log;				// dir for condor program logs
char		*PreenAdmin;		// who to send mail to in case of trouble
char		*MyName;			// name this program was invoked by
char        *ValidSpoolFiles;   // well known files in the spool dir
char        *InvalidLogFiles;   // files we know we want to delete from log
char		*MailPrg;			// what program to use to send email
BOOLEAN		MailFlag;			// true if we should send mail about problems
BOOLEAN		VerboseFlag;		// true if we should produce verbose output
BOOLEAN		RmFlag;				// true if we should remove extraneous files
StringList	*BadFiles;			// list of files which don't belong

// prototypes of local interest
void usage();
void send_mail_file();
void init_params();
void check_spool_dir();
void check_execute_dir();
void check_log_dir();
void bad_file( const char *, const char *, Directory & );
void good_file( const char *, const char * );
void produce_output();
BOOLEAN is_valid_shared_exe( const char *name );
BOOLEAN is_ckpt_file( const char *name );
BOOLEAN is_v2_ckpt( const char *name );
BOOLEAN is_v3_ckpt( const char *name );
BOOLEAN cluster_exists( int );
BOOLEAN proc_exists( int, int );
BOOLEAN is_myproxy_file( const char *name );
BOOLEAN is_ccb_file( const char *name );

/*
  Tell folks how to use this program.
*/
void
usage()
{
	fprintf( stderr, "Usage: %s [-mail] [-remove] [-verbose]\n", MyName );
	exit( 1 );
}


int
main( int argc, char *argv[] )
{
#ifndef WIN32
		// Ignore SIGPIPE so if we cannot connect to a daemon we do
		// not blowup with a sig 13.
    install_sig_handler(SIGPIPE, SIG_IGN );
#endif

		// Initialize things
	MyName = argv[0];
	myDistro->Init( argc, argv );
	config();
	init_params();
	BadFiles = new StringList;

		// Parse command line arguments
	for( argv++; *argv; argv++ ) {
		if( (*argv)[0] == '-' ) {
			switch( (*argv)[1] ) {
			
			  case 'v':
				VerboseFlag = TRUE;
				break;

			  case 'm':
				MailFlag = TRUE;
				break;

			  case 'r':
				RmFlag = TRUE;
				break;

			  default:
				usage();

			}
		} else {
			usage();
		}
	}

		// Do the file checking
	check_spool_dir();
	check_execute_dir();
	check_log_dir();


		// Produce output, either on stdout or by mail
	if( !BadFiles->isEmpty() ) {
		produce_output();
	}

		// Clean up
	delete BadFiles;

	return 0;
}

/*
  As the program runs, we create a list of messages regarding the status
  of file in the list BadFiles.  Now we use that to produce all output.
  If MailFlag is set, we send the output to the condor administrators
  via mail, otherwise we just print it on stdout.
*/
void
produce_output()
{
	char	*str;
	FILE	*mailer;
	MyString subject;
	subject.sprintf("condor_preen results %s: %d old file%s found", 
		my_full_hostname(), BadFiles->number(), 
		(BadFiles->number() > 1)?"s":"");

	if( MailFlag ) {
		if( (mailer=email_open(PreenAdmin, subject.Value())) == NULL ) {
			EXCEPT( "Can't do email_open(\"%s\", \"%s\")\n",PreenAdmin,subject.Value());
		}
	} else {
		mailer = stdout;
	}

	if( MailFlag ) {
		fprintf( mailer, "\n" );
		fprintf( mailer,
			 "The condor_preen process has found the following\n"
			 "stale condor files on <%s>:\n\n", my_hostname() );
	}

	for( BadFiles->rewind(); (str = BadFiles->next()); ) {
		fprintf( mailer, "  %s\n", str );
	}

	if( MailFlag ) {
		char *explanation = "\n\nWhat is condor_preen?\n\n"
"The condor_preen tool examines the directories belonging to Condor, and\n"
"removes extraneous files and directories which may be left over from Condor\n"
"processes which terminated abnormally either due to internal errors or a\n"
"system crash.  The directories checked are the LOG, EXECUTE, and SPOOL\n"
"directories as defined in the Condor configuration files.  The condor_preen\n"
"tool is intended to be run as user root (or user condor) periodically as a\n"
"backup method to ensure reasonable file system cleanliness in the face of\n"
"errors. This is done automatically by default by the condor_master daemon.\n"
"It may also be explicitly invoked on an as needed basis.\n\n"
"See the Condor manual section on condor_preen for more details.\n";

		fprintf( mailer, "%s\n", explanation );
		email_close( mailer );
	}
}


/*
  Check the condor spool directory for extraneous files.  Files found
  there should either be on a list of well known files, or should be
  checkpoint files belonging to jobs currently in the job queue.  We
  create a global list of all jobs in the queue for use by lower level
  routines which will check actual files aginst the job queue to see
  if they are legitimate checkpoints.
*/
void
check_spool_dir()
{
    unsigned int	history_length, startd_history_length;
	const char  	*f;
    const char      *history, *startd_history;
	Directory  		dir(Spool, PRIV_ROOT);
	StringList 		well_known_list, bad_spool_files;
	Qmgr_connection *qmgr;

	if ( ValidSpoolFiles == NULL ) {
		dprintf( D_ALWAYS, "Not cleaning spool directory: No VALID_SPOOL_FILES defined\n");
		return;
	}

    history = param("HISTORY");
    history = condor_basename(history); // condor_basename never returns NULL
    history_length = strlen(history);

    startd_history = param("STARTD_HISTORY");
   	startd_history = condor_basename(startd_history);
   	startd_history_length = strlen(startd_history);

	well_known_list.initializeFromString (ValidSpoolFiles);
		// add some reasonable defaults that we never want to remove
	well_known_list.append( "job_queue.log" );
	well_known_list.append( "job_queue.log.tmp" );
	well_known_list.append( "Accountant.log" );
	well_known_list.append( "Accountantnew.log" );
	well_known_list.append( "local_univ_execute" );
	well_known_list.append( "EventdShutdownRate.log" );
		// SCHEDD.lock: High availability lock file.  Current
		// manual recommends putting it in the spool, so avoid it.
	well_known_list.append( "SCHEDD.lock" );
		// These are Quill-related files
	well_known_list.append( ".quillwritepassword" );
	well_known_list.append( ".pgpass" );

	// connect to the Q manager
	if (!(qmgr = ConnectQ (0))) {
		dprintf( D_ALWAYS, "Not cleaning spool directory: Can't contact schedd\n" );
		return;
	}

		// Check each file in the directory
	while( (f = dir.Next()) ) {
			// see if it's on the list
		if( well_known_list.contains(f) ) {
			good_file( Spool, f );
			continue;
		}
		if( !strncmp(f,"job_queue.log",13) ) {
			// Historical job queue log files have names like: job_queue.log.3
			// In theory, we could clean up any such files that are not
			// in the range allowed by SCHEDD_MAX_HISTORICAL_LOGS, but
			// the sequence number keeps increasing each time a new
			// one is added, so we would have to find out what the latest
			// sequence number is in order to know what is safe to delete.
			// Therefore, this issue is ignored.  We rely on the schedd
			// to clean up after itself.
			good_file( Spool, f );
			continue;
		}
            // see if it's a rotated history file. 
        if (   strlen(f) >= history_length 
            && strncmp(f, history, history_length) == 0) {
            good_file( Spool, f );
            continue;
        }

			// if startd_history is defined, so if it's one of those
		if ( startd_history_length > 0 &&
			strlen(f) >= startd_history_length &&
			strncmp(f, startd_history, startd_history_length) == 0) {

            good_file( Spool, f );
            continue;
		}

			// see it it's an in-use shared executable
		if( is_valid_shared_exe(f) ) {
			good_file( Spool, f );
			continue;
		}

			// see if it's a legitimate checkpoint
		if( is_ckpt_file(f) ) {
			good_file( Spool, f );
			continue;
		}

			// See if it's a legimate MyProxy password file
		if ( is_myproxy_file( f ) ) {
			good_file( Spool, f );
			continue;
		}

			// See if it's a CCB server file
		if ( is_ccb_file( f ) ) {
			good_file( Spool, f );
			continue;
		}

			// We think it's bad.  For now, just append it to a
			// StringList, instead of actually deleting it.  This way,
			// if DisconnectQ() fails, we can abort and not actually
			// delete any of these files.  -Derek Wright 3/31/99
		bad_spool_files.append( f );
	}

	if( DisconnectQ(qmgr) ) {
			// We were actually talking to a real queue the whole time
			// and didn't have any errors.  So, it's now safe to
			// delete the files we think we can delete.
		bad_spool_files.rewind();
		while( (f = bad_spool_files.next()) ) {
			bad_file( Spool, f, dir );
		}
	} else {
		dprintf( D_ALWAYS, 
				 "Error disconnecting from job queue, not deleting spool files.\n" );
	}
}

/*
*/
BOOLEAN
is_valid_shared_exe( const char *name )
{
	if ((strlen(name) < 4) || (strncmp(name, "exe-", 4) != 0)) {
		return FALSE;
	}
	MyString path;
	path.sprintf("%s/%s", Spool, name);
	int count = link_count(path.Value());
	if (count == 1) {
		return FALSE;
	}
	if (count == -1) {
		dprintf(D_ALWAYS, "link_count error on %s; not deleting\n", name);
	}
	return TRUE;
}

/*
  Given the name of a file in the spool directory, return TRUE if it's a
  legitimate checkpoint file, and FALSE otherwise.  If the name starts
  with "cluster", it should be a V3 style checkpoint.  Otherwise it is
  either a V2 style checkpoint, or not a checkpoint at all.
*/
BOOLEAN
is_ckpt_file( const char *name )
{

	if( strstr(name,"cluster") ) {
		return is_v3_ckpt( name );
	} else {
		return is_v2_ckpt( name );
	}

}


/*
  Grab an integer value which has been embedded in a file name.  We're given
  a name to examine, and a pattern to search for.  If the pattern exists,
  then the number we want follows it immediately.  If the pattern doesn't
  exist, we return -1.
*/
inline int
grab_val( const char *str, const char *pattern )
{
	char const *ptr;

	if( (ptr = strstr(str,pattern)) ) {
		return atoi(ptr + strlen(pattern) );
	}
	return -1;
}

/*
  We're given the name of a file which appears to be a V2 checkpoint file.
  We try to dig out the cluster/proc ids, and search the job queue for
  a corresponding process.  We return TRUE if we find it, and FALSE
  otherwise.

  V2 checkpoint files formats are:
	  job<#>.ickpt		- initial checkpoint file
	  job<#>.ckpt.<#>	- specific checkpoint file
*/
BOOLEAN
is_v2_ckpt( const char *name )
{
	int		cluster;
	int		proc;

	cluster = grab_val( name, "job" );
	proc = grab_val( name, ".ckpt." );

	if( proc < 0 ) {
		return cluster_exists( cluster );
	} else {
		return proc_exists( cluster, proc );
	}
}

/*
  We're given the name of a file which appears to be a V3 checkpoint file.
  We try to dig out the cluster/proc ids, and search the job queue for
  a corresponding process.  We return TRUE if we find it, and FALSE
  otherwise.

  V3 checkpoint file formats are:
	  cluster<#>.ickpt.subproc<#>		- initial checkpoint file
	  cluster<#>.proc<#>.subproc<#>		- specific checkpoint file
*/
BOOLEAN
is_v3_ckpt( const char *name )
{
	int		cluster;
	int		proc;
	int		subproc;

	cluster = grab_val( name, "cluster" );
	proc = grab_val( name, ".proc" );
	subproc = grab_val( name, ".subproc" );

		
	if( proc < 0 ) {
		return cluster_exists( cluster );
	} else {
		return proc_exists( cluster, proc );
	}
}

/*
  Check whether the given file could be a valid MyProxy password file
  for a queued job.
*/
BOOLEAN
is_myproxy_file( const char *name )
{
	int cluster, proc;

		// TODO This will accept files that look like a valid MyProxy
		//   password file with extra characters on the end of the name.
	int rc = sscanf( name, "mpp.%d.%d", &cluster, &proc );
	if ( rc != 2 ) {
		return FALSE;
	}
	return proc_exists( cluster, proc );
}

/*
  Check whether the given file could be a valid MyProxy password file
  for a queued job.
*/
BOOLEAN
is_ccb_file( const char *name )
{
	if( strstr(name,".ccb_reconnect") ) {
		return TRUE;
	}
	return FALSE;
}

/*
  Check to see whether a given cluster number exists in the job queue.
*/
BOOLEAN
cluster_exists( int cluster )
{
	return proc_exists( cluster, -1 );
}

/*
  Check to see whether a given cluster and process number exist in the
  job queue.
*/
BOOLEAN
proc_exists( int cluster, int proc )
{
	ClassAd *ad;

	if ((ad = GetJobAd(cluster,proc)) != NULL) {
		FreeJobAd(ad);
		return TRUE;
	}

	return FALSE;
}

/*
  Scan the execute directory looking for bogus files.
*/ 
void
check_execute_dir()
{
	time_t now = time(NULL);
	const char	*f;
	bool	busy;
	State	s = get_machine_state();

		// If we know the state of the machine, we can use a simple
		// algorithm.  If we are hosting a job - anything goes,
		// otherwise the execute directory should be empty.  If we
		// can't find the state, just leave the execute directory
		// alone.  -Derek Wright 4/2/99
	switch( s ) {
	case owner_state:	
	case unclaimed_state:
	case matched_state:	
		busy = false;
		break;
	case claimed_state:
	case preempting_state:
		busy = true;
		break;
	default:
		dprintf( D_ALWAYS, 
				 "Error getting startd state, not cleaning execute directory.\n" );
		return;
	}

	ExecuteDirs.rewind();
	char const *Execute;
	while( (Execute=ExecuteDirs.next()) ) {
		Directory dir( Execute, PRIV_ROOT );
		while( (f = dir.Next()) ) {
			if( busy ) {
				good_file( Execute, f );	// let anything go here
			} else {
				if( dir.GetCreateTime() < now ) {
					bad_file( Execute, f, dir ); // junk it
				}
				else {
						// In case the startd just started up a job, we
						// avoid removing very recently created files.
						// (So any files forward dated in time will have
						// to wait for the startd to restart before they
						// are cleaned up.)
					dprintf(D_FULLDEBUG, "In %s, found %s with recent "
					        "creation time.  Not removing.\n", Execute, f );
					good_file( Execute, f ); // too young to kill
				}
			}
		}
	}
}

/*
  Scan the log directory for bogus files.  All files in the log directory
  should have well known names.
*/
void
check_log_dir()
{
	const char	*f;
	Directory dir(Log, PRIV_ROOT);
	StringList invalid;

	invalid.initializeFromString (InvalidLogFiles ? InvalidLogFiles : "");

	while( (f = dir.Next()) ) {
		if( invalid.contains(f) ) {
			bad_file( Log, f, dir );
		} else {
			good_file( Log, f );
		}
	}
}
	

extern "C" int
SetSyscalls( int foo ) { return foo; }

/*
  Initialize information from the configuration files.
*/
void
init_params()
{
	Spool = param("SPOOL");
    if( Spool == NULL ) {
        EXCEPT( "SPOOL not specified in config file\n" );
    }

	Log = param("LOG");
    if( Log == NULL ) {
        EXCEPT( "LOG not specified in config file\n" );
    }

	char *Execute = param("EXECUTE");
	if( Execute ) {
		ExecuteDirs.append(Execute);
		free(Execute);
		Execute = NULL;
	}
		// In addition to EXECUTE, there may be SLOT1_EXECUTE, ...
	ExtArray<ParamValue> *params = param_all();
	for( int p=params->length(); p--; ) {
		char const *name = (*params)[p].name.Value();
		char *tail = NULL;
		if( strncasecmp( name, "SLOT", 4 ) != 0 ) continue;
		strtol( name+4, &tail, 10 );
		if( tail <= name || strcasecmp( tail, "_EXECUTE" ) != 0 ) continue;

		Execute = param(name);
		if( Execute ) {
			if( !ExecuteDirs.contains( Execute ) ) {
				ExecuteDirs.append( Execute );
			}
			free( Execute );
		}
	}
	delete params;

    if( (PreenAdmin = param("PREEN_ADMIN")) == NULL ) {
		if( (PreenAdmin = param("CONDOR_ADMIN")) == NULL ) {
			EXCEPT( "CONDOR_ADMIN not specified in config file" );
		}
    }

	ValidSpoolFiles = param("VALID_SPOOL_FILES");

	InvalidLogFiles = param("INVALID_LOG_FILES");

	if( (MailPrg = param("MAIL")) == NULL ) {
		EXCEPT ( "MAIL not specified in config file" );
	}
}


/*
  Produce output for a file that has been determined to be legitimate.
*/
void
good_file( const char *dir, const char *name )
{
	if( VerboseFlag ) {
		printf( "%s%c%s - OK\n", dir, DIR_DELIM_CHAR, name );
	}
}

/*
  Produce output for a file that has been determined to be bogus.  We also
  remove the file here if that has been called for in our command line
  arguments.
*/
void
bad_file( const char *dirpath, const char *name, Directory & dir )
{
	MyString	pathname;
	MyString	buf;

	pathname.sprintf( "%s%c%s", dirpath, DIR_DELIM_CHAR, name );

	if( VerboseFlag ) {
		printf( "%s - BAD\n", pathname.Value() );
	}

	if( RmFlag ) {
		bool removed = dir.Remove_Full_Path( pathname.Value() );
		if( !removed && privsep_enabled() ) {
			removed = privsep_remove_dir( pathname.Value() );
			if( VerboseFlag ) {
				if( removed ) {
					printf( "%s - failed to remove directly, but succeeded via privsep switchboard\n", pathname.Value() );
				}
			}
		}
		if( removed ) {
			buf.sprintf( "%s - Removed", pathname.Value() );
		} else {
			buf.sprintf( "%s - Can't Remove", pathname.Value() );
		}
	} else {
		buf.sprintf( "%s - Not Removed", pathname.Value() );
	}
	BadFiles->append( buf.Value() );
}


// Returns the state of the local startd
State
get_machine_state()
{
	char* state_str = NULL;
	State s;

	ReliSock* sock;
	Daemon my_startd( DT_STARTD );
	if( ! my_startd.locate() ) {
		dprintf( D_ALWAYS, "Can't find local startd address.\n" );
		return _error_state_;
	}
   
	if( !(sock = (ReliSock*)
		  my_startd.startCommand(GIVE_STATE, Stream::reli_sock, 0)) ) {
		dprintf( D_ALWAYS, "Can't connect to startd at %s\n", 
				 my_startd.addr() );
		return _error_state_;
	}

	sock->eom();
	sock->decode();
	if( !sock->code( state_str ) || !sock->end_of_message() ) {
		dprintf( D_ALWAYS, "Can't read state/eom from startd.\n" );
		free(state_str);
		return _error_state_;
	}

	sock->close();
	delete sock;

	s = string_to_state( state_str );
	free(state_str);
	return s;
}

