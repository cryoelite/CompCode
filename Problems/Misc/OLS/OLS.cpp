// Orthogonal Line Segment Intersection

#define LOCAL

#include "../../Helpers/common.h"

namespace Algorithm {
using namespace std;
void start();
void output();
bool comparator(pair<CD, SegType> &, pair<CD, SegType> &);

void setup() {
  IOS;
#ifdef LOCAL
  FILE *inpStream;
  FILE *outStream;
  freopen_s(&inpStream, "input.txt", "r", stdin);
  freopen_s(&outStream, "output.txt", "w", stdout);
#endif
  // INPUT(testCases);

  while (testCases-- > 0) {
    INPUT(n);
    double arg1{};
    double arg2{};
    double arg3{};
    double arg4{};

    for (int i{}; i < n; ++i) {
      SegType s{};
      INPUT(arg1, arg2, arg3, arg4);

      if (arg1 == arg3) { // Vertical Segment
        s = SegType{V};
      } else {
        s = SegType{H};
      }

      totalSegs.pb(pair(CD({arg1, arg2}), s));
      totalSegs.pb(pair(CD({arg3, arg4}), s));
    }
    sort(totalSegs.begin(), totalSegs.end(), comparator);
    n *= 2;
    start();
  }
}

bool comparator(pair<CD, SegType> &a, pair<CD, SegType> &b) {
  return (a.first.R == b.first.R) ? a.first.I > b.first.I
                                  : a.first.R < b.first.R;
}

void start() {
  CD *firstV{nullptr};
  CD *secondV{nullptr};
  for (int i{0}; i < n; ++i) {
    SegType &sType{totalSegs[i].second};
    CD &point{totalSegs[i].first};

    if (sType == SegType{H}) {
      if (activeSegs.find(point.I) == activeSegs.end()) {
        activeSegs.insert(point.I);
      } else if (firstV != nullptr) {
        result++;
        activeSegs.erase(point.I);
      } else {
        activeSegs.erase(point.I);
      }
    } else {
      if (firstV == nullptr) {
        firstV = &point;
      } else {
        secondV = &point;

        for (int elem : activeSegs) {
          if (elem >= secondV->I &&
              elem <= firstV->I) { // The way we sort enables us the assumption
                                   // that the element that comes later in
                                   // totalSegs has greater Y axis (I)
            result++;
          }
        }
        firstV = nullptr;
        secondV = nullptr;
      }
    }
  }

  output();
}

void output() {

  std::cout << result << '\n';

  std::cout << std::endl;
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
