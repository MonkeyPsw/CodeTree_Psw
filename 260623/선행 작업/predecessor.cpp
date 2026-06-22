#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_N = 10000;

int n;
int work_time[MAX_N];
int prereq_count[MAX_N];
int prereq[MAX_N][101];

vector<int> graph[MAX_N];
int indegree[MAX_N];
int dp[MAX_N];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> work_time[i] >> prereq_count[i];
        for (int j = 0; j < prereq_count[i]; j++) {
            cin >> prereq[i][j];

            int pre = prereq[i][j] - 1;
            graph[pre].push_back(i);
            indegree[i]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < n; i++) {
        dp[i] = work_time[i];

        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];

            dp[next] = max(dp[next], dp[cur] + work_time[next]);
            indegree[next]--;

            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    int answer = 0;

    for (int i = 0; i < n; i++) {
        answer = max(answer, dp[i]);
    }

    cout << answer;

    return 0;
}