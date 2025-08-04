//

#define LOCAL

#include "../../Helpers/common.h"

void start();
void output(bool);
void compute();
void setup();
void commonSetupAndCleanInit();
void trie_insert(string_view);
bool search(string_view);

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
  INPUT(k, A, c);
  trie = vvi(cN, vi(A, 0));
  eos = vb(cN, false);
  counter = 0;
  {
    string arg{};
    cin.ignore(intmax, '\n');
    for (int i{}; i < k; ++i) {
      getline(cin, arg);
      trie_insert(arg);
    }
  }
}

// Trie
void compute() {
  string arg{};
  while (c-- > 0) {
    getline(cin, arg);
    output(search(arg));
  }
}

void trie_insert(string_view s) {
  int sz{cast(s.size())};
  int next{};

  for (int i{}; i < sz; ++i) {
    int &elem{trie[next][cast(s[i] % A)]};
    if (!elem)
      elem = ++counter;

    next = elem;
  }
  eos[next] = true;
}

bool search(string_view s) {
  int sz{cast(s.size())};
  int next{};
  for (int i{}; i < sz; ++i) {
    int &elem{trie[next][cast(s[i] % A)]};
    if (!elem)
      return false;

    next = elem;
  }
  return eos[next];
}

void output(bool result) {
  cout << boolalpha;
  cout << result << "\n";
}

void commonSetupAndCleanInit() {}

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
