#pragma once
//https://leetcode.com/problems/powx-n/

#include<algorithm>
#include<bitset>
class Solution {
public:
	/*
	double myPow(double x, int n) {
		if (n == 0)
			return 1.0;

		using namespace std;
		double result{ x };
		auto nInBinary{ bitset<128>(abs(n)).to_string() };
		auto iteratorBegin{ find(nInBinary.begin(), nInBinary.end(),'1') };
		iteratorBegin++;

		while (iteratorBegin < nInBinary.end())
		{
			result *= result;
			bool isFirstOne{ *iteratorBegin == '0' };
			result *= abs((x * isFirstOne) - (x - isFirstOne));

			iteratorBegin++;
		}
		bool isXNegative{ n < 0 };
		return (abs(((result * isXNegative) * (result * isXNegative)) - (2 * (result * isXNegative) * (result - isXNegative)) + ((result - isXNegative) * (result - isXNegative))) * 1 / result);
	}
	*/

	double myPow(double x, int n) {
		if (n == 0)
			return 1.0;

		using namespace std;
		double result{ x };
		auto nInBinary{ bitset<128>(abs(n)).to_string() };
		auto iteratorBegin{ find(nInBinary.begin(), nInBinary.end(),'1') };
		iteratorBegin++;

		while (iteratorBegin < nInBinary.end())
		{
			result *= result;
			if (*iteratorBegin == '1') {
				result *= x;
			}
			iteratorBegin++;
		}

		if (n > 0)
		{
			return result;
		}
		else {
			return 1 / result;
		}
	}

	double myPow2(double x, int n) {
		if (n == std::numeric_limits<int>::lowest()) {
			return myPow2(1 / x, -(n + 1)) / x;
		}
		if (n < 0) {
			return myPow2(1 / x, -n);
		}
		double ans = 1;
		while (n) {
			if (n & 1 == 1) ans *= x;
			x *= x;
			n >>= 1;
		}
		return ans;
	}
};
/*
temp = (z ? x) where z an be 0 or 1, z operation x returns 1 for z=1 and x for z=0.
temp = abs((x*z) - (x-z))

temp =  z ? result where z can be 0 or 1, z operation result returns result for 0 and 1/result for 1.
temp = (abs((result*z) - (result-z) * (result*z) - (result-z))) * 1/result;
m= ((x*z)-(x-z))*((x*z)-(x-z))  = (a-b) * (a-b), a=(x*z), b=(x-z)
m= a*a-2*a*b+b*b
m= (x*z)*(x*z)-2*(x*z)*(x-z)+ (x-z)*(x-z)
*/
