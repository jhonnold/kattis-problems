#include <iostream>
#include <cmath>

using namespace std;

double cosh(double x) {
  return (exp(x) + exp(-1 * x)) / 2;
}

double sinh(double x) {
  return (exp(x) - exp(-1 * x)) / 2;
}

double f(double a, int d, int s) {
  return a * cosh(d /(2 * a)) - a - s;
}

double binSearch(double l, double u, int d, int s) {
  double m = (l + u) / 2;
  double val = f(m, d, s);

  if (abs(val) < 0.000001) {
    return m;
  }

  if (val > 0) {
    return binSearch(m, u, d, s);
  } else if (val < 0) {
    return binSearch(l, m, d, s);
  } else {
    return m;
  }
}

int main() {
  int d, s;

  cin >> d >> s;

  double a = binSearch(0, 1000000000, d, s);
  double l = 2 * a * sinh(d / (2 * a));

  printf("%.9f\n", l);
}
