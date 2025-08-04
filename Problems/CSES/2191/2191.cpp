// https://cses.fi/problemset/task/2191

#define LOCAL

#include "../../Helpers/common.h"

namespace Algorithm {
using namespace std;
void start();
void output();
double crossProduct(CD &, CD &, CD &);

void setup() {
  IOS;
#ifdef LOCAL
  FILE *inpStream;
  FILE *outStream;
  freopen_s(&inpStream, "input.txt", "r", stdin);
  freopen_s(&outStream, "output.txt", "w", stdout);
#endif
  // INPUT(testCases);

  while (testCases-- > 0) {
    INPUT(n);

    double arg1{};
    double arg2{};

    points = vcd(n);
    for (int i{}; i < n; ++i) {

      INPUT(arg1, arg2);

      points[i] = CD{arg1, arg2};
    }

    start();
  }
}
// 2D vector cross product aka Complex Number Multiplication
double crossProduct(CD &a, CD &b, CD &p) {
  CD temp1{p - a};
  CD temp2{p - b};
  double result{(conj(temp1) * temp2).I};

  return result;
}

void start() {
  double value{};
  CD *next{nullptr};
  for (int i{}; i < n; ++i) {
    next = &points[(i + 1) % n];
    value += ((points[i].R * (*next).I) - ((*next).R * points[i].I));
  }

  result = static_cast<int>(abs(value)); // multiplying with 1/2 and 2, i.e. 1.
  output();
}

void output() {
  std::cout << result;
  std::cout << std::endl;
}

} // namespace Algorithm

signed main() {
#ifdef LOCAL
  EasyBench eb{};
#endif

  Algorithm::setup();

#ifdef LOCAL
  eb.showresult();
#endif
  return 0;
}
