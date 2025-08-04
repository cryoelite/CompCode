// https://leetcode.com/problems/valid-anagram

#define LOCAL

#include "../Helpers/common.h"

void start();
void output();

void setup() {
  IOS;
#ifdef LOCAL
  FILE *inpStream;
  FILE *outStream;
  freopen_s(&inpStream, "input.txt", "r", stdin);
  freopen_s(&outStream, "output.txt", "w", stdout);
  first = new string();
  second = new string();
  getline(cin, *first);
  getline(cin, *second);
  cin.ignore(5);
#endif
  freq = vi(26, 0);
  start();
  output();
}

void start() {
  if (first->size() != second->size()) {
    result = false;
    return;
  }
  for (int i{}; i < cast(first->size()); ++i) {
    freq[cast((*first)[i]) % 26]++;
    freq[cast((*second)[i]) % 26]--;
  }
  result = true;
  for (int i{}; i < 26; ++i) {
    if (freq[i] != 0) {
      result = false;
      return;
    }
  }
}

void output() {

  std::cout << result << '\n';

  std::cout << std::endl;
}

} // namespace Algorithm

#undef int
#undef double

#define START                                                                  \
  Algorithm::first = &s;                                                       \
  Algorithm::second = &t;                                                      \
  Algorithm::setup();                                                          \
  return Algorithm::result;

namespace {
using namespace std;
class Solution {
public:
  // call inserted method here
  void entrypoint() { isAnagram("", ""); }

  // Insert the method signature here
  bool isAnagram(string s, string t) { START; }
};
} // namespace

#ifdef LOCAL
signed main() {

  EasyBench eb{};

  Solution().entrypoint();

  eb.showresult();

  return 0;
}
#endif
