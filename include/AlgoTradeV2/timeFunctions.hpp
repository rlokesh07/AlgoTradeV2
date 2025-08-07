#pragma once
#include <ctime>
#include <chrono>

inline std::chrono::time_point<std::chrono::system_clock> currentTime() {
    auto now = std::chrono::system_clock::now();

    return now;

}
