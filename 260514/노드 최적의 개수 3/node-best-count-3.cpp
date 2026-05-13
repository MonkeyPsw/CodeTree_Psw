#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int from[100000], to[100000];

vector<int> edges[100001];
bool visited[100001];

int dp[100001][3];

const int INF = 1000000000;

void DFS(int x) {
    visited[x] = true;

    dp[x][0] = 1;   // x에 물건 놓음
    dp[x][1] = 0;   // 자식이 x를 덮어야 함
    dp[x][2] = 0;   // 부모가 x를 덮어줄 예정

    bool hasChild = false;

    for (int i = 0; i < edges[x].size(); i++) {
        int y = edges[x][i];

        if (visited[y]) continue;

        hasChild = true;
        DFS(y);

        // x에 물건 있음 -> 자식은 아무 상태나 가능 (단, 부모 의존 제외)
        dp[x][0] += min(dp[y][0], min(dp[y][1], dp[y][2]));

        // x가 부모에게 덮이려면, 자식들은 자기들끼리 해결해야 함
        dp[x][2] += min(dp[y][0], dp[y][1]);
    }

    // 리프면 dp[x][1] 불가능
    if (!hasChild) {
        dp[x][1] = INF;
        return;
    }

    // dp[x][1]:
    // 적어도 한 자식은 물건을 가져야 x가 덮임
    dp[x][1] = INF;

    for (int i = 0; i < edges[x].size(); i++) {
        int y = edges[x][i];

        if (visited[y] && dp[y][0] == 0 && dp[y][1] == 0 && dp[y][2] == 0)
            continue;
    }

    int base = 0;
    for (int i = 0; i < edges[x].size(); i++) {
        int y = edges[x][i];

        if (!visited[y]) continue;

        base += min(dp[y][0], dp[y][1]);
    }

    // 한 자식을 반드시 선택(물건 놓기)
    for (int i = 0; i < edges[x].size(); i++) {
        int y = edges[x][i];

        // 자식만 고려
        if (y == 0) continue;
        
        int best = min(dp[y][0], dp[y][1]);

        dp[x][1] = min(
            dp[x][1],
            base - best + dp[y][0]
        );
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        cin >> from[i] >> to[i];

        edges[from[i]].push_back(to[i]);
        edges[to[i]].push_back(from[i]);
    }

    DFS(1);

    // 루트는 부모가 없으므로 dp[1][2] 불가
    cout << min(dp[1][0], dp[1][1]);

    return 0;
}