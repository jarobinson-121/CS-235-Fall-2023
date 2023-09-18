#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int main(int argc, char const* argv[]) {
    
    // open files to pull from and print to
    ifstream inputFile(argv[1]);
    ofstream outputFile(argv[2]);

    // check that files opened properly
    if(!inputFile.is_open()) {
        cout << "inputFile could not be opened.";
    }

    if(!outputFile.is_open()) {
        cout << "outputFile could not be opened.";
    }

    // Variable declarations
    string delimiter = " ";
    string input;
    size_t spot = 0;
    string firstName;
    string lastName;
    int points;
    double factor;
    double finalPoints;

    while(getline(inputFile, input)) {
        firstName = input.substr(0, input.find(delimiter));

        input.erase(0, input.find(delimiter) + delimiter.length());

        lastName = input.substr(0, input.find(delimiter));
        
        input.erase(0, input.find(delimiter) + delimiter.length());
    
        points = stoi(input.substr(0, input.find(delimiter)));
        
        input.erase(0, input.find(delimiter) + delimiter.length());

        factor = stod(input.substr(0, input.find(delimiter)));
        
        input.erase(0, input.find(delimiter) + delimiter.length());

        cout << setprecision(2);

    }

    finalPoints = points * factor;

    inputFile.close();

    outputFile.close();

    return 0;
}
