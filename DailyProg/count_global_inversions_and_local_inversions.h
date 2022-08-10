#pragma once
//https://leetcode.com/problems/global-and-local-inversions/

#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	using vec = vector<int>;
	using ll = long long;
	bool isIdealPermutation(vec& nums) {
		ll globalCounter{ 0 };
		ll localCounter{ 0 };
		auto tempVec{ vec(nums.size()) };
		auto origArray{ vector<int>(nums) };

		auto it{ nums.begin() };

		split(0, nums.size() - 1, globalCounter, localCounter, nums, tempVec, origArray);

		return globalCounter == localCounter;
	}

private:
	void split(int start, int end, ll& globalCounter, ll& localCounter, vec& array, vec& tempVec, vec& origArray)
	{
		if (start < end) {
			int mid{ (start + end) / 2 };
			split(start, mid, globalCounter, localCounter, array, tempVec, origArray);
			split(mid + 1, end, globalCounter, localCounter, array, tempVec, origArray);
			count(start, mid, end, globalCounter, localCounter, array, tempVec, origArray);
		}
	}

	void count(int start, int mid, int end, ll& globalCounter, ll& localCounter, vec& array, vec& tempVec, vec& origArray) {
		auto tempStart{ start };
		auto tempMid{ mid++ };
		auto index{ 0 };
		while (start <= tempMid && mid <= end) {

			if (array.at(start) < array.at(mid)) {
				tempVec.at(index++) = array.at(start++);
			}
			else {
				globalCounter += mid - start - (mid - tempMid - 1);
				if (origArray.at(start) > origArray.at(mid) && mid-start==1)
				{
					localCounter++;
				}
				tempVec.at(index++) = array.at(mid++);
			}

		}

		while (start <= tempMid) {
			tempVec.at(index++) = array.at(start++);
		}

		while (mid <= end) {
			tempVec.at(index++) = array.at(mid++);
		}

		swap_ranges(array.begin() + tempStart, array.begin() + end + 1, tempVec.begin());
	}
};