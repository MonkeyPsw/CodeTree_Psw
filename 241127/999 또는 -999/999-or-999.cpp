#include <iostream>
using namespace std;

int main() {
    int cnt, num;
    int arr[100];

    for (int i = 0; i < 100; i++)
    {
        cin >> num;
        if (num == 999 || num == -999)
        {
            cnt = i;
            break;
        }
        arr[i] = num;
    }
    
    int max = arr[0];
    int min = arr[0];

    for (int i = 1; i < cnt; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    cout << max << " " << min;

    return 0;
}