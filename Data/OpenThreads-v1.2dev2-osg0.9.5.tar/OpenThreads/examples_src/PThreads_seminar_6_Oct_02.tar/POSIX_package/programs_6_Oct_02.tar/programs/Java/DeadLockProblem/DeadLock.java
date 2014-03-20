//              DeadLock/DeadLock.java

import java.io.*;
import java.util.*;
import Extensions.*;

public class DeadLock implements Runnable {
  static boolean DEBUG = true;
  static boolean KILL = true;
  static Thing things[];
  static int nThings = 4;	//4
  static int nThreads = 4;	//4
  static int nSwaps = 10;	//3
  static SingleBarrier b;



public static void main(String[] argv) throws Exception {
  DeadLock dead = new DeadLock();		// Reusable!

  if (argv.length > 0) nThings = Integer.parseInt(argv[0]);
  if (argv.length > 1) nThreads = Integer.parseInt(argv[1]);
  if (argv.length > 2) nSwaps = Integer.parseInt(argv[2]);
  if (System.getProperty("DEBUG") != null) DEBUG = true;
  if (System.getProperty("KILL") != null) KILL = true;
  System.out.println("DeadLock(nThings: " + nThings + " nThreads: "
                     + nThreads + " nSwaps: " + nSwaps
                     + ")");                 


  b = new SingleBarrier(nThreads);
  things = new Thing[nThings];
  for (int i = 0; i<nThings; i++) {things[i] = new Thing(i);}
  for (int i = 0; i<nThings; i++) {System.out.println(things[i]);}

  for (int i = 0; i<nThreads; i++) {
    new Thread(dead, "DeadThread_"+i).start();
  }

  if (KILL) new Thread(new Killer(10)).start();

  b.barrierWait();
  System.out.println("Exited Correctly!");
  for (int i = 0; i<nThings; i++) {System.out.println(things[i]);}
  System.exit(0);
}


public void run() {
  Random ran = new Random();
  int r1, r2;

  for (int i = 0; i<nSwaps; i++) {
    r1 = Math.abs(ran.nextInt() % nThings);
    r2 = Math.abs(ran.nextInt() % nThings);
    Thing thing1 = things[r1];
    Thing thing2 = things[r2]; 
    thing1.swap(thing2);

  }
  b.barrierPost();
}
}



 class Thing {
  int value;
  int count;
  Random ran;


public Thing(int i) {
  count = i;
  value = i;
  ran = new Random(i);
}

public String toString() {
  return("Thing_" + count + "[" + value + "]");
}


public  void swap(Thing t) {
  String name = Thread.currentThread().getName()+"\t";

  if (DeadLock.DEBUG) {System.out.println(name + this + ".swap(" + t + ")");}
  synchronized (this) {
    if (DeadLock.DEBUG) {System.out.println(name + this + ".swaping(" + t + ")");}
    synchronized (t) {
      int tmp1 = t.value();
      t.setValue(value);
      value = tmp1;
    }
  }
  if (DeadLock.DEBUG) {System.out.println(name + this + ".swapped(" + t + ")");}
}


public  synchronized int value() {
  String name = Thread.currentThread().getName()+"\t";
  if (DeadLock.DEBUG) {System.out.println(name + this + ".value()");}
  InterruptibleThread.sleep(Math.abs(ran.nextInt() % 100));
  return value;
}

  
public   synchronized void setValue(int v) {
  String name = Thread.currentThread().getName()+"\t";
  if (DeadLock.DEBUG) {System.out.println(name + this + ".setValue()");}
  InterruptibleThread.sleep(Math.abs(ran.nextInt() % 100));
  value = v;
}

}
