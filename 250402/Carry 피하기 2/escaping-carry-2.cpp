#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[20];
int num1[5], num2[5], num3[5];
int ans = -1;
bool isCarry;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                int a = arr[i];
                int b = arr[j];
                int c = arr[k];

                for (int x = 0; x < 5; x++)
                {
                    isCarry = false;
                    
                    num1[x] = a % 10;
                    num2[x] = b % 10;
                    num3[x] = c % 10;

                    if ((num1[x] + num2[x] + num3[x]) > 9)
                    {
                        isCarry = true;
                        break;
                    }

                    a /= 10;
                    b /= 10;
                    c /= 10;
                }

                if (!isCarry)
                {
                    int cnt = arr[i] + arr[j] + arr[k];
                    ans = max(ans, cnt);
                }
            }
        }
    }

    cout << ans;

    return 0;
}