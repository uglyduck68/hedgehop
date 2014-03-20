//              StopQueueProblem/Consumer.java

import java.io.*;
import Extensions.*;

public class Consumer implements Runnable {
  Workpile              workpile;
  SingleBarrier         barrier;
  BBoardMgrImpl		mgr;

public Consumer(Workpile w, BBoardMgrImpl m) {
  mgr = m;
  workpile = w;
}


public void run() {
  Request request;

  try {
    while (true) {
      synchronized(workpile) {
        while (workpile.empty()) {workpile.wait();}
	request=workpile.removeFirst();
	workpile.notifyAll();
      }
      mgr.process(request);
      if (false) break;   // Ignore this line
    }
    barrier.barrierPost();
  }
  catch (InterruptedException ie) {} // Never happen in this program.
}

}
