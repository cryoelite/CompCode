#pragma once
//https://leetcode.com/problems/search-a-2d-matrix/

#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		auto rowIt{ find_if(matrix.begin(), matrix.end(), [&target](vector<int> row) {
			return row.at(0) > target;
			}) };
		if (rowIt > matrix.begin())
			rowIt--;

		return binarySearchResult(*rowIt, target);
	}
private:
	bool binarySearchResult(vector<int>& array, int& target) {
		int mid{ static_cast<int>(array.size()) / 2 };
		auto start{ 0 };
		auto end{ array.size() - 1 };

		while (mid >= start && mid <= end) {
			if (array.at(start) == target || array.at(end) == target || array.at(mid) == target)
				return true;

			start++;
			end--;
			if (array.at(mid) > target)
			{
				mid = (mid + start) / 2;
			}
			else {
				mid = (end + mid) / 2;
			}
		}
		return false;
	}
};