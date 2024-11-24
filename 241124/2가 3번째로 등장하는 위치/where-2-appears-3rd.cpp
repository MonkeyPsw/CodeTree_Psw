#include <iostream>
using namespace std;

int main() {
    int n, num, idx = 0;
	int cnt = 0;
    cin >> n;

	/* 배열을 안써버렸다
	int arr[100];
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	*/

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (num == 2)
			cnt++;
		if (cnt == 3)
		{
			idx += i; // 그냥 여기서 i + 1 출력하고 끝내면 되는구나
			break;
		}
	}

	cout << ++idx;
	return 0;
}