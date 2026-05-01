#include <iostream>
#include <vector>

using namespace std;

int n, m;
int parent[100001];
int i[100001], w[100001];

vector<int> child[100001];
long long score[100001];

void DFS(int x) {
    for (int j = 0; j < child[x].size(); j++) {
        int next = child[x][j];

        score[next] += score[x];
        DFS(next);
    }
}

int main() {
    cin >> n >> m;

    for (int j = 1; j <= n; j++) {
        cin >> parent[j];

        if (parent[j] != -1) {
            child[parent[j]].push_back(j);
        }
    }

    for (int j = 1; j <= m; j++) {
        cin >> i[j] >> w[j];

        score[i[j]] += w[j];
    }

    DFS(1);

    for (int j = 1; j <= n; j++) {
        cout << score[j] << ' ';
    }

    return 0;
}