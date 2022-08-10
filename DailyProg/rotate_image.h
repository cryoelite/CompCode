#pragma once
//https://leetcode.com/problems/rotate-image/

#include<vector>
#include<limits>
using namespace std;
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		auto outputMatrix{ vector<vector<int>>(matrix.size()) };
		auto columnSize{ matrix.at(0).size() };
		for (auto column{ 0 }; column < matrix.size(); ++column)
		{
			outputMatrix.at(column).assign(columnSize, -1);
		}

		for (size_t row{ 0 }; row < matrix.size(); ++row)
		{
			for (size_t column{ 0 }; column < matrix.at(row).size(); ++column)

			{
				auto newColumn{ columnSize - row - 1 };
				auto newRow{ column };

				outputMatrix.at(newRow).at(newColumn) = matrix.at(row).at(column);
			}
		}

		matrix = move(outputMatrix);
	}

	void rotate2(vector < vector < int >>& matrix) {
		int n = matrix.size();
		//transposing the matrix
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				swap(matrix[i][j], matrix[j][i]);
			}
		}
		//reversing each row of the matrix
		for (int i = 0; i < n; i++) {
			reverse(matrix[i].begin(), matrix[i].end());
		}
	}
};/*
  size=2
  col=0
  row=0

  col=2
  -row=0

  col=1
  row=0

  col=2
  -row=1

  col=2
  row=0

  col=2
  -row=2

  col=0
  row=1

  col=1
  -row=0

  col=1
  row=1

  col=1
  -row=1

  col=2
  row=1

  col=1
  -row=2

  col=0
  row=2

  col=0

  col=1
  row=2

  col=0

  col=2
  row=2

  col=0

  size=3

  col=0
  row=3

	col=0

	col=1
	row=3

	col=0

	col=2
	row=3

	col=0

	col=3
	row=3

	col=0

  */