//              OneQueueProblem/Server.java

/*
  This is the prototypical producer/consumer example done by
  building a singly linked list. 

  Delays are inserted to simulate disk I/O (and to make things
  run slower!).
*/

import java.io.*;
import Extensions.*;


public class Server {
  static boolean        DEBUG = false;
  static boolean        KILL = false;
  static int            cDelay = 500, pDelay = 10;
  static int           	nConsumers = 10, nProducers = 1;


public static void main(String argv[]) {
  Workpile      workpile = new Workpile();
  SingleBarrier barrier;
  Client        c;

  if (argv.length > 0) cDelay = Integer.parseInt(argv[0]);
  if (argv.length > 1) pDelay = Integer.parseInt(argv[1]);
  if (argv.length > 2) nConsumers = Integer.parseInt(argv[2]);
  if (argv.length > 3) nProducers = Integer.parseInt(argv[3]);
  if (System.getProperty("DEBUG") != null) DEBUG = true;
  if (System.getProperty("KILL") != null) KILL = true;
  System.out.println("Server(cDelay: " + cDelay + " pDelay: "
                     + pDelay + " nConsumers: " + nConsumers
                     + " nProducers: " + nProducers
                     + ")");                 

  c   = new Client();
  barrier = new SingleBarrier(nProducers+nConsumers);

  System.out.println("Starting consumers...  List length: "
                     + workpile.size());
  for (int i=0; i<nConsumers; i++) {
    new Thread(new Consumer(workpile, barrier), "Consumer_"+i).start();
  }

  System.out.println("Starting producers...  List length: "
                     + workpile.size());
  for (int i=0; i<nProducers; i++) {
    new Thread(new Producer(workpile, c, barrier), "Producer_"+i).start();
  }

  if (KILL)
    InterruptibleThread.sleep(20000); // Make it pause a bit.
  else
    return;

  System.out.println("Finished!  Produced: " + Request.totalProduced
                     + " Consumed: " + Request.totalConsumed
                     + " items. List length: " + workpile.size());
  System.exit(0);
}
}


