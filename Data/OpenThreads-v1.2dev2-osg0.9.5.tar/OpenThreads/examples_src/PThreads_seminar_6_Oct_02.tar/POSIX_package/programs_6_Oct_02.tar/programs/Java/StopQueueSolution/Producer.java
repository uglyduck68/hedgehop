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
	while (workpile.full() && !workpile.stop) {workpile.wait();}
	workpile.add(request);
	if (workpile.stop) break;
	workpile.notify();
      }
    }
    barrier.barrierPost();
  } 
  catch (InterruptedException ie) {System.out.println("Impossible!");}
}
}
