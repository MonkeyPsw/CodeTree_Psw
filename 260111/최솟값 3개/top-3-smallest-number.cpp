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
    }

    for (int i = 0; i < n; i++)
    {
        pq.push(-arr[i]);

        if (pq.size() < 3)
        {
            cout << -1 << endl;
            continue;
        }

        int num[3] = {};

        for (int j = 0; j < 3; j++)
        {
            num[j] = -pq.top();
            pq.pop();
        }

        cout << num[0] * num[1] * num[2] << endl;

        for (int j = 0; j < 3; j++)
            pq.push(-num[j]);
    }

    return 0;
}
