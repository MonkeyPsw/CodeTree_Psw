#include <iostream>
using namespace std;

int main() {
    int n, m, num = 1;
    int arr[100][100];

    cin >> n >> m;

    for (int k = 0; k <= n + m; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i + j == k)
                    arr[i][j] = num++;
            }
        }

    }

    for (int i = 0; i < n; i++)
    {
		for (int j = 0; j < m; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}

    return 0;
}