#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char const* argv[]) {

    int numLines = 10;
    string fnombre = "iGuessthisisafilename.ohboy";
    string input;

    if(argc == 3) {
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

        if(fnombre != "iGuessthisisafilename.ohboy") {

            ifstream inputFile(fnombre);

            if(!inputFile.is_open()) {
                cerr << "ERROR: can't open " << fnombre;
                return -1;
            }

            for(int i = 0; i < numLines; i++) {
                if(!inputFile.eof()) {
                    getline(inputFile, input);
                    cout << input << endl;
                }
            }

            inputFile.close();

        }

    }

    else if(argc == 2) {
        string input2;
        if(argv[1][0] == '-') {
            //this is specifying numLines
            string lineStr = argv[1];
            numLines = stoi(lineStr.substr(1));

            for(int i = 0; i < numLines; i++) {
                getline(cin, input2);
                cout << input2 << endl;
            }
        }

        else {

            ifstream inputFile2(argv[1]);

            if(!inputFile2.is_open()) {
                cerr << "ERROR: can't open " << fnombre;
                return -1;
            }

            for(int i = 0; i < numLines; i++) {
                getline(inputFile2, input);
                cout << input << endl;
            }

            inputFile2.close();
        }
    }

    else {
        while(getline(cin, input)) {
            cout << input << endl;
        }
    }

    

    return 0;
}
