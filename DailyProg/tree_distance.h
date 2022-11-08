#pragma once

//https://cses.fi/problemset/task/1132

#include<iostream>
#include<vector>


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
			auto adj{ vec(nodes + 1, vec2()) };

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
			auto childNodes{ vec2(nodes + 1,0) };
			auto maxLength1{ vec2(nodes + 1,0) };
			auto maxLength2{ vec2(nodes + 1,0) };
			dfs(start, prev, adj, childNodes, maxLength1);

			dfs2(start, prev, adj, childNodes, maxLength1, maxLength2);

			for (auto i{ 1 }; i <= nodes; ++i) {
				cout << max(maxLength1.at(i), maxLength2.at(i)) << " ";
			}
		}
	}


	void dfs(int& start, int& prev, vec& adj, vec2& child, vec2& maxLength) {
		maxLength.at(start) = 0;
		child.at(start) = 0;
		for (auto& elem : adj.at(start)) {
			if (elem == prev) continue;
			dfs(elem, start, adj, child, maxLength);
			if (maxLength.at(start) < (maxLength.at(elem) + 1)) {
				maxLength.at(start) = maxLength.at(elem) + 1;
				child.at(start) = elem;
			}
		}
	}

	void dfs2(int& start, int& prev, vec& adj, vec2& child, vec2& maxLength1, vec2& maxLength2) {
		calculate_distance(start, adj, child, maxLength1, maxLength2);

		for (auto& elem : adj.at(start)) {
			if (elem == prev) continue;
			dfs2(elem, start, adj, child, maxLength1, maxLength2);
		}

	}

	void calculate_distance(int& start, vec& adj, vec2& child, vec2& maxLength1, vec2& maxLength2) {

		maxLength2.at(start) = 0;

		for (auto& elem : adj.at(start)) {
			if (child.at(elem) == start) {

				if (maxLength2.at(elem) + 1 > maxLength2.at(start)) maxLength2.at(start) = maxLength2.at(elem) + 1;

				continue;	
			}
			else if (child.at(start) == elem) continue;


			if (maxLength1.at(elem) + 1 > maxLength2.at(start)) maxLength2.at(start) = maxLength1.at(elem) + 1;
			if (maxLength2.at(elem) + 1 > maxLength2.at(start)) maxLength2.at(start) = maxLength2.at(elem) + 1;
		}

	}


};
