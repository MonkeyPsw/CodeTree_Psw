#include <iostream>
using namespace std;

int main() {
    int n, m, num = 1;
    int arr[100][100];

    cin >> n >> m;

    // 내 방법은 시간복잡도가 O(N^2*M + N*M^2) 맞나?
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

    /* 해설은 O(N*M)
    // Step 1:
    for(int start_col = 0; start_col < m; start_col++) {
        int curr_row = 0;
		int curr_col = start_col;

		while(curr_col >= 0 && curr_row < n) {
			answer[curr_row][curr_col] = count;

			// 변수 업데이트 :
			curr_row++;
			curr_col--;
			count++;
		}
    }

    // Step 2:
    for(int start_row = 1; start_row < n; start_row++) {
        int curr_row = start_row;
		int curr_col = m - 1;

        while(curr_col >= 0 && curr_row < n) {
			answer[curr_row][curr_col] = count;

			// 변수 업데이트 :
			curr_row++;
			curr_col--;
			count++;
		}
    }
    */

    for (int i = 0; i < n; i++)
    {
		for (int j = 0; j < m; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}

    return 0;
}