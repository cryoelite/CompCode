#pragma once
//https://leetcode.com/problems/merge-intervals/

#include <vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		//[[1, 4],[0,2]]
		if (intervals.empty()) return intervals;

		sort(intervals.begin(), intervals.end(), [](vector<int>& first, vector<int>& second) {return first.at(0) < second.at(0); });
		auto outputVec{ vector<vector<int>>({vector<int>({intervals.at(0).at(0), intervals.at(0).at(1)})}) };

		for (size_t index{ 1 }; index < intervals.size(); ++index)
		{
			//[[0,1],[1,4]]
			if (intervals.at(index).at(0) <= outputVec.back().at(1))
			{
				outputVec.back().at(1) = max(intervals.at(index).at(1), outputVec.back().at(1));
			}
			else {
				outputVec.push_back(intervals.at(index));
			}
		}

		return outputVec;
	}
};