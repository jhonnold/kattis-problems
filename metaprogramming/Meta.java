import java.util.*;
import java.io.*;

class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    HashMap<String, Integer> vars = new HashMap<>();

    while (in.hasNext()) {
      String[] line = in.nextLine().split(" ");

      if (line[0].equals("define")) {
        int val = Integer.parseInt(line[1]);
        vars.put(line[2], val);
      } else if (line[0].equals("eval")) {
        if (!vars.containsKey(line[1]) || !vars.containsKey(line[3])) {
          System.out.println("undefined");
        } else {
          int val1 = vars.get(line[1]);
          int val2 = vars.get(line[3]);

          if (line[2].equals("<")) {
            System.out.println(val1 < val2);
          } else if (line[2].equals("=")) {
            System.out.println(val1 == val2);
          } else if (line[2].equals(">")) {
            System.out.println(val1 > val2);
          }
        }
      }
    }
  }
}
