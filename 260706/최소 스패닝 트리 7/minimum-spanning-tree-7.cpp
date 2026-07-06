#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int from[40000];
int to[40000];
int weight[40000];

// 프림 알고리즘 및 트리의 지름을 위한 전역 변수 선언
vector<pair<int, int>> adj[40005];
vector<pair<int, int>> tree[40005];
bool visited[40005];
int max_dist = -1;
int farthest_node = -1;

void dfs(int node, int parent, int current_dist) {
    if (current_dist > max_dist) {
        max_dist = current_dist;
        farthest_node = node;
    }
    for (int i = 0; i < tree[node].size(); i++) {
        int next_node = tree[node][i].first;
        int w = tree[node][i].second;
        if (next_node != parent) {
            dfs(next_node, node, current_dist + w);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i] >> weight[i];
        adj[from[i]].push_back({to[i], weight[i]});
        adj[to[i]].push_back({from[i], weight[i]});
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    
    visited[1] = true;
    for (int i = 0; i < adj[1].size(); i++) {
        pq.push({adj[1][i].second, {1, adj[1][i].first}});
    }

    long long mst_weight = 0;
    int edge_count = 0;

    while (!pq.empty() && edge_count < n - 1) {
        auto curr = pq.top();
        pq.pop();

        int w = curr.first;
        int u = curr.second.first;
        int v = curr.second.second;

        if (visited[v]) continue;

        visited[v] = true;
        mst_weight += w;
        
        // MST 간선 기록
        tree[u].push_back({v, w});
        tree[v].push_back({u, w});
        edge_count++;

        for (int i = 0; i < adj[v].size(); i++) {
            if (!visited[adj[v][i].first]) {
                pq.push({adj[v][i].second, {v, adj[v][i].first}});
            }
        }
    }

    max_dist = -1;
    dfs(1, 0, 0);

    int start_node = farthest_node;
    max_dist = -1;
    dfs(start_node, 0, 0);

    cout << mst_weight << endl << max_dist;

    return 0;
}