#pragma once
//https://cses.fi/problemset/task/2079

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
	int queries = 1;
	int n;
	int x;
	int y;
	vi jobs;
	int ops = 0;

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

		//		INPUT(testCases);

		for (int i{ 1 }; i <= testCases; ++i)
		{
			INPUT(n);
			ops = 0;

			ARR_INPUT(jobs, n);

			solve();

			cout << "Case #" << i << ": " << ops << endl;
		}
	}

	void solve() {
		sort(jobs.begin(), jobs.end());
		int carryOver{ 0 };
		for (int i{ cast(jobs.size()) }; i >= 0; --i) {
			double xElem{ jobs.at(i) / x };
			int castedX{ cast(floor(xElem)) };
			carryOver += xElem - castedX;
			ops += castedX;
			int yMult{ castedX * y };
			for (int j{ 0 }; j < cast(jobs.size()) && yMult>0; ++j) {
				double yElem{ jobs.at(j) / yMult };
				yMult -= jobs.at(j);
				int castedY{ cast(floor(yElem)) };

				carryOver += yElem - castedY;
			}
		}
	}
};
