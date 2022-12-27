#pragma once
//https://cses.fi/problemset/task/1688

using namespace std;
#define LOG(x) static_cast<int>(floor(log2(x)))
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define LOCAL

#ifdef LOCAL
#include<iostream>
#include<vector>
#include<algorithm>
#else
#include<bits/stdc++.h>
#endif // LOCAL

template<typename... T>
void INPUT(T&... args) { ((cin >> args), ...); }
template<typename... T>
void OUTPUT(T&... args) { ((cout << args << " "), ...); cout << "\n"; }
#define ARR_INPUT(arr,x) for(auto i{0}; i<x; ++i) {int y;cin>> y; arr.push_back(y);}
#define cast(i) static_cast<int>(i)

using vec = vector<vector<int>>;
using vec2 = vector<int>;

class Solution {
public:
	Solution() {
		start();
	}
private:
	void start() {
		IOS;

#ifdef LOCAL
		FILE* inpStream;
		FILE* outStream;
		freopen_s(&inpStream, "../input.txt", "r", stdin);
		freopen_s(&outStream, "../output.txt", "w", stdout);

#endif
		/*Sol2().solve();
		return;*/
		auto testCases{ 0 };
		//cin >> testCases;
		testCases = 1;
		while (testCases-- > 0)
		{
			int nodes{ 0 };
			int queries{ 0 };
			INPUT(nodes, queries);

			//1-indexed
			auto ancestors{ vec(LOG(nodes) + 1, vec2(nodes + 1)) };
			auto adj{ vec(nodes + 1, vec2()) };

			for (auto i{ 2 }; i <= nodes; ++i)
			{
				auto firstArg{ 0 };
				INPUT(firstArg);

				ancestors.at(0).at(i) = firstArg;

				adj.at(i).push_back(firstArg);
				adj.at(firstArg).push_back(i);
			}

			initializeAncestors(ancestors, nodes);
			auto depth{ vec2(nodes + 1,0) };
			int start{ 1 };
			int prev{ 0 };
			dfs(start, prev, adj, depth);

			while (queries-- > 0)
			{
				auto firstArg{ 0 };
				auto secondArg{ 0 };
				INPUT(firstArg, secondArg);

				cout << lca(firstArg, secondArg, depth, ancestors) << endl;
			}
		}
	}

	void initializeAncestors(vec& ancestors, int& nodes) {
		for (auto i{ 1 }; i < ancestors.size(); ++i)
		{
			for (auto j{ 1 }; j <= nodes; ++j) {
				ancestors.at(i).at(j) = ancestors.at(i - 1).at(ancestors.at(i - 1).at(j));
			}
		}
	}

	void dfs(int& start, int& prev, vec& adj, vec2& depth) {
		for (auto& elem : adj.at(start)) {
			if (elem == prev) continue;
			depth.at(elem) = depth.at(start) + 1;
			dfs(elem, start, adj, depth);
		}
	}

	int raise(int a, int depth, vec& ancestors) {
		auto temp{ 0 };
		while (depth > 0) {
			if (depth & 1) a = ancestors.at(temp).at(a);
			temp++;
			depth >>= 1;
		}
		return a;
	}

	int lca(int a, int b, vec2& depth, vec& ancestors) {
		if (depth.at(a) > depth.at(b)) swap(a, b);
		b = raise(b, depth.at(b) - depth.at(a), ancestors);

		if (a == b) return a;

		for (int i{ cast(ancestors.size()) - 1 }; i >= 0; --i) {
			if (ancestors.at(i).at(a) != ancestors.at(i).at(b)) {
				a = ancestors.at(i).at(a);
				b = ancestors.at(i).at(b);
			}
		}

		return ancestors.at(0).at(a);
	}
};
