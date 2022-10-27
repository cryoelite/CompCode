#pragma once

//https://cses.fi/problemset/task/1648

#include<iostream>
#include<vector>
#include<fstream>
#include<string>

using namespace std;
#define LOG(x) static_cast<int>(floor(log2(x)))
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define LOCAL
template<typename... T>
void INPUT(T&... args) { ((cin >> args), ...); }
template<typename... T>
void OUTPUT(T&... args) { ((cout << args << " "), ...); cout << "\n"; }
#define ARR_INPUT(arr,x) for(auto i{0}; i<x; ++i) {int y;cin>> y; arr.push_back(y);}
using ll = long long int;
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

#endif
		auto testCases{ 0 };
		//cin >> testCases;
		testCases = 1;
		while (testCases-- > 0)
		{
			ll nValues{ 0 };
			ll nQueries{ 0 };
			INPUT(nValues, nQueries);

			//We can simply use only the biTree, but for subtraction, we need the origional array.

			/*
			//There are 2 ways to generate the biTree, first is to directly create a biTree by input and update
			// second is to get the input and then generate it seperately. This is the former method.
			//1-indexed
			auto biTree{ vector<int>(nValues + 1) };
			auto arr{ vector<int>(nValues+1) };
			for (int i{ 1 }; i <= nValues; ++i)
			{
				auto temp{ 0 };
				INPUT(temp);

				arr.at(i)=(temp);
				update(i, temp, biTree, nValues);
			}*/

			auto arr{ vector<ll>() };
			ARR_INPUT(arr, nValues);
			arr.emplace(arr.begin(), 0);
			auto biTree{ vector<ll>(arr.begin(), arr.end()) };
			generateBiTree(biTree, nValues);

			while (nQueries-- > 0)
			{
				auto query{ 0 };
				ll firstArg{ 0 };
				ll secondArg{ 0 };
				INPUT(query, firstArg, secondArg);

				if (query == 1)
				{
					update(firstArg, secondArg - arr.at(firstArg), biTree, nValues); //Update here adds and subtracts. If the new value is < old value, then it would send a -ve value to be added, otherwise +ve.
					arr.at(firstArg) = secondArg;
				}
				else if (query == 2)
					cout << range_sum(secondArg, biTree) - range_sum(firstArg - 1, biTree) << "\n";
			}
		}
	}

	void generateBiTree(vector<ll>& biTree, ll nSize) {
		ll p{ 0 };
		for (ll i{ 1 }; i <= nSize; ++i) {
			p = i & -i;
			if ((i + p) <= nSize)
				biTree.at(i + p) += biTree.at(i);
		}
	}

	ll range_sum(ll k, vector<ll>& biTree) {
		ll s{ 0 };
		while (k >= 1) {
			s += biTree[k];
			k -= k & -k;
		}
		return s;
	}

	void update(ll pos, ll value, vector<ll>& biTree, ll nSize)
	{
		while (pos <= nSize) {
			biTree[pos] += value;
			pos += pos & -pos;
		}
	}
};
