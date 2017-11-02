#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  while (N-- > 0) {
    int k, m, n;
    cin >> k >> m >> n;

    int s = (int)(log(n) / log(m)) + 1;
    int c[s];
    c[0] = 1;
    for (int i = 1; i < s; i++)
      c[i] = m * c[i - 1];

    unsigned int r[n + 1];
    memset(r, 0, sizeof(r));
    r[0] = 1;

    for (int i = 0; i < s; i++)
      for (int j = c[i]; j <= n; j++)
        r[j] += r[j - c[i]];

    cout << k << " " << r[n] << endl;
  }

  return 0;
}
