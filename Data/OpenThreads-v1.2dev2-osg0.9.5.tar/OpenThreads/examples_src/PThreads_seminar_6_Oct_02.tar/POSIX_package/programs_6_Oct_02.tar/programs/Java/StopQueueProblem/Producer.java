//              OneQueueProblem/Producer.java

import java.io.*;
import Extensions.*;

public class Producer implements Runnable {
  Workpile      workpile;
  SingleBarrier barrier;
  Client        client;


public Producer(Workpile w,  Client c, SingleBarrier b) {
  workpile = w;
  client = c;
  barrier= b;
}


public void run() {
  Request request;

  try {
    while (true) {
      request = client.read();
      synchronized(workpile) {
	while (workpile.full()) {workpile.wait();}
	workpile.add(request);
	workpile.notify();
      }
      if (false) break;			// Ignore this line!
    }
    barrier.barrierPost();
  } 
  catch (InterruptedException ie) {System.out.println("Impossible!");}
}
}
