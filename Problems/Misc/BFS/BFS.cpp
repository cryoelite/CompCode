// Problem: https://codeforces.com/problemset/problem/115/A

#define LOCAL

#include "../../Helpers/common.h"

namespace Algorithm {
using namespace std;
void start();
void output();
int bfs(int);

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
    INPUT(nodes);

    for (int i{1}; i <= nodes; ++i) {
      int arg1{};
      INPUT(arg1);
      if (arg1 == -1)
        nm[cnm++] = i;
      else
        adj[arg1].pb(i);
    }

    start();
  }
}

void start() {

  for (int i{}; i < cnm; ++i)
    result = max(bfs(nm[i]), result);

  output();
}

// iterative bfs
int bfs(int start) {
  int maxDepth{};
  nextElems.push(start);
  visited[start] = true;
  depth[start] = 0;
  while (!nextElems.empty()) {
    int elem{nextElems.top()};
    nextElems.pop();

    for (int node : adj[elem]) {
      if (visited[node])
        continue;
      nextElems.push(node);
      visited[node] = true;
      depth[node] = depth[elem] + 1;
    }

    maxDepth = max(depth[elem], maxDepth);
  }
  return maxDepth;
}

void output() {
  cout << result + 1 << endl; // result+1 because depth starts from 0
}
} // namespace Algorithm

signed main() {
  Algorithm::setup();
  return 0;
}
