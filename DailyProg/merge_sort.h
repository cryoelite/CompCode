#pragma once

#include<vector>

using namespace std;
class Solution {
public:
	void mergeSort(vector<int>& array) {
		sort(0, array.size() - 1, array);
		

	}
private:
	void sort(int start, int end, vector<int>& array) {
		if (start < end)
		{
			int mid = (start + end) / 2;
			sort(start, mid, array);
			sort(mid + 1, end, array);
			merge(start, mid, end, array);
		}
	}

	void merge(int start, int mid, int end, vector<int>& array) {
		auto tempMid{ mid++ };
		auto currentIndex{ 0 };
		auto tempStart{ start };
		auto output{ vector<int>(end - start + 1) };

		while (start <= tempMid && mid <= end)
		{
			if (array.at(start) < array.at(mid))
			{
				output.at(currentIndex++) = array.at(start++);
			}
			else {
				output.at(currentIndex++) = array.at(mid++);
			}
		}

		while (start <= tempMid)
		{
			output.at(currentIndex++) = array.at(start++);
		}

		while (mid <= end) {
			output.at(currentIndex++) = array.at(mid++);
		}

		for (size_t index{ static_cast<size_t>(tempStart) }, beg{ 0 }; index <= end; ++index, ++beg) {
			array.at(index) = output.at(beg);
		}
	}
};
