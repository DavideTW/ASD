#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int max(int a, int b, int c, int d) {
    if (a > b && a > c && a > d) {
        return a;
    } else if (b > a && b > c && b > d) {
        return b;
    } else if (c > a && c > b && c > d) {
        return c;
    } else {
        return d;
    }
}

int min(int a, int b, int c, int d) {
    if (a < b && a < c && a < d) {
        return a;
    } else if (b < a && b < c && b < d) {
        return b;
    } else if (c < a && c < b && c < d) {
        return c;
    } else {
        return d;
    }
}

/*
 * Scrivere un algoritmo
int minproduct(int[] A, int n)
che prende in input un vettore A contenente n interi e
restituisce il minimo prodotto che può essere ottenuto
moltiplicando un sottonsieme non vuoto di valori di A
fra di loro.

Discutere informalmente la correttezza dell’algoritmo e
la sua complessità computazionale.

Per esempio,
• per A = [−1, −1, 2, −2, 4, 3], l’output è
−1 · −1 · 2 · 2 · −2 · 4 · 3 = −48;
• per A = [−1, 0] l’output è −1 (valore singolo)
• per A = [0, 1] l’output è 0 (valore singolo)
• per A = [1, 2, 4], l’output è 1 (valore singolo)
 */
int minproduct (int A[], int n) {
    int maxSoFar = A[0];
    int minSoFar = A[0];

    for (int i = 1; i < n; i++) {
        maxSoFar = max(A[i], maxSoFar * A[i], minSoFar * A[i], maxSoFar);
        minSoFar = min(A[i], maxSoFar * A[i], minSoFar * A[i], minSoFar);
    }

    return minSoFar;
}

int main() {
    int A[] = {-1, -1, 2, -2, 4, 3};
    int n = 6;

    cout << minproduct(A, n) << endl;

    int B[] = {-1, 0};
    n = 2;
    cout << minproduct(B, n) << endl;

    int C[] = {0, 1};
    n = 2;
    cout << minproduct(C, n) << endl;

    int D[] = {1, 2, 4};
    n = 3;
    cout << minproduct(D, n) << endl;

    return 0;
}