#include <iostream>
#include <queue>

using namespace std;

int n;
int arr[100000];
priority_queue<int> pq;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        pq.push(arr[i]);
    }

    while (pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();

        int b = pq.top();
        pq.pop();

        if (a - b > 0)
            pq.push(a - b);
    }

    if (pq.empty())
        cout << -1;
    else
        cout << pq.top();

    return 0;
}
