#pragma once
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include<vector>
#include<limits>
using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		auto minBuyPrice{ numeric_limits<int>::max() };
		auto maxProfit{ 0 };

		for (auto& price : prices) {
			if (price < minBuyPrice)
			{
				minBuyPrice = price;
			}
			else {
				auto temp = price - minBuyPrice;

				if (temp > maxProfit)
				{
					maxProfit = temp;
				}
			}
		}

		return maxProfit;
	}
};
