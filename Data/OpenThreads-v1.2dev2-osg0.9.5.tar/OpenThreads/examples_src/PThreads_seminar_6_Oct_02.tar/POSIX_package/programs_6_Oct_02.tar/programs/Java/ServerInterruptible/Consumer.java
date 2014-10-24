//              ServerInterruptible/Consumer.java

import java.io.*;
import Extensions.*;



public class Consumer implements Runnable {
  Workpile              workpile;



public Consumer(Workpile w) {
  workpile = w;
}



public void run() {
  Request               request;
  String                selfName = Thread.currentThread().getName();

  while (true) {
    try {
      synchronized (workpile) {
        while (workpile.empty()) {workpile.wait();}
        request = workpile.removeFirst();
        workpile.notifyAll();
      }
      request.process();
    }
    catch (InterruptedException ie) {   // Never called.
      System.out.println(ie + " in consumer.run() " + selfName);
    }
  }
}

}
