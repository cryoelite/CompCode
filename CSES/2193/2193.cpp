// https://cses.fi/problemset/task/2193

#define LOCAL

#pragma region Headers

#ifdef LOCAL
#include <iostream>
#include <array>
#include <algorithm>
#include <map>
#include <stack>
#include <complex>
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
using si = sk<int>;
using CD = std::complex<double>;
using CI = std::complex<int>; // DEPRECATED
using si = std::stack<int>;
using pqii = std::priority_queue<pii>;
using vcd = std::vector<CD>;
using vs = std::vector<std::string_view>;
#pragma endregion

#pragma region Variables
int testCases{1};
int n{};
vcd points{};
int lInside{};
int lBoundary{};
#pragma endregion

namespace Algorithm
{
    using namespace std;
    void start();
    void output();
    double crossProduct(CD &, CD &, CD &);
    bool isMid(CD&,CD&,CD&);
    bool comparatorCD(CD&,CD&);
    int gcd(int,int);

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

            points = vcd(n);

            for (int i{}; i < n; ++i)
            {

                INPUT(arg1, arg2);

                points[i] = CD{arg1, arg2};
            }

            start();
        }
    }
    // 2D vector cross product aka Complex Number Multiplication
    double crossProduct(CD &a, CD &b, CD &p)
    {
        CD temp1{p - a};
        CD temp2{p - b};
        double result{(conj(temp1) * temp2).I};

        return result;
    }


    bool comparatorCD(CD &a, CD &b)
    {
        return (a.R == b.R) ? (a.I < b.I) : (a.R < b.R);
    }
    /// @brief checks if the point b is in middle on the cartesian plane with respect to the other args.
    /// @param a
    /// @param b
    /// @param c
    /// @return
    bool isMid(CD &a, CD &b, CD &c)
    {
        std::vector<CD> temp{a, b, c};
        std::sort(temp.begin(), temp.end(), comparatorCD);

        return temp[1] == b;
    }

   int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
   }


    //Pick's Theorem + https://math.stackexchange.com/a/301895/1103748 for boundary lattice points
    //+ https://math.stackexchange.com/a/849003/1103748 for interior lattice points
    void start()
    {
        CD const translatedA{0,0};
        CD translatedB{};
        int area{};
        for(int i{}; i<n;++i ){
            CD & tempA {points[i]};
            CD & tempB {points[(i+1)%n]};

            translatedB = tempB-tempA;//translating A to B to 0 to C where C is (B.x-A.x,B.y-A.y),
                                                                 //i.e., the same length as A to B but from origin.


            lBoundary += abs(gcd(translatedB.R, translatedB.I));

            area += ((conj(tempA)* tempB)).I;

        }
        area=abs(area)/2;
        lInside= (area+1) - (lBoundary/2);
        output();
    }

    void output()
    {

        std::cout << lInside<<" "<< lBoundary  << '\n';

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
