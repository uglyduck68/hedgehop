//              ServerSelect/Client.java

import java.io.*;
import java.net.*;


public class Client {
  boolean                       finishing = false;
  String                        name = "Inactive";
  int                           outstandingRequests = 0;
  boolean                       active = false;
  int				index;
  int                           delay = 10;
  static int                    total = 0;
  int                           MessageLength = 70;
  static Client[]		clients = new Client[Server.CLIENT_MAX];


  static {for (int i=0; i<Server.CLIENT_MAX; i++) clients[i]=new Client(i);}

  
public static Client find(int i) {
  return(clients[i]);
}

public Client() {}

public String toString() {
  return("<Client: " +name + " " + index + " A: " + active + " O: "
	 + outstandingRequests + ">");
}



public Client(int i) {
  index = i;
}



public synchronized void activate() throws IOException {
  if (index == Server.CLIENT_OVERFLOW) {
    System.out.println("Too many clients. Rejected new connection.");
    decrementOutstandingRequests();
    return;
  }
  if (active) {throw new IOException("ALREADY ACTIVE " + this);}
  active=true;
  total++;
  decrementOutstandingRequests();
  return;
}


public synchronized void incrementOutstandingRequests() {
  outstandingRequests++;
}

  
public synchronized int decrementOutstandingRequests() {
  outstandingRequests--;
  return(outstandingRequests);
}


public int write(String s) {
  int err;
  err=NativeSelect.write(s, index);
  return(err);
}

public synchronized void close() {
  NativeSelect.close(this);
  active = false;
  name = "Inactive";
  finishing = false;
  outstandingRequests = 0;
  synchronized(Client.class) {total--;}
}


public static void reset() {
  for (int i=0; i<Server.CLIENT_MAX; i++) {
    if (clients[i].active) clients[i].close();
    clients[i].active = false;
    clients[i].name = "Inactive";
    clients[i].finishing = false;
    clients[i].outstandingRequests = 0;
    total=0;
  }
}
}
