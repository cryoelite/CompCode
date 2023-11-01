// https://leetcode.com/problems/longest-common-subsequence/

#define LOCAL

#pragma region Headers

#ifdef LOCAL
#include "../Helpers/Easybench/Easybench.h"
#include <algorithm>
#include <array>
#include <complex>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string_view>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#else
#include <bits/stdc++.h>
#endif // LOCAL
#pragma endregion

#pragma region Defines
#define int long long
#define double long double
#define LOG(x) static_cast<int>(std::floor(std::log2(x)))
#define IOS                                                                    \
  std::ios_base::sync_with_stdio(false);                                       \
  std::cin.tie(0);                                                             \
  std::cout.tie(0);
template <typename... T> void INPUT(T &...args) { ((std::cin >> args), ...); }
template <typename... T> void OUTPUT(T &...args) {
  ((std::cout << args << " "), ...);
  std::cout << "\n";
}
#define ARR_INPUT(arr, x)                                                      \
  for (int i{0}; i < x; ++i) {                                                 \
    int y;                                                                     \
    std::cin >> y;                                                             \
    arr.push_back(y);                                                          \
  }
#define cast(i) static_cast<int>(i)
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
#define revit std::reverse_iterator
#define pb push_back
#define sk std::stack
#define X real()
#define Y imag()
#define tiii std::tuple<int, int, int>
#define mmi std::make_move_iterator
#pragma endregion

#pragma region Constants
constexpr int mod10{10000007};
constexpr int cN{200005}; // const N
constexpr int INF{std::numeric_limits<int>::max()};
constexpr int mINF{std::numeric_limits<int>::min()};
#pragma endregion

#pragma region Usings
using usi = std::unordered_set<int>;
using umi = std::unordered_map<int, int>;
using vi = std::vector<int>;
using si = std::set<int>;
using sd = std::set<double>;
using vvi = std::vector<vi>;
using pivi = std::pair<int, vi>; // first is node's value and second is node's
                                 // adjacent elements
using pii = std::pair<int, int>;
using vpii = std::vector<pii>; // edge list
using vtiii = std::vector<tiii>;
using vvtiii = std::vector<vtiii>; // adjacency list with adjacent node id, edge
                                   // weight and an extra value.
using vpivi = std::vector<pivi>;
using vvpii =
    std::vector<vpii>; // adjacency list with edge weights, the pii has first as
                       // node id and second as the edge weight
using mii = std::map<int, int>;
using vmii = std::vector<mii>;
using vb = std::vector<bool>; // vector<bool> is a special explicit definition
                              // of vector and behaves more like a bitset than a
                              // vector, also it is faster than array<bool>
                              // https://stackoverflow.com/a/55762317/13036358
using vvb = std::vector<vb>;
using ri = revit<vi::iterator>;
using ski = sk<int>;
using CD = std::complex<double>;
using CI = std::complex<int>; // DEPRECATED
using pqd = std::priority_queue<double>;
using pqi = std::priority_queue<int>;
using pqpii = std::priority_queue<pii>;
using vcd = std::vector<CD>;
using vci = std::vector<CI>;
using pcd = std::pair<CD, CD>;
using pci = std::pair<CI, CI>;
using vpcd = std::vector<pcd>;
using vpci = std::vector<pci>;
using vs = std::vector<std::string_view>;
#pragma endregion

namespace Algorithm {
using namespace std;

#pragma region Variables
string s1;
string s2;

vvi memoTable;
vvi dpTable;

int result{};
#pragma endregion

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
