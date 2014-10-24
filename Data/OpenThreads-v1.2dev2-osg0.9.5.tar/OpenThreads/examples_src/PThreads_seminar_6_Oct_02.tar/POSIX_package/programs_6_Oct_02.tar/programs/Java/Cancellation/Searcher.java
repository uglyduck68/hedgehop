//              Cancellation/Searcher.java


import java.io.*;
import java.util.*;
import Extensions.*;


public class Searcher implements Runnable {
  int           target;
  Cancellation  cancel;
  int           seed;


public Searcher(Cancellation c, int s) {
  target = c.target;
  cancel=c;
  seed = s;
}

  synchronized void doDatabaseThing() { // Should be atomic, but won't be. 
      cancel.incrementDatabase(1);
      InterruptibleThread.sleep(10);
      cancel.incrementDatabase(-1);
  }


public void run() {
  Thread self = Thread.currentThread();
  Random r = new Random(seed);
  int guess;
 
  System.out.println(self.getName() + " is searching...");

  for (int i=0; true; i++) {
    doDatabaseThing();
    guess = r.nextInt() % 1000;
    cancel.incrementGuesses();
    if (guess == target) {
      synchronized(cancel) {            // This is NOT quite right!  Why? 
        for (int j=0; j<cancel.nSearchers; j++)
          if (!cancel.threads[j].equals(self)) {
            cancel.threads[j].stop(); 	// Yes, stop() is deprecated.
          }
      }
      cancel.answer = guess;
      break;
    }
  }
  System.out.println(self.getName() + " got the answer: " + cancel.answer);
}
}
