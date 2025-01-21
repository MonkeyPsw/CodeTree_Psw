#include <iostream>

using namespace std;

int n;
int arr[100];

/* 이건 뭔데
#include <algorithm>

// a번째 까지 인덱스의 숫자 중에 가장 큰 값을 반환합니다.
int MaxValue(int a) {
    if(a == 0)
        return arr[0];

    return max(MaxValue(a - 1), arr[a]);
}

cout << MaxValue(n - 1);
*/

int FindMax(int arr[], int length)
{
    if (length == 1)
        return arr[0];

    if (arr[length - 1] >= arr[length - 2])
    {
        arr[length - 2] = arr[length - 1];
        return FindMax(arr, length - 1);
    }
    else
        return FindMax(arr, length - 1);
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << FindMax(arr, n);

    return 0;
}