#include <iostream>
using namespace std;

int main() {
    int arr[4][4];
    int sum = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            cin >> arr[i][j];
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = i; j < 4; j++)
            sum += arr[j][i];
    }
    /*
    for(int i = 0; i < 4; i++) {
		for(int j = 0; j <= i; j++)
			sum += arr_2d[i][j];
	}
    */
    
    cout << sum;

    return 0;
}