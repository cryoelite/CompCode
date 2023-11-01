// https://cses.fi/problemset/task/2194

//#define LOCAL

#pragma region Headers

#ifdef LOCAL
#include "../../Helpers/Easybench/Easybench.h"
#include <algorithm>
#include <array>
#include <complex>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string_view>
#include <tuple>
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
#define R real()
#define I imag()
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
int n{};
vci totalSegs;
#pragma endregion

void start();
void output(int);
void compute();
void setup();
void commonSetupAndCleanInit();

bool comparator(CI &, CI &);
int dist(CI &, CI);

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
    setup();
    compute();
  }
}

void setup() {

  INPUT(n);
  totalSegs = vci(n, CI());
  for (int i{}, arg1{}, arg2{}; i < n; ++i) {

    INPUT(arg1, arg2);

    totalSegs[i] = CI({arg1, arg2});
  }
  sort(totalSegs.begin(), totalSegs.end(), comparator);
}

void compute() {
  int d{INF};
  std::set<pii> pp{}; // processed points
  pp.insert(pii(totalSegs[0].I, totalSegs[0].R));

  for (int i{1}, j{0}; i < n; ++i) {
    CI &current{totalSegs[i]};
    int ed = ceil(sqrt(d)); // euclidean distance converted to int
    while (j < i &&
           current.R - totalSegs[j].R >
               ed) { // current.R or x axis will be always greater or equal to
      // the points before because of how we sorted totalSegs
      pp.erase({totalSegs[j].I, totalSegs[j].R});
      j++;
    }

    auto itLB{pp.lower_bound({current.I - ed, 0})}; // iterator lower bound
    auto itUB{pp.upper_bound({current.I + ed, 0})};
    while (itLB != itUB) {
      d = min(d, dist(current, {itLB->second, itLB->first}));
      itLB++;
    }
    pp.insert({current.I, current.R});
  }

  output(d);
}

void output(int result) {

  std::cout << result << '\n';

  std::cout << std::endl;
}

void commonSetupAndCleanInit() {}
bool comparator(CI &a, CI &b) { return (a.R == b.R) ? a.I < b.I : a.R < b.R; }

int dist(CI &a, CI b) {

  return ((a.R - b.R) * (a.R - b.R)) + ((a.I - b.I) * (a.I - b.I));
}

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
