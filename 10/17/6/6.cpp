#include <iostream>
#include <fstream>

using namespace std;

void merge(int array [], int first, int last, int mid);
void sort(int array[], int first, int last);

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n;
    in >> n;

    int array[n];

    for(int i = 0; i < n; i++) {
        in >> array[i];
    }

    sort(array, 0, n - 1);

    for(int i = 0; i < n; i++) {
        out << array[i] << " ";
    }
    
    return 0;
}

void merge(int array [], int first, int last, int mid) {
    int i = first;
    int j = mid + 1;
    int k = first;

    int temp[last]; 
    while(i <= mid && j <= last) {
        if (array[i] <= array[j]) {
            temp[k] = array[i];
            i++;
        } else {
            temp[k] = array[j];
            j++;
        }

        k++;
    }

    j = last;

    for (int h = mid; h >= i; h--) {
        array[j] = array[h];
        j--;
    }

    for(int j = first; j < k; j++) {
        array[j] = temp[j];
    }
}

void sort(int array[], int first, int last) {
    if (first < last) {
        int mid = first + (last - first) / 2;

        sort(array, first, mid);
        sort(array, mid + 1, last);

        merge(array, first, last, mid);
    }
}