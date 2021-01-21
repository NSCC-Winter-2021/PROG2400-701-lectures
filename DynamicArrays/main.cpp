
#include <iostream>
#include <cwchar>

using namespace std;

int main() {

    int *nums = new int[5] {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    int *nums2 = new int[6];
    memcpy(nums2, nums, 5*sizeof(int));
    delete[] nums;

    nums2[5] = 6;

    for (int i = 0; i < 6; ++i) {
        cout << nums2[i] << " ";
    }
    cout << endl;
    delete[] nums2;

    return 0;
}
