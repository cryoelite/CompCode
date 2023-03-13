#pragma once
//https://takeuforward.org/data-structure/find-the-repeating-and-missing-numbers/

#include<vector>
#include<numeric>
#include<iostream>
#include<bitset>
using namespace std;
class Solution {
public:
	void find_missing_repeating(vector<int>& array) {
		auto xorrer{ [](int a, int b) {
			return a ^ b;
		} };

		//step 1: xor array
		auto arrayXor{ reduce(array.begin(),array.end(), 0, xorrer) };

		//step 2: xor with a continuous series

		auto resultXor{ array.size() };
		auto counter{ 0 };

		for (auto& elem : array)
		{
			resultXor ^= elem;
			resultXor ^= counter;
			++counter;
		}

		//result is X^Y where X is missing and Y is repeating.
		//step 3: Seperate array elements into 2 buckets depending on their rightmost bit.
		int setBitIndex{ 0 };
		auto tempResult{ resultXor };
		while ((tempResult & 1) != 1)
		{
			tempResult >>= 1;
			setBitIndex++;
		}

		auto X{ 0 };
		auto Y{ 0 };

		for (auto& elem : array)
		{
			int bitAtIndex{ bitset<8>(elem)[setBitIndex] };
			if (bitAtIndex == 1)
			{
				X ^= elem;
			}
			else {
				Y ^= elem;
			}
		}

		//step 4: xor X and Y with a continuous series

		counter = 0;
		while (counter <= array.size())
		{
			int bitAtIndex{ bitset<8>(counter)[setBitIndex] };
			if (bitAtIndex == 1)
			{
				X ^= counter;
			}
			else {
				Y ^= counter;
			}
			++counter;
		}

		cout << "X is " << X << " and Y is " << Y;
	}
};