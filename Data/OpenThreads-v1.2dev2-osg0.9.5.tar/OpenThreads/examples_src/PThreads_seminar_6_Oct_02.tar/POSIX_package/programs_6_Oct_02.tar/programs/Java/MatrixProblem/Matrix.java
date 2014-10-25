//              MatrixProblem/Matrix.java

import java.io.*;
import Extensions.*;


public class Matrix {
  int           n_rows, n_cols;
  int [] []     array;


public void print() {
  for (int i=0; i<n_rows; i++) {
    System.out.println();
    for (int j=0; j<n_cols; j++) {
      System.out.print(" " + array[i] [j]);
    }
  }
  System.out.println();
}


public void fill() {
  for (int i=0; i<n_rows; i++) {
    for (int j=0; j<n_cols; j++) {
      array[i] [j] = 1000 + i*10 + j;
    }
  }
}


public Matrix(int i, int j) {
  n_rows = i;
  n_cols = j;
  array = new int[i] [j];
}

}
