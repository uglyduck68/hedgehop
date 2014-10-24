//              ServerRMI/Client.java

import Extensions.*;
import java.rmi.*;
import java.rmi.server.*;


public class Client  {
  static boolean                DEBUG = false;
  static String                 name;
  static int                    nCalls = 100, nTopics = 1;
  static int                    nThreads = 2;
  static int                    clientDelay = 10;
  static SingleBarrier          barrier;
  static boolean                KILL = false;


public static void main(String[] argv) {
  ClientListenerImpl c=null;

  long startTime = System.currentTimeMillis();
  name = "Client_" + (1000 +startTime%1000);

  if (System.getSecurityManager() == null)
    System.setSecurityManager(new RMISecurityManager());
  if (argv.length > 0) nCalls = Integer.parseInt(argv[0]);
  if (argv.length > 1) nThreads = Integer.parseInt(argv[1]);
  if (argv.length > 2) clientDelay = Integer.parseInt(argv[2]);
  if (argv.length > 3) nTopics = Integer.parseInt(argv[3]);
  if (System.getProperty("DEBUG") != null) DEBUG = true;
  if (System.getProperty("KILL") != null) KILL = true;
  System.out.println(name + "(nCalls: " + nCalls + " nThreads: "
                     + nThreads + " clientDelay: " + clientDelay
                     + " nTopics: " + nTopics + ")");

  barrier = new SingleBarrier(nThreads);
  

  try {c=new ClientListenerImpl(name);}
  catch (Exception re) {System.out.println(re);System.exit(1);}
    
  for (int i=0; i<nThreads; i++) {
    Thread t = new Thread(new ClientRunner(barrier), "ClientRunner" + i);
    t.start();
  }

  new Thread(new ReporterClient(), "ReporterClient").start();

  if (KILL) new Thread(new Killer(120)).start();    
  barrier.barrierWait();
  c.unregister();
 
  System.out.println(name +" finishing"  + ". \tProcessed " + ClientListenerImpl.nProcessed +
		     " requests. " + ClientListenerImpl.nListeners +
		     " listeners. "+ ClientListenerImpl.nSubscriptions +
		     " subscriptions. "+ ClientListenerImpl.nTopics +
		     " topics.");
  System.exit(0);
}


}
