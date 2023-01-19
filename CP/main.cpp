#include<vector>
#include<iostream>

#include "EasyBench.h"
#include "download_speed_capacity_scaling.h"

using namespace std;
signed main() {
	//auto vec{ vector<vector<int>>({vector<int>({7,2}),vector<int>({0,10}),vector<int>({5,0}),vector<int>({4,1}), vector<int>({5,8}), vector<int>({5,9}) }) };
//	auto vec{ vector<int>({3,2,4,5,1,1,5,3 })
//};
//	auto soln{ Solution(vec)};
//
//	cout << soln.rmq(1,1) << endl;
	auto eb{ EasyBench() };
	eb.startTimer();
	Solution();
	eb.showresult();

	return 0;
}