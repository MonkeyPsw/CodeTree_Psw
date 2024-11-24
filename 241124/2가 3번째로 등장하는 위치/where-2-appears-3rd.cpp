#include <iostream>
using namespace std;

int main() {
    int n, num, idx = 0;
	int cnt = 0;
    cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (num == 2)
			cnt++;
		if (cnt == 3)
		{
			idx += i;
			break;
		}
	}

	cout << ++idx;
	return 0;
}