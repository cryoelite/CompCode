#pragma once

#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:

	void nextPermutation(vector<int>& nums) {
		auto firstIt{ nums.rbegin() + 1 };
		auto endIt{ nums.rbegin() };

		while (firstIt < nums.rend()) {
			if (*firstIt < *(firstIt - 1)) {
				auto dbgVal{ *(firstIt - 1) };
				auto secondIt{ endIt };
				while (secondIt < firstIt) {
					if (*secondIt > *firstIt) {
						iter_swap(firstIt, secondIt);
						break;
					}
					++secondIt;
				}
				break;
			}

			++firstIt;
		}

		if (firstIt == nums.rend()) {
			reverse(nums.begin(), nums.end());
		}
		else {
			reverse(endIt, firstIt);
		}
	}
}; 