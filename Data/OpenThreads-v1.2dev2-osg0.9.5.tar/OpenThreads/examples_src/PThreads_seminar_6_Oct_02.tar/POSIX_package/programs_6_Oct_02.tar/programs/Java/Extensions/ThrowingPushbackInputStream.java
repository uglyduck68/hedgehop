//              Extensions/ThrowingPushbackInputStream.java

package Extensions;

import java.io.*;


public class ThrowingPushbackInputStream extends PushbackInputStream {
public int filePos = 0;
public int linePos = 0;
public int oldLinePos = 0;
public int endOfToken = -1;

public void unread(int c) throws IOException {

  super.unread(c);
  filePos--;
  if ((c == '\n') || (c == '\r')) {
    linePos = oldLinePos;
  }
  else
    linePos--;
}

public int read() throws IOException {
  int c;
  if (linePos == endOfToken) {
    endOfToken = -1; return(' ');
  }
  c = super.read();
  if (c == -1) throw new EOFException(" EOF in ThrowingPushbackInputStream.read()");
  filePos++;

  if ((c == '\n') || (c == '\r')) {
    oldLinePos = linePos; linePos = 0;
  }
  else
    linePos++;
 
  return c;
}

public ThrowingPushbackInputStream(InputStream in) {

  super(in);
}

}
