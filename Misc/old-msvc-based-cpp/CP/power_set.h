#pragma once
//https://leetcode.com/problems/subsets/

#define LOCAL
#pragma region HEADERS

#ifdef LOCAL
#include<iostream>
#include<vector>
#include<algorithm>
#include <map>
#include<stack>
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

#pragma endregion

class Solution {
	int testCases = 1;
	int nodes = 0;
	vi arr;
	vvb result;
	vb bitset;

public:
	Solution() {
#ifdef LOCAL
		setup();
#endif
	}

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
			nodes = 0;
			arr = vi();

			INPUT(nodes);
			ARR_INPUT(arr, nodes);

			vvi result{ subsets(arr) };

			cout << "[";
			for (vi& elem : result)
			{
				cout << "[";
				for (int& subElem : elem)
				{
					cout << subElem << ",";
				}
				cout << "],";
			}
			cout << "]" << endl;
		}
	}

	vvi subsets(vi& nums) {
		vvi ans{ vvi() };
		result = vvb();
		nodes = cast(nums.size());
		//bitset= (0 << (nodes-1));
		bitset = vb(nodes, 0);

		generateSubsets(0, nodes);

		for (vb& bitset : result)
		{
			vi temp{ vi() };
			for (size_t i{ 0 }; i < bitset.size(); ++i)
			{
				if (bitset[i])
					temp.pb(nums[i]);
			}
			ans.pb(temp);
		}

		return ans;
	}

	void generateSubsets(int i, int n) {
		if (i == n)
			result.pb(vb(bitset.begin(), bitset.end()));
		else
		{
			bitset[i] = 0;
			generateSubsets(i + 1, n);
			bitset[i] = 1;
			generateSubsets(i + 1, n);
		}
	}
};
