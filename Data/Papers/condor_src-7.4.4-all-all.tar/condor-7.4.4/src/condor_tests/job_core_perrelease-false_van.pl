#! /usr/bin/env perl
##**************************************************************
##
## Copyright (C) 1990-2007, Condor Team, Computer Sciences Department,
## University of Wisconsin-Madison, WI.
## 
## Licensed under the Apache License, Version 2.0 (the "License"); you
## may not use this file except in compliance with the License.  You may
## obtain a copy of the License at
## 
##    http://www.apache.org/licenses/LICENSE-2.0
## 
## Unless required by applicable law or agreed to in writing, software
## distributed under the License is distributed on an "AS IS" BASIS,
## WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
## See the License for the specific language governing permissions and
## limitations under the License.
##
##**************************************************************

use CondorTest;

$cmd = 'job_core_perrelease-false_van.cmd';
$testdesc =  'Condor submit policy test for periodic_release - vanilla U';
$testname = "job_core_perrelease_van";

my %info;
my $cluster;

# truly const variables in perl
sub IDLE{1};
sub HELD{5};
sub RUNNING{2};

$executed = sub
{
	%info = @_;
	$cluster = $info{"cluster"};

	CondorTest::debug("Bad. Job submitted on hold and NEVER released by periodic release policy... Should not RUN!\n",1);
	exit(1);
};

$success = sub
{
	my %info = @_;
	my $cluster = $info{"cluster"};

	CondorTest::debug("Bad. Job submitted on hold and NEVER released by periodic release policy... Should not Complete!\n",1);
	exit(1);
};

$timed = sub
{
	my %info = @_;
	#my $cluster = $info{"cluster"};

	CondorTest::RemoveTimed($testname);
	CondorTest::debug("Cluster $cluster alarm wakeup\n",1);
	CondorTest::debug("wakey wakey!!!!\n",1);

	my @adarray;
	my $status = 1;
	my $cmd = "condor_rm $cluster";
	$status = CondorTest::runCondorTool($cmd,\@adarray,2);
	if(!$status)
	{
		CondorTest::debug("Test failure due to Condor Tool Failure<$cmd>\n",1);
		exit(1)
	}
	sleep 5;
};

$submit = sub
{
	my %info = @_;
	$cluster = $info{"cluster"};

	my $qstat = CondorTest::getJobStatus($cluster);
	while($qstat == -1)
	{
		CondorTest::debug("Job status unknown - wait a bit\n",1);
		sleep 2;
		$qstat = CondorTest::getJobStatus($cluster);
	}

	CondorTest::debug("It better be on hold... status is $qstat(5 is correct)",1);
	if($qstat != HELD)
	{
		CondorTest::debug("Cluster $cluster failed to go on hold\n",1);
		exit(1);
	}


	CondorTest::debug("Cluster $cluster submitted\n",1);
};

$abort = sub
{
	my %info = @_;
	my $cluster = $info{"cluster"};

	CondorTest::debug("Cluster $cluster aborted after hold state verified\n",1);
};

CondorTest::RegisterSubmit($testname, $submit);
CondorTest::RegisterAbort($testname, $abort);
CondorTest::RegisterExecute($testname, $executed);
# Note we are never going to release this job if preriodic release
# policy is false.... so eventually we simply remove it
# Question is....... how long after submit do we wait to make sure
CondorTest::RegisterTimed($testname, $timed, 25); # kill in queue 25 seconds
CondorTest::RegisterExitedSuccess( $testname, $success );

if( CondorTest::RunTest($testname, $cmd, 0) ) {
	CondorTest::debug("$testname: SUCCESS\n",1);
	exit(0);
} else {
	die "$testname: CondorTest::RunTest() failed\n";
}

