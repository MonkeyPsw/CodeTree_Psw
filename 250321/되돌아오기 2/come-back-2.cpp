#include <iostream>
#include <string>

using namespace std;

string commands;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int x, y;
int d;

int main() {
    cin >> commands;

    for (int i = 0; i < commands.length(); i++)
    {
        if (commands[i] == 'F')
        {
            x += dx[d];
            y += dy[d];
        }
        else if (commands[i] == 'R')
            d = (d + 1) % 4;
        else
            d = (d - 1 + 4) % 4;

        if (!x && !y)
        {
            cout << i + 1;
            return 0;
        }
    }

    cout << -1;

    return 0;
}