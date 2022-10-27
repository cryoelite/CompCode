#pragma once

//https://cses.fi/problemset/task/1647

#include<iostream>
#include<vector>

using namespace std;
#define LOG(x) static_cast<int>(floor(log2(x)))
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define LOCAL
template<typename... T>
void INPUT(T&... args) { ((cin >> args), ...); }
template<typename... T>
void OUTPUT(T&... args) { ((cout << args << " "), ...); cout << "\n"; }
#define ARR_INPUT(arr,x) for(auto i{0}; i<x; ++i) {int y;cin>> y; arr.push_back(y);}

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
		//freopen("../../../input.txt", "r", stdin);
		//freopen("../../../output.txt", "w", stdout);

#endif
		auto testCases{ 0 };
		//cin >> testCases;
		testCases = 1;
		while (testCases-- > 0)
		{
			auto nValues{ 0 };
			auto nQueries{ 0 };
			INPUT(nValues, nQueries);

			auto values{ vector<int>() };
			ARR_INPUT(values, nValues);
			auto spTable{ vector<vector<int>>() };
			//auto altspTable{ vector<vector<int>>() };
			generate_sparse_table(values, spTable, nValues);
			//generate_alternate_sparse_table(values, altspTable, nValues);
			//cout << std::boolalpha << "Are tables equal ?" << "\n" << (spTable == altspTable) << "\n";
			while (nQueries-- > 0)
			{
				auto start{ 0 };
				auto end{ 0 };
				INPUT(start, end);

				cout << rmq(start, end, spTable) << "\n";
				//cout << alt_rmq(start, end, altspTable) << "\n";
			}
		}
	}

	static void generate_sparse_table(vector<int>& arr, vector<vector<int>>& spTable, int& arrSize) {
		auto logVal{ LOG(arr.size()) };

		spTable = vector<vector<int>>(logVal + 1, vector<int>(arrSize));
		spTable.at(0) = arr;

		for (auto i{ 1 }; i < logVal + 1; ++i) {
			int w{ 1 << i };
			for (auto j{ 0 }; j + w - 1 < arrSize; ++j)
			{
				spTable.at(i).at(j) = min(spTable.at(i - 1).at(j), spTable.at(i - 1).at(j + w / 2));
			}
		}
	}
	/*
	static void generate_alternate_sparse_table(vector<int>& arr, vector<vector<int>>& spTable, int& arrSize)
	{
		auto logVal{ LOG(arr.size()) };

		spTable = vector<vector<int>>(logVal + 1, vector<int>(arr.size()));
		spTable.at(0) = arr;

		int x = 1;

		while ((1 << x) <= arrSize) {
			int d = (1 << x);
			for (int i = 0; i < (arrSize - d + 1); ++i)
				spTable[x][i] = min(spTable[x - 1][i], spTable[x - 1][i + d / 2]);
			x++;
		}
	}

	static int alt_rmq(int start, int end, vector<vector<int>>& spTable) {
		int k = log2(end - start + 1);
		--start; --end;
		return min(spTable[k][start], spTable[k][end - (1 << k) + 1]);
	}
	*/

	/// <summary>
	/// Range Minimum Query
	/// </summary>
	/// <param name="start"></param>
	/// <param name="end"></param>
	/// <param name="spTable"></param>
	/// <returns></returns>
	static int rmq(int start, int end, vector<vector<int>>& spTable) {
		int k{ LOG(end - start + 1) };
		--start; --end;
		return min(spTable[k][start], spTable[k][end - (1 << k) + 1]);
	}
};
