#include <iostream>
#include <iomanip>

using namespace std;

void dumparray(int *array, int len) {
    for (int i = 0; i < len; ++i) {
        cout << setw(3) << array[i];
    }
    cout << endl;
}

void selectionsort(int *array, int len) {

    for (int i = 0; i < len - 1; ++i) {

        // find next lowest value
        int lowest = i;
        for (int j = i + 1; j < len; ++j) {
            if (array[j] < array[lowest]) {
                lowest = j;
            }
        }

        if (array[lowest] < array[i]) {
            int temp = array[lowest];
            array[lowest] = array[i];
            array[i] = temp;
        }
    }

}

int main() {

    int nums[] = {3, 6, 8, 10, 5, 9, 4, 1, 2, 7};
    int len = sizeof(nums)/sizeof(int);

    cout << "Before Sorting..." << endl;
    dumparray(nums, len);

    selectionsort(nums, len);

    cout << "After Sorting..." << endl;
    dumparray(nums, len);

    return 0;
}