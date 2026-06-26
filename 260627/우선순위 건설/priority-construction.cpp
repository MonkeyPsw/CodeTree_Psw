#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int t[500];
int prev_build[500][500];
int prev_count[500];

vector<int> graph[500];
int indegree[500];
int dp[500];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> t[i];
        int count = 0;
        while (true) {
            int x;
            cin >> x;
            if (x == -1) break;
            prev_build[i][count] = x - 1;
            graph[x - 1].push_back(i);
            indegree[i]++;
            count++;
        }
        prev_count[i] = count;
    }

    queue<int> q;

    for (int i = 0; i < n; i++) {
        dp[i] = t[i];

        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];

            dp[next] = max(dp[next], dp[cur] + t[next]);
            indegree[next]--;

            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << dp[i] << endl;
    }

    return 0;
}