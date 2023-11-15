#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void insertionSort(vector<string>& vector) {
    int length = vector.size();
    int j;

    for(int i = 1; i < length; i++) {
        j = i - 1;
        string item = vector[i];

        while ((j >= 0) && (vector[j] > item)) {
            vector[j + 1] = vector[j];
            j--;
        }

        vector[j + 1] = item;
    }
    
}

int main(int argc, char const* argv[]) {
    string temp;
    vector<string> sortVect;

    if(argc == 2) {
        ifstream inputFile(argv[1]);
        
        if(!inputFile.is_open()) {
            cerr << "File did not open." << endl;
            return 1;
        }
        else {
            while(inputFile >> temp) {
                sortVect.push_back(temp);
            }
        }

        inputFile.close();

        insertionSort(sortVect);

    }
    else {
        getline(cin, temp);

        while(temp != "") {
            sortVect.push_back(temp);

            getline(cin, temp);
        }
        insertionSort(sortVect);
    }

    for(int i = 0; i < sortVect.size(); i++) {
        cout << sortVect[i] << endl;
    }


    return 0;
}
