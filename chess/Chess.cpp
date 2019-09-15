#include <iostream>
using namespace std;

int columnToNumber(char c) {
  switch (c) {
    case 'A': return 1;
    case 'B': return 2;
    case 'C': return 3;
    case 'D': return 4;
    case 'E': return 5;
    case 'F': return 6;
    case 'G': return 7;
    case 'H': return 8;
  }
}

char numberToColumn(int c) {
  switch (c) {
    case 1: return 'A';
    case 2: return 'B';
    case 3: return 'C';
    case 4: return 'D';
    case 5: return 'E';
    case 6: return 'F';
    case 7: return 'G';
    case 8: return 'H';
  }
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int c1, r1, c2, r2;
    char c;

    cin >> c;
    c1 = columnToNumber(c);

    cin >> r1;

    cin >> c;
    c2 = columnToNumber(c);

    cin >> r2;

    if ((r1 + c1) % 2 != (r2 + c2) % 2) {
      cout << "Impossible" << endl;
    } else if (r1 == r2 && c1 == c2) {
      cout << "0 " << numberToColumn(c1) << " " << r1 << endl;
    } else {
      int x1 = (r2 + c2 + r1 - c1) / 2;
      int y1 = x1 - (r1 - c1);

      int x2 = (r1 + c1 + r2 - c2) / 2;
      int y2 = x2 - (r2 - c2);
    
      if (x1 == r1 && y1 == c1) {
        cout << "1 ";
        cout << numberToColumn(c1) << " " << r1 << " ";
        cout << numberToColumn(c2) << " " << r2 << endl;
      } else if (x1 == r2 && y1 == c2) {
        cout << "1 ";
        cout << numberToColumn(c1) << " " << r1 << " ";
        cout << numberToColumn(c2) << " " << r2 << endl;
      } else if (x1 >= 1 && x1 <= 8 && y1 >= 1 && y1 <= 8) {
        cout << "2 ";
        cout << numberToColumn(c1) << " " << r1 << " ";
        cout << numberToColumn(y1) << " " << x1 << " ";
        cout << numberToColumn(c2) << " " << r2 << endl;
      } else {
        cout << "2 ";
        cout << numberToColumn(c1) << " " << r1 << " ";
        cout << numberToColumn(y2) << " " << x2 << " ";
        cout << numberToColumn(c2) << " " << r2 << endl;
      }

    }
  }

  return 0;
}