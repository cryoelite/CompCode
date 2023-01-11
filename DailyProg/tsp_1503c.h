#pragma once
//https://codeforces.com/problemset/problem/1503/C

#define LOCAL
#pragma region HEADERS

#ifdef LOCAL
#include<iostream>
#include<vector>
#include<algorithm>
#include <map>
#include<stack>
#include<complex>
#else
#include<bits/stdc++.h>
#endif // LOCAL

using namespace std;
#define int long long
#define LOG(x) static_cast<int>(floor(log2(x)))
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
template<typename... T>
void INPUT(T&... args) { ((cin >> args), ...); }
template<typename... T>
void OUTPUT(T&... args) { ((cout << args << " "), ...); cout << "\n"; }
#define ARR_INPUT(arr,x) for(int i{0}; i<x; ++i) {int y;cin>> y; arr.push_back(y);}
#define cast(i) static_cast<int>(i)
#define intmax numeric_limits<int>::max()
#define intmin numeric_limits<int>::min()
#define revit reverse_iterator
#define pb push_back
#define sk stack
#define R real()
#define I imag()

using vi = vector<int>;
using vvi = vector<vector<int>>;
using pivi = pair<int, vector<int>>;  //first is node's value and second is node's adjacent elements
using pii = pair<int, int>;
using vpii = vector<pii>; // edge list
using vpivi = vector<pivi>;
using vvpii = vector<vector<pii>>;
using mii = map<int, int>;
using vmii = vector<mii>;
using vb = vector<bool>;
using vvb = vector<vb>;
using ri = revit<vi::iterator>;
using si = sk<int>;
using CD = complex<double>;
using CI = complex<int>;

#pragma endregion

class Solution {
	int testCases = 1;
	int edges = 0;
	int nodes = 0;
	vi route;
	vvi adjM; //matrix
	int finishedState;
	vvi edgeMinCost;
	vvi prev;
	int startNode;
	vpii aici;

public:
	Solution() {
		setup();
	}
private:
	void setup() {
		IOS;
#ifdef LOCAL
		FILE* inpStream;
		FILE* outStream;
		freopen_s(&inpStream, "../input.txt", "r", stdin);
		freopen_s(&outStream, "../output.txt", "w", stdout);

#endif

		//cin >> testCases;

		while (testCases-- > 0)
		{
			INPUT(nodes);

			//1-indexed
			adjM = vvi(nodes + 1, vi(nodes + 1, 0));
			route = vi();
			finishedState = (1ll << nodes) - 1;
			edgeMinCost = vvi(nodes + 1, vi(1ll << nodes, intmax));
			prev = vvi(nodes + 1, vi(1ll << nodes, 0));
			startNode = 1;

			aici = vpii(nodes + 1, pii(0, 0));

			for (int i{ 1 }; i <= nodes; ++i) {
				int arg1{};
				int arg2{};
				INPUT(arg1, arg2);

				aici[i] = pii(arg1, arg2);
			}

			start();
		}
	}

	void start() {
		int state{ startNode };

		int minCost = tsp(startNode, state);

		int index{ startNode };
		while (true) {
			route.pb(index);
			int nextIndex{ prev[index][state] };
			if (nextIndex == 0)
				break;
			state = state | (1ll << (nextIndex - 1));
			index = nextIndex;
		}

		route.pb(startNode);

		output(minCost);
	}

	//Bellman-Held-Karp Algorithm for TSP
	int tsp(int node, int state)
	{
		//tour is completed, now to return cost to return to start node
		if (state == finishedState) return adjM[node][startNode];

		//mincost already calculated for this path
		if (edgeMinCost[node][state] != intmax)  return edgeMinCost[node][state];

		int minCost{ intmax };
		int index{ 0 };
		for (int i{ 0 }; i < nodes; ++i)
		{
			if (adjM[node][i + 1] == 0)
				adjM[node][i + 1] = max(aici[node].second, aici[i + 1].first - aici[node].first);

			if ((state & 1ll << i) != 0) continue;
			//this node has been processed already for a given state list, for ex. if state is 1011 meaning node 1 and 2 are processed
			//then when we say go to node 3 that will still loop from 1 to 2 to 3, and 1 which is 0001 & 1011 will return 0001 meaning
			//it has been already processed. Same for any n node, but say i is 2 and state is 1001 then 1001 & 0010 will return 0000
			//meaning it hasn't been processed. This way we avoid reprocessing nodes.
			//The 1<<i returns the bit representation of any int i. This is also the reason why we loop from 0 to n
			//i.e., 1<<i for i=1 means we get 0010 which is actually 2, so instead of 1<<i-1 to get the correct val we do 0 to n.

			int nextState{ state | (1ll << i) };		 //mark current node as visited.
			int nextMinCost{ adjM[node][i + 1] + tsp(i + 1, nextState) };
			if (nextMinCost < minCost)
			{
				minCost = nextMinCost;
				index = i + 1;
			}
		}

		prev[node][state] = index;
		edgeMinCost[node][state] = minCost;
		return minCost;
	}

	void output(int minCost) {
		//for (int elem : route)
		//	cout << elem << " ";
		//cout << endl;
		cout << minCost << endl;
	}
};

#ifndef LOCAL
#undef int
int main() {
	Solution();
	return 0;
}
#endif