// https://cses.fi/problemset/task/1731

// #define LOCAL

#include "../../Helpers/common.h"

void start();
void setup();
void compute();
void trie_insert(string_view);
void output();
int search(int);

void start() {
  int testCases{1};

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
  // INPUT(testCases);
  // cin.ignore(intmax, '\n');
#endif

  while (testCases-- > 0) {
    setup();
    compute();
    output();
  }
}
void setup() {
  getline(cin, s);
  INPUT(n);
  A = 26;
  sz = cast(s.size());
  trie = vvi(cBN, vi(A, 0));
  eos = vb(cBN, false);
  counter = 0;
  dpTable = vi(sz + 1, 0);
  string arg{};
  cin.ignore(cN, '\n');
  while (n-- > 0) {
    getline(cin, arg);
    trie_insert(arg);
  }
}

void compute() {
  dpTable[sz] = 1;
  for (int i{sz - 1}; i >= 0; --i) {
    dpTable[i] = search(i);
  }
}
void trie_insert(string_view s) {
  int size_s{cast(s.size())};
  int next{};
  for (int i{}; i < size_s; ++i) {
    int &elem{trie[next][cast(s[i] % A)]};
    if (!elem)
      elem = ++counter;

    next = elem;
  }
  eos[next] = true;
}
int search(int x) {
  int next{};
  int ans{};
  for (int i{x}; i < sz; ++i) {
    int &elem{trie[next][cast(s[i] % A)]};
    if (!elem)
      return ans;
    next = elem;
    if (eos[next]) {
      ans += dpTable[i + 1];
      ans %= mod10_e9_7;
    }
  }
  return ans;
}

void output() { cout << dpTable[0] << "\n"; }

} // namespace Algorithm
  //
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
