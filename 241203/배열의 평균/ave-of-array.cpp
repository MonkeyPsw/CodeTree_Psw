#include <iostream>
using namespace std;

int main() {
    int arr[2][4];

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
            cin >> arr[i][j];
    }

    cout << fixed;
    cout.precision(1);

    for (int i = 0; i < 2; i++)
    {
        int sum = 0;
        for (int j = 0; j < 4; j++)
            sum += arr[i][j];
        cout << (double)sum / 4 << " ";
    }

    cout << endl;

    for (int i = 0; i < 4; i++)
    {
        int sum = 0;
        for (int j = 0; j < 2; j++)
            sum += arr[j][i];
        cout << (double)sum / 2 << " ";
    }

    cout << endl;

    int sum = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
            sum += arr[i][j];
    }
    cout << (double)sum / 8 << " ";

    return 0;
}