//              ServerInterruptible/Producer.java

import java.io.*;
import Extensions.*;

public class Producer implements Runnable {
public Workpile         workpile;
public Client           client;
public Server           server;
public static String    END =
"End                                                                   ";
public final int        MessageLength = 70;
public byte[]           END_BYTES = new byte[MessageLength];

  
public Producer(Server s, Client c) {
  server = s;
  workpile = server.workpile;
  client = c;
  END.getBytes(0, MessageLength-1, END_BYTES, 0);
}


  
public void run() {
  String                selfName = Thread.currentThread().getName();

  server.incrementOutstandingClients();
  for (int i = 0; true; i++) {
    try {
      Request request = client.read();
      if (request.string.startsWith("End")) {
        client.decrementOutstandingRequests();
        client.waitForOutstandingRequests();

        // Send "End" right back to client.  We're done!
        client.os.write(END_BYTES); 
        client.socket.close();
        System.out.println("Server[" + selfName + "]\tCompleted processing.");
        break;
      }
            
      synchronized (workpile) {
        while (workpile.full() && !workpile.stop) {workpile.wait();}
        workpile.add(request);
        workpile.notifyAll();
        if (workpile.stop) break;
      }
    }
    catch (InterruptedException e) {
      System.out.println(e + " in producer.run() for " + client);
      synchronized (workpile) {if (workpile.stop) break;}
      System.out.println("Impossible in producer.run(). Stop must be true!");
    }

    catch (InterruptedIOException e) {
      System.out.println(e + " in producer.run() for " + client);
      synchronized (workpile) {if (workpile.stop) break;}
      System.out.println("Impossible in producer.run(). Stop must be true!");
    }
    catch (IOException e) {             // Log failure, then ignore it.
      System.out.println(e + "in producer.run().");
      break;
    }
  }

  client.waitForOutstandingRequests();
  try {
    client.os.write(END_BYTES);
    client.socket.close();
  }
  catch (IOException ioe) {}

  server.decrementOutstandingClients();
  System.out.println("Server[" + selfName + "] exiting from producer.run().");
  return;
} 
  
}
