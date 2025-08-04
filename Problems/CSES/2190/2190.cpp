// Problem: https://cses.fi/problemset/task/2190

#define LOCAL

#include "../../Helpers/common.h"

namespace Algorithm {
using namespace std;
void start();
void output();
void init();
double crossProduct(CD &, CD &, CD &);
bool comparatorCD(CD &, CD &);
bool isMid(CD &, CD &, CD &);

void setup() {
  IOS;
#ifdef LOCAL
  FILE *inpStream;
  FILE *outStream;
  freopen_s(&inpStream, "input.txt", "r", stdin);
  freopen_s(&outStream, "output.txt", "w", stdout);
#endif
  INPUT(testCases);

  while (testCases-- > 0) {

    // init();
    double arg1{};
    double arg2{};

    INPUT(arg1, arg2);
    a1 = CD{arg1, arg2};

    INPUT(arg1, arg2);
    a2 = CD{arg1, arg2};

    INPUT(arg1, arg2);
    b1 = CD{arg1, arg2};

    INPUT(arg1, arg2);
    b2 = CD{arg1, arg2};

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

bool comparatorCD(CD &a, CD &b) {
  return (a.R == b.R) ? (a.I < b.I) : (a.R < b.R);
}
/// @brief checks if the point b is in middle on the cartesian plane with
/// respect to the other args.
/// @param a
/// @param b
/// @param c
/// @return
bool isMid(CD &a, CD &b, CD &c) {
  std::vector<CD> temp{a, b, c};
  std::sort(temp.begin(), temp.end(), comparatorCD);

  return temp[1] == b;
}

void start() {
  double resA1{crossProduct(b1, b2, a1)};

  double resA2{crossProduct(b1, b2, a2)};

  double resB1{crossProduct(a1, a2, b1)};

  double resB2{crossProduct(a1, a2, b2)};

  result = "NO";

  if (resB1 == 0 && isMid(a1, b1, a2)) {
    result = "YES";
  } else if (resB2 == 0 && isMid(a1, b2, a2)) {
    result = "YES";
  } else if (resA1 == 0 && isMid(b1, a1, b2)) {
    result = "YES";
  } else if (resA2 == 0 && isMid(b1, a2, b2)) {
    result = "YES";
  }
  if ((resA1 * resA2) < 0 && (resB1 * resB2) < 0) // case 3
  {
    result = "YES";
  }

  output();
}

void output() {
  std::cout << result;
  std::cout << std::endl;
}

void init() { result = ""; }
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
