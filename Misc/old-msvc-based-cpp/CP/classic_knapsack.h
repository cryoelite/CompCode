#pragma once
//  Weight array is given, denote all sums from those weights
#include<vector>
#include<numeric>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
	/*void knapsack(vector<int>& weights, vector<int>& sums) {
		auto maxSum{ accumulate(weights.begin(), weights.end(),0) };
		auto wtSize{ weights.size() };
		auto isPossible{ vector<vector<bool>>(wtSize + 1, vector<bool>(maxSum+1, false)) };
		isPossible.at(0).at(0) = true;
		for (auto wt{ 1 }; wt <= wtSize; ++wt) {
			for (auto i{ 0 }; i <= maxSum; ++i) {
				if (i - weights.at(wt - 1) >= 0) {
					isPossible.at(wt).at(i) = isPossible.at(wt - 1).at(i - weights.at(wt - 1));
				}
				isPossible.at(wt).at(i) = isPossible.at(wt).at(i) || isPossible.at(wt - 1).at(i);
			}
		}

		auto maxSumArray{ &isPossible.at(wtSize) };
		for (auto i{ 0 }; i < (*maxSumArray).size(); ++i) {
			if (maxSumArray->at(i)) {
				sums.push_back(i);
			}
		}
	}
	*/

	void knapsack2(vector<int>& weights, vector<int>& sums) {
		int maxSum{ accumulate(weights.begin(), weights.end(), 0) };
		auto wtSize{ weights.size() };
		auto isPossible{ vector<vector<bool>>(wtSize + 1, vector<bool>(maxSum + 1, false)) };
		isPossible.at(0).at(0) = true;

		for (auto i{ 1 }; i <= wtSize; ++i) {
			for (auto k{ 0 }; k <= maxSum; ++k) {
				if (k - weights.at(i - 1) >= 0) {
					isPossible.at(i).at(k) = isPossible.at(i - 1).at(k - weights.at(i - 1));
				}

				isPossible.at(i).at(k) = isPossible.at(i).at(k) || isPossible.at(i - 1).at(k);
			}
		}

		for (auto i{ 0 }; i <= maxSum; ++i)
		{
			if (isPossible.at(wtSize).at(i))
			{
				sums.push_back(i);
			}
		}
	}
};