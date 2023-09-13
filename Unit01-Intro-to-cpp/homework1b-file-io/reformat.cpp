#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int main(int argc, char const* argv[]) {
    
    ifstream inputFile(argv[1]);
    ofstream outputFile(argv[2]);

    if(inputFile.is_open()) {
        cout << "The File WorkS!!!";
    }
    
    else {
        cout << "booty";
    }

    if(outputFile.is_open()) {
        cout << "The File WorkS!!!2";
    }
    
    else {
        cout << "booty2";
    }

    inputFile.close();

    outputFile.close();

    return 0;
}
