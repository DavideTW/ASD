#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> baskets; 

void inizia(int N, int M) {
    vector<vector<int>> temp(M); 

    baskets = temp;
    for(int j = 0; j < N; j++) {
        baskets[0].push_back(j);
    }
}

void sposta(int a, int b) {
    int last = baskets[a].back();
    baskets[a].pop_back();
    baskets[b].push_back(last);
}

/* 
La funzione dovrà restituire l’indice dell’elemento del cestino a in posizione i dal fondo.
• Se un tale oggetto non esiste (quindi il cestino a ha meno di i + 1 oggetti), la funzione dovrà
restituire −1.
*/
int controlla(int a, int i) {
    if (baskets[a].size() <= i) return -1;

    return baskets[a][i];
}

