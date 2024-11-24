#include <iostream>
using namespace std;

int main() {
    int a, b, cnt = 0, sum = 0;
	int arr[100];
	int cnt_Arr[10] = {};

    cin >> a >> b;

    while (a > 1)
    {
        arr[cnt++] = a % b;
		a /= b;
    }
	
	for (int i = 0; i < cnt; i++)
		cnt_Arr[arr[i]]++;

	for (int i = 0; i < cnt; i++)
		sum += cnt_Arr[i] * cnt_Arr[i];

	cout << sum;

    return 0;
}