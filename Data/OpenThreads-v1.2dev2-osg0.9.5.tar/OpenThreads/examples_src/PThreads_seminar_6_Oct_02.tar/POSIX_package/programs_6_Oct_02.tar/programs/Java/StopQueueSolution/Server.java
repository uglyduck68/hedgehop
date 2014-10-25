//              StopQueueProblem/Server.java

/*
  This is the prototypical producer/consumer example done by
  building a singly linked list. Every few seconds we stop the
  queue completely, letting the consumers complete their current
  request, but not taking anything new from the queue.  Upon
  restart, the consumers get to empty the list before the producers
  start.

  Delays are inserted to simulate disk I/O (and to make things
  run slower!).
*/

import java.io.*;
import Extensions.*;


public class Server {
  static boolean        DEBUG = false;
  static boolean        KILL = false;
  static int            cDelay = 500, pDelay = 10;
  static int            nConsumers = 10, nProducers = 1;


public static void main(String argv[]) {
  Workpile      workpile = new Workpile();
  Thread        t;
  SingleBarrier barrier;
  Client        c;
  int           stopperTimeout = 10;

  if (argv.length > 0) cDelay = Integer.parseInt(argv[0]);
  if (argv.length > 1) pDelay = Integer.parseInt(argv[1]);
  if (argv.length > 2) nConsumers = Integer.parseInt(argv[2]);
  if (argv.length > 3) nProducers = Integer.parseInt(argv[3]);
  if (argv.length > 4) stopperTimeout = Integer.parseInt(argv[4]);
  if (System.getProperty("DEBUG") != null) DEBUG = true;
  if (System.getProperty("KILL") != null) KILL = true;
  System.out.println("Server(cDelay: " + cDelay + " pDelay: "
                     + pDelay + " nConsumers: " + nConsumers
                     + " nProducers: " + nProducers
                     + " stopperTimeout: " + stopperTimeout
                     + "s)");                 

  c   = new Client();
  barrier = new SingleBarrier(nConsumers + nProducers);
  if (KILL) new Thread(new Killer(120)).start();
     

  for (int j=0; j<3; j++) {             // Start/Stop 3 times
    System.out.println("Starting consumers...  List length: "
                       + workpile.size());
    for (int i=0; i<nConsumers; i++) {
      new Thread(new Consumer(workpile, barrier), "Consumer_"+i).start();
    }

    // Wait until the list is empty (your code here!)
    try {
      synchronized(workpile) {
	while (!workpile.empty()) {workpile.wait();}
      }
    }
    catch (InterruptedException ie) {System.out.println("Impossible!");}

       
    System.out.println("Starting producers...  List length: "
                       + workpile.size());
    for (int i=0; i<nProducers; i++) {
      new Thread(new Producer(workpile, c, barrier), "Producer_"+i).start();
    }

    new Thread(new Stopper(workpile, stopperTimeout), "Stopper_"+j).start();
    barrier.barrierWait();
    System.out.println("Stopped! List length: " + workpile.size());
    workpile.stop = false;
    InterruptibleThread.sleep(2000);    // Make it pause a bit.
  }      

  System.out.println("Finished!  Produced: " + Request.totalProduced
                     + " Consumed: " + Request.totalConsumed
                     + " items. List length: " + workpile.size());
  System.exit(0);

}
}


