#pragma once
//https://cses.fi/problemset/task/1139

using namespace std;
#define LOG(x) static_cast<int>(floor(log2(x)))
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define LOCAL

#ifdef LOCAL
#include<iostream>
#include<vector>
#include<algorithm>
#include <map>
#else
#include<bits/stdc++.h>
#endif // LOCAL

#define int long long
template<typename... T>
void INPUT(T&... args) { ((cin >> args), ...); }
template<typename... T>
void OUTPUT(T&... args) { ((cout << args << " "), ...); cout << "\n"; }
#define ARR_INPUT(arr,x) for(int i{0}; i<x; ++i) {int y;cin>> y; arr.push_back(y);}
#define cast(i) static_cast<int>(i)

using vec = vector<vector<int>>;
using vec2 = vector<int>;
using pr = pair<int, vector<int>>;  //first is node's value and second is node's adjacent elements
using vec3 = vector<pr>;
using map1 = map<int, int>;
using vecMap = vector<map1>;
using bVec = vector<bool>;

class Solution {
	//vec3 adj{ vec3(200005, pr()) };

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

		int testCases{ 0 };
		//cin >> testCases;
		testCases = 1;
		while (testCases-- > 0)
		{
			int nodes{ 0 };
			INPUT(nodes);

			//1-indexed
			vec adj{ vec(nodes + 1, vec2()) };
			vecMap nodeMaps{ vecMap(nodes + 1, map1()) };

			for (auto i{ 1 }; i <= nodes; ++i)
			{
				auto firstArg{ 0 };
				INPUT(firstArg);

				nodeMaps.at(i)[firstArg] = 1;
			}
			for (int i{ nodes - 1 }; i > 0; --i)
			{
				int firstArg{ 0 };
				int secondArg{ 0 };
				INPUT(firstArg, secondArg);

				adj.at(firstArg).push_back(secondArg);
				adj.at(secondArg).push_back(firstArg);
			}

			int start{ 1 };
			int prev{ 0 };
			vec2 answers{ vec2(nodes + 1,0) };

			dfs(start, prev, adj, nodeMaps, answers);

			for (int i{ 1 }; i <= nodes; ++i) {
				cout << answers.at(i) << " ";
			}
			cout << endl;
		}
	}

	void dfs(int& start, int& prev, vec& adj, vecMap& nodeMaps, vec2& answers) {
		for (auto& elem : adj.at(start)) {
			if (elem == prev) continue;

			dfs(elem, start, adj, nodeMaps, answers);

			if (nodeMaps.at(start).size() < nodeMaps.at(elem).size()) {
				swap(nodeMaps.at(start), nodeMaps.at(elem));
			}
			mergeMaps(nodeMaps.at(start), nodeMaps.at(elem));
		}

		answers.at(start) = nodeMaps.at(start).size();
	}
	void mergeMaps(map1& a, map1& b) {
		for (auto& elem : b)
		{
			//if a doesn't have the key, it is automatically inserted with the default value, which is 0 for int.
			a[elem.first] = a[elem.first] + elem.second;
		}
	}
};
