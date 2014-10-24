import java.io.*;
import java.util.*;
import Extensions.*;


public class TimeVolatile implements TimedObject {
  static volatile int           vol = 0;

public void test(int n) { 
  for (int i=0; i<n; i++) 
    {vol++;}   
}
 
}
