// https://leetcode.com/problems/edit-distance/

#define LOCAL

#include "../Helpers/common.h"

void start();
void setup();
void compute();
void output();

void start() {
  int testCases{1};

  IOS;
#ifdef LOCAL
#ifndef freopen_s // windows
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
  result = 0;
  size_s1 = cast(s1.size());
  size_s2 = cast(s2.size());
  edit_MemoTable = vvi(size_s1, vi(size_s2, -1));
}

inline int cost(int a, int b) { return cast(s1[a] != s2[b]); }

int edit(int a, int b) {
  if (min(a, b) < 0) {
    return max(a, b) + 1;
  }

  if (edit_MemoTable[a - 1][b] == -1) {
    edit_MemoTable[a - 1][b] = edit(a - 1, b) + 1;
  }
  if (edit_MemoTable[a][b - 1] == -1) {
    edit_MemoTable[a][b - 1] = edit(a, b - 1) + 1;
  }
  if (edit_MemoTable[a - 1][b - 1] == -1) {
    edit_MemoTable[a - 1][b - 1] = edit(a - 1, b - 1) + cost(a, b);
  }

  int min_a_or_b{min(edit_MemoTable[a - 1][b], edit_MemoTable[a][b - 1])};
  return min(min_a_or_b, edit_MemoTable[a - 1][b - 1]);
}

void compute() { result = edit(size_s1 - 1, size_s2 - 1); }

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
  int minDistance(string text1, string text2) { STARTLC; }
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
