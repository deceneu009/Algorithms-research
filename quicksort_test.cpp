#include <iostream>
#include <fstream>
#include <algorithm>    // std::swap

long int MAX_SIZE = 1000000;
std::ifstream inputFile;
long int check=0;

// void swap(long int &xp, long int &yp)
// {
//     long int temp = xp;
//     xp = yp;
//     yp = temp;
// }

// void swap(long int x, long int y)
// {
//     int temp = x;
//     x = y;
//     y = temp;
// }

int partition(long int *arr, long int start, long int end)
{
    long int pivot_val = arr[end];
    long int i = start;
    for (long int j = start; j < end; j++) // Corrected loop condition
    {
        if (arr[j] <= pivot_val)
        {
            std::swap(arr[i], arr[j]);
            i++;
        }
    }
    std::swap(arr[i], arr[end]);
    std::cout<<"succes on run:"<<check<<"\n";
    check++;
    return i;
}

void quickSort(long int *arr, long int start, long int end)
{
    // base case
    if (start < end)
    {
        // partitioning the array
        long int p = partition(arr, start, end);

        // Sorting the left part
        quickSort(arr, start, p - 1);

        // Sorting the right part
        quickSort(arr, p + 1, end);
    }
}

int main()
{
    long int *arr;
    std::ifstream inputFile("filegenerators/sizefiles/reverse/size1rev.txt");
    arr = new long int[MAX_SIZE];

    if (!inputFile.is_open())
    {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    long int count = 0; // To keep track of the number of elements read

    while (inputFile >> arr[count])
    {
        // Assuming values in the file are separated by spaces
        count++;
        if (count >= MAX_SIZE)
        {
            std::cerr << "Array size exceeded maximum limit." << std::endl;
            break;
        }
    }

    inputFile.close();

    // Sort the array using quicksort
    quickSort(arr, 0, MAX_SIZE - 1);
    // Display the elements read from the file
    std::cout << "Elements read from the file:" << std::endl;
    for (long int i = 0; i < MAX_SIZE; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    delete[] arr;
    return 0;
}