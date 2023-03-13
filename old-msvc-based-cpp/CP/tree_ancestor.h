#pragma once

//https://cses.fi/problemset/task/1687

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
			int queries{ 0 };
			INPUT(nodes, queries);

			//1-indexed
			auto ancestors{ vec(LOG(nodes) + 1, vec2(nodes + 1)) };

			for (auto i{ 2 }; i <= nodes; ++i)
			{
				auto firstArg{ 0 };
				INPUT(firstArg);

				ancestors.at(0).at(i) = firstArg;
			}

			initializeAncestors(ancestors, nodes);

			while (queries-- > 0)
			{
				auto firstArg{ 0 };
				auto secondArg{ 0 };
				INPUT(firstArg, secondArg);
				auto ans{ firstArg };
				auto temp{ 0 };
				while (secondArg > 0) {
					if (secondArg & 1) ans = ancestors.at(temp).at(ans);
					temp++;
					secondArg >>= 1;
				}
				if (ans == 0) ans = -1;
				cout << ans << endl;
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
};
