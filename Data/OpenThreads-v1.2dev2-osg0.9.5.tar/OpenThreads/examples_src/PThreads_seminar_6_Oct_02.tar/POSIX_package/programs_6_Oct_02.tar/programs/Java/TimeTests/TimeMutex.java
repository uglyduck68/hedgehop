import java.io.*;
import Extensions.*;


public class TimeMutex implements TimedObject {
public static  Mutex mutex = new Mutex();
 
public void test(int n) {
  for (int i=0; i<n; i++) 
    {mutex.lock();
    mutex.unlock(); 
    }
}
}

