//              Extensions/RecursiveMutex.java

package Extensions;

import java.io.*;


public class RecursiveMutex {
  Thread                owner = null;
  int                   count = 0;

  
public String toString() {
  String                name = "null";

  if (owner != null) name = owner.getName();
  return ("<" + super.toString() + "owner:" + name + "count: " + count + ">");
}
  

public synchronized void lock() {
  boolean               interrupted = false;

  while ((owner != null) && owner != Thread.currentThread()) {
    try {wait();}
    catch (InterruptedException ie) {interrupted=true;}
  }
  owner = Thread.currentThread();
  count++;
  if (interrupted) Thread.currentThread().interrupt();
}

  
public synchronized void unlock() {
  if (owner != Thread.currentThread())
    throw new IllegalMonitorStateException("Unlocking thread is not owner");
  count--;
  if (count == 0) {
    owner = null;
    notify();
  }
}

}
