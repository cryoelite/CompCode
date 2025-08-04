// https://cses.fi/problemset/task/2193

#define LOCAL

#include "../../Helpers/common.h"

namespace Algorithm {
using namespace std;
void start();
void output();
double crossProduct(CD &, CD &, CD &);
bool isMid(CD &, CD &, CD &);
bool comparatorCD(CD &, CD &);
int gcd(int, int);

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

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

// Pick's Theorem + https://math.stackexchange.com/a/301895/1103748 for boundary
// lattice points
//+ https://math.stackexchange.com/a/849003/1103748 for interior lattice points
void start() {
  CD const translatedA{0, 0};
  CD translatedB{};
  int area{};
  for (int i{}; i < n; ++i) {
    CD &tempA{points[i]};
    CD &tempB{points[(i + 1) % n]};

    translatedB =
        tempB -
        tempA; // translating A to B to 0 to C where C is (B.x-A.x,B.y-A.y),
               // i.e., the same length as A to B but from origin.

    lBoundary += abs(gcd(translatedB.R, translatedB.I));

    area += ((conj(tempA) * tempB)).I;
  }
  area = abs(area) / 2;
  lInside = (area + 1) - (lBoundary / 2);
  output();
}

void output() {

  std::cout << lInside << " " << lBoundary << '\n';

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
