//              ServerSelect/Reporter.java

import java.io.*;
import java.net.*;
import Extensions.*;



public class Reporter implements Runnable {
  long                  startTime= System.currentTimeMillis();
  int                   delay = 30; // 30 seconds
  int			previousProcessed = -1, previousClients =-1;


public Reporter() {
}


public void run() {
  if (Server.DEBUG) System.out.println("Reporter starting...");

  while (true) {
    InterruptibleThread.sleep(delay*1000);
    long time = (System.currentTimeMillis() - startTime)/1000;
    if ((previousProcessed == BBoardMgrImpl.nProcessed) &&
	(previousClients == BBoardMgrImpl.nListeners))
      System.out.print(".");
    else
      System.out.println("Server up at " + time + ". Processed " + BBoardMgrImpl.nProcessed +
			 " requests. " + BBoardMgrImpl.nListeners +
			 " listeners. "+ BBoardMgrImpl.nSubscriptions +
			 " subscriptions. "+ BBoardMgrImpl.nTopics +
			 " topics.");
    previousProcessed = BBoardMgrImpl.nProcessed;
    previousClients = BBoardMgrImpl.nListeners;
  }
}
}
