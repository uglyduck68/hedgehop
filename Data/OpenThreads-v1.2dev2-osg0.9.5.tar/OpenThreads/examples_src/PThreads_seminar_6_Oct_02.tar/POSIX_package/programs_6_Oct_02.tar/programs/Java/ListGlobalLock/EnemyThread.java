//              ListGlobalLock/EnemyThread.java

import java.io.*;
import Extensions.*;


public class EnemyThread implements Runnable {
  Person                enemies;
  Test                  test;

public EnemyThread(Person p, Test t) {
  enemies = p;
  test = t;
}

public void run() {

  while (enemies != null) {
    synchronized(test.people) {
      Person p = Person.findPerson(enemies, test.people);
      if (p != null) {
        p.liquidate();
      }
      enemies = enemies.next;
    }
    Thread.yield();             // Use for GREEN THREADS
  }
  test.barrier.barrierPost();
}

}
