#pragma once
//https://cses.fi/problemset/task/1694

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
	vvtiii adj;	//extra value is companion edge index in the adjacency list of a node.
	vb visited;
	int mf;
	int source;
	int sink;

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
			adj = vvtiii(nodes + 1, vtiii());
			visited = vb(nodes + 1, false);
			mf = 0;
			source = 1;
			sink = nodes; //given in problem statement

			for (int i{ 1 }; i <= edges; ++i) {
				int arg1{};
				int arg2{};
				int arg3{};
				INPUT(arg1, arg2, arg3);
				int residualEdgeIndex = adj[arg2].size();
				int normalEdgeIndex = adj[arg1].size();		//size is +1 automatically so we get the right index of the inserted element.

				adj[arg1].pb(tiii(arg2, arg3, residualEdgeIndex));
				adj[arg2].pb(tiii(arg1, 0, normalEdgeIndex));  //insert residual edge in the same graph.
			}

			start();
		}
	}

	//Ford-Fulkerson-Algorithm
	void start() {
		int temp{ 0 };
		while (true) {
			for_each(visited.begin(), visited.end(), [](auto elem) { elem = false; }); //since vector<bool> is a specialization we can't directly use bool& elem as the type is std::vector<bool>::reference. For other types, like int, we can use int& elem.
			temp = dfs(source, intmax);
			if (!temp) break;
			mf += temp;
		}

		output();
	}

	int dfs(int node, int minEdgeWeight)
	{
		if (node == sink) return minEdgeWeight;
		visited[node] = true;
		int originalMinEdgeWeight{ minEdgeWeight };


		for (tiii& elem : adj[node])
		{
			if (visited[get<0>(elem)] || get<1>(elem) == 0) continue;

			minEdgeWeight = min(minEdgeWeight, get<1>(elem));

			int tempWeight{ dfs(get<0>(elem), minEdgeWeight) };

			if (tempWeight > 0) {
				get<1>(elem) -= tempWeight;
				get<1>(adj[get<0>(elem)][get<2>(elem)]) += tempWeight;

				return tempWeight;
			}
			else
				minEdgeWeight = originalMinEdgeWeight;
		}

		return 0;
	}

	void output() {
		cout << mf << endl;
	}
};

#ifndef LOCAL
signed main() {
	Solution();
	return 0;
}
#endif