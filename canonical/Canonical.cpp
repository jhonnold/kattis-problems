#include <iostream>
#include <limits.h>
using namespace std;

// d -> denominations
// s -> previous solutions
int minCoins(int c, int n, int* d, int* s) {
  int min = INT_MAX;
  for (int i = 0; i < n; i++)
    if (c - d[i] >= 0)
      if (1 + s[c - d[i]] < min)
        min = 1 + s[c - d[i]];

  return min;
}

int minCoinsGreedy(int c, int n, int* d) {
  int i = n - 1, a = 0;
  while (c > 0) {
    while (d[i] > c) i--;
    c -= d[i];
    a++;
  }
  return a;
}

int main() {
  int n;
  cin >> n;

  int *d = new int[n];
  for (int i = 0; i < n; i++)
    cin >> d[i];

  int max = d[n - 1] + d[n - 2];
  int *s = new int[max + 1];
  s[0] = 0;
  for (int i = 1; i <= max; i++) {
    s[i] = minCoins(i, n, d, s);
    if (s[i] != minCoinsGreedy(i, n, d)) {
      cout << "non-canonical" << endl;
      return 0;
    }
  }

  cout << "canonical" << endl;

  return 0;
}
