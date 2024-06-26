#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n;
    in >> n;

    vector<pair<int, int>> vec;

    int max = 0;
    int min = 100;

    for(int i = 0; i < n; i++) {
        int first;
        int second;

        in >> first;
        in >> second;  

        if (second > max) max = second;
        if (first < min) min = first;

        pair<int, int> pair(first, second);

        vec.push_back(pair);
    }

    sort(vec.begin(), vec.end());
    
    int bestCount = 0;

    int start = 0;
    int end = 0;

    int lastSecond = 0;

    for(int i = 0; i < n; i++) {
        int first = vec[i].first;
        int second = vec[i].second;

        if (lastSecond != 0 && first - lastSecond > bestCount) {
            bestCount = first - lastSecond;
            start = lastSecond;
            end = first;
        }
        
        lastSecond = second;
    }

    if (bestCount == 0) {
        out << 0 << endl;
    } else {
        out << start << " " << end;
    }

    return 0;
}