//              ListGlobalLock/Person.java

import java.io.*;
import java.util.*;
import Extensions.*;

public class Person {
  static int            count = 1;
  int                   salary;
  String                name;
  Person                next;


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
  Person                old = null, p = null;
   
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


public void giveRaise() {
  if (Test.DEBUG) System.out.println(Thread.currentThread().getName() +
                                     "  \tGiving raise to: " + this);
  salary++;
  InterruptibleThread.sleep(Test.raiseDelay);
  Test.incrementRaises();
}



public void liquidate() {
  if (Test.DEBUG) System.out.println(Thread.currentThread().getName() +
                                     "  \tliquidating: " + this.next);
  next = next.next;
  InterruptibleThread.sleep(Test.liquidateDelay);
  Test.incrementLiquidations();
}



public static Person findPerson(Person p, Person people) {
  while (people.next != null) {
    if (p.name.equals(people.next.name))
      return(people);   // Previous person
    people = people.next;
  }
  return(null); 
}

}
