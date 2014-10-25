//              ServerSelect/Reporter.java

import java.io.*;
import java.net.*;
import Extensions.*;



public class Reporter implements Runnable {
  int                   delay = 30; // 30 seconds
  int			previousProcessed = -1, previousClients =-1;


public Reporter() {
}


public void run() {
  if (Server.DEBUG) System.out.println("Reporter starting...");

  while (true) {
    InterruptibleThread.sleep(delay*1000);
    if ((previousProcessed == Request.totalProcessed) &&
	(previousClients == Client.total))
      System.out.print(".");
    else
      System.out.println("Server up on port " + Server.ActualPortNumber +
			 ". Processed " + Request.totalProcessed +
			 " requests. " + Client.total +
			 " clients.");
    previousProcessed = Request.totalProcessed;
    previousClients = Client.total;
  }
}
}
