//              ServerProducerConsumer/Producer.java

import java.io.*;
import Extensions.*;


public class Producer implements Runnable {
  Workpile                      workpile;
  Client                        client;


  
public Producer(Workpile w, Client c) {
  workpile = w;
  client = c;
}


  
public void run() {
  String selfName = Thread.currentThread().getName();
  Request request;
  
  try {
    for (int i = 0; true; i++) {
      request = client.read();
      if (request.string.startsWith("End")) {
        client.decrementOutstandingRequests();
        client.waitForOutstandingRequests();

        // Send "End" right back to client.  We're done!
        client.write(request.bytes); 
        client.close();
        System.out.println("Server[" + selfName
			   + "]\tCompleted processing.");
        return;
      }
       
      synchronized (workpile) {
        while (workpile.full()) {workpile.wait();}
        workpile.add(request);
        workpile.notifyAll();
      }    
    }
  }
  catch (InterruptedException e) {
    System.out.println("Impossible " + e);
  }
  catch (IOException e) {               // Log failure, then ignore it.
    try {client.close();} catch (IOException ioe) {}
    System.out.println("Server[" + selfName +
                       "]\tException during processing." + e);
    return;
  }
}

}
