// https://leetcode.com/problems/edit-distance/

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
constexpr int mod10_e9_7{1000000007};
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
int size_s1;
int size_s2;
vvi edit_MemoTable{};

int result{};
#pragma endregion

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
