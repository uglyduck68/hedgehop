//              OneQueueProblem/Consumer.java

import java.io.*;
import Extensions.*;

public class Consumer implements Runnable {
  Workpile              workpile;
  SingleBarrier         barrier;

public Consumer(Workpile w, SingleBarrier b) {
  workpile = w;
  barrier= b;
}


public void run() {
  Request               request;

  try {
    while (true) {
      synchronized (workpile) {
        while (workpile.empty()) {workpile.wait();}
        request = workpile.removeFirst();
	workpile.notify();
      }
      request.process();
      if (false) break;			// Ignore this line!
    }
    barrier.barrierPost();
  } 
  catch (InterruptedException ie) {System.out.println("Impossible!");}
}
}
