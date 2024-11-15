#include <iostream>
using namespace std;

int main() {
    int arr[100];
    int n, cnt = 2;
    arr[0] = 1;
    cin >> arr[1];
    while (true)
    {
        arr[cnt] = (arr[cnt - 1] + arr[cnt - 2]);
        if (arr[cnt] > 100)
            break;
        cnt++;
    }
    for (int i = 0; i <= cnt; i++)
        cout << arr[i] << " ";
    return 0;
}