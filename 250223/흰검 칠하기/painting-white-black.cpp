#include <iostream>

using namespace std;

int n;
int x[1000];
char dir[1000];

//int line[200001];
int isBlack[200001];
int isWhite[200001];
bool lastColorIsBlack[200001];

int main() {
    int white = 0, black = 0, gray = 0;
    int origin = 100000;
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        int cnt = 0;

        cin >> x[i] >> dir[i];

        if (dir[i] == 'R')
        {
            for (int j = 0; j < x[i]; j++)
            {
                isBlack[origin]++;
                lastColorIsBlack[origin] = true;
                //line[origin]++;
                cnt++;
                if (cnt < x[i])
                    origin++;
            }
        }
        else
        {
            for (int j = 0; j < x[i]; j++)
            {
                isWhite[origin]++;
                lastColorIsBlack[origin] = false;
                //line[origin]++;
                cnt++;
                if (cnt < x[i])
                    origin--;
            }
        }
    }

    for (int i = 1; i <= 200000; i++)
    {
        int paint = isBlack[i] + isWhite[i];

        if (paint > 0)
        {
            if (isBlack[i] >= 2 && isWhite[i] >= 2)
                gray++;
            else
            {
                if (lastColorIsBlack[i])
                    black++;
                else
                    white++;
            }
        }
    }

    /* 이렇게 하면 그냥 4번만 칠해져도 회색이 되버림
        if (line[i] >= 4)
            gray++;
    */

    cout << white << " " << black << " " << gray;

    return 0;
}