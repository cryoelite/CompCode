#pragma once
//https://takeuforward.org/data-structure/grid-unique-paths-count-paths-from-left-top-to-the-right-bottom-of-a-matrix/

#include<vector>
using namespace std;
class Solution {
public:
	using vm = vector<vector<int>>;

	int uniquePaths(int m, int n) {
		//return traverseRecursively(--m, --n, 0, 0);

		//creating an initialized matrix
		auto vecMatrix{ vm(m, vector<int>(n,-1)) };


		return traverseDP(--m, --n, 0, 0, vecMatrix);

	}

	int uniquePaths2(int m, int n) {
		return traverseRecursively(--m, --n, 0, 0);

		//auto vecMatrix{ vm(m) };
		//for (auto i{ 0 }; i < m; ++i) {
		//	vecMatrix.at(i).assign(n, -1);
		//}
		//return traverseDP(--m, --n, 0, 0, vecMatrix);

	}


private:
	//recursive exponential time solution
	int traverseRecursively(int& m, int& n, int cm, int cn) {
		if (cm > m || cn > n)
		{
			return 0;
		}
		else if (cm == m && cn == n) {
			return 1;
		}

		auto res1 = traverseRecursively(m, n, cm + 1, cn);
		auto res2 = traverseRecursively(m, n, cm, cn + 1);
		return res1 + res2;
	}

	//DP + recursive n*m time solution
	int traverseDP(int& m, int& n, int cm, int cn, vm& vecMatrix) {
		if (cm > m || cn > n)
		{
			return 0;
		}
		else if (cm == m && cn == n) {
			return 1;
		}
		if (vecMatrix.at(cm).at(cn) != -1)
		{
			return vecMatrix.at(cm).at(cn);
		}
		else {

			int res1{ traverseDP(m, n, cm + 1, cn, vecMatrix) };
			int res2{ traverseDP(m, n, cm, cn + 1, vecMatrix) };

			vecMatrix.at(cm).at(cn) = res1+res2;
			return res1 + res2;

		}
	}
};