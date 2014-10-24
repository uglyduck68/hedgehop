//              Extensions/FIFOMutex.java



package Extensions;
import java.util.*;


public class FIFOMutex {
  Thread                owner = null;
  FIFOQueue             waiters = new FIFOQueue();

  
public String toString() {
  String         name = "null";

  if (owner != null) name = owner.getName();
  return ("<" + super.toString() + "owner:" + name + ">");
}
  

public void lock() {
  Thread                self = Thread.currentThread();
  Semaphore             sem;

  synchronized (this) {
    if ((owner == null) && waiters.empty()) {
      owner = self;
      return;
    }
    sem = new Semaphore();      // Nice if this could be TSD!
    waiters.add(sem);
  }
  sem.semWait();
}

  
public synchronized void unlock() {
  if (owner != Thread.currentThread())
    throw new IllegalMonitorStateException("Unlocking thread is not owner");

  if (waiters.empty()) return;
  Semaphore sem = (Semaphore) waiters.removeFirst();
  sem.semPost();
}

}
