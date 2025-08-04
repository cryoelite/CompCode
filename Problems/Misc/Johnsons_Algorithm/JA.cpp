// Problem: https://codeforces.com/gym/101498/problem/L

#define LOCAL

#include "../../Helpers/common.h"

namespace Algorithm {
using namespace std;
void start();
void output();
void bfs(int, bool);
bool bfa(int);
void init();

void setup() {
  IOS;
#ifdef LOCAL
  FILE *inpStream;
  FILE *outStream;
  freopen_s(&inpStream, "input.txt", "r", stdin);
  freopen_s(&outStream, "output.txt", "w", stdout);
#endif
  cin >> testCases;

  while (testCases-- > 0) {
    INPUT(nodes, edges);

    init();

    for (int i{1}, j{nodes + 1}, arg1{}, arg2{}, arg3{}; i <= edges; ++i) {
      INPUT(arg1, arg2, arg3);

      adj[arg1].pb({arg2, arg3});

      el[j++] = {arg1, arg2, arg3};
    }

    edges = edges + nodes; // m+n edges
    // nodes += 1;
    start();
  }
}

void start() {
  bool isCycle{bfa(0)};
  if (isCycle) {
    std::cout << "-inf" << '\n';
    return;
  }

  for (int i{1}; i <= nodes; ++i) {
    bfs(i, i == 1);
  }
  output();
}

// Bellman-Ford Alg, detect cycles too
bool bfa(int start) {
  reweights[start] = 0;
  bool isChanged{false};
  for (int i{0}; i <= nodes + 1; ++i, isChanged = false) {
    for (int j{1}; j <= edges; ++j) {
      int a{}, b{}, w{};
      tie(a, b, w) = el[j];

      if (reweights[a] != INF && reweights[a] + w < reweights[b]) {
        reweights[b] = reweights[a] + w;
        isChanged = true;
      }
    }
    if (!isChanged)
      break;
    else if (isChanged && i == (nodes + 1))
      return true; // cycle
  }
  return false;
}
// Dijkstra's Alg
void bfs(int start, bool shouldReweight) {
  std::fill(minD.begin(), minD.end(), INF);
  std::fill(visited.begin(), visited.end(), false);
  minD[start] = 0;
  nextElems.push({minD[start], start});

  while (!nextElems.empty()) {
    int elem{nextElems.top().second};
    nextElems.pop();

    if (visited[elem])
      continue;
    visited[elem] = true;
    for (pii &node : adj[elem]) {
      if (shouldReweight)
        node.second +=
            reweights[elem] - reweights[node.first]; // reweight the edge.

      if (minD[elem] + node.second < minD[node.first]) {
        minD[node.first] = minD[elem] + node.second;
        result = min(result, minD[node.first] -
                                 (reweights[start] - reweights[node.first]));
        nextElems.push({-minD[node.first], node.first});
      }
    }
  }
}

void output() {
  std::cout << result;
  std::cout << std::endl;
}

void init() {
  for (int i{1}; i <= nodes; ++i) {
    adj[i] = vpii();
    reweights[i] = INF;
    el[i] = {S, i, 0};
  }

  result = INF;
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
