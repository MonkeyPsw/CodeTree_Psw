#include <iostream>
using namespace std;

int main() {
    int arr[10];
    for (int i = 0; i < 10; i++)
        cin >> arr[i];
    cout << arr[2] + arr[4] + arr[9];
    return 0;
}
// 채점이 1시간 넘게 안되는건 너무했다.