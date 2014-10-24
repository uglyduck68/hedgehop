//              ServerInterruptible/Client.java

import java.io.*;
import java.net.*;


public class Client {
public int              outstandingRequests = 0;
public Socket           socket;
public InputStream      is;
public OutputStream     os;
public int              delay = 10;
public int              count = 0;
public static int       total = 0;
public int              MessageLength = 70;

  


public String toString() {
  return("<Client: " + count + ">");
}



public Client(Socket s) throws IOException {
  try {
    socket = s;
    is = socket.getInputStream();
    os = socket.getOutputStream();
    synchronized (Client.class) {
      total++;
      count = total;
    }
  }
  catch (IOException ie) {      // Included for illustration/debugging
    System.out.println(ie + " in new Client()");
    throw ie;    
  }
}
  


public Request read() throws InterruptedIOException, IOException {
  byte[] b = new byte[MessageLength];

  try {
    int n = is.read(b);
    if (n == -1)
      throw new IOException(this + " reading from closed socket??");
    if (n != MessageLength) 
      throw new IOException(this + " read too few characters " + n);
    incrementOutstandingRequests();
    return new Request(this, b);
  }
  catch (IOException ie) {      // Included for illustration/debugging
    System.out.println(ie + " in client.read()");
    throw ie;    
  }
}



// Methods something like these might be useful...  :-)

public synchronized void incrementOutstandingRequests() {
  outstandingRequests++;
}
  
  
public synchronized void decrementOutstandingRequests() {
  outstandingRequests--;
  if (outstandingRequests == 0)
    notifyAll();                // In case someday there's more than 1.
}

  
public synchronized void waitForOutstandingRequests() {
  boolean interrupted=false;

  while (outstandingRequests != 0) {
    try {wait();} 
    catch (InterruptedException e) {interrupted = true;}
  }
  if (interrupted) Thread.currentThread().interrupt();
}

}
