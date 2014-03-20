//              StopQueueSolution/Consumer.java

import java.io.*;
import Extensions.*;

public class Consumer implements Runnable {
  Workpile workpile;
  Server server;
  SingleBarrier barrier;

public Consumer(Workpile w,  Server s, SingleBarrier b) {
  workpile = w;
  server = s;
  barrier= b;
}


public void run() {
  Item item;

  while (true) {
    workpile.mutex.lock();
    if (Test.LWDelay > 0) {
      while (workpile.empty() && !workpile.stop) {
        InterruptibleThread.sleep(Test.LWDelay);
        workpile.consumerCV.condWait(workpile.mutex);
      }
    }
    else {
      while (workpile.empty() && !workpile.stop) {
        workpile.consumerCV.condWait(workpile.mutex);
      }
    }

    if (workpile.stop) break;
    item = workpile.removeFirst();
    workpile.mutex.unlock();
//     if (workpile.empty())
      workpile.producerCV.condSignal();
    server.process(item);
  }

  workpile.mutex.unlock();
  barrier.barrierPost();
}
 
}
