#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string T;
int m;
string P[100];

int pi[10000];
vector<int> end_pos[100001];
int dp[100001];

int main() {
    cin >> T >> m;
    for (int i = 0; i < m; i++) {
        cin >> P[i];
    }

    int n = T.size();

    for (int idx = 0; idx < m; idx++) {
        string pattern = P[idx];
        int len = pattern.size();

        for (int i = 0; i < len; i++) {
            pi[i] = 0;
        }

        for (int i = 1, j = 0; i < len; i++) {
            while (j > 0 && pattern[i] != pattern[j]) {
                j = pi[j - 1];
            }

            if (pattern[i] == pattern[j]) {
                pi[i] = ++j;
            }
        }

        for (int i = 0, j = 0; i < n; i++) {
            while (j > 0 && T[i] != pattern[j]) {
                j = pi[j - 1];
            }

            if (T[i] == pattern[j]) {
                if (j == len - 1) {
                    end_pos[i + 1].push_back(len);
                    j = pi[j];
                } else {
                    j++;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];

        for (int j = 0; j < (int)end_pos[i].size(); j++) {
            int len = end_pos[i][j];
            dp[i] = max(dp[i], dp[i - len] + len);
        }
    }

    cout << dp[n];

    return 0;
}