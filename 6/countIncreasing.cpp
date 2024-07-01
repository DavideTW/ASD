#include <iostream>
#include <vector>
using namespace std;

int countIncreasing(vector<int>& A, int n, int k) {
    vector<vector<int>> dp(n, vector<int>(k, 0));

    for (int i = 0; i < n; ++i) {
        dp[i][0] = 1;
    }

    int count = 0;

    for (int length = 1; length < k; ++length) {
        for (int i = length; i < n; ++i) {
            dp[i][length] = 0;
            for (int j = 0; j < i; ++j) {
                if (A[j] < A[i]) {
                    dp[i][length] += dp[j][length - 1];
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        count += dp[i][k - 1];
    }

    return count;
}

int main() {
    vector<int> A = {-3, 7, 5, 6, 9};
    int n = A.size();
    int k = 3;
    cout << countIncreasing(A, n, k) << endl;
    return 0;
}
