#pragma once

//https://cses.fi/problemset/task/1684

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
#define revit reverse_iterator

using vi = vector<int>;
using vvi = vector<vector<int>>;
using pivi = pair<int, vector<int>>;  //first is node's value and second is node's adjacent elements
using pii = pair<int, int>;
using vpii = vector<pii>;
using vpivi = vector<pivi>;
using mii = map<int, int>;
using vmii = vector<mii>;
using vb = vector<bool>;
using ri = revit<vi::iterator>;

#pragma endregion

class Solution {
	int testCases = 1;
	int nodes = 0;
	int toppings = 0;
	int edges = 0;
	vvi adjForward;
	vvi adjReverse;
	vb visitedP1; //Phase1Visited
	vb visitedP2; //Phase2Visited
	vb visitedP3; //resultVisited
	vi processedNodes;
	vi scc;
	vb result;

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
			INPUT(edges, toppings);

			nodes = toppings * 2;

			//1-indexed
			adjForward = vvi(nodes + 1, vi());
			adjReverse = vvi(nodes + 1, vi());
			visitedP1 = vb(nodes + 1, false);
			visitedP2 = vb(nodes + 1, false);

			processedNodes = vi();
			scc = vi(nodes + 1, 0);

			result = vb(toppings + 1, false);

			for (int i{ 1 }; i <= edges; ++i) {
				int arg2{ 0 };
				int arg4{ 0 };
				char arg1{};
				char arg3{};
				INPUT(arg1, arg2, arg3, arg4);
				int a{ 0 };
				int nota{ 0 };
				int b{ 0 };
				int notb{ 0 };

				a = arg1 == '+' ? arg2 : toppings + arg2;
				nota = arg1 == '+' ? toppings + arg2 : arg2;

				b = arg3 == '+' ? arg4 : toppings + arg4;
				notb = arg3 == '+' ? toppings + arg4 : arg4;

				adjForward.at(nota).push_back(b);
				adjForward.at(notb).push_back(a);

				adjReverse.at(b).push_back(nota);
				adjReverse.at(a).push_back(notb);
			}

			start();
		}
	}
	//Kosaraju's alg + 2-SAT using topSort

	void start() {
		//Phase 1
		for (int i = 1; i <= nodes; ++i)
			dfs1(i);
		//phase 2
		int counter{ 1 };
		for (auto elem{ processedNodes.rbegin() }; elem != processedNodes.rend(); ++elem)
		{
			int x{ *elem };
			if (!visitedP2.at(x))
			{
				dfs2(x, counter++);
			}
		}

		for (int i{ 1 }; i <= toppings; ++i) {
			if (scc.at(i) == scc.at(i + toppings))
			{
				cout << "IMPOSSIBLE" << endl;
				return;
			}
			result.at(i) = (scc.at(i) > scc.at(i + toppings));
		}

		output();
	}

	//output and hence SCC can be built more efficiently for the problem, but just for the sake of leaving SCC for understandability reference, I use this approach
	void output() {
		for (int i{ 1 }; i <= toppings; ++i) {
			cout << ((result.at(i)) ? '+' : '-') << " ";
		}
		cout << endl;
	}

	void dfs1(int current) {
		if (visitedP1.at(current)) return;
		visitedP1.at(current) = true;

		for (int elem : adjForward.at(current))
		{
			dfs1(elem);
		}

		processedNodes.push_back(current);
	}
	void dfs2(int current, int counter) {
		if (visitedP2.at(current)) return;
		visitedP2.at(current) = true;
		scc.at(current) = counter;

		for (int elem : adjReverse.at(current))
			dfs2(elem, counter);
	}
};

#ifndef LOCAL
#undef int
int main() {
	Solution();
	return 0;
}
#endif