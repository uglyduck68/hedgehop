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


#ifndef NORDUGRIDJOB_H
#define NORDUGRIDJOB_H

#include "condor_common.h"
#include "condor_classad.h"
#include "MyString.h"
#include "classad_hashtable.h"

#include "basejob.h"
#include "nordugridresource.h"
#include "proxymanager.h"
#include "gahp-client.h"

void NordugridJobInit();
void NordugridJobReconfig();
BaseJob *NordugridJobCreate( ClassAd *jobad );
bool NordugridJobAdMatch( const ClassAd *job_ad );

class NordugridResource;

class NordugridJob : public BaseJob
{
 public:

	NordugridJob( ClassAd *classad );

	~NordugridJob();

	void Reconfig();
	int doEvaluateState();
	BaseResource *GetResource();
	void SetRemoteJobId( const char *job_id );

	static int probeInterval;
	static int submitInterval;
	static int gahpCallTimeout;
	static int maxConnectFailures;

	static void setProbeInterval( int new_interval )
		{ probeInterval = new_interval; }
	static void setSubmitInterval( int new_interval )
		{ submitInterval = new_interval; }
	static void setGahpCallTimeout( int new_timeout )
		{ gahpCallTimeout = new_timeout; }
	static void setConnectFailureRetry( int count )
		{ maxConnectFailures = count; }

	void NotifyNewRemoteStatus( const char *status );

	int gmState;
	time_t lastProbeTime;
	bool probeNow;
	time_t enteredCurrentGmState;
	time_t lastSubmitAttempt;
	int numSubmitAttempts;

	MyString errorString;
	char *resourceManagerString;

	char *remoteJobId;
	MyString remoteJobState;

	Proxy *jobProxy;
	NordugridResource *myResource;
	GahpClient *gahp;

		// If we're in the middle of a gahp call that requires an RSL,
		// the RSL is stored here (so that we don't have to reconstruct the
		// RSL every time we test the call for completion). It should be
		// freed and reset to NULL once the call completes.
	MyString *RSL;
		// Same as for RSL, but used by the file staging calls.
	StringList *stageList;
	StringList *stageLocalList;

	MyString *buildSubmitRSL();
	StringList *buildStageInList();
	StringList *buildStageOutList();
	StringList *buildStageOutLocalList( StringList *stage_list );

 protected:
};

#endif

