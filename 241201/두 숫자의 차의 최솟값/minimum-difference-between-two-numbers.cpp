#include <iostream>
using namespace std;

int main() {
    int n;
    int arr[10];
    int sub[9];
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    for (int i = 0; i < n - 1; i++)
        sub[i] = arr[i + 1] - arr[i];

    int min = sub[0];

    for (int i = 1; i < n - 1; i++)
    {
        if (sub[i] < min)
            min = sub[i];
    }

    cout << min;
    return 0;
}