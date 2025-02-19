#include <iostream>

using namespace std;

int N, B;
int digits[20];

int VariousNumber(int n, int K)
{
    int cnt = 0;

    while (true)
    {
        if (n < K)
        {
            digits[cnt++] = n;
            break;
        }
    
        digits[cnt++] = n % K;
        n /= K;
    }

    return cnt;
}

int main() {
    cin >> N >> B;

    int length = VariousNumber(N, B);

    for (int i = length - 1; i >= 0; i--)
        cout << digits[i];

    return 0;
}