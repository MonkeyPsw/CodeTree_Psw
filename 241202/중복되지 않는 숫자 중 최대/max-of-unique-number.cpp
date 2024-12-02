#include <iostream>
using namespace std;

int main() {
    int n;
    int arr[1000];
    bool dup[1000];
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        dup[i] = false;
    }
    
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                dup[i] = true;
                dup[j] = true;
            }
        }
    }

    int max = -1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max && !dup[i])
            max = arr[i];
    }

    cout << max;

    return 0;
}