#pragma once
//https://leetcode.com/problems/minimum-path-sum/
#include<vector>

using namespace std;
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		auto rowSize{ grid.size() };
		auto columnSize{ grid.at(0).size() };
		constexpr int MAX{ static_cast<int>(1e9 + 5) };
		auto costMatrix{ vector<vector<int>>(rowSize, vector<int>(columnSize)) };

		for (auto i{ 0 }; i < rowSize; ++i) {
			for (auto j{ 0 }; j < columnSize; ++j) {
				if (i - 1 >= 0 || j - 1 >= 0)
					costMatrix.at(i).at(j) = grid.at(i).at(j) + min(i - 1 < 0 ? MAX : costMatrix.at(i - 1).at(j), j - 1 < 0 ? MAX : costMatrix.at(i).at(j - 1));
				else
					costMatrix.at(i).at(j) = grid.at(i).at(j);
			}
		}

		return costMatrix.at(rowSize - 1).at(columnSize - 1);
	}
};
