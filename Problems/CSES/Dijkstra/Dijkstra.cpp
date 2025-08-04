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

      adj[arg1].pb(pii(arg2, arg3));
    }

    start();
  }
}

void start() {

  bfs(1);
  output();
}

// Dijkstra's Alg
void bfs(int start) {
  minD[start] = 0;
  nextElems.push({minD[start], start});
  while (!nextElems.empty()) {
    int elem{nextElems.top().second}; // the first elem is just for defining the
                                      // node's position in the PQ
    nextElems.pop();
    if (visited[elem])
      continue;
    visited[elem] = true;
    for (pii &node : adj[elem]) {
      if (minD[elem] + node.second < minD[node.first]) {
        minD[node.first] = minD[elem] + node.second;
        nextElems.push({-minD[node.first], node.first});
      }
    }
  }
}

void output() {
  for (int i{1}; i <= nodes; ++i)
    std::cout << minD[i] << " ";
  std::cout << std::endl;
}
} // namespace Algorithm

signed main() {
  Algorithm::setup();
  return 0;
}
