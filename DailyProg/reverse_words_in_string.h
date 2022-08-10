#pragma once
//https://leetcode.com/problems/reverse-words-in-a-string/

#include<string>
#include<sstream>
#include<vector>

using namespace std;
class Solution {
public:
	string reverseWords(string s) {
		auto ss{ stringstream(s) };
		auto item{ string() };
		char delim{ ' ' };
		auto strings{ vector<string>() };
		while (getline(ss, item, delim)) {
			if (item != "")
				strings.push_back(item);
		}
		s.clear();

		for (int index{ (int)strings.size() - 1 }; index >= 0; --index) {
			s += strings.at(index);
			if (index != 0)
				s += " ";
		}

		return s;
	}
};