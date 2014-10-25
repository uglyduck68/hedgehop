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
        while (workpile.empty() && !workpile.stop) {workpile.wait();}
	if (workpile.stop) break;
        request = workpile.removeFirst();
	workpile.notify();
      }
      request.process();
    }
    barrier.barrierPost();
  } 
  catch (InterruptedException ie) {System.out.println("Impossible!");}
}
}
