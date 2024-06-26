#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void enumeration(vector<char> S, int i, int n, int m) {
    if (n == 0 && m == 0) {
        for (int j = 0; j < S.size(); j++) {
            cout << S[j] << " ";
        }
        cout << endl;
    } else {
        if (n > 0) {
            S[i] = 'G';
            enumeration(S, i + 1, n - 1, m);
        }
        if (m > 0) {
            S[i] = 'R';
            enumeration(S, i + 1, n, m - 1);
        }

    }
}

int main() {

    int n;
    int m;

    printf("Insert n and m: ");
    cin >> n >> m;

    vector<char> S = vector<char>(n * m);

    enumeration(S, 0, n, m);

    return 0;
}