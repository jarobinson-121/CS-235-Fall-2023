#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char const* argv[]) {

    int numLines = 10;
    string fnombre = "iGuessthisisafilename.ohboy";
    string input;

    if(argc > 1) {
        for(int i = 1; i < argc; i++) {
            if(argv[i][0] == '-') {
                //this is specifying numLines
                string lineStr = argv[i];
                numLines = stoi(lineStr.substr(1));
            }

            else {
                fnombre = argv[i];
            }
        }

        ifstream inputFile(fnombre);

        if(!inputFile.is_open()) {
            cerr << "ERROR: can't open " << fnombre;
            return -1;
        }

        for(int i = 0; i < numLines; i++) {
            getline(inputFile, input);
            cout << input << endl;
        }

    }

    else {
        while(getline(cin, input)) {
            cout << input << endl;
        }
    }

    return 0;
}
