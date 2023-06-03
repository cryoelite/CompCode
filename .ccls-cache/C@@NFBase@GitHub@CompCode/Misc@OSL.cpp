// https://cses.fi/problemset/task/2194

#define LOCAL

#pragma region Headers

#ifdef LOCAL
#include <iostream>
#include <array>
#include <algorithm>
#include <map>
#include <stack>
#include <complex>
#include <set>
#include <tuple>
#include <vector>
#include <queue>
#include <string_view>
#include "../Helpers/Easybench/Easybench.h"
#else
#include <bits/stdc++.h>
#endif // LOCAL
#pragma endregion

#pragma region Defines
#define int long long
#define double long double
#define LOG(x) static_cast<int>(std::floor(std::log2(x)))
#define IOS                                \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(0);                       \
    std::cout.tie(0);
template <typename... T>
void INPUT(T &...args)
{
    ((std::cin >> args), ...);
}
template <typename... T>
void OUTPUT(T &...args)
{
    ((std::cout << args << " "), ...);
    std::cout << "\n";
}
#define ARR_INPUT(arr, x)      \
    for (int i{0}; i < x; ++i) \
    {                          \
        int y;                 \
        std::cin >> y;         \
        arr.push_back(y);      \
    }
#define cast(i) static_cast<int>(i)
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
#define revit std::reverse_iterator
#define pb push_back
#define sk std::stack
#define R real()
#define I imag()
#define tiii std::tuple<int, int, int>
#define mmi std::make_move_iterator
#pragma endregion

#pragma region Constants
constexpr int mod10{10000007};
constexpr int N{200005};
constexpr int INF{std::numeric_limits<int>::max()};
#pragma endregion

#pragma region Usings
using vi = std::vector<int>;
using si= std::set<int>;
using sd= std::set<double>;
using vvi = std::vector<vi>;
using pivi = std::pair<int, vi>; // first is node's value and second is node's adjacent elements
using pii = std::pair<int, int>;
using vpii = std::vector<pii>; // edge list
using vtiii = std::vector<tiii>;
using vvtiii = std::vector<vtiii>; // adjacency list with adjacent node id, edge weight and an extra value.
using vpivi = std::vector<pivi>;
using vvpii = std::vector<vpii>; // adjacency list with edge weights, the pii has first as node id and second as the edge weight
using mii = std::map<int, int>;
using vmii = std::vector<mii>;
using vb = std::vector<bool>; // vector<bool> is a special explicit definition of vector and behaves more like a bitset than a vector, also it is faster than array<bool> https://stackoverflow.com/a/55762317/13036358
using vvb = std::vector<vb>;
using ri = revit<vi::iterator>;
using ski = sk<int>;
using CD = std::complex<double>;
using CI = std::complex<int>; // DEPRECATED
using pqd= std::priority_queue<double>;
using pqi = std::priority_queue<int>;
using pqpii = std::priority_queue<pii>;
using vcd = std::vector<CD>;
using vci = std::vector<CI>;
using pcd= std::pair<CD,CD>;
using pci = std::pair<CI, CI>;
using vpcd= std::vector<pcd>;
using vpci = std::vector<pci>;
using vs = std::vector<std::string_view>;
#pragma endregion

#pragma region Variables
enum SegType {
 H, //Horizontal
 V  //Vertical
};
int testCases{1};
int n{};
std::vector<std::pair<CD,SegType>> totalSegs; //
int result{};
sd activeSegs{};
#pragma endregion



namespace Algorithm
{
    using namespace std;
    void start();
    void output();
    bool comparatorX(pair<CD,SegType>&,pair<CD,SegType>&);

    void setup()
    {
        IOS;
#ifdef LOCAL
        FILE *inpStream;
        FILE *outStream;
        freopen_s(&inpStream, "input.txt", "r", stdin);
        freopen_s(&outStream, "output.txt", "w", stdout);
#endif
        // INPUT(testCases);

        while (testCases-- > 0)
        {
            INPUT(n);

            double arg1{};
            double arg2{};
            double arg3{};
            double arg4{};


            for (int i{}; i < n; ++i)
            {
                SegType s{};
                INPUT(arg1, arg2, arg3, arg4);

                if(arg1==arg3) { // Vertical Segment
                    s=SegType{V};
                }
                else{
                    s= SegType{H};
                }


                totalSegs.pb(pair(CD({arg1,arg2}), s));
                totalSegs.pb(pair(CD({arg3,arg4}), s));
            }
            sort(totalSegs.begin(), totalSegs.end(), comparatorX);
            n*=2;
            start();
        }
    }

    bool comparatorX(pair<CD,SegType>& a, pair<CD,SegType>& b ) {
        return a.first.R < b.first.R;
    }

   void start()
    {
        for(int i{0}; i< n; ++i) {
            SegType& sType{totalSegs[i].second};
            CD& point{totalSegs[i].first};

            if(sType == SegType{H}) {
                if(activeSegs.erase(point.I) == 0) { //That is, Element not found in the set, otherwise found and removed
                    activeSegs.insert(point.I);
                }
            } else {
                CD& secondPoint{totalSegs[++i].first};
                if(secondPoint.R != point.R) throw "Assumption Vertical points sort and stay together failed!";

                result+= static_cast<int>(activeSegs.size());

            }
            
        }

        
        output();
    }

    void output()
    {

        std::cout << result  << '\n';

        std::cout << std::endl;
    }



}

signed main()
{
#ifdef LOCAL
    EasyBench eb{};
#endif

    Algorithm::setup();

#ifdef LOCAL
    eb.showresult();
#endif
    return 0;
}
