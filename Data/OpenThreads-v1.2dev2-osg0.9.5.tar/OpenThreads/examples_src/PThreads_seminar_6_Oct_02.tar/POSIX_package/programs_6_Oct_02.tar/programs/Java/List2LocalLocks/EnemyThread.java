//              List2LocalLocks/EnemyThread.java

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
  TSDThread     self = ((TSDThread) Thread.currentThread());
  Test          test = self.test;
   
  while (enemies != null) {
    {
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
