#include <iostream>

using namespace std;

int N, M, K;
int penalty[10000];
int student[101];

int main() {
    int ans = -1;

    cin >> N >> M >> K;

    for (int i = 0; i < M; i++) {
        if (ans > 0)
            break;

        cin >> penalty[i];

        student[penalty[i]]++;

        for (int j = 0; j < N; j++)
        {
            if (student[j] >= K)
            {
                ans = j;
                break;
            }
        }
    }

    cout << ans;

    return 0;
}