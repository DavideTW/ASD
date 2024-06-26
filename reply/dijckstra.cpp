vector<int> dijkstra_cost(vector<city> graph, int C) { 
    vector<int> costs(C); // cosri
    vector<bool> sptSet(C); // controllati o meno
    vector<int> shortPath(C); // parent

    for (int i = 0; i < C; i++) {
        costs[i] = 100001;
        sptSet[i] = false; 
    }

    costs[0] = 0; // costo di 0 da 0 è 0
    shortPath[0] = -1;

    for (int count = 0; count < C - 1; count++) { 
        int u = minCost(costs, sptSet, C); 
        // imposta la città a true visto che l'ha già controllata

        sptSet[u] = true;
        for (int v = 0; v < graph[u].adj.size(); v++) {  // v = indice del vicino che stiamo scorrendo

            int cityIndex = graph[u].adj[v].first;
            int cityCost = graph[u].adj[v].second;
            
            if (cityIndex > 0 && (costs[u] + cityCost) < costs[cityIndex]){
                    costs[cityIndex] = costs[u] + cityCost; 
                    shortPath[cityIndex] = u;
            } 
        }
    } 
    return printPath(costs.size()-1, shortPath);
}