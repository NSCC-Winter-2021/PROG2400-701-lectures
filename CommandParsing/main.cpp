#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

int main() {

    char input[256];
    char command[32];
    int start;
    int end;

    cout << "Enter a command: ";
    cin.getline(input, 256);

    stringstream ss;
    ss << input;

    ss >> command;

    if (strlen(command) > 1) {
        cout << "You entered text." << endl;
    } else {
        cout << "You entered a " << command << " command" << endl;

        ss >> start;
        ss >> end;

        cout << "Command: " << command << endl;
        cout << "Start: " << start << endl;
        cout << "End: " << end << endl;

    }

    return 0;
}

