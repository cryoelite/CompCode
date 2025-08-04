// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

// #define LOCAL

#include "../../../Helpers/common.h"

namespace Algorithm {
using namespace std;

// Static Namespace Variables
int testCases{1};
int n{};
int m{};
vi a{};
vi b{};
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

#endif
  // INPUT(testCases);

  while (testCases-- > 0) {
    setup();
    compute();
    output();
  }
}

void setup() {
  cin >> n;
  cin >> m;
  result = 0;
  a = vi(n, 0);
  b = vi(n, 0);

  for (int i{}, arg{}; i < n; ++i) {
    cin >> arg;
    a[i] = arg;
  }
  for (int i{}, arg{}; i < m; ++i) {
    cin >> arg;
    b[i] = arg;
  }
}

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int lcm(int a, int b) { return abs(a * b) / gcd(a, b); }

void compute() {
  int a_lcm{a[0]};
  int b_gcd{b[0]};

  for (int i{}; i < n; ++i) {
    a_lcm = lcm(a_lcm, a[i]);
  }
  for (int i{}; i < m; ++i) {
    b_gcd = gcd(b_gcd, b[i]);
  }
  if (b_gcd % a_lcm != 0) {
    result = 0;
    return;
  }

  for (int i{a_lcm}; i <= b_gcd; i += a_lcm) {
    if (b_gcd % i == 0) {
      ++result;
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
