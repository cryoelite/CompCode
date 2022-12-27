#pragma once
//https://cses.fi/problemset/task/1691

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
	int edges = 0;
	int nodes = 0;
	int startNode;
	vpii el; //edgelist
	vb visited;
	vi degree;
	vvpii adj; //adjacency list which also contains edge id for each edge
	vi path;
	si st;

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
			visited = vb(edges + 1, false); //is the edge visited
			degree = vi(nodes + 1, 0);
			adj = vvpii(nodes + 1, vpii());
			path = vi();
			st = si();
			startNode = 0;
			//1-indexed
			el = vpii(edges + 1);

			for (int i{ 1 }; i <= edges; ++i) {
				int arg1{};
				int arg2{};
				INPUT(arg1, arg2);

				el[i] = pii(arg1, arg2);
			}

			start();
		}
	}

	//Hierholzer's Algorithm
	void start() {
		for (int i{ 1 }; i <= edges; ++i) {
			pii elem{ el[i] };
			adj[elem.first].pb(pii(elem.second, i));
			adj[elem.second].pb(pii(elem.first, i));

			degree[elem.first] += 1;
			degree[elem.second] += 1;

			//if (degree[elem.first] % 2 != 0)
			//	startNode = elem.first;
			//else if (degree[elem.second] % 2 != 0)
			//	startNode = elem.second; incorrect, as a node with the odd degree may appear earlier than a node that gets its degree made even later. Do this in a consequent loop.
		}
		int oddCounter{ 0 };
		int zeroDeg{ 0 };
		for (int i{ 1 }; i <= nodes; ++i)
		{
			if (degree[i] % 2 != 0)
				++oddCounter;
			else if (degree[i] == 0)
				++zeroDeg;
		}

		//if ((oddCounter != 0 && oddCounter != 2) || zeroDeg != 0) //Decide if EP/EC exists. Use for EP/EC
		//{
		//	cout << "IMPOSSIBLE" << endl;
		//	return;
		//}
		if (oddCounter != 0) //EC only
		{
			cout << "IMPOSSIBLE" << endl;
			return;
		}

		traverse();

		if (path.size() != edges + 1) {
			cout << "IMPOSSIBLE" << endl;
			return;
			//specific to problem
		}

		output();
	}

	void traverse() {
		//st.push(startNode); //use this for EP
		st.push(1);
		while (!st.empty()) {
			int elem = st.top();
			bool isLast{ true };
			while (!adj[elem].empty())
			{
				int nextElem{ adj[elem].back().first };
				int i{ adj[elem].back().second };

				adj[elem].pop_back();

				if (!visited[i])
				{
					st.push(nextElem);
					visited[i] = true;
					isLast = false;
					break;
				}
			}

			if (isLast)
			{
				path.pb(elem);
				st.pop();
			}
		}
	}

	void output() {
		for (int elem : path)
			cout << elem << " ";
		cout << endl;
	}
};

#ifndef LOCAL
#undef int
int main() {
	Solution();
	return 0;
}
#endif