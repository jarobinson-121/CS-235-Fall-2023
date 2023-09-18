#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int main(int argc, char const* argv[]) {
    
    ifstream inputFile(argv[1]);
    ofstream outputFile(argv[2]);

    if(!inputFile.is_open()) {
        cout << "inputFile could not be opened.";
    }

    if(!outputFile.is_open()) {
        cout << "outputFile could not be opened.";
    }

    

    inputFile.close();

    outputFile.close();

    return 0;
}
