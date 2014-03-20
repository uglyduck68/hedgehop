//              List2LocalLocks/Person.java

import java.io.*;
import java.util.*;
import Extensions.*;

public class Person {
  static int                    count = 1;
  int                           salary;
  String                        name;
  Mutex                         mutex = new Mutex();
  Person                        next;

public Person() {

  name = new String("Jan_" + count);
  count++;
  salary = 1000;
  next = null;
}

public Person(int i) {

  name = new String("Jan_" + i);
  salary = 1000;
  next = null;
}
  
public Person(Person p) {

  name = new String("Jan_" + count);
  count++;
  salary = 1000;
  next = p;
}

public Person(Person p, int i) {

  name = new String("Jan_" + i);
  salary = 1000;
  next = p;
}

public String toString() {

  return("<Person " + name + ">");
}
  
public void print() {

  Person p = this;
  while (p != null) {
    System.out.println(p);
    p = p.next;
  }
}


public static Person makeListOfPeople(int i) {
  Person old = null, p = null;
   
  for (int j=0; j<i; j++) {
    p = new Person(old);
    old = p;
  }
  return p;
}

  

public static Person makeRandomListOfPeople(int i, int NPeople) {
  Person                old = null, p = null;
  int                   ran;
  Date                  date = new Date();
  long                  ms = date.getTime();
  Random                r = new Random(ms);
   
  for (int j=0; j<i; j++) {
    ran = Math.abs(r.nextInt() % NPeople);
    p = new Person(old, ran);
    old = p;
  }
  return p;
}

public synchronized void giveRaise(Person previous) {
  TSDThread             self = ((TSDThread) Thread.currentThread());
  Test                  test = self.test;
   
  if (test.DEBUG) System.out.println(self.getName() +
                                     "  \tGiving raise to: " + this);
  previous.mutex.unlock();
  salary++;
  InterruptibleThread.sleep(test.raiseDelay);
  test.incrementRaises();
    
}


public synchronized void liquidate() {
  TSDThread             self = ((TSDThread) Thread.currentThread());
  Test                  test = self.test;
   
  if (test.DEBUG) System.out.println(self.getName() +
                                     "  \tliquidating: " + this.next);
  next = next.next;
  mutex.unlock();
  InterruptibleThread.sleep(test.liquidateDelay);
  test.incrementLiquidations();
}


public static Person findPerson(Person p, Person people) {
  Person                        previous;
   
  people.mutex.lock();

  while (people.next != null) {
    if (p.name.equals(people.next.name))
      return(people);   // Previous person (holding lock!)
    people.next.mutex.lock();
    previous = people;
    people = people.next;
    previous.mutex.unlock();
  }
  people.mutex.unlock();
  return(null);
}

}
