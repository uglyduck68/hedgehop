//              ServerRMI/ClientListenerImpl.java

import java.util.*;
import java.rmi.*;
import java.rmi.server.*;
import Extensions.*;


public class MyInteger {
public int value = 0;

public void inc() {
  value++;
}

public void dec() {
  value--;
}

}
