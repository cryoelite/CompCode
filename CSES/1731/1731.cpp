// https://cses.fi/problemset/task/1731

//#define LOCAL

#pragma region Headers

#ifdef LOCAL
#include "../../Helpers/Easybench/Easybench.h"
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
constexpr int cN{200005};   // const N
constexpr int cBN{1000005}; // Bigger N
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
int testCases{1};
string s{};
int sz{};
int n{};
int A{};    // alphabet set/lexicon size
vvi trie{}; // we can use std::array too but the call-stack size is limited,
            // rather use heap
vb eos{};   // end-of-string
int counter{};
vi dpTable{};

#pragma endregion

void start();
void setup();
void compute();
void trie_insert(string_view);
void output();
int search(int);

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
  getline(cin, s);
  INPUT(n);
  A = 26;
  sz = cast(s.size());
  trie = vvi(cBN, vi(A, 0));
  eos = vb(cBN, false);
  counter = 0;
  dpTable = vi(sz + 1, 0);
  string arg{};
  cin.ignore(cN,'\n');
  while (n-- > 0) {
    getline(cin, arg);
    trie_insert(arg);
  }
}

void compute() {
  dpTable[sz] = 1;
  for (int i{sz - 1}; i >= 0; --i) {
    dpTable[i] = search(i);
  }
}
void trie_insert(string_view s) {
  int size_s{cast(s.size())};
  int next{};
  for (int i{}; i < size_s; ++i) {
    int &elem{trie[next][cast(s[i]%A)]};
    if (!elem)
      elem = ++counter;

    next = elem;
  }
  eos[next] = true;
}
int search(int x) {
  int next{};
  int ans{};
  for (int i{x}; i < sz; ++i) {
    int &elem{trie[next][cast(s[i]%A)]};
    if (!elem)
      return ans;
    next = elem;
    if (eos[next]) {
      ans += dpTable[i + 1];
      ans %= mod10_e9_7;
    }
  }
  return ans;
}

void output() { cout << dpTable[0] << "\n"; }

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
