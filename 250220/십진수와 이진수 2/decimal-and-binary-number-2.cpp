#include <iostream>

using namespace std;

string N;
int digits[20];

int BinToDec(string s)
{
    int num = 0;

    for (int i = 0; i < s.length(); i++)
        num = num * 2 + (s[i] - '0');

    return num;
}

int DecToBin(int n)
{
    int cnt = 0;

    while (true)
    {
        if (n < 2)
        {
            digits[cnt++] = n;
            break;
        }
    
        digits[cnt++] = n % 2;
        n /= 2;
    }

    return cnt;
}

int main() {
    cin >> N;

    int DecN = BinToDec(N);
    int length = DecToBin(DecN * 17);

    for (int i = length - 1; i >= 0; i--)
        cout << digits[i];

    return 0;
}