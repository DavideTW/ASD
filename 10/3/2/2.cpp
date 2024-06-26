#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Data una sequenza di interi, trovare la sottosequenza di somma massima.

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n = 0;
    in >> n;

    vector<int> vec;

    for(int i = 0; i < n; i++) {
        int elem; 
        in >> elem;
        vec.push_back(elem);
    }

    int maxSum = 0;
    int maxNow = 0;

    for(auto el : vec) {
        maxNow = max(el + maxNow, 0);
        maxSum = max(maxNow, maxSum);
    }

    out << maxSum;
    
    return 0;
}