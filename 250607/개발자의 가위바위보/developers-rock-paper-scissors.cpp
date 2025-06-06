#include <iostream>
#include <algorithm>

using namespace std;

int N;
int a[100], b[100];
int cnt1, cnt2;

/* 1번 4번 5번 vs 2번 3번 6번
1   1 가위, 2 바위, 3 보

2   1 가위, 2 보, 3 바위

3   1 바위, 2 가위, 3 보

4   1 바위, 2 보, 3 가위

5   1 보, 2 가위, 3 바위

6   1 보, 2 바위, 3 가위
*/

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
    }

    for (int i = 0; i < N; i++)
    {
        if (a[i] == 1 && b[i] == 3 ||
            a[i] == 2 && b[i] == 1 ||
            a[i] == 3 && b[i] == 2)
            cnt1++;
    }

    for (int i = 0; i < N; i++)
    {
        if (a[i] == 1 && b[i] == 2 ||
            a[i] == 2 && b[i] == 3 ||
            a[i] == 3 && b[i] == 1)
            cnt2++;
    }

    cout << max(cnt1, cnt2);

    return 0;
}