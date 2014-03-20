//              FollowMe/Cell.java

import java.applet.*;
import java.awt.*;
import Extensions.*;

public class Cell {
  int           cellWidth = 100;        // The pixel width of a cell.
  int           cellHeight = 100;       // The pixel height of a cell.
  static Cell   cells[] = new Cell[4];
  int           x;                      // cell number (not pixel location)
  Color         color;

  
public Cell(Color c, int i) {
  color = c;
  x = i;
}

  
public void paint(Graphics g) {
  g.setColor(color);
  g.fillRect(x * cellWidth, 0, cellWidth, cellHeight);
}

  
public static void init() {
  cells[0] = new Cell(Color.blue.darker(), 0);
  cells[1] = new Cell(Color.yellow.darker(), 1);
  cells[2] = new Cell(Color.red.darker(), 2);
  cells[3] = new Cell(Color.green.darker(), 3);
}


public void brighten() {
  color = color.brighter();
}

public void darken() {
  color = color.darker();
}

}
