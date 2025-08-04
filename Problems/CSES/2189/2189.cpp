// Problem: https://cses.fi/problemset/task/2189

#define LOCAL

#include "../../Helpers/common.h"

namespace Algorithm {
using namespace std;
void start();
void output();
void bfs(int, bool);
bool bfa(int);
void init();

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

    init();
    double arg1{};
    double arg2{};

    INPUT(arg1, arg2);
    x = CD{arg1, arg2};

    INPUT(arg1, arg2);
    y = CD{arg1, arg2};

    INPUT(arg1, arg2);
    p = CD{arg1, arg2};

    start();
  }
}

void start() {
  ;
  CD a{p - x};
  CD b{p - y};
  double res{(conj(a) * b).I};
  if (res == 0)
    result = "TOUCH";
  else if (res < 0)
    result = "RIGHT";
  else
    result = "LEFT";
  output();
}

void output() {
  std::cout << result;
  std::cout << std::endl;
}

void init() {
  x = {};

  y = {};

  p = {};

  result = "";
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
