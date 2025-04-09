#include <iostream>

using namespace std;

int N, M;
int A[100], B[100];
bool check[100];
int ans;

bool IsBeautiful()
{
    for (int i = 0; i < M; i++)
    {
        if (!check[i])
            return false;
    }

    return true;
}

void ResetCheck()
{
    for (int i = 0; i < M; i++)
        check[i] = false;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) cin >> A[i];

    for (int i = 0; i < M; i++) cin >> B[i];

    for (int i = 0; i <= N - M; i++)
    {
        for (int j = i; j < i + M; j++)
        {
            for (int k = 0; k < M; k++)
            {
                if (!check[k] && A[j] == B[k])
                {
                    check[k] = true;
                    continue;
                }
            }
        }
        
        if (IsBeautiful())
            ans++;

        ResetCheck();
    }

    cout << ans;

    return 0;
}