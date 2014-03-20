//              CancellationInterrupt/Cancellation.java


/*
   A very simple example to run which illustrations cancellation.
   Choose a target number, then create a bunch of threads to search
   for using a heuristic (call rand()!).  The first to find it cancels
   the others.

   A "database" is included to illustrate typical problems.  The database
   should always by 0 at the end of every transaction.  Observe how
   much effort that takes. 

  
 */


import java.io.*;
import Extensions.*;

public class Cancellation {
  int           answer = 0;
  int           target = 9;
  boolean       found = false;
  int           nSearchers = 10;
  TSDThread     threads[] = new TSDThread[nSearchers];
  Object        databaseBalancedLock = new Object();
  int           databaseBalanced = 0;
  Object        nGuessesLock = new Object();
  int           nGuesses = 0;
  static        boolean DEBUG = false;


public static void main(String argv[]) throws InterruptedException {
  Cancellation c = new Cancellation();

  if (System.getProperty("DEBUG") != null) DEBUG = true;
  for (int i=0; i<2; i++) {
    c.run();
  }
}


public void incrementGuesses() {
  synchronized(nGuessesLock) {
    nGuesses++;
  }             // Cannot synchronize on cancel. Why?
}

public void incrementDatabase(int i) {

  if (DEBUG)
    System.out.println(Thread.currentThread().getName()
                       + " incrementing "
                       + databaseBalanced + " by " + i);

  synchronized(databaseBalancedLock) {
    databaseBalanced += i;
  }     // Cannot synchronize on cancel. Why?
}


public void run() throws InterruptedException {
  Thread t;
  nGuesses = 0;
  found = false;

  synchronized(this) {
    for (int i=0; i<nSearchers; i++) {
      threads[i] = new TSDThread(new Searcher(this, i));
      threads[i].start();
    }
  }
  for (int i=0; i<nSearchers; i++) {
    threads[i].join();
    System.out.println(threads[i].getName() + " joined.");
  }

  System.out.println("The answer is: " + answer + ", it took: " + nGuesses
                     + " guesses, and the database is...");
  if (databaseBalanced == 0)
    System.out.println("Consistant.");
  else
    System.out.println("Inconsistant!");
}

}
