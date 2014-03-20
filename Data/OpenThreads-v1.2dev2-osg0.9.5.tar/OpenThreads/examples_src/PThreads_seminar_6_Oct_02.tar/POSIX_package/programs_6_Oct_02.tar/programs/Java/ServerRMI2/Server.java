//              ServerRMI/Server.java

/*
  A simple RMI server program.  It sets up a registry name for the client
  program to connect to. It creates an unknown number of threads FOR you,
  exiting them when it feel like it.
  
*/


import java.rmi.*;
import java.rmi.server.*;
import Extensions.*;


public class Server {
  static int                    serverDelay = 50;
  static boolean                DEBUG = false;
  static boolean                KILL = false;
  

public static void main(String[] argv) throws Exception {
  Thread                        t;

  if (System.getSecurityManager() == null)
        System.setSecurityManager(new RMISecurityManager());
  if (argv.length > 0) serverDelay = Integer.parseInt(argv[0]);
  //  if (System.getProperty("DEBUG") != null) DEBUG = true;
  if (System.getProperty("KILL") != null) KILL = true;
  System.out.println("Server(serverDelay: " + serverDelay + ")");

  if (KILL) new Thread(new Killer(120)).start();
    
  Naming.rebind("Frobber", new ServerImpl());
  System.out.println("Server: 'Frobber' now registered with rmiregistry.");
}

}
  
