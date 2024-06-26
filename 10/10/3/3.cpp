#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int sum(vector<int>);

// Data una matrice di interi, trovare la sottomatrice di somma massima.

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int r = 0;
    int c = 0;

    in >> r;
    in >> c;

    vector<vector<int>> matrix;

    for(int i = 0; i < r; i++) {
        vector<int> vec;

        for(int j = 0; j < c; j++) {
            int elem;
            in >> elem;
            vec.push_back(elem);
        }

        matrix.push_back(vec);
    }

    int maxFinal = 0;
    
    int firstLength = matrix.size();
    int secondLength = matrix[0].size();



    for(int = 0; i < firstLength; i++) {
        sum(matrix[i])
    }
    

    out << maxFinal;
    
    return 0;
}

int sum(vector<int> a) {
    int result = 0;

    for(int i = 0; i < a.size(); i++) {
        result += a[i];
    }

    return result;
}