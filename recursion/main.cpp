#include <iostream>

using namespace std;

int count = 0;

void recursiveFunction() {

    count++;
    if(count > 10) return;

    cout << "hello" << endl;

    recursiveFunction();
}

int main() {

    recursiveFunction();

    return 0;
}