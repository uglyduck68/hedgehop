import java.io.*;
import Extensions.*;


public class TimeSyncFun implements TimedObject {
  
public void test(int n) { 
  for (int i=0; i<n; i++) 
    {foo();}
}
 
public synchronized void foo()
    {}

} 
