//              ServerRMI/ClientListenerOp.java

import java.rmi.*;

// A remote interface for an object that supports the "call" 
// operation.  

public interface ClientListenerOp extends Remote {

public void process(String topic, String msg) throws RemoteException;
}
