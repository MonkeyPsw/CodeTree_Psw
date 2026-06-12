#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int grid[50][50];

int comp[50][50];
int cityCost[2501][2501];

int qx[2500], qy[2500];

bool visited[2501];
int dist[2501];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void BFS(int sx, int sy, int id) {
    int front = 0, rear = 0;

    qx[rear] = sx;
    qy[rear] = sy;
    rear++;

    comp[sx][sy] = id;

    while (front < rear) {
        int x = qx[front];
        int y = qy[front];
        front++;

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            if (grid[nx][ny] == 0)
                continue;

            if (comp[nx][ny] != 0)
                continue;

            comp[nx][ny] = id;
            qx[rear] = nx;
            qy[rear] = ny;
            rear++;
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int cityCnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1 && comp[i][j] == 0) {
                cityCnt++;
                BFS(i, j, cityCnt);
            }
        }
    }

    if (cityCnt == 1) {
        cout << 0;
        return 0;
    }

    int INF = 1000000000;

    for (int i = 1; i <= cityCnt; i++) {
        for (int j = 1; j <= cityCnt; j++) {
            cityCost[i][j] = INF;
        }
    }

    // 가로 방향 도로 후보
    for (int i = 0; i < n; i++) {
        int last = 0;
        int len = 0;

        for (int j = 0; j < m; j++) {
            if (comp[i][j] != 0) {
                if (last != 0 && last != comp[i][j]) {
                    cityCost[last][comp[i][j]] = min(cityCost[last][comp[i][j]], len);
                    cityCost[comp[i][j]][last] = min(cityCost[comp[i][j]][last], len);
                }

                last = comp[i][j];
                len = 0;
            } else {
                if (last != 0)
                    len++;
            }
        }
    }

    // 세로 방향 도로 후보
    for (int j = 0; j < m; j++) {
        int last = 0;
        int len = 0;

        for (int i = 0; i < n; i++) {
            if (comp[i][j] != 0) {
                if (last != 0 && last != comp[i][j]) {
                    cityCost[last][comp[i][j]] = min(cityCost[last][comp[i][j]], len);
                    cityCost[comp[i][j]][last] = min(cityCost[comp[i][j]][last], len);
                }

                last = comp[i][j];
                len = 0;
            } else {
                if (last != 0)
                    len++;
            }
        }
    }

    for (int i = 1; i <= cityCnt; i++) {
        dist[i] = INF;
    }

    dist[1] = 0;

    int answer = 0;

    for (int i = 1; i <= cityCnt; i++) {
        int minIdx = -1;

        for (int j = 1; j <= cityCnt; j++) {
            if (!visited[j] && (minIdx == -1 || dist[j] < dist[minIdx])) {
                minIdx = j;
            }
        }

        if (minIdx == -1 || dist[minIdx] == INF) {
            cout << -1;
            return 0;
        }

        visited[minIdx] = true;
        answer += dist[minIdx];

        for (int j = 1; j <= cityCnt; j++) {
            if (!visited[j] && cityCost[minIdx][j] < dist[j]) {
                dist[j] = cityCost[minIdx][j];
            }
        }
    }

    cout << answer;

    return 0;
}