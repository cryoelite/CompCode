#pragma once
//https://leetcode.com/problems/majority-element-ii/

#include<vector>
#include<math.h>
using namespace std;

namespace {
	class Element {
	public:
		int value;
		int count;

		Element(int value, int count)
		{
			this->value = value;
			this->count = count;
		}
	};
}
class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		//boyer-moore alg. For n/3, the max majority elements can only be 2.
		auto numVec{ vector<int>() };
		auto elemOne{ Element(-1,0) };
		auto elemTwo{ Element(-1,0) };

		for (auto& element : nums)
		{
			if (element == elemOne.value)
				++elemOne.count;
			else if (element == elemTwo.value)
				++elemTwo.count;
			else if (elemOne.count == 0)
			{
				elemOne.value = element;
				++elemOne.count;
			}
			else if (elemTwo.count == 0) {
				elemTwo.value = element;
				++elemTwo.count;
			}
			else {
				--elemOne.count;
				--elemTwo.count;
			}
		}
		elemOne.count = 0;
		elemTwo.count = 0;
		for (auto& element : nums)
		{
			if (element == elemOne.value)
			{
				++elemOne.count;
			}
			else if (element == elemTwo.value)
			{
				++elemTwo.count;
			}
		}
		int maxNCount{ static_cast<int>(floor(static_cast<int>(nums.size()) / 3)) };
		if (elemOne.count > maxNCount)
			numVec.push_back(elemOne.value);
		if (elemTwo.count > maxNCount)
			numVec.push_back(elemTwo.value);

		return numVec;
	}
};
