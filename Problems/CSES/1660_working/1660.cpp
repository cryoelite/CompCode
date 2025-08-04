// https://cses.fi/problemset/task/1660

#include "../../Helpers/common.h"
}

namespace Signatures {
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
using namespace Signatures;
using namespace std;

int testCases{1};

int n{};
int x{};
vi arr{};
int result{};

void start() {
  // INPUT(testCases);
  while (testCases-- > 0) {
    setup();
    compute();
    output();
  }
}

void setup() {
  cin >> n;
  cin >> x;
  arr = vi(n, 0);

  for (int i{}, arg{}; i < n; ++i) {
    cin >> arg;
    arr[i] = arg;
  }
}

void compute() {
  int l{0};
  int r{0};
  int sum{0};
  while (l <= r && r < n) {
    if (sum > x) {
      sum -= arr[l];
      ++l;
    }
    if (sum < x) {
      ++r;
      sum += arr[r];
    }
    if (sum == x) {
      ++result;
      sum -= arr[l];
      ++l;
    }
  }
}

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
