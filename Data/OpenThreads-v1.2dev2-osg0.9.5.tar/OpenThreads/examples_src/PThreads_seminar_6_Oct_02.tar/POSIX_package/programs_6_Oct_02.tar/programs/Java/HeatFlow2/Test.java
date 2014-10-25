//              HeatFlow2/Test.java

/*
  A matrix with fixed value edges is iteratively transformed to a
  new matrix, each cell becoming the average of the surrounding
  cells.  A typical simulation problem for almost anything.

  Notice how barriers are used and how much parallelism is allowed
  for the two implmentations.
  
  */

import java.io.*;
import Extensions.*;


public class Test {
  static LList                  stateList;
  static Thread                 t;
  static int                    nThreads = 4;
  static int                    nIterations = 5;
  static SingleBarrier          b;
  static boolean                DEBUG = false;
  static int                    cDelay = 500, pDelay = 10;
  static int                    size = 10;
  static State                  state1, state2, state3;
  static boolean                KILL = false;
  

public static void main(String argv[]) {
  int                           cs, ce = 0;

  if (argv.length > 0) cDelay = Integer.parseInt(argv[0]);
  if (argv.length > 1) nThreads = Integer.parseInt(argv[1]);
  if (argv.length > 2) nIterations = Integer.parseInt(argv[2]);

  if (System.getProperty("DEBUG") != null) DEBUG = true;
  if (System.getProperty("KILL") != null) KILL = true;

  System.out.println("Test(cDelay: " + cDelay + " nThreads: " + nThreads
                     + " nIterations: " + nIterations
                     + ")");

  if (KILL) new Thread(new Killer(120)).start();

  b = new SingleBarrier(nThreads);
  state1 = new State(nThreads, size);
  state2 = new State(nThreads, size);
  state3 = new State(nThreads, size);
  state1.next = state2;
  state2.next = state3;
  state3.next = state1;

  state1.print(0);
         
  for (int i=0; i<nThreads; i++) {
    cs = ce;
    ce = ((i+1) * size)/nThreads;
    t = new Thread(new Worker(state1, b, cDelay, cs, ce, nIterations));
    t.start();
  }

  b.barrierWait();
  state1.print(nIterations);
  System.out.println("Finished!");
  System.exit(0);
}

}
