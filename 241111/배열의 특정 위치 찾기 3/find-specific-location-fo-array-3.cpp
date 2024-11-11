#include <iostream>
using namespace std;

int main() {
    int arr[100], sum = 0;
    for (int i = 0; i < 100; i++)
    {
        cin >> arr[i];
        if (arr[i] == 0)
        {
            for (int j = i; j >= i - 3; j--)
                sum += arr[j];
            break;
        }
    }
    cout << sum;
    return 0;
}