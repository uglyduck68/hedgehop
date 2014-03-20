import java.io.*;
import Extensions.*;


public class TimeNotify implements TimedObject {
  
public synchronized void test(int n) { 
  for (int i=0; i<n; i++) 
    {notify();}
}

} 
