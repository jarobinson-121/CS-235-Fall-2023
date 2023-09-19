#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

int main(int argc, char const* argv[]) {

    ifstream inputFile(argv[1]);
    int counter = 0;
    string words;
    istringstream iss(words);


    if(!inputFile.is_open()) {
        cout << "inputFile could not be opened.";
    }

    while(iss >> words) {
        counter ++;
    }

    return 0;
}
