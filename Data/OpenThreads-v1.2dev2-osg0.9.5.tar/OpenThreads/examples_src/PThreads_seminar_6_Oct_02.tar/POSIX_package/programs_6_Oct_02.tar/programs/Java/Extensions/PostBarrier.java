//              Extensions/PostBarrier.java

/*
  Like a SingleBarrier, only this resets itself after N threads have
  waited.
  */


package Extensions;

import java.io.*;


public class PostBarrier {
  int           currentCount;
  int           initialCount;
  int           nCompleted;


public PostBarrier (int i) {
  initialCount = i; currentCount=i;
}


public PostBarrier () {
  initialCount = 0; currentCount=0;
}


public synchronized void init(int i) {
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
    
  if (nCompleted == 0)  notifyAll();
  nCompleted++;
  if (nCompleted == initialCount) {
    currentCount = initialCount;
    nCompleted = 0;
    notifyAll();
  }
  if (interrupted) Thread.currentThread().interrupt();
}

}
