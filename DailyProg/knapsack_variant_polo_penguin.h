#pragma once
//https://www.codechef.com/problems/PPTEST/
#include<vector>
#include <numeric>
#include<iostream>
using namespace std;
int maxPoints(vector<vector<int>>& questions, int& minutes, int& n) {
	auto maxMinutes{ 0 };
	for (auto& elem : questions) {
		maxMinutes += elem.at(2);
	}
	auto tempValue{ 0 };
	auto tempMinute{ 0 };
	auto valueArray{ vector<int>(maxMinutes + 1,-1) };
	valueArray.at(0) = 0;
	for (int i{ 0 }; i < n; ++i) {
		tempValue = (questions.at(i).at(0) * (questions.at(i).at(1)));
		tempMinute = (questions.at(i).at(2));
		for (int j{ maxMinutes - tempMinute }; j >= 0; --j) {
			valueArray.at(j + tempMinute) = max(valueArray.at(j) + tempValue, tempValue);
		}
	}

	return valueArray.at(minutes);
}

int smain() {
	//freopen_s("../../input.txt", "r", stdin);

	//freopen("../output.txt", "w", stdout);
	auto testCases{ 0 };
	char arr[6];
	auto vec{ vector<vector<int>>() };
	auto minutes{ 0 };
	auto n{ 0 };
	cin >> testCases;
	cin.ignore(cin.rdbuf()->in_avail());

	for (auto i{ 0 }; i < testCases; ++i) {
		cin.getline(arr, 4);
		n = static_cast<int>(arr[0]) - 48;
		minutes = static_cast<int>(arr[2]) - 48;

		for (auto j{ 0 }; j < n; ++j) {
			cin.getline(arr, 6);
			vec.push_back(vector<int>({ static_cast<int>(arr[0]) - 48 ,static_cast<int>(arr[2]) - 48 ,static_cast<int>(arr[4]) - 48 }));
		}

		cout << maxPoints(vec, minutes, n);
		cout << "\n";
	}

	return 0;
}