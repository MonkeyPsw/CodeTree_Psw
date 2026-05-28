#include <iostream>

using namespace std;

int n;
int m;
int k[100000];

int parent[100002];

int Find(int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = Find(parent[x]);
}

int main() {
    cin >> n;
    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> k[i];
    }

    // 초기화
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    int answer = 0;

    for (int i = 0; i < m; i++) {
        // k[i] 이하의 가장 뒤 빈칸
        int pos = Find(k[i]);

        // 가능한 칸 없음
        if (pos == 0) {
            break;
        }

        answer++;

        // 사용 처리
        parent[pos] = Find(pos - 1);
    }

    cout << answer;

    return 0;
}