//              OneQueueProblem/Request.java

import java.io.*;
import java.net.*;
import Extensions.*;


public class Request {
Client          client;
Thread          self;
String          string = "";
int             count;
static int      totalProduced = 0;
static int      totalConsumed = 0;


public String toString() {
  return("<Request: " + count + " " + client + " " + self.getName() + ">");
}


public Request(Client c) {
  client = c;
  String name = Thread.currentThread().getName();

  self = Thread.currentThread();

  synchronized (Request.class) {count = ++totalProduced;}
  if (Server.DEBUG)
    System.out.println("Server[" + name + "]\tCreated:   " + this);
  if (((count % 1000) == 0) && Server.DEBUG)
    System.out.println("Server[" + name + "]\tCreated: "
                       + count + " requests.");
}


public void process() {
  String name = Thread.currentThread().getName();

  InterruptibleThread.sleep(Server.cDelay);
  synchronized (Request.class) {count = ++totalConsumed;}
  if ((totalConsumed % 1000) == 0)
    System.out.println("Server[" + name
                       + "]\tProcessed: " + count + " requests.");
  if (Server.DEBUG)
    System.out.println("Server[" + name + "]\tProcessed: " + this);
}
}
