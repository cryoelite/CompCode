// https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true

// #define LOCAL

#include "../../../Helpers/common.h"

namespace Algorithm {
using namespace std;

// Static Namespace Variables
int testCases{1};
int x1{};
int v1{};
int x2{};
int v2{};
char result[4]{};

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
  cin >> x1;
  cin >> v1;
  cin >> x2;
  cin >> v2;
  strcpy(result, "");
}

void compute() {
  if (x1 == x2) {
    strcpy(result, "YES");
    return;
  }
  if (v1 == v2) {
    strcpy(result, "NO");
    return;
  }

  int y{};
  y = (x2 - x1) / (v1 - v2);
  if (y > 0) {
    strcpy(result, "YES");
  } else {
    strcpy(result, "NO");
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
