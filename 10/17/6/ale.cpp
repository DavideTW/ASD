#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

// Merge two sorted subarrays into a single sorted array
void merge(int *arr, int left, int mid, int right) {
    int *temp= new int[right - left + 1];
    int i = left, j = mid + 1, k = 0;
    for(i; i <= mid && j <= right; k++) {
        if(arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        }
        else {
            temp[k] = arr[j];
            j++;
        }
    }
    for(i; i <= mid; i++, k++)
        temp[k] = arr[i];
    for(j; j <= right; j++, k++)
        temp[k] = arr[j];
    for(int p = 0; p < k; p++)
        arr[left + p] = temp[p];
    delete[] temp;
}

// Sort an array using merge sort algorithm
void mergeSort(int *arr, int left, int right) {
    if (left<right){
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

int main(){
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int n;
    inputFile >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        inputFile >> arr[i];
    }
    mergeSort(arr,0, n-1); 

    for (int i = 0; i < n; i++) {
        outputFile << arr[i] << " ";
    }

    inputFile.close();
    outputFile.close();

    return 0; 
}