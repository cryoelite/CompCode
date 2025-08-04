// https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true

#include "../../Helpers/common.h"

namespace Algorithm {
using namespace std;

// Static Namespace Variables
int testCases{1};
int m{};
int n{};
int a{};
int b{};
vi apples{};
vi oranges{};
int s{};
int t{};
int count_apples{};
int count_oranges{};

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
  cin >> s;
  cin >> t;
  cin >> a;
  cin >> b;
  cin >> m;
  cin >> n;

  apples = vi(m, 0);
  oranges = vi(n, 0);
  for (int i{}, arg{}; i < m; ++i) {
    cin >> arg;
    apples[i] = (arg);
  }
  for (int i{}, arg{}; i < n; ++i) {
    cin >> arg;
    oranges[i] = (arg);
  }
}

void compute() {
  for (int i{}, sum_a{}; i < m; ++i) {
    sum_a = a + apples[i];
    if (sum_a >= s && sum_a <= t) {
      ++count_apples;
    }
  }

  for (int i{}, sum_o{}; i < n; ++i) {
    sum_o = b + oranges[i];
    if (sum_o >= s && sum_o <= t) {
      ++count_oranges;
    }
  }
}

void output() {
  cout << count_apples << '\n';
  cout << count_oranges;
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
