#pragma once
#include <chrono>
#include <string_view>

class EasyBench {
	std::chrono::steady_clock::time_point m_start;
public:
	EasyBench();
	void showresult(std::string_view message="");
	void startTimer();
};
