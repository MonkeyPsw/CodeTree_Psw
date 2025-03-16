#include <iostream>

using namespace std;

string dirs;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1};
int x, y;
int d = 3;

int main() {
    cin >> dirs;

    for (int i = 0; i < dirs.length(); i++)
    {
        switch (dirs[i])
        {
            case 'L' :
                d = (d - 1 + 4) % 4;
                break;
            case 'R' :
                d = (d + 1) % 4;
                break;
            case 'F' :
                x += dx[d];
                y += dy[d];
                break;
        }
    }

    cout << x << " " << y;

    return 0;
}