#include <iostream>
using namespace std;

int main() {
  int n, t, c = 0;
  cin >> n;
  while (n-- > 0) {
    cin >> t;
    if (t < 0) c++;
  }
  cout << c << endl;
}
