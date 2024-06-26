#include <iostream>
#include <fstream>

using namespace std;

long long int pillole(int n) {
    int full = n;
    int half = 0;

    long long int result;

    if (half == 0) {
        full--;
        result++;
    }

    
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int N;
    in >> N;

    out << pillole(N) << endl; 

    return 0;
}