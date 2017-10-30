#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
  string num;
  int p, k, v;
  unsigned int b8, b10, b16;
  bool octal_bad;

  cin >> p;
  for (int i = 1; i <= p; i++) {
    octal_bad = false;
    cin >> k >> v;
    num = to_string(v);
    b8 = b10 = b16 = 0;

    while (num[0] != '\0') {
      int n = num[0] - '0';
      if (n >= 8) octal_bad = true;

      b8 *= 8;
      b10 *= 10;
      b16 *= 16;

      b8 += n;
      b10 += n;
      b16 += n;

      num = &num[1];
    }

    cout << k << " " << (octal_bad ? 0 : b8)
         << " " << b10 << " " << b16 << endl;
  }
}
