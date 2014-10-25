//              Extensions/SingleBarrier.java

/*
  Unlike a Barrier where all threads wait until all are ready, with this
  Threads may indicate that they've completed their job by doing a
  barrierPost() and then continue.  Later, other threads (or the same)
  may wait until everyone has done a barrierPost() by doing a
  barrierWait().

  By default, assume a single waiter.  You must know the number of
  threads that will be posting and the number that will be waiting.

*/


package Extensions;

import java.io.*;


public class SingleBarrier {
  int           currentPosters = 0, totalPosters = 0;
  int           passedWaiters = 0, totalWaiters = 1;


public SingleBarrier (int i) {
  totalPosters = i;
}


public SingleBarrier (int i, int j) {
  totalPosters = i; totalWaiters = j;
}

  
public SingleBarrier () {
}


public synchronized void init(int i) {
  totalPosters = i; currentPosters=0;
}


public synchronized void barrierSet(int i) {
  totalPosters = i; currentPosters=0;
}


public synchronized void barrierWait() {
  boolean interrupted = false;
  while (currentPosters != totalPosters) {
    try {wait();} 
    catch (InterruptedException ie) {interrupted=true;}
  }
  passedWaiters++;
  if (passedWaiters == totalWaiters) {
    currentPosters = 0; passedWaiters = 0; notifyAll();
  }     
  if (interrupted) Thread.currentThread().interrupt();
}


public synchronized void barrierPost() {
  boolean interrupted = false;

  // In case a poster thread beats barrierWait, keep count of posters.
  while (currentPosters == totalPosters) {      
    try {wait();} 
    catch (InterruptedException ie) {interrupted=true;}
  }
  currentPosters++;
  if (currentPosters == totalPosters) notifyAll();
  if (interrupted) Thread.currentThread().interrupt();
}

}
