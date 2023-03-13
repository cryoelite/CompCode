#pragma once

#include<iostream>
#include<sstream>

using namespace std;
class Solution {
public:

	int getInput() {
		int inp{};
		cin >> inp;
		cin.ignore(cin.rdbuf()->in_avail());
		return inp;
	}

	void solve(long long num, stringstream& outp) {
		if (num == 1) {
			outp << 1;

			cout << outp.str() << endl;
			return;
		}
		else {
			outp << num << " ";
			if (num % 2 == 0)
				num /= 2;
			else
				num = (num * 3) + 1;

			solve(num, outp);
		}
	}
};
