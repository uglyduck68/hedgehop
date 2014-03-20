//              ServerInterruptible/Request.java

import java.io.*;
import java.net.*;
import Extensions.*;


public class Request {
 Client                 client;
 byte[]                 bytes;
 Thread                 self;
 String                 string = "";
 int                    count;
 static final int       MessageLength = 70;
 static int             total = 0;



public String toString() {
  int                   i = string.indexOf(0);  // Find end-of-string.

  if (i<1) i=1;
  return("<Request: " + client + " " + self.getName() + " '"
         + string.substring(0, i) + "'>");
}



public Request(Client s, byte[] b) {
  client = s;
  bytes = b;
  self = Thread.currentThread();
  string = new String(b, 0);

  synchronized (Request.class) {count = ++total;}

  if (Server.DEBUG)
    System.out.println("Server[" + self.getName()
		                 + "]\tCreated: " + this);
  if (((count % 1000) == 0) && Server.DEBUG)
    System.out.println("Server[" + self.getName() + "]\tCreated: "
                       + count + " requests.");
}




public void process() {
  Thread                self =  Thread.currentThread();

  try {
    byte reply[] = new byte[MessageLength];
    String s = new String(bytes, 0);
    s = "[Server " + self.getName() + "] Reply: " + count + " to: " + s;
    s.getBytes(0, MessageLength-1, reply, 0);
    InterruptibleThread.sleep(Server.delay);
    client.os.write(reply);
    client.decrementOutstandingRequests();

    if ((count % 1000) == 0)
      System.out.println("Server[" + self.getName()
                         + "]\tProcessed: " + count + " requests.");
    if (Server.DEBUG)
      System.out.println("Server[" + self.getName()
			 + "]\tProcessed: " + this);
  }
  catch (InterruptedIOException e) {            // Log failure, then ignore.
    System.out.println(e + " in request.process().");
  }
  // A consumer *may* still be working on requests for a client that
  // has been closed! (Shouldn't happen.)
  catch (IOException e) {               // Log failure, then ignore it.
    System.out.println(e + " in request.process().");
  }
}

}
