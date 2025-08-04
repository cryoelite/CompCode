// https://leetcode.com/problems/longest-common-subsequence/https://leetcode.com/problems/longest-common-subsequence/

#define LOCAL

#include "../Helpers/common.h"

void start();
void resetState();
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
  INPUT(testCases);
#endif

  while (testCases-- > 0) {
    setup();
    resetState();
    compute();
    output();
  }
}
void setup() {
#ifdef LOCAL
  cin.ignore(intmax, '\n');
  getline(cin, s1);
  getline(cin, s2);
#else

#endif
}

// Resetting state variables before they are used
void resetState() { result = 0; }

// Trie
void compute() {}

void output() { cout << result << "\n"; }

} // namespace Algorithm
#define STARTLC                                                                \
  Algorithm::s1 = text1;                                                       \
  Algorithm::s2 = text2;                                                       \
  Algorithm::start();                                                          \
  return Algorithm::result;

#define STARTLOCAL Algorithm::start();

namespace {
using namespace std;
class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) { STARTLC; }
};
} // namespace
#undef int

#ifdef LOCAL
signed main() {

  EasyBench eb{};

  STARTLOCAL;

  eb.showresult();

  return 0;
}
#endif
