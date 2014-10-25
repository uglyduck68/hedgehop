//              ServerSimple/Producer.java

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

  try {
    for (int i = 0; true; i++) {
      Request request = client.read();
      if (request.string.startsWith("End")) {
        // Send "End" right back to client.  We're done!
        client.write(request.bytes); 
        client.close();
        System.out.println("Server[" + selfName +
                           "]\tCompleted processing.");
        return;
      }
      request.process();
    }
  }
  catch (IOException e) {
    System.out.println(e); System.exit(0);
  }
}
 

}
