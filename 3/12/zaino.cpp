#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int knapsack(vector<int> w, vector<int> p, int n, int C) {
    vector<vector<int>> dp(n + 1, vector<int>(C + 1, 0)); // Init 

    for(int item = 1; item <= n; item++) { // 0 items
        for(int capacity = 1; capacity <= C; capacity++) { // 0 capacity
            int notTaken = dp[item - 1][capacity];

            if(w[item - 1] <= capacity) { 
                dp[item][capacity] = max(p[item - 1] + dp[item - 1][capacity - w[item - 1]], notTaken);
            } else { 

                dp[item][capacity] = notTaken;
            }
        }
    }

    return dp[n][C]; // Max value 
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int C, N;

    in >> C >> N;

    vector<int> P(N);
    vector<int> V(N);

    for(int i = 0; i < N; i++) {
        in >> P[i] >> V[i];
    }

    out << knapsack(P, V, N, C) << endl; 

    return 0;
}
