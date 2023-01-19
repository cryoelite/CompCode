#pragma once

//https://cses.fi/problemset/task/1683

#define LOCAL
#pragma region HEADERS

#ifdef LOCAL
#include<iostream>
#include<vector>
#include<algorithm>
#include <map>
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

using vi = vector<int>;
using vvi = vector<vector<int>>;
using pivi = pair<int, vector<int>>;  //first is node's value and second is node's adjacent elements
using pii = pair<int, int>;
using vpii = vector<pii>;
using vpivi = vector<pivi>;
using mii = map<int, int>;
using vmii = vector<mii>;
using vb = vector<bool>;

#pragma endregion

class Solution {
	int testCases = 1;
	int nodes = 0;
	int edges = 0;
	vvi adjForward;
	vvi adjReverse;
	vb visitedP1; //Phase1Visited
	vb visitedP2; //Phase2Visited
	vi processedNodes;
	vvi scc;

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
			INPUT(nodes, edges);

			//1-indexed
			adjForward = vvi(nodes + 1, vi());
			adjReverse = vvi(nodes + 1, vi());
			visitedP1 = vb(nodes + 1, false);
			visitedP2 = vb(nodes + 1, false);
			processedNodes = vi();
			scc = vvi();

			for (int i{ 1 }; i <= edges; ++i) {
				int arg1{ 0 };
				int arg2{ 0 };
				INPUT(arg1, arg2);

				adjForward.at(arg1).push_back(arg2);
				adjReverse.at(arg2).push_back(arg1);
			}

			start();
		}
	}
	//Kosaraju's alg

	void start() {
		//Phase 1
		for (int i = 1; i <= nodes; ++i)
			dfs1(i);
		//phase 2
		for (int index{ cast(processedNodes.size() - 1) }; index >= 0; --index)
		{
			if (!visitedP2.at(processedNodes.at(index)))
			{
				scc.push_back(vi());
				dfs2(processedNodes.at(index), scc.size() - 1);
			}
		}

		output();
	}

	//output and hence SCC can be built more efficiently for the problem, but just for the sake of leaving SCC for understandability reference, I use this approach
	void output() {
		cout << scc.size() << endl;
		vi ans{ vi(nodes + 1,0) };
		for (size_t i{ 0 }; i < scc.size(); ++i)
			for (size_t j{ 0 }; j < scc.at(i).size(); ++j)
				ans.at(scc.at(i).at(j)) = i + 1;

		for (size_t i{ 1 }; i < ans.size(); ++i)
			cout << ans.at(i) << " ";
	}

	void dfs1(int current) {
		if (visitedP1.at(current)) return;
		visitedP1.at(current) = true;

		for (int elem : adjForward.at(current))
		{
			dfs1(elem);
		}

		processedNodes.push_back(current);
	}
	void dfs2(int current, int sccIndex) {
		if (visitedP2.at(current)) return;
		visitedP2.at(current) = true;

		for (int elem : adjReverse.at(current))
			dfs2(elem, sccIndex);

		scc.at(sccIndex).push_back(current);
	}
};

#ifndef LOCAL
#undef int
int main() {
	Solution();
	return 0;
}
#endif