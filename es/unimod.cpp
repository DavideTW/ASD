#include <iostream>

using namespace std;

int unimod(int arr [], int i, int j) {
    int mid = (j + i) / 2;

    if (arr[mid -1] > arr[mid] && arr[mid] < arr[mid + 1]) return arr[mid];

    if (arr[mid - 1] > arr[mid]) return unimod(arr, mid + 1, j);

    return unimod(arr, i, mid);
}

int main() {
    int arr[] = {10, 5, 1, 2, 3, 4};

    cout << unimod(arr, 0, 6);
}