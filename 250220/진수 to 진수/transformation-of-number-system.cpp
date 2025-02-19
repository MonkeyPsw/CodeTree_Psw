#include <iostream>

using namespace std;

int a, b;
string n;
int digits[20];

int KPosToDec(int K, string s)
{
    int Dec = 0;

    for (int i = 0; i < s.length(); i++)
        Dec = Dec * K + (s[i] - '0');

    return Dec;
}

int DecToKPos(int n, int K)
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
    cin >> a >> b;
    cin >> n;

    int num = KPosToDec(a, n);
    int length = DecToKPos(num, b);

    for (int i = length - 1; i >= 0; i--)
        cout << digits[i];

    return 0;
}