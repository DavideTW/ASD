#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct nodo{
  vector<int> vic;
  bool visited;
};

vector<nodo> graph;

int nodeCount(int index) {
    nodo node = graph[index];
    graph[index].visited = true;

    int count = 1;

    for(int i = 0; i < node.vic.size(); i++) {
        if (!graph[node.vic[i]].visited) {
            count += nodeCount(node.vic[i]);
        }
    }

    return count;
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int N, M, S;
    in >> N >> M >> S;

    graph.resize(N);

    for(int j = 0; j < M; j++) {
        int from, to;
        in >> from >> to;
        graph[from].vic.push_back(to);
    }  

    out << nodeCount(S) << endl; 
    return 0;
}