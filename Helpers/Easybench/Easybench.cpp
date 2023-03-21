#include "EasyBench.h"
#include <iostream>
EasyBench::EasyBench() : m_start{ std::chrono::steady_clock::now() } {}

void EasyBench::startTimer() {
	m_start = std::chrono::steady_clock::now();
}
void EasyBench::showresult(std::string_view message) {
	auto end = std::chrono::steady_clock::now();
	auto difference = end - m_start;
	std::cout << "Time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(difference).count() << " ns ";
	std::cout << "|" << std::chrono::duration_cast<std::chrono::microseconds>(difference).count() << " micros ";
	std::cout << "|" << std::chrono::duration_cast<std::chrono::milliseconds>(difference).count() << " millis" << "\n";

	std::cout << message << std::endl;
}