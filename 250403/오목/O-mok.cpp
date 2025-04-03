#include <iostream>

using namespace std;

int board[19][19];
int black[4], white[4]; // 0가로 1세로 2오른쪽아래대각\ 3왼쪽아래대각/
bool isAns, isBlack;
int x, y;

// dx dy 생각은 했는데 안썼다 나중에 다시 해볼까
/*
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
*/
// 근데 굳이 8방향 다 해야하나? 그건 또 몰루
// 왼쪽아래 아래 오른쪽아래 오른쪽만 해도될듯?
/*
int dx[4] = {1, 1, 1, 0};
int dy[4] = {-1, 0, 1, 1};

bool InRange(int x, int y)
{
    return 0 <= x && x < 19 && 0 <= y && y < 19;
}
*/


void ResetArr(bool color)
{
    for (int i = 0; i < 4; i++)
    {
        if (color)
            black[i] = 0;
        else
            white[i] = 0;
    }
}

int main() {
    for (int i = 0; i < 19; i++)
        for (int j = 0; j < 19; j++) cin >> board[i][j];

    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            if (isAns)
            {
                cout << (isBlack ? 1 : 2) << endl;
                cout << x << " " << y;
                return 0;
            }

            if (board[i][j] == 1)
            {
                for (int n = 1; n < 5; n++)
                {
                    if (board[i + n][j] == 1)
                        black[0]++;
                    if (board[i][j + n] == 1)
                        black[1]++;
                    if (board[i + n][j + n] == 1)
                        black[2]++;
                    if (board[i - n][j + n] == 1)
                        black[3]++;
                }

                for (int n = 0; n < 4; n++)
                {
                    if (black[n] == 4)
                    {
                        if (n == 0)
                        {
                            x = i + 3;
                            y = j + 1;
                        }
                        else if (n == 1)
                        {
                            x = i + 1;
                            y = j + 3;
                        }
                        else if (n == 2)
                        {
                            x = i + 3;
                            y = j + 3;
                        }
                        else
                        {
                            x = i - 1;
                            y = j + 3;
                        }

                        isAns = true;
                        isBlack = true;
                    }
                }

                ResetArr(true);
            }
            else if (board[i][j] == 2)
            {
                for (int n = 1; n < 5; n++)
                {
                    if (board[i + n][j] == 2)
                        white[0]++;
                    if (board[i][j + n] == 2)
                        white[1]++;
                    if (board[i + n][j + n] == 2)
                        white[2]++;
                    if (board[i - n][j + n] == 2)
                        white[3]++;
                }

                for (int n = 0; n < 4; n++)
                {
                    if (white[n] == 4)
                    {
                        if (n == 0)
                        {
                            x = i + 3;
                            y = j + 1;
                        }
                        else if (n == 1)
                        {
                            x = i + 1;
                            y = j + 3;
                        }
                        else if (n == 2)
                        {
                            x = i + 3;
                            y = j + 3;
                        }
                        else
                        {
                            x = i - 1;
                            y = j + 3;
                        }

                        isAns = true;
                    }
                }

                ResetArr(false);
            }
        }
    }

    cout << 0;

    return 0;
}