#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/* 
Date due stringhe S1 e S2 di lunghezza n1 e n2, una
stringa T è un misciotto di S1 e S2 se T ha lunghezza
n = n1 + n2 ed è ottenuta intercalando caratteri di S1
e S2, conservando però l’ordine originale dei caratteri
all’interno di ciascuna delle due stringhe.
Scrivere un algoritmo
printMixing(Item[ ] S1, Item[ ] S2, int n1, int n2)

che prenda in input le stringhe S1, S2 e le rispettive lunghezze, e stampi tutti i misciotti di S1 e
S2 Discutere informalmente correttezza e complessità
computazionale.
Per esempio,
• se S1 = "ABC" e S2 = "DEF", la stringa T =
"ADBCEF" è un misciotto di S1 e S2;
• se S1 = "ABC" e S2 = "ABC", la stringa T =
"ABCCBA" non è un misciotto di S1 e S2.
*/

void printMixing(vector<char> S1, vector<char> S2, vector<char> S, int i, int j) {
    if (S.size() == S1.size() + S2.size()) {
        for (char c : S) {
            cout << c;
        }
        cout << endl;
        return;
    }

    if (i < S1.size()) {
        S.push_back(S1[i]);
        printMixing(S1, S2, S, i + 1, j);
        S.pop_back();
    }

    if (j < S2.size()) {
        S.push_back(S2[j]);
        printMixing(S1, S2, S, i, j + 1);
        S.pop_back();
    }
}

int main() {
    vector<char> S1 = {'A', 'B', 'C'};
    vector<char> S2 = {'D', 'E', 'F'};

    vector<char> S;
    printMixing(S1, S2, S, 0, 0);

    cout << "----------------------\n" << endl;

    S.clear();

    vector<char> S3 = {'A', 'B', 'C'};
    vector<char> S4 = {'A', 'B', 'C'};
    
    printMixing(S3, S4, S, 0, 0);
    return 0;
}