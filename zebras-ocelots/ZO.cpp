#include <iostream>
using namespace std;

int main() {
    long n, t = 0;
    char c;

    cin >> n;
    while (n-- > 0) {
      t *= 2;
      cin >> c;
      if (c == 'O')
          t++;
    }

    cout << t << endl;
    return 0;
}
