// https://www.hackerrank.com/challenges/time-conversion/problem?isFullScreen=true

// #define LOCAL

#include "../../../Helpers/common.h"

namespace Algorithm {
using namespace std;

// Static Namespace Variables
int testCases{1};
string inp_time{};
string result{};

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
  getline(cin, inp_time);
  cin.ignore(numeric_limits<streamsize>::max());
}

void compute() {
  int hour{stoi(inp_time.substr(0, 2))};
  if (inp_time[8] == 'A') {
    hour %= 12;
    result = (hour / 10 < 1 ? "0" : "") + to_string(hour);
  } else {

    hour += 12;
    hour %= 24;
    result = hour == 0 ? "12" : to_string(hour);
  }
  result += inp_time.substr(2, 6);
}

void output() {
  cout << result;
  cout << '\n';
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
