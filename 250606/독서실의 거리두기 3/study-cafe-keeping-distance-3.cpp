#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int N;
string seat;
int seatNum[1000];
int leftPos, rightPos, maxDist;

int calSeatDistance()
{
    int cnt = 0;
    int seatIdx[1000] = {};
    int dist = INT_MAX;

    for (int i = 0; i < N; i++)
    {
        if (seatNum[i] == 1)
            seatIdx[cnt++] = i;
    }

    for (int i = 0; i < cnt - 1; i++)
        dist = min(dist, seatIdx[i + 1] - seatIdx[i]);

    return dist;
}

int main() {
    cin >> N;
    cin >> seat;

    for (int i = 0; i < N; i++)
        seatNum[i] = seat[i] - '0';

    for (int i = 0; i < N - 1; i++)
    {
        if (seatNum[i] == 1)
        {
            int tmpLeft = i, tmpRight = -1;

            for (int j = i + 1; j < N; j++)
            {
                if (seatNum[j] == 1)
                {
                    tmpRight = j;
                    break;
                }
            }

            if (tmpRight - tmpLeft > maxDist)
            {
                maxDist = tmpRight - tmpLeft;
                leftPos = tmpLeft;
                rightPos = tmpRight;
            }
        }
    }

    seatNum[(rightPos - leftPos) / 2]++;

    cout << calSeatDistance();

    return 0;
}