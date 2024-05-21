#include <iostream>
#include <fstream>

long int MAX_SIZE = 1000000000; // Change this to your desired maximum size

int main() {
    std::ifstream inputFile("filegenerators/sizefiles/random/size9.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    long int *arr= new long int [MAX_SIZE];
    long int count = 0; // To keep track of the number of elements read

    while (inputFile >> arr[count]) {
        // Assuming values in the file are separated by spaces
        count++;
        if (count >= MAX_SIZE) {
            std::cerr << "Array size exceeded maximum limit." << std::endl;
            break;
        }
    }

    inputFile.close();

    // Display the elements read from the file
    std::cout << "Elements read from the file:" << std::endl;
    for (long int i = 0; i < count; i++) {
        std::cout << arr[i] << " ";
    }
    free(arr);
    std::cout << std::endl;

    return 0;
}