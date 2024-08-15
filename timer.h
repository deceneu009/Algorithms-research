#pragma once

#include <fstream>
#include <chrono>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;
int it = -1;
double duration, milliseconds, seconds, hours, microseconds;
//except on 'almost sorted' where the order is "Quicksort, Merge sort, Insertion sort, Bubble sort, Selection sort"
const char *algo[5] = {"Quicksort", "Merge sort", "Selection sort", "Insertion sort", "Bubble sort"};

class Timer
{
private:
    std::ofstream results;
    fs::path fileLocation;
    std::chrono::time_point<std::chrono::high_resolution_clock> StartPoint;

public:
    Timer(std::string FileName)
    {
        #if defined(__linux__)
            fileLocation = "results/ResultsCSV/" + FileName;
        #elif defined(__WIN32) || defined(__WIN64)
            fileLocation = R"(results\ResultsCSV\)" + FileName;
        #endif
        
        results.open(fileLocation, std::ios_base::app);
        if (it == -1)
        {
            resize_file(fileLocation, 0);
            results.seekp(0);
            results << "Algorithm,nanoseconds,microseconds,milliseconds,seconds,hours\n";
        }
        it++;
        StartPoint = std::chrono::high_resolution_clock::now();
    }

    ~Timer()
    {
        stop();
        results << algo[it] << "," << duration << "," << microseconds << "," << milliseconds << "," << seconds << "," << hours << "\n";
        results.close();
    }

    void stop()
    {
        auto EndPoint = std::chrono::high_resolution_clock::now();

        auto start = std::chrono::time_point_cast<std::chrono::nanoseconds>(StartPoint).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::nanoseconds>(EndPoint).time_since_epoch().count();

        duration = end - start;

        microseconds = duration * 0.001;
        milliseconds = microseconds * 0.001;
        seconds = milliseconds * 0.001;
        hours = seconds * 0.0002777778;

        std::cout << "Duration: " << duration << " nanoseconds(" << microseconds << " microseconds, " << milliseconds << " milliseconds, " << seconds << " seconds, " << hours << " hours)\n";
    }
};
