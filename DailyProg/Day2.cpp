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

void divide(int size,int index, vector<int> &arr) {
	if (size > 1)
	{
		auto newSize{ (int)size / 2 };
		divide(newSize,index, arr);
		divide(newSize-size,index+newSize, arr);
	}

}

void merge(vector<int>& arr) {}

//O(nlogn): Merge sort
void func2(EasyBench& eb, vector<int> arr) {
	eb.startTimer();
	auto splitSize{ (int)arr.size()/2 };
	divide(splitSize,0, arr);
	divide(arr.size() - splitSize,splitSize, arr);
	merge(arr);
	eb.showresult();
	cout << "Array is: ";
	for (auto& elem : arr) {
		cout << elem << " ";
	}
	cout << endl;

}



int main() {
	vector<int> arr{ 1,3,8,2,9,2,5,6};
	auto easyBench{ EasyBench() };

	auto alg{ 0 };
	while (true) {
		switch (alg) {
		case 0: func1(easyBench, arr);
			break;
		case 1: func2(easyBench, arr);
			break;
		default: goto elx;

		}

		alg++;
	}
elx:
	return 0;
}
