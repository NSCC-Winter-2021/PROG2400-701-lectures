#include <iostream>
#include <cstring>

using namespace std;

bool isPalindrome(char *str) {
    int len = strlen(str);
    if (len <= 1) return true;

    char first = str[0];
    char last = str[len-1];

    if (first == last) {
        char substr[len-1];
        strncpy(substr, &str[1], len-2);
        substr[len-2] = '\0';

        return isPalindrome(substr);;
    }
    return false;
}

int main() {

    char buffer[256];

    cout << "Enter a word: ";
    cin >> buffer;

    if (isPalindrome(buffer)) {
        cout << buffer << " IS a palindrome!" << endl;
    } else {
        cout << buffer << " IS NOT a palindrome!" << endl;
    }


    return 0;
}