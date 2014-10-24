//              Extensions/RWLock.java

package Extensions;

import java.io.*;



public class RWLock {
  Thread                owner = null;
  int                   nCurrentReaders = 0;
  int                   nWaitingWriters = 0;
  int                   nWaitingReaders = 0;
  Mutex                 m =  new Mutex();
  ConditionVar          readersCV = new  ConditionVar();
  ConditionVar          writersCV = new  ConditionVar();


public String toString() {
  String name;

  if (owner == null)
    name = "null";
  else
    name = owner.getName();

  return("<RWLock: o:" + name + " r:" + nCurrentReaders + " ww:" 
         + nWaitingWriters + " wr:" + nWaitingReaders + m + ">");
}


public void readLock() {

  m.lock();
  nWaitingReaders++;
  while ((owner != null) || (nWaitingWriters > 0)) {
    readersCV.condWait(m); }
  nWaitingReaders--;
  nCurrentReaders++;
  m.unlock();
}


public void writeLock() {
  m.lock();
  nWaitingWriters++;
  while ((owner != null) || (nCurrentReaders > 0)) {
    writersCV.condWait(m);
  }
  nWaitingWriters--;
  owner = Thread.currentThread();
  m.unlock();
}

  
public void unlock() {
  m.lock();
  if (owner != null) {
    owner = null;
  }
  else
    nCurrentReaders--;

  if ((nWaitingWriters > 0) && (nCurrentReaders == 0)) {
    writersCV.condSignal();
  }
  else
    if ((nWaitingWriters == 0) && (nWaitingReaders > 0)) {
      readersCV.condBroadcast();
    }
  m.unlock();
}

}
