// ProtocolSpecificInit.cc
//
//  used to be Egida_Object_Init.cc
//
// $Locker:  $
// $Log: ProtocolSpecificInit.cc,v $
// Revision 1.1.1.1  2001/02/12 00:00:18  ravshank
// Start of Spring 2001
//
// Revision 1.21  2000/11/21 22:27:19  phoebe
// GarbageCollect in the SentStore is now working async. We changed the logic slightly so that all files are cleaned by one process and we clean when we've heard 3 responses (not necessarily all from different processes...this is ok we think.) Also...our favorite core dump on TakeCkpt (the memcpy one) has crept back in the picture. <grrrr>
//
// Revision 1.20  2000/11/15 22:12:31  phoebe
// Sanity check.
//
// Revision 1.19  2000/11/13 20:57:35  phoebe
// Security had the same memory leak but it's fixed now
//
// Revision 1.18  2000/11/10 15:48:54  phoebe
// Checkpoint memory leak is now solved, and so is the memcpy core dump on some checkpoints.
//
// Revision 1.17  2000/11/06 23:07:12  phoebe
// Encryption of checkpoints is working again. We still have the memcpy problem, but it seems to be less frequent. It's still a bit of a mystery as to why it's happening, and although the core is always dropped on a memcpy in WriteCkpt, it's not deterministic when it happens.
//
// Revision 1.16  2000/10/31 00:22:49  phoebe
// SBP now works with flushing and garbage collection. Before the file out pointers were not being managed properly so after a garbagecollect they were pointing to a non-existant file. So the point of all of this is we have a working SentStore.cc file.
//
// Revision 1.15  2000/10/24 16:32:30  phoebe
// Garbage collection of the sentLog is now happening but sometimes it doesn't recover...think it's a problem with multiple recoveries and not flushing some info. Will check into it. Fixed the memcpy core dump on taking a checkpoint...it was a problem with the fact that we were using a signed int to track the segment size and should have been using an unsigned int so that we didn't get overflow problem.
//
// Revision 1.14  2000/10/20 19:28:48  phoebe
// SentLog class is now integrated and works so protocols using the sentLog to store information will now restart on flushing.
//
// Revision 1.13  2000/10/17 15:02:35  phoebe
// Stable code checkin. RBP is extremely stable except if you kill the master and slave at exactly the same time....it will hang in ReplayDeliver. SBP cannot support concurrent failures due to the lost control messages or hanging in ReplayDeliver. Causal can do +concurrent+ failures as long as control messages are not lost....so the restart must be staggered. Causal seems to suffer the same RBP problem with a master/slave pair, but unsure if this is the problem or if I didn't set numfailures=2...think the later would fix this. All the sentLog protocols (SBP and Causal) suffer from processes dumping core during WriteCkpt if they have been running for a long time since we are not flushing volatile memory at the moment. Should go away with the proper sentLog class fix.
//
// Revision 1.12  2000/10/12 22:23:56  phoebe
// Causal logging seems to work for multiple failures (not concurrent) without a flush of the logs.
//
// Revision 1.11  2000/10/12 19:50:59  phoebe
// Optimistic is still not working for more than one failure, but the incarnation number is now working correctly, and on the second failure it hangs in exactly the same spot every time. Also...optimistic is now rolling back a checkpoint file instead of doing the exec-ing that it was doing before. Additionally, during some of the debugging process, checkpoints are now shrinking heap sizes correctly (we thought they were doing it before, but they weren't.)
//
// Revision 1.10  2000/10/03 22:56:25  phoebe
// Optimistic will now reliably restart once. Still fails multiple sequential failures.
//
// Revision 1.9  2000/09/29 00:20:14  phoebe
// Optimistic will now recover from the first failure...but not multiple sequential failures.
//
// Revision 1.8  2000/09/27 22:03:11  phoebe
// In CkptImpl changed the growing of the heap from a strict monotonically increasing function (using the check that we only grow if size is less than what is needed) to one that can shrink. The reason we can do this is sbrk will take as an argument a negative value, where as malloc cannot.
//
// Revision 1.7  2000/08/17 21:11:20  phoebe
// Optimistic protocol is now running to completion, but it's still not totally proper in that it still will only recover if we avoid the flush race condition.
//
// Revision 1.6  2000/07/11 22:20:05  phoebe
// Did several things: Streamlined DebugTrace so that Egida_Object's RestoreDone didnt' need to call it (got rid of a small memory leak by doing this.) It's less efficient, but then debugging code shouldn't be in the release copy anyway. Two...moved the -recover string to the proper place in the failuredetector so that on a subsequent restart (multiple restarts of one process) it will correctly identify which checkpoint it should be rolling back to. Third...moved growing of the heap in CkptImpl to the RestoreHeapData segs for FullCkpt and put it in the RestoreCkpt for Incremental (in the loop). This is in hopes of being able to restart from in incremental checkpoint. At the moment still can't restart multilple times and can't restart from an incremental checkpoint.
//
// Revision 1.5  2000/06/30 21:00:24  phoebe
// Changed when the FailureDetector is notified of the new checkpoint. It's now in a place where we could delete checkpoint files without any repercussions since the cleanup would be in the pbLog object most likely. Also, the failure detector now re-establishes the socket parameters after a failure whereas before it did not.
//
// Revision 1.4  2000/06/30 19:41:38  phoebe
// Commented out actions in PostCkptActions (Egida class) and can now restart Asynch checkpoint. However, this is still not a correct implementation because it will never clean up det logs.
//
// Revision 1.3  2000/06/29 20:10:33  phoebe
// By commenting out the std::cout's in the Full RestoreSegment method, Egida is now able to restart once again!
//
// Revision 1.2  2000/06/26 16:57:02  phoebe
// Made all the Egida_Object methods and members static. Also moved GetMyId and GetNumProcs out of Egida_Internal and into Egida_Object.
//
// Revision 1.1  2000/06/23 18:48:10  phoebe
// Made Egida_Object_Init.cc a method of the Egida class. It's now called ProtocolSpecificInit.
//
// Revision 1.27  2000/06/23 16:35:31  phoebe
// Cleaning out un-needed data members in classes.
//
// Revision 1.26  2000/06/22 16:18:08  phoebe
// In Egida_Object_Init.cc make sure the new for the NullOrphanDetection had the () at the end of the method. Also, turned on the Loop Counters in Egida_AppLoop.cc file.
//
// Revision 1.25  2000/06/09 14:37:54  phoebe
// Removed EventStore.mmap.cc and testing.cc since they are not needed by anything in Egida.
//
// Revision 1.24  2000/06/02 22:43:04  phoebe
// Added Encryption and Hash and Sign handling to PurgeDetsOnDisk subroutine in DetStore.cc but when testing on cg.B.4 with SBP logging it ran out of memory (the famous p4_shmalloc error)...so need to figure out where the leak is.
//
// Revision 1.23  2000/06/02 01:06:30  phoebe
// Changed pbLog to be correct type for both pessimistic logging types in Egida_Object_Init.cc
//
// Revision 1.22  2000/06/01 23:08:45  phoebe
// Reconfigured the Egida_Object_Init.cc file under the direction of Lorenzo so that the protocol inits make sense.
//
// Revision 1.21  2000/05/23 21:59:44  phoebe
// Realized a bug in the way deliveredLog was being flushed in Egida_Object_Init.cc and fixed it.
//
// Revision 1.18  2000/05/17 21:03:10  phoebe
// Sanity check to make sure all the little tweaks I've done in the last couple of days get saved.
//
// Revision 1.17  2000/04/28 20:08:16  phoebe
// Got Async Checkpoints to return micro-measurements.
//
// Revision 1.16  2000/04/21 15:07:21  phoebe
// Made the make-deps file more up to date.
//
// Revision 1.15  2000/04/20 21:49:44  phoebe
// Added Default protocol to Egida_Object_Init.cc
//
// Revision 1.14  2000/04/17 21:37:46  phoebe
// Combined all the init files for Egida_Object_Init.cc into a single file to make things easier to define. Optimistic logging option is still crashing.
//
// Revision 1.13  2000/04/14 16:34:41  phoebe
// Put in more stats to track encryption/decryption times. Also modified Communication.cc to have a cleaner interface for Message encryption/decryption so it would be easier to track with Stats...meaning I added a wrapper function call. Stats::Init is being done in Egida_PostInit which means the first checkpoint is being missed.
//
// Revision 1.12  2000/04/11 19:49:32  phoebe
// pound defined the loop iteration print statement off.
//
// Revision 1.11  2000/03/29 15:58:39  phoebe
// Added the functionality to just encrypt Egida messages and not Application messages.
//
// Revision 1.10  2000/03/17 21:37:15  phoebe
// Hashing and signing determinants working now. All security hooks should be done and reintegrated.
//
// Revision 1.9  2000/03/17 18:08:47  phoebe
// Encryption of determinants is now in place. Also I added members to DetStore.H class to handle the upcoming hash and sign hooks that will be needed for that functionality with determinants.
//
// Revision 1.8  2000/03/16 21:36:08  phoebe
// Hash and signing of checkpoints now back online. Both partial and full hash and sign.
//
// Revision 1.7  2000/03/16 16:35:01  phoebe
// Changed the writes in WriteCkpt to capture memory dumps in a buffer before writing to file. Memory changes between the initiatiation and termination of a call to write so to be able to hash appropriate values the write function and the hash function should not look directly at memory dumps but rather fixed buffer values.
//
// Revision 1.6  2000/03/16 16:13:38  phoebe
// Can now encrypt only the first checkpoint (the full ckpt) and none of the incremental checkpoints.
//
// Revision 1.5  2000/03/15 17:57:17  phoebe
// Partial checkpoint encryption is working. Tested with all three segment types. Still get the weird assert failing on EventStore.cc but generally it does not happen on loop 4...and when it does you can fail on loop 5 and it seems to be fine.
//
// Revision 1.4  2000/03/15 16:16:18  phoebe
// Full encryption of checkpoints is working.
//
// Revision 1.3  2000/03/07 16:24:50  phoebe
// Was able to restart causal logging by slightly modifying the Egida_Object_Init.cc file to distributed recovery and by tweaking StableDetStore::CkptDone function in DetStore.cc to check whether ofs was NULL before flushing. I restarted the causal protocol after the fourth loop iteration.
//
// Revision 1.2  2000/03/07 00:11:17  phoebe
// Channel Encryption now working. Init now does Security::Init and Security::Reinit. Communication.cc modified to call security functions (obviously). Tested with normal run and restart of Egida_Object_Init-default.cc.
//
// Revision 1.1  2000/03/06 20:43:43  phoebe
// Contains Security.cc and Security.H with no hooks in the code. Just changed the
// Makefile to compile and add Security to the libEgida.a
//
// $Id: ProtocolSpecificInit.cc,v 1.1.1.1 2001/02/12 00:00:18 ravshank Exp $

#include "Egida_Object.H" 

//define only ONE of the following logging protocols
//  by setting that choice to 1 and the rest to 0
#define RECEIVER_BASED_PESSIMISTIC 0
#define SENDER_BASED_PESSIMISTIC   0
#define OPTIMISTIC                 1
#define CAUSAL                     0
#define DEFAULT                    0


#if OPTIMISTIC
//this is receiver based optimistic

void Egida::ProtocolSpecificInit(int flushLogFreq, int ckptFreq, int numFailures) 
{ 
  ckptProtocol = new CkptProtocol(id, numProcs, 
				  ckptFreq,
				  FlushScheduler::EGIDA_PERIODIC_FLUSH);
  
  howToCkpt = new AsyncCkpt(id,
			    CkptImpl::EGIDA_FULL_CKPT, 
			    programName);
  
  detLog = new DetLog(id, numProcs, 
		      DetStore::EGIDA_VOLATILE_STORE, 
		      DetStore::EGIDA_STABLE_STORE,
		      FlushPolicy::EGIDA_INDEP_FLUSH, 
		      EGIDA_DET_LOG_MSG, 
		      flushLogFreq,
		      FlushScheduler::EGIDA_PERIODIC_FLUSH);
  
  deliveredLog = new EventLog(id, numProcs, 
			      EventStore::EGIDA_VOLATILE_STORE, 
			      EventStore::EGIDA_STABLE_STORE,
			      FlushPolicy::EGIDA_INDEP_FLUSH, 
			      EGIDA_DELIVERED_LOG_MSG, 
			      flushLogFreq,
			      FlushScheduler::EGIDA_PERIODIC_FLUSH);

  sentLog = new EventLog(id, numProcs,
			 EventStore::EGIDA_VOLATILE_STORE, 
			 EventStore::EGIDA_NULL_STORE,
			 FlushPolicy::EGIDA_INDEP_FLUSH,
			 EGIDA_SENT_LOG_MSG,
			 -1,
			 FlushScheduler::EGIDA_PERIODIC_FLUSH);
  
  pbLog = new PbVectorClock(id, numProcs, numFailures);

  pbCkpt = new PbCkpt(id, numProcs, ckptProtocol);

  orphanDetection = new OrphanDetectionByBroadcastLC((PbVectorClock *)pbLog);

  rollbackActions = new FlushOnRollback(detLog, 
					deliveredLog);
  
  rollforwardActions = new FlushOnRollback(detLog, 
					   deliveredLog);
  
  recovery = new Recovery(id, 
			  numFailures, 
			  detLog, 
			  sentLog, 
			  deliveredLog, 
			  pbLog, 
			  orphanDetection, 
			  CollectRecInfo::EGIDA_DISTRIBUTED_COLLECT_REC_INFO);
} 

#endif



#if CAUSAL

void Egida::ProtocolSpecificInit(int flushLogFreq, int ckptFreq, int numFailures) 
{ 
  ckptProtocol = new CkptProtocol(id, numProcs, 
				  ckptFreq,
				  FlushScheduler::EGIDA_PERIODIC_FLUSH);
  
  howToCkpt = new AsyncCkpt(id, 
			    CkptImpl::EGIDA_FULL_CKPT, 
			    programName);
  
  detLog = new DetLog(id, numProcs, 
		      DetStore::EGIDA_VOLATILE_STORE, 
		      DetStore::EGIDA_STABLE_STORE,
		      FlushPolicy::EGIDA_INDEP_FLUSH, 
		      EGIDA_DET_LOG_MSG, 
		      flushLogFreq,
		      FlushScheduler::EGIDA_PERIODIC_FLUSH);
 
  deliveredLog = new EventLog(id, numProcs, 
			      EventStore::EGIDA_NULL_STORE, 
			      EventStore::EGIDA_NULL_STORE,
			      FlushPolicy::EGIDA_INDEP_FLUSH, 
			      EGIDA_DELIVERED_LOG_MSG, 
			      -1,
			      FlushScheduler::EGIDA_PERIODIC_FLUSH);

  sentLog = new EventLog(id, numProcs,
			 EventStore::EGIDA_VOLATILE_STORE, 
			 EventStore::EGIDA_STABLE_STORE,
			 FlushPolicy::EGIDA_INDEP_FLUSH,
			 EGIDA_SENT_LOG_MSG,
			 flushLogFreq,
			 FlushScheduler::EGIDA_PERIODIC_FLUSH);
 
  pbLog = new PbCausal(id, numProcs, numFailures);
  
  pbCkpt = new PbCkpt(id, numProcs, ckptProtocol);
 
  orphanDetection = new NullOrphanDetection();
 
  rollbackActions = new RollbackActions(detLog, 
					deliveredLog);
  
  rollforwardActions = new RollbackActions(detLog, 
					   deliveredLog);

  recovery = new Recovery(id, numFailures, 
			  detLog, 
			  sentLog, 
			  deliveredLog, 
			  pbLog, 
			  orphanDetection, 
			  CollectRecInfo::EGIDA_DISTRIBUTED_COLLECT_REC_INFO);
  // ??? recovery needs to be distributed for f = 1 or centralized for f > 1.
  // it seems to work fine for distributed on f > 1 (pkw)
} 

#endif


#if SENDER_BASED_PESSIMISTIC

void Egida::ProtocolSpecificInit(int flushLogFreq, int ckptFreq, int numFailures)
{ 
  
  sentLog = new EventLog(id, numProcs,
			 EventStore::EGIDA_VOLATILE_STORE,
			 EventStore::EGIDA_STABLE_STORE,
			 FlushPolicy::EGIDA_INDEP_FLUSH,
			 EGIDA_SENT_LOG_MSG,
			 flushLogFreq, 
			 FlushScheduler::EGIDA_PERIODIC_FLUSH);
  
  detLog = new DetLog(id, numProcs,
		      DetStore::EGIDA_STABLE_STORE,
		      DetStore::EGIDA_STABLE_STORE,
		      FlushPolicy::EGIDA_INDEP_FLUSH,
		      EGIDA_DET_LOG_MSG,
		      -1,
		      FlushScheduler::EGIDA_PERIODIC_FLUSH);
  
  deliveredLog = new EventLog(id, numProcs,
			      EventStore::EGIDA_NULL_STORE,
			      EventStore::EGIDA_NULL_STORE,
			      FlushPolicy::EGIDA_INDEP_FLUSH,
			      EGIDA_DELIVERED_LOG_MSG,
			      -1,
			      FlushScheduler::EGIDA_PERIODIC_FLUSH);

  howToCkpt = new AsyncCkpt(id, CkptImpl::EGIDA_FULL_CKPT,
			    programName);

  // No orphans for pessimistic/causal
  orphanDetection = new NullOrphanDetection();

  pbLog = new PbLog(id, numProcs, numFailures);
  recovery = new Recovery(id, numFailures,
			  detLog,
			  sentLog,
			  deliveredLog,
			  pbLog,
			  orphanDetection,
			  CollectRecInfo::EGIDA_DISTRIBUTED_COLLECT_REC_INFO);
  
  rollbackActions = new FlushOnRollback(detLog,
					deliveredLog);
  
  rollforwardActions = new FlushOnRollback(detLog,
					   deliveredLog);

  ckptProtocol = new CkptProtocol(id, numProcs,
				  ckptFreq,
				  FlushScheduler::EGIDA_PERIODIC_FLUSH);
  
  // for a protocol that piggybacks nothing
  pbCkpt = new PbCkpt(id, numProcs, ckptProtocol);
} 

#endif



#if RECEIVER_BASED_PESSIMISTIC

void Egida::ProtocolSpecificInit(int flushLogFreq, int ckptFreq, int numFailures)
{ 
  
  sentLog = new EventLog(id, numProcs,
			 EventStore::EGIDA_VOLATILE_STORE,
			 EventStore::EGIDA_NULL_STORE,
			 FlushPolicy::EGIDA_INDEP_FLUSH,
			 EGIDA_SENT_LOG_MSG,  
			 -1, //in RBP each receive will clean the sentLog
			 FlushScheduler::EGIDA_PERIODIC_FLUSH);
  
  detLog = new DetLog(id, numProcs,
		      DetStore::EGIDA_STABLE_STORE,
		      DetStore::EGIDA_STABLE_STORE,
		      FlushPolicy::EGIDA_INDEP_FLUSH,
		      EGIDA_DET_LOG_MSG,
		      -1,
		      FlushScheduler::EGIDA_PERIODIC_FLUSH);
  
  deliveredLog = new EventLog(id, numProcs,
			      EventStore::EGIDA_STABLE_STORE,
			      EventStore::EGIDA_STABLE_STORE,
			      FlushPolicy::EGIDA_INDEP_FLUSH,
			      EGIDA_DELIVERED_LOG_MSG,
			      -1,
			      FlushScheduler::EGIDA_PERIODIC_FLUSH);
  
  howToCkpt = new AsyncCkpt(id, 
			   CkptImpl::EGIDA_FULL_CKPT, 
			   programName);

  // No orphans for pessimistic/causal
  orphanDetection = new NullOrphanDetection();

  pbLog = new PbLog(id, numProcs, numFailures);
  recovery = new Recovery(id, numFailures,
			  detLog,
			  sentLog,
			  deliveredLog,
			  pbLog,
			  orphanDetection,
			  CollectRecInfo::EGIDA_DISTRIBUTED_COLLECT_REC_INFO);
  
  rollbackActions = new FlushOnRollback(detLog,
					deliveredLog);
  
  rollforwardActions = new FlushOnRollback(detLog,
					   deliveredLog);

  ckptProtocol = new CkptProtocol(id, numProcs,
				  ckptFreq,
				  FlushScheduler::EGIDA_PERIODIC_FLUSH);

  // for a protocol that piggybacks nothing
  pbCkpt = new PbCkpt(id, numProcs, ckptProtocol);
} 

#endif



#if DEFAULT

void Egida::ProtocolSpecificInit(int flushLogFreq, int ckptFreq, int numFailures)
{

  
  sentLog = new EventLog(id, numProcs,
			 EventStore::EGIDA_VOLATILE_STORE,
			 EventStore::EGIDA_NULL_STORE,
			 FlushPolicy::EGIDA_INDEP_FLUSH,
			 EGIDA_SENT_LOG_MSG,
			 -1, /* flushLogFreq, */
			 FlushScheduler::EGIDA_PERIODIC_FLUSH);
  
  detLog = new DetLog(id, numProcs,
		      DetStore::EGIDA_VOLATILE_STORE,
		      DetStore::EGIDA_STABLE_STORE,
		      FlushPolicy::EGIDA_INDEP_FLUSH,
		      EGIDA_DET_LOG_MSG,
		      -1,
		      FlushScheduler::EGIDA_PERIODIC_FLUSH);
  
  // This is for no receiver-based logging
  deliveredLog = new EventLog(id, numProcs,
			      EventStore::EGIDA_NULL_STORE,
			      EventStore::EGIDA_STABLE_STORE,
			      FlushPolicy::EGIDA_COORD_FLUSH,
			      EGIDA_DELIVERED_LOG_MSG,
			      flushLogFreq,
			      FlushScheduler::EGIDA_PERIODIC_FLUSH);

  howToCkpt = new SyncCkpt(id, CkptImpl::EGIDA_INCR_CKPT,
			   programName);

  // No orphans for pessimistic/causal
  orphanDetection = new NullOrphanDetection();

  pbLog = new PbCausal(id, numProcs, numFailures);
  recovery = new Recovery(id, numFailures,
			  detLog,
			  sentLog,
			  deliveredLog,
			  pbLog,
			  orphanDetection,
			  CollectRecInfo::EGIDA_DISTRIBUTED_COLLECT_REC_INFO);
  
  rollbackActions = new FlushOnRollback(detLog,
					deliveredLog);
  
  rollforwardActions = new FlushOnRollback(detLog,
					   deliveredLog);
  
  ckptProtocol = new CkptProtocol(id, numProcs,
				  ckptFreq,
				  FlushScheduler::EGIDA_PERIODIC_FLUSH);
  // for a protocol that piggybacks nothing
  pbCkpt = new PbCkpt(id, numProcs, ckptProtocol);
}

#endif
