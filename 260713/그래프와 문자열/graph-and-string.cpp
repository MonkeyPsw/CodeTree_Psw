#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define MAX_N 100000

using namespace std;

int n;
string S;
int from[100000];
int to[100000];
char edge_char[100000];

struct Edge {
    int v;
    char c;
    bool forward; // 현재 정점에서 v로 가는 방향이면 true
};

vector<Edge> graph[MAX_N + 1];

bool removed[MAX_N + 1];
int subtree_size[MAX_N + 1];

int len;

int p[2] = {31, 37};
int mod[2] = {1000000007, 1000000009};

long long p_pow[2][MAX_N + 1];
long long prefix_hash[2][MAX_N + 1];
long long suffix_hash[2][MAX_N + 1];

long long totalIn[MAX_N + 1];
long long totalOut[MAX_N + 1];
long long localIn[MAX_N + 1];
long long localOut[MAX_N + 1];

long long answer = 0;

int ToInt(char c) {
    return c - 'a' + 1;
}

void dfsSize(int x, int parent) {
    subtree_size[x] = 1;

    for (Edge e : graph[x]) {
        int y = e.v;

        if (y == parent || removed[y]) {
            continue;
        }

        dfsSize(y, x);
        subtree_size[x] += subtree_size[y];
    }
}

int getCentroid(int x, int parent, int total_size) {
    for (Edge e : graph[x]) {
        int y = e.v;

        if (y == parent || removed[y]) {
            continue;
        }

        if (subtree_size[y] > total_size / 2) {
            return getCentroid(y, x, total_size);
        }
    }

    return x;
}

bool isPrefix(int depth, long long h0, long long h1) {
    return prefix_hash[0][depth] == h0 && prefix_hash[1][depth] == h1;
}

bool isSuffix(int depth, long long h0, long long h1) {
    return suffix_hash[0][depth] == h0 && suffix_hash[1][depth] == h1;
}

// 현재 노드에서 센트로이드 방향으로 가는 문자열
void collectIn(int x, int parent, int depth, long long h0, long long h1, vector<int>& result) {
    if (depth > len) {
        return;
    }

    if (isPrefix(depth, h0, h1)) {
        result.push_back(depth);
    }

    for (Edge e : graph[x]) {
        int y = e.v;

        if (y == parent || removed[y]) {
            continue;
        }

        // y -> x 방향이어야 y에서 센트로이드까지 이동 가능
        if (!e.forward) {
            int val = ToInt(e.c);

            long long nh0 = (val * p_pow[0][depth] + h0) % mod[0];
            long long nh1 = (val * p_pow[1][depth] + h1) % mod[1];

            collectIn(y, x, depth + 1, nh0, nh1, result);
        }
    }
}

// 센트로이드에서 현재 노드 방향으로 가는 문자열
void collectOut(int x, int parent, int depth, long long h0, long long h1, vector<int>& result) {
    if (depth > len) {
        return;
    }

    if (isSuffix(depth, h0, h1)) {
        result.push_back(depth);
    }

    for (Edge e : graph[x]) {
        int y = e.v;

        if (y == parent || removed[y]) {
            continue;
        }

        // x -> y 방향이어야 센트로이드에서 y까지 이동 가능
        if (e.forward) {
            int val = ToInt(e.c);

            long long nh0 = (h0 * p[0] + val) % mod[0];
            long long nh1 = (h1 * p[1] + val) % mod[1];

            collectOut(y, x, depth + 1, nh0, nh1, result);
        }
    }
}

void processCentroid(int center) {
    vector<vector<int> > inList;
    vector<vector<int> > outList;

    vector<int> touchedIn;
    vector<int> touchedOut;

    totalIn[0] = 1;
    totalOut[0] = 1;
    touchedIn.push_back(0);
    touchedOut.push_back(0);

    for (Edge e : graph[center]) {
        int y = e.v;

        if (removed[y]) {
            continue;
        }

        vector<int> curIn;
        vector<int> curOut;

        int val = ToInt(e.c);

        if (!e.forward) {
            collectIn(y, center, 1, val, val, curIn);
        }

        if (e.forward) {
            collectOut(y, center, 1, val, val, curOut);
        }

        for (int d : curIn) {
            if (totalIn[d] == 0) {
                touchedIn.push_back(d);
            }
            totalIn[d]++;
        }

        for (int d : curOut) {
            if (totalOut[d] == 0) {
                touchedOut.push_back(d);
            }
            totalOut[d]++;
        }

        inList.push_back(curIn);
        outList.push_back(curOut);
    }

    for (int d : touchedIn) {
        if (0 <= len - d && len - d <= len) {
            answer += totalIn[d] * totalOut[len - d];
        }
    }

    for (int i = 0; i < (int)inList.size(); i++) {
        vector<int> localTouchedIn;
        vector<int> localTouchedOut;

        for (int d : inList[i]) {
            if (localIn[d] == 0) {
                localTouchedIn.push_back(d);
            }
            localIn[d]++;
        }

        for (int d : outList[i]) {
            if (localOut[d] == 0) {
                localTouchedOut.push_back(d);
            }
            localOut[d]++;
        }

        for (int d : localTouchedIn) {
            int other = len - d;

            if (d > 0 && other > 0 && other <= len) {
                answer -= localIn[d] * localOut[other];
            }
        }

        for (int d : localTouchedIn) {
            localIn[d] = 0;
        }

        for (int d : localTouchedOut) {
            localOut[d] = 0;
        }
    }

    for (int d : touchedIn) {
        totalIn[d] = 0;
    }

    for (int d : touchedOut) {
        totalOut[d] = 0;
    }
}

void divideAndConquer(int x) {
    dfsSize(x, 0);

    int center = getCentroid(x, 0, subtree_size[x]);

    removed[center] = true;

    processCentroid(center);

    for (Edge e : graph[center]) {
        int y = e.v;

        if (!removed[y]) {
            divideAndConquer(y);
        }
    }
}

int main() {
    cin >> n >> S;

    for (int i = 0; i < n - 1; i++) {
        cin >> from[i] >> to[i] >> edge_char[i];

        graph[from[i]].push_back({to[i], edge_char[i], true});
        graph[to[i]].push_back({from[i], edge_char[i], false});
    }

    len = S.size();

    for (int k = 0; k < 2; k++) {
        p_pow[k][0] = 1;

        for (int i = 1; i <= len; i++) {
            p_pow[k][i] = p_pow[k][i - 1] * p[k] % mod[k];
        }

        for (int i = 0; i < len; i++) {
            prefix_hash[k][i + 1] = (prefix_hash[k][i] * p[k] + ToInt(S[i])) % mod[k];
        }

        for (int d = 1; d <= len; d++) {
            int start = len - d;

            suffix_hash[k][d] =
                (prefix_hash[k][len] - prefix_hash[k][start] * p_pow[k][d]) % mod[k];

            if (suffix_hash[k][d] < 0) {
                suffix_hash[k][d] += mod[k];
            }
        }
    }

    divideAndConquer(1);

    cout << answer;

    return 0;
}