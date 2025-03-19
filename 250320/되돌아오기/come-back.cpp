#include <iostream>

using namespace std;

int N;
char dir[100];
int dist[100];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1};
int x, y;
int d, cur;
//W서 S남 N북 E동

int main() {
    cin >> N;

    int cnt = -1;

    for (int i = 0; i < N; i++)
    {
        cin >> dir[i] >> dist[i];

        switch (dir[i])
        {
            case 'E' :
                d = 0;
                break;
            case 'S' :
                d = 1;
                break;
            case 'W' :
                d = 2;
                break;
            case 'N' :
                d = 3;
                break;
        }

        for (int j = 0; j < dist[i]; j++)
        {
            if (i && !x && !y)
            {
                cnt = cur;
                break;
            }

            x += dx[d];
            y += dy[d];
            cur++;
        }
    }

    cout << cnt;

    return 0;
}