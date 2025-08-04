// Problem: https://cses.fi/problemset/task/1671

#define LOCAL

#include "../../Helpers/common.h"

namespace Algorithm {
using namespace std;
void start();
void output();
void bfs(int);

void setup() {
  IOS;
#ifdef LOCAL
  FILE *inpStream;
  FILE *outStream;
  freopen_s(&inpStream, "input.txt", "r", stdin);
  freopen_s(&outStream, "output.txt", "w", stdout);
#endif
  // cin >> testCases;

  while (testCases-- > 0) {
    INPUT(nodes, edges);

    for (int i{1}, arg1{}, arg2{}, arg3{}; i <= edges; ++i) {
      INPUT(arg1, arg2, arg3);

      edgeList[i] = tiii(arg1, arg2, arg3);
    }

    start();
  }
}

// Bellman-Ford Alg, TLE tho
void start() {
  minD[1] = 0; // 1 is our start node
  bool isChanged{};
  for (int i{0}; i <= nodes - 1; ++i) {
    isChanged = false;
    for (int j{1}, a{}, b{}, w{}; j <= edges; ++j) {
      tie(a, b, w) = edgeList[j];
      if (minD[a] != INF &&
          minD[a] + w < minD[b]) // check is required to prevent INF overflowing
                                 // and wrapping around.
      {
        minD[b] = minD[a] + w;
        isChanged = true;
      }
    }
    if (!isChanged)
      break;
  }

  output();
}

void output() {
  for (int i{1}; i <= nodes; ++i)
    std::cout << minD[i] << " ";
  std::cout << std::endl;
}
} // namespace Algorithm

signed main() {
#ifdef LOCAL
  EasyBench eb{};
#endif

  Algorithm::setup();

#ifdef LOCAL
  eb.showresult();
#endif
  return 0;
}
