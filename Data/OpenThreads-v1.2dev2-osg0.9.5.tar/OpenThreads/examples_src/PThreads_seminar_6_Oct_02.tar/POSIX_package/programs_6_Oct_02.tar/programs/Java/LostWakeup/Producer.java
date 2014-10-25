//              StopQueueSolution/Producer.java

import java.io.*;
import Extensions.*;

public class Producer implements Runnable {
  Workpile workpile;
  Server server;
  SingleBarrier barrier;

public Producer(Workpile w,  Server s, SingleBarrier b) {
  workpile = w;
  server = s;
  barrier= b;
}

public void run() {
  Item item;

  while (true) {
    item = server.get();
    workpile.mutex.lock();
    while (workpile.full() && !workpile.stop) {
      workpile.producerCV.condWait(workpile.mutex);
    }
    workpile.add(item);
    if (workpile.stop) break; // Put the Item on the list!
    workpile.mutex.unlock();
//    if (workpile.full())
    workpile.consumerCV.condSignal();
  }

  workpile.mutex.unlock();
  barrier.barrierPost();
}
 
}
