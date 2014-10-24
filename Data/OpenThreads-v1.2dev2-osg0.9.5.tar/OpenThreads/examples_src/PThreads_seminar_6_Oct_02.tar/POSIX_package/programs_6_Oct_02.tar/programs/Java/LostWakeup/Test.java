//              StopQueueSolution/Test.java

/*
  This is the prototypical producer/consumer example done by
  building a singly linked list. Every few seconds we stop the
  queue completely, letting the consumers complete their current
  request, but not taking anything new from the queue.  Upon
  restart, the consumers get to empty the list before the producers
  start.

  Delays are inserted to simulate disk I/O (and to make things
  run slower!).

  Calls to sleep(0) do not affect the program (vs. commenting such
  lines out).
*/

import java.io.*;
import java.util.*;
import Extensions.*;


public class Test {
  static Workpile               workpile = new Workpile();
  static boolean                DEBUG = false;
  static Server                 server;
  static int                    stopDelay = 1000;
  static int                    LWDelay = 0;
  static int                    LWHangs = 0;
  static int                    testIterations = 10000;
  static SingleBarrier          barrier;
  static SingleBarrier          barrier2;
  static boolean                KILL = false;


public static void main(String argv[]) {
  int cDelay = 500, pDelay = 10;
  int nConsumers = 10, nProducers = 1;
  Thread t;
 
  if (argv.length > 0) cDelay = Integer.parseInt(argv[0]);
  if (argv.length > 1) pDelay = Integer.parseInt(argv[1]);
  if (argv.length > 2) nConsumers = Integer.parseInt(argv[2]);
  if (argv.length > 3) nProducers = Integer.parseInt(argv[3]);
  if (argv.length > 4) LWDelay = Integer.parseInt(argv[4]);
  if (System.getProperty("DEBUG") != null) DEBUG = true;
  if (System.getProperty("KILL") != null) KILL = true;

  System.out.println("Test(cDelay: " + cDelay + " pDelay: "
                     + pDelay + " nConsumers: " + nConsumers
                     + " nProducers: " + nProducers + " LWDelay " + LWDelay
                     + ")");

  server   = new Server(DEBUG, cDelay, pDelay, workpile);
  barrier = new SingleBarrier(nConsumers + nProducers);
  barrier2 = new SingleBarrier(1);
  if (KILL) new Thread(new Killer(120)).start();

  test();
  testProducer();
  testConsumer();
  server   = new Server(DEBUG, cDelay, pDelay, workpile);
     
  for (int j=0; j<100; j++) {

    System.out.println("Starting consumers...  List length: "
                       + workpile.size());
    for (int i=0; i<nConsumers; i++) {
      t=new Thread(new Consumer(workpile, server, barrier));
      t.start();
    }

    workpile.mutex.lock();
    while (!workpile.empty())
      workpile.producerCV.condWait(workpile.mutex);
    workpile.mutex.unlock();
       
    System.out.println("Starting producers...List length: "
                       + workpile.size());
                      
    for (int i=0; i<nProducers; i++) {
      t=new Thread(new Producer(workpile, server, barrier));
      t.start();
    }

    new Thread(new Stopper(workpile, stopDelay)).start();
    barrier.barrierWait();
    System.out.println("Stopped! List length: " + workpile.size());
    workpile.stop = false;
    barrier2.barrierWait();
  }

      

  System.out.println("Finished!  Produced: " + server.pcounter
                     + " Consumed: " + server.ccounter
                     + " items. List length: " + workpile.size()
                     + " Hangs " + LWHangs + " in " + stopDelay + " mS");
  System.exit(0);

}


public static void test() {
  long end, start;
  Item item;

  start = new Date().getTime();

  for (int i=0; i<testIterations; i++) {
    item = server.get();
    workpile.mutex.lock();
    while (workpile.full() && !workpile.stop) {
      workpile.producerCV.condWait(workpile.mutex);
    }
    workpile.add(item);
    if (workpile.stop) {}; // Put the Item on the list!
    workpile.mutex.unlock();
    workpile.consumerCV.condSignal();

    workpile.mutex.lock();
    if (Test.LWDelay > 0) {
      while (workpile.empty() && !workpile.stop) {
        //      InterruptibleThread.sleep(Test.LWDelay);
        workpile.consumerCV.condWait(workpile.mutex);
      }
    }
    else {
      while (workpile.empty() && !workpile.stop) {
        workpile.consumerCV.condWait(workpile.mutex);
      }
    }

    if (workpile.stop) {};
    item = workpile.removeFirst();
    workpile.mutex.unlock();
    workpile.producerCV.condSignal();
    server.process(item);
  }


  end = new Date().getTime();
  float time = ((float) (end-start))/testIterations;

  System.out.println("Produced&Consumed " + testIterations + " times in "
                     + ((end-start)/1000) + " seconds.");
  if (time > 1)
    System.out.println(time + " mS.");
  else
    System.out.println(time*1000 + " uS.");

}

public static void testProducer() {
  long end, start;
  Item item;
  int temp = workpile.max;

  workpile.max = testIterations+1;
  start = new Date().getTime();

  for (int i=0; i<testIterations; i++) {
    item = server.get();
    workpile.mutex.lock();
    while (workpile.full() && !workpile.stop) {
      workpile.producerCV.condWait(workpile.mutex);
    }
    workpile.add(item);
    if (workpile.stop) {}; // Put the Item on the list!
    workpile.mutex.unlock();
    workpile.consumerCV.condSignal();
  }


  end = new Date().getTime();
  float time = ((float) (end-start))/testIterations;
  workpile.max = temp;

  System.out.println("Produced " + testIterations + " times in "
                     + ((end-start)/1000) + " seconds.");
  if (time > 1)
    System.out.println(time + " mS.");
  else
    System.out.println(time*1000 + " uS.");

}

public static void testConsumer() {
  long end, start;
  Item item;

  start = new Date().getTime();

  for (int i=0; i<testIterations; i++) {

    workpile.mutex.lock();
    if (Test.LWDelay > 0) {
      while (workpile.empty() && !workpile.stop) {
        //      InterruptibleThread.sleep(Test.LWDelay);
        workpile.consumerCV.condWait(workpile.mutex);
      }
    }
    else {
      while (workpile.empty() && !workpile.stop) {
        workpile.consumerCV.condWait(workpile.mutex);
      }
    }

    if (workpile.stop) {};
    item = workpile.removeFirst();
    workpile.mutex.unlock();
    workpile.producerCV.condSignal();
    server.process(item);
  }


  end = new Date().getTime();
  float time = ((float) (end-start))/testIterations;

  System.out.println("Consumed " + testIterations + " times in "
                     + ((end-start)/1000) + " seconds.");
  if (time > 1)
    System.out.println(time + " mS.");
  else
    System.out.println(time*1000 + " uS.");

}

}


