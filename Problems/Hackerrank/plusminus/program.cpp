// https://www.hackerrank.com/challenges/plus-minus/problem

#include "../../Helpers/common.h"

namespace Algorithm {
using namespace std;

// Static Namespace Variables
int testCases{1};
int n{};
vi arr{};
double posV{};
double negV{};
double zeroV{};

// Function Signatures
void start();
void setup();
void compute();
void output();

// Function Bodies
void start() {
  IOS;

  // I/O Stream pointed at local text files
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
#endif

  while (testCases-- > 0) {
    setup();
    compute();
    output();
  }
}

void setup() {
  cin >> n;

  string inp{};
  cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
  getline(cin, inp);

  stringstream ss{inp};
  string temp{};

  arr = vi();
  while (getline(ss, temp, ' ')) {
    arr.pb(stoi(temp));
  }
}

void compute() {
  int posCount{}, negCount{}, zeroCount{};
  for (int i{}; i < n; ++i) {
    if (arr[i] == 0) {
      ++zeroCount;
    } else if (arr[i] > 0) {
      ++posCount;
    } else {
      ++negCount;
    }
  }

  posV = (static_cast<double>(posCount) / n);
  negV = (static_cast<double>(negCount) / n);
  zeroV = (static_cast<double>(zeroCount) / n);
}

void output() {
  cout << setprecision(6);
  cout << fixed;
  cout << posV << '\n';
  cout << negV << '\n';
  cout << zeroV << '\n';
  cout << "\n";
}

} // namespace Algorithm

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
