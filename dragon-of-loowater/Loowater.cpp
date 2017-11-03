#include <iostream>
using namespace std;

int comp(const void* p, const void* q) {
  int* a = (int*) p;
  int* b = (int*) q;
  return *a - *b;
}

int main() {
  while (true) {
    int n, m;
    cin >> n >> m;
    if (n == 0 && m == 0) break;

    int heads[n];
    for (int i = 0; i < n; i++)
      cin >> heads[i];

    int knights[m];
    for (int i = 0; i < m; i++)
      cin >> knights[i];

    qsort(heads, n, sizeof(int), comp);
    qsort(knights, m, sizeof(int), comp);

    bool doomed = false;
    int cost = 0;

    for (int i = 0, j = 0; i < n && !doomed; i++) {
      while (j < m && knights[j] < heads[i]) j++;
      if (j >= m) doomed = true;
      else cost += knights[j++];
    }

    if (doomed)
      cout << "Loowater is doomed!" << endl;
    else
      cout << cost << endl;
  }
}
