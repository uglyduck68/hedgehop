//              ServerSelect/Request.java

import java.io.*;
import java.net.*;
import Extensions.*;


public class Request {
  Client                client;
  Thread                self;
  String                string = "";
  int                   count;
  static final int      MessageLength = 70;
  static int            totalCreated = 0;
  static int            totalProcessed = 0;
public static String    END =
"End                                                                   ";



public String toString() {
  int                   i = string.indexOf(0);  // Find end-of-string.

  if (i<1) i=1;
  return("<Request: " + client + " " + self.getName() + " '"
         + string.substring(0, i) + "'>");
}



public Request(Client c, String s) {
  client = c;
  self = Thread.currentThread();
  string = s;

  client.incrementOutstandingRequests();
  synchronized (Request.class) {count = ++totalCreated;}
  if ((client.name.startsWith("Inactive")) || 
      (client.name.startsWith("New")))
    {client.name=string.substring(0, 12);}
  if (Server.DEBUG)
    System.out.println("Server[" + self.getName()
		       + "]\tCreated: " + this);
}




public void process() {
  Thread                        self =  Thread.currentThread();
  int                         	i, err=0;
  String 			reply;
      
    if (string.startsWith("End")) {
      synchronized(client) {client.finishing=true;}
    }
    else {
      reply= "[Server " + self.getName() + "] Reply: " +
	count + " to: " + string;
      InterruptibleThread.sleep(Server.delay);
      err = client.write(reply);
    }

  i=client.decrementOutstandingRequests();

  if (err == -1) {
    client.close();
    System.out.println("Error writing to " + client + ". Closed socket.");
  }

  synchronized(client) {
    if (client.finishing && i==0) {
      // Send "End" right back to client.  We're done!
      client.write(END); 
      client.close();
      if (Server.DEBUG)
	System.out.println("Server[" + self.getName() +
			   "]\tCompleted processing " + client + ".");
    }
  }


  synchronized(Request.class) {totalProcessed++;}

  if ((totalProcessed % 1000) == 0)
      if (Server.DEBUG)
    System.out.println("Server[" + self.getName()
		       + "]\tProcessed: " + count + " requests.");

  if (Server.DEBUG)
    System.out.println("Server[" + self.getName()
		       + "]\tProcessed: " + this);
}

}
