//              ServerSelect/Reporter.java

import java.io.*;
import java.net.*;
import Extensions.*;



public class ReporterClient implements Runnable {
  long                  startTime= System.currentTimeMillis();
  int                   delay = 10; // 30 seconds
  int			previousProcessed = -1, previousClients =-1;


public ReporterClient() {
}


public void run() {
  if (Server.DEBUG) System.out.println("Reporter starting...");

  while (true) {
    InterruptibleThread.sleep(delay*1000);
    long time = (System.currentTimeMillis() - startTime)/1000;
    if ((previousProcessed == ClientListenerImpl.nProcessed) &&
	(previousClients == ClientListenerImpl.nListeners))
      System.out.print(".");
    else
      System.out.println(Client.name + " up at " + time + ". \tProcessed "
			 + ClientListenerImpl.nProcessed +
			 " requests. " + ClientListenerImpl.nListeners +
			 " listeners. "+ ClientListenerImpl.nSubscriptions +
			 " subscriptions. "+ ClientListenerImpl.nTopics +
			 " topics.");
    previousProcessed = ClientListenerImpl.nProcessed;
    previousClients = ClientListenerImpl.nListeners;
  }
}
}
