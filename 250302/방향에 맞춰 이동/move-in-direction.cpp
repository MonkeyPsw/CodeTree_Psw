#include <iostream>

using namespace std;

int n;
char dir[100];
int dist[100];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1};
int x, y;
//W서 S남 N북 E동

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> dir[i] >> dist[i];

        int d = -1;
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

        x += dx[d] * dist[i];
        y += dy[d] * dist[i];
    }

    cout << x << " " << y;

    return 0;
}