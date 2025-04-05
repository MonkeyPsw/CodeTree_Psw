#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int N;
int arr[20][20];
bool check[20][20];
int ans = INT_MIN;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> arr[i][j];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 2; j++)
        {
            for (int k = 0; k < N; k++)
            {
                for (int l = 0; l < N - 2; l++)
                {
                    if (i == k && l <= j + 2)
                        continue;

                    int sum1 = arr[i][j] + arr[i][j + 1] + arr[i][j + 2];
                    int sum2 = arr[k][l] + arr[k][l + 1] + arr[k][l + 2];
                    ans = max(ans, sum1 + sum2);
                }
            }
        }
    }
    
    cout << ans;

    return 0;
}