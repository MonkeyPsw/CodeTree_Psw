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

    // 해설은 그냥 개수를 세면서 하나하나 비교했네
    /* 대각선 좌표 지정은 저렇게 하는거였군
    // 모든 쌍에 대해 전부 시도해 봅니다.
    for(int i = 1; i <= MAX_X; i++)
        for(int j = i + 1; j <= MAX_X; j++) {
            // i, j 두 명이 팀이 됐을 때 이길 수 있는지를 확인합니다.
            // win : 두 명이 팀이 됐을 때 이길 수 있다면 true
            bool win = false;

            // num_i , num_j : 각 줄에 i, j가 나오는 개수
            int num_i = 0, num_j = 0;

            // 가로로 빙고가 만들어질 때
            for(int k = 0; k < MAX_A; k++) {
                num_i = 0, num_j = 0;
                for(int l = 0; l < MAX_A; l++) {
                    if(board[k][l] == i)
                        num_i++;
                    if(board[k][l] == j)
                        num_j++;
                }

                // 3개의 칸에 i, j가 총 3번 나오며
                // 둘 다 최소 1번 이상 나오면 승리
                if(num_i + num_j == 3 && num_i >= 1 && num_j >= 1)
                    win = true;
            }

            // 세로로 빙고가 만들어질 때
            for(int k = 0; k < MAX_A; k++) {
                num_i = 0, num_j = 0;
                for(int l = 0; l < MAX_A; l++) {
                    if(board[l][k] == i)
                        num_i++;
                    if(board[l][k] == j)
                        num_j++;
                }

                // 3개의 칸에 i, j가 총 3번 나오며
                // 둘 다 최소 1번 이상 나오면 승리
                if(num_i + num_j == 3 && num_i >= 1 && num_j >= 1)
                    win = true;
            }

            // 왼쪽 위에서 오른쪽 아래를 잇는 대각선으로 빙고가 만들어질 때
            num_i = 0, num_j = 0;
            for(int k = 0; k < MAX_A; k++) {
                if(board[k][k] == i)
                    num_i++;
                if(board[k][k] == j)
                    num_j++;
            }

            // 3개의 칸에 i, j가 총 3번 나오며
            // 둘 다 최소 1번 이상 나오면 승리
            if(num_i + num_j == 3 && num_i >= 1 && num_j >= 1)
                win = true;


            // 오른쪽 위에서 왼쪽 아래를 잇는 대각선으로 빙고가 만들어질 때
            num_i = 0, num_j = 0;
            for(int k = 0; k < MAX_A; k++) {
                if(board[k][MAX_A - k - 1] == i)
                    num_i++;
                if(board[k][MAX_A - k - 1] == j)
                    num_j++;
            }

            // 3개의 칸에 i, j가 총 3번 나오며
            // 둘 다 최소 1번 이상 나오면 승리
            if(num_i + num_j == 3 && num_i >= 1 && num_j >= 1)
                win = true;
    */

    cout << ans;

    return 0;
}