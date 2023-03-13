#pragma once

#include<vector>
//
using namespace std;
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		for (auto x{ nums.end() - 1 }; x > nums.begin(); x--)
		{
			if (*(x - 1) == *x)
			{
				nums.erase(x);
			}
		}

		return nums.size();
	}
};
