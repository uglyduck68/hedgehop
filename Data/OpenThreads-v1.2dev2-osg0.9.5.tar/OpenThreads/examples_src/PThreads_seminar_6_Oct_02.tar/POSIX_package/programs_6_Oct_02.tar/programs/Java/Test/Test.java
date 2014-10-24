//              Test/Test.java

/*
 
*/


import java.io.*;
import Extensions.*;


public class Test {
  static TestA testA = new TestA();
  static TestB testB = new TestB();
  static boolean w = false;
  
public static void main(String[] args) throws Exception {
  int i = 2001002003;
  float f = (float) i;

  //  System.out.println("int: " + i + " float: " + f + " recast: " + (int) f);
  // new Thread( new Test1(), "MT1").start();
  // new Thread(new Test2(), "MT2").start();
  new Thread(new Test3(), "MT2").start();
  test();
}

public static synchronized void test() {
  try {
    while (w) {Test.class.wait();}
    System.out.println("Works!");
  }
  catch (InterruptedException ie) {}
}
}


  class TestA {
  static int count=0;
    
  void foo1() {
    synchronized (Test.testB) {
      count++;
      System.out.println(Thread.currentThread() + "In foo1(): Got lock on " + getClass() + " " + count);
      InterruptibleThread.sleep(200);
      synchronized (Test.testA) {}
    }
    System.out.println(Thread.currentThread() + "In foo1(): Releasing lock on " + getClass() + " " + count);
  }


  void foo2() {
    synchronized (Test.testA) {
      count++;
      System.out.println(Thread.currentThread() + "In foo2(): Got lock on " + TestA.class + " " + count);
      InterruptibleThread.sleep(200);
      synchronized (Test.testB) {}
      System.exit(0);
    }
    System.out.println(Thread.currentThread() + "In foo2(): Releasing lock on " + TestA.class + " " + count);
  }

}




  class TestB extends TestA {}




class Test1 implements Runnable {

public void run() {
  System.out.println("Entering Test1.run()" + this);
  Test.testA.foo1();
  //Test.testA.foo2();

}
}


class Test2 implements Runnable {

public void run() {
  System.out.println("Entering Test2.run()");
  //Test.testB.foo1();
  Test.testA.foo2();

}
}

class Test3 implements Runnable {

public void run() {
  System.out.println("Entering Test3.run()");
  synchronized (Test.class) {
    Test.class.notify();
  }
}
}
