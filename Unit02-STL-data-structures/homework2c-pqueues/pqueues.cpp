#include <iostream>
#include <string>
#include <queue>

#include "input.h"

using namespace std;

int main(int argc, char const* argv[]) {
    priority_queue<string> priQueue;
    string response;
    string prompt = "What do you want to do? ";
    string name;
    string newString;
    int priority = 0;

    bool check = input(prompt, response);

    while(check == true) {
        if(response == "add") {
            cout << "Name: ";
            getline(cin, name);

            cout << "Priority: ";
            cin >> priority;

            if(priority < 10) {
                newString = "0" + to_string(priority) + " - " + name;
                priQueue.push(newString);
            }
            else {
                newString = to_string(priority) + " - " + name;
                priQueue.push(newString);
            }
            cin.ignore();
        }
        else if(response == "take") {
            if(priQueue.empty()) {
                cout << "There are no more people in line" << endl;
            }
            else {
                cout << priQueue.top() << endl;
                priQueue.pop();

                cout.flush();
            }
        }
        else {
            cout << response << " isn't a valid operation" << endl;
        }
        check = input(prompt, response);
    }

    return 0;
}
