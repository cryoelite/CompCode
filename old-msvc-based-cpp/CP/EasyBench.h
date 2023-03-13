#pragma once
#include <chrono>
#include <string_view>
using namespace std;
class EasyBench {
	std::chrono::steady_clock::time_point m_start;
public:

	EasyBench();
	void showresult(string_view message = "");
	void startTimer();
};
