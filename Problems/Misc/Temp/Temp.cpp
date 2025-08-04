// https://cses.fi/problemset/task/1660

#include "../../Helpers/common.h"
}

namespace SetupEnvironment {
using namespace Definitions;

// Function Bodies
void setupIO() {
  IOS;

  // I/O Stream pointed at local text files
#ifdef LOCAL

#ifndef freopen_s // windows
  FILE *inpStream;
  FILE *outStream;

  freopen_s(&inpStream, "input.txt", "r", stdin);
  freopen_s(&outStream, "output.txt", "w", stdout);

#else // linux
  freopen64("input.txt", "r", stdin);
  freopen64("output.txt", "w", stdout);

#endif

#endif
}

}

namespace Solution {
using namespace Definitions;
using namespace SetupEnvironment;
using namespace std;
void start();
void initialize();
void compute();
void output();

int testCases{1};

int n{};
int x{};
vi arr{};
int result{2};

void start() {
  setupIO();
  // INPUT(testCases);
  while (testCases-- > 0) {
    initialize();
    compute();
    output();
  }
}

void initialize() {}

void compute() {}

void output() {
  cout << result;
  cout << '\n';
}

}

#define STARTLOCAL Solution::start();

signed main() {
#ifdef LOCAL
  EasyBench eb{};
#endif

  STARTLOCAL;

#ifdef LOCAL
  eb.showresult();
#endif
  return 0;
}
