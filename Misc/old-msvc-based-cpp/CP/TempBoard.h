#pragma once

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

const int mod10{ 1000000007 };

#pragma endregion

class Solution {
	int testCases = 1;
	int edges = 0;
	int nodes = 0;
	vvi adjM; //matrix, keeps count of edges from node a to b
	vvi radj; //reverse-adjacency list
	vi bitNodes; //bit representation of nodes
	vvi states; //each node and power set of set of nodes for it
	vvi nodeSet; //all nodes in a given set

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

			//0-indexed
			adjM = vvi(nodes, vi(nodes, 0));
			radj = vvi(nodes, vi());
			bitNodes = vi(nodes + 1);               //nodes+1 because p[0] will be 1 so it is 1-indexed
			states = vvi(nodes, vi(1ll << nodes));
			nodeSet = vvi(1ll << nodes, vi());

			for (int i{ 1 }; i <= edges; ++i) {
				int arg1{};
				int arg2{};
				INPUT(arg1, arg2);
				--arg1;
				--arg2;

				adjM[arg1][arg2]++;
			}

			start();
		}
	}

	void start() {
		for (int i{ 0 }; i <= nodes; ++i)
			bitNodes[i] = (1ll << i);

		states[0][1] = 1;
		//1 path from 0 to 1

		for (int i{ 0 }; i < nodes; ++i)
		{
			for (int j{ 0 }; j < nodes; ++j)
			{
				if (i != j && adjM[j][i] > 0)						//if there is a path from j to i, then radj[i] will have j inserted, as many times as the no. of paths from j to i
					for (int k{ 0 }; k < adjM[j][i]; ++k)
						radj[i].pb(j);
			}
		}

		for (int i{ 1 }; i < bitNodes[nodes]; ++i)    //bitNodes[nodes] because 1ll<<nodes would be a needless calculation
		{
			for (int j{ 1 }; j < nodes; ++j)
			{
				if (i & bitNodes[j])				//if node j is in the set i, i is a set because it is a bit representation of all sets of nodes.
					nodeSet[i].pb(j);				//nodeSet[i] is the list of all nodes in the power set i.
			}
		}

		for (int i{ 1 }; i < bitNodes[nodes]; ++i)
		{
			for (int j : nodeSet[i]) {
				int nodeEx{ i ^ (bitNodes[j]) };   //nodeEx is a bit representation/set of all nodes that i represents except the node j
				for (int k : radj[j])
				{
					states[j][i] += states[k][nodeEx];
				}
				states[j][i] %= mod10;
			}
		}

		output();
	}

	void output() {
		cout << states[nodes - 1][bitNodes[nodes] - 1] << endl;
	}
};

#ifndef LOCAL
signed main() {
	Solution();
	return 0;
}
#endif