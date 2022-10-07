#pragma once
#include<vector>
#include<numeric>
using namespace std;
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		constexpr int MAX{ numeric_limits<int>::max() - 1 };
		auto best{ MAX };
		auto values{ vector<int>(amount + 1, MAX) };
		values.at(0) = 0;

		for (auto i{ 1 }; i <= amount; ++i) {
			for (auto& c : coins) {
				if (i - c >= 0 && values.at(i - c) != -1) {
					best = min(best, values.at(i - c) + 1);
				}
			}
			values.at(i) = best == MAX ? -1 : best;
			best = MAX;
		}
		return values.at(amount);
	}
};