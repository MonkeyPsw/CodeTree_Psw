#include <iostream>

using namespace std;

int n;
int arr[100];
int cnt;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            
            for (int k = i; k <= j; k++)
                sum += arr[k];

            double avg = (double)sum / (j - i + 1);

            for (int l = i; l <= j; l++)
            {
                if (avg == arr[l])
                {
                    cnt++;
                    break;
                }
            }
            
        }
    }

    cout << cnt;

    return 0;
}