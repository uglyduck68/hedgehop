//              ServerProducerConsumer/Request.java

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
  String msg;
  String topic;



public String toString() {
  return("<Request: " + count + " " + client + " " + self.getName() + ">");
}



public Request(String topic, String msg) {
  self = Thread.currentThread();

  this.msg = msg;
  this.topic = topic;

  synchronized (Request.class) {count = ++totalProduced;}
  if (Server.DEBUG)
    System.out.println("Server[" + self.getName() + "]\tCreated: " + this);
}



}
