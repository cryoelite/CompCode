#include<vector>
#include<iostream>
#include<assert.h>
#include<vector>

#include "Temp_solution.h"


using namespace std;
int main() {
	auto vec1{ vector<int>({3,1,3,4,2}) };
	cout << Solution().findDuplicate(vec1);
	
	cout << endl;

	return 0;

}
#pragma region old
/*
	auto eb{EasyBench()};
	auto vec{ vector<int>({1,3,2,3,1}) };
	eb.startTimer();
	cout << Solution().reversePairs(vec) << endl;
	eb.showresult();

	vec = { 2,4,3,5,1 };
	eb.startTimer();
	cout << Solution().reversePairs(vec) << endl;
	eb.showresult();

	vec = { 2,0,1 };
	eb.startTimer();
	cout << Solution().reversePairs(vec) << endl;
	eb.showresult();


	vec = { 1,0,2};
	eb.startTimer();
	cout << Solution().reversePairs(vec) << endl;
	eb.showresult();
*/
/*
	auto eb{ EasyBench() };
	auto soln{ Solution() };
	auto result{ 0.0 };

	cout << "\nDummy run to initialize benchmarker\n";
	eb.startTimer();
	result = soln.myPow(2, 4);
	eb.showresult();
	cout << "\nDummy run over\n";

	eb.startTimer();
	result = soln.myPow(2, 560);
	eb.showresult();

	cout << "\n" << result << "\n";

	eb.startTimer();
	result = soln.myPow2(2, 560);
	eb.showresult();

	cout << "\n" << result << "\n";

	return 1;

*/
/*
	auto vec{ vector<vector<int>>({vector<int>({1,3,5,7}),vector<int>({10,11,16,20}),vector<int>({23,30,34,60})}) };
	cout<<boolalpha<<Solution().searchMatrix(vec, 3);

	vec = vector<vector<int>>({ vector<int>({1}) });
	cout << boolalpha << Solution().searchMatrix(vec, 0);
*/
/*
	auto vec{ vector<int>({3,1,3,4,2}) };
	auto soln{ Solution().findDuplicate(vec) };

	assert(((void)[&]() { cout << "It is "<< soln<< endl; }(), soln== 3));
*/
/*
	auto vec{ vector<int>({1,0,2}) };
	auto soln{ Solution().isIdealPermutation(vec) };
	auto eb{ EasyBench() };
	assert(((void)[&]() { cout << "It is " << soln << endl; }(), soln == true));
	eb.startTimer();

	vec = { 1,2,0 };
	soln = Solution().isIdealPermutation(vec);

	assert(((void)[&]() { cout << "It is " << soln << endl; }(), soln == false));

	vec = { 0,2,1 };
	soln = Solution().isIdealPermutation(vec);

	assert(((void)[&]() { cout << "It is " << soln << endl; }(), soln == true));

	vec = { 2,0,1 };
	soln = Solution().isIdealPermutation(vec);

	assert(((void)[&]() { cout << "It is " << soln << endl; }(), soln == false));

	vec = { 1,0,3,2 };
	soln = Solution().isIdealPermutation(vec);

	assert(((void)[&]() { cout << "It is " << soln << endl; }(), soln == true));

	vec = { 0,3,1,2 };
	soln = Solution().isIdealPermutation(vec);

	assert(((void)[&]() { cout << "It is " << soln << endl; }(), soln == false));
	eb.showresult();

	string inpPath{ R"abx(C:\Users\millify\Documents\GitHub\CompCode\DailyProg\inputs.txt)abx" };
	ifstream input{ inpPath };
	string tempString;
	char tempChar{ ',' };

	vec = {};

	while (getline(input, tempString, tempChar)) {
		vec.push_back(stoi(tempString));
	}
	eb.startTimer();
	soln = Solution().isIdealPermutation(vec);
	eb.showresult();
	return 0;

*/
/*
	auto vec{ vector<int>() };
	auto solnClass{ Solution() };
	auto eb{ EasyBench() };

	string inpPath{ R"abx(C:\Users\millify\Documents\GitHub\CompCode\DailyProg\inputs.txt)abx" };
	ifstream input{ inpPath };
	string tempString;
	char tempChar{ ',' };

	while (getline(input, tempString, tempChar)) {
		vec.push_back(stoi(tempString));
	}
	eb.startTimer();
	auto soln = Solution().inversions(vec);
	eb.showresult();
	cout << soln;
	return 0;

*/
// main() {
	//	vector<int> arr{ 1,3,8,2,9,2,5,6 };
		//	auto easyBench{ EasyBench() };
		//
		//	auto alg{ 0 };
		//	while (true) {
		//		switch (alg) {
		//		case 0: func1(easyBench, arr);
		//			break;
		//		case 1: func2(easyBench, arr);
		//			break;
		//		default: goto elx;
		//
		//		}
		//
		//		alg++;
		//	}
		//elx:

			//vector input{ { -1,-100,3,99 } };
			//auto k{ 5 };
			//Solution().rotate(input,k);

			/*auto vec{ vector<int>({0,1,2,2,1,0,0,2}) };
			auto vecHard{ vector<int>({0,1,2,2,1,0,0,2}) };
			auto vecDF{ vector<int>({0,1,2,2,1,0,0,2}) };

			auto eb{ EasyBench() };
			auto soln{ Solution() };

			eb.startTimer();
			soln.sortColors(vec);
			eb.showresult();
			cout << "\n"<<"Done 1"<<"\n";

			eb.startTimer();
			soln.sortColorsHard(vecHard);
			eb.showresult();
			cout << "\n";

			eb.startTimer();
			soln.sortColorsDutchNationalFlagAlg(vecDF);
			eb.showresult();
			cout << "\n";

			for (auto& x : vecDF)
			{
				cout << x << " ";
			}
			cout << "\n";
			return 0;*/

			//auto vec{ vector<int>({7,2,6,1,3 }) };

			//cout << Solution().maxProfit(vec);

		//auto vec{ vector<vector<int>>({vector<int>({1,2,3}), vector<int>({4,5,6}), vector<int>({7,8,9})}) };
		//auto eb{ EasyBench() };
		//auto soln{ Solution() };
		//eb.startTimer();
		//soln.rotate(vec);
		//eb.showresult();
		//cout << "\n";

		//auto vec2{ vector<vector<int>>({vector<int>({1,2,3}), vector<int>({4,5,6}), vector<int>({7,8,9})}) };

		//eb.startTimer();
		//soln.rotate2(vec2);
		//eb.showresult();
		//cout << "\n";

		//for (auto& x : vec2)
		//{
		//	for (auto& y : x) {
		//		cout << y << " ";
		//	}
		//	cout << "\n";

		//}

		//string inp{ "  a good   example  " };
		//auto pp = Solution().reverseWords(inp);
		//cout << pp;
/*
	auto vec{ vector<vector<int>>({vector<int>({1,4}),vector<int>({2,6}),vector<int>({3,7}),vector<int>({8,10}),vector<int>({15,18})}) };
	auto vecSoln{ vector<vector<int>>({vector<int>({1,7}),vector<int>({8,10}),vector<int>({15,18})}) };
	auto soln{ Solution() };
	auto solnVec{ vector < vector<int>>() };
	auto printsoln = [&solnVec]() {
		cout << "\n";
		for (auto& x : solnVec) {
			for (auto& y : x)
			{
				cout << y << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	};
	auto asserts = [&]() {
		solnVec = soln.merge(vec);
		assert(((void)printsoln(), solnVec == vecSoln)); cout << "Done one" << endl; };
	asserts();

	vec = vector<vector<int>>({ vector<int>({1,4}),vector<int>({0,5}) });
	vecSoln = vector<vector<int>>({ vector<int>({0,5}) });
	asserts();

	vec = vector<vector<int>>({ vector<int>({1,4}),vector<int>({0,1}) });
	vecSoln = vector<vector<int>>({ vector<int>({0,4}) });
	asserts();

	vec = vector<vector<int>>({ vector<int>({1,4}),vector<int>({2,3}) });
	vecSoln = vector<vector<int>>({ vector<int>({1,4}) });
	asserts();

	vec = vector<vector<int>>({ vector<int>({1,4}),vector<int>({0,2}) });
	vecSoln = vector<vector<int>>({ vector<int>({0,4}) });
	asserts();

*/

/*
	auto vec1{ vector<int>({1,3,5,7}) };
	auto vec2{ vector<int>({0,2,6}) };
	auto soln{ Solution() };

	soln.merge(vec1, vec1.size(), vec2, vec2.size());
	auto printVec = [](vector<int>& vec) {
		cout << "\n";
		for (auto& x : vec)
		{
			cout << x << " ";
		}
		cout << "\n";
	};

	assert(((void)printVec(vec1), vec1 == vector<int>({0,1,2,3})));
	assert(((void)printVec(vec2), vec2 == vector<int>({5,6,7})));
*/
//}



#pragma endregion
