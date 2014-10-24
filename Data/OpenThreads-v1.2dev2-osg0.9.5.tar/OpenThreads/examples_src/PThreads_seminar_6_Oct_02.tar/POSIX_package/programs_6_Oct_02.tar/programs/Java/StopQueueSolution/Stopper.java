//              StopQueueProblem/Stopper.java

import java.io.*;
import Extensions.*;

public class Stopper implements Runnable {
  Workpile              workpile;
  int                   delay;


public Stopper(Workpile w, int d) {
  workpile = w;
  delay = d;
}


public void run() {
  InterruptibleThread.sleep(delay*1000);
  System.out.println("Stopping...");
  synchronized(workpile) {
    workpile.stop = true;
    workpile.notifyAll();
  }
}

}
