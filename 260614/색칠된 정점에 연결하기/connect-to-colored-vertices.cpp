#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, k;
int from[100000], to[100000], weight[100000];
int colored[100000];

vector<pair<int, int> > graph[100001];
bool visited[100001];

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < k; i++) {
        cin >> colored[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i] >> weight[i];

        graph[from[i]].push_back(make_pair(to[i], weight[i]));
        graph[to[i]].push_back(make_pair(from[i], weight[i]));
    }

    priority_queue<pair<int, int> > pq;

    // 색칠된 정점들을 모두 시작점으로 넣음
    for (int i = 0; i < k; i++) {
        pq.push(make_pair(0, colored[i]));
    }

    long long answer = 0;

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (visited[cur])
            continue;

        visited[cur] = true;
        answer += cost;

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            int nextCost = graph[cur][i].second;

            if (!visited[next]) {
                pq.push(make_pair(-nextCost, next));
            }
        }
    }

    cout << answer;

    return 0;
}