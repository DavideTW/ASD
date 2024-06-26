// NOTE: it is recommended to use this even if you don't understand the following code.

#include <cassert>
#include <iostream>
#include <vector>

// constraints
#define MAXN 400000

using namespace std;

// input data
int N, K, T, i, t;
vector<int> P;

int main() {
    //  uncomment the following lines if you want to read/write from files
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    assert(cin >> T);
    for(t = 0; t < T; t++) {
        assert(cin >> N >> K);

        P.resize(N);

        for(i = 0; i < N; i++) {
            assert(cin >> P[i]);
        }

        vector<int> queue;

        while(!P.empty()) {
            int elem = P.back();
            P.pop_back();

            if (queue.empty()) queue.push_back(elem);
            else {
                if (queue.back() == elem) queue.pop_back();
                else queue.push_back(elem);
            }
        }

        int result = queue.empty() ? 1 : 0;
        
        cout << result << endl; 
    }
    return 0;
}
