
import java.util.*;
import java.io.*;
import Extensions.*;


public class TimeGarbage implements TimedObject {

public   void test(int n) { 

  //  System.out.println("\nFreeMem: " +  Runtime.getRuntime().freeMemory());
  //  System.out.println("TotalMem: " +  Runtime.getRuntime().totalMemory());
  for (int i=0; i<n; i++) 
    {
      TimeGarbage g = new TimeGarbage();
    }
  Runtime.getRuntime().gc();
  //  System.out.println("FreeMem: " +  Runtime.getRuntime().freeMemory());
  //  System.out.println("TotalMem: " +  Runtime.getRuntime().totalMemory());
}
}
