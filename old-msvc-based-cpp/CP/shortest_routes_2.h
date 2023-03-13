#pragma once
//https://cses.fi/problemset/task/1672

#define LOCAL
#pragma region HEADERS

#ifdef LOCAL
#include<iostream>
#include<vector>
#include<algorithm>
#include <map>
#include<stack>
#include<complex>
#include<tuple>
#else
#include<bits/stdc++.h>
#endif // LOCAL

using namespace std;
#define int long long
#define LOG2(x) static_cast<int>(floor(log2(x)))
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
#define tiii tuple<int,int,int>
#define mmi make_move_iterator

using vi = vector<int>;
using vvi = vector<vector<int>>;
using pivi = pair<int, vector<int>>;  //first is node's value and second is node's adjacent elements
using pii = pair<int, int>;
using vpii = vector<pii>; // edge list
using vtiii = vector<tiii>;
using vvtiii = vector<vector<tiii>>; //adjacency list with adjacent node id, edge weight and an extra value.
using vpivi = vector<pivi>;
using vvpii = vector<vector<pii>>; //adjacency list with edge weights, the pii has first as node id and second as the edge weight
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
	int queries = 0;


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
			INPUT(nodes, edges, queries);

			//1-indexed


			for (int i{ 1 }; i <= edges; ++i) {
	
			}

			start();
		}
	}

	//Dijkstra's Algorithm
	void start() {


	}


	void output() {

	}
};

#ifndef LOCAL
signed main() {
	Solution();
	return 0;
}
#endif
