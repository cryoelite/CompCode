// https://leetcode.com/problems/two-sum/description/

#define LOCAL

#include "../Helpers/common.h"

void start();
void output();
void localSetup();
void commonSetupAndCleanInit(); // needs to be cleaned up and setup, cleanup
                                // here because it resets results so must be
                                // done before other logic

void nonLocalSetup();

void localSetup() {
  IOS;
#ifdef freopen_s // windows
  FILE *inpStream;
  FILE *outStream;

  freopen_s(&inpStream, "input.txt", "r", stdin);
  freopen_s(&outStream, "output.txt", "w", stdout);
#else // linux
  freopen64("input.txt", "r", stdin);
  freopen64("output.txt", "w", stdout);
#endif
  INPUT(n);
  INPUT(target);
  ARR_INPUT(nums, n);
}

void commonSetupAndCleanInit() {
  ht = umi();
  result = vi();
}

void nonLocalSetup() { n = cast(nums.size()); }

void start() {
  for (int i{}, elem{}; i < (n * 2); ++i) {
    elem = nums[i % n];

    umi::iterator it{ht.find(target - elem)};
    if (it != ht.end()) {
      result.pb(i);
      result.pb(it->second);
      return;
    } else {
      ht.insert({elem, i});
    }
  }
}

void output() {

  for (int elem : result) {
    std::cout << elem << " ";
  }

  std::cout << std::endl;
}

void cleanup() {

  result.clear();
  ht.clear();
  n = 0;
  nums.clear();
  target = 0;
}

} // namespace Algorithm

#define START                                                                  \
  Algorithm::nums = nums;                                                      \
  Algorithm::target = target;                                                  \
  Algorithm::commonSetupAndCleanInit();                                        \
  Algorithm::nonLocalSetup();                                                  \
  Algorithm::start();                                                          \
  Algorithm::output();                                                         \
  return Algorithm::result;

namespace {
using namespace std;
class Solution {
public:
  /// Local Test Method
  void entrypoint() {
    Algorithm::localSetup();
    Algorithm::commonSetupAndCleanInit();
    Algorithm::start();
    Algorithm::output();
  }

  /// LC calls this method
  vector<int> twoSum(vector<int> &nums, int target) { START; }
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
