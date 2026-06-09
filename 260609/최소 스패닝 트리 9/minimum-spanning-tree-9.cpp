#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int from[100000], to[100000], weight[100000];

vector<pair<int, int> > graph[100001];
bool visited[100001];

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i] >> weight[i];

        graph[from[i]].push_back(make_pair(to[i], weight[i]));
        graph[to[i]].push_back(make_pair(from[i], weight[i]));
    }

    priority_queue<pair<int, int> > pq;

    pq.push(make_pair(0, 1));

    int answer = 0;
    int cnt = 0;

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (visited[cur])
            continue;

        visited[cur] = true;
        answer += cost;
        cnt++;

        if (cnt == n)
            break;

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