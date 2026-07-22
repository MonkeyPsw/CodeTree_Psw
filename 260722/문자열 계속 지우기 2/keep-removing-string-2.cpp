#include <iostream>
#include <string>
#include <vector>

using namespace std;

string A, B;

int pi[100000];

int main() {
    cin >> A >> B;

    int n = A.size();
    int m = B.size();

    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && B[i] != B[j]) {
            j = pi[j - 1];
        }

        if (B[i] == B[j]) {
            pi[i] = ++j;
        }
    }

    vector<char> result;
    vector<int> matched;

    int j = 0;

    for (int i = 0; i < n; i++) {
        while (j > 0 && A[i] != B[j]) {
            j = pi[j - 1];
        }

        if (A[i] == B[j]) {
            j++;
        }

        result.push_back(A[i]);
        matched.push_back(j);

        if (j == m) {
            for (int k = 0; k < m; k++) {
                result.pop_back();
                matched.pop_back();
            }

            if (matched.empty()) {
                j = 0;
            } else {
                j = matched.back();
            }
        }
    }

    for (int i = 0; i < (int)result.size(); i++) {
        cout << result[i];
    }

    return 0;
}