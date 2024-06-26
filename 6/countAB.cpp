#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/*
Un alberobello è un albero binario in cui tutti i nodi
hanno 0 o 2 figli; in altre parole, nessuno nodo ha 1
figlio.

Scrivere un algoritmo int countAB(int n)
che prenda in input un intero n e restituisca il numero
di alberibelli strutturalmente diversi contenenti n nodi.
*/

int countAB(int n) {
    if (n % 2 == 0) return 0;

    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    for (int i = 3; i <= n; i += 2) {
        for (int j = 1; j < i; j += 2) {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }

    return dp[n];
}

int main() {
    int n;
    cout << "Inserire n: ";
    cin >> n;

    cout << "countAB: " << countAB(n) << endl;

    return 0;
}