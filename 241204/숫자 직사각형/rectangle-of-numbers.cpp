#include <iostream>
using namespace std;

int main() {
    int n, m, num = 1;
    int arr[100][100];

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << num++ << " ";
        cout << endl;
    }

    return 0;
}