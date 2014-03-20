//              HeatFlow2/State.java

import java.io.*;
import Extensions.*;

public class State {
  SingleBarrier         barrier;
  int                   size;
  int                   array[][];
  String                name;
  static int            count = 0;
  State                 next;

public State(int nThreads, int s) {
  barrier = new SingleBarrier(nThreads, nThreads);
  size = s;
  array = new int[size+2] [size+2];     // Edges will be constants!
  name = "State[" + count + "]";
  for (int i = 0; i < size+2; i++) {
    array[i][0] = 9;
    array[0][i] = 9;
  }
  count++;
}


public void print(int iteration) {
  System.out.print("\n\t " + name + " iteration:" + iteration + "\n ");
  for (int i = 0; i < size+2; i++) {
    System.out.print("-");
  }
  System.out.println();
    
  for (int i = 0; i < size+2; i++) {
    System.out.print("|");
    for (int j = 0; j < size+2; j++) {
      System.out.print(array[i][j]);
    }
    System.out.println("|");
  }

  System.out.print(" ");
  for (int i = 0; i < size+2; i++) {
    System.out.print("-");
  }
  System.out.println();
}

  
public void transform(State newState, int j) {
  // Cheap way of avoiding dealing with array[-1] problems.    
  j++;
  for (int i = 1; i < size+1; i++) {
    newState.array[i] [j] =
      (array[i-1] [j-1] + array[i-1] [j] + array[i-1] [j+1] +
       array[i]   [j-1] + array[i]   [j] + array[i]   [j+1] +
       array[i+1] [j-1] + array[i+1] [j] + array[i+1] [j+1] + 8) / 9;
  }
}

}
