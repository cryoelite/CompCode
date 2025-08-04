// https://cses.fi/problemset/task/1069

#include "../../Helpers/common.h"

namespace Algorithm {
using namespace std;

// Static Namespace Variables
int testCases{1};
int result{};

// Function Signatures
void start();
void setup();
void compute();
void output();

// Function Bodies
void start() {
  IOS;

  // I/O Stream pointed at local text files
#ifdef LOCAL

#ifdef freopen_s // windows
  FILE *inpStream;
  FILE *outStream;

  freopen_s(&inpStream, "input.txt", "r", stdin);
  freopen_s(&outStream, "output.txt", "w", stdout);

#else // linux
  freopen64("input.txt", "r", stdin);
  freopen64("output.txt", "w", stdout);

#endif

  // INPUT(testCases);
#endif

  while (testCases-- > 0) {
    setup();
    compute();
    output();
  }
}
void setup() { result = 0; }

void compute() {
  char arg{};
  char lastArg{};
  int localCount{1};
  while (cin >> arg) {
    if (arg == lastArg) {
      localCount++;
      result = max(localCount, result);
    } else {
      localCount = 1;
    }

    lastArg = arg;
  }
  result = max(result, localCount);
}

void output() {
  cout << result;
  cout << "\n";
}

} // namespace Algorithm

#define STARTLOCAL Algorithm::start();

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
