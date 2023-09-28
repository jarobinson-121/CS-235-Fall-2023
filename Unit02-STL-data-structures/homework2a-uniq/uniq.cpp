#include <iostream>
#include <string>
#include <fstream>
#include <set>

using namespace std;

int main(int argc, char const* argv[]) {
    set<string> names; 
    string temp;
    if(argc == 2) {
        fstream inputFile(argv[1]);
        
        if(!inputFile.is_open()) {
            cerr << "File was not opened." << endl;
        }

        while(!inputFile.eof()) {
            getline(inputFile, temp);

            if(names.find(temp) == names.end()) {
                names.insert(temp);
                cout << temp << endl;
            }

        }

        inputFile.close();
    }

    else {
        getline(cin, temp);
        while(temp != "") {
            if(names.find(temp) == names.end()) {
                names.insert(temp);
                cout << temp << endl;
            }
            
            getline(cin, temp);
        }
    }
    return 0;
}
