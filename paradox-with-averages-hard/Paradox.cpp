#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  while (n-- > 0) {
    int n_c, n_e;
    double cs_avg = 0, e_avg = 0;

    cin >> n_c >> n_e;

    int cs[n_c];
    for (int i = 0; i < n_c; i++) {
      cin >> cs[i];
      cs_avg = (cs_avg * i + cs[i]) / (i + 1);
    }

    int e;
    for (int i = 0; i < n_e; i++) {
      cin >> e;
      e_avg = (e_avg * i + e) / (i + 1);
    }

    int c = 0;

    for (int i = 0; i < n_c; i++)
      if (cs[i] < cs_avg && cs[i] > e_avg) c++;

    cout << c << endl;
  }
}
