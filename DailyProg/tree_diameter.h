#pragma once

//https://cses.fi/problemset/task/1131

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define LOG(x) static_cast<int>(floor(log2(x)))
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define LOCAL
template<typename... T>
void INPUT(T&... args) { ((cin >> args), ...); }
template<typename... T>
void OUTPUT(T&... args) { ((cout << args << " "), ...); cout << "\n"; }
#define ARR_INPUT(arr,x) for(auto i{0}; i<x; ++i) {int y;cin>> y; arr.push_back(y);}
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
		auto testCases{ 0 };
		//cin >> testCases;
		testCases = 1;
		while (testCases-- > 0)
		{
			int nodes{ 0 };

			INPUT(nodes);

			//1-indexed
			auto adj{ vec(nodes + 1, vector<int>()) };

			for (auto i{ nodes }; i > 0; --i)
			{
				auto firstArg{ 0 };
				auto secondArg{ 0 };
				INPUT(firstArg, secondArg);

				adj.at(firstArg).push_back(secondArg);
				adj.at(secondArg).push_back(firstArg);
			}
			int start{ 1 };
			int prev{ 0 };
			auto toLeaf{ vec2(nodes + 1) };
			auto maxLength{ vec2(nodes + 1) };
			dfs(start, prev, adj, toLeaf, maxLength);
			cout << *max_element(maxLength.begin(), maxLength.end()) << endl;
		}
	}

	void dfs(int& start, int& prev, vec& adj, vec2& toLeaf, vec2& maxLength) {
		toLeaf.at(start) = 0;
		for (auto& elem : adj.at(start)) {
			if (elem == prev) continue;

			dfs(elem, start, adj, toLeaf, maxLength);
			toLeaf.at(start) = max(toLeaf.at(elem) + 1, toLeaf.at(start));
		}
		calculateMaxLength(start, prev, adj, toLeaf, maxLength);
	}

	void calculateMaxLength(int& start, int& prev, vec& adj, vec2& toLeaf, vec2& maxLength) {
		maxLength.at(start) = 0;

		auto max1{ -1 };

		auto max2{ -1 };
		for (auto& elem : adj.at(start)) {
			if (elem == prev) continue;
			if (toLeaf.at(elem) > max1) {
				max2 = max1;
				max1 = toLeaf.at(elem);
			}
			else if (toLeaf.at(elem) > max2) {
				max2 = toLeaf.at(elem);
			}
		}

		maxLength.at(start) = max1 + max2 + 2;
	}
};
