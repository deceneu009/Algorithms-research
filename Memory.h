// #pragma once

// #include <iostream>
// #include <memory>

// namespace MemoryTracking
// {
//     class AllocationMetrics
//     {
//     public:
//         uint32_t TotalAllocated = 0;
//         uint32_t TotalFreed = 0;
//         static AllocationMetrics s_AllocationMetrics;

//         uint32_t CurrentUsage()
//         {
//             return TotalAllocated - TotalFreed;
//         }

//         AllocationMetrics()
//         {
//         }

//         ~AllocationMetrics()
//         {
//             std::cout << "Memory usage: " << s_AllocationMetrics.CurrentUsage() << " bytes\n";
//         }
//     };

//     // Define s_AllocationMetrics outside the class
//     AllocationMetrics AllocationMetrics::s_AllocationMetrics;

// }

// void *operator new(size_t size)
// {
//     std::cout << "Allocating " << size << " bytes\n";
//     MemoryTracking::AllocationMetrics::s_AllocationMetrics.TotalAllocated += size;
//     return malloc(size);
// }

// void operator delete(void *memory, size_t size)
// {
//     MemoryTracking::AllocationMetrics::s_AllocationMetrics.TotalFreed += size;
//     std::cout << "Freeing " << s_AllocationMetrics.TotalFreed << "Bytes\n";
//     free(memory);
// }

#pragma once

#include <iostream>
#include <memory>

namespace MemoryTracking
{
    class AllocationMetrics
    {
    public:
        uint32_t TotalAllocated = 0;
        uint32_t TotalFreed = 0;
        static AllocationMetrics s_AllocationMetrics;
        bool firstInstance = false;

        uint32_t CurrentUsage()
        {
            return TotalAllocated - TotalFreed;
        }

        AllocationMetrics()
        {
            // Output memory usage only when the first instance is created
            firstInstance = true;
            if (firstInstance)
            {
                std::cout << "Memory usage: " << CurrentUsage() << " bytes\n";
                firstInstance = false;
            }
        }

        ~AllocationMetrics()
        {
            TotalAllocated = 0;
            TotalFreed = 0;
        }
    };

    // Define s_AllocationMetrics outside the class
    AllocationMetrics AllocationMetrics::s_AllocationMetrics;
}

// Operator new defined outside the namespace
void* operator new(size_t size)
{
    std::cout << "Allocating " << size << " bytes\n";
    MemoryTracking::AllocationMetrics::s_AllocationMetrics.TotalAllocated += size;
    return malloc(size);
}

// Operator delete defined outside the namespace
void operator delete(void* memory, size_t size) //noexcept
{
    MemoryTracking::AllocationMetrics::s_AllocationMetrics.TotalFreed += sizeof(memory);
    std::cout << "Freeing " << MemoryTracking::AllocationMetrics::s_AllocationMetrics.TotalFreed << "Bytes\n";
    free(memory);
}