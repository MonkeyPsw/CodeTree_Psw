#include <iostream>

using namespace std;

int N, M, K;
int penalty[10000];
int student[101];

int main() {
    int ans = -1;

    cin >> N >> M >> K;

    for (int i = 0; i < M; i++) {
        /*
        if (ans > 0)
            break;
        */

        cin >> penalty[i];

        student[penalty[i]]++;

        if (student[penalty[i]] >= K)
        {
            ans = penalty[i];
            break;
        }

        /* 이렇게 하면 너무 반복이 많지 맞아
        for (int j = 0; j < N; j++)
        {
            if (student[j] >= K)
            {
                ans = j;
                break;
            }
        }
        */
    }

    cout << ans;

    return 0;
}