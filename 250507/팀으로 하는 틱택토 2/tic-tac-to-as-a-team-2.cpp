#include <iostream>
#include <string>

using namespace std;

string inp[3];
int ans;
int num[10];
bool arr[10][10];

bool isExist(int n)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (inp[i][j] - '0' == n)
                return true;
        }
    }

    return false;
}

bool checkLine(char a, char b, char c, int num1, int num2)
{
    if (a == b && b == c || arr[num1][num2] || arr[num2][num1])
        return false;
    
    if ((a - '0' == num1 || a - '0' == num2) &&
        (b - '0' == num1 || b - '0' == num2) &&
        (c - '0' == num1 || c - '0' == num2))
        return (a == b && a != c) || (b == c && a != b) || (a == c && a != b);
    
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

    for (int i = 1; i <= 9; i++)
    {
        for (int j = i + 1; j <= 9; j++)
        {
            if (isExist(i) && isExist(j))
            {
                for (int x = 0; x < 3; x++)
                {
                    if (checkLine(inp[x][0], inp[x][1], inp[x][2], i, j))
                    {
                        arr[i][j] = true;
                        arr[j][i] = true;
                        ans++;
                    }
                }

                for (int y = 0; y < 3; y++)
                {
                    if (checkLine(inp[0][y], inp[1][y], inp[2][y], i, j))
                    {
                        arr[i][j] = true;
                        arr[j][i] = true;
                        ans++;
                    }
                }

                if (checkLine(inp[0][0], inp[1][1], inp[2][2], i, j))
                    ans++;

                if (checkLine(inp[2][0], inp[1][1], inp[0][2], i, j))
                    ans++;
            }
        }
    }

    /*
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
    */

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