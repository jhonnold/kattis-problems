#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Pair {
  int to;
  int value;
};

int main() {
  int n, t, k, s, v, c;
  queue<int> dead;
  cin >> n;

  int surplus[100000] = {0};
  vector<Pair> from_to[100000];
  vector<Pair> :: iterator ip;

  for (int i = 0; i < n; i++) {
    cin >> t >> k;
    while (k-- > 0) {
      Pair p;
      cin >> s >> v;
      p.to = i;
      p.value = v;
      from_to[s - 1].push_back(p);
      surplus[i] += v;
    }
    surplus[i] -= t;
  }

  dead.push(0);
  surplus[0] = -1;
  c = 0;
  while (!dead.empty()) {
    c++;
    int dead_isle = dead.front();
    dead.pop();
    for (ip = from_to[dead_isle].begin(); ip != from_to[dead_isle].end(); ++ip) {
      if (surplus[ip->to] >= 0) {
        surplus[ip->to] -= ip->value;
        if (surplus[ip->to] < 0) dead.push(ip->to);
      }
    }
  }

  cout << n - c << endl;

  return 0;
}
