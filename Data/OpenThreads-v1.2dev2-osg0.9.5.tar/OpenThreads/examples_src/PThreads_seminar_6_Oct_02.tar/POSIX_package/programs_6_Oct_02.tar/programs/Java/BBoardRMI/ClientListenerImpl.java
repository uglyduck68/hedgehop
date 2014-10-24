//              ServerRMI/ClientListenerImpl.java

import java.util.*;
import java.rmi.*;
import java.rmi.server.*;
import Extensions.*;


public class ClientListenerImpl extends UnicastRemoteObject implements ClientListenerOp {
  BBoardMgrOp mgr;
  static ClientListenerImpl cli;
  Hashtable topics = new Hashtable();
  Hashtable allListeners = new Hashtable();
  static int nListeners=0;
  static int nProcessed=0;
  static int nSubscriptions=0;
  static int nTopics=0;
  String name;


public ClientListenerImpl(String n) throws RemoteException {
  name = n;
  cli = this;
  try {
    mgr = (BBoardMgrOp)Naming.lookup("BBoardMgr");
    mgr.register(this, name);
  }
  catch (Exception re) {System.out.println(re);}
}

public void unregister() {
  try {
    mgr.unregister(this);
  }
  catch (Exception re) {System.out.println(re);}
}


public void subscribe(LocalListener l, String topic) {
  LinkedList listeners;

  synchronized(topics) {
    MyInteger i = (MyInteger) allListeners.get(l);
    if (i == null) {
      i = new MyInteger();
      allListeners.put(l, i);
    }
    if (i.value == 0) {nListeners++;}
    i.inc();

    nSubscriptions++;
    listeners = (LinkedList) topics.get(topic);
    if (listeners == null) {
      listeners = new LinkedList();
      topics.put(topic, listeners);
    }
    if (listeners.size() == 0) {
      try {mgr.subscribe(this, topic);}
      catch (RemoteException re) {System.out.println(re);}
    }
    listeners.add(l);
  }
  
}

public void unsubscribe(LocalListener ll, String topic) {
  LinkedList listeners;

  synchronized(topics) {
    MyInteger i = (MyInteger) allListeners.get(ll);
    if (i == null) {System.out.println("Never");return;} // not subscribed!

    listeners = (LinkedList) topics.get(topic);
    boolean removed = listeners.remove(ll);
    if (!removed) {System.out.println("Not");return;} // not subscribed!
    i.dec();
    if (i.value == 0) nListeners--;
    nSubscriptions--;
    if (listeners.size() == 0) {
      try {mgr.unsubscribe(this, topic);}
      catch (RemoteException re) {System.out.println(re);}
    }
  }
}


public void publish(String topic, String msg) {
  try {mgr.publish(topic, msg);}
  catch (RemoteException re) {System.out.println(re);}
}


public void process(String topic, String msg) throws RemoteException {
  String name = Thread.currentThread().getName().substring(8, 22);
  LinkedList listeners;

  synchronized(topics) {
    listeners = (LinkedList) topics.get(topic);
    if (listeners == null) {
      return; // Impossible
    }

    ListIterator i = listeners.listIterator();
    while (i.hasNext()) {
      LocalListener l = (LocalListener) i.next();
      l.process(topic, msg);
      nProcessed++;
    }
  }
 
  if (Client.DEBUG) System.out.println("CLI[" + name + "]\t" +topic + " -> " + msg);
}
  

}
