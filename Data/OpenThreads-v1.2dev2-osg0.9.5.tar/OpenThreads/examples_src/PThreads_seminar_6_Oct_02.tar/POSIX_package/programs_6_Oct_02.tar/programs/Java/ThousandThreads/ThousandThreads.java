//              ThousandThreads/ThousandThreads.java

/*
  Make 1000 threads
 */


import java.io.*;
import java.util.*;
import Extensions.*;

public class ThousandThreads implements Runnable {
 static boolean         DEBUG = false;
 static boolean         CREATE_ALL_BEFORE_ANY_EXIT = false;
 static int             nThreads = 1000;
 static Thread[]        threads;
 static Barrier         barrier;



public static void main(String[] args) throws InterruptedException {

  if (args.length > 0) nThreads  =              Integer.parseInt(args[0]);
  if (args.length > 1) CREATE_ALL_BEFORE_ANY_EXIT  =
                         (Integer.parseInt(args[1]) == 1);
  if (System.getProperty("DEBUG") != null) DEBUG = true;
  System.out.println("Client(nThreads: " + nThreads +
                     " CREATE_ALL_BEFORE_ANY_EXIT: " + CREATE_ALL_BEFORE_ANY_EXIT
                     + ")\nDEBUG: " + DEBUG + "\n");

  threads = new Thread[nThreads];
  barrier = new Barrier(nThreads+1);

  for (int i = 0; i < nThreads; i++) {
    threads[i] = new Thread(new ThousandThreads());
    if (DEBUG) System.out.println("Created " + threads[i]);
    threads[i].start();
  }

  if (CREATE_ALL_BEFORE_ANY_EXIT) barrier.barrierWait();
  for (int i = 0; i < nThreads; i++) {
    threads[i].join();
    if (DEBUG) System.out.println(threads[i] + " joined.");
  }
  System.out.println("Finished.");
}

public void run() {
  if (DEBUG) System.out.println(Thread.currentThread() + " started.");
  if (CREATE_ALL_BEFORE_ANY_EXIT) barrier.barrierWait();
}

}
