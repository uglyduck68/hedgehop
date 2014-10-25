//              ServerInterruptible/Server.java

/*
  A simple server program.  It sets up a TCP port for the client
  program to connect to. Then it accepts connections, spawning a
  new producer thread for each. (Java has no "select()" function.)

  It starts up nConsumers consumer threads to pull requests off the
  list and process them, sending a reply string back to the client.

  Any IO failures are handled by printing out an error message, closing
  the socket in question, then ignoring it.  Check out the location of
  the exception handlers and which methods throw exceptions. This is
  carefully designed and *should* be fully robust.

  This version is really just a producer/consumer program that happens
  to run across a socket.

  Unlike the StopQueueSolution which has the consumer threads exit at
  stop time (that was done for the illustration of synchronization), this
  program simply stops accepting new requests, closing the socket as soon
  as the final reply has been issued. The Client program is sent an "End"
  message then, and left to its own devices to deal with the fact that the
  socket has been closed.

  This program uses InterruptedIOException, hence MUST be compiled under
  Java 2.
*/


import java.io.*;
import java.net.*;
import Extensions.*;



public class Server {
  ServerSocket          port;                   // reading from  port
  static int            portNumber = 6500;
  static int            delay = 50;             // Sleep time / Request (ms)
  static int            spin = 10;              // CPU-spin time (us)
  static boolean        DEBUG = false;
  static int            nConsumers = 10;
  static int            MAX_OPEN = 1000;        // Max open file descriptors
  static int            outstandingClients = 0;
  static Workpile       workpile;
  static Thread[]       consumers;
  static Thread[]       producers;
  static int            nProducers=0;           // # active clients
  static int            stopperTimeout = 10;    // 10s
  static int            killerTimeout = 120;    // 2min
  static boolean        KILL = false; 
  static Thread         acceptor;               // Thread doing accept()


public static void main(String[] args) {
  Server                server = new Server();

  if (args.length > 0) portNumber  =    Integer.parseInt(args[0]);
  if (args.length > 1) delay =          Integer.parseInt(args[1]);
  if (args.length > 2) spin =           Integer.parseInt(args[2]);
  if (args.length > 3) nConsumers =     Integer.parseInt(args[3]);
  if (args.length > 4) stopperTimeout = Integer.parseInt(args[4]);
  if (args.length > 5) killerTimeout =  Integer.parseInt(args[5]);
  if (System.getProperty("DEBUG") != null) DEBUG = true;
  if (System.getProperty("KILL") != null) KILL = true;

  System.out.println("Server(port: " + portNumber + " delay: " + delay
                     + "ms spin: " + spin + "us nConsumers: "
                     + nConsumers + " stopperTimeout " + stopperTimeout
                     + "s killerTimeout " + killerTimeout + "s)");
  server.runServer();
}



public void runServer() { // Executes in main thread
  Socket                socket;

  if (KILL) new Thread(new Killer(120)).start();
  acceptor = Thread.currentThread();
  consumers = new Thread[nConsumers];
  producers = new Thread[MAX_OPEN];
  workpile = new Workpile();
  for (int i = 0; i < nConsumers; i++) {
    consumers[i] = new Thread(new Consumer(workpile));
    consumers[i].start();
  }

  for (int i = 0; i < 3; i++) {         // Main start/stop loop
    try {
      port = new ServerSocket(portNumber);
      System.out.println("\n=========================================");
      System.out.println("Server now listening on port " + portNumber);

      nProducers=0;
      new Thread(new Stopper(workpile, stopperTimeout)).start();
      for (int j=0; true; j++) {        // New client loop
        try {
          socket = port.accept();
          Client client = new Client(socket);
          synchronized (this) {waitIfTooManyClients();}
          Thread t = new Thread(new Producer(this, client));
          t.start();
          producers[j]=t;
          nProducers=j+1;
          System.out.println("Server[" + t.getName()
                             + "]\tStarted new client: " + client);
        }
        catch (IOException ie) {          // Naming clear in Java 1.2?
          synchronized (workpile) {
            System.out.println("Acceptor " + ie);
            Thread.interrupted();   //SocketException does NOT clear flag!
            if (workpile.stop) break;   // stop better be true!
            System.out.println("Impossible bug! Stop must be true.");
            System.exit(-1);
          }
        }
      }                                 // End of new client loop
      port.close();
      waitForOutstandingClients();
      System.out.println("Server shutdown complete.");
      InterruptibleThread.sleep(2000);  // "Feels" better to delay here.
      workpile.stop=false;
    }
    catch (IOException e) {     // Log failure, then die.
      System.out.println("Exiting on " + e);
      System.exit(-1);
    }
  }                                     // End of start/stop loop
  System.out.println("Exiting normally.");
  System.exit(-1);  
}




public Server() {
}



public synchronized void incrementOutstandingClients() {
  outstandingClients++;
}

  
  
public synchronized void decrementOutstandingClients() {
  outstandingClients--;
  if ((outstandingClients == 0) || (outstandingClients == MAX_OPEN-1))
    notifyAll();                // In case someday there's more than 1.
}


  
public synchronized void waitForOutstandingClients() {
  boolean                       interrupted=false;

  while (outstandingClients != 0) {
    try {wait();} 
    catch (InterruptedException e) {interrupted = true;}
  }
  if (interrupted) Thread.currentThread().interrupt();
}


 
public void waitIfTooManyClients() { // NOT synchronized!
  boolean                       interrupted=false;

  while (outstandingClients == MAX_OPEN) {
    try {wait();} 
    catch (InterruptedException e) {interrupted = true;}
  }
  if (interrupted) Thread.currentThread().interrupt();
}
}
