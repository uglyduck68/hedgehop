//              ServerSelect/Server.java

/*
  A robust server program. This uses a direct JNI call down to select()
  in C, which in turn handles many clients (CLIENT_MAX) from a single
  call. The C function get_request() will return a NativeRequest
  object which is either a normal request, a notification of a new
  client connection, or an error condition.

  To reduce communications across the JVM, duplicate client structures
  are kept in both Java and C. Only Strings, NativeRequests, and ints
  are sent. An error received in C will inactivate the client, but it's
  left to Java to request the actual close().

  Java starts up nConsumers consumer threads to pull requests off the
  list and process them, sending a reply string back to the client.

  At shutdown time, the stopper thread sets workpile.stop=true; does a
  notifyAll(), and calls down to C to set a similar stop flag there. C
  also will send a message to a pipe which select() is listening to. This
  guarantees that get_request() will return promptly.

  This is based on a similar program in C, server_select.c.

*/

import java.io.*;
import java.net.*;
import Extensions.*;



public class Server {
  ServerSocket          port;
  static int            portNumber = 6500;
  static int            ActualPortNumber = 6500;
  static int            delay = 50;
  static int            spin = 10;
  static boolean        DEBUG = false;
  static boolean        DEBUG2 = false;		/* More debugging info. */
  static int            nConsumers = 10;
  static boolean        KILL = false;
  static int            stopperTimeout = 100;
  static int		CLIENT_MAX=1024;
  static int		CLIENT_INTERRUPTOR = 0;
  static int		CLIENT_PORT_SOCKET = 1;
  static int		CLIENT_OVERFLOW = 2;



public static void main(String[] args) {
  Server                server = new Server();
  Thread                t;

  if (args.length > 0) portNumber  =    Integer.parseInt(args[0]);
  if (args.length > 1) delay =          Integer.parseInt(args[1]);
  if (args.length > 2) spin =           Integer.parseInt(args[2]);
  if (args.length > 3) nConsumers =     Integer.parseInt(args[3]);
  if (args.length > 4) stopperTimeout = Integer.parseInt(args[4]);
  if (System.getProperty("DEBUG") != null) DEBUG = true;
  if (System.getProperty("DEBUG2") != null) DEBUG2 = true;
  if (System.getProperty("KILL") != null) KILL = true;

  System.out.println("Server(port: " + portNumber + " delay: " + delay
                     + "ms spin: " + spin + "us nConsumers: "
                     + nConsumers + " stopperTimeout " + stopperTimeout
                     + "s)");

  if (KILL) new Thread(new Killer(120)).start();
  server.runServer();
}



public void runServer() { // Executes in main thread
  Socket                socket;
  Workpile              workpile = new Workpile();


  workpile.barrier = new SingleBarrier(nConsumers+1);
    new Thread(new Reporter()).start();

  for (int j = 0; j<10; j++) {
    ActualPortNumber = NativeSelect.initializePort(portNumber);
    System.out.println("Server now listening on port " + ActualPortNumber);

    for (int i = 0; i < nConsumers; i++) {
      new Thread(new Consumer(workpile)).start();
    }

    new Thread(new Producer(workpile)).start();
    new Thread(new Stopper(workpile, stopperTimeout)).start();
    workpile.barrier.barrierWait();
    System.out.println("Everything stopped.\n\n"); 
    Client.reset();
    workpile.stop=false;
    NativeSelect.setStop(false);
  }
  System.out.println("Server exiting normally.\n\n");
  System.exit(0);
}
  

public Server() {
}

}
