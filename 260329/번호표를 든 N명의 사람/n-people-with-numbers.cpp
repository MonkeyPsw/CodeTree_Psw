#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int N;
int T_max;
int d[10000];
int ans = 10001;

bool IsPossible(int num)
{
    int maxTime = 0;
    priority_queue<int, vector<int>, greater<int> > pq;

    for (int i = 0; i < num; i++)
        pq.push(d[i]);

    for (int i = num; i < N; i++)
    {
        int tmp = pq.top();

        pq.pop();

        pq.push(d[i] + tmp);
    }

    while (!pq.empty())
    {
        maxTime = max(maxTime, pq.top());
        pq.pop();
    }

    if (maxTime <= T_max)
        return true;
    
    return false;
}

int main() {
    cin >> N >> T_max;

    for (int i = 0; i < N; i++) {
        cin >> d[i];
    }

    int left = 1;
    int right = N;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (IsPossible(mid))
        {
            right = mid - 1;
            ans = min(ans, mid);
        }
        else
            left = mid + 1;
    }

    cout << ans;

    return 0;
}
