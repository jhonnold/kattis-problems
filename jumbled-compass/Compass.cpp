#include <iostream>
using namespace std;

int main() {
  int n1, n2, gap;

  cin >> n1 >> n2;

  gap = (n2 - n1 < 0) ? n2 - n1 + 360 : n2 - n1;
  gap = (gap > 180) ? gap - 360 : gap;

  cout << gap << endl;

  return 0;
}
