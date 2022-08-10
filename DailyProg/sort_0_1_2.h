#pragma once

//https://leetcode.com/problems/sort-colors/

#include<vector>
#include<set>
using namespace std;
class Solution {
public:
	void sortColors(vector<int>& nums) {
		auto setNums{ multiset<int>(make_move_iterator(nums.begin()),make_move_iterator(nums.end())) };
		nums.assign(make_move_iterator(setNums.begin()), make_move_iterator(setNums.end()));
	}

	void sortColorsHard(vector<int>& nums) {
		auto setNums{ multiset<int>(nums.begin(),nums.end()) };
		nums.assign(setNums.begin(), setNums.end());
	}

	//aka 3 pointer approach
	void sortColorsDutchNationalFlagAlg(vector<int>& nums) {
		auto beg{ nums.begin() };
		auto mid{ nums.begin() };
		auto end{ nums.end() - 1 };

		while (mid <= end)
		{
			switch (*mid) {
			case 0: iter_swap(mid++, beg++);
				break;
			case 1: mid++;
				break;
			case 2: iter_swap(mid, end--);
				break;
			}
		}
	}
};