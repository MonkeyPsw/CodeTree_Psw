#include <iostream>
#include <string>

using namespace std;

const int MAX_NODE = 2400000;

int n;
string words[300000];
char board[4][4];

int head[MAX_NODE + 1];
int nextEdge[MAX_NODE + 1];
int edgeTo[MAX_NODE + 1];
char edgeChar[MAX_NODE + 1];
bool isEnd[MAX_NODE + 1];

int nodeCnt;
int edgeCnt;
int answer;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int FindChild(int node, char c) {
    for (int edge = head[node]; edge != 0; edge = nextEdge[edge]) {
        if (edgeChar[edge] == c) {
            return edgeTo[edge];
        }
    }

    return 0;
}

int AddChild(int node, char c) {
    int child = ++nodeCnt;
    int edge = ++edgeCnt;

    edgeTo[edge] = child;
    edgeChar[edge] = c;
    nextEdge[edge] = head[node];
    head[node] = edge;

    return child;
}

void InsertWord(const string& word) {
    int cur = 0;

    for (char c : word) {
        int next = FindChild(cur, c);

        if (next == 0) {
            next = AddChild(cur, c);
        }

        cur = next;
    }

    isEnd[cur] = true;
}

void DFS(int x, int y, int node, int depth, int visited) {
    int next = FindChild(node, board[x][y]);

    if (next == 0) {
        return;
    }

    depth++;
    visited |= 1 << (x * 4 + y);

    if (isEnd[next]) {
        answer = max(answer, depth);
    }

    if (depth == 8) {
        return;
    }

    for (int dir = 0; dir < 8; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) {
            continue;
        }

        int position = nx * 4 + ny;

        if (visited & (1 << position)) {
            continue;
        }

        DFS(nx, ny, next, depth, visited);
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    for (int i = 0; i < 4; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < 4; j++) {
            board[i][j] = row[j];
        }
    }

    for (int i = 0; i < n; i++) {
        InsertWord(words[i]);
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            DFS(i, j, 0, 0, 0);
        }
    }

    cout << answer;

    return 0;
}