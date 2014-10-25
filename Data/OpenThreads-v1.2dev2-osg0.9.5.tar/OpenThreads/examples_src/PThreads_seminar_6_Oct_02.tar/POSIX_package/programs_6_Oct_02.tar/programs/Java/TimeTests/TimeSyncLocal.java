import java.io.*;
import Extensions.*;


public class TimeSyncLocal implements TimedObject {
  int j = 0;

  
public void test(int n) { 
  for (int i=0; i<n; i++) 
    {synchronized (this) {j++;} }
}
 
}
