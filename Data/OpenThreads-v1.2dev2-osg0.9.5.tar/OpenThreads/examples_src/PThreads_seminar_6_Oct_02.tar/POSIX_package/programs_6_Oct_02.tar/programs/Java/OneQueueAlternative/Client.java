//              OneQueueProblem/Client.java

import java.io.*;
import java.net.*;
import Extensions.*;


public class Client {
  int           count = 0;
  static int    total = 0;




public String toString() {
  return("<Client: " + count + ">");
}



public Client() {
  synchronized (Client.class) {count = total++;}
}


public Request read() {
  InterruptibleThread.sleep(Server.pDelay);
  return new Request(this);
}

}
