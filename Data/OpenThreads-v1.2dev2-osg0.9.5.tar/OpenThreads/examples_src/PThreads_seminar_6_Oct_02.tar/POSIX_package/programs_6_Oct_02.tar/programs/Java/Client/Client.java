//              Client/Client.java

/*
  This client program opens a socket on a port (6500 by default) and
  sends a bunch of "requests" across it, waiting for replies.  A
  request looks like this: "[Client Thread-4] Request: 99" (padded to
  70 chars).  The server then sends a reply that looks like this:
  "[Server Thread-5] Reply: 200 to: [Client Thread-4] Request: 99"
  (also 70 chars).

  The requests are sent out by one thread and then another thread
  waits for the replies.  Any number of sockets may be opened,
  with pairs of threads to send and receive.  (More than MAX_OPEN
  <limits.h> will exceed the Solaris limit of open fds. Don't do that.)

  This works equally well with a server written in C.  (See Bil's
  Pthreads course.)
 */


import java.io.*;
import java.util.*;
import java.net.*;
import Extensions.*;


public class Client implements Runnable {

public Socket           clientSocket;
public static int       portNumber = 6500;      // Always >= 6500
public static int       actualPortNumber = 6500;
public static String    host = "127.0.0.1";     // Loopback address
public static int       sDelay = 1;             // Sender Delay
public static int       rDelay = 1;             // Receiver Delay
public static boolean   DEBUG = false;
public static int       nClients = 1;
public static int       nRequests = 1000;
public static final int MessageLength = 70;
public OutputStream     os;
public InputStream      is;
public String           type;                   // Sender or Receiver
public int              outstandingRequests=0;
public Client           sender;
public static String    END =
"End\0                                                                  ";
public static String    pad =                   // Terminate & add spaces
"\0                                              ";


public static void main(String[] args) {
  Client client = new Client("Initial", null, null);

  if (args.length > 0) portNumber  =    Integer.parseInt(args[0]);
  if (args.length > 1) sDelay =         Integer.parseInt(args[1]);
  if (args.length > 2) rDelay =         Integer.parseInt(args[2]);
  if (args.length > 3) nClients =       Integer.parseInt(args[3]);
  if (System.getProperty("DEBUG") != null) DEBUG = true;
  System.out.println("Client(port: " + portNumber + " sDelay: " + sDelay
                     + " (ms) rDelay: " + rDelay + " (ms) nClients: "
                     + nClients + ")\n");
  client.runServer();
}


public void runServer() {                // Executes in main thread
  boolean first = true;
  for (int i = 0; i < nClients; i++) {
   
      mainloop: while (true) {
      for (int j= portNumber; j < portNumber+100; j++) {
	try {
	  clientSocket = new Socket(host, j);
	  actualPortNumber = j;
	  if (j!=portNumber && first) {
	    System.out.println("Actual Port: " + j);
	    first = false;
	  }
	  break mainloop;
	}
	catch  (IOException e) {
	  if (DEBUG) System.out.println("Could not connect to "+j);
	}
      }
      System.out.println("Could not connect at all. Try again in 5s.");
      InterruptibleThread.sleep(5000);
    }
    Client sender = new Client("Sender", clientSocket, null);
    Thread t = new Thread(sender);
    t.start();
    Client receiver = new Client("Receiver", clientSocket, sender);
    t = new Thread(receiver);     
    t.start();
  }
}
  



public Client(String s, Socket soc, Client c) {
  type = s; clientSocket = soc; sender = c;
}



public void run() {
  if (type == "Sender")
    runSender();
  else
    runReceiver();
}



public void runSender() {
  byte[]        bytesOut;  
  String        selfName = Thread.currentThread().getName();

  System.out.println("Client[" + selfName + "]\tStarted new sender.");
    
  try {
    os = clientSocket.getOutputStream();
    for (int i = 1; i<=nRequests; i++) {
      String sOut = "[Client " + selfName + "] Request: " + i + pad;
      bytesOut=sOut.substring(0, MessageLength).getBytes();
      os.write(bytesOut);
      synchronized (this) {outstandingRequests++;}

      if ((i % 100) == 0)
        System.out.println("Client[" + selfName
                           + "]\tSent: " + i + " requests.");
      if (DEBUG) {
        int i1 = sOut.indexOf(0);
        System.out.println("Client[" + selfName + "]\tSent: '"
                           + sOut.substring(0, i1) + "'");
      }
      InterruptibleThread.sleep(sDelay);
    }
    bytesOut=END.substring(0, MessageLength).getBytes();
    os.write(bytesOut);
    synchronized (this) {outstandingRequests++;}
  }
  catch (IOException e) {               // Let it die "dirty"
    System.out.println(e + " in client.runSender(). Exiting...");
    System.exit(-1);
  }
}



public void runReceiver() {
  byte[]        bytesIn = new byte[MessageLength];
  String        selfName = Thread.currentThread().getName();
  int           n = 0;
  long          startTime = System.currentTimeMillis();

  System.out.println("Client[" + selfName +"]\tStarted new receiver.");

  try {
    is = clientSocket.getInputStream();
    for (int i = 1; true; i++) {

      n = is.read(bytesIn);
      if (n == -1)
	throw new IOException(this + " reading from closed socket??");
      if (n != MessageLength) 
	throw new IOException(this + "Read too few characters " + n);
      synchronized (sender) {sender.outstandingRequests--;}
      String sIn = new String(bytesIn);
       
      if ((i % 100) == 0)
        System.out.println("Client[" + selfName
                           + "]\tReceived: " + i + " replies.");
      if (DEBUG) {
        int i1 = sIn.indexOf(0);
        System.out.println("Client[" + selfName + "]\tGot: '"
                           + sIn.substring(0, i1) + "'");
      }

      if (sIn.startsWith("End")) {
        clientSocket.close();                   // We're done!
        if (sender.outstandingRequests == 0)
          System.out.println("Client[" + selfName +
                             "]\tCompleted processing. ");
        else
          System.out.println("Client[" + selfName + "]\tServer dropped "
                             + sender.outstandingRequests
                             + " requests.");
        break;
      }
      InterruptibleThread.sleep(rDelay);
    }
    long endTime = System.currentTimeMillis();
    System.out.println("Client[" + selfName + "]\tTotal runtime: "
                       + (endTime-startTime)/1000);
  }
  
  catch (IOException e) {               // Let it die "dirty"
    System.out.println(e + " in client.runReceiver(). Exiting...");
    System.exit(-1);
  }
}

}
