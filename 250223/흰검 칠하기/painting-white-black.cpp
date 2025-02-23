#include <iostream>

using namespace std;

int n;
int x[1000];
char dir[1000];

int line[200001];
bool IsBlack[200001];

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
                IsBlack[origin] = true;
                line[origin]++;
                cnt++;
                if (cnt < x[i])
                    origin++;
            }
        }
        else
        {
            for (int j = 0; j < x[i]; j++)
            {
                IsBlack[origin] = false;
                line[origin]++;
                cnt++;
                if (cnt < x[i])
                    origin--;
            }
        }
    }

    for (int i = 1; i <= 200000; i++)
    {
        if (line[i] >= 1)
        {
            if (line[i] <= 3)
            {
                if (IsBlack[i])
                    black++;
                else
                    white++;
            }

            if (line[i] >= 4)
                gray++;
        }
    }

    cout << white << " " << black << " " << gray;

    return 0;
}