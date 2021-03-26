#include <iostream>
#include <iomanip>

using namespace std;

void dumparray(int *array, int len) {
    for (int i = 0; i < len; ++i) {
        cout << setw(3) << array[i];
    }
    cout << endl;
}

int split(int* array, int first, int last) {

    // find a pivot point
    int pivot = array[first];

    int left = first;
    int right = last;

    while (left < right) {

        // move elements lower to the left
        while (pivot < array[right]) {
            right--;
        }

        // move elements higher to the right
        while (pivot >= array[left]) {
            left++;
        }

        // as long as the indices haven't crossed boundaries
        // we have found two elements to swap
        if (left < right) {
//            int temp = array[left];
//            array[left] = array[right];
//            array[right] = temp;
            swap(array[left], array[right]);
        }
    }

    // move pivot point
    array[first] = array[right];
    array[right] = pivot;

    // return pivot
    return right;
}

void quicksort(int *array, int first, int last) {

    if (first < last) {
        int pivot = split(array, first, last);
        quicksort(array, first, pivot - 1);
        quicksort(array, pivot + 1, last);
    }

}

int main() {

    int nums[] = {3, 6, 8, 10, 5, 9, 4, 1, 2, 7};
    int len = sizeof(nums)/sizeof(int);

    cout << "Before Sorting..." << endl;
    dumparray(nums, len);

    quicksort(nums, 0, len - 1);

    cout << "After Sorting..." << endl;
    dumparray(nums, len);

    return 0;
}