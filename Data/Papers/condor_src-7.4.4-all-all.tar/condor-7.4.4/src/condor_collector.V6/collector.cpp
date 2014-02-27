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
#include "condor_classad.h"
#include "condor_parser.h"
#include "condor_status.h"
#include "condor_debug.h"
#include "condor_config.h"
#include "condor_network.h"
#include "internet.h"
#include "condor_io.h"
#include "condor_attributes.h"
#include "condor_parameters.h"
#include "condor_email.h"
#include "condor_query.h"

#include "condor_daemon_core.h"
#include "../condor_status.V6/status_types.h"
#include "../condor_status.V6/totals.h"

#include "condor_collector.h"
#include "collector_engine.h"
#include "HashTable.h"
#include "hashkey.h"

#include "condor_uid.h"
#include "condor_adtypes.h"
#include "condor_universe.h"
#include "my_hostname.h"
#include "condor_threads.h"

#include "collector.h"

#if HAVE_DLOPEN
#include "CollectorPlugin.h"
#endif

#include "ccb_server.h"

//----------------------------------------------------------------

extern "C" char* CondorVersion( void );
extern "C" char* CondorPlatform( void );

CollectorStats CollectorDaemon::collectorStats( false, 0, 0 );
CollectorEngine CollectorDaemon::collector( &collectorStats );
int CollectorDaemon::ClientTimeout;
int CollectorDaemon::QueryTimeout;
char* CollectorDaemon::CollectorName;
Daemon* CollectorDaemon::View_Collector;
Sock* CollectorDaemon::view_sock;
SocketCache* CollectorDaemon::sock_cache;

ClassAd* CollectorDaemon::__query__;
int CollectorDaemon::__numAds__;
int CollectorDaemon::__failed__;
List<ClassAd>* CollectorDaemon::__ClassAdResultList__;

TrackTotals* CollectorDaemon::normalTotals;
int CollectorDaemon::submittorRunningJobs;
int CollectorDaemon::submittorIdleJobs;

CollectorUniverseStats CollectorDaemon::ustatsAccum;
CollectorUniverseStats CollectorDaemon::ustatsMonthly;

int CollectorDaemon::machinesTotal;
int CollectorDaemon::machinesUnclaimed;
int CollectorDaemon::machinesClaimed;
int CollectorDaemon::machinesOwner;

ForkWork CollectorDaemon::forkQuery;

ClassAd* CollectorDaemon::ad;
CollectorList* CollectorDaemon::updateCollectors;
DCCollector* CollectorDaemon::updateRemoteCollector;
int CollectorDaemon::UpdateTimerId;

ClassAd *CollectorDaemon::query_any_result;
ClassAd CollectorDaemon::query_any_request;

#if ( HAVE_HIBERNATION )
OfflineCollectorPlugin CollectorDaemon::offline_plugin_;
#endif

CCBServer *CollectorDaemon::m_ccb_server;

//---------------------------------------------------------

// prototypes of library functions
typedef void (*SIGNAL_HANDLER)();
extern "C"
{
	void install_sig_handler( int, SIGNAL_HANDLER );
	void schedule_event ( int month, int day, int hour, int minute, int second, SIGNAL_HANDLER );
}

//----------------------------------------------------------------

void computeProjection(ClassAd *shortAd, ClassAd *curr_ad, SimpleList<MyString> *projectionList);

void CollectorDaemon::Init()
{
	dprintf(D_ALWAYS, "In CollectorDaemon::Init()\n");

	// read in various parameters from condor_config
	CollectorName=NULL;
	ad=NULL;
	View_Collector=NULL;
	view_sock=NULL;
	UpdateTimerId=-1;
	sock_cache = NULL;
	updateCollectors = NULL;
	updateRemoteCollector = NULL;
	Config();

    // setup routine to report to condor developers
    // schedule reports to developers
	schedule_event( -1, 1,  0, 0, 0, reportToDevelopers );
	schedule_event( -1, 8,  0, 0, 0, reportToDevelopers );
	schedule_event( -1, 15, 0, 0, 0, reportToDevelopers );
	schedule_event( -1, 23, 0, 0, 0, reportToDevelopers );

	// install command handlers for queries
	daemonCore->Register_Command(QUERY_STARTD_ADS,"QUERY_STARTD_ADS",
		(CommandHandler)receive_query_cedar,"receive_query_cedar",NULL,READ);
	daemonCore->Register_Command(QUERY_STARTD_PVT_ADS,"QUERY_STARTD_PVT_ADS",
		(CommandHandler)receive_query_cedar,"receive_query_cedar",NULL,NEGOTIATOR);
#ifdef WANT_QUILL
	daemonCore->Register_Command(QUERY_QUILL_ADS,"QUERY_QUILL_ADS",
		(CommandHandler)receive_query_cedar,"receive_query_cedar",NULL,READ);
#endif /* WANT_QUILL */

	daemonCore->Register_Command(QUERY_SCHEDD_ADS,"QUERY_SCHEDD_ADS",
		(CommandHandler)receive_query_cedar,"receive_query_cedar",NULL,READ);
	daemonCore->Register_Command(QUERY_MASTER_ADS,"QUERY_MASTER_ADS",
		(CommandHandler)receive_query_cedar,"receive_query_cedar",NULL,READ);
	daemonCore->Register_Command(QUERY_CKPT_SRVR_ADS,"QUERY_CKPT_SRVR_ADS",
		(CommandHandler)receive_query_cedar,"receive_query_cedar",NULL,READ);
	daemonCore->Register_Command(QUERY_SUBMITTOR_ADS,"QUERY_SUBMITTOR_ADS",
		(CommandHandler)receive_query_cedar,"receive_query_cedar",NULL,READ);
	daemonCore->Register_Command(QUERY_LICENSE_ADS,"QUERY_LICENSE_ADS",
		(CommandHandler)receive_query_cedar,"receive_query_cedar",NULL,READ);
	daemonCore->Register_Command(QUERY_COLLECTOR_ADS,"QUERY_COLLECTOR_ADS",
		(CommandHandler)receive_query_cedar,"receive_query_cedar",NULL,ADMINISTRATOR);
	daemonCore->Register_Command(QUERY_STORAGE_ADS,"QUERY_STORAGE_ADS",
		(CommandHandler)receive_query_cedar,"receive_query_cedar",NULL,READ);
	daemonCore->Register_Command(QUERY_NEGOTIATOR_ADS,"QUERY_NEGOTIATOR_ADS",
		(CommandHandler)receive_query_cedar,"receive_query_cedar",NULL,READ);
	daemonCore->Register_Command(QUERY_HAD_ADS,"QUERY_HAD_ADS",
		(CommandHandler)receive_query_cedar,"receive_query_cedar",NULL,READ);
	daemonCore->Register_Command(QUERY_XFER_SERVICE_ADS,"QUERY_XFER_SERVICE_ADS",
		(CommandHandler)receive_query_cedar,"receive_query_cedar",NULL,READ);
	daemonCore->Register_Command(QUERY_LEASE_MANAGER_ADS,"QUERY_LEASE_MANAGER_ADS",
		(CommandHandler)receive_query_cedar,"receive_query_cedar",NULL,READ);
	daemonCore->Register_Command(QUERY_ANY_ADS,"QUERY_ANY_ADS",
		(CommandHandler)receive_query_cedar,"receive_query_cedar",NULL,READ);
    daemonCore->Register_Command(QUERY_GRID_ADS,"QUERY_GRID_ADS",
		(CommandHandler)receive_query_cedar,"receive_query_cedar",NULL,READ);
	daemonCore->Register_Command(QUERY_GENERIC_ADS,"QUERY_GENERIC_ADS",
		(CommandHandler)receive_query_cedar,"receive_query_cedar",NULL,READ);
	
		// // // // // // // // // // // // // // // // // // // // //
		// WARNING!!!! If you add other invalidate commands here, you
		// also need to add them to the switch statement in the
		// sockCacheHandler() method!!!
		// // // // // // // // // // // // // // // // // // // // //

	// install command handlers for invalidations
	daemonCore->Register_Command(INVALIDATE_STARTD_ADS,"INVALIDATE_STARTD_ADS",
		(CommandHandler)receive_invalidation,"receive_invalidation",NULL,ADVERTISE_STARTD_PERM);

#ifdef WANT_QUILL
	daemonCore->Register_Command(INVALIDATE_QUILL_ADS,"INVALIDATE_QUILL_ADS",
		(CommandHandler)receive_invalidation,"receive_invalidation",NULL,DAEMON);
#endif /* WANT_QUILL */

	daemonCore->Register_Command(INVALIDATE_SCHEDD_ADS,"INVALIDATE_SCHEDD_ADS",
		(CommandHandler)receive_invalidation,"receive_invalidation",NULL,ADVERTISE_SCHEDD_PERM);
	daemonCore->Register_Command(INVALIDATE_MASTER_ADS,"INVALIDATE_MASTER_ADS",
		(CommandHandler)receive_invalidation,"receive_invalidation",NULL,ADVERTISE_MASTER_PERM);
	daemonCore->Register_Command(INVALIDATE_CKPT_SRVR_ADS,
		"INVALIDATE_CKPT_SRVR_ADS", (CommandHandler)receive_invalidation,
		"receive_invalidation",NULL,DAEMON);
	daemonCore->Register_Command(INVALIDATE_SUBMITTOR_ADS,
		"INVALIDATE_SUBMITTOR_ADS", (CommandHandler)receive_invalidation,
		"receive_invalidation",NULL,ADVERTISE_SCHEDD_PERM);
	daemonCore->Register_Command(INVALIDATE_LICENSE_ADS,
		"INVALIDATE_LICENSE_ADS", (CommandHandler)receive_invalidation,
		"receive_invalidation",NULL,DAEMON);
	daemonCore->Register_Command(INVALIDATE_COLLECTOR_ADS,
		"INVALIDATE_COLLECTOR_ADS", (CommandHandler)receive_invalidation,
		"receive_invalidation",NULL,DAEMON);
	daemonCore->Register_Command(INVALIDATE_STORAGE_ADS,
		"INVALIDATE_STORAGE_ADS", (CommandHandler)receive_invalidation,
		"receive_invalidation",NULL,DAEMON);
	daemonCore->Register_Command(INVALIDATE_NEGOTIATOR_ADS,
		"INVALIDATE_NEGOTIATOR_ADS", (CommandHandler)receive_invalidation,
		"receive_invalidation",NULL,NEGOTIATOR);
	daemonCore->Register_Command(INVALIDATE_HAD_ADS,
		"INVALIDATE_HAD_ADS", (CommandHandler)receive_invalidation,
		"receive_invalidation",NULL,DAEMON);
	daemonCore->Register_Command(INVALIDATE_ADS_GENERIC,
		"INVALIDATE_ADS_GENERIC", (CommandHandler)receive_invalidation,
		"receive_invalidation",NULL,DAEMON);
	daemonCore->Register_Command(INVALIDATE_XFER_SERVICE_ADS,
		"INVALIDATE_XFER_ENDPOINT_ADS", (CommandHandler)receive_invalidation,
		"receive_invalidation",NULL,DAEMON);
	daemonCore->Register_Command(INVALIDATE_LEASE_MANAGER_ADS,
		"INVALIDATE_LEASE_MANAGER_ADS", (CommandHandler)receive_invalidation,
		"receive_invalidation",NULL,DAEMON);
    daemonCore->Register_Command(INVALIDATE_GRID_ADS,
        "INVALIDATE_GRID_ADS", (CommandHandler)receive_invalidation,
		"receive_invalidation",NULL,DAEMON);

		// // // // // // // // // // // // // // // // // // // // //
		// WARNING!!!! If you add other update commands here, you
		// also need to add them to the switch statement in the
		// sockCacheHandler() method!!!
		// // // // // // // // // // // // // // // // // // // // //

	// install command handlers for updates

#ifdef WANT_QUILL
	daemonCore->Register_Command(UPDATE_QUILL_AD,"UPDATE_QUILL_AD",
		(CommandHandler)receive_update,"receive_update",NULL,DAEMON);
#endif /* WANT_QUILL */

	daemonCore->Register_Command(UPDATE_STARTD_AD,"UPDATE_STARTD_AD",
		(CommandHandler)receive_update,"receive_update",NULL,ADVERTISE_STARTD_PERM);
	daemonCore->Register_Command(MERGE_STARTD_AD,"MERGE_STARTD_AD",
		(CommandHandler)receive_update,"receive_update",NULL,NEGOTIATOR);
	daemonCore->Register_Command(UPDATE_SCHEDD_AD,"UPDATE_SCHEDD_AD",
		(CommandHandler)receive_update,"receive_update",NULL,ADVERTISE_SCHEDD_PERM);
	daemonCore->Register_Command(UPDATE_SUBMITTOR_AD,"UPDATE_SUBMITTOR_AD",
		(CommandHandler)receive_update,"receive_update",NULL,ADVERTISE_SCHEDD_PERM);
	daemonCore->Register_Command(UPDATE_LICENSE_AD,"UPDATE_LICENSE_AD",
		(CommandHandler)receive_update,"receive_update",NULL,DAEMON);
	daemonCore->Register_Command(UPDATE_MASTER_AD,"UPDATE_MASTER_AD",
		(CommandHandler)receive_update,"receive_update",NULL,ADVERTISE_MASTER_PERM);
	daemonCore->Register_Command(UPDATE_CKPT_SRVR_AD,"UPDATE_CKPT_SRVR_AD",
		(CommandHandler)receive_update,"receive_update",NULL,DAEMON);
	daemonCore->Register_Command(UPDATE_COLLECTOR_AD,"UPDATE_COLLECTOR_AD",
		(CommandHandler)receive_update,"receive_update",NULL,ALLOW);
	daemonCore->Register_Command(UPDATE_STORAGE_AD,"UPDATE_STORAGE_AD",
		(CommandHandler)receive_update,"receive_update",NULL,DAEMON);
	daemonCore->Register_Command(UPDATE_NEGOTIATOR_AD,"UPDATE_NEGOTIATOR_AD",
		(CommandHandler)receive_update,"receive_update",NULL,NEGOTIATOR);
	daemonCore->Register_Command(UPDATE_HAD_AD,"UPDATE_HAD_AD",
		(CommandHandler)receive_update,"receive_update",NULL,DAEMON);
	daemonCore->Register_Command(UPDATE_XFER_SERVICE_AD,"UPDATE_XFER_SERVICE_AD",
		(CommandHandler)receive_update,"receive_update",NULL,DAEMON);
	daemonCore->Register_Command(UPDATE_LEASE_MANAGER_AD,"UPDATE_LEASE_MANAGER_AD",
		(CommandHandler)receive_update,"receive_update",NULL,DAEMON);
	daemonCore->Register_Command(UPDATE_AD_GENERIC, "UPDATE_AD_GENERIC",
		(CommandHandler)receive_update,"receive_update", NULL, DAEMON);
    daemonCore->Register_Command(UPDATE_GRID_AD,"UPDATE_GRID_AD",
		(CommandHandler)receive_update,"receive_update",NULL,DAEMON);

        // // // // // // // // // // // // // // // // // // // // //
        // WARNING!!!! If you add other update commands here, you
        // also need to add them to the switch statement in the
        // sockCacheHandler() method!!!
		// // // // // // // // // // // // // // // // // // // // //

    // install command handlers for updates with acknowledgement

    daemonCore->Register_Command(
		UPDATE_STARTD_AD_WITH_ACK,
		"UPDATE_STARTD_AD_WITH_ACK",
		(CommandHandler)receive_update_expect_ack,
		"receive_update_expect_ack",NULL,ADVERTISE_STARTD_PERM);

#if ( HAVE_HIBERNATION )
    // add all persisted ads back into the collector's store
    // process the given command
    int     insert = -3;
    ClassAd *ad;
    offline_plugin_.rewind ();
    while ( offline_plugin_.iterate ( ad ) ) {
		ad = new ClassAd(*ad);
	    if ( !collector.collect ( UPDATE_STARTD_AD, ad, NULL, insert ) ) {
		    
            if ( -3 == insert ) {

                /* this happens when we get a classad for which a hash 
                key could not been made. This occurs when certain 
                attributes are needed for the particular category the
                ad is destined for, but they are not present in the 
                ad itself. */
			    dprintf (
                    D_ALWAYS,
				    "Received malformed ad. Ignoring.\n" );

	        }
			delete ad;
	    }

    }
#endif

	forkQuery.Initialize( );
}

int CollectorDaemon::receive_query_cedar(Service* /*s*/,
										 int command,
										 Stream* sock)
{
	ClassAd cad;

	sock->decode();
	sock->timeout(ClientTimeout);
	bool ep = CondorThreads::enable_parallel(true);
	bool res = !cad.initFromStream(*sock) || !sock->eom();
	CondorThreads::enable_parallel(ep);
    if( res )
    {
        dprintf(D_ALWAYS,"Failed to receive query on TCP: aborting\n");
        return FALSE;
    }

		// here we set up a network timeout of a longer duration
	sock->timeout(QueryTimeout);

	// Initial query handler
	AdTypes whichAds = receive_query_public( command );

	// CRUFT: Before 7.3.2, submitter ads had a MyType of
	//   "Scheduler". The only way to tell the difference
	//   was that submitter ads didn't have ATTR_NUM_USERS.
	//   The correosponding query ads had a TargetType of
	//   "Scheduler", which we now coerce to "Submitter".
	if ( whichAds == SUBMITTOR_AD ) {
		cad.SetTargetTypeName( SUBMITTER_ADTYPE );
	}

	// Perform the query
	List<ClassAd> results;
	ForkStatus	fork_status = FORK_FAILED;
	int	   		return_status = 0;
    if (whichAds != (AdTypes) -1) {
		fork_status = forkQuery.NewJob( );
		if ( FORK_PARENT == fork_status ) {
			return 1;
		} else {
			// Child / Fork failed / busy
			process_query_public (whichAds, &cad, &results);
		}
	}

	// send the results via cedar
	sock->encode();
	results.Rewind();
	ClassAd *curr_ad = NULL;
	int more = 1;
	
		// See if query ad asks for server-side projection
	char *projection = NULL;
	cad.LookupString("projection", &projection);
	SimpleList<MyString> projectionList;
	::split_args(projection, &projectionList);

	while ( (curr_ad=results.Next()) )
    {
		ClassAd *ad_to_send = NULL;
		ClassAd shortAd;

		if (projectionList.Number() > 0) {
			// compute projection, send thin ad
			computeProjection(&shortAd, curr_ad, &projectionList);
			ad_to_send = &shortAd;
		} else {
			// if no projection, send the full ad
			ad_to_send = curr_ad;
		}
		
        if (!sock->code(more) || !ad_to_send->put(*sock))
        {
            dprintf (D_ALWAYS,
                    "Error sending query result to client -- aborting\n");
            return_status = 0;
			goto END;
        }
    }

	// end of query response ...
	more = 0;
	if (!sock->code(more))
	{
		dprintf (D_ALWAYS, "Error sending EndOfResponse (0) to client\n");
	}

	// flush the output
	if (!sock->end_of_message())
	{
		dprintf (D_ALWAYS, "Error flushing CEDAR socket\n");
	}
	return_status = 1;


    // all done; let daemon core will clean up connection
  END:
	if ( FORK_CHILD == fork_status ) {
		forkQuery.WorkerDone( );		// Never returns
	}
	return return_status;
}

AdTypes
CollectorDaemon::receive_query_public( int command )
{
	AdTypes whichAds;

    switch (command)
    {
	  case QUERY_STARTD_ADS:
		dprintf (D_ALWAYS, "Got QUERY_STARTD_ADS\n");
		whichAds = STARTD_AD;
		break;
		
	  case QUERY_SCHEDD_ADS:
		dprintf (D_ALWAYS, "Got QUERY_SCHEDD_ADS\n");
		whichAds = SCHEDD_AD;
		break;

#ifdef WANT_QUILL
	  case QUERY_QUILL_ADS:
		dprintf (D_ALWAYS, "Got QUERY_QUILL_ADS\n");
		whichAds = QUILL_AD;
		break;
#endif /* WANT_QUILL */
		
	  case QUERY_SUBMITTOR_ADS:
		dprintf (D_ALWAYS, "Got QUERY_SUBMITTOR_ADS\n");
		whichAds = SUBMITTOR_AD;
		break;

	  case QUERY_LICENSE_ADS:
		dprintf (D_ALWAYS, "Got QUERY_LICENSE_ADS\n");
		whichAds = LICENSE_AD;
		break;

	  case QUERY_MASTER_ADS:
		dprintf (D_ALWAYS, "Got QUERY_MASTER_ADS\n");
		whichAds = MASTER_AD;
		break;
		
	  case QUERY_CKPT_SRVR_ADS:
		dprintf (D_ALWAYS, "Got QUERY_CKPT_SRVR_ADS\n");
		whichAds = CKPT_SRVR_AD;	
		break;
		
	  case QUERY_STARTD_PVT_ADS:
		dprintf (D_ALWAYS, "Got QUERY_STARTD_PVT_ADS\n");
		whichAds = STARTD_PVT_AD;
		break;

	  case QUERY_COLLECTOR_ADS:
		dprintf (D_FULLDEBUG,"Got QUERY_COLLECTOR_ADS\n");
		whichAds = COLLECTOR_AD;
		break;

	  case QUERY_STORAGE_ADS:
		dprintf (D_FULLDEBUG,"Got QUERY_STORAGE_ADS\n");
		whichAds = STORAGE_AD;
		break;

	  case QUERY_NEGOTIATOR_ADS:
		dprintf (D_FULLDEBUG,"Got QUERY_NEGOTIATOR_ADS\n");
		whichAds = NEGOTIATOR_AD;
		break;

	  case QUERY_HAD_ADS:
		dprintf (D_FULLDEBUG,"Got QUERY_HAD_ADS\n");
		whichAds = HAD_AD;
		break;

	  case QUERY_XFER_SERVICE_ADS:
		dprintf (D_FULLDEBUG,"Got QUERY_XFER_SERVICE_ADS\n");
		whichAds = XFER_SERVICE_AD;
		break;

	  case QUERY_LEASE_MANAGER_ADS:
		dprintf (D_FULLDEBUG,"Got QUERY_LEASE_MANAGER_ADS\n");
		whichAds = LEASE_MANAGER_AD;
		break;

	  case QUERY_GENERIC_ADS:
		dprintf (D_FULLDEBUG,"Got QUERY_GENERIC_ADS\n");
		whichAds = GENERIC_AD;
		break;

	  case QUERY_ANY_ADS:
		dprintf (D_FULLDEBUG,"Got QUERY_ANY_ADS\n");
		whichAds = ANY_AD;
		break;
      
      case QUERY_GRID_ADS:
        dprintf (D_FULLDEBUG,"Got QUERY_GRID_ADS\n");
        whichAds = GRID_AD;
		break;

	  default:
		dprintf(D_ALWAYS,
				"Unknown command %d in receive_query_public()\n",
				command);
		whichAds = (AdTypes) -1;
    }

	return whichAds;
}

int CollectorDaemon::receive_invalidation(Service* /*s*/,
										  int command,
										  Stream* sock)
{
	AdTypes whichAds;
	ClassAd cad;

	sock->decode();
	sock->timeout(ClientTimeout);
    if( !cad.initFromStream(*sock) || !sock->eom() )
    {
        dprintf( D_ALWAYS,
				 "Failed to receive invalidation on %s: aborting\n",
				 sock->type() == Stream::reli_sock ? "TCP" : "UDP" );
        return FALSE;
    }

    // cancel timeout --- collector engine sets up its own timeout for
    // collecting further information
    sock->timeout(0);

    switch (command)
    {
	  case INVALIDATE_STARTD_ADS:
		dprintf (D_ALWAYS, "Got INVALIDATE_STARTD_ADS\n");
		whichAds = STARTD_AD;
		break;
		
	  case INVALIDATE_SCHEDD_ADS:
		dprintf (D_ALWAYS, "Got INVALIDATE_SCHEDD_ADS\n");
		whichAds = SCHEDD_AD;
		break;

#ifdef WANT_QUILL
	  case INVALIDATE_QUILL_ADS:
		dprintf (D_ALWAYS, "Got INVALIDATE_QUILL_ADS\n");
		whichAds = QUILL_AD;
		break;
#endif /* WANT_QUILL */
		
	  case INVALIDATE_SUBMITTOR_ADS:
		dprintf (D_ALWAYS, "Got INVALIDATE_SUBMITTOR_ADS\n");
		whichAds = SUBMITTOR_AD;
		break;

	  case INVALIDATE_LICENSE_ADS:
		dprintf (D_ALWAYS, "Got INVALIDATE_LICENSE_ADS\n");
		whichAds = LICENSE_AD;
		break;

	  case INVALIDATE_MASTER_ADS:
		dprintf (D_ALWAYS, "Got INVALIDATE_MASTER_ADS\n");
		whichAds = MASTER_AD;
		break;
		
	  case INVALIDATE_CKPT_SRVR_ADS:
		dprintf (D_ALWAYS, "Got INVALIDATE_CKPT_SRVR_ADS\n");
		whichAds = CKPT_SRVR_AD;	
		break;
		
	  case INVALIDATE_COLLECTOR_ADS:
		dprintf (D_ALWAYS, "Got INVALIDATE_COLLECTOR_ADS\n");
		whichAds = COLLECTOR_AD;
		break;

	  case INVALIDATE_NEGOTIATOR_ADS:
		dprintf (D_ALWAYS, "Got INVALIDATE_NEGOTIATOR_ADS\n");
		whichAds = NEGOTIATOR_AD;
		break;

	  case INVALIDATE_HAD_ADS:
		dprintf (D_ALWAYS, "Got INVALIDATE_HAD_ADS\n");
		whichAds = HAD_AD;
		break;

	  case INVALIDATE_XFER_SERVICE_ADS:
		dprintf (D_ALWAYS, "Got INVALIDATE_XFER_SERVICE_ADS\n");
		whichAds = XFER_SERVICE_AD;
		break;

	  case INVALIDATE_LEASE_MANAGER_ADS:
		dprintf (D_ALWAYS, "Got INVALIDATE_LEASE_MANAGER_ADS\n");
		whichAds = LEASE_MANAGER_AD;
		break;

	  case INVALIDATE_STORAGE_ADS:
		dprintf (D_ALWAYS, "Got INVALIDATE_STORAGE_ADS\n");
		whichAds = STORAGE_AD;
		break;

	  case INVALIDATE_ADS_GENERIC:
		dprintf(D_ALWAYS, "Got INVALIDATE_ADS_GENERIC\n");
		whichAds = GENERIC_AD;
		break;

      case INVALIDATE_GRID_ADS:
        dprintf(D_ALWAYS, "Got INVALIDATE_GRID_ADS\n");
        whichAds = GRID_AD;
		break;

	  default:
		dprintf(D_ALWAYS,"Unknown command %d in receive_invalidation()\n",
			command);
		whichAds = (AdTypes) -1;
    }

    if (whichAds != (AdTypes) -1)
		process_invalidation (whichAds, cad, sock);

	// if the invalidation was for the STARTD ads, also invalidate startd
	// private ads with the same query ad
	if (command == INVALIDATE_STARTD_ADS)
		process_invalidation (STARTD_PVT_AD, cad, sock);

#if ( HAVE_HIBERNATION )
    /* let the off-line plug-in invalidate the given ad */
    offline_plugin_.invalidate ( command, cad );
#endif

#if HAVE_DLOPEN
	CollectorPluginManager::Invalidate(command, cad);
#endif

	if(View_Collector && ((command == INVALIDATE_STARTD_ADS) ||
		(command == INVALIDATE_SUBMITTOR_ADS)) ) {
		send_classad_to_sock(command, View_Collector, &cad);
	}	

	if( sock_cache && sock->type() == Stream::reli_sock ) {
			// if this is a TCP update and we've got a cache, stash
			// this socket for future updates...
		return stashSocket( sock );
	}

    // all done; let daemon core will clean up connection
	return TRUE;
}


int CollectorDaemon::receive_update(Service* /*s*/, int command, Stream* sock)
{
    int	insert;
	sockaddr_in *from;
	ClassAd *cad;

	/* assume the ad is malformed... other functions set this value */
	insert = -3;

  		// unless the collector has been configured to use a socket
  		// cache for TCP updates, refuse any update commands that come
  		// in via TCP...
	if( ! sock_cache && sock->type() == Stream::reli_sock ) {
		// update via tcp; sorry buddy, use udp or you're outa here!
		dprintf(D_ALWAYS,"Received UPDATE command via TCP; ignored\n");
		// let daemon core clean up the socket
		return TRUE;
	}

	// get endpoint
	from = ((Sock*)sock)->peer_addr();

    // process the given command
	if (!(cad = collector.collect (command,(Sock*)sock,from,insert)))
	{
		if (insert == -2)
		{
			// this should never happen assuming we never register QUERY
			// commands with daemon core, but it cannot hurt to check...
			dprintf (D_ALWAYS,"Got QUERY command (%d); not supported for UDP\n",
						command);
		}

		if (insert == -3)
		{
			/* this happens when we get a classad for which a hash key could
				not been made. This occurs when certain attributes are needed
				for the particular catagory the ad is destined for, but they
				are not present in the ad. */
			dprintf (D_ALWAYS,
				"Received malformed ad from command (%d). Ignoring.\n",
				command);
		}

		return FALSE;

	}

#if ( HAVE_HIBERNATION )
	/* let the off-line plug-in have at it */
	offline_plugin_.update ( command, *cad );
#endif

#if HAVE_DLOPEN
	CollectorPluginManager::Update(command, *cad);
#endif

	if(View_Collector && ((command == UPDATE_STARTD_AD) ||
			(command == UPDATE_SUBMITTOR_AD)) ) {
		send_classad_to_sock(command, View_Collector, cad);
	}	

	if( sock_cache && sock->type() == Stream::reli_sock ) {
			// if this is a TCP update and we've got a cache, stash
			// this socket for future updates...
		return stashSocket( sock );
	}

	// let daemon core clean up the socket
	return TRUE;
}

int CollectorDaemon::receive_update_expect_ack( Service* /*s*/,
												int command,
												Stream *stream )
{

    if ( NULL == stream ) {
        return FALSE;
    }

    Sock        *socket = (Sock*) stream;
    ClassAd     *updateAd = new ClassAd;
    const int   timeout = 5;
    int         ok      = 1;
    
    socket->decode ();
    socket->timeout ( timeout );
    
    if ( !updateAd->initFromStream ( *socket ) ) {

        dprintf ( 
            D_ALWAYS,
            "receive_update_expect_ack: "
            "Failed to read class ad off the wire, aborting\n" );

        return FALSE;

    }

    /* assume the ad is malformed */
    int insert = -3;
    
    /* get peer's IP/port */
    sockaddr_in *from = socket->peer_addr();

    /* "collect" the ad */
    ClassAd *cad = collector.collect ( 
        command,
        updateAd,
        from,
        insert );

    if ( !cad ) {

        /* attempting to "collect" a QUERY or INVALIDATE command?!? */
        if ( -2 == insert ) {

	        dprintf (
                D_ALWAYS,
                "receive_update_expect_ack: "
                "Got QUERY or INVALIDATE command (%d); these are "
                "not supported.\n",
                command );

        }

        /* this happens when we get a classad for which a hash key 
        could not been made. This occurs when certain attributes are 
        needed for the particular catagory the ad is destined for, 
        but they are not present in the ad. */
	    if ( -3 == insert ) {
			
	        dprintf (
                D_ALWAYS,
                "receive_update_expect_ack: "
		        "Received malformed ad from command (%d).\n",
                command );

	    }

    } else {

        socket->encode ();
        socket->timeout ( timeout );

        /* send an acknowledgment that we received the ad */
        if ( !socket->code ( ok ) ) {
        
            dprintf ( 
                D_ALWAYS,
                "receive_update_expect_ack: "
                "Failed to send acknowledgement to host %s, "
                "aborting\n",
                socket->peer_ip_str () );
        
            /* it's ok if we fail here, since we won't drop the ad,
            it's only on the client side that any error should be
            treated as fatal */

        }

        if ( !socket->eom () ) {
        
            dprintf ( 
                D_FULLDEBUG, 
                "receive_update_expect_ack: "
                "Failed to send update EOM to host %s.\n", 
                socket->peer_ip_str () );
            
	    }   
        
    }

#if ( HAVE_HIBERNATION )
    /* let the off-line plug-in have at it */
    offline_plugin_.update ( command, *cad );
#endif

#if HAVE_DLOPEN
    CollectorPluginManager::Update ( command, *cad );
#endif

    if( View_Collector && UPDATE_STARTD_AD_WITH_ACK == command ) {
		send_classad_to_sock ( command, View_Collector, cad );
	}

	// let daemon core clean up the socket
	return TRUE;
}


int
CollectorDaemon::stashSocket( Stream* sock )
{
		
	ReliSock* rsock;
	char* addr = sin_to_string( ((Sock*)sock)->peer_addr() );
	rsock = sock_cache->findReliSock( addr );
	if( ! rsock ) {
			// don't have it in the socket already, see if the cache
			// is full.  if not, add this socket to the cache so we
			// can reuse it for future updates.  if we're full, we're
			// going to have to screw this connection and not cache
			// it, to allow the cache to be useful for the other
			// daemons.
		if( sock_cache->isFull() ) {
			dprintf( D_ALWAYS, "WARNING: socket cache (size: %d) "
					 "is full - NOT caching TCP updates from %s\n",
					 sock_cache->size(), addr );
			return TRUE;
		}
		sock_cache->addReliSock( addr, (ReliSock*)sock );

			// now that it's in our socket, we want to register this
			// socket w/ DaemonCore so we wake up if there's more data
			// to read...
		daemonCore->Register_Socket( sock, "TCP Cached Socket",
									 (SocketHandler)sockCacheHandler,
									 "sockCacheHandler", NULL, DAEMON );
	}

		// if we're here, it means the sock is in the cache (either
		// because it was there already, or because we just added it).
		// either, way, we don't want daemonCore to mess with the
		// socket...
	return KEEP_STREAM;
}


int
CollectorDaemon::sockCacheHandler( Service*, Stream* sock )
{
	int cmd;
	char* addr = sin_to_string( ((Sock*)sock)->peer_addr() );
	sock->decode();
	dprintf( D_FULLDEBUG, "Activity on stashed TCP socket from %s\n",
			 addr );

	sock->timeout(20);

	if( ! sock->code(cmd) ) {
			// can't read an int, the other side probably closed the
			// socket, which is why select() woke up.
		dprintf( D_FULLDEBUG,
				 "Socket has been closed, removing from cache\n" );
		daemonCore->Cancel_Socket( sock );
		sock_cache->invalidateSock( addr );
		return KEEP_STREAM;
	}

	switch( cmd ) {
#ifdef WANT_QUILL
	case UPDATE_QUILL_AD:
#endif /* WANT_QUILL */
	case UPDATE_STARTD_AD:
	case UPDATE_SCHEDD_AD:
	case UPDATE_MASTER_AD:
	case UPDATE_GATEWAY_AD:
	case UPDATE_CKPT_SRVR_AD:
	case UPDATE_SUBMITTOR_AD:
	case UPDATE_COLLECTOR_AD:
	case UPDATE_NEGOTIATOR_AD:
	case UPDATE_HAD_AD:
	case UPDATE_XFER_SERVICE_AD:
	case UPDATE_LEASE_MANAGER_AD:
	case UPDATE_LICENSE_AD:
	case UPDATE_STORAGE_AD:
	case UPDATE_AD_GENERIC:
    case UPDATE_GRID_AD:
		return receive_update( NULL, cmd, sock );
		break;

    case UPDATE_STARTD_AD_WITH_ACK:
        return receive_update_expect_ack ( NULL, cmd, sock );

#ifdef WANT_QUILL
	case INVALIDATE_QUILL_ADS:
#endif /* WANT_QUILL */
	case INVALIDATE_STARTD_ADS:
	case INVALIDATE_SCHEDD_ADS:
	case INVALIDATE_MASTER_ADS:
	case INVALIDATE_GATEWAY_ADS:
	case INVALIDATE_CKPT_SRVR_ADS:
	case INVALIDATE_SUBMITTOR_ADS:
	case INVALIDATE_COLLECTOR_ADS:
	case INVALIDATE_NEGOTIATOR_ADS:
	case INVALIDATE_HAD_ADS:
	case INVALIDATE_XFER_SERVICE_ADS:
	case INVALIDATE_LEASE_MANAGER_ADS:
	case INVALIDATE_LICENSE_ADS:
	case INVALIDATE_STORAGE_ADS:
    case INVALIDATE_GRID_ADS:
	case INVALIDATE_ADS_GENERIC:
		return receive_invalidation( NULL, cmd, sock );
		break;

	default:
		dprintf( D_ALWAYS,
				 "ERROR: invalid command %d on stashed TCP socket\n", cmd );
		daemonCore->Cancel_Socket( sock );
		sock_cache->invalidateSock( addr );
		return KEEP_STREAM;
		break;
    }
	EXCEPT( "Should never reach here" );
	return FALSE;
}


int CollectorDaemon::query_scanFunc (ClassAd *cad)
{
    if ((*cad) >= (*__query__))
    {
		// Found a match 
        __numAds__++;
		__ClassAdResultList__->Append(cad);
    }

    return 1;
}

/*
Examine the given ad, and see if it satisfies the query.
If so, return zero, causing the scan to stop.
Otherwise, return 1.
*/

int CollectorDaemon::select_by_match( ClassAd *cad )
{
	if( query_any_request <= *cad ) {
		query_any_result = cad;
		return 0;
	}
	return 1;
}

void CollectorDaemon::process_query_public (AdTypes whichAds,
											ClassAd *query,
											List<ClassAd>* results)
{
	// set up for hashtable scan
	__query__ = query;
	__numAds__ = 0;
	__ClassAdResultList__ = results;

	if (!collector.walkHashTable (whichAds, query_scanFunc))
	{
		dprintf (D_ALWAYS, "Error sending query response\n");
	}


	dprintf (D_ALWAYS, "(Sending %d ads in response to query)\n", __numAds__);
}	

int CollectorDaemon::invalidation_scanFunc (ClassAd *cad)
{
	static char buffer[64];
	
	sprintf( buffer, "%s = 0", ATTR_LAST_HEARD_FROM );

    if ((*cad) >= (*__query__))
    {
		cad->Insert( buffer );			
        __numAds__++;
    }

    return 1;
}

void CollectorDaemon::process_invalidation (AdTypes whichAds, ClassAd &query, Stream *sock)
{
	// here we set up a network timeout of a longer duration
	sock->timeout(QueryTimeout);

	// set up for hashtable scan
	__query__ = &query;
	__numAds__ = 0;

	// first set all the "LastHeardFrom" attributes to low values ...
	collector.walkHashTable (whichAds, invalidation_scanFunc);

	// ... then invoke the housekeeper
	collector.invokeHousekeeper (whichAds);

	dprintf (D_ALWAYS, "(Invalidated %d ads)\n", __numAds__);

		// Suppose lots of ads are getting invalidated and we have no clue
		// why.  That is what the following block of code tries to solve.
	if( __numAds__ > 1 ) {
		dprintf(D_ALWAYS, "The invalidation query was this:\n");
		query.dPrint(D_ALWAYS);
	}
}	



int CollectorDaemon::reportStartdScanFunc( ClassAd *cad )
{
	return normalTotals->update( cad );
}

int CollectorDaemon::reportSubmittorScanFunc( ClassAd *cad )
{
	int tmp1, tmp2;
	if( !cad->LookupInteger( ATTR_RUNNING_JOBS , tmp1 ) ||
		!cad->LookupInteger( ATTR_IDLE_JOBS, tmp2 ) )
			return 0;
	submittorRunningJobs += tmp1;
	submittorIdleJobs	 += tmp2;

	return 1;
}

int CollectorDaemon::reportMiniStartdScanFunc( ClassAd *cad )
{
    char buf[80];

    if ( !cad->LookupString( ATTR_STATE, buf ) )
        return 0;
    machinesTotal++;
    switch ( buf[0] ) {
        case 'C':
            machinesClaimed++;
            break;
        case 'U':
            machinesUnclaimed++;
            break;
        case 'O':
            machinesOwner++;
            break;
    }

	// Count the number of jobs in each universe
	int		universe;
	if ( cad->LookupInteger( ATTR_JOB_UNIVERSE, universe ) ) {
		ustatsAccum.accumulate( universe );
	}

	// Done
    return 1;
}

void CollectorDaemon::reportToDevelopers (void)
{
	char	buffer[128];
	FILE	*mailer;
	TrackTotals	totals( PP_STARTD_NORMAL );

    // compute machine information
    machinesTotal = 0;
    machinesUnclaimed = 0;
    machinesClaimed = 0;
    machinesOwner = 0;
	ustatsAccum.Reset( );

    if (!collector.walkHashTable (STARTD_AD, reportMiniStartdScanFunc)) {
            dprintf (D_ALWAYS, "Error counting machines in devel report \n");
    }

    // If we don't have any machines reporting to us, bail out early
    if(machinesTotal == 0) 	
        return;

	if( ( normalTotals = new TrackTotals( PP_STARTD_NORMAL ) ) == NULL ) {
		dprintf( D_ALWAYS, "Didn't send monthly report (failed totals)\n" );
		return;
	}

	// Accumulate our monthly maxes
	ustatsMonthly.setMax( ustatsAccum );

	sprintf( buffer, "Collector (%s):  Monthly report",
			 my_full_hostname() );
	if( ( mailer = email_developers_open(buffer) ) == NULL ) {
		dprintf (D_ALWAYS, "Didn't send monthly report (couldn't open mailer)\n");		
		return;
	}

	fprintf( mailer , "This Collector has the following IDs:\n");
	fprintf( mailer , "    %s\n", CondorVersion() );
	fprintf( mailer , "    %s\n\n", CondorPlatform() );

	normalTotals = &totals;
	if (!collector.walkHashTable (STARTD_AD, reportStartdScanFunc)) {
		dprintf (D_ALWAYS, "Error making monthly report (startd scan) \n");
	}
		
	// output totals summary to the mailer
	totals.displayTotals( mailer, 20 );

	// now output information about submitted jobs
	submittorRunningJobs = 0;
	submittorIdleJobs = 0;
	if( !collector.walkHashTable( SUBMITTOR_AD, reportSubmittorScanFunc ) ) {
		dprintf( D_ALWAYS, "Error making monthly report (submittor scan)\n" );
	}
	fprintf( mailer , "%20s\t%20s\n" , ATTR_RUNNING_JOBS , ATTR_IDLE_JOBS );
	fprintf( mailer , "%20d\t%20d\n" , submittorRunningJobs,submittorIdleJobs );

	// If we've got any, find the maxes
	if ( ustatsMonthly.getCount( ) ) {
		fprintf( mailer , "\n%20s\t%20s\n" , "Universe", "Max Running Jobs" );
		int		univ;
		for( univ=0;  univ<CONDOR_UNIVERSE_MAX;  univ++) {
			const char	*name = ustatsMonthly.getName( univ );
			if ( name ) {
				fprintf( mailer, "%20s\t%20d\n",
						 name, ustatsMonthly.getValue(univ) );
			}
		}
		fprintf( mailer, "%20s\t%20d\n",
				 "All", ustatsMonthly.getCount( ) );
	}
	ustatsMonthly.Reset( );
	
	email_close( mailer );
	return;
}
	
void CollectorDaemon::Config()
{
	dprintf(D_ALWAYS, "In CollectorDaemon::Config()\n");

    char	*tmp;
    int     ClassadLifetime;

    ClientTimeout = param_integer ("CLIENT_TIMEOUT",30);
    QueryTimeout = param_integer ("QUERY_TIMEOUT",60);
    ClassadLifetime = param_integer ("CLASSAD_LIFETIME",900);

    if (CollectorName) free (CollectorName);
    CollectorName = param("COLLECTOR_NAME");

	// handle params for Collector updates
	if ( UpdateTimerId >= 0 ) {
		daemonCore->Cancel_Timer(UpdateTimerId);
		UpdateTimerId = -1;
	}

	if( updateCollectors ) {
		delete updateCollectors;
		updateCollectors = NULL;
	}
	updateCollectors = CollectorList::create( NULL );

	tmp = param ("CONDOR_DEVELOPERS_COLLECTOR");
	if (tmp == NULL) {
		tmp = strdup("condor.cs.wisc.edu");
	}
	if (stricmp(tmp,"NONE") == 0 ) {
		free(tmp);
		tmp = NULL;
	}

	if( updateRemoteCollector ) {
		// we should just delete it.  since we never use TCP
		// for these updates, we don't really loose anything
		// by destroying the object and recreating it...
		delete updateRemoteCollector;
		updateRemoteCollector = NULL;
	}
	if ( tmp ) {
		updateRemoteCollector = new DCCollector( tmp, DCCollector::UDP );
	}

	free( tmp );
	
	int i = param_integer("COLLECTOR_UPDATE_INTERVAL",900); // default 15 min
	if( UpdateTimerId < 0 ) {
		UpdateTimerId = daemonCore->
			Register_Timer( 1, i, (TimerHandler)sendCollectorAd,
							"sendCollectorAd" );
	}

	tmp = param(COLLECTOR_REQUIREMENTS);
	MyString collector_req_err;
	if( !collector.setCollectorRequirements( tmp, collector_req_err ) ) {
		EXCEPT("Handling of '%s=%s' failed: %s\n",
			   COLLECTOR_REQUIREMENTS,
			   tmp ? tmp : "(null)",
			   collector_req_err.Value());
	}
	if( tmp ) {
		free( tmp );
		tmp = NULL;
	}

	init_classad(i);

    // set the appropriate parameters in the collector engine
    collector.setClientTimeout( ClientTimeout );
    collector.scheduleHousekeeper( ClassadLifetime );

#if ( HAVE_HIBERNATION )
    offline_plugin_.configure ();
#endif

    // if we're not the View Collector, let's set something up to forward
    // all of our ads to the view collector.
    if(View_Collector) {
        delete View_Collector;
    }

    if(view_sock) {
        delete view_sock;
    }	

    tmp = param("CONDOR_VIEW_HOST");
    if(tmp) {
       View_Collector = new DCCollector( tmp );
       Sinful view_addr( View_Collector->addr() );
	   Sinful my_addr( daemonCore->publicNetworkIpAddr() );

       if( my_addr.addressPointsToMe( view_addr ) )
       {
       	     // Do not forward to myself.
          dprintf(D_ALWAYS, "Not forwarding to View Server %s, because that's me!\n", tmp);
          delete View_Collector;
          View_Collector = NULL;
       }
       else {
          dprintf(D_ALWAYS, "Will forward ads on to View Server %s\n", tmp);
       }
       free(tmp);
       if(View_Collector) {
           view_sock = View_Collector->safeSock();
       }
    }

		// the upper bound here is because a TCP port can't be any
		// bigger than 64K (65536).  however, b/c of reserved ports
		// and some other things, we leave it at 64000, just to be
		// safe...
	int size = param_integer( "COLLECTOR_SOCKET_CACHE_SIZE",-1,0,64000 );
	if( size == -1 ) {
		delete sock_cache;
		sock_cache = NULL;
	}
	else {
		if( sock_cache ) {
			if( size > sock_cache->size() ) {
				sock_cache->resize( size );
			}
		} else {
			sock_cache = new SocketCache( size );
		}
	}
	if( sock_cache ) {
		dprintf( D_FULLDEBUG,
				 "Using a SocketCache for TCP updates (size: %d)\n",
				 sock_cache->size() );
	} else {
		dprintf( D_FULLDEBUG, "No SocketCache, will refuse TCP updates\n" );
	}		

	size = param_integer ("COLLECTOR_CLASS_HISTORY_SIZE",1024);
	collectorStats.setClassHistorySize( size );

	bool collector_daemon_stats = param_boolean ("COLLECTOR_DAEMON_STATS",true);
	collectorStats.setDaemonStats( collector_daemon_stats );

    size = param_integer ("COLLECTOR_DAEMON_HISTORY_SIZE",128);
    collectorStats.setDaemonHistorySize( size );

	time_t garbage_interval = param_integer( "COLLECTOR_STATS_SWEEP", DEFAULT_COLLECTOR_STATS_GARBAGE_INTERVAL );
	collectorStats.setGarbageCollectionInterval( garbage_interval );

    size = param_integer ("COLLECTOR_QUERY_WORKERS", 2);
    forkQuery.setMaxWorkers( size );

	bool ccb_server_enabled = param_boolean("ENABLE_CCB_SERVER",true);
	if( ccb_server_enabled ) {
		if( !m_ccb_server ) {
			dprintf(D_ALWAYS, "Enabling CCB Server.\n");
			m_ccb_server = new CCBServer;
		}
		m_ccb_server->InitAndReconfig();
	}
	else if( m_ccb_server ) {
		dprintf(D_ALWAYS, "Disabling CCB Server.\n");
		delete m_ccb_server;
		m_ccb_server = NULL;
	}

    return;
}

void CollectorDaemon::Exit()
{
	// Clean up any workers that have exited but haven't been reaped yet.
	// This can occur if the collector receives a query followed
	// immediately by a shutdown command.  The worker will exit but
	// not be reaped because the SIGTERM from the shutdown command will
	// be processed before the SIGCHLD from the worker process exit.
	// Allowing the stack to clean up worker processes is problematic
	// because the collector will be shutdown and the daemonCore
	// object deleted by the time the worker cleanup is attempted.
	forkQuery.DeleteAll( );
	if ( UpdateTimerId >= 0 ) {
		daemonCore->Cancel_Timer(UpdateTimerId);
		UpdateTimerId = -1;
	}
	return;
}

void CollectorDaemon::Shutdown()
{
	// Clean up any workers that have exited but haven't been reaped yet.
	// This can occur if the collector receives a query followed
	// immediately by a shutdown command.  The worker will exit but
	// not be reaped because the SIGTERM from the shutdown command will
	// be processed before the SIGCHLD from the worker process exit.
	// Allowing the stack to clean up worker processes is problematic
	// because the collector will be shutdown and the daemonCore
	// object deleted by the time the worker cleanup is attempted.
	forkQuery.DeleteAll( );
	if ( UpdateTimerId >= 0 ) {
		daemonCore->Cancel_Timer(UpdateTimerId);
		UpdateTimerId = -1;
	}
	return;
}

int CollectorDaemon::sendCollectorAd()
{
    // compute submitted jobs information
    submittorRunningJobs = 0;
    submittorIdleJobs = 0;
    if( !collector.walkHashTable( SUBMITTOR_AD, reportSubmittorScanFunc ) ) {
         dprintf( D_ALWAYS, "Error making collector ad (submittor scan)\n" );
    }

    // compute machine information
    machinesTotal = 0;
    machinesUnclaimed = 0;
    machinesClaimed = 0;
    machinesOwner = 0;
	ustatsAccum.Reset( );
    if (!collector.walkHashTable (STARTD_AD, reportMiniStartdScanFunc)) {
            dprintf (D_ALWAYS, "Error making collector ad (startd scan) \n");
    }

    // insert values into the ad
    char line[100];
    sprintf(line,"%s = %d",ATTR_RUNNING_JOBS,submittorRunningJobs);
    ad->Insert(line);
    sprintf(line,"%s = %d",ATTR_IDLE_JOBS,submittorIdleJobs);
    ad->Insert(line);
    sprintf(line,"%s = %d",ATTR_NUM_HOSTS_TOTAL,machinesTotal);
    ad->Insert(line);
    sprintf(line,"%s = %d",ATTR_NUM_HOSTS_CLAIMED,machinesClaimed);
    ad->Insert(line);
    sprintf(line,"%s = %d",ATTR_NUM_HOSTS_UNCLAIMED,machinesUnclaimed);
    ad->Insert(line);
    sprintf(line,"%s = %d",ATTR_NUM_HOSTS_OWNER,machinesOwner);
    ad->Insert(line);

	// Accumulate for the monthly
	ustatsMonthly.setMax( ustatsAccum );

	// If we've got any universe reports, find the maxes
	ustatsAccum.publish( ATTR_CURRENT_JOBS_RUNNING, ad );
	ustatsMonthly.publish( ATTR_MAX_JOBS_RUNNING, ad );

	// Collector engine stats, too
	collectorStats.publishGlobal( ad );

	// Send the ad
	int num_updated = updateCollectors->sendUpdates(UPDATE_COLLECTOR_AD, ad, NULL, false);
	if ( num_updated != updateCollectors->number() ) {
		dprintf( D_ALWAYS, "Unable to send UPDATE_COLLECTOR_AD to all configured collectors\n");
	}

       // If we don't have any machines, then bail out. You oftentimes
       // see people run a collector on each macnine in their pool. Duh.
	if(machinesTotal == 0) {
		return 1;
	}
	if ( updateRemoteCollector ) {
		char *update_addr = updateRemoteCollector->addr();
		if (!update_addr) update_addr = "(null)";
		if( ! updateRemoteCollector->sendUpdate(UPDATE_COLLECTOR_AD, ad, NULL, false) ) {
			dprintf( D_ALWAYS, "Can't send UPDATE_COLLECTOR_AD to collector "
					 "(%s): %s\n", update_addr,
					 updateRemoteCollector->error() );
			return 0;
		}
	}
	return 1;
}

void CollectorDaemon::init_classad(int interval)
{
    if( ad ) delete( ad );
    ad = new ClassAd();

    ad->SetMyTypeName(COLLECTOR_ADTYPE);
    ad->SetTargetTypeName("");

    char *tmp;
    tmp = param( "CONDOR_ADMIN" );
    if( tmp ) {
        ad->Assign( ATTR_CONDOR_ADMIN, tmp );
        free( tmp );
    }

    MyString id;
    if( CollectorName ) {
            if( strchr( CollectorName, '@' ) ) {
               id.sprintf( "%s", CollectorName );
            } else {
               id.sprintf( "%s@%s", CollectorName, my_full_hostname() );
            }
    } else {
            id.sprintf( "%s", my_full_hostname() );
    }
    ad->Assign( ATTR_NAME, id.Value() );

    ad->Assign( ATTR_COLLECTOR_IP_ADDR, global_dc_sinful() );

    if ( interval > 0 ) {
            ad->Assign( ATTR_UPDATE_INTERVAL, 24*interval );
    }

		// Publish all DaemonCore-specific attributes, which also handles
		// COLLECTOR_ATTRS for us.
	daemonCore->publish(ad);
}

void
CollectorDaemon::send_classad_to_sock(int cmd, Daemon * d, ClassAd* theAd)
{
    // view_sock is static
    if(!view_sock) {
	dprintf(D_ALWAYS, "Trying to forward ad on, but no connection to View "
		"Collector!\n");
        return;
    }
    if(!theAd) {
	dprintf(D_ALWAYS, "Trying to forward ad on, but ad is NULL!!!\n");
        return;
    }
    if (! d->startCommand(cmd, view_sock)) {
        dprintf( D_ALWAYS, "Can't send command %d to View Collector\n", cmd);
        view_sock->end_of_message();
        return;
    }

    if( theAd ) {
        if( ! theAd->put( *view_sock ) ) {
            dprintf( D_ALWAYS, "Can't forward classad to View Collector\n");
            view_sock->end_of_message();
            return;
        }
    }

	if( cmd == UPDATE_STARTD_AD ) {
			// Forward the startd private ad as well.  This allows the
			// target collector to act as an aggregator for multiple collectors
			// that balance the load of authenticating connections from
			// the rest of the pool.

		AdNameHashKey		hk;
		ClassAd *pvt_ad;

		ASSERT( makeStartdAdHashKey (hk, theAd, NULL) );
		pvt_ad = collector.lookup(STARTD_PVT_AD,hk);
		if( pvt_ad ) {
			if( ! pvt_ad->put( *view_sock ) ) {
				dprintf( D_ALWAYS, "Can't forward startd private classad to View Collector\n");
				view_sock->end_of_message();
				return;
			}
		}
	}

    if( ! view_sock->end_of_message() ) {
        dprintf( D_ALWAYS, "Can't send end_of_message to View Collector\n");
        return;
    }
    return;
}

//  Collector stats on universes
CollectorUniverseStats::CollectorUniverseStats( void )
{
	Reset( );
}

//  Collector stats on universes
CollectorUniverseStats::CollectorUniverseStats( CollectorUniverseStats &ref )
{
	int		univ;

	for( univ=0;  univ<CONDOR_UNIVERSE_MAX;  univ++) {
		perUniverse[univ] = ref.perUniverse[univ];
	}
	count = ref.count;
}

CollectorUniverseStats::~CollectorUniverseStats( void )
{
}

void
CollectorUniverseStats::Reset( void )
{
	int		univ;

	for( univ=0;  univ<CONDOR_UNIVERSE_MAX;  univ++) {
		perUniverse[univ] = 0;
	}
	count = 0;
}

void
CollectorUniverseStats::accumulate(int univ )
{
	if (  ( univ >= 0 ) && ( univ < CONDOR_UNIVERSE_MAX ) ) {
		perUniverse[univ]++;
		count++;
	}
}

int
CollectorUniverseStats::getValue (int univ )
{
	if (  ( univ >= 0 ) && ( univ < CONDOR_UNIVERSE_MAX ) ) {
		return perUniverse[univ];
	} else {
		return -1;
	}
}

int
CollectorUniverseStats::getCount ( void )
{
	return count;
}

int
CollectorUniverseStats::setMax( CollectorUniverseStats &ref )
{
	int		univ;

	for( univ=0;  univ<CONDOR_UNIVERSE_MAX;  univ++) {
		if ( ref.perUniverse[univ] > perUniverse[univ] ) {
			perUniverse[univ] = ref.perUniverse[univ];
		}
		if ( ref.count > count ) {
			count = ref.count;
		}
	}
	return 0;
}

const char *
CollectorUniverseStats::getName( int univ )
{
	return CondorUniverseNameUcFirst( univ );
}

int
CollectorUniverseStats::publish( const char *label, ClassAd *ad )
{
	int	univ;
	char line[100];

	// Loop through, publish all universes with a name
	for( univ=0;  univ<CONDOR_UNIVERSE_MAX;  univ++) {
		const char *name = getName( univ );
		if ( name ) {
			sprintf( line, "%s%s = %d", label, name, getValue( univ ) );
			ad->Insert(line);
		}
	}
	sprintf( line, "%s%s = %d", label, "All", count );
	ad->Insert(line);

	return 0;
}

	// Given a full ad, and a StringList of expressions, Project out of
	// the full ad into the short ad all the attributes those expressions
	// depend on.

	// So, if the projection is passed in "foo", and foo is an expression
	// that expands to bar, we return bar
	
void
computeProjection(ClassAd *shortAd, ClassAd *full_ad, SimpleList<MyString> *projectionList) {
    projectionList->Rewind();

	// CRUFT: Before 7.3.2, submitter ads had a MyType of
	//   "Scheduler". The only way to tell the difference
	//   was that submitter ads didn't have ATTR_NUM_USERS.
	//   If we don't include ATTR_NUM_USERS in our projection,
	//   older clients will morph scheduler ads into
	//   submitter ads, regardless of MyType.
	if (strcmp("Scheduler", full_ad->GetMyTypeName()) == 0) {
		projectionList->Append(MyString(ATTR_NUM_USERS));
	}

		// For each expression in the list...
	MyString attr;
	while (projectionList->Next(attr)) {
		StringList internals;
		StringList externals; // shouldn't have any

			// Get the indirect attributes
		if( !full_ad->GetExprReferences(attr.Value(), internals, externals) ) {
			dprintf(D_FULLDEBUG,
				"computeProjection failed to parse "
				"requested ClassAd expression: %s\n",attr.Value());
		}
		internals.rewind();

		while (char *indirect_attr = internals.next()) {
			ExprTree *tree = full_ad->Lookup(indirect_attr);
			if (tree) shortAd->Insert(tree->DeepCopy());
		}
	}
	shortAd->SetMyTypeName(full_ad->GetMyTypeName());
	shortAd->SetTargetTypeName(full_ad->GetTargetTypeName());

}
