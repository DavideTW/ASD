#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ifstream in("input.txt");
    ofstream out("output.txt");

    int N = 0;
    in >> N;

    int graph[N][N];

    for (int i = 0; i < N; i++) {

        for(int j = 0; j < i; j++) {
            int vertex = 0;
            in >> vertex;

            graph[i][j] = vertex;
            graph[j][i] = vertex;
        }
    }
    
    for (int i = 0; i < N; i++) {
        cout << i << ": ";

        for (int j = 0; j < i; j++){
            cout << j << " - " << graph[i][j] << ", ";
        }

        cout << endl;
    }

    bool visited[N];
    for (int i = 0; i < N; i++) visited[i] = false;

    int currentNode = 0;
    for (int i = 0; i < N; i++) {
        visited[currentNode] = true;
        cout << currentNode << " ";
        out << currentNode << " ";
        int min = 1001;
        int nextNode = 0;

        for (int j = 0; j < N; j++) {
            if (graph[currentNode][j] < min && !visited[j]) {
                min = graph[currentNode][j];
                nextNode = j;
            }
        }

        currentNode = nextNode;
    }

    out << "0#";

    return 0;
}