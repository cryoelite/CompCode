// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true

#include "../../Helpers/common.h"

namespace Algorithm {
using namespace std;

// Static Namespace Variables
int testCases{};
int grade{};
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
  INPUT(testCases);

  while (testCases-- > 0) {
    setup();
    compute();
    output();
  }
}

void setup() {
  result = 0;
  cin >> grade;
}

void compute() {
  if (grade < 38) {
    result = grade;
  } else {
    int nm5 = grade + (5 - (grade + 5) % 5);
    result = (nm5 - grade < 3) ? nm5 : grade;
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
