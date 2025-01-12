#include <iostream>

using namespace std;

int n;
int arr[50];

void EvenCutter(int arr[])
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
            arr[i] /= 2;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    EvenCutter(arr);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}