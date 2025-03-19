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
            x += dx[d];
            y += dy[d];
            cur++;

            if (!x && !y)
            {
                cout << cur;
                // break로 하면 위에 i for문을 탈출 못하구나 맞네
                return 0;
            }
        }
    }

    cout << -1;

    return 0;
}