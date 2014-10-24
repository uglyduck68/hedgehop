//              List2LocalLocks/TSDThread.java

import java.io.*;
import java.util.*;
import Extensions.*;



public class TSDThread extends Thread {
  Test                  test;


public TSDThread(FriendThread o) {
  super(o); }

public TSDThread(EnemyThread o) {
  super(o); }

  //  Why can't I define: public TSDThread(Runnable o)?  (Runtime error)

}
