// https://cses.fi/problemset/task/1731

// #define LOCAL

#include "../../Helpers/common.h"

namespace Algorithm {
using namespace std;

#pragma region Variables
int testCases{1};
int n{};
vi results{};

#pragma endregion

void start();
void setup();
void compute();
void output();

void start() {
  int testCases{1};

  IOS;
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
  // cin.ignore(intmax, '\n');
#endif

  while (testCases-- > 0) {
    setup();
    compute();
    output();
  }
}
void setup() {
  INPUT(n);
  results = vi({n});
}

void compute() {
  while (n > 1) {

    if (n % 2 == 0) {
      n /= 2;
    } else {
      n = (n * 3) + 1;
    }
    results.pb(n);
  }
}

void output() {
  for (int &elem : results) {
    cout << elem << " ";
  }
  cout << "\n";
}

} // namespace Algorithm
  //
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
