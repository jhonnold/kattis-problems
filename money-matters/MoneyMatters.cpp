#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > f(10000, vector<int>(10000));
int d[10000];
bool v[10000];

void dfs(int p, int *c) {
  if (v[p]) return;
  v[p] = true;
  *c += d[p];
  for (int i = 0; i < f[p].size(); i++)
    if (!v[f[p][i]]) dfs(f[p][i], c);
}

int main() {
  int n, m, a, b, s;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> d[i];
    v[i] = false;
  }

  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    f[a].push_back(b);
    f[b].push_back(a);
  }

  for (int i = 0; i < n; i++) {
    s = 0;
    dfs(i, &s);
    if (s != 0) break;
  }

  if (s == 0) cout << "POSSIBLE" << endl;
  else cout << "IMPOSSIBLE" << endl;
}
