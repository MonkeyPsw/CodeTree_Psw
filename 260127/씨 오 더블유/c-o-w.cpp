#include <iostream>
#include <string>

using namespace std;

int n;
string word;
int cntC[100000], cntW[100000];
int cnt;
long long ans;

int main() {
    cin >> n;
    cin >> word;

    for (int i = 0; i < n; i++)
    {
        if (word[i] == 'C')
            cnt++;

        cntC[i] = cnt;
    }

    cnt = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        if (word[i] == 'W')
            cnt++;

        cntW[i] = cnt;
    }

    for (int i = 1; i < n - 1; i++)
    {
        if (word[i] == 'O')
            ans += (long long)cntC[i - 1] * cntW[i + 1];
    }

    cout << ans;

    return 0;
}
