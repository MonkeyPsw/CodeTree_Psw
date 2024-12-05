#include <iostream>
using namespace std;

int main() {
    int n, num = 1;
    int arr[10][10];

    cin >> n;

    for (int i = n - 1; i >= 0; i--)
    {
        if (n % 2 == 1)
        {
            if (i % 2 == 0)
            {
                for (int j = n - 1; j >= 0; j--)
                    arr[j][i] = num++;
            }
            else
            {
                for (int j = 0; j < n; j++)
                    arr[j][i] = num++;
            }
        }
        else
        {
            if (i % 2 == 1)
            {
                for (int j = n - 1; j >= 0; j--)
                    arr[j][i] = num++;
            }
            else
            {
                for (int j = 0; j < n; j++)
                    arr[j][i] = num++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
		for (int j = 0; j < n; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}

    return 0;
}