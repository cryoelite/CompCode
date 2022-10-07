#pragma once
//https://leetcode.com/problems/majority-element/

#include<vector>

using namespace std;
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		//boyer-moore alg

		int count{ 0 };
		int currentElement{ nums.at(0) };
		for (auto& elem : nums)
		{
			if (count == 0)
			{
				currentElement = elem;
			}
			if (currentElement == elem)
			{
				++count;
			}
			else {
				--count;
			}
		}

		return currentElement;
	}
};