#include <iostream>

using namespace std;

int n;
int arr[10];

/*
// 두 수간의 최소공배수를 구하여 반환합니다.
int LCM(int a, int b) {
    int gcd = 1;
    for(int i = 1; i <= min(a, b); i++) {
        if(a % i == 0 && b % i == 0)
            gcd = i;
    }

    return a * b / gcd;
}

// index번째 까지 인덱스의 숫자 중에 가장 큰 값을 반환합니다.
int GetLCMAll(int index) {
    // 남은 원소가 1개라면 그 자신이 답이 됩니다.
    if(index == 1)
        return arr[1];

    // 1번째 ~ index - 1번째 원소의 최소공배수를 구한 결과와
    // 현재 index 원소의 최소공배수를 구하여 반환합니다.
    return LCM(GetLCMAll(index - 1), arr[index]);
}
*/

int GetGCD(int a, int b)
{
    return b ? GetGCD(b, a % b) : a;
}

int GetLCM(int arr[], int length)
{
    if (length == 1)
        return arr[0];

    int gcd = GetGCD(arr[length - 2], arr[length - 1]);

    arr[length - 2] *= arr[length - 1] / gcd;

    return GetLCM(arr, length - 1);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << GetLCM(arr, n);

    return 0;
}