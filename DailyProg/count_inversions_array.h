#pragma once
//https://takeuforward.org/data-structure/count-inversions-in-an-array/

#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int inversions(vector<int>& array) {
		int counter{ 0 };
		auto tempVec{ vector<int>(array.size()) };
		split(0, array.size() - 1, array, counter, tempVec);

		//auto tempVector{ vector<int>(array.size())};
		//	counter = merge_Sort(array,tempVector, 0, array.size()-1);
		return counter;
	}
private:

	/*int merge(vector<int>& arr, vector<int>& temp, int left, int mid, int right)
	{
		int inv_count = 0;
		int i = left;
		int j = mid;
		int k = left;
		while ((i <= mid - 1) && (j <= right)) {
			if (arr[i] <= arr[j]) {
				temp[k++] = arr[i++];
			}
			else
			{
				temp[k++] = arr[j++];
				inv_count = inv_count + (mid - i);
			}
		}

		while (i <= mid - 1)
			temp[k++] = arr[i++];

		while (j <= right)
			temp[k++] = arr[j++];

		for (i = left; i <= right; i++)
			arr[i] = temp[i];

		return inv_count;
	}

	int merge_Sort(vector<int>& arr, vector<int>& temp, int left, int right)
	{
		int mid, inv_count = 0;
		if (right > left)
		{
			mid = (left + right) / 2;

			inv_count += merge_Sort(arr, temp, left, mid);
			inv_count += merge_Sort(arr, temp, mid + 1, right);

			inv_count += merge(arr, temp, left, mid + 1, right);
		}
		return inv_count;
	}*/

	void split(int start, int end, vector<int>& array, int& counter, vector<int>& tempVec)
	{
		if (start < end) {
			int mid{ (start + end) / 2 };
			split(start, mid, array, counter, tempVec);
			split(mid + 1, end, array, counter, tempVec);
			count(counter, array, tempVec, start, mid, end);
		}
	}

	void count(int& counter, vector<int>& array, vector<int>& tempVec, int start, int mid, int end) {
		auto tempStart{ start };
		auto tempMid{ mid++ };

		auto index{ 0 };
		while (start <= tempMid && mid <= end) {
			if (array.at(start) < array.at(mid)) {
				tempVec.at(index++) = array.at(start++);
			}
			else {
				counter += mid - start - (mid - tempMid - 1);
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
