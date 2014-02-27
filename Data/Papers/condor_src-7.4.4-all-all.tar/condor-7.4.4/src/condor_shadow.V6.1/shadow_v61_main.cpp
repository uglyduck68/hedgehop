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


#include "condor_common.h"
#include "condor_daemon_core.h"
#include "subsystem_info.h"
#include "baseshadow.h"
#include "shadow.h"
#include "mpishadow.h"
#include "parallelshadow.h"
#include "exit.h"
#include "condor_debug.h"
#include "condor_version.h"
#include "condor_attributes.h"

BaseShadow *Shadow = NULL;

// settings we're given on the command-line
static const char* schedd_addr = NULL;
const char* public_schedd_addr = NULL;
static const char* job_ad_file = NULL;
static bool is_reconnect = false;
static int cluster = -1;
static int proc = -1;
static const char * xfer_queue_contact_info = NULL;

static void
usage( int argc, char* argv[] )
{
	dprintf( D_ALWAYS, "Usage: %s cluster.proc schedd_addr file_name\n",
			 argv[0] );
	for (int i=0; i < argc; i++) {
		dprintf(D_ALWAYS, "argv[%d] = %s\n", i, argv[i]);
	}
	exit( JOB_SHADOW_USAGE );
}


extern "C" {
int
ExceptCleanup(int, int, char *buf)
{
  BaseShadow::log_except(buf);
  return 0;
}
}

/* DaemonCore interface implementation */

DECL_SUBSYSTEM( "SHADOW", SUBSYSTEM_TYPE_SHADOW );

int
dummy_reaper(Service *,int pid,int)
{
	dprintf(D_ALWAYS,"dummy-reaper: pid %d exited; ignored\n",pid);
	return TRUE;
}


void
parseArgs( int argc, char *argv[] )
{
	char *opt;
	int args_handled = 0;

	char** tmp = argv;
	for( tmp++; *tmp; tmp++ ) {
		opt = tmp[0];

		if( sscanf(opt, "%d.%d", &cluster, &proc) == 2 ) {
			if( cluster < 0 || proc < 0 ) {
				dprintf(D_ALWAYS, 
						"ERROR: invalid cluster.proc specified: %s\n", opt);
				usage(argc, argv);
			}
				// great, it was a job id, we're done with this option
			args_handled++;
			continue;
		}
		
		if( opt[0] == '<' ) { 
				// might be the schedd's address
			if( is_valid_sinful(opt) ) {
				schedd_addr = opt;
				args_handled++;
				continue;
			} else {
				dprintf(D_ALWAYS, 
						"ERROR: invalid shadow-private schedd_addr specified: %s\n", opt);
				usage(argc, argv);
			}
		}

		if( !strcmp(opt, "--reconnect") || !strcmp(opt, "-reconnect") ) {
			is_reconnect = true;
			args_handled++;
			continue;
		}

		if (strncmp(opt, "--schedd", 8) == 0) {
			char *ptr = strchr(opt, '<');
			if (ptr && is_valid_sinful(ptr)) {
				public_schedd_addr = ptr;
				args_handled++;
				continue;
			}
			else {
				dprintf(D_ALWAYS, 
						"ERROR: invalid public schedd_addr specified: %s\n",
						opt);
				usage(argc, argv);
			}
		}

		if (strncmp(opt, "--xfer-queue=", 13) == 0) {
			xfer_queue_contact_info = opt+13;
			args_handled++;
			continue;
		}

			// the only other argument we understand is the
			// filename we should read our ClassAd from, "-" for
			// STDIN.  There's no further checking we need to do 
		if( job_ad_file ) {
				// already were here, bail out
			dprintf( D_ALWAYS, "ERROR: unrecognized option (%s)\n", opt );
			usage(argc, argv);
		}
		job_ad_file = opt;
		args_handled++;
	}
	if( args_handled < 3 || args_handled != (argc-1) ) {
		dprintf( D_ALWAYS, "ERROR: missing command-line arguments!" );
		usage(argc, argv);
	}
}


ClassAd* 
readJobAd( void )
{
	ClassAd* ad = NULL;
	FILE* fp = NULL;
	bool is_stdin = false;
	bool read_something = false;

	ASSERT( job_ad_file );

	if( job_ad_file[0] == '-' && job_ad_file[1] == '\0' ) {
		fp = stdin;
		is_stdin = true;
	} else {
		fp = safe_fopen_wrapper( job_ad_file, "r" );
		if( ! fp ) {
			EXCEPT( "Failed to open ClassAd file (%s): %s (errno %d)",
					job_ad_file, strerror(errno), errno );
		}
	}

	dprintf( D_FULLDEBUG, "Reading job ClassAd from %s\n",
			 is_stdin ? "STDIN" : job_ad_file );

	ad = new ClassAd;
	MyString line;
	while( line.readLine(fp) ) {
        read_something = true;
		line.chomp();
		if( line[0] == '#' ) {
			dprintf( D_JOB, "IGNORING COMMENT: %s\n", line.Value() );
			continue;
		}
		if( line == "***" ) {
			dprintf( D_JOB, "Saw ClassAd delimitor, stopping\n" );
			break;
		}
        if( ! ad->Insert(line.Value()) ) {
			EXCEPT( "Failed to insert \"%s\" into ClassAd!", line.Value() );
        }
    }
	if( ! read_something ) {
		EXCEPT( "ERROR reading ClassAd from (%s): file is empty",
				is_stdin ? "STDIN" : job_ad_file );
	}
	if( (DebugFlags & D_JOB) && (DebugFlags & D_FULLDEBUG) ) {
		ad->dPrint( D_JOB );
	} 
	if( ! is_stdin ) {
		fclose( fp );
	}

	// For debugging, see if there's a special attribute in the
	// job ad that sends us into an infinite loop, waiting for
	// someone to attach with a debugger
	int shadow_should_wait = 0;
	ad->LookupInteger( ATTR_SHADOW_WAIT_FOR_DEBUG,
					   shadow_should_wait );
	if( shadow_should_wait ) {
		dprintf( D_ALWAYS, "Job requested shadow should wait for "
			"debugger with %s=%d, going into infinite loop\n",
			ATTR_SHADOW_WAIT_FOR_DEBUG, shadow_should_wait );
		while( shadow_should_wait );
	}

	return ad;
}


void
initShadow( ClassAd* ad )
{
	int universe; 
	if( ! ad->LookupInteger(ATTR_JOB_UNIVERSE, universe) ) {
			// change to the right universes when everything works.
		dprintf( D_ALWAYS, "WARNING %s not specified, assuming VANILLA\n", 
				 ATTR_JOB_UNIVERSE );
		universe = CONDOR_UNIVERSE_VANILLA;
	}

	dprintf( D_ALWAYS, "Initializing a %s shadow for job %d.%d\n", 
			 CondorUniverseName(universe), cluster, proc );

	switch ( universe ) {
	case CONDOR_UNIVERSE_PARALLEL:
		Shadow = new ParallelShadow();
		break;
	case CONDOR_UNIVERSE_VANILLA:
	case CONDOR_UNIVERSE_JAVA:
	case CONDOR_UNIVERSE_VM:
		Shadow = new UniShadow();
		break;
	case CONDOR_UNIVERSE_MPI:
		Shadow = new MPIShadow();
		break;
	case CONDOR_UNIVERSE_PVM:
			// some day we'll support this.  for now, fall through and
			// print out an error message that might mean something to
			// our user, not "PVM...hopefully one day..."
//		Shadow = new PVMShadow();
//		break;
	default:
		dprintf( D_ALWAYS, "This version of the shadow cannot support "
				 "universe %d (%s)\n", universe,
				 CondorUniverseName(universe) );
		EXCEPT( "Universe not supported" );
	}
	Shadow->init( ad, schedd_addr, xfer_queue_contact_info );
}


int
main_init(int argc, char *argv[])
{
	_EXCEPT_Cleanup = ExceptCleanup;

		/* Start up with condor.condor privileges. */
	set_condor_priv();

		// Register a do-nothing reaper.  This is just because the
		// file transfer object, which could be instantiated later,
		// registers its own reaper and does an EXCEPT if it gets
		// a reaper ID of 1 (since lots of other daemons have a reaper
		// ID of 1 hard-coded as special... this is bad).
	daemonCore->Register_Reaper("dummy_reaper",
							(ReaperHandler)&dummy_reaper,
							"dummy_reaper",NULL);


	parseArgs( argc, argv );

	ClassAd* ad = readJobAd();
	if( ! ad ) {
		EXCEPT( "Failed to read job ad!" );
	}

		// see if the SchedD punched a DAEMON-level authorization
		// hole for this job. if it did, we'll do the same here
		//
	MyString auth_hole_id;
	if (ad->LookupString(ATTR_STARTD_PRINCIPAL, auth_hole_id)) {
		IpVerify* ipv = daemonCore->getIpVerify();
		if (!ipv->PunchHole(DAEMON, auth_hole_id)) {
			dprintf(D_ALWAYS,
			        "WARNING: IpVerify::PunchHole error for %s: "
			            "job may fail to execute\n",
			        auth_hole_id.Value());
		}
	}

	initShadow( ad );

	if( is_reconnect ) {
		Shadow->reconnect();
	} else {
		Shadow->spawn();
	}		

	return 0;
}


int
main_config( bool /* is_full */ )
{
	Shadow->config();
	return 0;
}


int
main_shutdown_fast()
{
	Shadow->shutDown( JOB_NOT_CKPTED );
	return 0;
}

int
main_shutdown_graceful()
{
	Shadow->gracefulShutDown();
	return 0;
}


void
dumpClassad( const char* header, ClassAd* ad, int debug_flag )
{
	if( ! header  ) {
		dprintf( D_ALWAYS, "ERROR: called dumpClassad() w/ NULL header\n" ); 
		return;
	}
	if( ! ad  ) {
		dprintf( D_ALWAYS, "ERROR: called dumpClassad(\"%s\") w/ NULL ad\n", 
				 header );   
		return;
	}
	if( DebugFlags & debug_flag ) {
		dprintf( debug_flag, "*** ClassAd Dump: %s ***\n", header );  
		ad->dPrint( debug_flag );
		dprintf( debug_flag, "--- End of ClassAd ---\n" );
	}
}


void
printClassAd( void )
{
	printf( "%s = True\n", ATTR_IS_DAEMON_CORE );
	printf( "%s = True\n", ATTR_HAS_FILE_TRANSFER );
	printf( "%s = True\n", ATTR_HAS_PER_FILE_ENCRYPTION );
	printf( "%s = True\n", ATTR_HAS_MPI );
	printf( "%s = True\n", ATTR_HAS_JAVA );
	printf( "%s = True\n", ATTR_HAS_RECONNECT );
	printf( "%s = True\n", ATTR_HAS_JOB_AD_FROM_FILE );
	printf( "%s = True\n", ATTR_HAS_VM );
	printf( "%s = \"%s\"\n", ATTR_VERSION, CondorVersion() );
}


void
main_pre_dc_init( int argc, char* argv[] )
{
	if( argc == 2 && strincmp(argv[1],"-cl",3) == MATCH ) {
		printClassAd();
		exit(0);
	}
}


void
main_pre_command_sock_init( )
{
}
