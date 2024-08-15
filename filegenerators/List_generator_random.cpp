#include <iostream>
#include <fstream>
#include <cstring>
#include <cerrno>
//#include "memory.h"

int main()
{
    long int size, *arr;
    //AllocationMetrics aloc;
    std::ofstream Size1("sizefiles/random/size1random.txt");
    if (Size1.is_open())
    {
        size = 10;
        arr = new long int[size];
        if (arr != nullptr)
        { // Check if memory allocation was successful
            for (long int i = 0; i < size; i++)
            {
                arr[i] = rand() % size;
                Size1 << arr[i] << " ";
            }
            delete[] arr;
        }
        else
        {
            std::cerr << "Failed to allocate memory for the array! " << std::strerror(errno) << std::endl;
            return 1; // Return an error code
        }
        Size1.close();
    }
    else
    {
        std::cerr << "Failed to open file size1random.txt! " << std::strerror(errno) << std::endl;
        return 1;
    }

    std::ofstream Size2("sizefiles/random/size2random.txt");
    if (Size2.is_open())
    {
        size = 100;
        arr = new long int[size];
        if (arr != nullptr)
        { // Check if memory allocation was successful
            for (long int i = 0; i < size; i++)
            {
                arr[i] = rand() % size;
                Size2 << arr[i] << " ";
            }
            delete[] arr;
        }
        else
        {
            std::cerr << "Failed to allocate memory for the array! " << std::strerror(errno) << std::endl;
            return 1; // Return an error code
        }
        Size2.close();
    }
    else
    {
        std::cerr << "Failed to open file size2random.txt! " << std::strerror(errno) << std::endl;
        return 1;
    }

    std::ofstream Size3("sizefiles/random/size3random.txt");
    if (Size3.is_open())
    {
        size = 1000;
        arr = new long int[size];
        if (arr != nullptr)
        { // Check if memory allocation was successful
            for (long int i = 0; i < size; i++)
            {
                arr[i] = rand() % size;
                Size3 << arr[i] << " ";
            }
            delete[] arr;
        }
        else
        {
            std::cerr << "Failed to allocate memory for the array! " << std::strerror(errno) << std::endl;
            return 1; // Return an error code
        }
        Size3.close();
    }
    else
    {
        std::cerr << "Failed to open file size3random.txt! " << std::strerror(errno) << std::endl;
        return 1;
    }

    std::ofstream Size4("sizefiles/random/size4random.txt");
    if (Size4.is_open())
    {
        size = 10000;
        arr = new long int[size];
        if (arr != nullptr)
        { // Check if memory allocation was successful
            for (long int i = 0; i < size; i++)
            {
                arr[i] = rand() % size;
                Size4 << arr[i] << " ";
            }
            delete[] arr;
        }
        else
        {
            std::cerr << "Failed to allocate memory for the array! " << std::strerror(errno) << std::endl;
            return 1; // Return an error code
        }

        Size4.close();
    }
    else
    {
        std::cerr << "Failed to open file size4random.txt! " << std::strerror(errno) << std::endl;
        return 1;
    }

    std::ofstream Size5("sizefiles/random/size5random.txt");
    if (Size5.is_open())
    {
        size = 100000;
        arr = new long int[size];
        if (arr != nullptr)
        { // Check if memory allocation was successful
            for (long int i = 0; i < size; i++)
            {
                arr[i] = rand() % size;
                Size5 << arr[i] << " ";
            }
            delete[] arr;
        }
        else
        {
            std::cerr << "Failed to allocate memory for the array! " << std::strerror(errno) << std::endl;
            return 1; // Return an error code
        }
        Size5.close();
    }
    else
    {
        std::cerr << "Failed to open file size5random.txt! " << std::strerror(errno) << std::endl;
        return 1;
    }

    std::ofstream Size6("sizefiles/random/size6random.txt");
    if (Size6.is_open())
    {
        size = 1000000;
        arr = new long int[size];

        if (arr != nullptr)
        { // Check if memory allocation was successful
            for (long int i = 0; i < size; i++)
            {
                arr[i] = rand() % size;
                Size6 << arr[i] << " ";
            }
            delete[] arr;
        }
        else
        {
            std::cerr << "Failed to allocate memory for the array! " << std::strerror(errno) << std::endl;
            return 1; // Return an error code
        }
        Size6.close();
    }
    else
    {
        std::cerr << "Failed to open file size6random.txt! " << std::strerror(errno) << std::endl;
        return 1;
    }

    std::ofstream Size7("sizefiles/random/size7random.txt");
    if (Size7.is_open())
    {
        size = 10000000;
        arr = new long int[size]; // Dynamically allocate memory

        if (arr != nullptr)
        { // Check if memory allocation was successful
            for (long int i = 0; i < size; i++)
            {
                arr[i] = rand() % size;
                Size7 << arr[i] << " ";
            }
            delete[] arr; // Free dynamically allocated memory
        }
        else
        {
            std::cerr << "Failed to allocate memory for the array! " << std::strerror(errno) << std::endl;
            return 1; // Return an error code
        }
        Size7.close();
    }
    else
    {
        std::cerr << "Failed to open file size7random.txt! " << std::strerror(errno) << std::endl;
        return 1; // Return an error code
    }

    std::ofstream Size8("sizefiles/random/size8random.txt");
    if (Size8.is_open())
    {
        size = 100000000;
        arr = new long int[size]; // Dynamically allocate memory

        if (arr != nullptr)
        { // Check if memory allocation was successful
            for (long int i = 0; i < size; i++)
            {
                arr[i] = rand() % size;
                Size8 << arr[i] << " ";
            }
            delete[] arr; // Free dynamically allocated memory
        }
        else
        {
            std::cerr << "Failed to allocate memory for the array! " << std::strerror(errno) << std::endl;
            return 1; // Return an error code
        }
        Size8.close();
    }
    else
    {
        std::cerr << "Failed to open file size8random.txt! " << std::strerror(errno) << std::endl;
        return 1; // Return an error code
    }

    std::ofstream Size9("sizefiles/random/size9random.txt");
    if (Size9.is_open())
    {
        size = 1000000000;
        arr = new long int[size]; // Dynamically allocate memory

        if (arr != nullptr)
        { // Check if memory allocation was successful
            for (long int i = 0; i < size; i++)
            {
                arr[i] = rand() % size;
                Size9 << arr[i] << " ";
            }
            delete[] arr; // Free dynamically allocated memory
        }
        else
        {
            std::cerr << "Failed to allocate memory for the array! " << std::strerror(errno) << std::endl;
            return 1; // Return an error code
        }
        Size9.close();
    }
    else
    {
        std::cerr << "Failed to open file size9random.txt! " << std::strerror(errno) << std::endl;
        return 1; // Return an error code
    }

    return 0;
}
