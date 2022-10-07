#include<vector>
#include<iostream>

#include "minimum_money.h"
using namespace std;
int main() {
	//auto vec{ vector<vector<int>>({vector<int>({7,2}),vector<int>({0,10}),vector<int>({5,0}),vector<int>({4,1}), vector<int>({5,8}), vector<int>({5,9}) }) };
	auto vec{ vector<vector<int>>({vector<int>({2,1}),vector<int>({5,0}), vector<int>({4,2}) })	};
	auto soln{ Solution().minimumMoney(vec) };

	cout << soln << endl;

	return 0;
}


