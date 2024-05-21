#include <iostream>
#include <fstream>

const int MAX_SIZE = 10; // Change this to your desired maximum size

std::ifstream inputFile;

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

int main()
{
    long int *arr = new long int[MAX_SIZE];
    std::ifstream inputFile("sizefiles/size1.txt");

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
    long int nrel = 0;
    // Sort the array using Merge Sort
    MergeSort(arr, 0, MAX_SIZE - 1);
    // Display the elements read from the file
    std::cout << "Elements read from the file:" << std::endl;
    for (long int i = 0; i < MAX_SIZE; i++)
    {
        nrel++;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    delete[] arr;
    std::cout << nrel << "\n";
    return 0;
}