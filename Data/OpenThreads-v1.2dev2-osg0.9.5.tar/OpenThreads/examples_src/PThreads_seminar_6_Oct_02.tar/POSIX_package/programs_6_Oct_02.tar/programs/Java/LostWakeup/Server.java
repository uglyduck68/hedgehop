//              StopQueueSolution/Server.java

import java.io.*;
import Extensions.*;


public class Server {
  int pcounter = 0;
  int ccounter = 0;
  boolean DEBUG = false;
  int cDelay = 500, pDelay = 10;
  Workpile workpile;


public Server(boolean debug, int c, int p, Workpile w) {
  DEBUG = debug;
  cDelay = c;
  pDelay = p;
  workpile = w;
}

public Item get()  {
  Item item;

  synchronized (this) {item = new Item(pcounter++);}
  if (DEBUG)
    System.out.println(Thread.currentThread().getName() +
                       "  \t returning new \t" + item.toString() +
                       "  \t Length: " + workpile.size());
//   InterruptibleThread.sleep(pDelay);
  return(item);
}

public void process(Item item)  {

  {
    synchronized (this) {ccounter++;}
    if (DEBUG)
      System.out.println(Thread.currentThread().getName() +
                         "   \t processing \t" + item.toString() +
                          "  \t Length: " + workpile.size());
//     InterruptibleThread.sleep(cDelay);
  }

}
 
}
