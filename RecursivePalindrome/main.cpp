#include <iostream>
#include <cstring>

using namespace std;

bool isPalindrome(char *str, int len) {
    if (len <= 1) return true;
    return (str[0] == str[len-1]) && isPalindrome(&str[1], len-2);
}

int main() {

    char buffer[256];

    cout << "Enter a word: ";
    cin >> buffer;

    int len = strlen(buffer);

    if (isPalindrome(buffer, len)) {
        cout << buffer << " IS a palindrome!" << endl;
    } else {
        cout << buffer << " IS NOT a palindrome!" << endl;
    }


    return 0;
}