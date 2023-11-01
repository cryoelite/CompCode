//

#define LOCAL

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
int testCases{1};
int k{};
int c{};
int A{};    // alphabet set/lexicon size
vvi trie{}; // we can use std::array too but the call-stack size is limited,
            // rather use heap
int result{};
vb eos{}; // end-of-string
int counter{};

#pragma endregion

void start();
void output(bool);
void compute();
void setup();
void commonSetupAndCleanInit();
void trie_insert(string_view);
bool search(string_view);

void start() {
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

#endif
  //    INPUT(testCases);
  while (testCases-- > 0) {
    commonSetupAndCleanInit();
    setup();
    compute();
  }
}

void setup() {
  INPUT(k, A, c);
  trie = vvi(cN, vi(A, 0));
  eos = vb(cN, false);
  counter = 0;
  {
    string arg{};
    cin.ignore(intmax, '\n');
    for (int i{}; i < k; ++i) {
      getline(cin, arg);
      trie_insert(arg);
    }
  }
}

// Trie
void compute() {
  string arg{};
  while (c-- > 0) {
    getline(cin, arg);
    output(search(arg));
  }
}

void trie_insert(string_view s) {
  int sz{cast(s.size())};
  int next{};

  for (int i{}; i < sz; ++i) {
    int &elem{trie[next][cast(s[i] % A)]};
    if (!elem)
      elem = ++counter;

    next = elem;
  }
  eos[next] = true;
}

bool search(string_view s) {
  int sz{cast(s.size())};
  int next{};
  for (int i{}; i < sz; ++i) {
    int &elem{trie[next][cast(s[i] % A)]};
    if (!elem)
      return false;

    next = elem;
  }
  return eos[next];
}

void output(bool result) {
  cout << boolalpha;
  cout << result << "\n";
}

void commonSetupAndCleanInit() {}

} // namespace Algorithm

signed main() {
#ifdef LOCAL
  EasyBench eb{};
#endif

  Algorithm::start();

#ifdef LOCAL
  eb.showresult();
#endif
  return 0;
}
