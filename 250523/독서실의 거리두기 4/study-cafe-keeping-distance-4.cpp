#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

int N;
string seat;
int seatNum[100];
int ans;

int calSeatDistance()
{
    int cnt = 0;
    int seatIdx[100] = {};
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

int main() {
    cin >> N;
    cin >> seat;

    for (int i = 0; i < N; i++)
        seatNum[i] = seat[i] - '0';

    for (int i = 0; i < N; i++)
    {
        if (seatNum[i] == 0)
        {
            for (int j = i + 1; j < N; j++)
            {
                if (seatNum[j] == 0)
                {
                    seatNum[i]++;
                    seatNum[j]++;
                    
                    int cnt = calSeatDistance();

                    ans = max(ans, cnt);

                    seatNum[i]--;
                    seatNum[j]--;
                }
            }
        }
    }

    cout << ans;

    return 0;
}