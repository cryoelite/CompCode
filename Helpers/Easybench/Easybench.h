#ifndef EASYBENCH
#define EASYBENCH
// Header Guard

#include <chrono>
class EasyBench
{
    std::chrono::steady_clock::time_point m_start;

public:
    EasyBench();
    void showresult(std::string_view message = "");
    void startTimer();
};

#endif