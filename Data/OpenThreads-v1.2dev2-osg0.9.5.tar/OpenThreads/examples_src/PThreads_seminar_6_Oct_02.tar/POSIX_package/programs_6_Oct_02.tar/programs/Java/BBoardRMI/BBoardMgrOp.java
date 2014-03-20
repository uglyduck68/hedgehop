//              ServerRMI/BBoardMgrOp.java

import java.rmi.*;

// A remote interface for an object that supports the "call" 
// operation.  

public interface BBoardMgrOp extends Remote {

public void register(ClientListenerOp l, String topic) throws RemoteException;
public void unregister(ClientListenerOp l) throws RemoteException;
public void subscribe(ClientListenerOp l, String topic) throws RemoteException;
public void unsubscribe(ClientListenerOp l, String topic) throws RemoteException;
public void publish(String topic, String msg) throws RemoteException;

}
