#include <iostream>
#include <string>

using namespace std;

string inp[3];
int a, b;
int cnt, ans;

// 가로
bool checkH(int num)
{
    if (inp[num][0] == inp[num][1] && inp[num][0] != inp[num][2] ||
        inp[num][1] == inp[num][2] && inp[num][0] != inp[num][1] ||
        inp[num][0] == inp[num][2] && inp[num][0] != inp[num][1])
        return true;

    return false;
}

// 세로
bool checkV(int num)
{
    if (inp[0][num] == inp[1][num] && inp[0][num] != inp[2][num] ||
        inp[1][num] == inp[2][num] && inp[0][num] != inp[1][num] ||
        inp[0][num] == inp[2][num] && inp[0][num] != inp[1][num])
        return true;

    return false;
}

int main() {
    for (int i = 0; i < 3; i++) cin >> inp[i];

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
        ans++;

    if (inp[2][0] == inp[1][1] && inp[2][0] != inp[0][2] ||
        inp[1][1] == inp[0][2] && inp[1][1] != inp[2][0] ||
        inp[2][0] == inp[0][2] && inp[2][0] != inp[1][1])
        ans++;

    cout << ans;

    return 0;
}