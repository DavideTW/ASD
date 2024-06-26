#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int sottocres(vector<int> A, int N) {
    vector<int> DP(N);

    int result = 0;

    for(int i = 0;i < N ;i++) {
        DP[i] = A[i]; 

        for(int k = 0; k < i; k++)
            if(A[k] <= A[i]) 
                DP[i] = max(DP[i], A[i] + DP[k]);

        result = max(result, DP[i]);
    }

    return result;
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int N;
    in >> N;

    vector<int> A(N);

    for(int i = 0; i < N; i++) {
        in >> A[i];
    }

    out << sottocres(A, N) << endl; 

    return 0;
}
