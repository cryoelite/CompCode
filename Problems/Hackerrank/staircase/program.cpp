// https://www.hackerrank.com/challenges/staircase/problem?isFullScreen=true

#include "../../Helpers/common.h"

namespace Algorithm {
using namespace std;

// Static Namespace Variables
int testCases{1};
int n{};

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

void setup() { cin >> n; }

// Nothing to compute
void compute() {}

void output() {
  for (int i{}, spaces{n - 1}, hashes{1}; i < n;
       ++i, hashes = i + 1, spaces = n - hashes) {
    while (spaces-- > 0) {
      cout << " ";
    }
    while (hashes-- > 0) {
      cout << "#";
    }
    cout << "\n";
  }
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
