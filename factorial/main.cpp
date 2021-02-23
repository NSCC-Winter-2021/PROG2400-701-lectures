#include <iostream>

// 5! = 5 * 4 * 3 * 2 * 1 = 120

using namespace std;

unsigned long long recursiveFactorial(int num) {
    if (num == 1) return 1;
    return num * recursiveFactorial(num - 1);
}

unsigned long long factorial(int num) {

    unsigned long long answer = 1;
    for (int i = 1; i <= num; ++i) {
        answer *= i;
    }
    return answer;
}

int main() {

    int num;

    cout << "Enter a number:";
    cin >> num;

    cout << num << "! = " << factorial(num) << endl;
    cout << num << "! = " << recursiveFactorial(num) << endl;

    return 0;
}