import java.io.*;
import Extensions.*;


public class TimeRWLock implements TimedObject {
public static RWLock rwlock = new RWLock();

public void test(int n) { 

  for (int i=0; i<n; i++) {
    rwlock.writeLock();
    rwlock.unlock();
    }

}
}
