#include <iostream>
#include <cmath>

using namespace std;

char board[10][10];
int width_L, length_L, width_B, length_B;

int main() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> board[i][j];
        }
    }

    // 이게 왜 여러가지 상황이 있는거지
    // 각 문자가 하나씩이면 그냥 LB가로세로차이합-1 아닌가

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
        }
    }

    cout << abs(length_L - length_B) + abs(width_L - width_B) - 1;

    return 0;
}