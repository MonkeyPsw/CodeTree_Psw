#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string S;

int main() {
    cin >> S;

    int n = S.size();

    vector<int> sa(n), group(n), temp(n);

    for (int i = 0; i < n; i++) {
        sa[i] = i;
        group[i] = S[i];
    }

    for (int t = 1; t < n; t *= 2) {
        auto cmp = [&](int a, int b) {
            if (group[a] != group[b]) {
                return group[a] < group[b];
            }

            int a_next = a + t < n ? group[a + t] : -1;
            int b_next = b + t < n ? group[b + t] : -1;

            return a_next < b_next;
        };

        sort(sa.begin(), sa.end(), cmp);

        temp[sa[0]] = 0;

        for (int i = 1; i < n; i++) {
            if (cmp(sa[i - 1], sa[i])) {
                temp[sa[i]] = temp[sa[i - 1]] + 1;
            } else {
                temp[sa[i]] = temp[sa[i - 1]];
            }
        }

        for (int i = 0; i < n; i++) {
            group[i] = temp[i];
        }

        if (group[sa[n - 1]] == n - 1) {
            break;
        }
    }

    vector<int> rank(n);

    for (int i = 0; i < n; i++) {
        rank[sa[i]] = i;
    }

    long long lcp_sum = 0;
    int h = 0;

    for (int i = 0; i < n; i++) {
        if (rank[i] == 0) {
            continue;
        }

        int j = sa[rank[i] - 1];

        while (i + h < n && j + h < n && S[i + h] == S[j + h]) {
            h++;
        }

        lcp_sum += h;

        if (h > 0) {
            h--;
        }
    }

    long long total = 1LL * n * (n + 1) / 2;

    cout << total - lcp_sum;

    return 0;
}