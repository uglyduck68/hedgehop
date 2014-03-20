import java.io.*;
import Extensions.*;
 

public class GetProperty implements TimedObject {
  static int j = 0;

 
public void test(int n) {
  for (int i=0; i<n; i++)
    {String s = System.getProperty("DEBUG");}
  
}
}
