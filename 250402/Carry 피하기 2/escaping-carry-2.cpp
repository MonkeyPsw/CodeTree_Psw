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

                /* 해설은 이렇게 했네
                //일의 자리에서 carry가 발생하는 경우
                if(arr[i] % 10 + arr[j] % 10 + arr[k] % 10 >= 10)
					carry = true;
				
				//십의 자리에서 carry가 발생하는 경우
                if(arr[i] % 100 / 10 + arr[j] % 100 / 10 + arr[k] % 100 / 10 >= 10)
					carry = true;
				
				//백의 자리에서 carry가 발생하는 경우
                if(arr[i] % 1000 / 100 + arr[j] % 1000 / 100 + arr[k] % 1000 / 100 >= 10)
					carry = true;
				
				//천의 자리에서 carry가 발생하는 경우
                if(arr[i] % 10000 / 1000 + arr[j] % 10000 / 1000 + arr[k] % 10000 / 1000 >= 10)
					carry = true;
                */

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