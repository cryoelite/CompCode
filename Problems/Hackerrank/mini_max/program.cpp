// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true

#include "../../Helpers/common.h"

namespace Algorithm {
using namespace std;

// Static Namespace Variables
int testCases{1};
constexpr int n{5};
array<int, n> arr{};
int min_sum{};
int max_sum{};

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
  min_sum = 0;
  max_sum = 0;
  for (int i{}, arg{}; i < n; ++i) {
    cin >> arg;
    arr[i] = arg;
  }
}

void compute() {
  int total{0};
  int min_val{arr[0]};
  int max_val{arr[0]};
  for (int i{}; i < n; ++i) {
    total += arr[i];
    min_val = min(arr[i], min_val);
    max_val = max(arr[i], max_val);
  }
  min_sum = total - max_val;
  max_sum = total - min_val;
}

void output() {
  cout << min_sum << " " << max_sum;
  cout << '\n';
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
