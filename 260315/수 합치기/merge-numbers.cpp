#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int n;
int arr[100000];
int ans;
priority_queue<int, vector<int>, greater<int> > pq;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
        pq.push(arr[i]);
    
    while (pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();

        int b = pq.top();
        pq.pop();

        ans += a + b;

        pq.push(a + b);
    }

    cout << ans;

    return 0;
}

/* 굳이 long long 안써도 흠
int n;
int arr[100000];
long long ans;
priority_queue<long long, vector<long long>, greater<long long> > pq;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
        pq.push(arr[i]);
    
    while (pq.size() > 1)
    {
        long long a = pq.top();
        pq.pop();

        long long b = pq.top();
        pq.pop();

        ans += a + b;

        pq.push(a + b);
    }

    cout << ans;

    return 0;
}
*/