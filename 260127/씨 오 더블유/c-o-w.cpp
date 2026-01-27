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
        int cntO = 1;

        if (word[i] == 'O')
        {
            int endIdx = -1;
            for (int j = i + 1; j < n - 1; j++)
            {
                if (word[j] != 'O')
                {
                    endIdx = j;
                    break;
                }

                cntO++;
            }

            ans += (long long)cntC[i - 1] * cntO * cntW[endIdx];

            i = endIdx;
        }
    }

    cout << ans;

    return 0;
}
