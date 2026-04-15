#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int C, N;
int T[100000];
int A[100000], B[100000];
pair<int, int> p[100000];
priority_queue<int, vector<int>, greater<int> > pq;
int idx, ans;

int main() {
    cin >> C >> N;

    for (int i = 0; i < C; i++) {
        cin >> T[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    for (int i = 0; i < N; i++)
        p[i] = make_pair(A[i], B[i]);

    sort(T, T + C);
    sort(p, p + N);

    for (int i = 0; i < C; i++)
    {
        while (idx <= N && T[i] >= p[idx].first)
        {
            pq.push(p[idx].second);
            idx++;
        }

        while (!pq.empty() && pq.top() < T[i])
            pq.pop();
        
        if (!pq.empty())
        {
            pq.pop();
            ans++;
        }
    }

    cout << ans;

    return 0;
}
