#pragma once
//https://leetcode.com/problems/pascals-triangle/

#include<vector>
#include<algorithm>
#include <cmath>


using namespace std;
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		auto outputVec{ vector<vector<int>>(numRows,vector<int>(1,1)) };

		for (size_t xIndex{ 1 }; xIndex < outputVec.size(); ++xIndex)
		{
			for (size_t yIndex{ 1 }; yIndex <= xIndex; ++yIndex)
			{
				auto firstValue{ xIndex != yIndex ? outputVec.at(xIndex - 1).at(yIndex) : 0 };

				auto secondValue{ outputVec.at(xIndex - 1).at(yIndex - 1) };

				outputVec.at(xIndex).push_back(firstValue + secondValue);
			}
		}
		return outputVec;
	}

	//nCr approach
	vector<vector<int>> generate2(int numRows) {
			auto outputVec{ vector<vector<int>>(numRows) };
			auto n{ 0 };
			auto r{ 0 };


			auto generator{ [&n,&r]() mutable -> int {


				auto value{round(exp(lgamma(n + 1) - (lgamma(r + 1) + lgamma(n - r + 1))))};
				//auto value{tgamma(n + 1) / (tgamma(r + 1) * tgamma(n - r + 1))};
				//auto value{round(1 / ((n + 1) * beta(n - r + 1,r + 1)))};
				if (r < n)
					++r;
				else {
					r = 0;
					++n;
					}
				return value;
			} };
			for (size_t x{ 0 }; x < outputVec.size(); ++x) {
				outputVec.at(x) = vector<int>(n + 1);
				std::generate(outputVec.at(x).begin(), outputVec.at(x).end(), generator);

			}
			return outputVec;

		}
};