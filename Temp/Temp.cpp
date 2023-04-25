// Problem: https://codeforces.com/gym/101498/problem/L

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
using CD = std::complex<long double>;
using CI = std::complex<int>;
using si = std::stack<int>;
using pqii = std::priority_queue<pii>;
#pragma endregion

#pragma region Variables
int testCases{1};
int nodes{};
int edges{};
vvpii adj{vvpii(N, vpii())}; // 1-indexed
vtiii el{vtiii(N)};

vi reweights{vi(N)};
vb visited{vb(N, false)};
pqii nextElems{};

vi minD{vi(N)};
int result{INF};
int S{};
#pragma endregion

namespace Algorithm
{
    using namespace std;
    void start();
    void output();
    void bfs(int, bool);
    bool bfa(int);
    void init();

    void setup()
    {
        IOS;
#ifdef LOCAL
        FILE *inpStream;
        FILE *outStream;
        freopen_s(&inpStream, "input.txt", "r", stdin);
        freopen_s(&outStream, "output.txt", "w", stdout);
#endif
        cin >> testCases;

        while (testCases-- > 0)
        {
            INPUT(nodes, edges);

            init();

            for (int i{1}, j{nodes + 1}, arg1{}, arg2{}, arg3{}; i <= edges; ++i)
            {
                INPUT(arg1, arg2, arg3);

                adj[arg1].pb({arg2, arg3});

                el[j++] = {arg1, arg2, arg3};
            }

            edges = edges + nodes; // m+n edges
            // nodes += 1;
            start();
        }
    }

    void start()
    {
        bool isCycle{bfa(0)};
        if (isCycle)
        {
            std::cout << "-inf" << '\n';
            return;
        }

        for (int i{1}; i <= nodes; ++i)
        {
            bfs(i, i == 1);
        }
        output();
    }

    // Bellman-Ford Alg, detect cycles too
    bool bfa(int start)
    {
        reweights[start] = 0;
        bool isChanged{false};
        for (int i{0}; i <= nodes + 1; ++i, isChanged = false)
        {
            for (int j{1}; j <= edges; ++j)
            {
                int a{}, b{}, w{};
                tie(a, b, w) = el[j];

                if (reweights[a] != INF && reweights[a] + w < reweights[b])
                {
                    reweights[b] = reweights[a] + w;
                    isChanged = true;
                }
            }
            if (!isChanged)
                break;
            else if (isChanged && i == (nodes + 1))
                return true; // cycle
        }
        return false;
    }
    // Dijkstra's Alg
    void bfs(int start, bool shouldReweight)
    {
        std::fill(minD.begin(), minD.end(), INF);
        std::fill(visited.begin(), visited.end(), false);
        minD[start] = 0;
        nextElems.push({minD[start], start});

        while (!nextElems.empty())
        {
            int elem{nextElems.top().second};
            nextElems.pop();

            if (visited[elem])
                continue;
            visited[elem] = true;
            for (pii &node : adj[elem])
            {
                if (shouldReweight)
                    node.second += reweights[elem] - reweights[node.first]; // reweight the edge.

                if (minD[elem] + node.second < minD[node.first])
                {
                    minD[node.first] = minD[elem] + node.second;
                    result = min(result, minD[node.first] - (reweights[start] - reweights[node.first]));
                    nextElems.push({-minD[node.first], node.first});
                }
            }
        }
    }

    void output()
    {
        std::cout << result;
        std::cout << std::endl;
    }

    void init()
    {
        for (int i{1}; i <= nodes; ++i)
        {
            adj[i] = vpii();
            reweights[i] = INF;
            el[i] = {S, i, 0};
        }

        result = INF;
    }
}

signed main()
{
#ifdef LOCAL
    EasyBench eb{};
#endif

    //Algorithm::setup();
    CI a{3,4};
    CI b{2,5};
    CI c{a*b};
    std::cout<<c.R<<"\n";

#ifdef LOCAL
    eb.showresult();
#endif
    return 0;
}
