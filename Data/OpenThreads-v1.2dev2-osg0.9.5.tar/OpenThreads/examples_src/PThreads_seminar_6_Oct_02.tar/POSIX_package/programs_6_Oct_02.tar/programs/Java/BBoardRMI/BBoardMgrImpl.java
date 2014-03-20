//              ServerRMI/BBoardMgrImpl.java

import java.util.*;
import java.rmi.*;
import java.rmi.server.*;
import Extensions.*;


public class BBoardMgrImpl extends UnicastRemoteObject implements BBoardMgrOp {
  Hashtable topics = new Hashtable();
  Hashtable allListeners = new Hashtable();
  Hashtable listenerNames = new Hashtable();
  static int nListeners=0;
  static int nProcessed=0;
  static int nSubscriptions=0;
  static int nTopics=0;
  Workpile workpile;

public BBoardMgrImpl() throws RemoteException {}


public void register(ClientListenerOp l, String name)  {    
  synchronized(topics) {
    String n = (String)listenerNames.get(l);
    if (n != null) {System.out.println("Reregistering " +l+ " from " + n + " to " + name);}
    listenerNames.put(l, name);
    MyInteger i = new MyInteger();
    allListeners.put(l, i);
    nListeners++;
  }
}


public void unregister(ClientListenerOp l)  {    
  synchronized(topics) {
    String n = (String)listenerNames.get(l);
    if (n == null) {System.out.println("Unregistering " +l+ " wasn't registered");}
//    listenerNames.remove(l);
    allListeners.remove(l);
    nListeners--;
  }
}

public void subscribe(ClientListenerOp l, String topic)  {
  LinkedList listeners;

  String name = (String)listenerNames.get(l);
  if (Server.DEBUG) System.out.println("new Topic " + topic + " for " + name);

  synchronized(topics) {
    MyInteger i = (MyInteger) allListeners.get(l);
    nSubscriptions++;
    if (i == null) {
      System.out.println("Subscription w/o registeration?! " +l);
      i = new MyInteger();
      allListeners.put(l, i);
      nListeners++;
    }
    i.inc();
    
    listeners = (LinkedList) topics.get(topic);
    if (listeners == null) {
      listeners = new LinkedList();
      topics.put(topic, listeners);
    }
    if (listeners.size() == 0) {nTopics++;}
    listeners.add(l);
  }
}

public void unsubscribe(ClientListenerOp l, String topic)  {
  LinkedList listeners;

  String name = (String)listenerNames.get(l);
  if (Server.DEBUG) System.out.println("del Topic " + topic + " for " + name);

  synchronized(topics) {
    MyInteger i = (MyInteger) allListeners.get(l);
    if (i == null) {System.out.println("BUG"); return;}		// Dude ain't even here!
    i.dec();
    nSubscriptions--;
    
    listeners = (LinkedList) topics.get(topic);
    if (listeners == null) {System.out.println("BUG2"); return;}
    listeners.remove(l);
    if (listeners.size() == 0) {nTopics--;}
  }
}

  /*
public void publish(String topic, String msg) {
  String tname = "Server[" + Thread.currentThread().getName().substring(8, 22) + "]\t";
  LinkedList listeners, listeners2;

  synchronized(topics) {
    listeners = (LinkedList) topics.get(topic);
    if (listeners == null) {
      return;
    }
    listeners2 = (LinkedList) listeners.clone();
  }

  ListIterator li = listeners2.listIterator();
  while (li.hasNext()) {
    ClientListenerOp l = (ClientListenerOp) li.next();

    try {l.process(topic, tname + msg); nProcessed++;}
    catch (Exception re) {
      synchronized(topics) {
        listeners = (LinkedList) topics.get(topic);
	listeners.remove(l);
	String name =  (String) listenerNames.get(l);
	unregister(l);
	System.out.println("process(" + name +", "+ topic +", "+ msg +") "+ re);
      }
    }
  }
}
*/ 


public void publish(String topic, String msg) {
  
  try {
    Request request = new Request(topic, msg);
    synchronized(workpile) {
      while (workpile.full()) {workpile.wait();}
      workpile.add(request);
      workpile.notifyAll();
    }
  }
  catch (InterruptedException ie) {} // Never happen in this program.
}


 public void process(Request request) {
   String topic = request.topic;
     String msg = request.msg;
  String tname = "Server[" + Thread.currentThread().getName() + "]\t";
  LinkedList listeners, listeners2;

  synchronized(topics) {
    listeners = (LinkedList) topics.get(topic);
    if (listeners == null) {
      return;
    }
    listeners2 = (LinkedList) listeners.clone();
  }

  ListIterator li = listeners2.listIterator();
  while (li.hasNext()) {
    ClientListenerOp l = (ClientListenerOp) li.next();

    try {l.process(topic, tname + msg); nProcessed++;}
    catch (Exception re) {
      synchronized(topics) {
        listeners = (LinkedList) topics.get(topic);
	listeners.remove(l);
	String name =  (String) listenerNames.get(l);
	unregister(l);
	System.out.println("process(" + name +", "+ topic +", "+ msg +") "+ re);
      }
    }
  }
}


}
 
