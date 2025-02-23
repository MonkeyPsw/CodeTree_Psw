#include <iostream>

using namespace std;

int n;
int x[1000];
char dir[1000];

int line[200001];
bool lastColorIsBlack[200001];

int main() {
    int white = 0, black = 0;
    int origin = 100000;
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        int cnt = 0;

        cin >> x[i] >> dir[i];

        if (dir[i] == 'R')
        {
            for (int j = 0; j < x[i]; j++)
            {
                line[origin]++;
                lastColorIsBlack[origin] = true;
                cnt++;
                if (cnt < x[i])
                    origin++;
            }
        }
        else
        {
            for (int j = 0; j < x[i]; j++)
            {
                line[origin]++;
                lastColorIsBlack[origin] = false;
                cnt++;
                if (cnt < x[i])
                    origin--;
            }
        }
    }

    for (int i = 1; i <= 200000; i++)
    {
        if (line[i] > 0)
        {
            if (lastColorIsBlack[i])
                black++;
            else
                white++;
        }
    }

    cout << white << " " << black;

    return 0;
}