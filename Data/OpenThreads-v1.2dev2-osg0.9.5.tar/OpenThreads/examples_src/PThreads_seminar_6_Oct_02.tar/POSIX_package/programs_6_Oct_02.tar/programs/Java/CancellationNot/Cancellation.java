//              CancellationNot/Cancellation.java

/*
   A very simple example to run which illustrations a cancellation
   alternative.
   Choose a target number, then create a bunch of threads to search
   for using a heuristic (call rand()!).  The first to find it sets
   a variable for the the others to see.

   A "database" is included to illustrate typical problems.  The database
   should always by 0 at the end of every transaction.  Observe how
   much effort that takes.  This is 100% correct.either! (Why?)

  
 */


import java.io.*;
import Extensions.*;


public class Cancellation {
  int           answer = 0;
  int           target = 100;
  int           nSearchers = 10;
  Thread        threads[] = new Thread[nSearchers];
  SingleBarrier barrier = new SingleBarrier(nSearchers);
  int           databaseBalanced = 0;
  int           nGuesses = 0;
  boolean       found = false;


public static void main(String argv[]) throws InterruptedException {
  Cancellation c = new Cancellation();

  for (int i=0; i<2; i++) {
    c.run();
  }
}


public synchronized void incrementGuesses() {
  nGuesses++;
}

public synchronized void incrementDatabase(int i) {
  databaseBalanced += i;
}


public void run() throws InterruptedException {
  Thread t;
  nGuesses = 0;
  found = false;
   
  synchronized(this) {
    for (int i=0; i<nSearchers; i++) {
      threads[i] = new Thread(new Searcher(this, i));
      threads[i].start();
    }
  }
  barrier.barrierWait();
  System.out.println("The answer is: " + answer + ", it took: " + nGuesses
                     + " guesses, and the database is...");
  if (databaseBalanced == 0)
    System.out.println("Consistant.");
  else
    System.out.println("Inconsistant!");
}

}

