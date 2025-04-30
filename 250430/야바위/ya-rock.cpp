#include <iostream>
#include <algorithm>

using namespace std;

int N;
int a[100], b[100], c[100];
bool cups[4];
int ans = -1;

void ResetCup()
{
    for (int i = 1; i < 4; i++)
        cups[i] = false;
}

void ChangeCup(int n, int m)
{
    swap(cups[n], cups[m]);
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    for (int i = 1; i < 4; i++)
    {
        int cnt = 0;

        cups[i] = true;

        for (int j = 0; j < N; j++)
        {
            ChangeCup(a[j], b[j]);

            if (cups[c[j]])
                cnt++;
        }

        ans = max(ans, cnt);

        ResetCup();
    }

    cout << ans;

    return 0;
}