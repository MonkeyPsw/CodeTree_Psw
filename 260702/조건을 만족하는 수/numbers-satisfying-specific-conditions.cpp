#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int n;
char signs[1000];

vector<int> graph[1005];     // 정방향 그래프 (최댓값용)
vector<int> rev_graph[1005]; // 역방향 그래프 (최솟값용)
int indegree[1005];          // 진입 차수
int outdegree[1005];         // 진출 차수

int answer1[1005]; // 최솟값 저장
int answer2[1005]; // 최댓값 저장

string num(int x) {
    string s = to_string(x);
    while (s.size() < 3) s = "0" + s;
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n)) return 0;

    for (int i = 0; i < n - 1; i++) {
        cin >> signs[i];

        if (signs[i] == '<') {
            // 정방향: i+1 -> i+2
            graph[i + 1].push_back(i + 2);
            indegree[i + 2]++;
            
            // 역방향: i+2 -> i+1 (Outdegree 관리를 위함)
            rev_graph[i + 2].push_back(i + 1);
            outdegree[i + 1]++;
        } else {
            // 정방향: i+2 -> i+1
            graph[i + 2].push_back(i + 1);
            indegree[i + 1]++;
            
            // 역방향: i+1 -> i+2
            rev_graph[i + 1].push_back(i + 2);
            outdegree[i + 2]++;
        }
    }

    priority_queue<int> pq_min;
    int cur_outdegree[1005];
    
    for (int i = 1; i <= n; i++) {
        cur_outdegree[i] = outdegree[i];
        if (cur_outdegree[i] == 0) pq_min.push(i);
    }

    int val_min = n;
    while (!pq_min.empty()) {
        int cur = pq_min.top();
        pq_min.pop();

        answer1[cur] = val_min--;

        for (int next : rev_graph[cur]) {
            cur_outdegree[next]--;
            if (cur_outdegree[next] == 0) pq_min.push(next);
        }
    }

    priority_queue<int> pq_max;
    int cur_indegree[1005];
    
    for (int i = 1; i <= n; i++) {
        cur_indegree[i] = indegree[i];
        if (cur_indegree[i] == 0) pq_max.push(i);
    }

    int val_max = 1;
    while (!pq_max.empty()) {
        int cur = pq_max.top();
        pq_max.pop();

        answer2[cur] = val_max++;

        for (int next : graph[cur]) {
            cur_indegree[next]--;
            if (cur_indegree[next] == 0) pq_max.push(next);
        }
    }

    string s1 = "";
    string s2 = "";
    for (int i = 1; i <= n; i++) s1 += num(answer1[i]);
    for (int i = 1; i <= n; i++) s2 += num(answer2[i]);

    cout << s1 << endl << s2;

    return 0;
}