#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int from[100000], to[100000];
int items[100000];

vector<int> tree[100001];
int dp[100001][2];
bool fixed_node[100001];

const int INF = 1000000000;

void DFS(int x, int parent)
{
    dp[x][0] = 0; // x 선택 안함
    dp[x][1] = 1; // x 선택함

    for (int i = 0; i < tree[x].size(); i++)
    {
        int y = tree[x][i];

        if (y == parent)
            continue;

        DFS(y, x);

        // x를 선택 안하면 자식은 반드시 선택
        dp[x][0] += dp[y][1];

        // x를 선택하면 자식은 자유
        dp[x][1] += min(dp[y][0], dp[y][1]);
    }

    // 이미 물건이 있는 노드는 반드시 선택해야 함
    if (fixed_node[x])
        dp[x][0] = INF;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n - 1; i++) {
        cin >> from[i] >> to[i];

        tree[from[i]].push_back(to[i]);
        tree[to[i]].push_back(from[i]);
    }

    for (int i = 0; i < m; i++) {
        cin >> items[i];
        fixed_node[items[i]] = true;
    }

    DFS(1, 0);

    // 전체 최소 개수에서 이미 있는 m개 빼기
    cout << min(dp[1][0], dp[1][1]) - m;

    return 0;
}