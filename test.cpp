#include <iostream>
#include <vector>
#include "timer.h"
#include <fstream>
#include "OpenFile.h"
// #include "memory.h"

std::ifstream inputFile;
short int choice;
std::string NameOfFile;

bool is_empty(std::fstream &pFile)
{
    return pFile.peek() == std::fstream::traits_type::eof();
}

void swap(long int &xp, long int &yp)
{
    long int temp = xp;
    xp = yp;
    yp = temp;
}

void selection_sort(long int size)
{
    if (choice == 1)
    {
        OpenFileRandom(size, inputFile, NameOfFile);
    }
    if (choice == 2)
    {
        OpenFileReversed(size, inputFile, NameOfFile);
    }
    if (choice == 3)
    {
        OpenFileAlmost(size, inputFile, NameOfFile);
    }
    if (!inputFile.is_open())
    {
        std::cerr << "Error opening the file." << std::endl;
        return;
    }

    long int *arr = new long int[size];
    long int count = 0; // To keep track of the number of elements read

    // Reading the elements from the file into the array
    while (inputFile >> arr[count])
    {
        // Assuming values in the file are separated by spaces
        count++;
        if (count >= size)
        {
            std::cerr << "Array size exceeded maximum limit." << std::endl;
            break;
        }
    }

    // Sorting algorithm
    long int i, j, min_idx;
    {
        Timer timeit(NameOfFile);
        for (i = 0; i < size - 1; i++)
        {
            min_idx = i;
            for (j = i + 1; j < size; j++)
                if (arr[j] < arr[min_idx])
                    min_idx = j;

            swap(arr[min_idx], arr[i]);
        }
    }
    inputFile.close();

    // Printing...if you really want to
    /*for (long int i = 0; i < size; i++)
    {
        std::cout << arrl[i] << " ";
    }*/
    delete[] arr;

    std::cout << "\n\n\n";
}

// Quicksort
long int medianOfThree(long int arr[], long int left, long int right)
{
    long int middle = left + (right - left) / 2;

    if (arr[left] > arr[middle])
        swap(arr[left], arr[middle]);

    if (arr[left] > arr[right])
        swap(arr[left], arr[right]);

    if (arr[middle] > arr[right])
        swap(arr[middle], arr[right]);

    return middle;
}

// Partition with median of three
long int partitionM(long int *arr, long int start, long int end)
{
    // Choose pivot using median-of-three method
    long int pivotIndex = medianOfThree(arr, start, end);

    // Swap pivot with the first element
    swap(arr[start], arr[pivotIndex]);

    // Continue with the rest of the partitioning logic as before
    long int pivot = arr[start];
    long int i = start, j = end;

    while (i < j)
    {
        while (i <= end && arr[i] <= pivot)
            i++;

        while (arr[j] > pivot)
            j--;

        if (i < j)
            swap(arr[i], arr[j]);
    }

    // Swap pivot to its correct position
    swap(arr[start], arr[j]);

    return j;
}

// Partition without median of three

long int partition(long int *arr, long int start, long int end)
{
    long int pivot = arr[start];

    long int count = 0;
    for (long int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
            count++;
    }

    // Giving pivot element its correct position
    long int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    // Sorting left and right parts of the pivot element
    long int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex)
    {

        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(long int *arr, long int start, long int end)
{
    // base case
    if (start >= end)
        return;

    // partitioning the array
    long int p = partition(arr, start, end);

    // Sorting the left part
    quickSort(arr, start, p - 1);

    // Sorting the right part
    quickSort(arr, p + 1, end);
}

void quickSortM(long int *arr, long int start, long int end)
{
    // base case
    if (start >= end)
        return;

    // partitioning the array
    long int p = partitionM(arr, start, end);

    // Sorting the left part
    quickSortM(arr, start, p - 1);

    // Sorting the right part
    quickSortM(arr, p + 1, end);
}

// Merge sort
void Merge(long int arr[], long int l, long int m, long int r)
{
    long int i = l;
    long int j = m + 1;
    long int k = l;

    long int size = r;
    long int *temp = new long int[size + 1];

    while (i <= m && j <= r) // while the left has not exceeded the middle and the right side(middle+1) has not exceeded the right side(the limit of the array)
    {
        if (arr[i] <= arr[j]) // compare the first element from the first subarray(from left to the middle) to the second subarray(from middle+1 to right)
        {
            temp[k] = arr[i]; // if it is smaller then we put the element from the first subarray in a temp array
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j]; // otherwise we put the element from the second subarray in the temp array
            j++;
            k++;
        }
    }
    while (i <= m)
    {
        temp[k] = arr[i]; // Copying all elements from left subarray to the temp array
        i++;
        k++;
    }
    while (j <= r)
    {
        temp[k] = arr[j]; // Copying all elements from right subarray to the temp array
        j++;
        k++;
    }
    // we transfer the elements from the temp array to the main array so it is ready to be re-executed in Merge Sort
    for (long int z = l; z <= r; z++)
    {
        arr[z] = temp[z];
    }
    delete[] temp;
}

void MergeSort(long int arr[], long int left, long int right)
{
    if (left < right)
    {
        long int middle = (left + right) / 2;
        MergeSort(arr, left, middle);
        MergeSort(arr, middle + 1, right);
        Merge(arr, left, middle, right);
    }
}

void insertion_sort(long int size)
{
    if (choice == 1)
    {
        OpenFileRandom(size, inputFile, NameOfFile);
    }
    if (choice == 2)
    {
        OpenFileReversed(size, inputFile, NameOfFile);
    }
    if (choice == 3)
    {
        OpenFileAlmost(size, inputFile, NameOfFile);
    }
    if (!inputFile.is_open())
    {
        std::cerr << "Error opening the file." << std::endl;
        return;
    }

    long int *arr = new long int[size];
    long int count = 0; // To keep track of the number of elements read

    // Reading the elements from the file into the array
    while (inputFile >> arr[count])
    {
        // Assuming values in the file are separated by spaces
        count++;
        if (count >= size)
        {
            std::cerr << "Array size exceeded maximum limit." << std::endl;
            break;
        }
    }

    // sorting algorithm
    {
        Timer timeit(NameOfFile);
        for (long int i = 1; i < size; i++)
        {
            long int key = arr[i];
            long int j = i - 1;
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
    inputFile.close();

    // Printing...if you really want to
    /*for (long int i = 0; i < size; i++)
    {
        std::cout << arrl[i] << " ";
    }*/
    delete[] arr;
    std::cout << "\n\n\n";
}

void bubble_sort(long int size)
{
    if (choice == 1)
    {
        OpenFileRandom(size, inputFile, NameOfFile);
    }
    if (choice == 2)
    {
        OpenFileReversed(size, inputFile, NameOfFile);
    }
    if (choice == 3)
    {
        OpenFileAlmost(size, inputFile, NameOfFile);
    }

    if (!inputFile.is_open())
    {
        std::cerr << "Error opening the file." << std::endl;
        return;
    }

    long int *arr = new long int[size];
    long int count = 0; // To keep track of the number of elements read

    while (inputFile >> arr[count])
    {
        // Assuming values in the file are separated by spaces
        count++;
        if (count >= size)
        {
            std::cerr << "Array size exceeded maximum limit." << std::endl;
            break;
        }
    }

    // sorting algorithm
    {
        Timer timeit(NameOfFile);
        for (long int i = 0; i < size - 1; i++)
        {
            for (long int j = i + 1; j < size; j++)
            {
                if (arr[j] < arr[i])
                    swap(arr[j], arr[i]);
            }
        }
    }

    inputFile.close();

    // Printing...if you really want to
    /*for (long int i = 0; i < size; i++)
    {
        std::cout << arrl[i] << " ";
    }*/
    delete[] arr;
    std::cout << "\n\n\n";
}

void RunBenchmarkRandom()
{
    short int choiceions;
    long int size;
    char answ;
    std::cout << "What size do you want to sort?\n1) 10\n2) 100\n3) 1000\n4) 10000\n5) 100000\n6) 1000000\n7) 10000000\n8) 100000000\n9) 1000000000\n";
    std::cin >> choiceions;
    switch (choiceions)
    {
    case 1:

        size = 10;
        break;

    case 2:

        size = 100;
        break;

    case 3:

        size = 1000;
        break;

    case 4:

        size = 10000;
        break;

    case 5:

        size = 100000;
        break;

    case 6:

        size = 1000000;
        break;

    case 7:

        size = 10000000;
        break;
    case 8:

        size = 100000000;
        break;
    case 9:

        size = 1000000000;
        break;
    }

    long int *arrl;

    arrl = new long int[size];

    // Quicksort | random | opening correct file
    OpenFileRandom(size, inputFile, NameOfFile);

    if (!inputFile.is_open())
    {
        std::cerr << "Error opening the file." << std::endl;
        delete[] arrl;
        return;
    }

    long int count = 0; // To keep track of the number of elements read

    // Getting the numbers from the file into the array
    while (inputFile >> arrl[count])
    {
        // Assuming values in the file are separated by spaces
        count++;
        if (count >= size)
        {
            std::cerr << "Array size exceeded maximum limit." << std::endl;
            break;
        }
    }

    inputFile.close();

    std::cout << "Do you want to use median of three for quicksort?(y/n)";
    std::cin >> answ;

    if (answ == 'n')
    {
        std::cout << "Quicksort:\n";
        {
            Timer timeit(NameOfFile);
            quickSort(arrl, 0, size - 1);
        }
    }

    if (answ == 'y')
    {
        std::cout << "Quicksort:\n";
        {
            Timer timeit(NameOfFile);
            quickSortM(arrl, 0, size - 1);
        }
    }

    // Printing...if you really want to

    // for (long int i = 0; i < size; i++)
    // {
    //     std::cout << arrl[i] << " ";
    // }

    std::cout << "\n\n\n";
    delete[] arrl;

    arrl = new long int[size];

    count = 0;

    // Merge sort | for random | Opening the correct file
    OpenFileRandom(size, inputFile, NameOfFile);

    if (!inputFile.is_open())
    {
        std::cerr << "Error opening the file." << std::endl;
        delete[] arrl;
        return;
    }

    inputFile.clear();  // Clear any error flags
    inputFile.seekg(0); // Move the cursor to the beginning of the file

    // Getting the elements from the file into the array
    while (inputFile >> arrl[count])
    {
        // Assuming values in the file are separated by spaces
        count++;
        if (count >= size)
        {
            std::cerr << "Array size exceeded maximum limit." << std::endl;
            break;
        }
    }

    std::cout << "Merge sort:\n";
    {
        Timer timeit(NameOfFile);
        MergeSort(arrl, 0, size - 1);
    }
    inputFile.close();

    // Printing...if you really want to
    /*for (long int i = 0; i < size; i++)
    {
        std::cout << arrl[i] << " ";
    }*/

    std::cout << "\n\n\n";

    delete[] arrl;

    std::cout << "Selection sort:\n";
    selection_sort(size);

    std::cout << "Insertion sort:\n";
    insertion_sort(size);

    std::cout << "Bubble sort:\n";
    bubble_sort(size);
}

void RunBenchmarkReversed()
{
    short int choiceions;
    long int size;
    char answ;

    std::cout << "What size do you want to sort?\n1) 10\n2) 100\n3) 1000\n4) 10000\n5) 100000\n6) 1000000\n7) 10000000\n8) 100000000\n9) 1000000000\n";
    std::cin >> choiceions;

    switch (choiceions)
    {
    case 1:

        size = 10;
        break;

    case 2:

        size = 100;
        break;

    case 3:

        size = 1000;
        break;

    case 4:

        size = 10000;
        break;

    case 5:

        size = 100000;
        break;

    case 6:

        size = 1000000;
        break;

    case 7:

        size = 10000000;
        break;
    case 8:

        size = 100000000;
        break;
    case 9:

        size = 1000000000;
        break;
    }

    long int *arrl;

    arrl = new long int[size];

    // Quicksort | reversed | opening correct file
    OpenFileReversed(size, inputFile, NameOfFile);

    if (!inputFile.is_open())
    {
        std::cerr << "Error opening the file." << std::endl;
        delete[] arrl;
        return;
    }

    long int count = 0; // To keep track of the number of elements read

    // getting the elements from the file into the array
    while (inputFile >> arrl[count])
    {
        // Assuming values in the file are separated by spaces
        count++;
        if (count >= size)
        {
            std::cerr << "Array size exceeded maximum limit." << std::endl;
            break;
        }
    }

    inputFile.close();

    if (size <= 10000)
    {
        std::cout << "Do you want to use median of three for quicksort?(y/n)";
        std::cin >> answ;
    }

    // if size bigger than 10000 use median of three
    if (answ == 'n')
    {
        std::cout << "Quicksort:\n";
        {
            Timer timeit(NameOfFile);
            quickSort(arrl, 0, size - 1);
        }
    }

    if (answ == 'y' || size >= 100000)
    {
        std::cout << "Quicksort:\n";
        {
            Timer timeit(NameOfFile);
            quickSortM(arrl, 0, size - 1);
        }
    }

    // Printing...if you really want to
    /*for (long int i = 0; i < size; i++)
    {
        std::cout << arrl[i] << " ";
    }*/

    delete[] arrl;
    std::cout << "\n\n\n";

    arrl = new long int[size];

    count = 0;

    // Merge sort | reversed | opening correct file
    OpenFileReversed(size, inputFile, NameOfFile);

    if (!inputFile.is_open())
    {
        std::cerr << "Error opening the file." << std::endl;
        delete[] arrl;
        return;
    }

    inputFile.clear();  // Clear any error flags
    inputFile.seekg(0); // Move the cursor to the beginning of the file

    // Getting the elements from the file into the array
    while (inputFile >> arrl[count])
    {
        // Assuming values in the file are separated by spaces
        count++;
        if (count >= size)
        {
            std::cerr << "Array size exceeded maximum limit." << std::endl;
            break;
        }
    }

    std::cout << "Merge sort:\n";
    {
        Timer timeit(NameOfFile);
        MergeSort(arrl, 0, size - 1);
    }

    // Printing...if you really want to
    /*for (long int i = 0; i < size; i++)
    {
        std::cout << arrl[i] << " ";
    }*/

    std::cout << "\n\n\n";

    delete[] arrl;
    inputFile.close();

    std::cout << "Selection sort:\n";
    selection_sort(size);

    std::cout << "Insertion sort:\n";
    insertion_sort(size);

    std::cout << "Bubble sort:\n";
    bubble_sort(size);
}

void RunBenchmarkAlmostSorted()
{
    short int choiceions;
    long int size;
    char answ;

    std::cout << "What size do you want to sort?\n1) 10\n2) 100\n3) 1000\n4) 10000\n5) 100000\n6) 1000000\n7) 10000000\n8) 100000000\n9) 1000000000\n";
    std::cin >> choiceions;

    switch (choiceions)
    {
    case 1:

        size = 10;
        break;

    case 2:

        size = 100;
        break;

    case 3:

        size = 1000;
        break;

    case 4:

        size = 10000;
        break;

    case 5:

        size = 100000;
        break;

    case 6:

        size = 1000000;
        break;

    case 7:

        size = 10000000;
        break;
    case 8:

        size = 100000000;
        break;
    case 9:

        size = 1000000000;
        break;
    }

    long int *arrl;

    arrl = new long int[size];

    // Quicksort | almost sorted | opening the correct file
    OpenFileAlmost(size, inputFile, NameOfFile);

    if (!inputFile.is_open())
    {
        std::cerr << "Error opening the file." << std::endl;
        delete[] arrl;
        return;
    }

    long int count = 0; // To keep track of the number of elements read

    // getting the elements from the file into the array
    while (inputFile >> arrl[count])
    {
        // Assuming values in the file are separated by spaces
        count++;
        if (count >= size)
        {
            std::cerr << "Array size exceeded maximum limit." << std::endl;
            break;
        }
    }

    inputFile.close();

    if (size <= 10000)
    {
        std::cout << "Do you want to use median of three for quicksort?(y/n)";
        std::cin >> answ;
    }

    // if size bigger than 10000 use median of three
    if (answ == 'n')
    {
        std::cout << "Quicksort:\n";
        {
            Timer timeit(NameOfFile);
            quickSort(arrl, 0, size - 1);
        }
    }

    if (answ == 'y' || size >= 100000)
    {
        std::cout << "Quicksort:\n";
        {
            Timer timeit(NameOfFile);
            quickSortM(arrl, 0, size - 1);
        }
    }

    // Printing...if you really want to
    /*for (long int i = 0; i < size; i++)
    {
        std::cout << arrl[i] << " ";
    }*/

    delete[] arrl;
    std::cout << "\n\n\n";

    // start again for merge sort this time
    arrl = new long int[size];
    count = 0;

    // Merge Sort | Almost sorted | opening the correct file
    OpenFileAlmost(size, inputFile, NameOfFile);

    if (!inputFile.is_open())
    {
        std::cerr << "Error opening the file." << std::endl;
        delete[] arrl;
        return;
    }

    inputFile.clear();  // Clear any error flags
    inputFile.seekg(0); // Move the cursor to the beginning of the file

    // Getting the elements from the file into the array
    while (inputFile >> arrl[count])
    {
        // Assuming values in the file are separated by spaces
        count++;
        if (count >= size)
        {
            std::cerr << "Array size exceeded maximum limit." << std::endl;
            break;
        }
    }

    // time the algorithm
    std::cout << "Merge sort:\n";
    {
        Timer timeit(NameOfFile);
        MergeSort(arrl, 0, size - 1);
    }

    // Printing...if you really want to
    /*for (long int i = 0; i < size; i++)
    {
        std::cout << arrl[i] << " ";
    }*/
    std::cout << "\n\n\n";

    delete[] arrl;
    inputFile.close();

    std::cout << "Insertion sort:\n";
    insertion_sort(size);

    std::cout << "Bubble sort:\n";
    bubble_sort(size);

    std::cout << "Selection sort:\n";
    selection_sort(size);
}

int main(int argc, char *argv[])
{
    std::cout << "What type of array do you want to sort:\n1)random\n2)reversed\n3)almost sorted\n";
    std::cin >> choice;
    std::cout << "\n";

    if (choice == 1)
    {
        RunBenchmarkRandom();
    }
    if (choice == 2)
    {
        RunBenchmarkReversed();
    }
    if (choice == 3)
    {
        // for almost sorted selection sort and insertion sort are swaped...insertion sort takes less time to sort than selection sort(Talking about the results inside the .csv files)
        RunBenchmarkAlmostSorted();
    }

    return 0;
}