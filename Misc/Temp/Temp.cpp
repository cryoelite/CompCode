// https://cses.fi/problemset/task/1660

// Local Mode (for local tests, take input from files), or comment this to be in Submission mode (take input from CLI)
// #define LOCAL

// Headers
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
#include <numeric>
#include <iomanip>
#ifdef LOCAL
#include "../../Helpers/Easybench/Easybench.h"
#endif // LOCAL

namespace Definitions

{
  // Defines
#define int long long
#define double long double
#define LOG(x) static_cast<int>(std::floor(std::log2(x)))
#define IOS                              \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(0);                       \
  std::cout.tie(0);
  template <typename... T>
  void INPUT(T &...args) { ((std::cin >> args), ...); }
  template <typename... T>
  void OUTPUT(T &...args)
  {
    ((std::cout << args << " "), ...);
    std::cout << "\n";
  }
#define ARR_INPUT(arr, x)    \
  for (int i{0}; i < x; ++i) \
  {                          \
    int y;                   \
    std::cin >> y;           \
    arr.push_back(y);        \
  }
#define ARR_OUTPUT(arr, sep) \
  for (auto &elem : arr)     \
  {                          \
    cout << elem << sep;     \
  }

#define cast(i) static_cast<int>(i)
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
#define pb push_back
#define X real()
#define Y imag()
#define tiii std::tuple<int, int, int>
#define mmi std::make_move_iterator

  // Constants
  constexpr int cmod10_e9_7{1000000007}; // const mod 10e9^7
  constexpr int cIN{200005};             // const N (fits in int)
  constexpr int cLN{1000005};            // const long N(fits in long long)

  // Type Aliases
  using usi = std::unordered_set<int>;
  using umii = std::unordered_map<int, int>;
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
  using ri = std::reverse_iterator<vi::iterator>;
  using ski = std::stack<int>;
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

}

namespace SetupEnvironment
{
  using namespace Definitions;

  // Function Bodies
  void setupIO()
  {
    IOS;

    // I/O Stream pointed at local text files
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

#endif
  }

}

namespace Solution
{
  using namespace Definitions;
  using namespace SetupEnvironment;
  using namespace std;
  void start();
  void initialize();
  void compute();
  void output();

  int testCases{1};

  int n{};
  int x{};
  vi arr{};
  int result{2};

  void start()
  {
    setupIO();
    // INPUT(testCases);
    while (testCases-- > 0)
    {
      initialize();
      compute();
      output();
    }
  }

  void initialize()
  {
  }

  void compute()
  {
  }

  void output()
  {
    cout << result;
    cout << '\n';
  }

}

#define STARTLOCAL Solution::start();

signed main()
{
#ifdef LOCAL
  EasyBench eb{};
#endif

  STARTLOCAL;

#ifdef LOCAL
  eb.showresult();
#endif
  return 0;
}
