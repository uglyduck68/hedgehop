//              StopQueueSolution/Stopper.java

import java.io.*;
import Extensions.*;

public class Stopper implements Runnable {

  Workpile workpile;
  int delay;


public Stopper(Workpile w, int d) {

  workpile = w;
  delay = d;
}

public void run() {

  InterruptibleThread.sleep(delay);
  System.out.println("Stopping...");
  //    workpile.mutex.lock();
  workpile.stop = true;
  //    workpile.mutex.unlock();
  workpile.consumerCV.condBroadcast();
  workpile.producerCV.condBroadcast();

  // Now, did they all exit?
  InterruptibleThread.sleep(10);
  if (workpile.stop == true) {    
    System.out.println("Hanging, Rebroadcasting...");
    workpile.consumerCV.condBroadcast();
    workpile.producerCV.condBroadcast();
    InterruptibleThread.sleep(10);
    Test.LWHangs++;
    if (workpile.stop == true) {
      System.out.println("Impossible");
      System.exit(-1);
    }
  }
      Test.barrier2.barrierPost();
}

}
