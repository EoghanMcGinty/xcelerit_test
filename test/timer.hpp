#include <iostream>
#include <chrono>

class Timer
{
public:
    Timer() {
        startTime = std::chrono::high_resolution_clock::now();
    }

    long int stop() {
        auto endTime = std::chrono::high_resolution_clock::now();

        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(startTime).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTime).time_since_epoch().count();

        auto duration = end - start;
        return duration;
    }
    
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
};