#include "arrGen.h"
#include <random>

std::vector<int> generateRandomArray(int size, int rangeMin, int rangeMax)
{
    // Make the random engine static to avoid re-seeding on every call
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(rangeMin, rangeMax);

    std::vector<int> arr(size);
    for (int i = 0; i < size; ++i)
    {
        arr[i] = dist(gen);
    }

    return arr;
}