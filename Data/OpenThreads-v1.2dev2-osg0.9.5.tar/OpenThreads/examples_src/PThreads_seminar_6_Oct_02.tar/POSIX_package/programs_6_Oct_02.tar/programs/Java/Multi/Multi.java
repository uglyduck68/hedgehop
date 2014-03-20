//              Multi/Multi.java

/*
  Simple program that just illustrates thread creation, thread
  exiting, waiting for threads, and interrupting threads.

  This program relys completely on the accuracy of the sleep() 
  method, something which is ill-advised in a real program. You
  will notice that if you pause the program in a debugger, you'll
  get a null pointer exception.

  For this example, that's OK. 

  When you write REAL programs, DON'T DO THAT!
*/



public class Multi {
  static Thread         threadA, threadB, threadC;
  static Thread         threadD, threadE, threadMain;

public static void main(String[] args) throws Exception {
  threadMain = new Thread(new MyMain(), "threadMain");
  threadMain.start();
}
}


class MyMain implements Runnable {	// The *real* main() is not joinable!
  static long           startTime = 0;


public void run() {
  try {
    startTime = System.currentTimeMillis();
    System.out.println("\nTime\tThread\t\tEvent");
    System.out.println("====\t======\t\t=====");
    System.out.println(time() + "threadMain\tStarted ");

    Thread.sleep(1000);
    Multi.threadA = new Thread(new RunnableA(), "threadA");
    Multi.threadA.start();
    System.out.println(time() + "threadMain\tCreated threadA");

    Thread.sleep(1000);
    Multi.threadC = new Thread(new RunnableC(), "threadC");
    Multi.threadC.start();
    System.out.println(time() + "threadMain\tCreated threadC");

    Thread.sleep(2000);
    System.out.println(time() + "threadMain\tCancelling threadD");
    Multi.threadD.interrupt();
   
    Thread.sleep(1000);
    System.out.println(time() + "threadMain\tExiting");
  }
  catch (InterruptedException ie) {System.out.println("Impossible!");}
}


public static String time() {
  long time = (System.currentTimeMillis() - startTime)/1000 + 1000;
  return(time + "\t");
}
}


class RunnableA implements Runnable {

public void run() {
  try {
    System.out.println(MyMain.time() + "threadA\t\tStarting...");
    Thread.sleep(1000);
    Multi.threadD = new Thread(new RunnableD(), "threadD");
    Multi.threadD.start();
    System.out.println(MyMain.time() + "threadA\t\tCreated threadD");
    Thread.sleep(3000);
    System.out.println(MyMain.time() + "threadA\t\tExiting ");
  }
  catch (InterruptedException ie) {System.out.println("Impossible!");}
}
}


class RunnableB implements Runnable {

public void run() {
  try {
    System.out.println(MyMain.time() + "threadB\t\tStarting... ");
    Thread.sleep(4000);
    System.out.println(MyMain.time() + "threadB\t\tExiting ");
  }
  catch (InterruptedException ie) {System.out.println("Impossible!");}
}
}


class RunnableC implements Runnable {
  
public void run() {
  try {
    System.out.println(MyMain.time() + "threadC\t\tStarting... ");
    Thread.sleep(2000);
   
    System.out.println(MyMain.time() + "threadC\t\tJoining threadMain");
    Multi.threadMain.join();
    System.out.println(MyMain.time() + "threadC\t\tJoined threadMain");
    Thread.sleep(1000);

    Multi.threadB = new Thread(new RunnableB(), "threadB");
    Multi.threadB.start();
    System.out.println(MyMain.time() + "threadC\t\tCreated threadB");
    Thread.sleep(4000);

    System.out.println(MyMain.time() + "threadC\t\tExiting ");
  }
  catch (InterruptedException ie) {System.out.println("Impossible!");}
}
}


class RunnableD implements Runnable {

public void run() {
  try {
    System.out.println(MyMain.time() + "threadD\t\tStarting... ");
    Thread.sleep(1000);

    Multi.threadE = new Thread(new RunnableE(), "threadE");
    Multi.threadE.start();
    System.out.println(MyMain.time() + "threadD\t\tCreated threadE");
    Thread.sleep(5000);
    System.out.println(MyMain.time() + "threadD\t\tSHOULDN'T REACH HERE!");
  }
  catch (InterruptedException e) {
    System.out.println(MyMain.time() + "threadD\t\tInterrupted. Exiting");
  }
}
}


class RunnableE implements Runnable {  

public void run() {
  try {
    System.out.println(MyMain.time() + "threadE\t\tStarting... ");
    Thread.sleep(3000);
   
    System.out.println(MyMain.time() + "threadE\t\tJoining threadA");
    Multi.threadA.join();
    System.out.println(MyMain.time() + "threadE\t\tJoined threadA");
    Thread.sleep(2000);

    System.out.println(MyMain.time() + "threadE\t\tJoining threadC");
    Multi.threadC.join();
    System.out.println(MyMain.time() + "threadE\t\tJoined threadC");
    Thread.sleep(2000);

    System.out.println(MyMain.time() + "threadE\t\tJoining threadD");
    Multi.threadD.join();
    System.out.println(MyMain.time() + "threadE\t\tJoined threadD");
    Thread.sleep(1000);
   
    System.out.println(MyMain.time() + "threadE\t\tExiting ");
  }
  catch (InterruptedException ie) {System.out.println("Impossible!");}
}
}
