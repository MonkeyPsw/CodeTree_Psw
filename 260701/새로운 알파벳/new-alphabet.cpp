#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
string words[100];

bool used[26];
bool graph[26][26];
int indegree[26];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> words[i];

        for (int j = 0; j < words[i].size(); j++) {
            used[words[i][j] - 'a'] = true;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        string a = words[i];
        string b = words[i + 1];

        int len = min(a.size(), b.size());
        bool found = false;

        for (int j = 0; j < len; j++) {
            if (a[j] != b[j]) {
                int u = a[j] - 'a';
                int v = b[j] - 'a';

                if (!graph[u][v]) {
                    graph[u][v] = true;
                    indegree[v]++;
                }

                found = true;
                break;
            }
        }

        if (!found && a.size() > b.size()) {
            cout << -1;
            return 0;
        }
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    int total = 0;
    for (int i = 0; i < 26; i++) {
        if (used[i]) {
            total++;

            if (indegree[i] == 0) {
                pq.push(i);
            }
        }
    }

    string answer = "";
    bool multiple = false;

    while (!pq.empty()) {
        if (pq.size() >= 2) {
            multiple = true;
        }

        int cur = pq.top();
        pq.pop();

        answer += char(cur + 'a');

        for (int next = 0; next < 26; next++) {
            if (graph[cur][next]) {
                indegree[next]--;

                if (indegree[next] == 0) {
                    pq.push(next);
                }
            }
        }
    }

    if (answer.size() != total) {
        cout << -1;
    } else if (multiple) {
        cout << "inf";
    } else {
        cout << answer;
    }

    return 0;
}