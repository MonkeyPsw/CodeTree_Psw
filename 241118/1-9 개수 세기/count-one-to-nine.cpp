#include <iostream>
using namespace std;

int main() {
    int n;
	int arr[10];
	int cnt_Arr[10] = {};

    cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++)
		cnt_Arr[arr[i]]++;

	for (int i = 1; i < 10; i++)
		cout << cnt_Arr[i] << endl;

	return 0;
}