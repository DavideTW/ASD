#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/*
 * Scrivere un algoritmo
printWithSpaces(Item[ ] A, int n)
che prende in input una stringa contenente n caratteri,
e produce in output tutti i modi in cui è possibile stam-
pare la stringa inserendo zero o più caratteri spazio al
suo interno, evitando di inserire due spazi consecutivi.
Discutere informalmente la correttezza dell’algoritmo e
la sua complessità computazionale.
Per esempio, se A = "CIAO", l’algoritmo deve stampare
CIAO
CIA O
CI AO
CI A O
C IAO
C IA O
C I AO
C I A O
non necessariamente in questo ordine.
 */

void printWithSpacesEnum(vector<char> A, int n, vector<int> S, int i) {
    if (i == n) {
        for (int j = 0; j < A.size(); j++) {
            if (S[j] == 1) cout << " ";

            cout << A[j];
        }
        cout << endl;
    } else {
        vector<int> coiches = {0, 1};
        for (int j = 0; j < coiches.size(); j++) {
            S[i] = coiches[j];
            printWithSpacesEnum(A, n, S, i + 1);
        }
    }

}

void printWithSpaces(vector<char> A, int n) {
    vector<int> S(n, 0);

    printWithSpacesEnum(A, n, S, 1);
}

int main() {
    vector<char> A = {'C', 'I', 'A', 'O'};
    printWithSpaces(A, 4);

    return 0;
}