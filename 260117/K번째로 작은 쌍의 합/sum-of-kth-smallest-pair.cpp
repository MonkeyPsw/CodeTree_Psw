#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
using T = tuple<int, int, int>;

int n, m, k;
int arr1[100000];
int arr2[100000];
priority_queue<T, vector<T>, greater<T> > pq;

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);

    for (int i = 0; i < n; i++)
        pq.push(make_tuple(arr1[i] + arr2[0], i, 0));

    for (int cnt = 0; cnt < k - 1; cnt++) {
        T cur = pq.top();
        pq.pop();

        int i = get<1>(cur);
        int j = get<2>(cur);

        if (j + 1 < m)
            pq.push(make_tuple(arr1[i] + arr2[j + 1], i, j + 1));
    }

    cout << get<0>(pq.top());

    /* 메모리가 부족할듯?
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            pq.push(make_tuple(arr1[i] + arr2[j], arr1[i], arr2[j]));
    }

    for (int i = 0; i < k - 1; i++)
        pq.pop();

    T tmp = pq.top();

    cout << get<0>(tmp);
    */

    return 0;
}