#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool accept(vector<int> n) {
    for (int i = 0; i < n.size(); i++) {
        if (n[i] != 0) {
            return false;
        }
    }
    return true;
}

void enumeration(vector<char> chars, vector<char> S, int i, vector<int> n) {
    if (accept(n)) {
        for (int i = 0; i < S.size(); i++) {
            cout << S[i] << " ";
        }
        cout << endl;
    } else {
        for (int i = 0; i < chars.size(); i++) {
            if (n[i] > 0) {
                S[i] = chars[i];

                n[i]--;
                enumeration(chars, S, i + 1, n);
                n[i]++;
            }
        }

    }
}

int main() {

    int n;

    printf("Insert number of chats: ");
    cin >> n;

    vector<char> chars(n);
    printf("Insert %d characters: ", n);

    for (int i = 0; i < n; i++) {
        cin >> chars[i];
    }

    vector<int> numbers(n);

    printf("Insert %d numbers: ", n);

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    vector<char> S = vector<char>(n);

    enumeration(chars, S, 0, numbers);

    return 0;
}