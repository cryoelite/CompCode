#include <iostream>
#include <vector>
#include "EasyBench.h"
/*
Sorting

*/
using namespace std;

//On^2 algs: Bubble sort
void func1(EasyBench& eb, vector<int> arr) {
	eb.startTimer();
	//Bubble sort
	for (auto index{ 0 }; index < arr.size(); ++index) {
		for (auto jIndex{ 0 }; jIndex < arr.size() - 1; ++jIndex)
		{
			if (arr[jIndex] > arr[jIndex + 1])
				swap(arr[jIndex], arr[jIndex + 1]);
		}
	}
	//The logic here is, after every iteration of swapping, the biggest element will be at the end. So we loop until the 2nd largest element and leave the last one
	//as is, then the 3rd largest and so on.

	eb.showresult();
	cout << "Array is: ";
	for (auto& elem : arr) {
		cout << elem << " ";
	}
	cout << endl;
}
void merge(vector<int>& arr, int start, int end, int split) {}

void mergeSort(vector<int>& arr, int startIndex, int endIndex) {
	if (startIndex >= endIndex)
		return;
	auto splitSize{ (int)((startIndex + endIndex) / 2) };
	cout << "Startindex: " << startIndex << "EndIndex: " << endIndex << "Split: " << splitSize << endl;
	mergeSort(arr, startIndex, splitSize);
	mergeSort(arr, splitSize, endIndex);
	merge(arr, startIndex, endIndex, splitSize);
}

//O(nlogn): Merge sort
void func2(EasyBench& eb, vector<int> arr) {
	eb.startTimer();
	mergeSort(arr, 0, arr.size() - 1);
	eb.showresult();
	cout << "Array is: ";
	for (auto& elem : arr) {
		cout << elem << " ";
	}
	cout << endl;
}