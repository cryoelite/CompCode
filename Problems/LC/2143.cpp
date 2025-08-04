// https://leetcode.com/problems/longest-common-subsequence/

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
  cin.ignore(intmax, '\n');
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
  getline(cin, s1);
  getline(cin, s2);
#else

#endif
  memoTable = vvi(s1.size(), vi(s2.size(), -1));
  dpTable = vvi(s1.size() + 1, vi(s2.size() + 1, 0));
}

// Resetting state variables before they are used
void resetState() { result = 0; }

// Bottom up, (size1,size2), Normal Recursion based approach, TLE
int lcs(int i, int j) {
  if (i < 0 || j < 0) {
    return 0;
  }

  if (s1[i] == s2[j]) {
    return 1 + lcs(i - 1, j - 1);
  } else {
    return max(lcs(i, j - 1), lcs(i - 1, j));
  }
}

// Bottom up, Recursion+Memoized, (size1,size2), a bit slower growth in TC
int lcsMemoized(int i, int j) {
  if (i < 0 || j < 0) {
    return 0;
  }

  if (memoTable[i][j] != -1) {
    return memoTable[i][j];
  }

  if (s1[i] == s2[j]) {
    memoTable[i][j] = 1 + lcsMemoized(i - 1, j - 1);
  } else {
    memoTable[i][j] = max(lcsMemoized(i, j - 1), lcsMemoized(i - 1, j));
  }
  return memoTable[i][j];
}
// Top to Bottom, 1 indexed, DP + Iterative + Memoized, O(nm)
int lcsDP() {
  for (int i{1}; i <= cast(s1.size()); ++i) {
    for (int j{1}; j <= cast(s2.size()); ++j) {
      dpTable[i][j] = s1[i - 1] == s2[j - 1]
                          ? 1 + dpTable[i - 1][j - 1]
                          : max(dpTable[i][j - 1], dpTable[i - 1][j]);
    }
  }
  return dpTable[s1.size()][s2.size()];
}

void compute() {
  // result = lcs(s1.size() - 1, s2.size() - 1);
  // result = lcsMemoized(s1.size() - 1, s2.size() - 1);
  result = lcsDP();
}

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
