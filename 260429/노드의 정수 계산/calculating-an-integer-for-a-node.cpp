#include <iostream>
#include <vector>

using namespace std;

int n;
int t[100001];
int a[100001];
int p[100001];

vector<int> child[100001];

long long DFS(int x) {
    long long sum = 0;

    for (int i = 0; i < child[x].size(); i++) {
        int next = child[x][i];
        sum += DFS(next);
    }

    if (t[x] == 1) {
        sum += a[x];
    }
    else if (t[x] == 0) {
        sum -= a[x];
    }

    if (sum < 0) sum = 0;

    return sum;
}

int main() {
    cin >> n;

    for (int i = 2; i <= n; i++) {
        cin >> t[i] >> a[i] >> p[i];
        child[p[i]].push_back(i);
    }

    cout << DFS(1) << endl;

    return 0;
}