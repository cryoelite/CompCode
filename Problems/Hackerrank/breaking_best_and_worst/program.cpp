// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem

// #define LOCAL

#include "../../../Helpers/common.h"

namespace Algorithm {
using namespace std;

// Static Namespace Variables
int testCases{1};
int n{};
vi scores{};
int max_breaks{};
int min_breaks{};

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
  max_breaks = 0;
  min_breaks = 0;
  scores = vi(n, 0);
  for (int i{}, arg{}; i < n; ++i) {
    cin >> arg;
    scores[i] = arg;
  }
}

void compute() {
  int max_elem{scores[0]};
  int min_elem{scores[0]};

  for (int i{1}, score{scores[1]}; i < n; ++i, score = scores[i]) {
    if (score > max_elem) {
      max_elem = score;
      ++max_breaks;
    }
    if (score < min_elem) {
      min_elem = score;
      ++min_breaks;
    }
  }
}

void output() {
  cout << max_breaks << " " << min_breaks;
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
