//              Extensions/Barrier.java

/*
  A "classic" barrier.  You construct a barrier for N threads.  Each
  thread calls barrierWait() then waits until all N have called it
  before proceeding.
  */


package Extensions;

import java.io.*;


public class Barrier {
  int currentCount;
  int initialCount;
  int nCompleted;

public Barrier (int i) {
  initialCount = i; currentCount=i;
}

public Barrier () {
  initialCount = 0; currentCount=0;
}

public synchronized void init(int i) {
  initialCount = i; currentCount=i;
}

public synchronized void barrierSet(int i) {
  initialCount = i; currentCount=i;
}

public synchronized void barrierWait() {
  boolean interrupted = false;

  while (nCompleted > 0) {              // Are there still sleepers waking from 
    try {wait();}                       // from the previous use? 
    catch (InterruptedException ie) {interrupted=true;}
  }

  currentCount--;
  while (currentCount > 0) {
    try {wait();}
    catch (InterruptedException ie) {interrupted=true;}
  }
  if (nCompleted == 0) notifyAll();
  nCompleted++;
  if (nCompleted == initialCount) {
    currentCount = initialCount;
    nCompleted = 0;
    notifyAll();
  }
  if (interrupted) Thread.currentThread().interrupt();
}

}
