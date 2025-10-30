#include <iostream>
using namespace std;

int main() {
    int arr[10][10];
    int n;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int cnt = n;

        for (int j = 1; j <= n; j++)
        {
            if (i % 2 == 1)
                arr[j][i] = j;
            else
                arr[j][i] = cnt--;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << arr[i][j];
        cout << endl;
    }

    return 0;
}