#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const* argv[]) {

    if(argc < 1) {
        string s = argv[1];
        cout << s << endl;
    }

    int numLines = 10;
    string fnombre = "iGuessthisisafilename.ohboy";

    for(int i = 1; i < argc; i++) {
        if(argv[i][0] == '-') {
            //this is specifying numLines
            string lineStr = argv[i];
            numLines = stoi(lineStr.substr(1));
        }
        else {
            fnombre = argv[1];
        }
    }

    

    return 0;
}
