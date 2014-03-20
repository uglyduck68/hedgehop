//              ListGlobalRW2/Test.java

/*

  Make a list of people (with names like "Jan_1234") and their salaries.
  Then spawn some threads to run down that list and give raises to all
  the people I like.  Spawn some more threads to delete from the list
  the people you don't like.  (Some people I like might also be people
  you don't like.)

  Insert delays during the raising and deleting functions to simulate disk
  I/O and make the program more interesting.

  Now consider the following parameters:
        o  Raise delay
        o  Liquidation delay
        o  Time for average search

  Which of the various locking designs works fastest for which combination
  of the above?



  This program allocates one global rwlock to protect the list itself, and
  one mutex to protect each salary.  It is *vital* that you know exactly 
  what each lock is going to protect.

  GLOBAL_RWLOCK

         __________________________________
        |              |  salary  |        |
        |              |  lock    |        |
        |--------------|----------|--------|
        |    Name      |  salary  |  next  |
        |  "Jan_123"   |  100000  |    o---|------>
        |______________|__________|________|


*/


import java.io.*;
import java.util.*;
import Extensions.*;


public class Test {
  Person                people;
  Person                friends, enemies;
  int                   NPeople = 1000, NFriends = 100, NEnemies = 100;
  int                   NFriendThreads = 10, NEnemyThreads = 1;
  int                   raiseDelay = 100, liquidateDelay = 100;
  int                   totalRaises=0, totalLiquidations=0;
  SingleBarrier         barrier = new SingleBarrier();
  boolean               DEBUG = false;
  RWLock                rwlock = new RWLock();


public static void main(String argv[]) {
  Test test = new Test();
  test.run(argv);
}


public void run(String argv[]) {
  if (argv.length > 0) liquidateDelay = Integer.parseInt(argv[0]);
  if (argv.length > 1) raiseDelay = Integer.parseInt(argv[1]);
  if (argv.length > 2) NPeople = Integer.parseInt(argv[2]);
  if (argv.length > 3) NFriends = Integer.parseInt(argv[3]);
  if (argv.length > 4) NEnemyThreads = Integer.parseInt(argv[4]);
  if (argv.length > 5) NFriendThreads = Integer.parseInt(argv[5]); 
  if (System.getProperty("DEBUG") != null) DEBUG = true;


  System.out.println("ListGlobalRW2(liquidateDelay: " + liquidateDelay
                     + "  raiseDelay: " + raiseDelay
                     + "  NPeople: " + NPeople
                     + "\n     NFriends: " + NFriends
                     + "  NEnemyThreads: " + NEnemyThreads
                     + "  NFriendThreads: " + NFriendThreads
                     + ")");


    
  people = Person.makeListOfPeople(NPeople);
  people = new Person(people, -1); // Placeholder person



  barrier.init(NFriendThreads + NEnemyThreads);

  //    if (DEBUG) people.print();
  long start = new Date().getTime();
  for (int i=0; i<NFriendThreads; i++) {
    friends = Person.makeRandomListOfPeople(NFriends, NPeople);
    TSDThread t = new TSDThread(new FriendThread(friends, this));
    t.test = this;       
    t.start();
  }

  for (int i=0; i<NEnemyThreads; i++) {
    enemies = Person.makeRandomListOfPeople(NEnemies, NPeople);
    TSDThread t = new TSDThread(new EnemyThread(enemies, this));
    t.test = this;
    t.start();
  }


  barrier.barrierWait();
  long end = new Date().getTime();
  //    if (DEBUG) people.print();

      
  System.out.println("Finished!  Realtime " + (end - start)/1000.0
                     + " (secs)");
  System.out.println("Total Raises: " + totalRaises
                     + " Total Liquidations: " + totalLiquidations);
  System.out.println("==================================================");
  System.exit(0);

}


public synchronized void  incrementLiquidations() {
  totalLiquidations++;
}
 
 
public synchronized void  incrementRaises() {
  totalRaises++;
}

}
