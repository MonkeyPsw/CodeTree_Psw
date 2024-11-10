#include <iostream>
using namespace std;

int main() {
    int cnt = 0;
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
        if (arr[i] == 0)
            break;
        cnt++;
    }
    for (int i = cnt - 1; i >= 0; i--)
        cout << arr[i] << " ";
    return 0;
}