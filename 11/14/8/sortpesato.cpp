#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n;
    in >> n;

    vector<int> vec;

    for(int i = 0; i < n; i++) {
        int number = 0;
        in >> number;

        vec.push_back(number);
    }

    int count = 0;
    int cost = 0;

    for(int i = 0; i < n; i++) {
        int minMove = 100;

        int nowCount = 0;

        while(vec[i] != i + 1) {
            int temp = vec[i];
            vec[i] = vec[temp - 1];
            vec[temp - 1] = temp;

            nowCount++;
            
            cost += temp;

            cout << "temp " << temp << endl;

            minMove = min(minMove, vec[i]);
        }

        cout << "minMove " << minMove << endl;

        count += nowCount;
        cost += (nowCount * minMove);
    }
    
    out << count << " " << cost <<  endl; 
    return 0;
}