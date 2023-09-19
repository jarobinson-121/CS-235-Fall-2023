#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

int main(int argc, char const* argv[]) {

    ifstream inputFile(argv[1]);
    int counter = 0;
    string words;
    string longestString = "";
    int longestCount = 0;
    string temp;


    if(!inputFile.is_open()) {

        cout << "inputFile could not be opened.";
        
        return -1;
    }
    else {

        while(!inputFile.eof()) {

            getline(inputFile, words);

            temp = words;

            istringstream iss(words);

                while(iss >> words) {

                    counter ++;

                }

                if(counter > longestCount) {

                    longestCount = counter;

                    longestString = temp;

                }

        }


        cout << longestString << endl;

        inputFile.close();
    }

    return 0;

}
