#pragma once
//https://cses.fi/problemset/task/2134

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
	vvi adj;
	int nodes = 0;
	vi subSize;
	int queries = 1;
	vi depth;
	vi values;
	vi parents;
	vi segment_tree;
	vi id;
	vi tops;
	int counter = 1;

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
			subSize = vi(nodes + 1, 1);
			depth = vi(nodes + 1, 0);
			parents = vi(nodes + 1, 0);
			values = vi(nodes + 1, 0);
			id = vi(nodes + 1, 0);
			tops = vi(nodes + 1, 0);
			counter = 0;
			segment_tree = vi(2 * nodes, 0);

			for (int i{ 1 }; i <= nodes; ++i) {
				int arg{ 0 };
				INPUT(arg);

				values.at(i) = arg;
			}

			for (int i{ nodes - 1 }; i > 0; --i)
			{
				int arg1{ 0 };
				int arg2{ 0 };
				INPUT(arg1, arg2);

				adj.at(arg1).push_back(arg2);
				adj.at(arg2).push_back(arg1);
			}

			start();
		}
	}

	void start() {
		dfs(1, 1);
		hld(1, 1, 1);
		output();
	}

	void output() {
		while (queries-- > 0) {
			int arg1{ 0 };
			int arg2{ 0 };
			int arg3{ 0 };

			INPUT(arg1, arg2, arg3);
			if (arg1 == 1) {
				values.at(arg2) = arg3;
				update(id.at(arg2), values.at(arg2));
			}
			else if (arg1 == 2)
			{
				int res{ path(arg2,arg3) };
				cout << res << " ";
			}
		}
		cout << endl;
	}

	void dfs(int current, int prev = 0) {
		parents.at(current) = prev;

		for (int elem : adj.at(current))
		{
			if (elem == prev) continue;
			depth.at(elem) = depth.at(current) + 1;

			dfs(elem, current);

			subSize.at(current) += subSize.at(elem);
		}
	}

	/// <summary>
	/// HLD generation
	/// </summary>
	/// <param name="current"></param>
	/// <param name="parent"></param>
	/// <param name="top"></param>
	void hld(int current, int parent, int top) {
		id.at(current) = counter++;
		tops.at(current) = top;
		update(id.at(current), values.at(current));
		int h_child{ -1 };
		int h_subTreeSize{ -1 };
		for (int elem : adj.at(current))
		{
			if (elem == parent) continue;

			if (subSize.at(elem) > h_subTreeSize)
			{
				h_child = elem;
				h_subTreeSize = subSize.at(elem);
			}
		}

		if (h_child == -1) return;

		hld(h_child, current, top);
		for (int elem : adj.at(current)) {
			if (elem == parent || elem == h_child) continue;

			hld(elem, current, elem);
		}
	}

	/// <summary>
	/// Path from a to b.
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns></returns>
	int path(int a, int b) {
		int ret{ 0 };
		while (tops.at(a) != tops.at(b)) {
			if (depth.at(tops.at(a)) < depth.at(tops.at(b))) swap(a, b);
			ret = max(ret, query(id.at(tops.at(a)), id.at(a)));
			a = parents.at(tops.at(a));
		}
		if (depth.at(a) > depth.at(b)) swap(a, b);

		ret = max(ret, query(id.at(a), id.at(b)));

		return ret;
	}

	/// <summary>
	/// Max elem in the ST
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns></returns>
	int query(int a, int b) {
		a += nodes;
		b += nodes;
		int left{ 0 };
		int right{ 0 };
		while (a <= b) {
			if (a % 2 == 1)
				left = max(left, segment_tree.at(a++));

			if (b % 2 == 0)
				right = max(right, segment_tree.at(b--));

			a /= 2;
			b /= 2;
		}

		return max(left, right);
	}

	/// <summary>
	/// Updating the ST with an elem.
	/// </summary>
	/// <param name="pos"></param>
	/// <param name="elem"></param>
	void update(int pos, int elem) {
		pos += nodes;

		segment_tree.at(pos) = elem;

		for (int k{ pos / 2 }; k >= 1; k /= 2)
			segment_tree.at(k) = max(segment_tree.at(2 * k), segment_tree.at((2 * k) + 1));
	}
};

#ifndef LOCAL
#undef int
int main() {
	Solution();
	return 0;
}
#endif