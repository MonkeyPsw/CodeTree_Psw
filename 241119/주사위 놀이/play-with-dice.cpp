#include <iostream>
using namespace std;

int main() {
	int arr[10];
	int cnt_Arr[7] = {};

	for (int i = 0; i < 10; i++)
		cin >> arr[i];

	for (int i = 0; i < 10; i++)
		cnt_Arr[arr[i]]++;

	for (int i = 1; i < 7; i++)
		cout << i << " - " << cnt_Arr[i] << endl;

	return 0;
}