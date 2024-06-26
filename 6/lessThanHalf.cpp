#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/*Scrivere un algoritmo
    lessThanHalf(int n)
    che prenda in input un intero n e stampi 
    tutte le sequenze A = a1, . . . , ak di interi positivi che iniziano con
    il valore n (a1 = n), tali per cui ogni elemento Ai con
    i > 1 sia tale che Ai−1 ≥ 2 · Ai
    .
    Discutere informalmente la correttezza dell’algoritmo e
    la sua complessità computazionale.
    Per esempio, se n = 7, queste sono le sequenze 
    che devono essere stampate, non necessariamente in quest’ordine:
    [7], [7, 1], [7, 2], [7, 2, 1], [7, 3], [7, 3, 1]
*/

vector<int> generateCoiches(int n) {
    vector<int> coiches;
    
    for (int i = 1; i <= n / 2; i++) {
        coiches.push_back(i);
    }

    return coiches;
}

void lessThanHalfEnum(int n, vector<int> S, int i) {
    for (int j = 0; j < S.size(); j++) {
        if (S[j] != 0) cout << S[j] << " ";
    }
    cout << endl;

    if (n <= 0) return;

    vector<int> coiches = generateCoiches(S[i - 1]);

    for (int j = 0; j < coiches.size(); j++) {
        S[i] = coiches[j];

        lessThanHalfEnum(n / 2, S, i + 1);
    }
}

void lessThanHalf(int n) {
    vector<int> S(n / 2);
    S[0] = n;

    lessThanHalfEnum(n, S, 1);
}

int main() {
    int n;
    cout << "Inserire n: ";
    cin >> n;

    lessThanHalf(n);
    return 0;
}