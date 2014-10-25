//              CancellationNot/Searcher.java


import java.io.*;
import java.util.*;
import Extensions.*;


public class Searcher implements Runnable {
  int target;
  Cancellation cancel;
  int seed;


public Searcher(Cancellation c, int s) {
  target = c.target;
  cancel=c;
  seed = s;
}


public synchronized void doDatabaseThing() {
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
    synchronized(cancel) {if (cancel.found) break;}
    guess = r.nextInt() % 1000;
    cancel.incrementGuesses();
    if (guess == target) {
      System.out.println(self.getName() + " got the answer: " + cancel.answer);
      synchronized(cancel) {
        if (cancel.found) break;
        cancel.answer = guess;
        cancel.found = true;
        break;
      }
    }
  }
  cancel.barrier.barrierPost();
  return;
}

}
