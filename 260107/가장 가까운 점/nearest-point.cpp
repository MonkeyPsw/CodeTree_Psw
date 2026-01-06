#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <functional>

using namespace std;
using T = tuple<int, int, int>;

const int MAX_N = 100000;
int n, m;
int x[MAX_N], y[MAX_N];
//priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, greater<tuple<int, int, int> > > pq;
priority_queue<T, vector<T>, greater<T> > pq;
int ansX, ansY;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];

        pq.push(make_tuple(x[i] + y[i], x[i], y[i]));
    }

    for (int i = 0; i < m; i++)
    {
        int nx = 0, ny = 0;

        tie(ignore, nx, ny) = pq.top();
        nx += 2;
        ny += 2;

        pq.push(make_tuple(nx + ny, nx, ny));
        pq.pop();
    }

    tie(ignore, ansX, ansY) = pq.top();

    cout << ansX << " " << ansY;

    return 0;
}