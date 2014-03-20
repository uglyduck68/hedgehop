//              ServerSelect/NativeSelect.java


import java.io.*;
import java.util.*;
import Extensions.*;


public class NativeSelect {
  static int port=14;

  static native int native_initialize_port(int i);
  static native NativeRequest native_get_request();
  static native void native_set_stop(int i);
  static native int native_write(String s, int i);
  static native void native_close(int i);

  static {
    System.loadLibrary("NativeSelect");
    //System.out.println("Loaded");
  }

  static public int initializePort(int i) {
    if (Server.DEBUG2) System.out.println("Calling: native_initialize_port");
    port = native_initialize_port(i);
    if (Server.DEBUG2) System.out.println("Returned from: native_initialize_port");
    return(port);
  }

  static public Request getRequest() {
    if (Server.DEBUG2) System.out.println("Calling: native_get_request");
    NativeRequest nr = native_get_request();
    // NativeRequest nr = new  NativeRequest(1, "New                                                                   ");
    if (Server.DEBUG2)
      System.out.println("Returned from: native_get_request " + nr.index + " " + nr.str);
    Request r = new Request(Client.find(nr.index), nr.str);
    if (Server.DEBUG2) System.out.println("getRequest: " + r);
    return(r);
  }

  static public void setStop(boolean b) {
    int i = 0;

    if (Server.DEBUG2) System.out.println("Calling: native_set_stop " + b);
    if (b) i=1;
    native_set_stop(i);
    if (Server.DEBUG2) System.out.println("Returned from: native_set_stop");
  }

  static public int write(String s, int i) {
    int err;

    if (Server.DEBUG2) System.out.println("Calling: native_write " + s + " " +i);
    err= native_write(s, i);
    if (Server.DEBUG2) System.out.println("Returned from: native_write");
    return(err);
  }

  static public void close(Client c) {
    if (Server.DEBUG2) System.out.println("Calling: native_close " + c);
    native_close(c.index);
    if (Server.DEBUG2) System.out.println("Returned from: native_close");
  }


  
public static void main(String[] args) {
  initializePort(6400);
  System.out.println("Opened Port: " + port);
  Request r =  getRequest();
  System.out.println("" + r);
  write("This is test one.", 10);
}



}


/* We could go directly to a Request, but this decoupling makes
debugging easier because the constructor does less work. */

class NativeRequest {
  int index;
  String str;

public NativeRequest(int i, String s) {
  index = i;
  str=s;
}

public NativeRequest(int i) {
  index = i;
}

}
