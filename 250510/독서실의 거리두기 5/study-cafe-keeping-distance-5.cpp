#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

int N;
string seat;
int seatNum[20];
int ans;

int calSeatDistance()
{
    int cnt = 0;
    int seatIdx[20] = {};
    int dist = INT_MAX;

    for (int i = 0; i < N; i++)
    {
        if (seatNum[i] == 1)
            seatIdx[cnt++] = i;
    }

    for (int i = 0; i < cnt - 1; i++)
        dist = min(dist, abs(seatIdx[i] - seatIdx[i + 1]));

    return dist;
}

/* 왼쪽 오른쪽만 계산해봤다가 으앙함
int calSeatDistance(int x)
{
    int tmp1 = INT_MAX, tmp2 = INT_MAX;

    for (int i = x - 1; i >= 0; i--)
    {
        if (seatNum[i] == 1)
        {
            tmp1 = x - i;
            break;
        }
    }

    for (int i = x + 1; i < N; i++)
    {
        if (seatNum[i] == 1)
        {
            tmp2 = i - x;
            break;
        }
    }

    return min(tmp1, tmp2);
}
*/

int main() {
    cin >> N;
    cin >> seat;

    for (int i = 0; i < N; i++)
        seatNum[i] = seat[i] - '0';

    for (int i = 0; i < N; i++)
    {
        if (seatNum[i] == 0)
        {
            seatNum[i]++;
            
            int cnt = calSeatDistance();

            ans = max(ans, cnt);

            seatNum[i]--;
        }
    }

    cout << ans;

    return 0;
}