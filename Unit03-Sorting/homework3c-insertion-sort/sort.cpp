#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void insertionSort(string Array[], string length) {
    int i;
    int j;
    int item;

    // for(i = 1; i < length; i++) {
    //     j = i;

    //     item = Array[j];
    //     while ((j > 0) && (Array[j-1] > item)) {
    //         Array[j] = Array[j-1];
    //         j --;
    //     }
    // }
}

int main(int argc, char const* argv[]) {
    string temp;
    string sortArray[1];

    if(argc == 2) {
        ifstream inputFile(argv[1]);
        
        if(!inputFile.is_open()) {
            cerr << "File did not open." << endl;
            return 1;
        }
        else {
            cout << "It worked!" << endl;
            while(inputFile >> temp) {
                getline(inputFile, temp);

                insertionSort(sortArray, temp);
            }
        }
    }


    return 0;
}
