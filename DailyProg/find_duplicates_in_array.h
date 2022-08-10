#pragma once
//https://leetcode.com/problems/find-the-duplicate-number/

#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		//floyds hare and tortoise method
		auto rabbit{ nums.begin() };
		auto turtle{ nums.begin() };
		//3,1,3,4,2
		do {
			turtle = nums.begin() + *turtle; //3   4    2    3    4   2   3   4   2   3
			rabbit = nums.begin() + *rabbit; //3  4 2  3 4  2 3  4 2
			rabbit = nums.begin() + *rabbit;
		} while (turtle != rabbit);
		turtle = nums.begin();
		while (*turtle != *rabbit) {
			turtle = nums.begin() + *turtle; //3  4
			rabbit = nums.begin() + *rabbit; //3  4
		}

		return *turtle;
	}
	//Unknown how to do it.One more method is by comparing the sum of array to the sum of numbers from 1 to N using AP, the difference giving us the repeating no. Time O(N) and space O(1) but only detects 1 duplicate.
	//And another method is by using a hash set, which stores the numbers and then we check if the no. already exists. Time O(N) but space O(N)
	
	//[1:N] 
	int findDuplicate2(vector<int>& nums) {
		auto trackerIt{ nums.begin() };
		auto beginIt{ nums.begin() };
		auto tempIt{ nums.begin() };
		auto tempValue{ 0 };
		while (trackerIt != nums.end()) {
			tempValue = abs(*(trackerIt));
			tempIt = (beginIt + tempValue);
			if (*tempIt < 0)
				return tempValue;

			*tempIt *= -1;
			++trackerIt;
		}

		return -1;
	}
};