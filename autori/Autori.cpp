#include <iostream>
using namespace std;

int main() {
  string line;
  getline(cin, line);

  while (line[0] != '\0') {
    if (line[0] >= 65 && line[0] <= 90) cout << line[0];
    line = &line[1];
  }

  cout << endl;

  return 0;
}
