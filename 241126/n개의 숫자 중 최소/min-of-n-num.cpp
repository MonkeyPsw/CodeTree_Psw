#include <iostream>
using namespace std;

int main() {
    int n;
    int arr[100];
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    int min = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }

    int cnt = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == min)
            cnt++;
    }

    cout << min << " " << cnt;
    return 0;
}