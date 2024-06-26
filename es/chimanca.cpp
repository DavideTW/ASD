#include <iostream>
#include <vector>

using namespace std;

int missing(int array[], int n) {
    if (array[n] == n) return n + 1;

    return missingRec(array, 1, n);
}

int missingRec(int array[], int i, int j) {
    if (i == j) return i;

    int m = (i + j) / 2;
    if (array[m] == m) return missingRec(array, m + i, j);

    return missingRec(array, i, m);
}