#include <iostream>
#include <string>

using namespace std;

string inp[3];
int ans;
bool arr[10];

bool checkLine(char a, char b, char c)
{
    if (arr[a - '0'] && arr[b - '0'] && arr[c - '0'])
        return false;

    if ((a == b && a != c) || (b == c && a != b) || (a == c && a != b))
    {
        arr[a - '0'] = true;
        arr[b - '0'] = true;
        arr[c - '0'] = true;
        return true;
    }
    
    return false;
}

/*
// 가로
bool checkH(int num)
{
    if (arr[inp[num][0] - '0'] &&
        arr[inp[num][1] - '0'] &&
        arr[inp[num][2] - '0'])
        return false;

    if (inp[num][0] == inp[num][1] && inp[num][0] != inp[num][2] ||
        inp[num][1] == inp[num][2] && inp[num][0] != inp[num][1] ||
        inp[num][0] == inp[num][2] && inp[num][0] != inp[num][1])
    {
        arr[inp[num][0] - '0'] = true;
        arr[inp[num][1] - '0'] = true;
        arr[inp[num][2] - '0'] = true;

        return true;
    }

    return false;
}

// 세로
bool checkV(int num)
{
    if (arr[inp[0][num] - '0'] &&
        arr[inp[1][num] - '0'] &&
        arr[inp[2][num] - '0'])
        return false;

    if (inp[0][num] == inp[1][num] && inp[0][num] != inp[2][num] ||
        inp[1][num] == inp[2][num] && inp[0][num] != inp[1][num] ||
        inp[0][num] == inp[2][num] && inp[0][num] != inp[1][num])
    {
        arr[inp[0][num] - '0'] = true;
        arr[inp[1][num] - '0'] = true;
        arr[inp[2][num] - '0'] = true;

        return true;
    }

    return false;
}
*/

int main() {
    for (int i = 0; i < 3; i++) cin >> inp[i];

    for (int i = 0; i < 3; i++)
    {
        if (checkLine(inp[i][0], inp[i][1], inp[i][2]))
            ans++;
    }

    for (int j = 0; j < 3; j++)
    {
        if (checkLine(inp[0][j], inp[1][j], inp[2][j]))
            ans++;
    }

    if (checkLine(inp[0][0], inp[1][1], inp[2][2]))
        ans++;
    if (checkLine(inp[2][0], inp[1][1], inp[0][2]))
        ans++;

    /*
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 0)
            {
                if (checkV(j))
                    ans++;
            }

            if (j == 0)
            {
                if (checkH(i))
                    ans++;
            }
        }
    }

    if (inp[0][0] == inp[1][1] && inp[0][0] != inp[2][2] ||
        inp[1][1] == inp[2][2] && inp[1][1] != inp[0][0] ||
        inp[0][0] == inp[2][2] && inp[0][0] != inp[1][1])
    {
        if (!(arr[inp[0][0] - '0'] &&
            arr[inp[1][1] - '0'] &&
            arr[inp[2][2] - '0']))
            ans++;
    }

    if (inp[2][0] == inp[1][1] && inp[2][0] != inp[0][2] ||
        inp[1][1] == inp[0][2] && inp[1][1] != inp[2][0] ||
        inp[2][0] == inp[0][2] && inp[2][0] != inp[1][1])
    {
        if (!(arr[inp[2][0] - '0'] &&
            arr[inp[1][1] - '0'] &&
            arr[inp[0][2] - '0']))
            ans++;
    }
    */

    cout << ans;

    return 0;
}