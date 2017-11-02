#include <iostream>
#include <limits.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int graph[n][n];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> graph[i][j];
    }
  }

  int mst[n];
  int key[n];
  bool mstSet[n];

  for (int i = 0; i < n; i++) {
    key[i] = INT_MAX;
    mstSet[i] = false;
  }

  key[0] = 0;
  mst[0] = -1;

  for (int c = 0; c < n - 1; c++) {
    int min = INT_MAX;
    int min_i;

    for (int v = 0; v < n; v++) {
      if (mstSet[v] == false && key[v] < min) {
        min = key[v];
        min_i = v;
      }
    }

    mstSet[min_i] = true;
    for (int v = 0; v < n; v++) {
      if (graph[min_i][v] && mstSet[v] == false && graph[min_i][v] < key[v]) {
        mst[v] = min_i;
        key[v] = graph[min_i][v];
      }
    }
  }

  for (int i = 1; i < n; i++) {
    printf("%d %d\n", mst[i] + 1, i + 1);
  }

  return 0;
}
