//              ServerRMI/LocalListener.java

import java.rmi.*;
import java.rmi.server.*;
import Extensions.*;


public class LocalListener  {
  ClientListenerImpl cli;


public LocalListener()  {
  cli = ClientListenerImpl.cli;
}

public void subscribe(String topic) {
  cli.subscribe(this, topic);
}

public void publish(String topic, String msg) {
  cli.publish(topic, msg);
}

public void unsubscribe(String topic) {
  cli.unsubscribe(this, topic);
}

public void process(String topic, String msg) throws RemoteException {
  String name = Thread.currentThread().getName().substring(8, 22);
 
  if (Client.DEBUG) System.out.println(Client.name + "[" + name + "]\t" +topic + " -> " + msg);
}
  

}
