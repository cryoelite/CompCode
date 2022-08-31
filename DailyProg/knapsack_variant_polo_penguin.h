#pragma once
//https://www.codechef.com/problems/PPTEST/
#include<vector>

using namespace std;
class Solution {
public:
	
	int maxPoints(vector<vector<int>>& questions, int& minutes, int& n) {
		auto isPossible{ vector<vector<bool>>(n +1 , vector<bool>(minutes+1, false))};
		isPossible.at(0).at(0) = true;
		auto result{ 0 };
		auto tempValue{ 0 };
		
		for (auto wt{ 1 }; wt <= n; ++wt) {
			for (auto i{ 0 }; i <= minutes; ++i) {
				tempValue = questions.at(wt - 1)[2]; //weight
				if (i - tempValue >= 0)
					isPossible.at(wt).at(i) = isPossible.at(wt - 1).at(i - tempValue);
				isPossible.at(wt).at(i) = isPossible.at(wt).at(i) || isPossible.at(wt - 1).at(i);
			}
		}
		
		for (auto curr{ minutes }; curr > 0; --curr) {
			for (auto tempN{ n - 1 }; tempN > 0; --tempN) {
				if (isPossible.at(tempN).at(curr)) {
					result += (questions.at(tempN - 1)[0] * questions.at(tempN - 1)[1]);
					curr = curr - questions.at(tempN - 1)[2];
					--tempN;
				}
			}
			
		}

		return result;

	}
};