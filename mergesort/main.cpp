#include <iostream>
#include <iomanip>

using namespace std;

void dumparray(int *array, int len) {
    for (int i = 0; i < len; ++i) {
        cout << setw(3) << array[i];
    }
    cout << endl;
}

void split(int* inarray, int len, int* outarray1, int* outsize1, int* outarray2, int* outsize2) {

    // used to determine which file write into
    int numSubFiles = 0;

    // needed when dealing with arrays
    int in = 0;
    int out1 = 0;
    int out2 = 0;

    // keep track of two records
    int curr;
    int next = inarray[in++]; // read in first record

    // am I at the EOF?
    while (in <= len) {

        // while still in an ordered subfile
        do {

            curr = next;

            // read next record
            if (in < len) {
                next = inarray[in];
            }
            in++;

            // write record to correct temporary file
            if (numSubFiles % 2 == 0) {
                outarray1[out1++] = curr;
            } else {
                outarray2[out2++] = curr;
            }

        } while((curr < next) && (in <= len));

        numSubFiles++;

    }

    // again, not needed when using files
    *outsize1 = out1;
    *outsize2 = out2;
}

int merge(int* outarray, int *outsize, int* inarray1, int insize1, int* inarray2, int insize2) {

    int numSubFiles = 0;

    // not needed if using files
    int in1 = 0;
    int in2 = 0;
    int out = 0;

    // keep track of two records from each temp file
    int curr1;
    int curr2;

    int prev1;
    int prev2;

    // read a record from each temp file
    curr1 = inarray1[in1++];
    curr2 = inarray2[in2++];

    // keep looping while both files have records
    while ((in1 <= insize1) && (in2 <= insize2)) {

        // flags to indicate when a subfile has been crossed
        bool endOfSub1 = false;
        bool endOfSub2 = false;

        // keep reading/writing records while in order
        while (!endOfSub1 && !endOfSub2) {

            if (curr1 < curr2) {
                // write curr1 to merged file
                outarray[out++] = curr1;

                // read next record from temp file 1
                prev1 = curr1;
                if (in1 < insize1) {
                    curr1 = inarray1[in1];
                }
                in1++;

                // did we cross to a new subfile
                if ((prev1 > curr1) || (in1 > insize1)) {
                    endOfSub1 = true;
                }
            }

            if (curr2 < curr1) {
                // write curr2 to merged file
                outarray[out++] = curr2;

                // read next record from temp file 2
                prev2 = curr2;
                if (in2 < insize2) {
                    curr2 = inarray2[in2];
                }
                in2++;

                // did we cross to a new subfile
                if ((prev2 > curr2) || (in2 > insize2)) {
                    endOfSub2 = true;
                }
            }
        }

        // write remaining in-order records from file 1 that still them
        while (!endOfSub1) {
            // write curr1 to merged file
            outarray[out++] = curr1;

            // read next record from temp file 1
            prev1 = curr1;
            if (in1 < insize1) {
                curr1 = inarray1[in1];
            }
            in1++;

            // did we cross to a new subfile
            if ((prev1 > curr1) || (in1 > insize1)) {
                endOfSub1 = true;
            }
        }

        // write remaining in-order records from file 2 that still them
        while (!endOfSub2) {
            // write curr2 to merged file
            outarray[out++] = curr2;

            // read next record from temp file 2
            prev2 = curr2;
            if (in2 < insize2) {
                curr2 = inarray2[in2];
            }
            in2++;

            // did we cross to a new subfile
            if ((prev2 > curr2) || (in2 > insize2)) {
                endOfSub2 = true;
            }
        }

        numSubFiles++;

    }

    // dump remaining records from file 1 into merged file
    while (in1 <= insize1) {
        // write curr1 to merged file
        outarray[out++] = curr1;

        // read next record from temp file 1
        prev1 = curr1;
        if (in1 < insize1) {
            curr1 = inarray1[in1];
        }
        in1++;

        // did we cross to a new subfile
        if ((prev1 > curr1) || (in1 > insize1)) {
            numSubFiles++;
        }
    }

    // dump remaining records from file 2 into merged file
    while (in2 <= insize2) {
        // write curr2 to merged file
        outarray[out++] = curr2;

        // read next record from temp file 2
        prev2 = curr2;
        if (in2 < insize2) {
            curr2 = inarray2[in2];
        }
        in2++;

        // did we cross to a new subfile
        if ((prev2 > curr2) || (in2 > insize2)) {
            numSubFiles++;
        }

    }

    // again, not needed when using files
    *outsize = out;

    return numSubFiles;
}

void mergesort(int *array, int len) {

    int subFiles = 0;

    // two temporary files
    int *temp1 = new int[len];
    int *temp2 = new int[len];
    int tempsize1;
    int tempsize2;

    do {

        // pass filenames to split into
        split(array, len, temp1, &tempsize1, temp2, &tempsize2);

        // pass in three filenames
        subFiles = merge(array, &len, temp1, tempsize1, temp2, tempsize2);

    } while (subFiles != 1);

    delete [] temp1;
    delete [] temp2;

}

int main() {

    int nums[] = {3, 6, 8, 10, 5, 9, 4, 1, 2, 7};
    int len = sizeof(nums)/sizeof(int);

    cout << "Before Sorting..." << endl;
    dumparray(nums, len);

    // pass in filename
    mergesort(nums, len);

    cout << "After Sorting..." << endl;
    dumparray(nums, len);

    return 0;
}