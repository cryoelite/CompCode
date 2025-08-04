// https://www.hackerrank.com/challenges/diagonal-difference/problem

#include "../../Helpers/common.h"

namespace Algorithm {
using namespace std;

// Static Namespace Variables
int testCases{1};
int n{};
int result{};
vvi matrix{};
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
  cin >> n;
  matrix = vvi(n, vi(n, 0));

  for (int i{}; i < n; ++i) {
    for (int j{}, arg{}; j < n; ++j) {
      cin >> arg;
      matrix[i][j] = arg;
    }
  }
}

void compute() {
  int sum1{}, sum2{};
  for (int i{}; i < n; ++i) {
    for (int j{}; j < n; ++j) {
      if (i == j) {
        sum1 += matrix[i][j];
      }
      if (i == n - j - 1) {
        sum2 += matrix[i][j];
      }
    }
  }

  result = abs(sum1 - sum2);
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
