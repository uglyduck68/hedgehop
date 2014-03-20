//              ServerSimple/Request.java

import java.io.*;
import java.net.*;
import Extensions.*;


public class Request {
  Client                client;
  byte[]                bytes;
  Thread                self;
  String                string = "";
  int                   count;
  static final int      MessageLength = 70;
  static int            total = 0;
  static String		spaces = "                                        ";


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
  string = new String(b);

  synchronized (Request.class) {count = ++total;}
  if (Server.DEBUG)
    System.out.println("Server[" + self.getName() + "]\tCreated:   " + this);
  if (((count % 1000) == 0) && Server.DEBUG)
    System.out.println("Server[" + self.getName() + "]\tCreated: "
                       + count + " requests.");
}




public void process() {
  Thread                        self =  Thread.currentThread();

  try {
    byte reply[];
    String s = new String(bytes);
    s = "[Server " + self.getName() + "] Reply: " + count + " to: " + s + spaces;
    s = s.substring(0, MessageLength);
    reply = s.getBytes();
    InterruptibleThread.sleep(Server.delay);
    client.write(reply);

    if ((count % 1000) == 0)
      System.out.println("Server[" + self.getName()
                         + "]\tProcessed: " + count + " requests.");

    if (Server.DEBUG)
      System.out.println("Server[" + self.getName() + "]\tProcessed: " + this);
  }
  catch (IOException e) {               // Log failure, then ignore it.
    try {client.close();} catch (IOException ioe) {}
    System.out.println("Server[" + self.getName() +
                       "]\tException during processing." + e);
  }
}

}
