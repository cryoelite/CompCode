#pragma once
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_set>
using namespace std;
class Solution {
public:

	int goodString(int N, int Q, string S, vector<int> arr, vector<vector<int>> ranges) {
		auto result{ 0 };
		goodStringSolver(result, N, Q, S, arr, ranges);
		return result;
	}
private:

	void goodStringSolver(int& result, int& N, int& Q, string S, vector<int> arr, vector<vector<int>>& ranges) {
		if (checkRanges(ranges, S)) {
			return;
		}
		S.at(*arr.begin() - 1) = '_';
		++result;
		goodStringSolver(result, N, Q, S, vector<int>(arr.begin() + 1, arr.end()), ranges);
	}


	bool checkRanges(vector<vector<int>>& ranges, string& s) {
		bool result{
			all_of(ranges.begin(),ranges.end(), [&s](vector<int> elem) {
				auto tempString{string(s.begin() + elem.at(0) - 1, s.begin() + elem.at(1))};
				auto setString{unordered_set<char>()};
				for (auto& character : tempString) {

					if (character != '_' && setString.find(character) != setString.end())
					{
						return false;
					}
					else {
						setString.insert(character);
					}
				}
				return true;
				})
		};

		return result;

	}

};