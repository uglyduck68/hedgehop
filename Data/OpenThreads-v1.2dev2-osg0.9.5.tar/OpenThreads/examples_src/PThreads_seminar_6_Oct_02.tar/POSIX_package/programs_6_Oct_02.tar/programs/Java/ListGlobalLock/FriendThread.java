//              ListGlobalLock/FriendThread.java

import java.io.*;
import Extensions.*;


public class FriendThread implements Runnable {
  Person                friends;
  Test                  test;

public FriendThread(Person p, Test t) {
  friends = p;
  test = t;
}

public void run() {
 
  while (friends != null) {
    synchronized(test.people) {
      Person p = Person.findPerson(friends, test.people);
      if (p != null) {
        p.next.giveRaise();
      }
      friends = friends.next;
    }
    Thread.yield();             // Use for GREEN THREADS
  }
  test.barrier.barrierPost();
}

}
