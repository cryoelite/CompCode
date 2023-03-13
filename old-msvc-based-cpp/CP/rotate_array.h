#pragma once
#include<vector>
#include<iostream>
//https://leetcode.com/explore/featured/card/top-interview-questions-easy/92/array/646/

using namespace std;
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		auto marker = [&nums, &k]()-> vector<int>::iterator {
			return nums.end() - k;
		};

		nums.insert(nums.begin(), marker(), nums.end());

		nums.erase(marker(), nums.end());
		for (auto& x : nums)
		{
			cout << x << " ";
		}
		cout << endl;
	}
};