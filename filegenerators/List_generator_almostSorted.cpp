#include <iostream>
#include <fstream>
#include <cstring>
#include <cerrno>

void swap(long int &xp, long int &yp)
{
    int temp = xp;
    xp = yp;
    yp = temp;
}

int main()
{
    long int size, *arr;

    std::ofstream Size1Almost("sizefiles/almostSorted/size1Almost.txt");
    if (Size1Almost.is_open())
    {
        long int j = 0, thirds;
        size = 10;
        thirds = size / 3;
        arr = new long int[size];
        if (arr != nullptr)
        { // Check if memory allocation was successful
            for (long int i = 0; i < size; i++)
            {
                arr[i] = i;
            }
            for (long int i = size - 1; i >= 0; i--)
            {
                j++;
                if (j == thirds)
                {
                    swap(arr[i], arr[i + 1]);
                    j = 0;
                }
            }
            for (long int i = 0; i < size; i++)
            {
                Size1Almost << arr[i] << " ";
            }
            delete[] arr;
        }
        else
        {
            std::cerr << "Failed to allocate memory for the array! " << std::strerror(errno) << std::endl;
            return 1; // Return an error code
        }
        Size1Almost.close();
    }
    else
    {
        std::cerr << "Failed to open file size1Almost.txt! " << std::strerror(errno) << std::endl;
        return 1;
    }

    std::ofstream Size2Almost("sizefiles/almostSorted/size2Almost.txt");
    if (Size2Almost.is_open())
    {
        long int j = 0, quarters;
        size = 100;
        quarters = size / 4;
        arr = new long int[size];
        if (arr != nullptr)
        { // Check if memory allocation was successful
            for (long int i = 0; i < size; i++)
            {
                arr[i] = i;
            }
            for (long int i = size - 1; i >= 0; i--)
            {
                j++;
                if (j == quarters)
                {
                    swap(arr[i], arr[i + 1]);
                    j = 0;
                }
            }
            for (long int i = 0; i < size; i++)
            {
                Size2Almost << arr[i] << " ";
            }
            delete[] arr;
        }
        else
        {
            std::cerr << "Failed to allocate memory for the array! " << std::strerror(errno) << std::endl;
            return 1; // Return an error code
        }
        Size2Almost.close();
    }
    else
    {
        std::cerr << "Failed to open file size2Almost.txt! " << std::strerror(errno) << std::endl;
        return 1;
    }

    std::ofstream Size3Almost("sizefiles/almostSorted/size3Almost.txt");
    if (Size3Almost.is_open())
    {
        long int j = 0, quarters;
        size = 1000;
        quarters = size / 4;
        arr = new long int[size];
        if (arr != nullptr)
        { // Check if memory allocation was successful
            for (long int i = 0; i < size; i++)
            {
                arr[i] = i;
            }
            for (long int i = size - 1; i >= 0; i--)
            {
                j++;
                if (j == quarters)
                {
                    swap(arr[i], arr[i + 1]);
                    j = 0;
                }
            }
            for (long int i = 0; i < size; i++)
            {
                Size3Almost << arr[i] << " ";
            }
            delete[] arr;
        }
        else
        {
            std::cerr << "Failed to allocate memory for the array! " << std::strerror(errno) << std::endl;
            return 1; // Return an error code
        }
        Size3Almost.close();
    }
    else
    {
        std::cerr << "Failed to open file size3Almost.txt! " << std::strerror(errno) << std::endl;
        return 1;
    }

    std::ofstream Size4Almost("sizefiles/almostSorted/size4Almost.txt");
    if (Size4Almost.is_open())
    {
        long int j = 0, quarters;
        size = 10000;
        quarters = size / 4;
        arr = new long int[size];
        if (arr != nullptr)
        { // Check if memory allocation was successful
            for (long int i = 0; i < size; i++)
            {
                arr[i] = i;
            }
            for (long int i = size - 1; i >= 0; i--)
            {
                j++;
                if (j == quarters)
                {
                    swap(arr[i], arr[i + 1]);
                    j = 0;
                }
            }
            for (long int i = 0; i < size; i++)
            {
                Size4Almost << arr[i] << " ";
            }
            delete[] arr;
        }
        else
        {
            std::cerr << "Failed to allocate memory for the array! " << std::strerror(errno) << std::endl;
            return 1; // Return an error code
        }
        Size4Almost.close();
    }
    else
    {
        std::cerr << "Failed to open file size4Almost.txt! " << std::strerror(errno) << std::endl;
        return 1;
    }

    std::ofstream Size5Almost("sizefiles/almostSorted/size5Almost.txt");
    if (Size5Almost.is_open())
    {
        long int j = 0, quarters;
        size = 100000;
        quarters = size / 4;
        arr = new long int[size];
        if (arr != nullptr)
        { // Check if memory allocation was successful
            for (long int i = 0; i < size; i++)
            {
                arr[i] = i;
            }
            for (long int i = size - 1; i >= 0; i--)
            {
                j++;
                if (j == quarters)
                {
                    swap(arr[i], arr[i + 1]);
                    j = 0;
                }
            }
            for (long int i = 0; i < size; i++)
            {
                Size5Almost << arr[i] << " ";
            }
            delete[] arr;
        }
        else
        {
            std::cerr << "Failed to allocate memory for the array! " << std::strerror(errno) << std::endl;
            return 1; // Return an error code
        }
        Size5Almost.close();
    }
    else
    {
        std::cerr << "Failed to open file size5Almost.txt! " << std::strerror(errno) << std::endl;
        return 1;
    }

    std::ofstream Size6Almost("sizefiles/almostSorted/size6Almost.txt");
    if (Size6Almost.is_open())
    {
        long int j = 0, quarters;
        size = 1000000;
        quarters = size / 4;
        arr = new long int[size];
        if (arr != nullptr)
        { // Check if memory allocation was successful
            for (long int i = 0; i < size; i++)
            {
                arr[i] = i;
            }
            for (long int i = size - 1; i >= 0; i--)
            {
                j++;
                if (j == quarters)
                {
                    swap(arr[i], arr[i + 1]);
                    j = 0;
                }
            }
            for (long int i = 0; i < size; i++)
            {
                Size6Almost << arr[i] << " ";
            }
            delete[] arr;
        }
        else
        {
            std::cerr << "Failed to allocate memory for the array! " << std::strerror(errno) << std::endl;
            return 1; // Return an error code
        }
        Size6Almost.close();
    }
    else
    {
        std::cerr << "Failed to open file size6Almost.txt! " << std::strerror(errno) << std::endl;
        return 1;
    }

    std::ofstream Size7Almost("sizefiles/almostSorted/size7Almost.txt");
    if (Size7Almost.is_open())
    {
        long int j = 0, quarters;
        size = 10000000;
        quarters = size / 4;
        arr = new long int[size];
        if (arr != nullptr)
        { // Check if memory allocation was successful
            for (long int i = 0; i < size; i++)
            {
                arr[i] = i;
            }
            for (long int i = size - 1; i >= 0; i--)
            {
                j++;
                if (j == quarters)
                {
                    swap(arr[i], arr[i + 1]);
                    j = 0;
                }
            }
            for (long int i = 0; i < size; i++)
            {
                Size7Almost << arr[i] << " ";
            }
            delete[] arr;
        }
        else
        {
            std::cerr << "Failed to allocate memory for the array! " << std::strerror(errno) << std::endl;
            return 1; // Return an error code
        }
        Size7Almost.close();
    }
    else
    {
        std::cerr << "Failed to open file size7Almost.txt! " << std::strerror(errno) << std::endl;
        return 1;
    }

    std::ofstream Size8Almost("sizefiles/almostSorted/size8Almost.txt");
    if (Size8Almost.is_open())
    {
        long int j = 0, quarters;
        size = 100000000;
        quarters = size / 4;
        arr = new long int[size];
        if (arr != nullptr)
        { // Check if memory allocation was successful
            for (long int i = 0; i < size; i++)
            {
                arr[i] = i;
            }
            for (long int i = size - 1; i >= 0; i--)
            {
                j++;
                if (j == quarters)
                {
                    swap(arr[i], arr[i + 1]);
                    j = 0;
                }
            }
            for (long int i = 0; i < size; i++)
            {
                Size8Almost << arr[i] << " ";
            }
            delete[] arr;
        }
        else
        {
            std::cerr << "Failed to allocate memory for the array! " << std::strerror(errno) << std::endl;
            return 1; // Return an error code
        }
        Size8Almost.close();
    }
    else
    {
        std::cerr << "Failed to open file size8Almost.txt! " << std::strerror(errno) << std::endl;
        return 1;
    }

    std::ofstream Size9Almost("sizefiles/almostSorted/size9Almost.txt");
    if (Size9Almost.is_open())
    {
        long int j = 0, quarters;
        size = 1000000000;
        quarters = size / 4;
        arr = new long int[size];
        if (arr != nullptr)
        { // Check if memory allocation was successful
            for (long int i = 0; i < size; i++)
            {
                arr[i] = i;
            }
            for (long int i = size - 1; i >= 0; i--)
            {
                j++;
                if (j == quarters)
                {
                    swap(arr[i], arr[i + 1]);
                    j = 0;
                }
            }
            for (long int i = 0; i < size; i++)
            {
                Size9Almost << arr[i] << " ";
            }
            delete[] arr;
        }
        else
        {
            std::cerr << "Failed to allocate memory for the array! " << std::strerror(errno) << std::endl;
            return 1; // Return an error code
        }
        Size9Almost.close();
    }
    else
    {
        std::cerr << "Failed to open file size9Almost.txt! " << std::strerror(errno) << std::endl;
        return 1;
    }
}