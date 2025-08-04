// https://www.hackerrank.com/challenges/compare-the-triplets/problem

#include "../../Helpers/common.h"

namespace Algorithm {
using namespace std;

// Static Namespace Variables
int testCases{1};
int n{};
array<int, 3> alice{};
array<int, 3> bob{};
array<int, 2> result{};

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
void setup() {

  for (int i{}, arg{}; i < 3; ++i) {
    cin >> arg;
    alice[i] = arg;
  }
  for (int i{}, arg{}; i < 3; ++i) {
    cin >> arg;
    bob[i] = arg;
  }
  result = {0, 0};
}

void compute() {
  for (int i{}; i < 3; ++i) {
    if (alice[i] > bob[i]) {
      result[0] += 1;
    } else if (alice[i] < bob[i]) {
      result[1] += 1;
    }
  }
}

void output() {
  cout << result[0] << " " << result[1];
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
