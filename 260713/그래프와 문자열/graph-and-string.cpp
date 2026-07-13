#include <iostream>
#include <string>
#include <vector>
#include <tuple>

#define MAX_N 100000

using namespace std;

int n;
string S;
int from[100000];
int to[100000];
char edge_char[100000];

vector<pair<int, char> > edges[MAX_N + 1];

int p[2] = {31, 37};
int mod[2] = {1000000007, 1000000009};

long long p_pow[2][MAX_N + 1];
long long pattern_hash[2];

char path[MAX_N + 1];

int len;
int answer = 0;

int ToInt(char c) {
    return c - 'a' + 1;
}

void DFS(int x, int depth, long long h0, long long h1) {
    long long cur_hash[2] = {h0, h1};

    if (depth == len) {
        cur_hash[0] = 0;
        cur_hash[1] = 0;

        for (int k = 0; k < 2; k++) {
            for (int i = 0; i < len; i++) {
                cur_hash[k] = (cur_hash[k] + ToInt(path[i]) * p_pow[k][len - 1 - i]) % mod[k];
            }
        }
    } else if (depth > len) {
        for (int k = 0; k < 2; k++) {
            cur_hash[k] = (cur_hash[k] * p[k]
                           - ToInt(path[depth - len - 1]) * p_pow[k][len]
                           + ToInt(path[depth - 1])) % mod[k];

            if (cur_hash[k] < 0) {
                cur_hash[k] += mod[k];
            }
        }
    }

    if (cur_hash[0] == pattern_hash[0] && cur_hash[1] == pattern_hash[1]) {
        answer++;
    }

    for (int i = 0; i < (int)edges[x].size(); i++) {
        int y = edges[x][i].first;
        char c = edges[x][i].second;

        path[depth] = c;
        DFS(y, depth + 1, cur_hash[0], cur_hash[1]);
    }
}

int main() {
    cin >> n >> S;

    for (int i = 0; i < n - 1; i++) {
        cin >> from[i] >> to[i] >> edge_char[i];

        edges[from[i]].push_back(make_pair(to[i], edge_char[i]));
    }

    len = S.size();

    for (int k = 0; k < 2; k++) {
        p_pow[k][0] = 1;

        for (int i = 1; i <= n; i++) {
            p_pow[k][i] = p_pow[k][i - 1] * p[k] % mod[k];
        }
    }

    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < len; i++) {
            pattern_hash[k] = (pattern_hash[k] + ToInt(S[i]) * p_pow[k][len - 1 - i]) % mod[k];
        }
    }

    DFS(1, 0, 0, 0);

    cout << answer;

    return 0;
}