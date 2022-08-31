#include<vector>
#include<iostream>

#include "knapsack_variant_polo_penguin.h"
using namespace std;
int main() {
	auto vec{ vector<vector<int>>({vector<int>({1,2,3}),vector<int>({2,3,5}), vector<int>({3,3,3})}) };



	
	auto minutes{ 7 };
	auto n{ 3 };

	cout << Solution().maxPoints(vec, minutes, n);
	cout << endl;

	return 0;

}