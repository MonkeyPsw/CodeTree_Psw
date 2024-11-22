#include <iostream>
using namespace std;

int main() {
	int cnt;
	int arr[100];
	int cnt_Arr[11] = {};

	for (int i = 0; i < 100; i++)
	{
		cin >> arr[i];
		if (arr[i] == 0)
		{
			cnt = i;
			break;
		}
	}

	for (int i = 0; i < cnt; i++)
		cnt_Arr[arr[i] / 10]++;

	for (int i = 10; i > 0; i--)
		cout << i * 10 << " - " << cnt_Arr[i] << endl;

	return 0;
}