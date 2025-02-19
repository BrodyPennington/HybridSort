#include "SortFunctions.h"
#include "arrGen.h"
#include "chrono.h"
#include <iostream>
#include <fstream>




int main() {
    Chrono timer; // measures time

    std::vector<int> sizes;
    std::vector<double> selectionTimes;
    std::vector<double> mergeTimes;


    bool foundCrossover = false;
    int crossoverSize = -1; 

    std::ofstream outFile("results.csv");
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open results.csv for writing.\n";
        return 1;
    }

    outFile << "ArraySize,SelectionSort,MergeSort\n";

    std::cout << "Array size, selectionSort (ms), mergeSort (ms)" << std::endl;

    for (int size = 10; size <= 150000; size += 10) {
        
        // generate an array
        std::vector<int> baseArray = generateRandomArray(size, 1, 200);

        // make a copy for selection sort
        std::vector<int> arrSelectSort = baseArray;
        // make a copy for merge sort
        std::vector<int> arrMergeSort = baseArray;


        timer.start();

        if (size < 285) {
            selectionSort(arrSelectSort);
        } else {
            mergeSort(arrMergeSort, 0, arrMergeSort.size() - 1);
        }


        double sortTime = timer.stop();


        outFile << size << "," << sortTime << std::endl;


        std::cout << size << ", " << sortTime << std::endl;


    }

    outFile.close();

    
}


