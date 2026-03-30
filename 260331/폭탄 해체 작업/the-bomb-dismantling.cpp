#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int N;
int score[10000];
int time_limit[10000];
pair<int, int> p[10000];
priority_queue<int, vector<int>, greater<int> > pq;
int ans;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> score[i] >> time_limit[i];
    }

    for (int i = 0; i < N; i++)
        p[i] = make_pair(time_limit[i], score[i]);
    
    sort(p, p + N);

    for (int i = 0; i < N; i++)
    {
        pq.push(p[i].second);

        if (pq.size() > p[i].first)
            pq.pop();
    }

    while (!pq.empty())
    {
        ans += pq.top();
        pq.pop();
    }

    cout << ans;

    return 0;
}
