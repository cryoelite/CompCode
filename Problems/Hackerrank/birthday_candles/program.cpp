// https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true

#include "../../Helpers/common.h"

namespace Algorithm {
using namespace std;

// Static Namespace Variables
int testCases{1};
int n{};
vi arr{};
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

void setup() {
  cin >> n;
  arr = vi(n, 0);

  for (int i{}, arg{}; i < n; ++i) {
    cin >> arg;
    arr[i] = arg;
  }
}

void compute() {
  int max_elem{arr[0]};
  for (int i{}; i < n; ++i) {
    if (arr[i] == max_elem) {
      ++result;
    } else if (arr[i] > max_elem) {
      max_elem = arr[i];
      result = 1;
    }
  }
}

void output() {
  cout << result;
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
