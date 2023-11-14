#include <iostream>
#include <fstream>
#include <vector>

void insertionSort(std::vector<std::string>& array) {
    int n = array.size();
    
    for (int i = 1; i < n; ++i) {
        std::string key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }

        array[j + 1] = key;
    }
}

int main() {
    std::ifstream inputFile("input.txt"); // Change the file name as needed

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::vector<std::string> array;
    std::string item;

    // Read items from the file into the vector
    while (inputFile >> item) {
        array.push_back(item);
    }

    inputFile.close();

    std::cout << "Original array: ";
    for (const std::string& str : array) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    insertionSort(array);

    std::cout << "Sorted array: ";
    for (const std::string& str : array) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    return 0;
}
