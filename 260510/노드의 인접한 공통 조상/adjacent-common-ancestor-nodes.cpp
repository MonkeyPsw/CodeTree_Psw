#include <iostream>

using namespace std;

int n;
int from[10000];
int to[10000];
int parent[10001];
bool visited[10001];
int a, b;

int main() {
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        cin >> from[i] >> to[i];

        // from이 부모, to가 자식
        parent[to[i]] = from[i];
    }

    cin >> a >> b;

    // a의 모든 조상 방문 표시
    while (a != 0) {
        visited[a] = true;
        a = parent[a];
    }

    // b를 올라가면서 처음 만나는 공통 조상 출력
    while (b != 0) {
        if (visited[b]) {
            cout << b;
            break;
        }
        b = parent[b];
    }

    return 0;
}