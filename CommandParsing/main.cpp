#include <iostream>

using namespace std;

int main() {

    char command[32];
    int start;
    int end;

    cout << "Enter a command: ";
    cin >> command >> start >> end;

    cout << "Command: " << command << endl;
    cout << "Start: " << start << endl;
    cout << "End: " << end << endl;

    return 0;
}

