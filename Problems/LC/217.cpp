// https://leetcode.com/problems/contains-duplicate/

#define LOCAL

#include "../Helpers/common.h"

using namespace std;
void start();
void output();
void cleanup();

void setup() {
  IOS;
#ifdef LOCAL
  FILE *inpStream;
  FILE *outStream;
  freopen_s(&inpStream, "input.txt", "r", stdin);
  freopen_s(&outStream, "output.txt", "w", stdout);
  INPUT(n);
  ARR_INPUT(arr, n);
#endif

  start();
  output();
  cleanup();
}

void start() {
  ui un{ui(arr.begin(), arr.end())};
  result = cast(un.size()) != n;
}

void output() {

  std::cout << result << '\n';

  std::cout << std::endl;
}

void cleanup() {
  arr.clear();
  n = 0;
}

} // namespace Algorithm

#undef int;
namespace {
using namespace std;
class Solution {
public:
  // call inserted method here
  void entrypoint() {
    vector<int> v{};
    containsDuplicate(v);
  }

  // Insert the method signature here
  bool containsDuplicate(vector<int> &nums) {
    Algorithm::arr.insert(Algorithm::arr.begin(), nums.begin(), nums.end());
    Algorithm::n = nums.size();
    Algorithm::setup();

    return Algorithm::result;
  }
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
