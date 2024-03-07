// https://cses.fi/problemset/task/1083

//Local Mode (for local tests), or comment this to be in Submission mode
//#define LOCAL

//Headers
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

//Defines
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


//Constants
constexpr int mod10_e9_7{1000000007};
constexpr int cN{200005};   // const N
constexpr int cBN{1000005}; // Bigger N
constexpr int INF{std::numeric_limits<int>::max()};
constexpr int mINF{std::numeric_limits<int>::min()};


//Type Aliases
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


namespace Algorithm {
using namespace std;

//Static Namespace Variables
int testCases{1};
int n{};
int result{};
int initialSum{};

//Function Signatures
void start();
void setup();
void compute();
void output();


//Function Bodies
void start() {
  IOS;

  //I/O Stream pointed at text files
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
#endif

  while (testCases-- > 0) {
    setup();
    compute();
    output();
  }
}
void setup() {
  INPUT(n);
  initialSum=0;
  for(int i{0}, arg{}; i<n-1; ++i){
    INPUT(arg);
    initialSum+=arg;
  }
}

void compute() {
  int sumOfN{ (n*(n+1))/2 };
  result= sumOfN-initialSum;
}

void output() {
  cout<< result;
  cout<< "\n";
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
