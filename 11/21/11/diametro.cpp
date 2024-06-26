#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<vector<int>> graph;

int distance(int index) {
    vector<int> queue;
    queue.push_back(index);

    vector<int> distance(graph.size()); 

    for(int i = 0; i < graph.size(); i++) {
        if (i == index) continue;

        distance[i] = -1;
    }
    distance[index] = 0;

    while(!queue.empty()) {
        int u = queue.front();
        queue.erase(queue.begin());

        for(int v : graph[u]) {
            if (distance[v] == -1) {
                distance[v] = distance[u] + 1;
                queue.push_back(v);
            }
        }
    }

    int maxDistance = 0;

    for(int i = 0; i < distance.size(); i++) {
        if (distance[i] > maxDistance) maxDistance = distance[i];
    }

    return maxDistance;

}   

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int N, M;
    in >> N >> M;

    graph.resize(N);

    for(int j = 0; j < M; j++) {
        int from, to;
        in >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }  

    int maxDistance = 0;

    for(int i = 0; i < N; i++) {
        int nowDistance = distance(i);
        if (nowDistance > maxDistance) maxDistance = nowDistance;
    }

    out << maxDistance << endl; 
    return 0;
}