#include <iostream>

using namespace std;

int n;
int x[100];
char dir[100];
int line[2001];

int main() {
    cin >> n;

    int origin = 1000;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> dir[i];

        if (dir[i] == 'R')
        {
            for (int j = 0; j < x[i]; j++)
                line[origin++]++;
        }
        else
        {
            for (int j = 0; j < x[i]; j++)
                line[origin--]++;
        }

    }

    int cnt = 0;
    for (int i = 1; i <= 2000; i++)
    {
        if (line[i] >= 2)
            cnt++;
    }

    cout << cnt;

    return 0;
}