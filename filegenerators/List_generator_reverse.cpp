#include <iostream>
#include <fstream>
#include <cerrno>
#include <cstring>

int main()
{
    long int size, *arr;

    std::ofstream Size1rev("sizefiles/reverse/size1rev.txt");
    if (Size1rev.is_open())
    {
        size = 10;
        arr = new long int[size];
        if (arr != nullptr)
        { // Check if memory allocation was successful
            for (long int i = size-1; i >=0; i--)
            {
                arr[i] = i+1;
                Size1rev << arr[i] << " ";
            }
            delete[] arr;
        }
        else
        {
            std::cerr << "Failed to allocate memory for the array!" << std::strerror(errno) << std::endl;
            return 1; // Return an error code
        }
        Size1rev.close();
    }
    else
    {
        std::cerr << "Failed to open file size1rev.txt!" << std::strerror(errno) << std::endl;
        return 1; // Return an error code
    }

    std::ofstream Size2rev("sizefiles/reverse/size2rev.txt");
    if (Size2rev.is_open())
    {
        size = 100;
        arr = new long int[size];
        if (arr != nullptr)
        { // Check if memory allocation was successful
            for (long int i = size-1; i >= 0; i--)
            {
                arr[i] = i+1;
                Size2rev << arr[i] << " ";
            }
            delete[] arr;
        }
        else
        {
            std::cerr << "Failed to allocate memory for the array!" << std::strerror(errno) << std::endl;
            return 1; // Return an error code
        }
        Size2rev.close();
    }
    else
    {
        std::cerr << "Failed to open file size2rev.txt!" << std::strerror(errno) << std::endl;
        return 1; // Return an error code
    }

    std::ofstream Size3rev("sizefiles/reverse/size3rev.txt");
    if (Size3rev.is_open())
    {
        size = 1000;
        arr = new long int[size];
        if (arr != nullptr)
        { // Check if memory allocation was successful
            for (long int i = size-1; i >= 0; i--)
            {
                arr[i] = i+1;
                Size3rev << arr[i] << " ";
            }
            delete[] arr;
        }
        else
        {
            std::cerr << "Failed to allocate memory for the array!" << std::strerror(errno) << std::endl;
            return 1; // Return an error code
        }
        Size3rev.close();
    }
    else
    {
        std::cerr << "Failed to open file size3rev.txt!" << std::strerror(errno) << std::endl;
        return 1; // Return an error code
    }

    std::ofstream Size4rev("sizefiles/reverse/size4rev.txt");
    if (Size4rev.is_open())
    {
        size = 10000;
        arr = new long int[size];
        if (arr != nullptr)
        { // Check if memory allocation was successful
            for (long int i = size-1; i >= 0; i--)
            {
                arr[i] = i+1;
                Size4rev << arr[i] << " ";
            }
            delete[] arr;
        }
        else
        {
            std::cerr << "Failed to allocate memory for the array!" << std::strerror(errno) << std::endl;
            return 1; // Return an error code
        }
        Size4rev.close();
    }
    else
    {
        std::cerr << "Failed to open file size4rev.txt!" << std::strerror(errno) << std::endl;
        return 1; // Return an error code
    }

    std::ofstream Size5rev("sizefiles/reverse/size5rev.txt");
    if (Size5rev.is_open())
    {
        size = 100000;
        arr = new long int[size];
        if (arr != nullptr)
        { // Check if memory allocation was successful
            for (long int i = size-1; i >= 0; i--)
            {
                arr[i] = i+1;
                Size5rev << arr[i] << " ";
            }
            delete[] arr;
        }
        else
        {
            std::cerr << "Failed to allocate memory for the array!" << std::strerror(errno) << std::endl;
            return 1; // Return an error code
        }
        Size5rev.close();
    }
    else
    {
        std::cerr << "Failed to open file size5rev.txt!" << std::strerror(errno) << std::endl;
        return 1; // Return an error code
    }

    std::ofstream Size6rev("sizefiles/reverse/size6rev.txt");
    if (Size6rev.is_open())
    {
        size = 1000000;
        arr = new long int[size];
        if (arr != nullptr)
        { // Check if memory allocation was successful
            for (long int i = size-1; i >= 0; i--)
            {
                arr[i] = i+1;
                Size6rev << arr[i] << " ";
            }
            delete[] arr;
        }
        else
        {
            std::cerr << "Failed to allocate memory for the array!" << std::strerror(errno) << std::endl;
            return 1; // Return an error code
        }
        Size6rev.close();
    }
    else
    {
        std::cerr << "Failed to open file size6rev.txt!" << std::strerror(errno) << std::endl;
        return 1; // Return an error code
    }

    std::ofstream Size7rev("sizefiles/reverse/size7rev.txt");
    if (Size7rev.is_open())
    {
        size = 10000000;
        arr = new long int[size]; // Dynamically allocate memory

        if (arr != nullptr)
        { // Check if memory allocation was successful
            for (long int i = size-1; i >= 0; i--)
            {
                arr[i] = i+1;
                Size7rev << arr[i] << " ";
            }
            delete[] arr; // Free dynamically allocated memory
        }
        else
        {
            std::cerr << "Failed to allocate memory for the array!" << std::strerror(errno) << std::endl;
            return 1; // Return an error code
        }
        Size7rev.close();
    }
    else
    {
        std::cerr << "Failed to open file size7.txt!" << std::strerror(errno) << std::endl;
        return 1; // Return an error code
    }

    std::ofstream Size8rev("sizefiles/reverse/size8rev.txt");
    if (Size8rev.is_open())
    {
        size = 100000000;
        arr = new long int[size]; // Dynamically allocate memory

        if (arr != nullptr)
        { // Check if memory allocation was successful
            for (long int i = size-1; i >= 0; i--)
            {
                arr[i] = i+1;
                Size8rev << arr[i] << " ";
            }
            delete[] arr; // Free dynamically allocated memory
        }
        else
        {
            std::cerr << "Failed to allocate memory for the array!" << std::strerror(errno) << std::endl;
            return 1; // Return an error code
        }
        Size8rev.close();
    }
    else
    {
        std::cerr << "Failed to open file size8rev.txt!" << std::strerror(errno) << std::endl;
        return 1; // Return an error code
    }

    std::ofstream Size9rev("sizefiles/reverse/size9rev.txt");
    if (Size9rev.is_open())
    {
        size = 1000000000;
        arr = new long int[size]; // Dynamically allocate memory

        if (arr != nullptr)
        { // Check if memory allocation was successful
            for (long int i = size-1; i >= 0; i--)
            {
                arr[i] = i+1;
                Size9rev << arr[i] << " ";
            }
            delete[] arr; // Free dynamically allocated memory
        }
        else
        {
            std::cerr << "Failed to allocate memory for the array!" << std::strerror(errno) << std::endl;
            return 1; // Return an error code
        }
        Size9rev.close();
    }
    else
    {
        std::cerr << "Failed to open file size9rev.txt!" << std::strerror(errno) << std::endl;
        return 1; // Return an error code
    }
}