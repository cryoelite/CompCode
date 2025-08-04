// https://cses.fi/problemset/task/2194

// #define LOCAL

#include "../../Helpers/common.h"

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
