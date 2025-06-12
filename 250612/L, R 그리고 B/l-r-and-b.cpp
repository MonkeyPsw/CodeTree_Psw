#include <iostream>
#include <cmath>

using namespace std;

char board[10][10];
int width_L, length_L, width_B, length_B, width_R, length_R;

int main() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> board[i][j];
        }
    }

    // 이게 왜 여러가지 상황이 있는거지
    // 각 문자가 하나씩이면 그냥 LB가로세로차이합-1 아닌가
    // 아하 전부 같은 가로줄이나 세로줄인 경우가 있구나 엄마야
    // 전부 같은줄인데 L이랑 B가 먼저 가까운 경우도 있구나 세상에

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (board[i][j] == 'L')
            {
                length_L = i;
                width_L = j;
            }

            if (board[i][j] == 'B')
            {
                length_B = i;
                width_B = j;
            }

            if (board[i][j] == 'R')
            {
                length_R = i;
                width_R = j;
            }
        }
    }

    int dist = abs(length_L - length_B) + abs(width_L - width_B) - 1;

    if (width_L == width_B && width_B == width_R)
    {
        if (length_R > length_L && length_R < length_B ||
            length_R < length_L && length_R > length_B)
            dist += 2;
    }
    else if (length_L == length_B && length_B == length_R)
    {
        if (width_R > width_L && width_R < width_B ||
            width_R < width_L && width_R > width_B)
            dist += 2;
    }
    
    cout << dist;

    return 0;
}