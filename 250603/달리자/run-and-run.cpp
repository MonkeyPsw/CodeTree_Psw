#include <iostream>

using namespace std;

int n;
int A[100];
int B[100];
int ans;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (A[i] > B[i])
        {
            int num = A[i] - B[i];
            A[i] -= num;
            A[i + 1] += num;
            ans += num;
        }
    }

    /* 너무 복잡하게 했나봄
    for (int i = n - 1; i >= 0; i--)
    {
        if (A[i] < B[i])
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (A[i] == B[i])
                    break;
                
                while (A[j] > B[j])
                {
                    A[j]--;
                    A[i]++;
                    ans += i - j;

                    if (A[i] == B[i])
                        break;
                }
            }
        }
    }
    */

    cout << ans;

    return 0;
}