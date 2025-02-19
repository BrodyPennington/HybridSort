#include "chrono.h"

void Chrono::start() {
    startTime = std::chrono::high_resolution_clock::now();
}

double Chrono::stop() {
    auto endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = endTime - startTime;
    return duration.count();  // Return time in milliseconds
}