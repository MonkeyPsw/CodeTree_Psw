#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int N;
int arr[100000];
priority_queue<int, vector<int>, greater<int> > pq;
long long sum;
double ans;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = N - 1; i >= 0; i--)
    {
        sum += arr[i];
        pq.push(arr[i]);

        if (pq.size() >= 2)
            ans = max(ans, (double)(sum - pq.top()) / (pq.size() - 1));
    }

    cout << fixed;
    cout.precision(2);

    cout << ans;

    return 0;
}
