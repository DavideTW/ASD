#include <iostream>

using namespace std;

/* 
Punto fisso: Scrivere un algoritmo che prenda in input 
un vettore ordinato A contenente n interi distinti e 
restituisca true se e solo se esiste un indice i tale 
che A[i] = i, in tempo O(log n).
*/

bool fixedPoint(int array [], int i, int j) {
    if (i == j) return array[i] == i;

    int m = (i + j) / 2;
    if (array[m] > m) return fixedPoint(array, i, m);

    return fixedPoint(array, m + 1, j);
}

int main() {
    int array[] = {-1, 0, 1, 3, 5};

    cout << (sizeof(array) - sizeof(array[0])) / 4 << endl;

    cout << fixedPoint(array, 0, 5);
}