//              ListGlobalRW2/FriendThread.java

import java.io.*;
import Extensions.*;


public class FriendThread implements Runnable {
  Person                friends;
  Test          test;


public FriendThread(Person p, Test t) {
  friends = p;
  test = t;
}


public void run() {
  TSDThread             self = ((TSDThread) Thread.currentThread());
  Test                  test = self.test;

  while (friends != null) {
    test.rwlock.readLock(); {
      Person p = Person.findPerson(friends, test.people);
      if (p != null) {
        p.next.giveRaise();
      }
      else
        test.rwlock.unlock();
      friends = friends.next;
    }
    Thread.yield();             // Use for GREEN THREADS
  }
  test.barrier.barrierPost();
}

}
