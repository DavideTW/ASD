#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int minpal(string A,int i, int j) {
    if (i >= j) return 0;

    if (A[i] == A[j]) {
        return minpal(A, i + 1, j - 1);
    } 

    return 1 + min(minpal(A, i + 1, j), minpal(A, i, j - 1));
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n;
    in >> n;    

    for (int i = 0; i < n; i++){
        string A;
        in >> A;
        out << minpal(A, 0, A.size() - 1) << endl;
    }

    return 0;
}