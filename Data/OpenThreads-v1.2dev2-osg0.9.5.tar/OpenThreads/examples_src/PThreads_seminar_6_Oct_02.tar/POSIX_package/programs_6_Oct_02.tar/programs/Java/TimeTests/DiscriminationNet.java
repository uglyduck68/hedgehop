import java.io.*;
import Extensions.*;
 

public class DiscriminationNet implements TimedObject {
  static int j = 0;

 
public void test(int n) {
  Object[] a = new Object[1];
  a[0] = new Object();
  for (int i=0; i<n; i++)
    {Object o = (Object) a[0];}
  
}


  /*

public void test(int n) {
  Object[] a = new Object[1];
  a[0] = new Thing();
  for (int i=0; i<n; i++)
    {Thing o = (Thing) a[0];}
  
}
}

public void test(int n) {
  Object[] a = new Object[1];
  a[0] = new Thing();
  for (int i=0; i<n; i++)
    {Thing o = (Thing) a[0];}
  
}
}

public void test(int n) {
  Object[] a = new Object[1];
  a[0] = new Thing();
  for (int i=0; i<n; i++)
    {Thing o = (Thing) a[0];}
  
}
}
*/
}


class Thing10 {
public int foo() {
return 100;
}}

class Thing9 extends Thing10 {
public int foo() {
return 10;
}}

class Thing8 extends Thing9 {
public int foo() {
return 19;
}}

class Thing7 extends Thing8 {
public int foo() {
return 18;
}}

class Thing6 extends Thing7 {
public int foo() {
return 17;
}}

class Thing5 extends Thing6 {
public int foo() {
return 16;
}}

class Thing4 extends Thing5 {
public int foo() {
return 15;
}}

class Thing3 extends Thing4 {
public int foo() {
return 14;
}}

class Thing2 extends Thing3 {
public int foo() {
return 13;
}}

class Thing1 extends Thing2 {
public int foo() {
return 12;
}}

class Thing extends Thing1 {
public int foo() {
return 1;
}}
