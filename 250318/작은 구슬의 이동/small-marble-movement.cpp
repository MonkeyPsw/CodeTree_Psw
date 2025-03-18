#include <iostream>

using namespace std;

int n, t;
int r, c;
char d;
int dx[4] = {0, 1, -1, 0}, dy[4] = {1, 0, 0, -1};
int x, y;

int GetDir(char a)
{
    if(a == 'R')
        return 0;
    else if(a == 'D')
        return 1;
    else if(a == 'U')
        return 2;
    else
        return 3;
}

bool InRange(int x, int y)
{
    return (0 <= x && x < n && 0 <= y && y < n);
}

int main() {
    cin >> n >> t;
    cin >> r >> c >> d;

    x = r - 1;
    y = c - 1;
    int dir = GetDir(d);
  
    while (t--)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (!InRange(nx, ny))
            dir = 3 - dir;
        else
        {
            y = ny;
            x = nx;
        }
    }
    
    cout << x + 1 << " " << y + 1;

    return 0;
}