//              CancellationInterrupt/Searcher.java

import java.io.*;
import java.util.*;
import Extensions.*;


public class Searcher implements Runnable {
  int           target;
  Cancellation  cancel;
  int           seed;


public Searcher(Cancellation c, int s) {
  target = c.target;
  cancel = c;
  seed = s;
}


public void doDatabaseThing() throws InterruptedException {
  TSDThread self = (TSDThread) Thread.currentThread();

    synchronized (self) {
      if (Thread.interrupted()) {
        System.out.println(self.getName() +
                           " before DoDatabaseThing, interrupted.");
        throw new InterruptedException();
      }
      self.inCriticalSection = true;       // Don't cancel in critical section!
    }
    try {
      cancel.incrementDatabase(1);
      Thread.sleep(10);                   // Use normal sleep() here.
      cancel.incrementDatabase(-1);
      synchronized (self) {
        self.inCriticalSection = false;
        self.notify();
      }
    }
  catch (InterruptedException ie) {
    // Should never get here!
    InterruptibleThread.impossible(ie);
  }
}


public void run() {
  TSDThread self = (TSDThread) Thread.currentThread();
  Random r = new Random(seed);
  int guess;
 
  System.out.println(self.getName() + " is searching...");

  for (int i=0; true; i++) {
    try { doDatabaseThing(); }
    catch (InterruptedException ie) {return;}
    guess = r.nextInt()% 10;
    cancel.incrementGuesses();

    if (guess == target) {
      synchronized(cancel) {
        System.out.println(self.getName() + " got the answer: " + guess); 
        if (cancel.found) {
          System.out.println(self.getName() + " too late! Exiting");
        return;      // If someone else already found it...
        }
        cancel.found = true;
        for (int j=0; j<cancel.nSearchers; j++) {
          TSDThread t1 = (TSDThread) cancel.threads[j];
          if (!t1.equals(self)) {          // Don't kill yourself
            synchronized (t1) {
              while (t1.inCriticalSection) { 
                try  {
                  t1.wait();
                } 
                catch (InterruptedException ie)
		  {InterruptibleThread.impossible(ie);}
              }
              t1.interrupt();
              if (Cancellation.DEBUG)
                System.out.println(self.getName() + " cancelling "
                                   + t1.getName());
            }
          }
        }
        cancel.answer = guess;
        System.out.println(self.getName() + " done.");
        return;
      }
    }
  }
}

}
