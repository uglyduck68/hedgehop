//              ServerProducerConsumer/Consumer.java

import java.io.*;
import Extensions.*;



public class Consumer implements Runnable {
  Workpile                      workpile;



public Consumer(Workpile w) {
  workpile = w;
}



public void run() {
  Request request;
  
  try {
    while (true) {
      synchronized (workpile) {
	while (workpile.empty()) {workpile.wait();}
	request = workpile.removeFirst();
	workpile.notifyAll();
      }
      request.process();
    }
  }
  catch (InterruptedException ie) {System.out.println("Impossible!");}
}
}
