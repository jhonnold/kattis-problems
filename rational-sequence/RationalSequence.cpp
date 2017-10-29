#include <iostream>
using namespace std;

void F(int n, unsigned int* p, unsigned int* q) {
  // Base case
  if (n == 1) {
    *p = 1;
    *q = 1;
    return;
  }

  // Get the p and q from the last node in the tree
  F(n / 2, p, q);

  // if its even then its left, else right
  if (n % 2 == 0)
    *q = *p + *q;
  else
    *p = *p + *q;

  return;
}

int main() {
  unsigned int p, q;
  int n, c, k;

  cin >> c;

  for (int i = 1; i <= c; i++) {
    cin >> k >> n;
    F(n, &p, &q);

    cout << k << " " << p << "/" << q << endl;
  }

  return 0;
}
