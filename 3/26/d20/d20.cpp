#include <iostream>
#include <fstream>

using namespace std;

int nWays(int n, vector<int> F, int X) {
    if (X < n) return 0;
    if (X == n) return 1;

    int ways = 1;

    for (int i = n; i > 0; i--) {
        ways += nWays(n - 1, F, X - F[i]);
    }

    return ways;
}


int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n;
    in >> n;

    vector<int> F(n);
    for (int i = 0; i < n; i++) {
        in >> F[i];
    }

    int X;
    in >> X;

    out << nWays(n, F, X) << endl;
    
    return 0;
}