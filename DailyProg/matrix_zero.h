#pragma once
#include<vector>
//https://leetcode.com/problems/set-matrix-zeroes/

using namespace std;
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		auto rowSizedVector{ vector<int>(matrix.size(),-1) };
		auto columnSizedVector{ vector<int>(matrix.at(0).size(),-1) };
		for (size_t x{ 0 }; x < matrix.size(); ++x)
		{
			for (size_t y{ 0 }; y < matrix.at(x).size(); ++y)
			{
				if (matrix.at(x).at(y) == 0)
				{
					rowSizedVector.at(x) = 0;
					columnSizedVector.at(y) = 0;
				}
			}
		}
		for (size_t x{ 0 }; x < matrix.size(); ++x)
		{
			for (size_t y{ 0 }; y < matrix.at(x).size(); ++y)
			{
				if (rowSizedVector.at(x) == 0 || columnSizedVector.at(y) == 0)
				{
					matrix.at(x).at(y) = 0;
				}
			}
		}
	}
};