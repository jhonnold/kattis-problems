#include <iostream>

using namespace std;

int main() {
  int s, t, i, j;
  int streets[40000]; // Worst case

  cin >> s;
  for (i = 0; i < s; i++) {
    // read in the 4 coords
    cin >> streets[4 * i] >> streets[4 * i + 1]
        >> streets[4 * i + 2] >> streets[4 * i + 3];
  }

  cin >> t;
  for (i = 0; i < t; i++) {
    bool same = true;
    int x1, y1, x2, y2;

    cin >> x1 >> y1 >> x2 >> y2;

    for (j = 0; j < s; j++) {
      // (y2 - y1)/(x2 - x1)
      double slope = (double)(streets[4 * j + 3] - streets[4 * j + 1])/(streets[4 * j + 2] - streets[4 * j]);
      // y - y1 - S(x - x1) = 0 <-- Equation for the line
      // this figures out what side of the street theyre on
      double l1 = y1 - streets[4 * j + 1] - slope * (x1 - streets[4 * j]);
      double l2 = y2 - streets[4 * j + 1] - slope * (x2 - streets[4 * j]);

      // normalize to 1 or 0
      l1 = l1 >= 0 ? 1 : 0;
      l2 = l2 >= 0 ? 1 : 0;

      // if they're diffent then reverse the same
      if (l1 != l2) same = !same;
    }

    if (same) {
      cout << "same" << endl;
    } else {
      cout << "different" << endl;
    }
  }
}
