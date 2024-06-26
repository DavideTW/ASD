#include <iostream>
#include <vector>

using namespace std;

void minCardinalityEnum(vector<int> data, vector<int> S, int i) {
    if (i > data.size()) {
        int min = 10000;
        int n = 0;

		for (int j = 0; j < data.size(); j++) {
			if (S[j] != 0) {
                n++;
                if (j + 1 < min) min = j + 1;
			}
		}

        if (min == n) {
            for (int j = 0; j < data.size(); j++) {
                if (S[j] != 0) {
                    cout << j + 1 << " ";
                }
            }

		    cout << endl;
        }
	} else {
		vector<int> coiches = {0, 1};
		for (int j = 0; j < coiches.size(); j++) {
			S[i] = coiches[j];
			minCardinalityEnum(data, S, i + 1);
		}
	}
}

void minCardinality(int n) {
  vector<int> S(n, 0);
  vector<int> data(n);
  
  for (int i = 0; i < n; i++) {
	data[i] = i;
  }

  minCardinalityEnum(data, S, 0);
}

int main() {
    int n;
    cout << "Inserire n: ";
    cin >> n;

    minCardinality(n);
}