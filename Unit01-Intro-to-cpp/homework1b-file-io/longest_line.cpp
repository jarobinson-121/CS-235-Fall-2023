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
    string longestString;
    int longestCount;


    if(!inputFile.is_open()) {

        cout << "inputFile could not be opened.";
        
        return -1;
    }

    while(!inputFile.eof()) {

        getline(inputFile, words);

        while(iss >> words) {

            counter ++;

        }

        if(counter > longestCount) {

            longestCount = counter;

            longestString = words;

        }

    }

    return 0;
}
