#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_N = 1000;
const int MAX_K = 15;
const int MAX_LEN = 16;

int n;
int k[MAX_N];
char words[MAX_N][MAX_K][MAX_LEN];
int order[MAX_N];

bool Compare(int a, int b) {
    int len = min(k[a], k[b]);

    for (int i = 0; i < len; i++) {
        int result = strcmp(words[a][i], words[b][i]);

        if (result != 0) {
            return result < 0;
        }
    }

    return k[a] < k[b];
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k[i];
        for (int j = 0; j < k[i]; j++) {
            cin >> words[i][j];
        }

        order[i] = i;
    }

    sort(order, order + n, Compare);

    for (int i = 0; i < n; i++) {
        int cur = order[i];
        int common = 0;

        if (i > 0) {
            int prev = order[i - 1];
            int len = min(k[cur], k[prev]);

            while (common < len &&
                   strcmp(words[cur][common], words[prev][common]) == 0) {
                common++;
            }
        }

        for (int j = common; j < k[cur]; j++) {
            for (int depth = 0; depth < j; depth++) {
                cout << "--";
            }

            cout << words[cur][j] << endl;
        }
    }

    return 0;
}