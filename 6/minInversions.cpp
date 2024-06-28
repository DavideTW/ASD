#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/*
Una stringa binaria è detta elegante se è composta da
un certo numero di 0 (possibilmente nessuno), seguito 
da un certo numero di 1 (anche qui, possibilmente
nessuno).

Un’inversione di un bit della stringa consiste nel
cambiare tale bit da 0 a 1 o da 1 a 0.

Scrivere un algoritmo: int minInversions(Item[] S, int n)

che prenda in input una stringa S di dimensione n e
restituisca il numero minimo di inversioni necessarie per
renderla elegante.

Discutere informalmente la correttezza dell’algoritmo e
la sua complessità computazionale.

Per esempio,
• 000010000 può essere trasformata nella stringa
elegante 000000000 con 1 inversione (ma non con
0), quindi l’algoritmo deve restituire 1;
• 001110011 può essere trasformata nella stringa
elegante 001111111 con 2 inversioni (ma non con
0 o 1), quindi l’algoritmo deve restituire 2.
• 111111111 e 000011111 sono già eleganti, quindi
l’algoritmo deve restituire 0.
*/

int min(int a, int b) {
    return a < b ? a : b;
}

int minInversions(vector<char> S, int n) {
   int dp[n][2] = {0};

   for (int i = 0; i < n; i++) {
        dp[i + 1][0] = dp[i][0] + (S[i] == '1' ? 1 : 0);
        dp[i + 1][1] = min(dp[i][0], dp[i][1]) + (S[i] == '0' ? 1 : 0);
   }

   return min(dp[n - 1][0], dp[n - 1][1]);
}

int main() {
    vector<char> first = {'0', '0', '0', '0', '1', '0', '0', '0', '0'};
    vector<char> second = {'0', '0', '1', '1', '1', '0', '0', '1', '1'};
    vector<char> third = {'1', '1', '1', '1', '1', '1', '1', '1', '1'};

    cout << "minInversions: " << minInversions(first, 9) << endl;
    cout << "minInversions: " << minInversions(second, 9) << endl;
    cout << "minInversions: " << minInversions(third, 9) << endl;

    return 0;
}