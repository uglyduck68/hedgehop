//              Test/TestSub.java

/*
 
*/


import java.io.*;
import Extensions.*;


public class TestSub extends Test  {

public int which;



public synchronized void frob() {
  try {
    System.out.println("  in frob (sub)");
 //   super.frob();
  }
  catch (Exception e) {
    System.out.println(e + " in frob (sub)");
  }
  finally {
    System.out.println("  finally in frob (sub)");
  }
}

}
