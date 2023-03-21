// Problem: https://cses.fi/problemset/task/1671

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
#include "../Helpers/Easybench/Easybench.h"
#else
#include <bits/stdc++.h>
#endif // LOCAL
#pragma endregion

#pragma region Defines
#define int long long
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
using CI = std::complex<int>;
using si = std::stack<int>;
using pqii = std::priority_queue<pii>;
#pragma endregion

#pragma region Variables
int testCases{1};
int nodes{};
int edges{};
vtiii edgeList{vtiii(N)}; // first is node a, second is node b and third is the edge weight
vi minD{vi(N, INF)};
vb visited{vb(N, false)};
pqii nextElems{};

#pragma endregion

namespace Algorithm
{
    using namespace std;
    void start();
    void output();
    void bfs(int);

    void setup()
    {
        IOS;
#ifdef LOCAL
        FILE *inpStream;
        FILE *outStream;
        freopen_s(&inpStream, "input.txt", "r", stdin);
        freopen_s(&outStream, "output.txt", "w", stdout);
#endif
        // cin >> testCases;

        while (testCases-- > 0)
        {
            INPUT(nodes, edges);

            for (int i{1}, arg1{}, arg2{}, arg3{}; i <= edges; ++i)
            {
                INPUT(arg1, arg2, arg3);

                edgeList[i] = tiii(arg1, arg2, arg3);
            }

            start();
        }
    }

    // Bellman-Ford Alg
    void start()
    {
        minD[1] = 0; // 1 is our start node
        bool isChanged{};
        for (int i{0}; i <= nodes - 1; ++i)
        {
            isChanged = false;
            for (int j{1}, a{}, b{}, w{}; j <= edges; ++j)
            {
                tie(a, b, w) = edgeList[j];
                if (minD[a] != INF && minD[a] + w < minD[b]) //check is required to prevent INF overflowing and wrapping around.
                {
                    minD[b] = minD[a] + w;
                    isChanged = true;
                }
            }
            if (!isChanged)
                break;
        }

        output();
    }

    void output()
    {
        for (int i{1}; i <= nodes; ++i)
            std::cout << minD[i] << " ";
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
