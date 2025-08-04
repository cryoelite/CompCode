// https://cses.fi/problemset/task/2192

#define LOCAL

#include "../../Helpers/common.h"

namespace Algorithm {
using namespace std;
void start();
void output();
double crossProduct(CD &, CD &, CD &);
bool isMid(CD &, CD &, CD &);
bool comparatorCD(CD &, CD &);

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
    INPUT(n, m);

    double arg1{};
    double arg2{};

    pips = vcd(n);
    points = vcd(m);
    results = vs(m);
    for (int i{}; i < n; ++i) {

      INPUT(arg1, arg2);

      pips[i] = CD{arg1, arg2};
    }
    for (int i{}; i < m; ++i) {

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

// Raycasting Alg
void start() {
  CD extPoint{1e9 + 1,
              -1e9 + 1}; // Any point on the outside.
                         // We can use this point to check if any line segment
                         // from this point to any other point intersects with
                         // the polygon and hence performing Ray casting.
  bool isBoundary{false};
  for (int i{}, countsPoint{}; i < m; ++i, countsPoint = 0) {
    isBoundary = false;
    for (int j{}; j < n; ++j) {
      CD &p1{points[i]};
      CD &p2{extPoint};

      CD &pips1{pips[j]};
      CD &pips2{pips[(j + 1) % n]};

      double resPip1{crossProduct(p1, p2, pips1)};
      double resPip2{crossProduct(p1, p2, pips2)};
      double resP1{crossProduct(pips1, pips2, p1)};
      double resP2{crossProduct(pips1, pips2, p2)};

      if (resP1 == 0 && isMid(pips1, p1, pips2)) {
        isBoundary = true;
        break;
      } else if ((resPip1 * resPip2) < 0 && (resP1 * resP2) < 0) {
        countsPoint++;
      }
    }
    if (isBoundary) {
      results[i] = "BOUNDARY";
    } else if (countsPoint == 0 || countsPoint % 2 == 0) {
      results[i] = "OUTSIDE";
    } else {
      results[i] = "INSIDE";
    }
  }
  output();
}

void output() {
  for (auto &result : results) {
    std::cout << result << '\n';
  }
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
