#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/*
 * Scrivere una funzione
 * int paths(boolean[][] A, int n)
 * che prenda in input una matrice di dimensione n × n e
 * restituisca il numero di percorsi che permettono di an-
 * dare dalla posizione (n, n) alla posizione (1, 1), potendo
 * andare solo in alto (riga−1) o a sinistra (colonna−1) e
 * considerato che non è possibile attraversare celle della
 * matrice il cui valore sia false.
 * Discutere informalmente la correttezza dell’algoritmo
 * e la sua complessità computazionale. Potete assumere
 * che A[1][1] = A[n][n] = true, ma non è strettamente
 * necessario.
 */

# define DIM 3

int paths(bool A[][DIM], int n) {
    int dp[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!A[i][j]) {
                dp[i][j] = 0;
            } else if (i == 0 && j == 0) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    return dp[n - 1][n - 1];
}

int main() {

    bool A[DIM][DIM] = {
        {true, true, true},
        {true, false, true},
        {true, true, true}
    };

    cout << paths(A, DIM) << endl;

    return 0;
}