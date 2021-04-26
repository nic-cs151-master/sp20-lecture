#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <chrono>
typedef std::chrono::high_resolution_clock Clock;

class StopWatch
{
public:
    StopWatch()
    {
        time = Clock::now();
    }

    int64_t restartClock()
    {
        std::chrono::_V2::system_clock::time_point prevTime = time;
        time = Clock::now();
        return std::chrono::duration_cast<std::chrono::microseconds>(time - prevTime).count();
    }
private:
    std::chrono::_V2::system_clock::time_point time;
};

#endif