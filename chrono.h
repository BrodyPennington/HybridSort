#include <chrono>

class Chrono {
public:
    // Starts the timer
    void start();

    // Stops the timer and returns the elapsed time in milliseconds
    double stop();

private:
    std::chrono::high_resolution_clock::time_point startTime;
};