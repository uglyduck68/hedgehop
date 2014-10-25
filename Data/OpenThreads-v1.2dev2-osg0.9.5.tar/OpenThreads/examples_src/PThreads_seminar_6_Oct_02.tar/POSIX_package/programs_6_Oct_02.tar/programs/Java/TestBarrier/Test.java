//              TestBarrier/Test.java

/*

  Test your barrier.  Replace "Barrier" with "MyBarrier", then write it!

*/

import java.io.*;
import java.util.*;
import Extensions.*;


public class Test implements Runnable {
  static String                 stars[] =  {"", "*", "**", "***", "****",
					    "*****", "******", "*******",
					    "********", "*********"};
  static RecursiveMutex         mutex = new RecursiveMutex();
  static SingleBarrier          singleBarrier;
  static MyBarrier	        myBarrier; 	// Replace with MyBarrier
  static boolean                KILL = false;
  Random 	       		ran = new Random();
  static int 			nThreads = 5;
  static int 			iterations = 10;


public static void main(String argv[]) {
  Thread                t;

  if (System.getProperty("KILL") != null) KILL = true;
  if (argv.length > 0) nThreads = Integer.parseInt(argv[0]);
  if (argv.length > 1) iterations = Integer.parseInt(argv[1]);
  if (iterations > 10) iterations = 10;
  System.out.println("Test(nThreads: " + nThreads + " iterations: "
		     + iterations + " )");


  if (KILL) new Thread(new Killer(120)).start();
  singleBarrier = new SingleBarrier(nThreads);
  myBarrier = new MyBarrier(nThreads); 		// Replace with MyBarrier

  
  for (int j=0; j<nThreads; j++) {
    t = new Thread(new Test());
    t.start();
  }

  singleBarrier.barrierWait();
  System.out.println("Done.");
  System.exit(0);    
}


public void doWork(int i) { 
  int s = Math.abs(ran.nextInt() % 100);
  InterruptibleThread.sleep(s);
  System.out.println(Thread.currentThread().getName() +
		     " completed interation " + i + "\t" + stars[i]);
}


public void run() {

  for (int i = 1; i<iterations; i++) {
    doWork(i);
    myBarrier.barrierWait();
  }
    
  singleBarrier.barrierPost(); // We're all done. Tell mom.
}
 
}
