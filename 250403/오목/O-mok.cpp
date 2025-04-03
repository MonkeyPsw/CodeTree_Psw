#include <iostream>

using namespace std;

int board[19][19];
int black[3], white[3]; // 0가로 1세로 2대각
bool isAns, isBlack;
int x, y;

void ResetArr(bool color)
{
    for (int i = 0; i < 3; i++)
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
                }

                for (int n = 0; n < 3; n++)
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
                        else
                        {
                            x = i + 3;
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
                }

                for (int n = 0; n < 3; n++)
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
                        else
                        {
                            x = i + 3;
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