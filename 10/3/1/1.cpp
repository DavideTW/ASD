#include <iostream>
#include <fstream>

using namespace std;

// Dati due interi, sommateli.

int main() {
    int n = 0, m = 0;

    ifstream in("input.txt");
    ofstream out("output.txt");

    in >> n;
    in >> m;
    
    out << n + m << endl; 
    return 0;
}