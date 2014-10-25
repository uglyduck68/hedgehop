//              ServerProducerConsumer/Server.java

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

*/

import java.io.*;
import java.net.*;
import Extensions.*;



public class Server {
  ServerSocket          port;
  static int            portNumber = 6500;
  static int            delay = 50;
  static int            spin = 10;
  static boolean        DEBUG = false;
  static boolean        KILL = false;
  static int            nConsumers = 10;



public static void main(String[] args) {
  Server                server = new Server();
  Thread                t;
  int                   stopperTimeout = 10; // 10s

  if (args.length > 0) portNumber  =    Integer.parseInt(args[0]);
  if (args.length > 1) delay =          Integer.parseInt(args[1]);
  if (args.length > 2) spin =           Integer.parseInt(args[2]);
  if (args.length > 3) nConsumers =     Integer.parseInt(args[3]);
  if (args.length > 4) stopperTimeout = Integer.parseInt(args[4]);
  if (System.getProperty("DEBUG") != null) DEBUG = true;
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
  Thread		t;
  try {
    port = new ServerSocket(portNumber);
    System.out.println("Server now listening on port " + portNumber);

    for (int i = 1; i < nConsumers; i++) {
      t = new Thread(new Consumer(workpile));
      t.start();
    }

    for (int i = 0; true; i++) {
      socket = port.accept();
      Client client = new Client(socket);
      t = new Thread(new Producer(workpile, client), "Producer_"+i);
      t.start();
      System.out.println("Server[" + t.getName()
                         + "]\tStarted new client: " + client);
    }
  }
  catch (IOException e) {       // Log failure, then ignore it.
    System.out.println("Cannot get I/O streams in new Client()" + e);
  }
}


public Server() {
}

}
