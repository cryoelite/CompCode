#pragma once
//https://cses.fi/problemset/task/1688

#define LOCAL
#pragma region HEADERS

#ifdef LOCAL
#include<iostream>
#include<vector>
#include<algorithm>
#include <map>
#include<limits>
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
	vvi adj;
	int nodes = 0;

	int queries = 1;
	vi depth;
	vpii euler_tour_tree;
	int marker;

	vpii segment_tree;

	vi ett_indices;

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
			INPUT(nodes, queries);

			//1-indexed
			adj = vvi(nodes + 1, vi());

			for (int i{ 2 }; i <= nodes; ++i)
			{
				int arg{ 0 };
				INPUT(arg);

				adj.at(i).push_back(arg);
				adj.at(arg).push_back(i);
			}

			depth = vi(nodes + 1, 0);

			//0-indexed
			euler_tour_tree = vpii((2 * nodes) - 1, pii(0, 0));  //first is node id, second is node depth.
			marker = 0;
			segment_tree = vpii(4 * nodes, pii(0, intmax)); //first is node id, second is value.

			ett_indices = vi(nodes + 1, 0);

			start();
		}
	}

	void start() {
		dfs(1, 0);

		output();
	}

	void output() {
		while (queries-- > 0) {
			int arg1{ 0 };
			int arg2{ 0 };

			INPUT(arg1, arg2);
			arg1 = ett_indices.at(arg1);
			arg2 = ett_indices.at(arg2);

			if (arg1 > arg2) swap(arg1, arg2);

			cout << min_node(arg1, arg2) << " ";
		}

		cout << endl;
	}

	void dfs(int current, int prev) {
		euler_tour_tree.at(marker) = pii(current, depth.at(current));
		update_ST(marker, depth.at(current), current);

		ett_indices.at(current) = marker++;

		for (auto elem : adj.at(current))
		{
			if (elem == prev) continue;
			depth.at(elem) = depth.at(current) + 1;

			dfs(elem, current);

			euler_tour_tree.at(marker) = pii(current, depth.at(current));
			update_ST(marker++, depth.at(current), current);
		}
	}

	int min_node(int a, int b) {
		a += 2 * nodes;
		b += 2 * nodes;
		int ans = intmax;
		int node = 0;
		while (a <= b) {
			if (a % 2 == 1) {
				if (segment_tree.at(a).second < ans)
				{
					ans = segment_tree.at(a).second;
					node = segment_tree.at(a).first;
				}
				++a;
			}
			if (b % 2 == 0) {
				if (segment_tree.at(b).second < ans)
				{
					ans = segment_tree.at(b).second;
					node = segment_tree.at(b).first;
				}
				--b;
			}

			a /= 2;
			b /= 2;
		}

		return node;
	}

	void update_ST(int pos, int elem, int node) {
		pos += 2 * nodes;

		if (elem < segment_tree.at(pos).second) {
			segment_tree.at(pos).first = node;
			segment_tree.at(pos).second = elem;
		}

		//segment_tree.at(pos) += elem;
		for (int i{ pos / 2 }; i >= 1; i /= 2) {
			//	segment_tree.at(i) = segment_tree.at(2 * i) + segment_tree.at((2 * i) + 1);
			if (segment_tree.at(2 * i).second < segment_tree.at((2 * i) + 1).second)
				segment_tree.at(i) = segment_tree.at(2 * i);
			else
				segment_tree.at(i) = segment_tree.at((2 * i) + 1);
		}
	}
};
