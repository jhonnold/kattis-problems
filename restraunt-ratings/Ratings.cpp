#include <iostream>
using namespace std;

long long choose(int n, int k) {
  if (k > n) return 0;
  if (k * 2 > n) k = n - k;
  if (k == 0) return 1;

  long long result = n;
  for (int i = 2; i <= k; i++) {
    result *= (n - i + 1);
    result /= i;
  }
  return result;
}

int main() {
  while (true) {
    int n;
    cin >> n;
    if (n <= 0) break;

    int ratings[n], rating = 0;
    for (int i = 0; i < n; i++) {
      cin >> ratings[i];
      rating += ratings[i];
    }

    long long w = 0;
    for (int i = 0; i < rating; i++) {
      w += choose(i + n - 1, i);
    }

    for (int i = 0, pre = 0; i < n - 1; pre += ratings[i++])
      for (int j = 0; j < ratings[i]; j++)
        w += choose(rating - j - pre + n - i - 2, n - i - 2);

    cout << w + 1 << endl;
  }
  return 0;
}
