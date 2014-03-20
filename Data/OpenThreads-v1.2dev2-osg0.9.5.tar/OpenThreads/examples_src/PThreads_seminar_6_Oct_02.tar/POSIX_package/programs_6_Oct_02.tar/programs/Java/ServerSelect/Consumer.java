//              ServerSelect/Consumer.java

import java.io.*;
import Extensions.*;



public class Consumer implements Runnable {
  Workpile                      workpile;



public Consumer(Workpile w) {
  workpile = w;
}



public void run() {
  Request request;

  if (Server.DEBUG) System.out.println("Consumer starting...");

  try {
    while (true) {
      synchronized (workpile) {
	while (workpile.empty() && !workpile.stop) {workpile.wait();}
	if (workpile.empty() && workpile.stop) {	/*Empty it first */
	  workpile.barrier.barrierPost();
	    if (Server.DEBUG) System.out.println("Consumer exiting...");
	  return;
	}
	request = workpile.removeFirst();
	workpile.notifyAll();
      }
      request.process();
    }
  }
  catch (InterruptedException e) {
    System.out.println("Impossible in Consumer.run() " + e);
  }
}

}
