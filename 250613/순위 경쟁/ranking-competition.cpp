#include <iostream>

using namespace std;

int n;
char ch[100];
int s[100];
int ans, a, b, c;

int CheckScore()
{
    if (a > b && a > c)
        return 0;
    else if (a < b && b > c)
        return 1;
    else if (a < c && b < c)
        return 2;
    else if (a == b && a > c)
        return 3;
    else if (a == c && a > b)
        return 4;
    else if (b == c && a < b)
        return 5;
    else
        return 6;
}

int FindIndex(int arr[])
{
    for (int i = 0; i < 7; i++)
    {
        if (arr[i] == 1)
            return i;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ch[i] >> s[i];
    }

    for (int i = 0; i < n; i++)
    {
        int before[7] = {};

        before[CheckScore()]++;

        if (ch[i] == 'A')
            a += s[i];
        else if (ch[i] == 'B')
            b += s[i];
        else
            c += s[i];

        int after[7] = {};

        after[CheckScore()]++;
        
        if (FindIndex(before) != FindIndex(after))
            ans++;
    }
    
    cout << ans;

    return 0;
}