#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, r;
int from[100000], to[100000];

vector<int> graph[100001];

int FindCenter() {
    int cur = r;
    int parent = 0;

    while (true) {
        int childCnt = 0;
        int nextNode = 0;

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];

            if (next == parent) continue;

            childCnt++;
            nextNode = next;
        }

        if (childCnt >= 2) return cur;
        if (childCnt == 0) return cur;

        parent = cur;
        cur = nextNode;
    }
}

int DFS(int x, int parent) {
    int cnt = 1;

    for (int i = 0; i < graph[x].size(); i++) {
        int next = graph[x][i];

        if (next == parent) continue;

        cnt += DFS(next, x);
    }

    return cnt;
}

int main() {
    cin >> n >> r;

    for (int i = 0; i < n - 1; i++) {
        cin >> from[i] >> to[i];

        graph[from[i]].push_back(to[i]);
        graph[to[i]].push_back(from[i]);
    }

    int center = FindCenter();

    int minSize = n;
    int maxSize = 0;

    for (int i = 0; i < graph[center].size(); i++) {
        int next = graph[center][i];

        int subtreeSize = DFS(next, center);

        minSize = min(minSize, subtreeSize);
        maxSize = max(maxSize, subtreeSize);
    }

    cout << maxSize - minSize << endl;

    return 0;
}