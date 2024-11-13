#include <iostream>
using namespace std;

int main() {
    int n, cnt = 0;
    int arr[100], i = 1;
    cin >> n;
    while (cnt < 2)
    {
        arr[i - 1] = n * i;
        cout << arr[i - 1] << " ";
        if (arr[i - 1] % 5 == 0)
            cnt++;
        i++;
        
    }
    return 0;
}