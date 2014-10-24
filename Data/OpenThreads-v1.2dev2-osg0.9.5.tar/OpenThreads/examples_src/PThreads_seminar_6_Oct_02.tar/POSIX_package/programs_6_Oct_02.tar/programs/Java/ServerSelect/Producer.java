//              ServerSelect/Producer.java

import java.io.*;
import Extensions.*;


public class Producer implements Runnable {
  Workpile                      workpile;

  
public Producer(Workpile w) {
  workpile = w;
}


  
public void run() {
  String selfName = Thread.currentThread().getName();
  Request request;
  
  if (Server.DEBUG) System.out.println("Producer starting...");
  
try {
    for (int i = 0; true; i++) {
      request = NativeSelect.getRequest();
      Client client = request.client;
      
      if (request.string.startsWith("New"))
	client.activate();

      else {       
	synchronized (workpile) {
	  while (workpile.full() && !workpile.stop) {workpile.wait();}
	  if (request.string.startsWith("STOP"))
	    client.decrementOutstandingRequests();
	  else
	    workpile.add(request);
	  if (workpile.stop) {
	    Client.clients[1].close(); /* Port */
	    if (Server.DEBUG) System.out.println("Producer exiting...");
	    workpile.barrier.barrierPost();
	    return;
	  }
	  workpile.notifyAll();
	}    
      }
    }
  }
  catch (InterruptedException e) {
    System.out.println("Impossible " + e);
  }
  catch (IOException e) {               // Log failure, then ignore it.

    System.out.println("Server[" + selfName +
                       "]\tException during processing." + e);
    return;
  }
}

}
