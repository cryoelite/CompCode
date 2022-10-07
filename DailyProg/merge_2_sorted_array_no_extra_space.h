#pragma once

//https://takeuforward.org/data-structure/merge-two-sorted-arrays-without-extra-space/

#include <vector>
#include<ranges>
using namespace std;
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int interval{ static_cast<int>(ceil((m + n) * 1.0 / 2.0)) };
		//	auto vec1{ vector<int>({1,4,8,10}) };
		//auto vec2{ vector<int>({2,3,9}) };
		//6
		//
		while (interval > 1) {
			auto startIndex{ 0 };
			auto endIndex{ interval - 1 };

			while (endIndex < m + n) {
				auto startIt{ startIndex >= m ? nums2.begin() + (startIndex - m) : nums1.begin() + startIndex };
				auto endIt{ endIndex >= m ? nums2.begin() + (endIndex - m) : nums1.begin() + endIndex };
				if (*startIt > *endIt) {
					swap(*startIt, *endIt);
				}

				startIndex++;
				endIndex++;
			}

			interval = static_cast<int>(ceil(interval * 1.0 / 2.0));
		}
	}

	//merges them but stores them in only array 1.
	void merge3(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		auto gap{ static_cast<int>(ceil((m + n) / 2)) };
		auto firstIndex{ 0 };
		auto secondIndex{ gap };
		int* firstValue;
		int* secondValue;
		while (gap > 0) {
			firstIndex = 0;
			secondIndex = gap;

			while (secondIndex < m + n) {
				if (firstIndex < m)
					firstValue = &nums1.at(firstIndex);
				else
					firstValue = &nums2.at(firstIndex - m);
				if (secondIndex < m)
					secondValue = &nums1.at(secondIndex);
				else
					secondValue = &nums2.at(secondIndex - m);

				if (*secondValue < *firstValue)
				{
					swap(*firstValue, *secondValue);
				}

				++firstIndex;
				++secondIndex;
			}

			if (gap == 1)
				gap = 0;
			gap = static_cast<int>(ceil(gap / 2.0));
		}
		move(nums2.begin(), nums2.end(), nums1.begin() + m);
	}

	//merges them in place and uses both arrays
	void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		auto gap{ static_cast<int>(ceil(m + n / 2)) };
		auto firstIndex{ 0 };
		auto secondIndex{ gap };
		int* firstValue;
		int* secondValue;
		while (gap > 0) {
			firstIndex = 0;
			secondIndex = gap;

			while (secondIndex < m + n) {
				if (firstIndex < m)
					firstValue = &nums1.at(firstIndex);
				else
					firstValue = &nums2.at(firstIndex - m);
				if (secondIndex < m)
					secondValue = &nums1.at(secondIndex);
				else
					secondValue = &nums2.at(secondIndex - m);

				if (*secondValue < *firstValue)
				{
					swap(*firstValue, *secondValue);
				}

				++firstIndex;
				++secondIndex;
			}

			gap /= 2;
		}
	}
};