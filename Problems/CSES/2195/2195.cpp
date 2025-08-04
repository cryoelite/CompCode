// https://cses.fi/problemset/task/2195

// #define LOCAL

#include "../../Helpers/common.h"

void start();
void output(int, int);
void compute();
void setup();
void commonSetupAndCleanInit();
int dirn(CI &, CI &, CI &); // direction
int solveHull(vci &, std::function<bool(int)> &);

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
    commonSetupAndCleanInit();
    setup();
    compute();
  }
}

void setup() {

  INPUT(n);
  points = vci(n, CI());
  upperHull = vci();
  lowerHull = vci();
  for (int i{}, arg1{}, arg2{}; i < n; ++i) {

    INPUT(arg1, arg2);

    points[i] = CI({arg1, arg2});
  }
  sort(points.begin(), points.end(), comparator);
}

// Andrew's Algorithm
void compute() {
  std::function<bool(int)> check{
      [](int res) { return res > 0; }}; // point is to the left

  upperHull.pb(points[0]);
  lowerHull.pb(points[0]);

  int kUpper{solveHull(upperHull, check)};

  check = {[](int res) { return res < 0; }}; // point is to the right

  int kLower{solveHull(lowerHull, check)};
  output(kUpper, kLower);
}

int solveHull(vci &results, std::function<bool(int)> &check) {
  int k{1};

  for (int i{1}; i < n; ++i) {

    while (k >= 2 && check(dirn(results[k - 2], results[k - 1], points[i]))) {
      results.pop_back();
      --k;
    }

    results.pb(points[i]);
    ++k;
  }

  return k;
}

void output(int kUpper, int kLower) {
  std::cout << kUpper + kLower - 2 << "\n";
  for (auto &point : upperHull) {
    std::cout << point.X << " " << point.Y << "\n";
  }
  for (int i{1}; i < kLower - 1; ++i) {
    std::cout << lowerHull[i].X << " " << lowerHull[i].Y << "\n";
  }

  std::cout << std::endl;
}

void commonSetupAndCleanInit() {}
bool comparator(CI &a, CI &b) { return (a.X == b.X) ? a.Y < b.Y : a.X < b.X; }

int dirn(CI &x, CI &y, CI &p) {
  CI a{p - x};
  CI b{p - y};
  int res{cast((conj(a) * b).Y)};
  return res;
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
