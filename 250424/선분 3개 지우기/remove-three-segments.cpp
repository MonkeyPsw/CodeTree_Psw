#include <iostream>

using namespace std;

int n;
int l[10], r[10];
int ans;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                int arr[101] = {};
                bool isCross = true;

                for (int a = 0; a < n; a++)
                {
                    if (a == i || a == j || a == k)
                        continue;
                    
                    for (int b = l[a]; b <= r[a]; b++)
                        arr[b]++;
                }

                for (int l = 0; l <= 100; l++)
                {
                    if (arr[l] > 1)
                    {
                        isCross = false;
                        break;
                    }
                }

                if (isCross)
                    ans++;
            }
        }
    }

    cout << ans;

    return 0;
}