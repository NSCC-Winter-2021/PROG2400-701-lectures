#include <iostream>
#include <iomanip>

using namespace std;

void dumparray(int *array, int len) {
    for (int i = 0; i < len; ++i) {
        cout << setw(3) << array[i];
    }
    cout << endl;
}

void shellsort(int *array, int len) {

    for (int gap = len/2; gap > 0 ; gap /= 2) {

        cout << "gap: " << gap << endl;

        // sort each sublist
        for (int start = 0; start < gap; start++) {

            // insertion sort
            for (int i = start + gap; i < len; i += gap) {

                // get element to insert
                int temp = array[i];

                // shuffle elements along
                int j;
                for (j = i; j >= gap && temp < array[j - gap]; j -= gap) {
                    array[j] = array[j - gap];
                }

                // insert the element
                array[j] = temp;
            }

            dumparray(array, len);
        }
    }

}

int main() {

    int nums[] = {3, 6, 8, 10, 5, 9, 4, 1, 2, 7};
    int len = sizeof(nums)/sizeof(int);

    cout << "Before Sorting..." << endl;
    dumparray(nums, len);

    shellsort(nums, len);

    cout << "After Sorting..." << endl;
    dumparray(nums, len);

    return 0;
}